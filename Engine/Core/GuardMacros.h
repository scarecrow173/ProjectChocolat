//=======================================================================================
//!	@file	:	Type.h
//!	@author	:	Akiyoshi Koyama
//!	@date	:	2014/12/3
//! @brief	:	Define Guard Macros
//=======================================================================================
#pragma once
namespace Chocolat
{
namespace Core
{
#if defined(_DEBUG) || defined(DEBUG)
#define INLINE
#else
#define INLINE inline
#endif
}
}

//===============================================================
//	End of File
//===============================================================