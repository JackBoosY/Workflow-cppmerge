/***********************************************************************
!!!!!! DO NOT MODIFY !!!!!!

Source: ../Resources/Codegen/NestedLambda.txt

This file is generated by Workflow compiler
https://github.com/vczh-libraries
***********************************************************************/

#include "NestedLambda.h"
/* CodePack:BeginIgnore() */
#ifndef VCZH_DEBUG_NO_REFLECTION
/* CodePack:ConditionOff(VCZH_DEBUG_NO_REFLECTION, NestedLambdaReflection.h) */
#include "NestedLambdaReflection.h"
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

#define GLOBAL_SYMBOL ::vl_workflow_global::NestedLambda::
#define GLOBAL_NAME ::vl_workflow_global::NestedLambda::Instance().
#define GLOBAL_OBJ &::vl_workflow_global::NestedLambda::Instance()

/***********************************************************************
Global Variables
***********************************************************************/

BEGIN_GLOBAL_STORAGE_CLASS(vl_workflow_global_NestedLambda)
	vl_workflow_global::NestedLambda instance;
	INITIALIZE_GLOBAL_STORAGE_CLASS
	FINALIZE_GLOBAL_STORAGE_CLASS
END_GLOBAL_STORAGE_CLASS(vl_workflow_global_NestedLambda)

namespace vl_workflow_global
{
/***********************************************************************
Global Functions
***********************************************************************/

	::vl::WString NestedLambda::main()
	{
		return ::vl::__vwsn::This(::vl::Ptr<::IA>(new ::vl_workflow_global::__vwsnc1_NestedLambda_main__IA()).Obj())->Calculate();
	}

	NestedLambda& NestedLambda::Instance()
	{
		return Getvl_workflow_global_NestedLambda().instance;
	}

/***********************************************************************
Closures
***********************************************************************/

	//-------------------------------------------------------------------

	__vwsnf3_NestedLambda_main_H_Calculate_::__vwsnf3_NestedLambda_main_H_Calculate_(::IB* __vwsnctorthis_0, ::IA* __vwsnctorthis_1)
		:__vwsnthis_0(::vl::__vwsn::This(__vwsnctorthis_0))
		, __vwsnthis_1(::vl::__vwsn::This(__vwsnctorthis_1))
	{
	}

	::vl::vint __vwsnf3_NestedLambda_main_H_Calculate_::operator()() const
	{
		return __vwsnthis_1->GetA();
	}

	//-------------------------------------------------------------------

	__vwsnf4_NestedLambda_main_H_Calculate_::__vwsnf4_NestedLambda_main_H_Calculate_(::IB* __vwsnctorthis_0, ::IA* __vwsnctorthis_1)
		:__vwsnthis_0(::vl::__vwsn::This(__vwsnctorthis_0))
		, __vwsnthis_1(::vl::__vwsn::This(__vwsnctorthis_1))
	{
	}

	::vl::vint __vwsnf4_NestedLambda_main_H_Calculate_::operator()() const
	{
		return (LAMBDA(::vl_workflow_global::__vwsno5_NestedLambda_main_H_Calculate__(__vwsnthis_0, __vwsnthis_1))() + __vwsnthis_0->GetB());
	}

	//-------------------------------------------------------------------

	__vwsnf7_NestedLambda_main_Calculate_::__vwsnf7_NestedLambda_main_Calculate_(::IA* __vwsnctorthis_0)
		:__vwsnthis_0(::vl::__vwsn::This(__vwsnctorthis_0))
	{
	}

	::vl::vint __vwsnf7_NestedLambda_main_Calculate_::operator()() const
	{
		return __vwsnthis_0->GetA();
	}

	//-------------------------------------------------------------------

	__vwsnf8_NestedLambda_main_Calculate_::__vwsnf8_NestedLambda_main_Calculate_(::IA* __vwsnctorthis_0)
		:__vwsnthis_0(::vl::__vwsn::This(__vwsnctorthis_0))
	{
	}

	::vl::vint __vwsnf8_NestedLambda_main_Calculate_::operator()() const
	{
		return LAMBDA(::vl_workflow_global::__vwsno9_NestedLambda_main_Calculate__(__vwsnthis_0))();
	}

	//-------------------------------------------------------------------

	__vwsno1_NestedLambda_main_H_::__vwsno1_NestedLambda_main_H_(::IA* __vwsnctorthis_0)
		:__vwsnthis_0(::vl::__vwsn::This(__vwsnctorthis_0))
	{
	}

	::vl::WString __vwsno1_NestedLambda_main_H_::operator()() const
	{
		return ::vl::__vwsn::This(::vl::Ptr<::IB>(new ::vl_workflow_global::__vwsnc2_NestedLambda_main_H__IB(__vwsnthis_0)).Obj())->Calculate();
	}

	//-------------------------------------------------------------------

	__vwsno2_NestedLambda_main_H_Calculate_::__vwsno2_NestedLambda_main_H_Calculate_(::IB* __vwsnctorthis_0, ::IA* __vwsnctorthis_1)
		:__vwsnthis_0(::vl::__vwsn::This(__vwsnctorthis_0))
		, __vwsnthis_1(::vl::__vwsn::This(__vwsnctorthis_1))
	{
	}

	::vl::vint __vwsno2_NestedLambda_main_H_Calculate_::operator()() const
	{
		return (LAMBDA(::vl_workflow_global::__vwsnf3_NestedLambda_main_H_Calculate_(__vwsnthis_0, __vwsnthis_1))() + __vwsnthis_0->GetB());
	}

	//-------------------------------------------------------------------

	__vwsno5_NestedLambda_main_H_Calculate__::__vwsno5_NestedLambda_main_H_Calculate__(::IB* __vwsnctorthis_0, ::IA* __vwsnctorthis_1)
		:__vwsnthis_0(::vl::__vwsn::This(__vwsnctorthis_0))
		, __vwsnthis_1(::vl::__vwsn::This(__vwsnctorthis_1))
	{
	}

	::vl::vint __vwsno5_NestedLambda_main_H_Calculate__::operator()() const
	{
		return __vwsnthis_1->GetA();
	}

	//-------------------------------------------------------------------

	__vwsno6_NestedLambda_main_Calculate_::__vwsno6_NestedLambda_main_Calculate_(::IA* __vwsnctorthis_0)
		:__vwsnthis_0(::vl::__vwsn::This(__vwsnctorthis_0))
	{
	}

	::vl::vint __vwsno6_NestedLambda_main_Calculate_::operator()() const
	{
		return LAMBDA(::vl_workflow_global::__vwsnf7_NestedLambda_main_Calculate_(__vwsnthis_0))();
	}

	//-------------------------------------------------------------------

	__vwsno9_NestedLambda_main_Calculate__::__vwsno9_NestedLambda_main_Calculate__(::IA* __vwsnctorthis_0)
		:__vwsnthis_0(::vl::__vwsn::This(__vwsnctorthis_0))
	{
	}

	::vl::vint __vwsno9_NestedLambda_main_Calculate__::operator()() const
	{
		return __vwsnthis_0->GetA();
	}

	//-------------------------------------------------------------------

	__vwsnc1_NestedLambda_main__IA::__vwsnc1_NestedLambda_main__IA()
	{
		this->a = static_cast<::vl::vint>(0);
	}

	::vl::vint __vwsnc1_NestedLambda_main__IA::GetA()
	{
		return a;
	}

	void __vwsnc1_NestedLambda_main__IA::SetA(::vl::vint value)
	{
		(a = value);
		::vl::__vwsn::EventInvoke(this->AChanged)();
	}

	::vl::WString __vwsnc1_NestedLambda_main__IA::H()
	{
		return LAMBDA(::vl_workflow_global::__vwsno1_NestedLambda_main_H_(this))();
	}

	::vl::WString __vwsnc1_NestedLambda_main__IA::Calculate()
	{
		auto f = LAMBDA(::vl_workflow_global::__vwsno6_NestedLambda_main_Calculate_(this));
		auto g = LAMBDA(::vl_workflow_global::__vwsnf8_NestedLambda_main_Calculate_(this));
		auto h = ::vl::Func<::vl::WString()>(this, &__vwsnc1_NestedLambda_main__IA::H);
		auto s = ::vl::WString::Unmanaged(L"");
		(a = static_cast<::vl::vint>(1));
		(s = (s + ((::vl::WString::Unmanaged(L"[") + ::vl::__vwsn::ToString(f())) + ::vl::WString::Unmanaged(L"]"))));
		this->SetA(static_cast<::vl::vint>(2));
		(s = (s + ((::vl::WString::Unmanaged(L"[") + ::vl::__vwsn::ToString(g())) + ::vl::WString::Unmanaged(L"]"))));
		this->SetA((this->GetA() + static_cast<::vl::vint>(1)));
		(s = (s + ((::vl::WString::Unmanaged(L"[") + h()) + ::vl::WString::Unmanaged(L"]"))));
		return s;
	}

	//-------------------------------------------------------------------

	__vwsnc2_NestedLambda_main_H__IB::__vwsnc2_NestedLambda_main_H__IB(::IA* __vwsnctorthis_0)
		:__vwsnthis_0(::vl::__vwsn::This(__vwsnctorthis_0))
	{
		this->b = static_cast<::vl::vint>(0);
	}

	::vl::vint __vwsnc2_NestedLambda_main_H__IB::GetB()
	{
		return b;
	}

	void __vwsnc2_NestedLambda_main_H__IB::SetB(::vl::vint value)
	{
		(b = value);
		::vl::__vwsn::EventInvoke(this->BChanged)();
	}

	::vl::WString __vwsnc2_NestedLambda_main_H__IB::H()
	{
		return ((((::vl::WString::Unmanaged(L"[") + ::vl::__vwsn::ToString(__vwsnthis_0->GetA())) + ::vl::WString::Unmanaged(L", ")) + ::vl::__vwsn::ToString(this->GetB())) + ::vl::WString::Unmanaged(L"]"));
	}

	::vl::WString __vwsnc2_NestedLambda_main_H__IB::Calculate()
	{
		auto f = LAMBDA(::vl_workflow_global::__vwsno2_NestedLambda_main_H_Calculate_(this, __vwsnthis_0));
		auto g = LAMBDA(::vl_workflow_global::__vwsnf4_NestedLambda_main_H_Calculate_(this, __vwsnthis_0));
		auto h = ::vl::Func<::vl::WString()>(this, &__vwsnc2_NestedLambda_main_H__IB::H);
		auto s = ::vl::WString::Unmanaged(L"");
		(b = static_cast<::vl::vint>(1));
		(s = (s + ((::vl::WString::Unmanaged(L"[") + ::vl::__vwsn::ToString(f())) + ::vl::WString::Unmanaged(L"]"))));
		this->SetB(static_cast<::vl::vint>(2));
		(s = (s + ((::vl::WString::Unmanaged(L"[") + ::vl::__vwsn::ToString(g())) + ::vl::WString::Unmanaged(L"]"))));
		this->SetB((this->GetB() + static_cast<::vl::vint>(10)));
		(s = (s + ((::vl::WString::Unmanaged(L"[") + h()) + ::vl::WString::Unmanaged(L"]"))));
		return s;
	}

}

/***********************************************************************
Class (::IA)
***********************************************************************/

/***********************************************************************
Class (::IB)
***********************************************************************/

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
