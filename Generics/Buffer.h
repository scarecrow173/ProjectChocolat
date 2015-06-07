//=======================================================================================
//!	@file	:	Buffer.h
//!	@author	:	Akiyoshi Koyama
//!	@date	:	2015/05/01
//=======================================================================================
#pragma once

#include "Core.h"
#include "Memory.h"
namespace Chocolat
{
namespace Generics
{
//=======================================================================================
//!	@class	:	Buffer
//!	@brief	:	Buffer
//!	@par	:	
//!	@note	:	
//=======================================================================================
class Buffer
{
public:
	/**
	* デフォルトコンストラクタ
	* 空バッファ作成
	*/
	Buffer()
		: m_Data(NULL)
		, m_Size(0)
	{}

	/** 
	* コンストラクタ
	* サイズ分メモリを新たに確保
	*/
	Buffer(Core::U32 _size)
		: m_Data(NULL)
		, m_Size(_size)
	{
		if (m_Size)
		{
			m_Data = Memory::Malloc(m_Size);
			Memory::MemZero(m_Data);
		}
	}

	/**
	* コンストラクタ
	* メモリを確保し、データコピー
	*/
	Buffer(const void* _data, Core::U32 _size)
		: m_Data(NULL)
		, m_Size(_size)
	{
		if (m_Size)
			m_Data = Memory::Malloc(m_Size);
		if (m_Data)
			Memory::Memcpy(m_Data, _data, m_Size);
		
	}

	/**
	* 確保していたメモリを解放
	*/
	virtual ~Buffer()
	{
		if (m_Data)
			Memory::Free(m_Data);
	}

private:

	/** データ */
	void* m_Data;

	/** データサイズ */
	Core::U32 m_Size;
};


}
}
//===============================================================
//	End of File
//===============================================================