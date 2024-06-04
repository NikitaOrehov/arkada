#pragma once
#include <wx/wx.h>
#include "ship.h"

class Ship1: public Ship{
private:
public:
    Ship1(){
        hp = 1;
        wxInitAllImageHandlers();
        image = new wxBitmap("C:/Users/User/Project/arkada/6666.jpg", wxBITMAP_TYPE_JPEG);
    }

    void Reset() override {
        srand(time(nullptr));
        hp = 1;
        int random = 60 * (rand() % 16);
        this->ChangePosition(random, -30);
    }
};