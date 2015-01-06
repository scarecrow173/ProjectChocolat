//=======================================================================================
//!	@file	:	TypeConstants.h
//!	@author	:	小山 瑛圭
//!	@date	:	2014/12/3
//! @brief	:	基本形汎用定数の定義
//=======================================================================================
#ifndef __CHOCOLAT_CORE_TYPE_CONSTANTS__
#define __CHOCOLAT_CORE_TYPE_CONSTANTS__
#include "Types.h"
namespace Chocolat
{
namespace Core
{ 
#define __EQUAL_CONST_F F32(0.000001)									///< Constant float epsilon used for F32 comparisons
	static const F32 F32_ONE	= F32(1.0);								///< Constant float 1.0
	static const F32 F32_HALF	= F32(0.5);								///< Constant float 0.5
	static const F32 F32_ZERO	= F32(0.0);								///< Constant float 0.0
	static const F32 F32_PI		= F32(3.14159265358979323846);			///< Constant float PI
	static const F32 F32_2PI	= F32(2.0 * 3.14159265358979323846);	///< Constant float 2*PI

	static const S8  S8_MIN		= S8(-128);                             ///< Constant Min Limit S8
	static const S8  S8_MAX		= S8(127);                              ///< Constant Max Limit S8

	static const U8  U8_MIN		= U8(0);								///< Constant Min Limit U8
	static const U8  U8_MAX		= U8(255);                              ///< Constant Max Limit U8

	static const S16 S16_MIN	= S16(-32768);                          ///< Constant Min Limit S16
	static const S16 S16_MAX	= S16(32767);                           ///< Constant Max Limit S16

	static const U16 U16_MIN	= U16(0);								///< Constant Min Limit U16
	static const U16 U16_MAX	= U16(65535);                           ///< Constant Max Limit U16

	static const S32 S32_MIN	= S32(-2147483647 - 1);                 ///< Constant Min Limit S32
	static const S32 S32_MAX	= S32(2147483647);                      ///< Constant Max Limit S32

	static const U32 U32_MIN	= U32(0x00000000);						///< Constant Min Limit U32
	static const U32 U32_MAX	= U32(0xffffffff);                      ///< Constant Max Limit U32

	static const F32 F32_MIN	= F32(1.175494351e-38F);                ///< Constant Min Limit F32
	static const F32 F32_MAX	= F32(3.402823466e+38F);                ///< Constant Max Limit F32

	static const S64 S64_MIN	= S64(-9223372036854775808);			///< Constant Min Limit S64
	static const S64 S64_MAX	= S64(9223372036854775807);				///< Constant Max Limit S64

	static const U64 U64_MIN	= U64(0);								///< Constant Min Limit U64
	static const U64 U64_MAX	= U64(18446744073709551615);			///< Constant Max Limit U64
	
	static const F64 F64_MIN	= F64(2.2250738585072014e-308);			///< Constant Min Limit F64
	static const F64 F64_MAX	= F64(1.7976931348623158e+308);			///< Constant Max Limit F64
}
}
#endif
//===============================================================
//	End of File
//===============================================================