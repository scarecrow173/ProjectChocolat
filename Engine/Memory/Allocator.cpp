//=======================================================================================
//!	@file	:	Allocator.cpp
//!	@author	:	Akiyoshi Koyama
//!	@date	:	2015/10/18
//! @brief	:	Define Memory Allocator
//=======================================================================================

#include "Memory.h"
#include "Allocator.h"
#include "MemoryMethods.h"
namespace Chocolat
{
namespace Memory
{

Core::U32 Allocator::InvalidSignature = 0xDEADC0DE;
Allocator::MemoryMap Allocator::MemoryMapInfo[Allocator::MemoryCategory::Category_NUM];

Memory::MallocFuncType Allocator::MallocFunction = nullptr;
Memory::FreeFuncType   Allocator::FreeFunction = nullptr;

bool Allocator::InitializeAllocator(MallocFuncType MallocFunc, FreeFuncType FreeFunc)
{
	Allocator::MallocFunction = MallocFunc;
	Allocator::FreeFunction = FreeFunc;

	Memset(Allocator::MemoryMapInfo, 0, sizeof(Allocator::MemoryMap) * Allocator::MemoryCategory::Category_NUM);
	return Allocator::MallocFunction && Allocator::FreeFunction;
}

void* Allocator::Malloc(size_t Size, MemoryCategory Category)
{
	const size_t AllocateSize = Size + sizeof(Allocator::MemoryHeader);
	Allocator::MemoryHeader* AllocedMemory = (Allocator::MemoryHeader*)MallocFunction(AllocateSize);
	
	AllocedMemory->Signature = Allocator::InvalidSignature;
	AllocedMemory->AllocatedSize = AllocateSize;
	AllocedMemory->Next = Allocator::CurrentHeader;
	AllocedMemory->Preview = nullptr;
	AllocedMemory->Category = Category;

	if (Allocator::CurrentHeader)
		Allocator::CurrentHeader->Preview = AllocedMemory;
	Allocator::CurrentHeader = AllocedMemory;


	UpdateAllocadedCountFromAlloc(Category, AllocateSize);
	
	return (void*)(AllocedMemory + 1);
}

void* Allocator::Realloc(void* Ptr, size_t Size, MemoryCategory Category)
{
	void* NewAllocedMemory = Allocator::Malloc(Size, Category);
	
	const size_t OldSize = (((MemoryHeader*)Ptr) - 1)->AllocatedSize - sizeof(MemoryHeader);
	const size_t AlocateSize = Size < OldSize ? Size : OldSize;
	
	Memcpy(NewAllocedMemory, Ptr, AlocateSize);
	Allocator::Free(Ptr);
	
	return NewAllocedMemory;
}

void  Allocator::Free(void* Address)
{
	MemoryHeader* Header = ((MemoryHeader*)Address) - 1;
	
	if (!Header->Preview)
		Allocator::CurrentHeader = Header->Next;
	else
		Header->Preview->Next = Header->Next;

	if (!Header->Next)
		Header->Next->Preview = Header->Preview;

	Allocator::UpdateAllocadedCountFromFree(Header->Category, Header->AllocatedSize);

	Allocator::FreeFunction(Header);
	
}

Core::U32 Allocator::UpdateAllocadedCountFromAlloc(MemoryCategory Category, size_t Size)
{
	
	Allocator::MemoryMapInfo[Category].TotalAllocatedSize += Size;
	Allocator::MemoryMapInfo[Category].PeakAllocatedSize = MemoryMapInfo[Category].TotalAllocatedSize > MemoryMapInfo[Category].PeakAllocatedSize ? MemoryMapInfo[Category].TotalAllocatedSize : MemoryMapInfo[Category].PeakAllocatedSize;
	return ++Allocator::MemoryMapInfo[Category].AllocatedCount;
}

Core::U32 Allocator::UpdateAllocadedCountFromFree(MemoryCategory Category, size_t Size)
{
	Allocator::MemoryMapInfo[Category].TotalAllocatedSize -= Size;
	return --Allocator::MemoryMapInfo[Category].AllocatedCount;
}

Core::U32 Allocator::GetMemoryBookmark(MemoryCategory Category)
{
	return Allocator::MemoryMapInfo[Category].AllocatedCount;
}

}
}

//===============================================================
//	End of File
//===============================================================