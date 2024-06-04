#pragma once
#include <wx/wx.h>
#include "ship.h"

class Ship2: public Ship{
public:
    Ship2(){
        hp = 2;
        wxInitAllImageHandlers();
        image = new wxBitmap("C:/Users/User/Project/arkada/image/ship2.png", wxBITMAP_TYPE_PNG);
    }

    void Reset() override {
        srand(time(nullptr));
        hp = 2;
        int random = 100 * (rand() % 10);
        this->ChangePosition(random, -100);
    }
};