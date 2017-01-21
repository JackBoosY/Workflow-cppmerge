/***********************************************************************
!!!!!! DO NOT MODIFY !!!!!!

Source: ../Resources/Codegen/CallStaticMethod.txt

This file is generated by Workflow compiler
https://github.com/vczh-libraries
***********************************************************************/

#ifndef VCZH_WORKFLOW_COMPILER_GENERATED_CALLSTATICMETHOD
#define VCZH_WORKFLOW_COMPILER_GENERATED_CALLSTATICMETHOD

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

class Calculator;

class Calculator : public ::vl::Object, public ::vl::reflection::Description<Calculator>
{
public:
	class Internal;

	class Internal : public virtual ::vl::reflection::IDescriptable, public ::vl::reflection::Description<Internal>
	{
	public:

		static ::vl::vint32_t Sum(::vl::vint32_t begin, ::vl::vint32_t end);
	};

	static ::vl::vint32_t Sum2(::vl::vint32_t begin, ::vl::vint32_t end, ::vl::vint32_t sum);
	Calculator();
};

/***********************************************************************
Global Variables and Functions
***********************************************************************/

namespace vl_workflow_global
{
	class CallStaticMethod
	{
	public:

		::vl::WString main();

		static CallStaticMethod& Instance();
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
			DECL_TYPE_INFO(::Calculator)
			DECL_TYPE_INFO(::Calculator::Internal)

			BEGIN_INTERFACE_PROXY_NOPARENT_SHAREDPTR(::Calculator::Internal)
			END_INTERFACE_PROXY(::Calculator::Internal)
#endif

			extern bool LoadCallStaticMethodTypes();
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
