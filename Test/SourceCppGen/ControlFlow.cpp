/***********************************************************************
!!!!!! DO NOT MODIFY !!!!!!

Source: ../Resources/Codegen/ControlFlow.txt

This file is generated by Workflow compiler
https://github.com/vczh-libraries
***********************************************************************/

#include "ControlFlow.h"

#if defined( _MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#elif defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wparentheses-equality"
#elif defined(__GNUC__)
#pragma GCC diagnostic push
#endif

#define GLOBAL_SYMBOL ::vl_workflow_global::ControlFlow::
#define GLOBAL_NAME ::vl_workflow_global::ControlFlow::Instance().
#define GLOBAL_OBJ &::vl_workflow_global::ControlFlow::Instance()

/***********************************************************************
Global Variables
***********************************************************************/

BEGIN_GLOBAL_STORAGE_CLASS(vl_workflow_global_ControlFlow)
	vl_workflow_global::ControlFlow instance;
	INITIALIZE_GLOBAL_STORAGE_CLASS
	FINALIZE_GLOBAL_STORAGE_CLASS
END_GLOBAL_STORAGE_CLASS(vl_workflow_global_ControlFlow)

namespace vl_workflow_global
{
/***********************************************************************
Global Functions
***********************************************************************/

	::vl::vint ControlFlow::Sum1(::vl::vint start, ::vl::vint end)
	{
		auto result = static_cast<::vl::vint>(0);
		{
			auto __vwsn_for_begin_x = start;
			auto __vwsn_for_end_x = end;
			auto x = __vwsn_for_begin_x;
			while ((x <= __vwsn_for_end_x))
			{
				{
					(result = (result + x));
				}
				(x = (x + static_cast<::vl::vint>(1)));
			}
		}
		return result;
	}

	::vl::vint ControlFlow::Sum2(::vl::vint start, ::vl::vint end)
	{
		auto result = static_cast<::vl::vint>(0);
		{
			auto __vwsn_for_begin_x = start;
			auto __vwsn_for_end_x = end;
			auto x = __vwsn_for_end_x;
			while ((x >= __vwsn_for_begin_x))
			{
				{
					(result = (result + x));
				}
				(x = (x - static_cast<::vl::vint>(1)));
			}
		}
		return result;
	}

	::vl::vint ControlFlow::Sum3(::vl::vint start, ::vl::vint end)
	{
		auto result = static_cast<::vl::vint>(0);
		auto current = start;
		while ((current <= end))
		{
			(result = (result + current));
			(current = (current + static_cast<::vl::vint>(1)));
		}
		return result;
	}

	::vl::vint ControlFlow::Sum4(::vl::vint start, ::vl::vint end)
	{
		auto result = static_cast<::vl::vint>(0);
		auto current = start;
		while (true)
		{
			if ((current > end))
			{
				break;
			}
			(result = (result + current));
			(current = (current + static_cast<::vl::vint>(1)));
		}
		return result;
	}

	::vl::vint ControlFlow::Sum5(::vl::vint start, ::vl::vint end)
	{
		auto result = static_cast<::vl::vint>(0);
		auto current = start;
		auto needToExit = false;
		while ((! needToExit))
		{
			{
				auto __vwsn_switch_0 = current;
				if ((__vwsn_switch_0 == (end + static_cast<::vl::vint>(1))))
				{
					(needToExit = true);
				}
				else
				{
					(result = (result + current));
				}
			}
			(current = (current + static_cast<::vl::vint>(1)));
		}
		return result;
	}

	::vl::WString ControlFlow::main()
	{
		return ((((((((::vl::__vwsn::ToString(GLOBAL_NAME Sum1(static_cast<::vl::vint>(1), static_cast<::vl::vint>(10))) + ::vl::WString::Unmanaged(L", ")) + ::vl::__vwsn::ToString(GLOBAL_NAME Sum2(static_cast<::vl::vint>(1), static_cast<::vl::vint>(10)))) + ::vl::WString::Unmanaged(L", ")) + ::vl::__vwsn::ToString(GLOBAL_NAME Sum3(static_cast<::vl::vint>(1), static_cast<::vl::vint>(10)))) + ::vl::WString::Unmanaged(L", ")) + ::vl::__vwsn::ToString(GLOBAL_NAME Sum4(static_cast<::vl::vint>(1), static_cast<::vl::vint>(10)))) + ::vl::WString::Unmanaged(L", ")) + ::vl::__vwsn::ToString(GLOBAL_NAME Sum5(static_cast<::vl::vint>(1), static_cast<::vl::vint>(10))));
	}

	ControlFlow& ControlFlow::Instance()
	{
		return Getvl_workflow_global_ControlFlow().instance;
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
