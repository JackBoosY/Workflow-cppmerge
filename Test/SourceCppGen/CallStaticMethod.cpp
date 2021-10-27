/***********************************************************************
!!!!!! DO NOT MODIFY !!!!!!

Source: ../Resources/Codegen/CallStaticMethod.txt

This file is generated by Workflow compiler
https://github.com/vczh-libraries
***********************************************************************/

#include "CallStaticMethod.h"
/* CodePack:BeginIgnore() */
#ifndef VCZH_DEBUG_NO_REFLECTION
/* CodePack:ConditionOff(VCZH_DEBUG_NO_REFLECTION, CallStaticMethodReflection.h) */
#include "CallStaticMethodReflection.h"
#endif
/* CodePack:EndIgnore() */

#if defined( _MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#elif defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wparentheses-equality"
#elif defined(__GNUC__)
#pragma GCC diagnostic push
#endif

#define GLOBAL_SYMBOL ::vl_workflow_global::CallStaticMethod::
#define GLOBAL_NAME ::vl_workflow_global::CallStaticMethod::Instance().
#define GLOBAL_OBJ &::vl_workflow_global::CallStaticMethod::Instance()

/***********************************************************************
Global Variables
***********************************************************************/

BEGIN_GLOBAL_STORAGE_CLASS(vl_workflow_global_CallStaticMethod)
	vl_workflow_global::CallStaticMethod instance;
	INITIALIZE_GLOBAL_STORAGE_CLASS
	FINALIZE_GLOBAL_STORAGE_CLASS
END_GLOBAL_STORAGE_CLASS(vl_workflow_global_CallStaticMethod)

namespace vl_workflow_global
{
/***********************************************************************
Global Functions
***********************************************************************/

	::vl::WString CallStaticMethod::main()
	{
		return ::vl::__vwsn::ToString(::Calculator::Internal::Sum(static_cast<::vl::vint>(1), static_cast<::vl::vint>(10)));
	}

	CallStaticMethod& CallStaticMethod::Instance()
	{
		return Getvl_workflow_global_CallStaticMethod().instance;
	}
}

/***********************************************************************
Class (::Calculator)
***********************************************************************/

::vl::vint Calculator::Sum2(::vl::vint begin, ::vl::vint end, ::vl::vint sum)
{
	if ((begin > end))
	{
		return sum;
	}
	else
	{
		return ::Calculator::Sum2((begin + static_cast<::vl::vint>(1)), end, (sum + begin));
	}
}

Calculator::Calculator()
{
}

/***********************************************************************
Class (::Calculator::Internal)
***********************************************************************/

::vl::vint Calculator::Internal::Sum(::vl::vint begin, ::vl::vint end)
{
	return ::Calculator::Sum2(begin, end, static_cast<::vl::vint>(0));
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
