//=======================================================================================
//!	@file	:	State.h
//!	@author	:	Akiyoshi Koyama
//!	@date	:	2015/3/01
//=======================================================================================
#pragma once

namespace Chocolat
{
	namespace Generics
	{
		//=======================================================================================
		//!	@class	:	State
		//!	@brief	:	Design Pattern State 
		//!	@par	:	example
		//!	@note	:	example
		//=======================================================================================
		template<class T>
		class State
		{
		public:
			State(){};
			virtual ~State(){}

			virtual void		Initialize(T& _owner)	= 0;
			virtual void		Entry(T& _owner)		= 0;
			virtual void		Exit(T& _owner)			= 0;
			virtual void		Execute(T& _owner)		= 0;
			virtual State<T>&	Transition()			= 0;
		private:

		};
	}
}
//===============================================================
//	End of File
//===============================================================