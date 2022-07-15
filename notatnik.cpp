#include"notatnik.h"

MyFrame::MyFrame()
    : wxFrame(NULL, wxID_ANY, "Notatnik")
{
    wxDisplay display(wxDisplay::GetFromWindow(this));
    wxRect screen = display.GetClientArea();
    wxSize frameSize(screen.width / 100 * 69, screen.height / 100 * 75);

    SetSize(frameSize);
    //Setting text field

    editBox = new wxTextCtrl(this, ID_TEXT_Main, "Hi", wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxTE_RICH, wxDefaultValidator, wxTextCtrlNameStr);
    wxFont notepadFont(20, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_MEDIUM, false);
    editBox->SetFont(notepadFont);

    //ZAKLADKA File
    wxMenu* menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
        "Help string shown in status bar for this menu item");
    menuFile->Append(wxID_ANY, "Nowa");
    menuFile->Append(wxID_ANY, "Nowe okno");
    menuFile->Append(wxID_ANY, "Otwórz");
    menuFile->Append(wxID_ANY, "Zapisz");
    menuFile->Append(wxID_ANY, "Zapisz jako");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);

    //zakladka Edit
    wxMenu* menuEdit = new wxMenu;
    menuEdit->Append(wxID_ANY, "Cofnij");
    menuEdit->Append(wxID_ANY, "Wytnij");
    menuEdit->Append(wxID_ANY, "Kopiuj");
    menuEdit->Append(wxID_ANY, "Wklej");
    menuEdit->Append(wxID_ANY, "Wklej");
    menuEdit->Append(wxID_ANY, "Usuñ");
    menuFile->AppendSeparator();
    menuEdit->Append(ID_FontBox, "Czcionka");
    //zakladka Help
    wxMenu* menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    //zakladka Display
    wxMenu* menuDisplay = new wxMenu;
    wxMenu* menuPowieksz = new wxMenu;
    menuPowieksz->Append(wxID_ANY, "Powieksz");
    menuPowieksz->Append(wxID_ANY, "Pomniejsz");
    menuPowieksz->Append(wxID_ANY, "Przywroc powiekszenie domyslne");

    menuDisplay->AppendSubMenu(menuPowieksz, "Powiekszanie");
    menuDisplay->AppendCheckItem(wxID_ANY, "Pasek stanu");
    menuDisplay->AppendCheckItem(wxID_ANY, "Zawijanie wierszy");


    wxMenuBar* menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&Plik");
    menuBar->Append(menuEdit, "&Edytuj");
    menuBar->Append(menuDisplay, "&Wyswietl");
    menuBar->Append(menuHelp, "&Pomoc");

    SetMenuBar(menuBar);

    CreateStatusBar();
    SetStatusText("Welcome to wxWidgets!");

    Bind(wxEVT_MENU, &MyFrame::OnHello, this, ID_Hello);
    Bind(wxEVT_MENU, &MyFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &MyFrame::OnExit, this, wxID_EXIT);
    Bind(wxEVT_MENU, &MyFrame::OnDisplay, this, ID_Display);
    Bind(wxEVT_MENU, &MyFrame::OnFont(, this), this, ID_FontBox);

}

void MyFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}

void MyFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("This is a wxWidgets Hello World example",
        "About Hello World", wxOK | wxICON_INFORMATION);
}

void MyFrame::OnHello(wxCommandEvent& event)
{
    wxLogMessage("Hello world from wxWidgets!");
}
void MyFrame::OnDisplay(wxCommandEvent& event)
{
    wxLogMessage("Powiêkszenie");
}
MyFontFrame::MyFontFrame(wxWindow &p)
    :wxFrame(NULL, wxID_ANY, "Czcionka") {

}
void MyFrame::OnFont(wxCommandEvent& event, wxWindow &p)
{
    MyFontFrame* fontFrame = new MyFontFrame(p);
    fontFrame->Show(true);
}