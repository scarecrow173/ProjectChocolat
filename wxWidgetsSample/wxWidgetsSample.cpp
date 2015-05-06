#include "wxWidgetsSample.h"
#include "wx/graphics.h"
#include <stdio.h>
#include "ImageWriter.h"
#include "AudioLoader.h"
#include "BitmapRenderer.h"
#ifdef _CHOCOLAT_WINDOWS_
#pragma comment(lib, "OpenGL32.lib")
#include "GL/glew.h"
#endif
BitmapRenderer* g_Renderer = nullptr;
void ConvertPCMToImageData(unsigned char* rawPCM, unsigned char* rawImage);
//int main()
//{
//    printf("wxWidgetsSample!!\n");
//
//    getchar();
//
//    return 0;
//}
wxBEGIN_EVENT_TABLE(wxWidgetsSampleFrame, wxFrame)
	EVT_MENU(SelectFile, wxWidgetsSampleFrame::OnSelectFile)
	EVT_MENU(SaveFile, wxWidgetsSampleFrame::OnSave)
	EVT_MENU(Quit, wxWidgetsSampleFrame::OnQuit)
	EVT_MENU(About, wxWidgetsSampleFrame::OnAbout)
	EVT_IDLE(wxWidgetsSampleFrame::OnIdle)
wxEND_EVENT_TABLE()

wxWidgetsSampleFrame::wxWidgetsSampleFrame(const wxString& title)
	:	wxFrame	(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(256,256))
{
	InitGL();
	wxMenu* menuFile = new wxMenu();
	menuFile->Append(SelectFile, wxT("Select WAV &file...\tCtrl-O"), wxT("Select a new wav file to play"));
	menuFile->Append(SaveFile, wxT("Save Image &file...\tCtrl-S"), wxT("Save to Image File"));
	menuFile->Append(Quit, wxT("E&xit\tAlt-X"), wxT("Quit this program"));

	wxMenu *helpMenu = new wxMenu();
	helpMenu->Append(About, wxT("&About\tF1"), wxT("Show about dialog"));

	// now append the freshly created menu to the menu bar...
	wxMenuBar *menuBar = new wxMenuBar();
	menuBar->Append(menuFile, wxT("&File"));
	//menuBar->Append(playMenu, wxT("&Play"));
	menuBar->Append(helpMenu, wxT("&Help"));

	// ... and attach this menu bar to the frame
	SetMenuBar(menuBar);
}

void wxWidgetsSampleFrame::OnSelectFile(wxCommandEvent& WXUNUSED(event))
{
	wxFileDialog dlg(this, wxT("Choose a sound file"),
		wxEmptyString, wxEmptyString,
		wxString::Format
		(
		"WAV files (*.wav)|*.wav|All files (%s)|%s",
		wxFileSelectorDefaultWildcardStr,
		wxFileSelectorDefaultWildcardStr
		),
		wxFD_OPEN | wxFD_CHANGE_DIR);
	if (dlg.ShowModal() == wxID_OK)
	{
        
		AudioLoader audioLoad = AudioLoader(dlg.GetPath());
		
		const int widht = 256;
		const int height = 256;
		const int colorNum = 3; // RGB
		unsigned char* rawData = new unsigned char[(widht * height) * colorNum];

		const unsigned int PCMSize = audioLoad.wav->size()/2;
		unsigned char* rawPCM = new unsigned char[PCMSize];
#ifdef _CHOCOLAT_WINDOWS_
		memcpy_s(rawPCM, PCMSize, audioLoad.wav->rawRData(), PCMSize);
#elif _CHOCOLAT_OSX_
		memcpy(rawPCM, audioLoad.wav->rawRData(), PCMSize);
#endif
		ConvertPCMToImageData(rawPCM, rawData);

		wxString path = dlg.GetPath().append(".bmp");
		ImageWriter writer;
		writer.Write(path, widht, height, rawData);
	}
}
void wxWidgetsSampleFrame::OnQuit(wxCommandEvent& event)
{
	// true is to force the frame to close
	Close(true);
}
void wxWidgetsSampleFrame::OnAbout(wxCommandEvent& event)
{}

void wxWidgetsSampleFrame::OnSave(wxCommandEvent& event)
{
	wxFileDialog dlg(this, wxT("Choose a sound file"),
		wxEmptyString, wxEmptyString,
		wxString::Format
		(
		"WAV files (*.bmp)|*.bmp|All files (%s)|%s",
		wxFileSelectorDefaultWildcardStr,
		wxFileSelectorDefaultWildcardStr
		),
		wxFD_SAVE | wxFD_CHANGE_DIR);
	if (dlg.ShowModal() == wxID_OK)
	{
		dlg.GetPath();
		ImageWriter writer;
		unsigned char data[] =
		{
			0x52, 0x49, 0x46, 0x46, 0x00, 0x1f, 0x00, 0x00, 0x57, 0x41, 0x56, 0x52, 0x49, 0x46, 0x46, 0x00, 0x1f, 0x00, 0x00, 0x57, 0x41, 0x56,
		};
		writer.Write(dlg.GetPath(), 256, 256, data);
	}
}
void wxWidgetsSampleFrame::NotifyUsingFile(const wxString& name)
{
}
void wxWidgetsSampleFrame::OnIdle(wxIdleEvent& event)
{
	event.RequestMore(true);
	OnDraw();
	
}

void wxWidgetsSampleFrame::OnDraw()
{
	glClearColor(0.0f, 0.5f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	if (g_Renderer)
	{
		g_Renderer->SetPixelData(nullptr);
		g_Renderer->Draw();
	}
	else
	{
		g_Renderer = new BitmapRenderer();
	}
	glFlush();
	SwapBuffers(m_DC);
	
}
void wxWidgetsSampleFrame::InitGL()
{
	// OpenGL初期化
	// ピクセルフォーマット初期化
	PIXELFORMATDESCRIPTOR pfd =
	{
		sizeof(PIXELFORMATDESCRIPTOR),
		1,
		PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER, //Flags
		PFD_TYPE_RGBA, //The kind of framebuffer. RGBA or palette.
		32, //Colordepth of the framebuffer.
		0, 0, 0, 0, 0, 0,
		0,
		0,
		0,
		0, 0, 0, 0,
		24, //Number of bits for the depthbuffer
		8, //Number of bits for the stencilbuffer
		0, //Number of Aux buffers in the framebuffer.
		PFD_MAIN_PLANE,
		0,
		0, 0, 0
	};
	m_DC = GetDC(this->GetHWND());
	int format = ChoosePixelFormat(m_DC, &pfd);
	if (format == 0)
		return; // 該当するピクセルフォーマットが無い

	// OpenGLが使うデバイスコンテキストに指定のピクセルフォーマットをセット
	if (!SetPixelFormat(m_DC, format, &pfd))
		return; // DCへフォーマットを設定するのに失敗

	// OpenGL contextを作成
	m_GLRC = wglCreateContext(m_DC);

	// 作成されたコンテキストがカレント（現在使用中のコンテキスト）か？
	if (!wglMakeCurrent(m_DC, m_GLRC))
		return; // 何か正しくないみたい…

}


bool wxWidgetsSampleApp::OnInit()
{
	wxApp::OnInit();
	wxInitAllImageHandlers();

	wxFrame *frame = new wxWidgetsSampleFrame( _("Hello World"));


    frame->Show(true);
    SetTopWindow(frame);
    return true;
}



IMPLEMENT_APP(wxWidgetsSampleApp)

void ConvertPCMToImageData(unsigned char* rawPCM, unsigned char* rawImage)
{
    for (int i=0; i<256*256*3; ++i)
    {
        rawImage[i] = rawPCM[i];
    }
}