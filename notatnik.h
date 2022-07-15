#pragma once
// wxWidgets "Hello World" Program

// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#include <wx/display.h>


#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};

class MyFrame : public wxFrame
{
public:
    MyFrame();
    wxTextCtrl* editBox;
private:
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnDisplay(wxCommandEvent& event);
    void OnFont(wxCommandEvent& event, wxWindow &p);
};

class MyFontFrame : public wxFrame {
    public:
        MyFontFrame(wxWindow &p);
private:
    //functions
};

enum
{
    ID_Hello = 1,
    ID_Display = 2,
    ID_View = 3,
    ID_Skale = 4,
    ID_TEXT_Main = 5,
    ID_FontBox = 6
};
