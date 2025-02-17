/***********************************************************************
!!!!!! DO NOT MODIFY !!!!!!

Source: ../Resources/Codegen/BindCustomInterface.txt

This file is generated by Workflow compiler
https://github.com/vczh-libraries
***********************************************************************/

#include "BindCustomInterface.h"
/* CodePack:BeginIgnore() */
#ifndef VCZH_DEBUG_NO_REFLECTION
/* CodePack:ConditionOff(VCZH_DEBUG_NO_REFLECTION, BindCustomInterfaceReflection.h) */
#include "BindCustomInterfaceReflection.h"
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

#define GLOBAL_SYMBOL ::vl_workflow_global::BindCustomInterface::
#define GLOBAL_NAME ::vl_workflow_global::BindCustomInterface::Instance().
#define GLOBAL_OBJ &::vl_workflow_global::BindCustomInterface::Instance()

/***********************************************************************
Global Variables
***********************************************************************/

BEGIN_GLOBAL_STORAGE_CLASS(vl_workflow_global_BindCustomInterface)
	vl_workflow_global::BindCustomInterface instance;
	INITIALIZE_GLOBAL_STORAGE_CLASS

		instance.s = ::vl::WString::Unmanaged(L"");
	FINALIZE_GLOBAL_STORAGE_CLASS

		instance.s = ::vl::WString::Empty;
END_GLOBAL_STORAGE_CLASS(vl_workflow_global_BindCustomInterface)

namespace vl_workflow_global
{
/***********************************************************************
Global Functions
***********************************************************************/

	::vl::Ptr<::vl::reflection::description::IValueSubscription> BindCustomInterface::Bind(::vl::Ptr<::ISummer> summer)
	{
		auto subscription = ::vl::Ptr<::vl::reflection::description::IValueSubscription>(new ::vl_workflow_global::__vwsnc1_BindCustomInterface_Bind__vl_reflection_description_IValueSubscription(summer));
		::vl::__vwsn::This(subscription.Obj())->Open();
		::vl::__vwsn::EventAttach(::vl::__vwsn::This(subscription.Obj())->ValueChanged, LAMBDA(::vl_workflow_global::__vwsnf1_BindCustomInterface_Bind_()));
		return subscription;
	}

	void BindCustomInterface::Execute(::vl::Ptr<::IAdder> adder)
	{
		auto subscription = GLOBAL_NAME Bind(::vl::Ptr<::ISummer>(adder));
		{
			auto __vwsn_for_begin_x = static_cast<::vl::vint>(1);
			auto __vwsn_for_end_x = static_cast<::vl::vint>(5);
			auto x = __vwsn_for_begin_x;
			while ((x <= __vwsn_for_end_x))
			{
				{
					::vl::__vwsn::This(adder.Obj())->Add(x);
				}
				(x = (x + static_cast<::vl::vint>(1)));
			}
		}
		::vl::__vwsn::This(subscription.Obj())->Close();
	}

	::vl::WString BindCustomInterface::main()
	{
		GLOBAL_NAME Execute(::vl::Ptr<::IAdder>(new ::vl_workflow_global::__vwsnc2_BindCustomInterface_main__IAdder()));
		return GLOBAL_NAME s;
	}

	BindCustomInterface& BindCustomInterface::Instance()
	{
		return Getvl_workflow_global_BindCustomInterface().instance;
	}

/***********************************************************************
Closures
***********************************************************************/

	//-------------------------------------------------------------------

	__vwsnf1_BindCustomInterface_Bind_::__vwsnf1_BindCustomInterface_Bind_()
	{
	}

	void __vwsnf1_BindCustomInterface_Bind_::operator()(const ::vl::reflection::description::Value& value) const
	{
		(GLOBAL_NAME s = ((((::vl::WString::Unmanaged(L"") + GLOBAL_NAME s) + ::vl::WString::Unmanaged(L"[")) + ::vl::__vwsn::ToString(::vl::__vwsn::Unbox<::vl::vint>(value))) + ::vl::WString::Unmanaged(L"]")));
	}

	//-------------------------------------------------------------------

	__vwsnc1_BindCustomInterface_Bind__vl_reflection_description_IValueSubscription::__vwsnc1_BindCustomInterface_Bind__vl_reflection_description_IValueSubscription(::vl::Ptr<::ISummer> __vwsnctor_summer)
		:summer(__vwsnctor_summer)
	{
		this->__vwsn_bind_cache_0 = ::vl::Ptr<::ISummer>();
		this->__vwsn_bind_handler_0_0 = ::vl::Ptr<::vl::reflection::description::IEventHandler>();
		this->__vwsn_bind_opened_ = false;
		this->__vwsn_bind_closed_ = false;
	}

	void __vwsnc1_BindCustomInterface_Bind__vl_reflection_description_IValueSubscription::__vwsn_bind_activator_()
	{
		auto __vwsn_bind_activator_result_ = ::vl::__vwsn::This(__vwsn_bind_cache_0.Obj())->GetSum();
		::vl::__vwsn::EventInvoke(this->ValueChanged)(::vl::__vwsn::Box(__vwsn_bind_activator_result_));
	}

	void __vwsnc1_BindCustomInterface_Bind__vl_reflection_description_IValueSubscription::__vwsn_bind_callback_0_0()
	{
		this->__vwsn_bind_activator_();
	}

	bool __vwsnc1_BindCustomInterface_Bind__vl_reflection_description_IValueSubscription::Open()
	{
		if ((! __vwsn_bind_opened_))
		{
			(__vwsn_bind_opened_ = true);
			(__vwsn_bind_cache_0 = [&](){ try{ return summer; } catch(...){ return ::vl::Ptr<::ISummer>(); } }());
			(__vwsn_bind_handler_0_0 = [&](){ try{ return ::vl::__vwsn::EventAttach(::vl::__vwsn::This(__vwsn_bind_cache_0.Obj())->SumChanged, ::vl::Func<void()>(this, &__vwsnc1_BindCustomInterface_Bind__vl_reflection_description_IValueSubscription::__vwsn_bind_callback_0_0)); } catch(...){ return ::vl::Ptr<::vl::reflection::description::IEventHandler>(); } }());
			return true;
		}
		return false;
	}

	bool __vwsnc1_BindCustomInterface_Bind__vl_reflection_description_IValueSubscription::Update()
	{
		if ((__vwsn_bind_opened_ && (! __vwsn_bind_closed_)))
		{
			this->__vwsn_bind_activator_();
			return true;
		}
		return false;
	}

	bool __vwsnc1_BindCustomInterface_Bind__vl_reflection_description_IValueSubscription::Close()
	{
		if ((! __vwsn_bind_closed_))
		{
			(__vwsn_bind_closed_ = true);
			if (static_cast<bool>(__vwsn_bind_handler_0_0))
			{
				::vl::__vwsn::EventDetach(::vl::__vwsn::This(__vwsn_bind_cache_0.Obj())->SumChanged, __vwsn_bind_handler_0_0);
				(__vwsn_bind_handler_0_0 = ::vl::Ptr<::vl::reflection::description::IEventHandler>());
			}
			(__vwsn_bind_cache_0 = ::vl::Ptr<::ISummer>());
			(__vwsn_bind_handler_0_0 = ::vl::Ptr<::vl::reflection::description::IEventHandler>());
			return true;
		}
		return false;
	}

	//-------------------------------------------------------------------

	__vwsnc2_BindCustomInterface_main__IAdder::__vwsnc2_BindCustomInterface_main__IAdder()
	{
		this->sum = static_cast<::vl::vint>(0);
	}

	::vl::vint __vwsnc2_BindCustomInterface_main__IAdder::GetSum()
	{
		return sum;
	}

	void __vwsnc2_BindCustomInterface_main__IAdder::Add(::vl::vint value)
	{
		(sum = (sum + value));
		::vl::__vwsn::EventInvoke(this->SumChanged)();
	}

}

/***********************************************************************
Class (::ISummer)
***********************************************************************/

/***********************************************************************
Class (::IAdder)
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
