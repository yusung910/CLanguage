#pragma once
#include "Init.h"
class Render{
public :
    Render();
    ~Render();
    VOID MainRender();
    VOID KeyControl();
protected:
    FLOAT g_fXmove = 0.0f, g_fZmove = 0.0f;				//�̵��� ���� ����
    FLOAT g_fRX = 0.0f, g_fRY = 0.0f, g_fRZ = 0.0f;	//ȸ���� ���� ����
    FLOAT g_fX = 0.0f, g_fY = 0.0f, g_fZ = 0.0f;	//��ǥ�� ���� ����
private:
};