//=======================================================================================
//!	@file	:	BitmapRenderer.h
//!	@author	:	Akiyoshi Koyama
//!	@date	:	2015/05/06
//=======================================================================================
#pragma once

class wxBitmap;
class wxMemoryDC;
class wxFrame;
#ifdef _CHOCOLAT_WINDOWS_
#pragma comment(lib, "OpenGL32.lib")
#include "GL/glew.h"
#endif
//=======================================================================================
//!	@class	:	BitmapRenderer
//!	@brief	:	BitmapRenderer
//!	@par	:	リアルタイムにBitmapを描画
//!	@note	:	テキトー
//=======================================================================================
class BitmapRenderer
{
public:
	BitmapRenderer(unsigned int width = 256, unsigned int height = 256);
	virtual ~BitmapRenderer();
	
	void Draw();
	void SetPixelData(unsigned char* pixelData);

	GLuint m_RenderTarget;
	unsigned int m_Width;
	unsigned int m_Height;
	unsigned char* m_PixelData;
	
	
};

//===============================================================
//	End of File
//===============================================================