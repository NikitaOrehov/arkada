#pragma once
#include <wx/wx.h>
#include "MyPanel.h"

class Ship: public MyPanel{
private:
protected:
    size_t hp;
public:
    int ChangeHp(){
        hp--;
        if (hp == 0){
            return 0;
        }
        return 1;
    }

    int GetHp(){
        return hp;
    }
};

//sfml