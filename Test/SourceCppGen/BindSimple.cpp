/***********************************************************************
!!!!!! DO NOT MODIFY !!!!!!

Source: ../Resources/Codegen/BindSimple.txt

This file is generated by Workflow compiler
https://github.com/vczh-libraries
***********************************************************************/

#include "BindSimple.h"
/* CodePack:BeginIgnore() */
#ifndef VCZH_DEBUG_NO_REFLECTION
/* CodePack:ConditionOff(VCZH_DEBUG_NO_REFLECTION, BindSimpleReflection.h) */
#include "BindSimpleReflection.h"
#endif
/* CodePack:EndIgnore() */

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

#define GLOBAL_SYMBOL ::vl_workflow_global::BindSimple::
#define GLOBAL_NAME ::vl_workflow_global::BindSimple::Instance().
#define GLOBAL_OBJ &::vl_workflow_global::BindSimple::Instance()
#define USERIMPL(...)

/***********************************************************************
Global Variables
***********************************************************************/

BEGIN_GLOBAL_STORAGE_CLASS(vl_workflow_global_BindSimple)
	vl_workflow_global::BindSimple instance;
	INITIALIZE_GLOBAL_STORAGE_CLASS
	FINALIZE_GLOBAL_STORAGE_CLASS
END_GLOBAL_STORAGE_CLASS(vl_workflow_global_BindSimple)

namespace vl_workflow_global
{
/***********************************************************************
Global Functions
***********************************************************************/

	::vl::WString BindSimple::main()
	{
		auto derived = ::vl::Ptr<::Derived>(new ::Derived());
		::vl::__vwsn::This(derived.Obj())->Execute();
		return ::vl::__vwsn::This(derived.Obj())->s;
	}

	BindSimple& BindSimple::Instance()
	{
		return Getvl_workflow_global_BindSimple().instance;
	}

/***********************************************************************
Closures
***********************************************************************/

	//-------------------------------------------------------------------

	__vwsnf1_BindSimple_OuterClass_Base_Initialize_::__vwsnf1_BindSimple_OuterClass_Base_Initialize_(::OuterClass::Base* __vwsnctorthis_0)
		:__vwsnthis_0(::vl::__vwsn::This(__vwsnctorthis_0))
	{
	}

	void __vwsnf1_BindSimple_OuterClass_Base_Initialize_::operator()(const ::vl::reflection::description::Value& value) const
	{
		(__vwsnthis_0->s = ((((::vl::WString(L"", false) + __vwsnthis_0->s) + ::vl::WString(L"[", false)) + ::vl::__vwsn::ToString(::vl::__vwsn::Unbox<::vl::vint>(value))) + ::vl::WString(L"]", false)));
	}

	//-------------------------------------------------------------------

	__vwsnc1_BindSimple_OuterClass_Base_Initialize__vl_reflection_description_IValueSubscription::__vwsnc1_BindSimple_OuterClass_Base_Initialize__vl_reflection_description_IValueSubscription(::Derived* __vwsnctor_derived, ::OuterClass::Base* __vwsnctorthis_0)
		:derived(__vwsnctor_derived)
		, __vwsnthis_0(::vl::__vwsn::This(__vwsnctorthis_0))
	{
		this->__vwsn_bind_cache_0 = ::vl::Ptr<::test::ObservableValue>();
		this->__vwsn_bind_cache_1 = ::vl::Ptr<::test::ObservableValue>();
		this->__vwsn_bind_cache_2 = ::vl::Ptr<::test::ObservableValue>();
		this->__vwsn_bind_handler_0_0 = ::vl::Ptr<::vl::reflection::description::IEventHandler>();
		this->__vwsn_bind_handler_1_0 = ::vl::Ptr<::vl::reflection::description::IEventHandler>();
		this->__vwsn_bind_handler_2_0 = ::vl::Ptr<::vl::reflection::description::IEventHandler>();
		this->__vwsn_bind_opened_ = false;
		this->__vwsn_bind_closed_ = false;
	}

	void __vwsnc1_BindSimple_OuterClass_Base_Initialize__vl_reflection_description_IValueSubscription::__vwsn_bind_activator_()
	{
		auto __vwsn_bind_activator_result_ = ((::vl::__vwsn::This(__vwsn_bind_cache_0.Obj())->GetValue() + ::vl::__vwsn::This(__vwsn_bind_cache_1.Obj())->GetValue()) + ::vl::__vwsn::This(__vwsn_bind_cache_2.Obj())->GetValue());
		::vl::__vwsn::EventInvoke(this->ValueChanged)(::vl::__vwsn::Box(__vwsn_bind_activator_result_));
	}

	void __vwsnc1_BindSimple_OuterClass_Base_Initialize__vl_reflection_description_IValueSubscription::__vwsn_bind_callback_0_0(::vl::vint __vwsn_bind_callback_argument_0, ::vl::vint __vwsn_bind_callback_argument_1)
	{
		this->__vwsn_bind_activator_();
	}

	void __vwsnc1_BindSimple_OuterClass_Base_Initialize__vl_reflection_description_IValueSubscription::__vwsn_bind_callback_1_0(::vl::vint __vwsn_bind_callback_argument_0, ::vl::vint __vwsn_bind_callback_argument_1)
	{
		this->__vwsn_bind_activator_();
	}

	void __vwsnc1_BindSimple_OuterClass_Base_Initialize__vl_reflection_description_IValueSubscription::__vwsn_bind_callback_2_0(::vl::vint __vwsn_bind_callback_argument_0, ::vl::vint __vwsn_bind_callback_argument_1)
	{
		this->__vwsn_bind_activator_();
	}

	bool __vwsnc1_BindSimple_OuterClass_Base_Initialize__vl_reflection_description_IValueSubscription::Open()
	{
		if ((! __vwsn_bind_opened_))
		{
			(__vwsn_bind_opened_ = true);
			(__vwsn_bind_cache_0 = ::vl::__vwsn::This(derived)->x);
			(__vwsn_bind_cache_1 = ::vl::__vwsn::This(derived)->y);
			(__vwsn_bind_cache_2 = ::vl::__vwsn::This(derived)->z);
			(__vwsn_bind_handler_0_0 = ::vl::__vwsn::EventAttach(::vl::__vwsn::This(__vwsn_bind_cache_0.Obj())->ValueChanged, ::vl::Func<void(::vl::vint, ::vl::vint)>(this, &__vwsnc1_BindSimple_OuterClass_Base_Initialize__vl_reflection_description_IValueSubscription::__vwsn_bind_callback_0_0)));
			(__vwsn_bind_handler_1_0 = ::vl::__vwsn::EventAttach(::vl::__vwsn::This(__vwsn_bind_cache_1.Obj())->ValueChanged, ::vl::Func<void(::vl::vint, ::vl::vint)>(this, &__vwsnc1_BindSimple_OuterClass_Base_Initialize__vl_reflection_description_IValueSubscription::__vwsn_bind_callback_1_0)));
			(__vwsn_bind_handler_2_0 = ::vl::__vwsn::EventAttach(::vl::__vwsn::This(__vwsn_bind_cache_2.Obj())->ValueChanged, ::vl::Func<void(::vl::vint, ::vl::vint)>(this, &__vwsnc1_BindSimple_OuterClass_Base_Initialize__vl_reflection_description_IValueSubscription::__vwsn_bind_callback_2_0)));
			return true;
		}
		return false;
	}

	bool __vwsnc1_BindSimple_OuterClass_Base_Initialize__vl_reflection_description_IValueSubscription::Update()
	{
		if ((__vwsn_bind_opened_ && (! __vwsn_bind_closed_)))
		{
			this->__vwsn_bind_activator_();
			return true;
		}
		return false;
	}

	bool __vwsnc1_BindSimple_OuterClass_Base_Initialize__vl_reflection_description_IValueSubscription::Close()
	{
		if ((! __vwsn_bind_closed_))
		{
			(__vwsn_bind_closed_ = true);
			::vl::__vwsn::EventDetach(::vl::__vwsn::This(__vwsn_bind_cache_0.Obj())->ValueChanged, __vwsn_bind_handler_0_0);
			::vl::__vwsn::EventDetach(::vl::__vwsn::This(__vwsn_bind_cache_1.Obj())->ValueChanged, __vwsn_bind_handler_1_0);
			::vl::__vwsn::EventDetach(::vl::__vwsn::This(__vwsn_bind_cache_2.Obj())->ValueChanged, __vwsn_bind_handler_2_0);
			(__vwsn_bind_cache_0 = ::vl::Ptr<::test::ObservableValue>());
			(__vwsn_bind_cache_1 = ::vl::Ptr<::test::ObservableValue>());
			(__vwsn_bind_cache_2 = ::vl::Ptr<::test::ObservableValue>());
			(__vwsn_bind_handler_0_0 = ::vl::Ptr<::vl::reflection::description::IEventHandler>());
			(__vwsn_bind_handler_1_0 = ::vl::Ptr<::vl::reflection::description::IEventHandler>());
			(__vwsn_bind_handler_2_0 = ::vl::Ptr<::vl::reflection::description::IEventHandler>());
			return true;
		}
		return false;
	}

}

/***********************************************************************
Class (::OuterClass)
***********************************************************************/

OuterClass::OuterClass()
{
}

/***********************************************************************
Class (::OuterClass::Base)
***********************************************************************/

void OuterClass::Base::Initialize(::Derived* derived)
{
	(this->subscription = ::vl::Ptr<::vl::reflection::description::IValueSubscription>(new ::vl_workflow_global::__vwsnc1_BindSimple_OuterClass_Base_Initialize__vl_reflection_description_IValueSubscription(derived, this)));
	::vl::__vwsn::This(this->subscription.Obj())->Open();
	::vl::__vwsn::EventAttach(::vl::__vwsn::This(this->subscription.Obj())->ValueChanged, LAMBDA(::vl_workflow_global::__vwsnf1_BindSimple_OuterClass_Base_Initialize_(this)));
}

OuterClass::Base::Base()
	: subscription(::vl::Ptr<::vl::reflection::description::IValueSubscription>())
	, s(::vl::WString(L"", false))
{
}

/***********************************************************************
Class (::Derived)
***********************************************************************/

Derived::Derived()
	: x(::vl::Ptr<::test::ObservableValue>(new ::test::ObservableValue()))
	, y(::vl::Ptr<::test::ObservableValue>(new ::test::ObservableValue()))
	, z(::vl::Ptr<::test::ObservableValue>(new ::test::ObservableValue()))
{
	this->Initialize(this);
}

void Derived::Execute()
{
	::vl::__vwsn::This(this->x.Obj())->SetValue(static_cast<::vl::vint>(10));
	::vl::__vwsn::This(this->y.Obj())->SetValue(static_cast<::vl::vint>(20));
	::vl::__vwsn::This(this->z.Obj())->SetValue(static_cast<::vl::vint>(30));
	::vl::__vwsn::This(this->subscription.Obj())->Close();
}

#undef GLOBAL_SYMBOL
#undef GLOBAL_NAME
#undef GLOBAL_OBJ
#undef USERIMPL

#if defined( _MSC_VER)
#pragma warning(pop)
#elif defined(__GNUC__)
#pragma GCC diagnostic pop
#elif defined(__clang__)
#pragma clang diagnostic pop
#endif
