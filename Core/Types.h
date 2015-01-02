//=======================================================================================
//!	@file	:	Type.h
//!	@author	:	è¨éR âlå\
//!	@date	:	2014/12/3
//! @brief	:	äÓñ{å^ÇÃíËã`
//=======================================================================================
#ifndef __CHOCOLAT_CORE_TYPES__
#define __CHOCOLAT_CORE_TYPES__
namespace Chocolat
{
namespace Core
{
	///< 8Bit Signed Char
	typedef signed char				S8;
	///< 16Bit Signed Short 
	typedef signed short			S16;
	///< 32Bit Signed Int
	typedef signed int				S32;
	///< 64Bit Signed LongLong
	typedef signed long long		S64;
	///< 8Bit Unsigned Char
	typedef unsigned char			U8;
	///< 16Bit Unsigned Short
	typedef unsigned short			U16;
	///< 32Bit Unsigned Int
	typedef unsigned int			U32;
	///< 64Bit Unsigned LongLong
	typedef unsigned long long		U64;
	///< 32Bit Float
	typedef float					F32;
	///< 64Bit Float
	typedef double					F64;
	///< 8Bit Byte
	typedef U8						Byte;

	///< "Null" type used by templates
	struct							EmptyType {};
	///< Const Char Ptr
	typedef const char*				StringTableEntry;
}
}
#endif
//===============================================================
//	End of File
//===============================================================