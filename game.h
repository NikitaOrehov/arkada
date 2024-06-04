#pragma once
#include "wx/wx.h"
#include <vector>
#include "ship.h"
#include "ship1.h"
#include "ship2.h"
#include "ship3.h"
#include "patron.h"
#include "Pattern.h"

class game: public wxFrame{
private:
    std::vector<Ship*> enemy;
    std::vector<Patron*> patrons;
public:
    game();
    void start();
    int check(Patron* patron, Ship* enemys);
    void RestartGame();
    void OnPaint(wxPaintEvent& event);
    void OnKeyDown(wxKeyEvent& event);
    wxBitmap background;
    Ship* player;
    int size = 3;
    int count = 1;
    int random;
    int status = 0;
    wxTimer* Timer;
    wxBitmap* temp;
    Patron* p;
    const int MAX_Y = 700;
};