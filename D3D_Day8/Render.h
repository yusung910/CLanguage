#pragma once
#include "Init.h"
class Render{
public :
    Render();
    ~Render();
    VOID MainRender();
    VOID KeyControl();
protected:
    FLOAT g_fXmove = 0.0f, g_fZmove = 0.0f;				//이동값 전역 변수
    FLOAT g_fRX = 0.0f, g_fRY = 0.0f, g_fRZ = 0.0f;	//회전값 전역 변수
    FLOAT g_fX = 0.0f, g_fY = 0.0f, g_fZ = 0.0f;	//좌표값 전역 변수
private:
};