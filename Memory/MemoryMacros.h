//=======================================================================================
//!	@file	:	MemoryMacros.h
//!	@author	:	Akiyoshi Koyama
//!	@date	:	2014/12/3
//! @brief	:	Define Memory Macro
//=======================================================================================
#pragma once
#include <new>
namespace Chocolat
{
namespace Memory
{
#if defined(_DEBUG) || defined(DEBUG)
#define NEW			new (_NORMAL_BLOCK, __FILE__, __LINE__)
#define MALLOC(s)	_malloc_dbg(s, _NORMAL_BLOCK, __FILE__, __LINE__)

#else
#define NEW			new
#define MALLOC(s)	malloc(s)

#endif

#ifndef SAFE_DELETE
#define SAFE_DELETE(p)       { if (p) { delete (p);     (p)=NULL; } }
#endif    
#ifndef SAFE_DELETE_ARRAY
#define SAFE_DELETE_ARRAY(p) { if (p) { delete[] (p);   (p)=NULL; } }
#endif

}
}

//===============================================================
//	End of File
//===============================================================