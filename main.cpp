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
    : wxFrame(nullptr, wxID_ANY, "Hello World", wxPoint(0, 0), wxSize(3000, 3000))
{
    wxInitAllImageHandlers();
    wxBitmap* image_backgroun = new wxBitmap("C:/Users/User/Project/arkada/image/background_menu.jpg", wxBITMAP_TYPE_JPEG);
    wxStaticBitmap* background = new wxStaticBitmap(this, wxID_ANY, *image_backgroun, wxPoint(0, 0), wxSize(1920, 1200));

    wxFont font(18, wxFONTFAMILY_SWISS, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD);
    wxStaticText* staticText = new wxStaticText(this, wxID_ANY, "ARKADA", wxPoint(200, 170));
    staticText->SetFont(font);

    wxBoxSizer* MainSizer = new wxBoxSizer(wxVERTICAL);
    MainSizer->Add(background, 1, wxEXPAND);

    wxPanel* MenuPanel = new wxPanel(background, wxID_ANY, wxDefaultPosition, wxSize(200, 400));
    MenuPanel->SetBackgroundColour(wxColor(102, 116, 172));//красный
    wxBoxSizer* MenuSizer = new wxBoxSizer(wxVERTICAL);
    MenuSizer->Add(MenuPanel, 1, wxEXPAND | wxALL, 150);

    background->SetSizerAndFit(MenuSizer);
    wxPanel* temp = new wxPanel(MenuPanel, wxID_ANY, wxDefaultPosition, wxSize(200, 40));
    wxButton* start = new wxButton(MenuPanel, wxID_ANY, _T("start"), wxPoint(200, 200), wxSize(150, 50));
    wxButton* setting = new wxButton(MenuPanel, wxID_ANY, _T("setting"), wxDefaultPosition, wxSize(150, 50));
    wxButton* exit = new wxButton(MenuPanel, wxID_EXIT, _T("exit"), wxDefaultPosition, wxSize(150, 50));
    wxBoxSizer* ButtonSizer = new wxBoxSizer(wxVERTICAL);
    wxSizerFlags flags1;
    ButtonSizer->Add(temp, 0, wxALL, 20);
    ButtonSizer->Add(start, 0, wxALL, 25);
    ButtonSizer->Add(setting, 0, wxALL, 25);
    ButtonSizer->Add(exit, 0, wxALL, 25);
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
