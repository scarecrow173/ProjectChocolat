#include "wxWidgetsSample.h"
#include <stdio.h>

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
	EVT_MENU(Quit, wxWidgetsSampleFrame::OnQuit)
	EVT_MENU(About, wxWidgetsSampleFrame::OnAbout)
wxEND_EVENT_TABLE()

wxWidgetsSampleFrame::wxWidgetsSampleFrame(const wxString& title)
	:	wxFrame	(NULL, wxID_ANY, title)
{
	wxMenu* menuFile = new wxMenu();
	menuFile->Append(SelectFile, wxT("Select WAV &file...\tCtrl-O"), wxT("Select a new wav file to play"));
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
	}
}
void wxWidgetsSampleFrame::OnQuit(wxCommandEvent& event)
{
	// true is to force the frame to close
	Close(true);
}
void wxWidgetsSampleFrame::OnAbout(wxCommandEvent& event)
{}
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