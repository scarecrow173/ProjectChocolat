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
#define CALLOC(c, s)    _calloc_dbg(c, s, _NORMAL_BLOCK, __FILE__, __LINE__)
#define REALLOC(p, s)   _realloc_dbg(p, s, _NORMAL_BLOCK, __FILE__, __LINE__)
#define EXPAND(p, s)    _expand_dbg(p, s, _NORMAL_BLOCK, __FILE__, __LINE__)
#define FREE(p)         _free_dbg(p, _NORMAL_BLOCK)
#define MEMSIZE(p)      _msize_dbg(p, _NORMAL_BLOCK)
#else
#define NEW			new
#define MALLOC(s)	malloc(s)
#define CALLOC(c, s)    calloc(c, s)
#define REALLOC(p, s)   realloc(p, s)
#define EXPAND(p, s)    _expand(p, s)
#define FREE(p)         free(p)
#define MEMSIZE(p)      _msize(p)
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