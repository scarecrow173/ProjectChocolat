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
	* �f�t�H���g�R���X�g���N�^
	* ��o�b�t�@�쐬
	*/
	Buffer()
		: m_Data(NULL)
		, m_Size(0)
	{}

	/** 
	* �R���X�g���N�^
	* �T�C�Y����������V���Ɋm��
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
	* �R���X�g���N�^
	* ���������m�ۂ��A�f�[�^�R�s�[
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
	* �m�ۂ��Ă��������������
	*/
	virtual ~Buffer()
	{
		if (m_Data)
			Memory::Free(m_Data);
	}

private:

	/** �f�[�^ */
	void* m_Data;

	/** �f�[�^�T�C�Y */
	Core::U32 m_Size;
};


}
}
//===============================================================
//	End of File
//===============================================================