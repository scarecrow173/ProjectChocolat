//=======================================================================================
//!	@file	:	ImageWriter.h
//!	@author	:	Akiyoshi Koyama
//!	@date	:	2014/3/8
//! @brief	:	sample classes
//=======================================================================================
#pragma once
//=======================================================================================
//!	@class	:	ImageWriter
//!	@brief	:	Image Writer
//!	@par	:	sample acclication
//!	@note	:	temporary
//=======================================================================================
class ImageWriter
{
public:
	ImageWriter();
	virtual ~ImageWriter();

	bool Write(const char* filePath, unsigned int width, unsigned int height, unsigned char* data);
};
//===============================================================
//	End of File
//===============================================================