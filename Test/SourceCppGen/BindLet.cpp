/***********************************************************************
!!!!!! DO NOT MODIFY !!!!!!

Source: ../Resources/Codegen/BindLet.txt

This file is generated by Workflow compiler
https://github.com/vczh-libraries
***********************************************************************/

#include "BindLet.h"
/* CodePack:BeginIgnore() */
#ifndef VCZH_DEBUG_NO_REFLECTION
/* CodePack:ConditionOff(VCZH_DEBUG_NO_REFLECTION, BindLetReflection.h) */
#include "BindLetReflection.h"
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

#define GLOBAL_SYMBOL ::vl_workflow_global::BindLet::
#define GLOBAL_NAME ::vl_workflow_global::BindLet::Instance().
#define GLOBAL_OBJ &::vl_workflow_global::BindLet::Instance()

/***********************************************************************
Global Variables
***********************************************************************/

BEGIN_GLOBAL_STORAGE_CLASS(vl_workflow_global_BindLet)
	vl_workflow_global::BindLet instance;
	INITIALIZE_GLOBAL_STORAGE_CLASS

		instance.s = ::vl::WString::Unmanaged(L"");
	FINALIZE_GLOBAL_STORAGE_CLASS

		instance.s = ::vl::WString::Empty;
END_GLOBAL_STORAGE_CLASS(vl_workflow_global_BindLet)

namespace vl_workflow_global
{
/***********************************************************************
Global Functions
***********************************************************************/

	void BindLet::Callback(const ::vl::reflection::description::Value& value)
	{
		(GLOBAL_NAME s = ((((::vl::WString::Unmanaged(L"") + GLOBAL_NAME s) + ::vl::WString::Unmanaged(L"[")) + ::vl::__vwsn::ToString(::vl::__vwsn::Unbox<::vl::vint>(value))) + ::vl::WString::Unmanaged(L"]")));
	}

	::vl::WString BindLet::main()
	{
		auto x = ::vl::Ptr<::Foo>(new ::Foo());
		auto y = ::vl::Ptr<::Foo>(new ::Foo());
		auto z = ::vl::Ptr<::Foo>(new ::Foo());
		auto subscription = ::vl::Ptr<::vl::reflection::description::IValueSubscription>(new ::vl_workflow_global::__vwsnc1_BindLet_main__vl_reflection_description_IValueSubscription(x, y, z));
		::vl::__vwsn::This(subscription.Obj())->Open();
		::vl::__vwsn::EventAttach(::vl::__vwsn::This(subscription.Obj())->ValueChanged, ::vl::Func<void(const ::vl::reflection::description::Value&)>(GLOBAL_OBJ, &GLOBAL_SYMBOL Callback));
		::vl::__vwsn::This(x.Obj())->Setbar(::vl::Ptr<::Bar>(new ::Bar(static_cast<::vl::vint>(1))));
		::vl::__vwsn::This(::vl::__vwsn::This(x.Obj())->Getbar().Obj())->Setvalue(static_cast<::vl::vint>(2));
		::vl::__vwsn::This(y.Obj())->Setbar(::vl::Ptr<::Bar>(new ::Bar(static_cast<::vl::vint>(10))));
		::vl::__vwsn::This(::vl::__vwsn::This(y.Obj())->Getbar().Obj())->Setvalue(static_cast<::vl::vint>(20));
		::vl::__vwsn::This(z.Obj())->Setbar(::vl::Ptr<::Bar>(new ::Bar(static_cast<::vl::vint>(100))));
		::vl::__vwsn::This(::vl::__vwsn::This(z.Obj())->Getbar().Obj())->Setvalue(static_cast<::vl::vint>(200));
		::vl::__vwsn::This(subscription.Obj())->Close();
		return GLOBAL_NAME s;
	}

	BindLet& BindLet::Instance()
	{
		return Getvl_workflow_global_BindLet().instance;
	}

/***********************************************************************
Closures
***********************************************************************/

	//-------------------------------------------------------------------

	__vwsnc1_BindLet_main__vl_reflection_description_IValueSubscription::__vwsnc1_BindLet_main__vl_reflection_description_IValueSubscription(::vl::Ptr<::Foo> __vwsnctor_x, ::vl::Ptr<::Foo> __vwsnctor_y, ::vl::Ptr<::Foo> __vwsnctor_z)
		:x(__vwsnctor_x)
		, y(__vwsnctor_y)
		, z(__vwsnctor_z)
	{
		this->__vwsn_bind_cache_0 = ::vl::Ptr<::Foo>();
		this->__vwsn_bind_cache_1 = ::vl::Ptr<::Foo>();
		this->__vwsn_bind_cache_2 = ::vl::Ptr<::Bar>();
		this->__vwsn_bind_cache_3 = ::vl::Ptr<::Foo>();
		this->__vwsn_bind_cache_4 = ::vl::Ptr<::Bar>();
		this->__vwsn_bind_cache_5 = ::vl::Ptr<::Bar>();
		this->__vwsn_bind_handler_0_0 = ::vl::Ptr<::vl::reflection::description::IEventHandler>();
		this->__vwsn_bind_handler_1_0 = ::vl::Ptr<::vl::reflection::description::IEventHandler>();
		this->__vwsn_bind_handler_2_0 = ::vl::Ptr<::vl::reflection::description::IEventHandler>();
		this->__vwsn_bind_handler_3_0 = ::vl::Ptr<::vl::reflection::description::IEventHandler>();
		this->__vwsn_bind_handler_4_0 = ::vl::Ptr<::vl::reflection::description::IEventHandler>();
		this->__vwsn_bind_handler_5_0 = ::vl::Ptr<::vl::reflection::description::IEventHandler>();
		this->__vwsn_bind_handler_6_0 = ::vl::Ptr<::vl::reflection::description::IEventHandler>();
		this->__vwsn_bind_opened_ = false;
		this->__vwsn_bind_closed_ = false;
	}

	void __vwsnc1_BindLet_main__vl_reflection_description_IValueSubscription::__vwsn_bind_activator_()
	{
		auto __vwsn_bind_activator_result_ = [&](auto _z){ return ((::vl::__vwsn::This(__vwsn_bind_cache_4.Obj())->Getvalue() + (::vl::__vwsn::This(__vwsn_bind_cache_5.Obj())->Getvalue() + ::vl::__vwsn::This(__vwsn_bind_cache_5.Obj())->Getvalue())) + ((_z + _z) + _z)); }(::vl::__vwsn::This(__vwsn_bind_cache_2.Obj())->Getvalue());
		::vl::__vwsn::EventInvoke(this->ValueChanged)(::vl::__vwsn::Box(__vwsn_bind_activator_result_));
	}

	void __vwsnc1_BindLet_main__vl_reflection_description_IValueSubscription::__vwsn_bind_callback_0_0()
	{
		if (static_cast<bool>(__vwsn_bind_handler_6_0))
		{
			::vl::__vwsn::EventDetach(::vl::__vwsn::This(__vwsn_bind_cache_5.Obj())->valueChanged, __vwsn_bind_handler_6_0);
			(__vwsn_bind_handler_6_0 = ::vl::Ptr<::vl::reflection::description::IEventHandler>());
		}
		if (static_cast<bool>(__vwsn_bind_handler_5_0))
		{
			::vl::__vwsn::EventDetach(::vl::__vwsn::This(__vwsn_bind_cache_5.Obj())->valueChanged, __vwsn_bind_handler_5_0);
			(__vwsn_bind_handler_5_0 = ::vl::Ptr<::vl::reflection::description::IEventHandler>());
		}
		(__vwsn_bind_cache_5 = [&](){ try{ return ::vl::__vwsn::This(__vwsn_bind_cache_0.Obj())->Getbar(); } catch(...){ return ::vl::Ptr<::Bar>(); } }());
		(__vwsn_bind_handler_5_0 = [&](){ try{ return ::vl::__vwsn::EventAttach(::vl::__vwsn::This(__vwsn_bind_cache_5.Obj())->valueChanged, ::vl::Func<void()>(this, &__vwsnc1_BindLet_main__vl_reflection_description_IValueSubscription::__vwsn_bind_callback_5_0)); } catch(...){ return ::vl::Ptr<::vl::reflection::description::IEventHandler>(); } }());
		(__vwsn_bind_handler_6_0 = [&](){ try{ return ::vl::__vwsn::EventAttach(::vl::__vwsn::This(__vwsn_bind_cache_5.Obj())->valueChanged, ::vl::Func<void()>(this, &__vwsnc1_BindLet_main__vl_reflection_description_IValueSubscription::__vwsn_bind_callback_6_0)); } catch(...){ return ::vl::Ptr<::vl::reflection::description::IEventHandler>(); } }());
		this->__vwsn_bind_activator_();
	}

	void __vwsnc1_BindLet_main__vl_reflection_description_IValueSubscription::__vwsn_bind_callback_1_0()
	{
		if (static_cast<bool>(__vwsn_bind_handler_2_0))
		{
			::vl::__vwsn::EventDetach(::vl::__vwsn::This(__vwsn_bind_cache_2.Obj())->valueChanged, __vwsn_bind_handler_2_0);
			(__vwsn_bind_handler_2_0 = ::vl::Ptr<::vl::reflection::description::IEventHandler>());
		}
		(__vwsn_bind_cache_2 = [&](){ try{ return ::vl::__vwsn::This(__vwsn_bind_cache_1.Obj())->Getbar(); } catch(...){ return ::vl::Ptr<::Bar>(); } }());
		(__vwsn_bind_handler_2_0 = [&](){ try{ return ::vl::__vwsn::EventAttach(::vl::__vwsn::This(__vwsn_bind_cache_2.Obj())->valueChanged, ::vl::Func<void()>(this, &__vwsnc1_BindLet_main__vl_reflection_description_IValueSubscription::__vwsn_bind_callback_2_0)); } catch(...){ return ::vl::Ptr<::vl::reflection::description::IEventHandler>(); } }());
		this->__vwsn_bind_activator_();
	}

	void __vwsnc1_BindLet_main__vl_reflection_description_IValueSubscription::__vwsn_bind_callback_2_0()
	{
		this->__vwsn_bind_activator_();
	}

	void __vwsnc1_BindLet_main__vl_reflection_description_IValueSubscription::__vwsn_bind_callback_3_0()
	{
		if (static_cast<bool>(__vwsn_bind_handler_4_0))
		{
			::vl::__vwsn::EventDetach(::vl::__vwsn::This(__vwsn_bind_cache_4.Obj())->valueChanged, __vwsn_bind_handler_4_0);
			(__vwsn_bind_handler_4_0 = ::vl::Ptr<::vl::reflection::description::IEventHandler>());
		}
		(__vwsn_bind_cache_4 = [&](){ try{ return ::vl::__vwsn::This(__vwsn_bind_cache_3.Obj())->Getbar(); } catch(...){ return ::vl::Ptr<::Bar>(); } }());
		(__vwsn_bind_handler_4_0 = [&](){ try{ return ::vl::__vwsn::EventAttach(::vl::__vwsn::This(__vwsn_bind_cache_4.Obj())->valueChanged, ::vl::Func<void()>(this, &__vwsnc1_BindLet_main__vl_reflection_description_IValueSubscription::__vwsn_bind_callback_4_0)); } catch(...){ return ::vl::Ptr<::vl::reflection::description::IEventHandler>(); } }());
		this->__vwsn_bind_activator_();
	}

	void __vwsnc1_BindLet_main__vl_reflection_description_IValueSubscription::__vwsn_bind_callback_4_0()
	{
		this->__vwsn_bind_activator_();
	}

	void __vwsnc1_BindLet_main__vl_reflection_description_IValueSubscription::__vwsn_bind_callback_5_0()
	{
		this->__vwsn_bind_activator_();
	}

	void __vwsnc1_BindLet_main__vl_reflection_description_IValueSubscription::__vwsn_bind_callback_6_0()
	{
		this->__vwsn_bind_activator_();
	}

	bool __vwsnc1_BindLet_main__vl_reflection_description_IValueSubscription::Open()
	{
		if ((! __vwsn_bind_opened_))
		{
			(__vwsn_bind_opened_ = true);
			(__vwsn_bind_cache_0 = [&](){ try{ return this->y; } catch(...){ return ::vl::Ptr<::Foo>(); } }());
			(__vwsn_bind_cache_1 = [&](){ try{ return this->z; } catch(...){ return ::vl::Ptr<::Foo>(); } }());
			(__vwsn_bind_cache_3 = [&](){ try{ return this->x; } catch(...){ return ::vl::Ptr<::Foo>(); } }());
			(__vwsn_bind_cache_2 = [&](){ try{ return ::vl::__vwsn::This(__vwsn_bind_cache_1.Obj())->Getbar(); } catch(...){ return ::vl::Ptr<::Bar>(); } }());
			(__vwsn_bind_cache_4 = [&](){ try{ return ::vl::__vwsn::This(__vwsn_bind_cache_3.Obj())->Getbar(); } catch(...){ return ::vl::Ptr<::Bar>(); } }());
			(__vwsn_bind_cache_5 = [&](){ try{ return ::vl::__vwsn::This(__vwsn_bind_cache_0.Obj())->Getbar(); } catch(...){ return ::vl::Ptr<::Bar>(); } }());
			(__vwsn_bind_handler_0_0 = [&](){ try{ return ::vl::__vwsn::EventAttach(::vl::__vwsn::This(__vwsn_bind_cache_0.Obj())->barChanged, ::vl::Func<void()>(this, &__vwsnc1_BindLet_main__vl_reflection_description_IValueSubscription::__vwsn_bind_callback_0_0)); } catch(...){ return ::vl::Ptr<::vl::reflection::description::IEventHandler>(); } }());
			(__vwsn_bind_handler_1_0 = [&](){ try{ return ::vl::__vwsn::EventAttach(::vl::__vwsn::This(__vwsn_bind_cache_1.Obj())->barChanged, ::vl::Func<void()>(this, &__vwsnc1_BindLet_main__vl_reflection_description_IValueSubscription::__vwsn_bind_callback_1_0)); } catch(...){ return ::vl::Ptr<::vl::reflection::description::IEventHandler>(); } }());
			(__vwsn_bind_handler_2_0 = [&](){ try{ return ::vl::__vwsn::EventAttach(::vl::__vwsn::This(__vwsn_bind_cache_2.Obj())->valueChanged, ::vl::Func<void()>(this, &__vwsnc1_BindLet_main__vl_reflection_description_IValueSubscription::__vwsn_bind_callback_2_0)); } catch(...){ return ::vl::Ptr<::vl::reflection::description::IEventHandler>(); } }());
			(__vwsn_bind_handler_3_0 = [&](){ try{ return ::vl::__vwsn::EventAttach(::vl::__vwsn::This(__vwsn_bind_cache_3.Obj())->barChanged, ::vl::Func<void()>(this, &__vwsnc1_BindLet_main__vl_reflection_description_IValueSubscription::__vwsn_bind_callback_3_0)); } catch(...){ return ::vl::Ptr<::vl::reflection::description::IEventHandler>(); } }());
			(__vwsn_bind_handler_4_0 = [&](){ try{ return ::vl::__vwsn::EventAttach(::vl::__vwsn::This(__vwsn_bind_cache_4.Obj())->valueChanged, ::vl::Func<void()>(this, &__vwsnc1_BindLet_main__vl_reflection_description_IValueSubscription::__vwsn_bind_callback_4_0)); } catch(...){ return ::vl::Ptr<::vl::reflection::description::IEventHandler>(); } }());
			(__vwsn_bind_handler_5_0 = [&](){ try{ return ::vl::__vwsn::EventAttach(::vl::__vwsn::This(__vwsn_bind_cache_5.Obj())->valueChanged, ::vl::Func<void()>(this, &__vwsnc1_BindLet_main__vl_reflection_description_IValueSubscription::__vwsn_bind_callback_5_0)); } catch(...){ return ::vl::Ptr<::vl::reflection::description::IEventHandler>(); } }());
			(__vwsn_bind_handler_6_0 = [&](){ try{ return ::vl::__vwsn::EventAttach(::vl::__vwsn::This(__vwsn_bind_cache_5.Obj())->valueChanged, ::vl::Func<void()>(this, &__vwsnc1_BindLet_main__vl_reflection_description_IValueSubscription::__vwsn_bind_callback_6_0)); } catch(...){ return ::vl::Ptr<::vl::reflection::description::IEventHandler>(); } }());
			return true;
		}
		return false;
	}

	bool __vwsnc1_BindLet_main__vl_reflection_description_IValueSubscription::Update()
	{
		if ((__vwsn_bind_opened_ && (! __vwsn_bind_closed_)))
		{
			this->__vwsn_bind_activator_();
			return true;
		}
		return false;
	}

	bool __vwsnc1_BindLet_main__vl_reflection_description_IValueSubscription::Close()
	{
		if ((! __vwsn_bind_closed_))
		{
			(__vwsn_bind_closed_ = true);
			if (static_cast<bool>(__vwsn_bind_handler_0_0))
			{
				::vl::__vwsn::EventDetach(::vl::__vwsn::This(__vwsn_bind_cache_0.Obj())->barChanged, __vwsn_bind_handler_0_0);
				(__vwsn_bind_handler_0_0 = ::vl::Ptr<::vl::reflection::description::IEventHandler>());
			}
			if (static_cast<bool>(__vwsn_bind_handler_1_0))
			{
				::vl::__vwsn::EventDetach(::vl::__vwsn::This(__vwsn_bind_cache_1.Obj())->barChanged, __vwsn_bind_handler_1_0);
				(__vwsn_bind_handler_1_0 = ::vl::Ptr<::vl::reflection::description::IEventHandler>());
			}
			if (static_cast<bool>(__vwsn_bind_handler_2_0))
			{
				::vl::__vwsn::EventDetach(::vl::__vwsn::This(__vwsn_bind_cache_2.Obj())->valueChanged, __vwsn_bind_handler_2_0);
				(__vwsn_bind_handler_2_0 = ::vl::Ptr<::vl::reflection::description::IEventHandler>());
			}
			if (static_cast<bool>(__vwsn_bind_handler_3_0))
			{
				::vl::__vwsn::EventDetach(::vl::__vwsn::This(__vwsn_bind_cache_3.Obj())->barChanged, __vwsn_bind_handler_3_0);
				(__vwsn_bind_handler_3_0 = ::vl::Ptr<::vl::reflection::description::IEventHandler>());
			}
			if (static_cast<bool>(__vwsn_bind_handler_4_0))
			{
				::vl::__vwsn::EventDetach(::vl::__vwsn::This(__vwsn_bind_cache_4.Obj())->valueChanged, __vwsn_bind_handler_4_0);
				(__vwsn_bind_handler_4_0 = ::vl::Ptr<::vl::reflection::description::IEventHandler>());
			}
			if (static_cast<bool>(__vwsn_bind_handler_5_0))
			{
				::vl::__vwsn::EventDetach(::vl::__vwsn::This(__vwsn_bind_cache_5.Obj())->valueChanged, __vwsn_bind_handler_5_0);
				(__vwsn_bind_handler_5_0 = ::vl::Ptr<::vl::reflection::description::IEventHandler>());
			}
			if (static_cast<bool>(__vwsn_bind_handler_6_0))
			{
				::vl::__vwsn::EventDetach(::vl::__vwsn::This(__vwsn_bind_cache_5.Obj())->valueChanged, __vwsn_bind_handler_6_0);
				(__vwsn_bind_handler_6_0 = ::vl::Ptr<::vl::reflection::description::IEventHandler>());
			}
			(__vwsn_bind_cache_0 = ::vl::Ptr<::Foo>());
			(__vwsn_bind_cache_1 = ::vl::Ptr<::Foo>());
			(__vwsn_bind_cache_2 = ::vl::Ptr<::Bar>());
			(__vwsn_bind_cache_3 = ::vl::Ptr<::Foo>());
			(__vwsn_bind_cache_4 = ::vl::Ptr<::Bar>());
			(__vwsn_bind_cache_5 = ::vl::Ptr<::Bar>());
			(__vwsn_bind_handler_0_0 = ::vl::Ptr<::vl::reflection::description::IEventHandler>());
			(__vwsn_bind_handler_1_0 = ::vl::Ptr<::vl::reflection::description::IEventHandler>());
			(__vwsn_bind_handler_2_0 = ::vl::Ptr<::vl::reflection::description::IEventHandler>());
			(__vwsn_bind_handler_3_0 = ::vl::Ptr<::vl::reflection::description::IEventHandler>());
			(__vwsn_bind_handler_4_0 = ::vl::Ptr<::vl::reflection::description::IEventHandler>());
			(__vwsn_bind_handler_5_0 = ::vl::Ptr<::vl::reflection::description::IEventHandler>());
			(__vwsn_bind_handler_6_0 = ::vl::Ptr<::vl::reflection::description::IEventHandler>());
			return true;
		}
		return false;
	}

}

/***********************************************************************
Class (::Bar)
***********************************************************************/

::vl::vint Bar::Getvalue()
{
	return this->__vwsn_prop_value;
}
void Bar::Setvalue(::vl::vint __vwsn_value_)
{
	if ((this->__vwsn_prop_value != __vwsn_value_))
	{
		(this->__vwsn_prop_value = __vwsn_value_);
		::vl::__vwsn::EventInvoke(this->valueChanged)();
	}
}

Bar::Bar()
	: __vwsn_prop_value(static_cast<::vl::vint>(0))
{
}

Bar::Bar(::vl::vint _value)
	: __vwsn_prop_value(static_cast<::vl::vint>(0))
{
	::vl::__vwsn::This(this)->Setvalue(_value);
}

/***********************************************************************
Class (::Foo)
***********************************************************************/

::vl::Ptr<::Bar> Foo::Getbar()
{
	return this->__vwsn_prop_bar;
}
void Foo::Setbar(::vl::Ptr<::Bar> __vwsn_value_)
{
	if ((this->__vwsn_prop_bar.Obj() != __vwsn_value_.Obj()))
	{
		(this->__vwsn_prop_bar = __vwsn_value_);
		::vl::__vwsn::EventInvoke(this->barChanged)();
	}
}

Foo::Foo()
	: __vwsn_prop_bar(::vl::Ptr<::Bar>(new ::Bar()))
{
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
