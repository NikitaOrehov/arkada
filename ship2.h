#pragma once
#include <wx/wx.h>
#include "ship.h"

class Ship2: public Ship{
public:
    Ship2(){
        hp = 2;
        wxInitAllImageHandlers();
        image = new wxBitmap("C:/Users/User/Project/arkada/image_ship2.jpg", wxBITMAP_TYPE_JPEG);
    }

    void Reset() override {
        srand(time(nullptr));
        hp = 2;
        int random = 60 * (rand() % 16);
        this->ChangePosition(random, -30);
    }
};