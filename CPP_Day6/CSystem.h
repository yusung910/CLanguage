#pragma once
#include "CPoint.h"
#include "CString.h"

class CSystem : CPoint, CString {
public:
    //������
    CSystem();
    //�Ҹ���
    ~CSystem();

    void PrintBorderLine();
private:
    int m_nScreenX;
    int m_nScreenY;
protected:
};