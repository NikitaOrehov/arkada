#pragma once
#include <wx/wx.h>

class Pattern{
private:
protected:
    wxBitmap* image;
    wxPoint point;
public:
    Pattern(){
        point = wxPoint(0, 0);
    }
    virtual void SetPlanel(wxBitmap* p){
        image = p;
    }
    int GetX(){
        return point.x;
    }
    int GetY(){
        return point.y;
    }
    void Move(int x, int y){
        point.x += x;
        point.y += y;
    }
    void ChangePosition(int x, int y){
        point.x = x;
        point.y = y;
    }

    const wxBitmap* GetBitmap(){
        return image;
    }

    wxPoint GetPoint(){
        return point;
    }
};