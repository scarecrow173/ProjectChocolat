#include "wxWidgetsSample.h"
#include "ImageWriter.h"
#include "wx/wx.h"
#include "wx/rawbmp.h"
ImageWriter::ImageWriter()
{}
ImageWriter::~ImageWriter()
{}
bool ImageWriter::Write(const char* filePath, unsigned int width, unsigned int height, unsigned char* data)
{
	
	wxBitmap bitmap(width, height,24);
	//bool bTmp = bitmap.Create(width, height);
	wxNativePixelData pixel(bitmap);
	wxNativePixelData::Iterator it(pixel);
	for (size_t i = 0; i < height; i++)
	{
		wxNativePixelData::Iterator rowStart = it;
		for (size_t j = 0; j < width; j++)
		{
			it.Red() = data[j+(width*i*3+0)];
			it.Green() = data[j+(width*i*3+1)];
			it.Blue() = data[j+(width*i*3+2)];
			++it;
		}
		it = rowStart;
		it.OffsetY(pixel, 1);
	}
	wxImage image = bitmap.ConvertToImage();
	return image.SaveFile(filePath);
}