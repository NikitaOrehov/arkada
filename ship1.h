#pragma once
#include <wx/wx.h>
#include "ship.h"

class Ship1: public Ship{
private:
public:
    Ship1(){
        hp = 1;
        wxInitAllImageHandlers();
        image = new wxBitmap("C:/Users/User/Project/arkada/image/ship1.png", wxBITMAP_TYPE_PNG);
    }

    void Reset() override {
        srand(time(nullptr));
        hp = 1;
        int random = 100 * (rand() % 10);
        this->ChangePosition(random, -100);
    }
};