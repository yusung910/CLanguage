#pragma once
#include <conio.h>
#include "Drawing.h"

class CSystem : public Drawing {
public:
    //������
    CSystem();
    //�Ҹ���
    ~CSystem();

    void InitBasicDisplayArea();
protected:

private:
    int m_nBackground[50][150];
    int m_nDisplayX = 150;
    int m_nDisplayY = 50;
};