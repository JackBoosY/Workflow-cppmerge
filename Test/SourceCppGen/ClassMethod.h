/***********************************************************************
!!!!!! DO NOT MODIFY !!!!!!

Source: ../Resources/Codegen/ClassMethod.txt

This file is generated by Workflow compiler
https://github.com/vczh-libraries
***********************************************************************/

#ifndef VCZH_WORKFLOW_COMPILER_GENERATED_CLASSMETHOD
#define VCZH_WORKFLOW_COMPILER_GENERATED_CLASSMETHOD

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

namespace vl_workflow_global
{
	struct __vwsnf1_ClassMethod_main_;
}

class Methods;

class Methods : public ::vl::Object, public ::vl::reflection::Description<Methods>
{
#ifndef VCZH_DEBUG_NO_REFLECTION
	friend struct ::vl::reflection::description::CustomTypeDescriptorSelector<Methods>;
#endif
public:
	::vl::vint x;
	Methods();
	Methods(::vl::vint _x);
	::vl::vint GetX();
	void SetX(::vl::vint _x);
	::vl::Event<void()> XChanged;
};

/***********************************************************************
Global Variables and Functions
***********************************************************************/

namespace vl_workflow_global
{
	class ClassMethod
	{
	public:

		::vl::WString s;

		::vl::WString main();

		static ClassMethod& Instance();
	};

/***********************************************************************
Closures
***********************************************************************/

	struct __vwsnf1_ClassMethod_main_
	{
		::vl::Ptr<::Methods> a;

		__vwsnf1_ClassMethod_main_(::vl::Ptr<::Methods> __vwsnctor_a);

		void operator()() const;
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
