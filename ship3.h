#pragma once
#include <wx/wx.h>
#include "ship.h"

class Ship3: public Ship{
public:
    Ship3(){
        hp = 3;
        wxInitAllImageHandlers();
        image = new wxBitmap("C:/Users/User/Project/arkada/image/ship3.png", wxBITMAP_TYPE_PNG);
    }

    void Reset() override {
        srand(time(nullptr));
        hp = 3;
        int random = 100 * (rand() % 10);
        this->ChangePosition(random, -100);
    }
};