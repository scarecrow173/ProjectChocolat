#include "wxWidgetsSample.h"
#include <stdio.h>
#include "ImageWriter.h"
#include "AudioLoader.h"

void ConvertPCMToImageData(WAVReader* reader, unsigned char* rawImage);
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
wxEND_EVENT_TABLE()

wxWidgetsSampleFrame::wxWidgetsSampleFrame(const wxString& title)
	:	wxFrame	(NULL, wxID_ANY, title)
{
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
        
		AudioLoader *audioLoad = new AudioLoader(dlg.GetPath());
        unsigned char* wavtable = audioLoad->wav->pcmData();
		
		const int widht = 256;
		const int height = 256;
		const int colorNum = 3; // RGB
		unsigned char* rawData = new unsigned char[(widht * height) * colorNum];

		ConvertPCMToImageData(audioLoad->wav, rawData);

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

bool wxWidgetsSampleApp::OnInit()
{
	wxFrame *frame = new wxWidgetsSampleFrame( _("Hello World"));
    frame->Show(true);
    SetTopWindow(frame);
    return true;
}

IMPLEMENT_APP(wxWidgetsSampleApp)

void ConvertPCMToImageData(WAVReader* reader, unsigned char* rawImage)
{
	
}