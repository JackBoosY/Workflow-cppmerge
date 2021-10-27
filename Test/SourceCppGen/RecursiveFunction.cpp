/***********************************************************************
!!!!!! DO NOT MODIFY !!!!!!

Source: ../Resources/Codegen/RecursiveFunction.txt

This file is generated by Workflow compiler
https://github.com/vczh-libraries
***********************************************************************/

#include "RecursiveFunction.h"

#if defined( _MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#elif defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wparentheses-equality"
#elif defined(__GNUC__)
#pragma GCC diagnostic push
#endif

#define GLOBAL_SYMBOL ::vl_workflow_global::RecursiveFunction::
#define GLOBAL_NAME ::vl_workflow_global::RecursiveFunction::Instance().
#define GLOBAL_OBJ &::vl_workflow_global::RecursiveFunction::Instance()

/***********************************************************************
Global Variables
***********************************************************************/

BEGIN_GLOBAL_STORAGE_CLASS(vl_workflow_global_RecursiveFunction)
	vl_workflow_global::RecursiveFunction instance;
	INITIALIZE_GLOBAL_STORAGE_CLASS
	FINALIZE_GLOBAL_STORAGE_CLASS
END_GLOBAL_STORAGE_CLASS(vl_workflow_global_RecursiveFunction)

namespace vl_workflow_global
{
/***********************************************************************
Global Functions
***********************************************************************/

	::vl::vint RecursiveFunction::Fib(::vl::vint n)
	{
		return ((n <= static_cast<::vl::vint>(2)) ? static_cast<::vl::vint>(1) : (GLOBAL_NAME Fib((n - static_cast<::vl::vint>(1))) + GLOBAL_NAME Fib((n - static_cast<::vl::vint>(2)))));
	}

	::vl::WString RecursiveFunction::main()
	{
		return ((((((((::vl::__vwsn::ToString(GLOBAL_NAME Fib(static_cast<::vl::vint>(1))) + ::vl::WString::Unmanaged(L", ")) + ::vl::__vwsn::ToString(GLOBAL_NAME Fib(static_cast<::vl::vint>(2)))) + ::vl::WString::Unmanaged(L", ")) + ::vl::__vwsn::ToString(GLOBAL_NAME Fib(static_cast<::vl::vint>(3)))) + ::vl::WString::Unmanaged(L", ")) + ::vl::__vwsn::ToString(GLOBAL_NAME Fib(static_cast<::vl::vint>(4)))) + ::vl::WString::Unmanaged(L", ")) + ::vl::__vwsn::ToString(GLOBAL_NAME Fib(static_cast<::vl::vint>(5))));
	}

	RecursiveFunction& RecursiveFunction::Instance()
	{
		return Getvl_workflow_global_RecursiveFunction().instance;
	}
}

#undef GLOBAL_SYMBOL
#undef GLOBAL_NAME
#undef GLOBAL_OBJ

#if defined( _MSC_VER)
#pragma warning(pop)
#elif defined(__clang__)
#pragma clang diagnostic pop
#elif defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
