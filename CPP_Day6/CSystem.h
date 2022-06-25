#pragma once
#include "CPoint.h"
#include "CString.h"

class CSystem : CPoint, CString {
public:
    //持失切
    CSystem();
    //社瑚切
    ~CSystem();

    void PrintBorderLine();
private:
    int m_nScreenX;
    int m_nScreenY;
protected:
};