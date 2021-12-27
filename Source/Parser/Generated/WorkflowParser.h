/***********************************************************************
This file is generated by: Vczh Parser Generator
From parser definition:Workflow
Licensed under https://github.com/vczh-libraries/License
***********************************************************************/

#ifndef VCZH_WORKFLOW_PARSER_PARSER_SYNTAX
#define VCZH_WORKFLOW_PARSER_PARSER_SYNTAX

#include "Workflow_Assembler.h"
#include "Workflow_Lexer.h"

namespace vl
{
	namespace workflow
	{
		enum class ParserStates
		{
			_Type = 0,
			_CtorFragment = 50,
			_LetVariable = 55,
			_VirtualExpression = 60,
			_BeginBoundary = 81,
			_EndBoundary = 85,
			_SetTestingOperator = 89,
			_ExpPrimitive = 94,
			_Exp0 = 231,
			_Exp1 = 246,
			_Exp2 = 252,
			_Exp3 = 264,
			_Exp4 = 279,
			_Exp5 = 288,
			_Exp6 = 309,
			_Exp7 = 315,
			_Exp8 = 321,
			_Exp9 = 327,
			_Exp10 = 333,
			_Exp11 = 341,
			_Expression = 347,
			_SwitchCase = 350,
			_Block = 356,
			_ElseStat = 364,
			_If = 368,
			_ForOperator = 382,
			_VirtualStatement = 387,
			_CoStatement = 406,
			_CoProvider = 418,
			_StateSwitchHead = 423,
			_StateSwitchArgument = 446,
			_StateSwitchCase = 449,
			_StateStatement = 460,
			_Statement = 480,
			_StateInput = 520,
			_StateDecl = 529,
			_StateMachine = 539,
			_Attribute = 546,
			_Namespace = 555,
			_FunctionArgument = 562,
			_FunctionArgumentList = 568,
			_FunctionStat = 574,
			_FunctionBody = 578,
			_FunctionKind = 588,
			_Function = 595,
			_Variable = 602,
			_Event = 611,
			_Property = 620,
			_BaseConstructorCall = 633,
			_ConstructorType = 641,
			_Constructor = 646,
			_Destructor = 657,
			_ClassBody = 661,
			_Class = 670,
			_EnumItemInt = 682,
			_EnumItemA = 685,
			_EnumItemB = 692,
			_Enum = 701,
			_StructMember = 716,
			_Struct = 723,
			_APConfig = 730,
			_AutoPropertyKind = 747,
			_AutoProperty = 754,
			_CastResultInterface = 763,
			_DeclarationCandidates = 773,
			_Declaration = 787,
			_UsingFragment = 791,
			_UsingItem = 795,
			_UsingPath = 799,
			_ModuleBody = 806,
			_Module = 812,
		};

		template<ParserStates> struct ParserStateTypes;
		template<> struct ParserStateTypes<ParserStates::_Type> { using Type = vl::workflow::WfType; };
		template<> struct ParserStateTypes<ParserStates::_Expression> { using Type = vl::workflow::WfExpression; };
		template<> struct ParserStateTypes<ParserStates::_CoProvider> { using Type = vl::workflow::WfCoProviderStatement; };
		template<> struct ParserStateTypes<ParserStates::_Statement> { using Type = vl::workflow::WfStatement; };
		template<> struct ParserStateTypes<ParserStates::_Declaration> { using Type = vl::workflow::WfDeclaration; };
		template<> struct ParserStateTypes<ParserStates::_Module> { using Type = vl::workflow::WfModule; };

		const wchar_t* ParserRuleName(vl::vint index);
		const wchar_t* ParserStateLabel(vl::vint index);
		extern void WorkflowParserData(vl::stream::IStream& outputStream);

		class Parser
			: public vl::glr::ParserBase<WorkflowTokens, ParserStates, WorkflowAstInsReceiver, ParserStateTypes>
			, protected vl::glr::automaton::TraceManager::ITypeCallback
		{
		protected:
			vl::vint32_t FindCommonBaseClass(vl::vint32_t class1, vl::vint32_t class2) const override;
		public:
			Parser();

			vl::Ptr<vl::workflow::WfType> Parse_Type(const vl::WString& input, vl::vint codeIndex = -1) const;
			vl::Ptr<vl::workflow::WfType> Parse_Type(vl::collections::List<vl::regex::RegexToken>& tokens, vl::vint codeIndex = -1) const;
			vl::Ptr<vl::workflow::WfExpression> Parse_Expression(const vl::WString& input, vl::vint codeIndex = -1) const;
			vl::Ptr<vl::workflow::WfExpression> Parse_Expression(vl::collections::List<vl::regex::RegexToken>& tokens, vl::vint codeIndex = -1) const;
			vl::Ptr<vl::workflow::WfCoProviderStatement> Parse_CoProvider(const vl::WString& input, vl::vint codeIndex = -1) const;
			vl::Ptr<vl::workflow::WfCoProviderStatement> Parse_CoProvider(vl::collections::List<vl::regex::RegexToken>& tokens, vl::vint codeIndex = -1) const;
			vl::Ptr<vl::workflow::WfStatement> Parse_Statement(const vl::WString& input, vl::vint codeIndex = -1) const;
			vl::Ptr<vl::workflow::WfStatement> Parse_Statement(vl::collections::List<vl::regex::RegexToken>& tokens, vl::vint codeIndex = -1) const;
			vl::Ptr<vl::workflow::WfDeclaration> Parse_Declaration(const vl::WString& input, vl::vint codeIndex = -1) const;
			vl::Ptr<vl::workflow::WfDeclaration> Parse_Declaration(vl::collections::List<vl::regex::RegexToken>& tokens, vl::vint codeIndex = -1) const;
			vl::Ptr<vl::workflow::WfModule> Parse_Module(const vl::WString& input, vl::vint codeIndex = -1) const;
			vl::Ptr<vl::workflow::WfModule> Parse_Module(vl::collections::List<vl::regex::RegexToken>& tokens, vl::vint codeIndex = -1) const;
		};
	}
}
#endif