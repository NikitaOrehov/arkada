#include "game.h"
#include <iostream>
#include <random>


game::game() : wxFrame(nullptr, wxID_ANY, "game", wxPoint(0, 0), wxSize(1920, 1080)){
    wxInitAllImageHandlers();
    background = wxBitmap("C:/Users/User/Project/arkada/image/background_game4.jpg", wxBITMAP_TYPE_JPEG);
    image_player = new wxBitmap("C:/Users/User/Project/arkada/image/player.png", wxBITMAP_TYPE_PNG);

    player = new Ship1();
    player->ChangePosition(500, 700);
    player->SetPlanel(image_player);

    Timer = new wxTimer(this);
    Timer->SetOwner(this);

    enemy = std::vector<Ship*>(20);
    srand(time(nullptr));
    for (int i = 0; i < 20; i++){
        int random1 = rand() % 3;
        random = 100 * (rand() % 10);
        if (random1 == 0){
            enemy[i] = new Ship1();
            enemy[i]->ChangePosition(random, -100);
        }
        else if (random1 == 1){
            enemy[i] = new Ship2();
            enemy[i]->ChangePosition(random, -100);
        }
        else{
            enemy[i] = new Ship3();
            enemy[i]->ChangePosition(random, -100);
        }
    }

    Bind(wxEVT_PAINT, game::OnPaint, this);
    Bind(wxEVT_KEY_DOWN, game::OnKeyDown, this);
}

void game::start(){
    this->Bind(wxEVT_TIMER, [this](wxTimerEvent){
        if (count % 20 == 0){
            p = new Patron();
            p->ChangePosition(player->GetX() + 48, player->GetY());
            patrons.push_back(p);
        }
        if (count % 350 == 0 && size < 20){
            size += 1;
        }
        else{
            for (int i = 0; i < size; i++){
                if (enemy[i]->GetY() == -100){
                    random = rand() % 2;
                    if (random == 1){
                        enemy[i]->Move(0, 3);
                    }
                }
                else{
                    enemy[i]->Move(0, 3);
                }
                if (enemy[i]->GetY() + 2 >= 670){
                    Timer->Stop();
                    RestartGame();
                }
            }
            for (int i = 0; i < patrons.size(); i++){
                for (int j = 0; j < size; j++){
                    status = check(patrons[i], enemy[j]);
                    if (status == 1){
                        if (i == (patrons.size() - 1)){
                            patrons[i]->ChangePosition(-0, -50);
                            patrons.pop_back();
                            enemy[j]->Reset();
                            break;
                        }
                        patrons[i]->ChangePosition(-50, -50);
                        p = patrons[patrons.size() - 1];
                        patrons[patrons.size() - 1] = patrons[i];
                        patrons[i] = p;
                        patrons.pop_back();
                        enemy[j]->Reset();
                    }
                    else if (status == -1){
                        if (i == (patrons.size() - 1)){
                            patrons[i]->ChangePosition(-50, -50);
                            patrons.pop_back();
                            break;
                        }
                        patrons[i]->ChangePosition(-50, -50);
                        p = patrons[patrons.size() - 1];
                        patrons[patrons.size() - 1] = patrons[i];
                        patrons[i] = p;
                        patrons.pop_back();
                    }
                }
                if (patrons[i]->GetY() - 10 < -10 && patrons.size() != i){
                    patrons[i]->Move(-50, -50);
                    p = patrons[patrons.size() - 1];
                    patrons[patrons.size() - 1] = patrons[i];
                    patrons[i] = p;
                    patrons.pop_back();//������� ������?
                }
                else{
                    patrons[i]->Move(0, -10);
                }
            }
        }
        count += 1;
        Refresh();
    });
}

void game::OnPaint(wxPaintEvent& event){
    wxPaintDC dc(this);
    dc.DrawBitmap(background, wxPoint(0, 0));
    dc.DrawBitmap(*(player->GetBitmap()), player->GetPoint());
    for (int i = 0; i < size; i++){
        dc.DrawBitmap(*enemy[i]->GetBitmap(), enemy[i]->GetPoint());
    }
    for (int i = 0; i < patrons.size(); i++){
        dc.DrawBitmap(*patrons[i]->GetBitmap(), patrons[i]->GetPoint());
    }
}

void game::OnKeyDown(wxKeyEvent& event){
    int key = event.GetKeyCode();
    switch(key){
        case 65: player->Move(-50, 0); break;
        case 68: player->Move(30, 0); break;
        case WXK_SPACE: Timer->Start(150); break;
        case WXK_ESCAPE: Timer->Stop(); break;
        default: event.Skip(); break;
    }
}


int game::check(Patron* patron, Ship* enemys){
    if (patron->GetY() < (enemys->GetY() + 100) && patron->GetY() > enemys->GetY()){
        if (patron->GetX() < enemys->GetX() + 100 && patron->GetX() > enemys->GetX()){
            enemys->ChangeHp();
            if (enemys->GetHp() == 0){
                return 1;
            }
            return -1;
        }
    }
    if (patron->GetY() < enemys->GetY() + 100 && patron->GetY() > enemys->GetY()){
        if (patron->GetX() + 5 < enemys->GetX() + 100 && patron->GetX() + 5 > enemys->GetX()){
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
        enemy[i]->ChangePosition(random, -100);
    }
    for (int i = 0; i < patrons.size(); i++){
        patrons[i]->ChangePosition(-100, -100);
    }
    patrons.clear();
    int size = 3;
    int count = 1;
    int random;
    int count_patron = 0;
    bool status = 0;
    Refresh();
}