#pragma once
#include <wx/wx.h>
#include "Pattern.h"
#include <random>


class Ship: public Pattern{
private:
protected:
    size_t hp;
public:
    Ship(){
        hp = 1;
    }
    int ChangeHp(){
        hp -= 1;
        if (hp == 0){
            return 0;
        }
        return 1;
    }

    void ChangeHp(int i){
        hp = i;
    }

    int GetHp(){
        return hp;
    }

    virtual void Reset() = 0;
};

//sfml