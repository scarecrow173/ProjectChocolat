//=======================================================================================
//!	@file	:	Allocator.h
//!	@author	:	Akiyoshi Koyama
//!	@date	:	2015/10/18
//! @brief	:	Define Memory Allocator
//=======================================================================================
#pragma once
#include "Core.h"
namespace Chocolat
{
namespace Memory
{

typedef void* (*MallocFuncType)(size_t Size);		//!< mallocŒ^
typedef void(*FreeFuncType)(void* Ptr);				//!< freeŒ^

class Allocator
{
public:
	enum MemoryCategory
	{
		Category_Core,
		Category_Framework,
		Category_File,
		Category_Audio,
		Category_Graphics,
		Category_Game,
		Category_Tools,
		Category_NUM
	};

	struct MemoryHeader
	{
		Core::U32 Signature;
		size_t AllocatedSize;
		MemoryCategory Category;

		MemoryHeader *Next;
		MemoryHeader *Preview;
	};


public:
	static bool  InitializeAllocator(Chocolat::Memory::MallocFuncType MallocFunc, Chocolat::Memory::FreeFuncType FreeFunc);
	static void* Malloc(size_t Size, MemoryCategory Category);
	static void* Realloc(void* Ptr, size_t Size, MemoryCategory Category);
	static void  Free(void* Address);

private:
	struct MemoryMap
	{
		Core::U32 AllocatedCount;
		size_t TotalAllocatedSize;
		size_t PeakAllocatedSize;
	};

private:
	static Core::U32 UpdateAllocadedCountFromAlloc(MemoryCategory Category, size_t Size);
	static Core::U32 UpdateAllocadedCountFromFree(MemoryCategory Category, size_t Size);
	static Core::U32 GetMemoryBookmark(MemoryCategory Category);

private:
	
	static Core::U32 InvalidSignature;
	static MemoryMap MemoryMapInfo[MemoryCategory::Category_NUM];
	static MemoryHeader* CurrentHeader;

	static Chocolat::Memory::MallocFuncType MallocFunction;
	static Chocolat::Memory::FreeFuncType   FreeFunction;
};

}
}

//===============================================================
//	End of File
//===============================================================