#pragma once
#include "wx/wx.h"
#include <vector>
#include "ship.h"
#include "ship1.h"
#include "ship2.h"
#include "ship3.h"
#include "patron.h"
#include "Mypanel.h"

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
    wxBitmap image1;
    int size = 3;
    int count = 1;
    int random;
    int count_patron = 0;
    int status = 0;
    wxTimer Timer;
    wxPanel* Panel1;
    wxPanel* Panel2;
    wxPanel* player;
    wxBitmap* temp;
    Patron* p;
    wxButton* button1;
    wxButton* button2;
    const int MAX_Y = 700;



    wxBitmap* m_bitmap;
    bool m_isDragging = false;
    wxPoint m_prevPosition;
};