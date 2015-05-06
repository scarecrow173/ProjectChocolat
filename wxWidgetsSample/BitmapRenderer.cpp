#include "wxWidgetsSample.h"
#include "BitmapRenderer.h"
#include "wx/wx.h"
#include "wx/rawbmp.h"
#include "wx/graphics.h"
#include "wx/dcbuffer.h"
#include "wx/dcgraph.h"
#ifdef _CHOCOLAT_WINDOWS_
#pragma comment(lib, "OpenGL32.lib")
#include "GL/glew.h"
#endif
BitmapRenderer::BitmapRenderer(unsigned int width, unsigned int height)
	: m_RenderTarget(0)
	, m_Width	(width)
	, m_Height	(height)
	, m_PixelData(nullptr)
{
	m_PixelData = new unsigned char[m_Height * m_Width * 3];
	glGenTextures(0, &m_RenderTarget);
	glBindTexture(GL_TEXTURE_2D, m_RenderTarget);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
}
BitmapRenderer::~BitmapRenderer()
{

}

void BitmapRenderer::Draw()
{
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_QUADS);

	glTexCoord2d(0.0, 1.0);   glVertex2d(-1, 1);
	glTexCoord2d(0.0, 0.0);   glVertex2d(-1, -1);
	glTexCoord2d(1.0, 0.0);   glVertex2d(1, -1);
	glTexCoord2d(1.0, 1.0);   glVertex2d(1, 1);

	glEnd();

	glDisable(GL_TEXTURE_2D);

}

void BitmapRenderer::SetPixelData(unsigned char* pixelData)
{
	static unsigned int LoopColor = 0;
	unsigned int GColor = abs(sin(LoopColor)) * 255;
	++LoopColor;

	for (size_t iPixel = 0; iPixel < (m_Width * m_Height * 3); iPixel++)
	{
		unsigned char color = 0;
		switch (iPixel % 3)
		{
		case 0: // R
			color = 255;
			break;
		case 1: // G
			color = GColor;
			break;
		case 2: // B
			color = 0;
			break;
		default:
			break;
		}
		m_PixelData[iPixel] = color;
	}
	glGenTextures(0, &m_RenderTarget);
	glBindTexture(GL_TEXTURE_2D, m_RenderTarget);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, m_Width, m_Height,
		0, GL_RGB, GL_UNSIGNED_BYTE, m_PixelData);
}