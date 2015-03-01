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
#include "wx/wx.h"

class MyApp: public wxApp
{
    virtual bool OnInit();
};

bool MyApp::OnInit()
{
    wxFrame *frame = new wxFrame(	NULL, -1, _("Hello World"),
                                 wxPoint(10, 10), wxSize(200, 200) );
    frame->Show(true);
    SetTopWindow(frame);
    return true;
}

IMPLEMENT_APP(MyApp)