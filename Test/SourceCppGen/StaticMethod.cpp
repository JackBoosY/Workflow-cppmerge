/***********************************************************************
!!!!!! DO NOT MODIFY !!!!!!

Source: ../Resources/Codegen/StaticMethod.txt

This file is generated by Workflow compiler
https://github.com/vczh-libraries
***********************************************************************/

#include "StaticMethod.h"

#if defined( _MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#elif defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wparentheses-equality"
#elif defined(__GNUC__)
#pragma GCC diagnostic push
#endif

#define GLOBAL_SYMBOL ::vl_workflow_global::StaticMethod::
#define GLOBAL_NAME ::vl_workflow_global::StaticMethod::Instance().
#define GLOBAL_OBJ &::vl_workflow_global::StaticMethod::Instance()

/***********************************************************************
Global Variables
***********************************************************************/

BEGIN_GLOBAL_STORAGE_CLASS(vl_workflow_global_StaticMethod)
	vl_workflow_global::StaticMethod instance;
	INITIALIZE_GLOBAL_STORAGE_CLASS
	FINALIZE_GLOBAL_STORAGE_CLASS
END_GLOBAL_STORAGE_CLASS(vl_workflow_global_StaticMethod)

namespace vl_workflow_global
{
/***********************************************************************
Global Functions
***********************************************************************/

	::vl::Ptr<::test::ObservableValue> StaticMethod::Create2(::vl::vint value, const ::vl::WString& name)
	{
		return ::test::ObservableValue::Create(value, name);
	}

	::vl::WString StaticMethod::main()
	{
		auto create1 = ::vl::Func<::vl::Ptr<::test::ObservableValue>(::vl::vint, const ::vl::WString&)>(&::test::ObservableValue::Create);
		auto create2 = ::vl::Func<::vl::Ptr<::test::ObservableValue>(::vl::vint, const ::vl::WString&)>(GLOBAL_OBJ, &GLOBAL_SYMBOL Create2);
		auto o1 = create1(static_cast<::vl::vint>(1), ::vl::WString::Unmanaged(L"one"));
		auto o2 = GLOBAL_NAME Create2(static_cast<::vl::vint>(2), ::vl::WString::Unmanaged(L"two"));
		return ((((((::vl::__vwsn::ToString(::vl::__vwsn::This(o1.Obj())->GetValue()) + ::vl::WString::Unmanaged(L", ")) + ::vl::__vwsn::This(o1.Obj())->GetDisplayName()) + ::vl::WString::Unmanaged(L", ")) + ::vl::__vwsn::ToString(::vl::__vwsn::This(o2.Obj())->GetValue())) + ::vl::WString::Unmanaged(L", ")) + ::vl::__vwsn::This(o2.Obj())->GetDisplayName());
	}

	StaticMethod& StaticMethod::Instance()
	{
		return Getvl_workflow_global_StaticMethod().instance;
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
