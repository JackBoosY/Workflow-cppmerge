/***********************************************************************
!!!!!! DO NOT MODIFY !!!!!!

Source: ../Resources/Codegen/WorkflowHints.txt

This file is generated by Workflow compiler
https://github.com/vczh-libraries
***********************************************************************/

#ifndef VCZH_WORKFLOW_COMPILER_GENERATED_WORKFLOWHINTS
#define VCZH_WORKFLOW_COMPILER_GENERATED_WORKFLOWHINTS

#include "../Source/CppTypes.h"

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

namespace workflow
{
	namespace hints
	{
		class Base;
		class Derived;

		class Base : public ::vl::Object, public ::vl::reflection::Description<Base>
		{
		public:

			Base();
			Base(::vl::vint32_t x);
		};

		class Derived : public ::workflow::hints::Base, public ::vl::reflection::Description<Derived>
		{
		public:

			Derived();
			Derived(::vl::vint32_t x);
		};
	}
}

/***********************************************************************
Global Variables and Functions
***********************************************************************/

namespace vl_workflow_global
{
	class WorkflowHints
	{
	public:

		void Ensure(bool condition);
		void ExtraTests();
		::vl::WString main();

		static WorkflowHints& Instance();
	};
}

/***********************************************************************
Reflection
***********************************************************************/

namespace vl
{
	namespace reflection
	{
		namespace description
		{
#ifndef VCZH_DEBUG_NO_REFLECTION
			DECL_TYPE_INFO(::workflow::hints::Base)
			DECL_TYPE_INFO(::workflow::hints::Derived)
#endif

			extern bool LoadWorkflowHintsTypes();
		}
	}
}

#if defined( _MSC_VER)
#pragma warning(pop)
#elif defined(__GNUC__)
#pragma GCC diagnostic pop
#elif defined(__clang__)
#pragma clang diagnostic pop
#endif

#endif
