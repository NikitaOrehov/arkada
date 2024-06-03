#include "game.h"
// #include <iostream>
#include <random>

game::game() : wxFrame(nullptr, wxID_ANY, "game", wxDefaultPosition, wxSize(1000, 1200)){
    wxInitAllImageHandlers();
    image1 = wxBitmap("C:/Users/User/Project/arkada/6666.jpg", wxBITMAP_TYPE_JPEG);
    wxPanel* MainPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(1000, 1100));
    MainPanel->SetBackgroundColour(wxColor(100, 100, 200));

    wxBoxSizer* MainSizer = new wxBoxSizer(wxVERTICAL);

    Panel2 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(1000, 70));//нижн€€ полоса
    Panel2->SetBackgroundColour(wxColor(100, 200, 100));

    button1 = new wxButton(Panel2, wxID_ANY, _T("start"), wxDefaultPosition, wxSize(100, 50));//старт
    button2 = new wxButton(Panel2, wxID_ANY, _T("reset"), wxDefaultPosition, wxSize(100, 50));
    wxButton* left = new wxButton(Panel2, wxID_ANY, _T("left"), wxDefaultPosition, wxSize(100, 50));
    wxButton* right = new wxButton(Panel2, wxID_ANY, _T("right"), wxDefaultPosition, wxSize(100, 50));

    button2->Disable();

    wxBoxSizer* Sizer2 = new wxBoxSizer(wxHORIZONTAL);//хранит кнопки
    Sizer2->Add(button1, 0, wxEXPAND | wxALL, 10);
    Sizer2->Add(button2, 0, wxEXPAND | wxALL, 10);
    Sizer2->Add(left, 0, wxEXPAND | wxALL, 10);
    Sizer2->Add(right, 0, wxEXPAND | wxALL, 10);

    Panel2->SetSizer(Sizer2);

    MainSizer->Add(MainPanel, 1, wxEXPAND);
    MainSizer->Add(Panel2, 0, wxEXPAND);

    this->SetSizerAndFit(MainSizer);

    player = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(30, 30));
    player->SetBackgroundColour(wxColor(200, 200, 100));
    player->Move(480, 600);

    Timer.SetOwner(this);

    left->Bind(wxEVT_BUTTON, [this](wxCommandEvent &event){
        player->Move(player->GetPosition().x - 30, player->GetPosition().y);
    });

    right->Bind(wxEVT_BUTTON, [this](wxCommandEvent &event){
        player->Move(player->GetPosition().x + 30, player->GetPosition().y);
    });

    button1->Bind(wxEVT_BUTTON, [this](wxCommandEvent &event){
        button1->Disable();
        button2->Enable();
        Timer.Start(100);
    });
    button2->Bind(wxEVT_BUTTON, [this](wxCommandEvent& event){
        Timer.Stop();
        std::cout<<"Stop1 \n";
        button1->Enable();
        button2->Disable();
        RestartGame();
    });

    Bind(wxEVT_PAINT, &game::OnPaint, this);

    enemy = std::vector<Ship*>(20);
    srand(time(nullptr));
    for (int i = 0; i < 20; i++){
        int random1 = rand() % 3;
        random = 60 * (rand() % 16);
        if (random1 == 0){
            enemy[i] = new Ship1();
            enemy[i]->ChangePosition(random, -30);
        }
        else if (random1 == 1){
            enemy[i] = new Ship2();
            enemy[i]->ChangePosition(random, -30);
        }
        else{
            enemy[i] = new Ship3();
            enemy[i]->ChangePosition(random, -30);
        }
    }
}

void game::start(){
    this->Bind(wxEVT_TIMER, [this](wxTimerEvent){
        std::cout<<"777\n";
        if (count % 20 == 0){
            p = new Patron();
            p->ChangePosition(player->GetPosition().x + 12, player->GetPosition().y);
            patrons.push_back(p);
        }
        std::cout<<"iii\n";
        if (count % 350 == 0 && size < 20){
            size += 1;
        }
        else{
            for (int i = 0; i < size; i++){
                if (enemy[i]->GetY() == -30){
                    random = rand() % 2;
                    if (random == 1){
                        enemy[i]->Move(0, 3);
                    }
                }
                else{
                    enemy[i]->Move(0, 3);
                }
                if (enemy[i]->GetY() + 2 >= 700){
                    Timer.Stop();
                    button1->Enable();
                    button2->Disable();
                    RestartGame();
                    std::cout<<"Stop2 \n";
                }
            }
            for (int i = 0; i < patrons.size(); i++){
                std::cout<<"000\n";
                for (int j = 0; j < size; j++){
                    std::cout<<"-1-1-1\n";
                    status = check(patrons[i], enemy[j]);
                    std::cout<<"111\n";
                    if (status == 1){
                        if (i == (patrons.size() - 1)){
                            patrons[i]->ChangePosition(-30, -30);
                            patrons.pop_back();
                            random = 60 * (rand() % 16);
                            enemy[j]->ChangePosition(random, -30);
                            break;
                        }
                        patrons[i]->ChangePosition(-30, -30);
                        p = patrons[patrons.size() - 1];
                        patrons[patrons.size() - 1] = patrons[i];
                        patrons[i] = p;
                        patrons.pop_back();
                        random = 60 * (rand() % 16);
                        enemy[j]->ChangePosition(random, -30);
                    }
                    else if (status == -1){
                        if (i == (patrons.size() - 1)){
                            patrons[i]->ChangePosition(-30, -30);
                            patrons.pop_back();
                            break;
                        }
                        patrons[i]->ChangePosition(-30, -30);
                        p = patrons[patrons.size() - 1];
                        patrons[patrons.size() - 1] = patrons[i];
                        patrons[i] = p;
                        patrons.pop_back();
                    }
                }
                if (patrons[i]->GetY() - 10 < -10 && patrons.size() != i){
                    patrons[i]->Move(-30, -30);
                    p = patrons[patrons.size() - 1];
                    patrons[patrons.size() - 1] = patrons[i];
                    patrons[i] = p;
                    patrons.pop_back();//крашнет пам€ть?
                }
                else{
                    patrons[i]->Move(0, -10);
                }
            }
        }
        count += 1;
        Refresh();
        std::cout<<"999\n";
    });
}

void game::OnPaint(wxPaintEvent& event){
    wxPaintDC dc(this);
    dc.DrawBitmap(image1, wxPoint(0, 0));
    for (int i = 0; i < size; i++){
        std::cout<<"\n\n\n\n1\n";
        dc.DrawBitmap(*enemy[i]->GetBitmap(), enemy[i]->GetPoint());
    }
}


int game::check(Patron* patron, Ship* enemys){
    if (patron->GetY() < (enemys->GetY() + 30) && patron->GetY() > enemys->GetY()){
        if (patron->GetX() < enemys->GetX() + 30 && patron->GetX() > enemys->GetX()){
            enemys->ChangeHp();
            if (enemys->GetHp() == 0){
                return 1;
            }
            return -1;
        }
    }
    if (patron->GetY() < enemys->GetY() + 30 && patron->GetY() > enemys->GetY()){
        if (patron->GetX() + 5 < enemys->GetX() + 30 && patron->GetX() + 5 > enemys->GetX()){
            enemys->ChangeHp();
            if (enemys->GetHp() == 0){
                return 1;
            }
            return -1;
        }
    }
    return 0;
}

void game::RestartGame(){
    for (int i = 0; i < size; i++){
        random = 60 * (rand() % 16);
        enemy[i]->ChangePosition(random, -30);
    }
    for (int i = 0; i < patrons.size(); i++){
        patrons[i]->ChangePosition(-30, -30);
    }
    patrons.clear();
    int size = 3;
    int count = 1;
    int random;
    int count_patron = 0;
    bool status = 0;
    Refresh();
}