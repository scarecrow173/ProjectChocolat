//=======================================================================================
//!	@file	:	Singleton.h
//!	@author	:	Akiyoshi Koyama
//!	@date	:	2015/3/01
//=======================================================================================
#pragma once
#include "NonCopytable.h"

namespace Chocolat
{
	namespace Generics
	{
		//=======================================================================================
		//!	@class	:	Singleton
		//!	@brief	:	Singleton Base
		//!	@par	:	example
		//!	@note	:	example
		//=======================================================================================
		template<class T>
		class Singleton : private NonCopytable<Singleton<T>>
		{
		public:
			static void		Destory();
			static T*		GetInstance();
		private:
			Singleton(){};
			virtual ~Singleton(){};
			
			static T* m_instance;
		};
		//=======================================================================================
		//		Constants Definitions
		//=======================================================================================
		template <class T>
		T* Singleton<T>::m_instance = NULL;
		//=======================================================================================
		//		inline method
		//=======================================================================================
		//-------------------------------------------------------------
		//!	@brief		: Getter
		//-------------------------------------------------------------
		template <class T>
		INLINE T* Singleton<T>::GetInstance()
		{
			if (!m_instance)
				m_instance = new T();
			return m_instance;
		}
		//-------------------------------------------------------------
		//!	@brief		: Destory
		//-------------------------------------------------------------
		template <class T>
		INLINE void Singleton<T>::Destory()
		{
			SAFE_DELETE(m_instance);
		}
	}
}
//===============================================================
//	End of File
//===============================================================