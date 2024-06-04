#pragma once
#include <wx/wx.h>
#include "ship.h"

class Ship3: public Ship{
public:
    Ship3(){
        hp = 3;
        wxInitAllImageHandlers();
        image = new wxBitmap("C:/Users/User/Project/arkada/image_ship3.jpg", wxBITMAP_TYPE_JPEG);
    }

    void Reset() override {
        srand(time(nullptr));
        hp = 3;
        int random = 60 * (rand() % 16);
        this->ChangePosition(random, -30);
    }
};