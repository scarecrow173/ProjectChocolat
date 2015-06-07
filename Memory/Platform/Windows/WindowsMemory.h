//=======================================================================================
//!	@file	:	PlatformMemory.h
//!	@author	:	Akiyoshi Koyama
//!	@date	:	2014/12/3
//! @brief	:	Define Memory Methods By Platform
//=======================================================================================
#pragma once
#ifdef _CHOCOLAT_WINDOWS_
#include <memory>
#include "Core.h"
namespace Chocolat
{
	namespace Memory
	{
		class PlatformMemory_Windows
		{
		public:
			PlatformMemory_Windows(){};
			virtual ~PlatformMemory_Windows(){};

			static INLINE void* Memmove(void* _dst, const void* _src, Core::U32 _size)
			{
				return memmove(_dst, _src, _size);
			}

			static INLINE Core::S32 Memcmp(const void* _first, const void* _second, Core::U32 _size)
			{
				return memcmp(_first, _second, _size);
			}

			static INLINE void* Memset(void* _dst, Core::U8 _ch, Core::U32 _size)
			{
				return memset(_dst, _ch, _size);
			}

			static INLINE void* Memzero(void* _dst, Core::U32 _size)
			{
				return memset(_dst, 0,_size);
			}


			static INLINE void* Memcpy(void* _dst, const void* _src, Core::U32 _size)
			{
				return memcpy(_dst, _src, _size);
			}

			static INLINE void Memswap(void* _first, void* _second, Core::U32 _size)
			{
				if (_first == _second)
					return;
				
				void* tmp = ::malloc(_size);
				Memcpy(tmp, _first, _size);
				Memcpy(_first, _second, _size);
				Memcpy(_second, tmp, _size);
			}
		};
	}
}
#endif
//=======================================================================================
//	End of File
//=======================================================================================