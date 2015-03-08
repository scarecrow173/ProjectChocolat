//=======================================================================================
//!	@file	:	wxWidgetsSample.h
//!	@author	:	Akiyoshi Koyama
//!	@date	:	2014/3/8
//! @brief	:	sample classes
//=======================================================================================
#pragma once
#include "wx/wx.h"

//=======================================================================================
//!	@class	:	wxWidgetsSampleApp
//!	@brief	:	Application class
//!	@par	:	sample acclication
//!	@note	:	temporary
//=======================================================================================
class wxWidgetsSampleApp : public wxApp
{
	virtual bool OnInit();
};
//=======================================================================================
//!	@class	:	wxWidgetsSampleFrame
//!	@brief	:	Frame class
//!	@par	:	sample Frame
//!	@note	:	temporary
//=======================================================================================
class wxWidgetsSampleFrame : public wxFrame
{
public:
	wxWidgetsSampleFrame(const wxString& title);
	~wxWidgetsSampleFrame() { }

	void OnSelectFile(wxCommandEvent& event);
	void OnQuit(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);
	void OnSave(wxCommandEvent& event);
	void NotifyUsingFile(const wxString& name);

	wxDECLARE_EVENT_TABLE();
};

// IDs for the controls and the menu commands
enum wxMenuCommand
{
	// menu items
	SelectFile = wxID_HIGHEST + 1,
	SaveFile,
	Quit = wxID_EXIT,
	About = wxID_ABOUT
};

//===============================================================
//	End of File
//===============================================================