#pragma once
#include <wx/wx.h>

class MyPanel{
private:
protected:
    wxBitmap* image;
    wxPoint point;
public:
    MyPanel(){
        point = wxPoint(0, 0);
        wxInitAllImageHandlers();
        image = new wxBitmap("C:/Users/User/Project/arkada/6666.jpg", wxBITMAP_TYPE_JPEG);
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