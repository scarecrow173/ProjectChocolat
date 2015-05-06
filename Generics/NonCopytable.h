//=======================================================================================
//!	@file	:	NonCopytable.h
//!	@author	:	Akiyoshi Koyama
//!	@date	:	2015/3/01
//=======================================================================================
#pragma once

namespace Chocolat
{
	namespace Generics
	{
		//=======================================================================================
		//!	@class	:	NonCopytable
		//!	@brief	:	Non Copytable Object Base
		//!	@par	:	example
		//!	@note	:	example
		//=======================================================================================
		template<class T>
		class NonCopytable
		{
		protected:
			NonCopytable(){};
			~NonCopytable(){}
		private:
			/// Not implemented Copy Constracut.
			NonCopytable(const NonCopytable&);
			/// Not implemented Copy Operator.
			T& operator = (const T&);

		};
	}
}
//===============================================================
//	End of File
//===============================================================