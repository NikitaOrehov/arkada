#include <wx/wx.h>
#include "game.h"
#include <vector>
 
class MyApp : public wxApp
{
public:
    bool OnInit() override;
};
 

wxIMPLEMENT_APP(MyApp);

 
class MyFrame : public wxFrame
{
public:
    MyFrame();
    void start(wxCommandEvent&);
    void exit(wxCommandEvent&);
    void setting(wxCommandEvent&);
private:
};

MyFrame::MyFrame()
    : wxFrame(nullptr, wxID_ANY, "Hello World")
{
    wxPanel* MainPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(600, 600));
    MainPanel->SetBackgroundColour(wxColor(100, 200, 100));//зелёный

    wxBoxSizer* MainSizer = new wxBoxSizer(wxVERTICAL);
    MainSizer->Add(MainPanel, 1, wxEXPAND);

    wxPanel* MenuPanel = new wxPanel(MainPanel, wxID_ANY, wxDefaultPosition, wxSize(150, 300));
    MenuPanel->SetBackgroundColour(wxColor(200, 100, 100));//красный
    wxBoxSizer* MenuSizer = new wxBoxSizer(wxVERTICAL);
    MenuSizer->Add(MenuPanel, 1, wxEXPAND | wxALL, 100);

    MainPanel->SetSizerAndFit(MenuSizer);

    wxButton* start = new wxButton(MenuPanel, wxID_ANY, _T("start"), wxDefaultPosition, wxSize(70, 40));
    wxButton* setting = new wxButton(MenuPanel, wxID_ANY, _T("setting"), wxDefaultPosition, wxSize(70, 40));
    wxButton* exit = new wxButton(MenuPanel, wxID_EXIT, _T("exit"), wxDefaultPosition, wxSize(70, 40));
    wxBoxSizer* ButtonSizer = new wxBoxSizer(wxVERTICAL);
    ButtonSizer->Add(start, 1, wxEXPAND | wxALL, 20);
    ButtonSizer->Add(setting, 1, wxEXPAND | wxALL, 20);
    ButtonSizer->Add(exit, 1, wxEXPAND | wxALL, 20);
    MenuPanel->SetSizerAndFit(ButtonSizer);

    this->SetSizerAndFit(MainSizer);


    start -> Bind(wxEVT_BUTTON, &MyFrame::start, this);
    setting -> Bind(wxEVT_BUTTON, &MyFrame::setting, this);
    exit -> Bind(wxEVT_BUTTON, &MyFrame::exit, this);
}

void MyFrame::exit(wxCommandEvent& e){
    this->Close();
}

void MyFrame::start(wxCommandEvent& e){
    game* GameFrame = new game();
    GameFrame->Show(true);
    GameFrame->start();
}

void MyFrame::setting(wxCommandEvent& e){
    
}

bool MyApp::OnInit()
{
    MyFrame *frame = new MyFrame();
    frame->Show(true);
    return true;
}
