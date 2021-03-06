//=======================================================================================
//!	@file	:	PlatformMemory.h
//!	@author	:	Akiyoshi Koyama
//!	@date	:	2014/12/3
//! @brief	:	Define Memory Methods By Platform
//=======================================================================================
#pragma once

#if defined(_CHOCOLAT_WINDOWS_)
#include "Platform/Windows/WindowsMemory.h"
#elif defined(_CHOCOLAT_OSX_)

#else

#endif

namespace Chocolat
{
namespace Memory
{

#if defined(_CHOCOLAT_WINDOWS_)
typedef PlatformMemory_Windows PlatformMemory;
#elif defined(_CHOCOLAT_OSX_)

#else

#endif

}
}


//=======================================================================================
//	End of File
//=======================================================================================