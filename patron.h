#pragma once
#include <wx/wx.h>
#include "Pattern.h"


class Patron: public Pattern{
private:
public:
    Patron(){
        wxInitAllImageHandlers();
        image = new wxBitmap("C:/Users/User/Project/arkada/Patron1.jpg", wxBITMAP_TYPE_JPEG);
    }
};