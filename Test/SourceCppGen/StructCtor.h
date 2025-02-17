/***********************************************************************
!!!!!! DO NOT MODIFY !!!!!!

Source: ../Resources/Codegen/StructCtor.txt

This file is generated by Workflow compiler
https://github.com/vczh-libraries
***********************************************************************/

#ifndef VCZH_WORKFLOW_COMPILER_GENERATED_STRUCTCTOR
#define VCZH_WORKFLOW_COMPILER_GENERATED_STRUCTCTOR

#include "../Source/CppTypes.h"

#if defined( _MSC_VER)
#pragma warning(push)
#pragma warning(disable:4250)
#elif defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wparentheses-equality"
#elif defined(__GNUC__)
#pragma GCC diagnostic push
#endif

namespace __vwsn_structs
{
	struct _depended_structs_B
	{
		::test::Point data;
	};
	inline bool operator== (const _depended_structs_B& a, const _depended_structs_B& b)
	{
		if (a.data != b.data) return false;
		return true;
	}
	inline bool operator!= (const _depended_structs_B& a, const _depended_structs_B& b)
	{
		if (a.data != b.data) return true;
		return false;
	}

	struct _depended_structs_A
	{
		::__vwsn_structs::_depended_structs_B data;
	};
	inline bool operator== (const _depended_structs_A& a, const _depended_structs_A& b)
	{
		if (a.data != b.data) return false;
		return true;
	}
	inline bool operator!= (const _depended_structs_A& a, const _depended_structs_A& b)
	{
		if (a.data != b.data) return true;
		return false;
	}

	struct _depended_structs_C
	{
		::__vwsn_structs::_depended_structs_A data;
	};
	inline bool operator== (const _depended_structs_C& a, const _depended_structs_C& b)
	{
		if (a.data != b.data) return false;
		return true;
	}
	inline bool operator!= (const _depended_structs_C& a, const _depended_structs_C& b)
	{
		if (a.data != b.data) return true;
		return false;
	}

	struct _depended_structs_D
	{
		::__vwsn_structs::_depended_structs_B data;
	};
	inline bool operator== (const _depended_structs_D& a, const _depended_structs_D& b)
	{
		if (a.data != b.data) return false;
		return true;
	}
	inline bool operator!= (const _depended_structs_D& a, const _depended_structs_D& b)
	{
		if (a.data != b.data) return true;
		return false;
	}

}
namespace depended_structs
{
	using A = ::__vwsn_structs::_depended_structs_A;
	using B = ::__vwsn_structs::_depended_structs_B;
	using C = ::__vwsn_structs::_depended_structs_C;
	using D = ::__vwsn_structs::_depended_structs_D;

}
/***********************************************************************
Global Variables and Functions
***********************************************************************/

namespace vl_workflow_global
{
	class StructCtor
	{
	public:

		::vl::vint Do(::test::Point p);
		::vl::WString main();

		static StructCtor& Instance();
	};
}

#if defined( _MSC_VER)
#pragma warning(pop)
#elif defined(__clang__)
#pragma clang diagnostic pop
#elif defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

#endif
