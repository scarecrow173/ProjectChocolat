//=======================================================================================
//!	@file	:	MemoryMethods.h
//!	@author	:	Akiyoshi Koyama
//!	@date	:	2014/12/3
//! @brief	:	Define Memory Methods
//=======================================================================================
#pragma once
#include "Core.h"
#include "MemoryMacros.h"
#include "Platform/PlatformMemory.h"
namespace Chocolat
{
	namespace Memory
	{
		/** */
		static INLINE void* Memmove(void* _dst, const void* _src, Core::U32 _size)
		{
			return PlatformMemory::Memmove(_dst, _src, _size);
		}
		
		/** */
		static INLINE Core::S32 Memcmp(const void* _first, const void* _second, Core::U32 _size)
		{
			return PlatformMemory::Memcmp(_first, _second, _size);
		}
		
		/** */
		static INLINE void* Memset(void* _dst, Core::U8 _ch, Core::U32 _size)
		{
			return PlatformMemory::Memset(_dst, _ch, _size);
		}
		
		/** */
		static INLINE void* Memzero(void* _dst, Core::U32 _size)
		{
			return PlatformMemory::Memzero(_dst, _size);
		}

		/** */
		static INLINE void* Memcpy(void* _dst, const void* _src, Core::U32 _size)
		{
			return PlatformMemory::Memcpy(_dst, _src, _size);
		}

		/** */
		static INLINE void Memswap(void* _first, void* _second, Core::U32 _size)
		{
			PlatformMemory::Memswap(_first, _second, _size);
		}

		/** */
		template< class T >
		static INLINE void MemSet(T& _src, Core::U8 _valueToSet)
		{
			FMemory::Memset(&_src, _valueToSet, sizeof(T));
		}

		/** */
		template< class T >
		static INLINE void MemZero(T& _src)
		{
			FMemory::Memset(&_src, 0, sizeof(T));
		}

		/** */
		template< class T >
		static INLINE void MemCopy(T& _dst, const T& _src)
		{
			FMemory::Memcpy(&_dst, &_src, sizeof(T));
		}

		static INLINE void* Malloc(Core::U32 _size)
		{
			MALLOC(_size);
		}
		static INLINE void* Realloc(void* _original, Core::U32 _size)
		{
			REALLOC(_original, _size);
		}
		static INLINE void Free(void* _mem)
		{
			FREE(_mem);
		}

	}
}

//===============================================================
//	End of File
//===============================================================