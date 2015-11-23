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
#  define CHOCOLAT_INLINE 
#  define CHOCOLAT_FORCE_INLINE     CHOCOLAT_INLINE
#else
#  if defined(__cplusplus)
#    define CHOCOLAT_INLINE            inline
#  elif defined(_MSC_VER)
#    define CHOCOLAT_INLINE            __inline
#    define CHOCOLAT_FORCE_INLINE     __forceinline
#  elif defined(__GNUC__)
#    define CHOCOLAT_INLINE            __inline__
#    define CHOCOLAT_FORCE_INLINE     __attribute__((always_inline)) CHOCOLAT_INLINE
#  else
#    define CHOCOLAT_INLINE            inline
#    define CHOCOLAT_FORCE_INLINE     CHOCOLAT_INLINE
#  endif
#endif

#if defined(_CHOCOLAT_WINDOWS_)// DLL export and import definitions
#  define CHOCOLAT_DLLEXPORT __declspec(dllexport)
#  define CHOCOLAT_DLLIMPORT __declspec(dllimport)
#else
#  define CHOCOLAT_DLLEXPORT 
#  define CHOCOLAT_DLLIMPORT 
#endif


}
}

//===============================================================
//	End of File
//===============================================================