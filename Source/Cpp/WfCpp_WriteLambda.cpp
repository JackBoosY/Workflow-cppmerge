#include "WfCpp.h"

namespace vl
{
	namespace workflow
	{
		namespace cppcodegen
		{
			using namespace collections;
			using namespace parsing;
			using namespace analyzer;
			using namespace reflection;
			using namespace reflection::description;

/***********************************************************************
WfCppConfig::CollectClosureInfo
***********************************************************************/

			class WfCppCollectClassExprInfoVisitor : public Object, public WfDeclaration::IVisitor
			{
			public:
				WfCppConfig*							config;
				vint									variableCount = 0;
				WfFunctionDeclaration*					firstFunction = nullptr;
				Ptr<analyzer::WfLexicalCapture>			capture;

				WfCppCollectClassExprInfoVisitor(WfCppConfig* _config)
					:config(_config)
				{
				}

				void Visit(WfNamespaceDeclaration* node)override
				{
				}

				void Visit(WfFunctionDeclaration* node)override
				{
					if (!firstFunction)
					{
						firstFunction = node;
						capture = config->manager->lambdaCaptures[node];
					}
				}

				void Visit(WfVariableDeclaration* node)override
				{
					variableCount++;
				}

				void Visit(WfEventDeclaration* node)override
				{
				}

				void Visit(WfPropertyDeclaration* node)override
				{
				}

				void Visit(WfClassDeclaration* node)override
				{
				}

				void Visit(WfConstructorDeclaration* node)override
				{
				}

				void Visit(WfDestructorDeclaration* node)override
				{
				}

				void Visit(WfEnumDeclaration* node)override
				{
				}

				void Visit(WfStructDeclaration* node)override
				{
				}

				void Execute(WfNewInterfaceExpression* node)
				{
					FOREACH(Ptr<WfDeclaration>, decl, node->declarations)
					{
						decl->Accept(this);
					}
				}
			};

			Ptr<WfCppConfig::ClosureInfo> WfCppConfig::CollectClosureInfo(Ptr<WfExpression> closure)
			{
				using SymbolPair = Pair<WString, Ptr<analyzer::WfLexicalSymbol>>;

				auto info = MakePtr<ClosureInfo>();
				WfLexicalScope* scope = nullptr;

				if (auto ordered = closure.Cast<WfOrderedLambdaExpression>())
				{
					// stable symbol order by sorting them by name
					CopyFrom(
						info->symbols,
						From(manager->lambdaCaptures[ordered.Obj()]->symbols)
							.Select([](Ptr<WfLexicalSymbol> symbol)
							{
								return SymbolPair(symbol->name, symbol);
							})
						);
					scope = manager->nodeScopes[ordered.Obj()].Obj();
				}
				else if (auto funcExpr = closure.Cast<WfFunctionExpression>())
				{
					// stable symbol order by sorting them by name
					CopyFrom(
						info->symbols,
						From(manager->lambdaCaptures[funcExpr->function.Obj()]->symbols)
							.Select([](Ptr<WfLexicalSymbol> symbol)
							{
								return SymbolPair(symbol->name, symbol);
							})
						);
					scope = manager->nodeScopes[funcExpr->function.Obj()].Obj();
				}
				else if (auto classExpr = closure.Cast<WfNewInterfaceExpression>())
				{
					WfCppCollectClassExprInfoVisitor visitor(this);
					visitor.Execute(classExpr.Obj());

					if (visitor.capture)
					{
						// stable symbol order by sorting them by name
						CopyFrom(
							info->symbols,
							From(visitor.capture->symbols)
								.Skip(visitor.variableCount)
								.Select([](Ptr<WfLexicalSymbol> symbol)
								{
									return SymbolPair(symbol->name, symbol);
								})
							);
					}

					scope = manager->nodeScopes[classExpr.Obj()].Obj();
				}

				Ptr<WfLexicalFunctionConfig> methodConfig;
				while (scope)
				{
					if (scope->typeOfThisExpr)
					{
						if (methodConfig)
						{
							info->thisTypes.Add(scope->typeOfThisExpr);
							if (!methodConfig->parentThisAccessable)
							{
								break;
							}
							methodConfig = nullptr;
						}
					}

					if (scope->functionConfig)
					{
						if (scope->functionConfig->thisAccessable)
						{
							methodConfig = scope->functionConfig;
						}
					}
					scope = scope->parentScope.Obj();
				}

				return info;
			}

/***********************************************************************
WfCppConfig::WriteCpp
***********************************************************************/

			void WfCppConfig::WriteHeader_ClosurePreDecl(stream::StreamWriter& writer, Ptr<WfExpression> closure)
			{
				auto info = closureInfos[closure.Obj()];
				writer.WriteString(L"\t");
				if (closure.Cast<WfNewInterfaceExpression>())
				{
					writer.WriteString(L"class ");
				}
				else
				{
					writer.WriteString(L"struct ");
				}
				writer.WriteString(info->lambdaClassName);
				writer.WriteLine(L";");
			}

			void WfCppConfig::WriteHeader_LambdaExprDecl(stream::StreamWriter& writer, Ptr<WfExpression> lambda)
			{
				if (auto ordered = lambda.Cast<WfOrderedLambdaExpression>())
				{
					auto name = lambdaExprs[lambda.Obj()];
					writer.WriteLine(L"\tstruct " + name);
					writer.WriteLine(L"\t{");

					if (WriteCpp_ClosureMembers(writer, lambda))
					{
						writer.WriteLine(L"");
					}
					writer.WriteString(L"\t\t");
					WriteCpp_ClosureCtor(writer, lambda, name);
					writer.WriteLine(L";");
					writer.WriteLine(L"");

					writer.WriteString(L"\t\t");
					WriteFunctionHeader(writer, ordered, L"operator()", true);
					writer.WriteLine(L" const;");
					writer.WriteLine(L"\t};");
				}
				else if (auto funcExpr = lambda.Cast<WfFunctionExpression>())
				{
					auto name = lambdaExprs[lambda.Obj()];
					writer.WriteLine(L"\tstruct " + name);
					writer.WriteLine(L"\t{");

					if (WriteCpp_ClosureMembers(writer, lambda))
					{
						writer.WriteLine(L"");
					}
					writer.WriteString(L"\t\t");
					WriteCpp_ClosureCtor(writer, lambda, name);
					writer.WriteLine(L";");
					writer.WriteLine(L"");

					writer.WriteString(L"\t\t");
					WriteFunctionHeader(writer, funcExpr, L"operator()", true);
					writer.WriteLine(L" const;");
					writer.WriteLine(L"\t};");
				}
			}

			void WfCppConfig::WriteHeader_ClassExprDecl(stream::StreamWriter& writer, Ptr<WfNewInterfaceExpression> lambda)
			{
				auto result = manager->expressionResolvings[lambda.Obj()];
				auto td = result.constructorInfo->GetOwnerTypeDescriptor();
				auto name = classExprs[lambda.Obj()];
				writer.WriteLine(L"\tclass " + name + L" : public ::vl::Object, public virtual " + ConvertType(td));
				writer.WriteLine(L"\t{");
				writer.WriteLine(L"\tpublic:");

				if (WriteCpp_ClosureMembers(writer, lambda))
				{
					writer.WriteLine(L"");
				}
				writer.WriteString(L"\t\t");
				WriteCpp_ClosureCtor(writer, lambda, name);
				writer.WriteLine(L";");
				writer.WriteLine(L"");

				FOREACH(Ptr<WfDeclaration>, decl, lambda->declarations)
				{
					GenerateClassMemberDecl(this, writer, name, decl, L"\t\t", true);
				}
				writer.WriteLine(L"\t};");
			}

			bool WfCppConfig::WriteCpp_ClosureMembers(stream::StreamWriter& writer, Ptr<WfExpression> closure)
			{
				auto info = closureInfos[closure.Obj()];

				FOREACH(Ptr<WfLexicalSymbol>, symbol, info->symbols.Values())
				{
					writer.WriteString(L"\t\t");
					writer.WriteString(ConvertType(symbol->typeInfo.Obj()));
					writer.WriteString(L" ");
					writer.WriteString(ConvertName(symbol->name));
					writer.WriteLine(L";");
				}

				FOREACH_INDEXER(ITypeDescriptor*, thisType, index, info->thisTypes)
				{
					auto typeInfo = MakePtr<RawPtrTypeInfo>(MakePtr<TypeDescriptorTypeInfo>(thisType, TypeInfoHint::Normal));

					writer.WriteString(L"\t\t");
					writer.WriteString(ConvertType(typeInfo.Obj()));
					writer.WriteString(L" ");
					writer.WriteString(L"__vwsnthis_" + itow(index));
					writer.WriteLine(L";");
				}

				return info->symbols.Count() + info->thisTypes.Count() > 0;
			}

			void WfCppConfig::WriteCpp_ClosureCtor(stream::StreamWriter& writer, Ptr<WfExpression> closure, const WString& name)
			{
				auto info = closureInfos[closure.Obj()];

				writer.WriteString(name);
				writer.WriteString(L"(");

				FOREACH_INDEXER(Ptr<WfLexicalSymbol>, symbol, index, info->symbols.Values())
				{
					if (index > 0)
					{
						writer.WriteString(L", ");
					}
					writer.WriteString(ConvertType(symbol->typeInfo.Obj()));
					writer.WriteString(L" __vwsnctor_");
					writer.WriteString(ConvertName(symbol->name));
				}

				FOREACH_INDEXER(ITypeDescriptor*, thisType, index, info->thisTypes)
				{
					auto typeInfo = MakePtr<RawPtrTypeInfo>(MakePtr<TypeDescriptorTypeInfo>(thisType, TypeInfoHint::Normal));

					if (index > 0 || info->symbols.Count() > 0)
					{
						writer.WriteString(L", ");
					}
					writer.WriteString(ConvertType(typeInfo.Obj()));
					writer.WriteString(L" __vwsnctorthis_" + itow(index));
				}

				writer.WriteString(L")");
			}

			void WfCppConfig::WriteCpp_ClosureCtorInitList(stream::StreamWriter& writer, Ptr<WfExpression> closure)
			{
				auto info = closureInfos[closure.Obj()];

				FOREACH_INDEXER(Ptr<WfLexicalSymbol>, symbol, index, info->symbols.Values())
				{
					if (index > 0)
					{
						writer.WriteString(L"\t\t, ");
					}
					else
					{
						writer.WriteString(L"\t\t:");
					}
					writer.WriteString(ConvertName(symbol->name));
					writer.WriteString(L"(__vwsnctor_");
					writer.WriteString(ConvertName(symbol->name));
					writer.WriteLine(L")");
				}

				FOREACH_INDEXER(ITypeDescriptor*, thisType, index, info->thisTypes)
				{
					if (index > 0 || info->symbols.Count() > 0)
					{
						writer.WriteString(L"\t\t, ");
					}
					else
					{
						writer.WriteString(L"\t\t:");
					}
					writer.WriteString(L"__vwsnthis_" + itow(index));
					writer.WriteString(L"(__vwsnctorthis_" + itow(index));
					writer.WriteLine(L")");
				}
			}

			void WfCppConfig::WriteCpp_LambdaExprImpl(stream::StreamWriter& writer, Ptr<WfExpression> lambda)
			{
				if (auto ordered = lambda.Cast<WfOrderedLambdaExpression>())
				{
					auto name = lambdaExprs[lambda.Obj()];

					writer.WriteString(L"\t");
					WriteCpp_ClosureCtor(writer, lambda, name + L"::" + name);
					writer.WriteLine(L"");
					WriteCpp_ClosureCtorInitList(writer, lambda);
					writer.WriteLine(L"\t{");
					writer.WriteLine(L"\t}");
					writer.WriteLine(L"");

					writer.WriteString(L"\t");
					auto returnType = WriteFunctionHeader(writer, ordered, name + L"::operator()", true);
					writer.WriteLine(L" const");
					writer.WriteLine(L"\t{");
					WriteFunctionBody(writer, ordered->body, L"\t\t", returnType);
					writer.WriteLine(L"\t}");
				}
				else if (auto funcExpr = lambda.Cast<WfFunctionExpression>())
				{
					auto name = lambdaExprs[lambda.Obj()];

					writer.WriteString(L"\t");
					WriteCpp_ClosureCtor(writer, lambda, name + L"::" + name);
					writer.WriteLine(L"");
					WriteCpp_ClosureCtorInitList(writer, lambda);
					writer.WriteLine(L"\t{");
					writer.WriteLine(L"\t}");
					writer.WriteLine(L"");

					writer.WriteString(L"\t");
					auto returnType = WriteFunctionHeader(writer, funcExpr, name + L"::operator()", true);
					writer.WriteLine(L" const");
					WriteFunctionBody(writer, funcExpr->function->statement, L"\t", returnType);
				}
			}

			class WriteCpp_ClassExprImpl_InitFieldVisitor
				: public empty_visitor::DeclarationVisitor
			{
			public:
				WfCppConfig*						config;
				stream::StreamWriter&				writer;

				WriteCpp_ClassExprImpl_InitFieldVisitor(WfCppConfig* _config, stream::StreamWriter& _writer)
					:config(_config)
					, writer(_writer)
				{
				}

				virtual void Visit(WfVariableDeclaration* node)override
				{
					if (node->expression)
					{
						auto scope = config->manager->nodeScopes[node].Obj();
						auto symbol = scope->symbols[node->name.value][0];
						auto typeInfo = symbol->typeInfo;
						writer.WriteString(L"\t\tthis->");
						writer.WriteString(config->ConvertName(node->name.value));
						writer.WriteString(L" = ");
						GenerateExpression(config, writer, node->expression, typeInfo.Obj());
						writer.WriteLine(L";");
					}
				}
			};

			void WfCppConfig::WriteCpp_ClassExprImpl(stream::StreamWriter& writer, Ptr<WfNewInterfaceExpression> lambda)
			{
				auto name = classExprs[lambda.Obj()];

				writer.WriteString(L"\t");
				WriteCpp_ClosureCtor(writer, lambda, name + L"::" + name);
				writer.WriteLine(L"");
				WriteCpp_ClosureCtorInitList(writer, lambda);
				writer.WriteLine(L"\t{");

				{
					WriteCpp_ClassExprImpl_InitFieldVisitor visitor(this, writer);
					FOREACH(Ptr<WfDeclaration>, decl, lambda->declarations)
					{
						decl->Accept(&visitor);
					}
				}

				writer.WriteLine(L"\t}");
				writer.WriteLine(L"");

				WString classFullName = L"::" + assemblyNamespace + L"::" + name;
				FOREACH(Ptr<WfDeclaration>, decl, lambda->declarations)
				{
					if (GenerateClassMemberImpl(this, writer, name, name, classFullName, decl, L"\t"))
					{
						writer.WriteLine(L"");
					}
				}
			}
		}
	}
}