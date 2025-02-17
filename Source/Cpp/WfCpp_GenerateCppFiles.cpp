#include "WfCpp.h"

namespace vl
{
	namespace workflow
	{
		namespace cppcodegen
		{
			using namespace stream;

/***********************************************************************
WfCppInput
***********************************************************************/

			WfCppInput::WfCppInput(const WString& _assemblyName)
			{
				headerGuardPrefix = L"VCZH_WORKFLOW_COMPILER_GENERATED_";
				assemblyName = _assemblyName;
				assemblyNamespace = L"vl_workflow_global";
				includeFileName = _assemblyName + L"Includes";
				reflectionFileName = assemblyName + L"Reflection";
				defaultFileName = _assemblyName;
			}

/***********************************************************************
GenerateCppFiles
***********************************************************************/

			void GenerateCppComment(StreamWriter& writer, const WString& comment)
			{
				writer.WriteLine(L"/***********************************************************************");
				writer.WriteLine(L"!!!!!! DO NOT MODIFY !!!!!!");
				writer.WriteLine(L"");
				writer.WriteLine(comment);
				writer.WriteLine(L"");
				writer.WriteLine(L"This file is generated by Workflow compiler");
				writer.WriteLine(L"https://github.com/vczh-libraries");
				writer.WriteLine(L"***********************************************************************/");
			}

			void WriteReflectionInclude(bool reflection, Ptr<WfCppInput> input, stream::StreamWriter& writer)
			{
				if (reflection || input->reflectionIncludes.Count() > 0)
				{
					writer.WriteLine(L"/* CodePack:BeginIgnore() */");
					writer.WriteLine(L"#ifndef VCZH_DEBUG_NO_REFLECTION");
					if (reflection)
					{
						writer.WriteLine(L"/* CodePack:ConditionOff(VCZH_DEBUG_NO_REFLECTION, " + input->reflectionFileName + L".h) */");
						writer.WriteLine(L"#include \"" + input->reflectionFileName + L".h\"");
					}
					else
					{
						for (auto include : input->reflectionIncludes)
						{
							writer.WriteLine(L"/* CodePack:ConditionOff(VCZH_DEBUG_NO_REFLECTION, " + include + L") */");
							writer.WriteLine(L"#include \"" + include + L"\"");
						}
					}
					writer.WriteLine(L"#endif");
					writer.WriteLine(L"/* CodePack:EndIgnore() */");
				}
			}

			void WriteDependedInclude(Ptr<WfCppInput> input, WfCppConfig& config, vint headerIndex, stream::StreamWriter& writer)
			{
				vint index = config.headerIncludes.Keys().IndexOf(headerIndex);
				if (index != -1)
				{
					const auto& headers = config.headerIncludes.GetByIndex(index);
					for (auto header : headers)
					{
						if (header == 0)
						{
							writer.WriteLine(L"#include \"" + input->defaultFileName + L".h\"");
						}
						else if (header > 0)
						{
							writer.WriteLine(L"#include \"" + config.customFilesClasses.Keys()[header] + L".h\"");
						}
						else
						{
							writer.WriteLine(L"#include \"" + input->defaultFileName + itow(-header) + L".h\"");
						}
					}
				}
			}

			void WriteHeader(Ptr<WfCppInput> input, Ptr<WfCppOutput> output, WfCppConfig& config, bool multiFile, bool reflection, stream::StreamWriter& writer)
			{
				GenerateCppComment(writer, input->comment);
				writer.WriteLine(L"");
				writer.WriteLine(L"#ifndef " + input->headerGuardPrefix + wupper(input->defaultFileName));
				writer.WriteLine(L"#define " + input->headerGuardPrefix + wupper(input->defaultFileName));
				writer.WriteLine(L"");
				for (auto include : input->normalIncludes)
				{
					writer.WriteLine(L"#include \"" + include + L"\"");
				}
				writer.WriteLine(L"");
				config.WriteHeader(writer, multiFile);
				writer.WriteLine(L"");
				writer.WriteLine(L"#endif");
			}

			void WriteNonCustomSubHeader(Ptr<WfCppInput> input, Ptr<WfCppOutput> output, WfCppConfig& config, bool multiFile, bool reflection, vint fileIndex, stream::StreamWriter& writer)
			{
				GenerateCppComment(writer, input->comment);
				writer.WriteLine(L"");
				writer.WriteLine(L"#ifndef " + input->headerGuardPrefix + wupper(input->defaultFileName) + L"_DP" + itow(fileIndex));
				writer.WriteLine(L"#define " + input->headerGuardPrefix + wupper(input->defaultFileName) + L"_DP" + itow(fileIndex));
				writer.WriteLine(L"");
				writer.WriteLine(L"#include \"" + input->defaultFileName + L".h\"");
				WriteDependedInclude(input, config, -fileIndex, writer);
				writer.WriteLine(L"");
				config.WriteNonCustomSubHeader(writer, fileIndex);
				writer.WriteLine(L"");
				writer.WriteLine(L"#endif");
			}

			void WriteCpp(Ptr<WfCppInput> input, Ptr<WfCppOutput> output, WfCppConfig& config, bool multiFile, bool reflection, stream::StreamWriter& writer)
			{
				GenerateCppComment(writer, input->comment);
				writer.WriteLine(L"");
				writer.WriteLine(L"#include \"" + output->entryFileName + L".h\"");
				WriteReflectionInclude(reflection, input, writer);
				writer.WriteLine(L"");
				config.WriteCpp(writer, multiFile);
			}

			void WriteReflectionHeader(Ptr<WfCppInput> input, Ptr<WfCppOutput> output, WfCppConfig& config, bool multiFile, bool reflection, stream::StreamWriter& writer)
			{
				GenerateCppComment(writer, input->comment);
				writer.WriteLine(L"");
				writer.WriteLine(L"#ifndef " + input->headerGuardPrefix + wupper(input->reflectionFileName));
				writer.WriteLine(L"#define " + input->headerGuardPrefix + wupper(input->reflectionFileName));
				writer.WriteLine(L"");
				writer.WriteLine(L"#include \"" + output->entryFileName + L".h\"");
				if (input->reflectionIncludes.Count() > 0)
				{
					writer.WriteLine(L"#ifndef VCZH_DEBUG_NO_REFLECTION");
					for (auto include : input->reflectionIncludes)
					{
						writer.WriteLine(L"#include \"" + include + L"\"");
					}
					writer.WriteLine(L"#endif");
				}
				writer.WriteLine(L"");
				config.WriteReflectionHeader(writer, multiFile);
				writer.WriteLine(L"");
				writer.WriteLine(L"#endif");
			}

			void WriteReflectionCpp(Ptr<WfCppInput> input, Ptr<WfCppOutput> output, WfCppConfig& config, bool multiFile, bool reflection, stream::StreamWriter& writer)
			{
				GenerateCppComment(writer, input->comment);
				writer.WriteLine(L"");
				writer.WriteLine(L"#include \"" + input->reflectionFileName + L".h\"");
				writer.WriteLine(L"");
				config.WriteReflectionCpp(writer, multiFile);
			}

			void WriteIncludesHeader(Ptr<WfCppInput> input, Ptr<WfCppOutput> output, WfCppConfig& config, bool multiFile, bool reflection, stream::StreamWriter& writer)
			{
				GenerateCppComment(writer, input->comment);
				writer.WriteLine(L"");
				writer.WriteLine(L"#ifndef " + input->headerGuardPrefix + wupper(input->includeFileName));
				writer.WriteLine(L"#define " + input->headerGuardPrefix + wupper(input->includeFileName));
				writer.WriteLine(L"");

				writer.WriteLine(L"#include \"" + input->defaultFileName + L".h\"");
				for (auto fileName : config.customFilesClasses.Keys())
				{
					if (fileName != L"")
					{
						writer.WriteLine(L"#include \"" + fileName + L".h\"");
					}
				}
				for (auto fileIndex : config.headerFilesClasses.Keys())
				{
					if (fileIndex != 0)
					{
						writer.WriteLine(L"#include \"" + input->defaultFileName + itow(fileIndex) + L".h\"");
					}
				}

				writer.WriteLine(L"");
				writer.WriteLine(L"#endif");
			}

			void WriteSubHeader(Ptr<WfCppInput> input, Ptr<WfCppOutput> output, WfCppConfig& config, bool multiFile, bool reflection, const WString& fileName, stream::StreamWriter& writer)
			{
				GenerateCppComment(writer, input->comment);
				writer.WriteLine(L"");
				writer.WriteLine(L"#ifndef " + input->headerGuardPrefix + wupper(fileName));
				writer.WriteLine(L"#define " + input->headerGuardPrefix + wupper(fileName));
				writer.WriteLine(L"");
				writer.WriteLine(L"#include \"" + input->defaultFileName + L".h\"");
				WriteDependedInclude(input, config, config.customFilesClasses.Keys().IndexOf(fileName), writer);
				writer.WriteLine(L"");
				config.WriteSubHeader(writer, fileName);
				writer.WriteLine(L"");
				writer.WriteLine(L"#endif");
			}

			void WriteSubCpp(Ptr<WfCppInput> input, Ptr<WfCppOutput> output, WfCppConfig& config, bool multiFile, bool reflection, const WString& fileName, stream::StreamWriter& writer)
			{
				GenerateCppComment(writer, input->comment);
				writer.WriteLine(L"");
				writer.WriteLine(L"#include \"" + input->includeFileName + L".h\"");
				WriteReflectionInclude(reflection, input, writer);
				writer.WriteLine(L"");
				config.WriteSubCpp(writer, fileName);
			}

			Ptr<WfCppOutput> GenerateCppFiles(Ptr<WfCppInput> input, analyzer::WfLexicalScopeManager* manager)
			{
				WfCppConfig config(manager, input->assemblyName, input->assemblyNamespace);
				if (manager->errors.Count() > 0)
				{
					return nullptr;
				}

				auto output = MakePtr<WfCppOutput>();
				if (config.manager->declarationTypes.Count() > 0)
				{
					output->containsReflectionInfo = true;
				}

				bool multiFile = false;
				switch (input->multiFile)
				{
				case WfCppFileSwitch::Enabled:
					multiFile = true;
					break;
				case WfCppFileSwitch::Disabled:
					multiFile = false;
					break;
				default:
					multiFile = config.customFilesClasses.Count() > 1;
				}

				bool reflection = false;
				switch (input->reflection)
				{
				case WfCppFileSwitch::Enabled:
					reflection = true;
					break;
				case WfCppFileSwitch::Disabled:
					reflection = false;
					break;
				default:
					reflection = config.manager->declarationTypes.Count() > 0;
				}

				output->multiFile = multiFile;
				output->reflection = reflection;

				if (multiFile)
				{
					output->entryFileName = input->includeFileName;
				}
				else
				{
					output->entryFileName = input->defaultFileName;
				}

				output->cppFiles.Add(input->defaultFileName + L".h", GenerateToStream([&](StreamWriter& writer)
				{
					WriteHeader(input, output, config, multiFile, reflection, writer);
				}));
				for (auto fileIndex : config.headerFilesClasses.Keys())
				{
					if (fileIndex != 0)
					{
						output->cppFiles.Add(input->defaultFileName + itow(fileIndex) + L".h", GenerateToStream([&](StreamWriter& writer)
						{
							WriteNonCustomSubHeader(input, output, config, multiFile, reflection, fileIndex, writer);
						}));
					}
				}

				output->cppFiles.Add(input->defaultFileName + L".cpp", GenerateToStream([&](StreamWriter& writer)
				{
					WriteCpp(input, output, config, multiFile, reflection, writer);
				}));

				if (reflection)
				{
					output->cppFiles.Add(input->reflectionFileName + L".h", GenerateToStream([&](StreamWriter& writer)
					{
						WriteReflectionHeader(input, output, config, multiFile, reflection, writer);
					}));

					output->cppFiles.Add(input->reflectionFileName + L".cpp", GenerateToStream([&](StreamWriter& writer)
					{
						WriteReflectionCpp(input, output, config, multiFile, reflection, writer);
					}));
				}

				if (multiFile)
				{
					output->cppFiles.Add(input->includeFileName + L".h", GenerateToStream([&](StreamWriter& writer)
					{
						WriteIncludesHeader(input, output, config, multiFile, reflection, writer);
					}));

					for (auto fileName : config.customFilesClasses.Keys())
					{
						if (fileName != L"")
						{
							output->cppFiles.Add(fileName + L".h", GenerateToStream([&](StreamWriter& writer)
							{
								WriteSubHeader(input, output, config, multiFile, reflection, fileName, writer);
							}));

							output->cppFiles.Add(fileName + L".cpp", GenerateToStream([&](StreamWriter& writer)
							{
								WriteSubCpp(input, output, config, multiFile, reflection, fileName, writer);
							}));
						}
					}
				}

				return output;
			}
		}
	}
}
