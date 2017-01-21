/***********************************************************************
!!!!!! DO NOT MODIFY !!!!!!

Source: ../Resources/Codegen/WorkflowAttributes.txt

This file is generated by Workflow compiler
https://github.com/vczh-libraries
***********************************************************************/

#ifndef VCZH_WORKFLOW_COMPILER_GENERATED_WORKFLOWATTRIBUTES_EXPRESSION
#define VCZH_WORKFLOW_COMPILER_GENERATED_WORKFLOWATTRIBUTES_EXPRESSION

#include "WorkflowAttributes.h"

#if defined( _MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#elif defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wparentheses-equality"
#elif defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wparentheses-equality"
#endif

namespace calculator
{
	class Expression : public ::vl::Object, public ::vl::reflection::Description<Expression>
	{
#ifndef VCZH_DEBUG_NO_REFLECTION
		friend struct ::vl::reflection::description::CustomTypeDescriptorSelector<Expression>;
#endif
	public:
		::vl::WString Print();
		::vl::vint32_t Evaluate();
		Expression();
	};

}
#if defined( _MSC_VER)
#pragma warning(pop)
#elif defined(__GNUC__)
#pragma GCC diagnostic pop
#elif defined(__clang__)
#pragma clang diagnostic pop
#endif

#endif
