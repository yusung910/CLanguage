#pragma once
#include "Init.h"

class SetupD3D : Init {
public:
    SetupD3D();
    ~SetupD3D();

    //D3D 초기화
    HRESULT InitD3D(HWND hWnd);
    //index buffer 초기화
    HRESULT InitIB();
    //texture 초기화
    HRESULT InitTexture();

    //메인 렌더링 실행
    VOID MainRender();

    //메인 객체 이동
    VOID KeyControl();

    //초기화
    VOID CleanUp();
protected:
    FLOAT g_fXmove = 0.0f, g_fZmove = 0.0f;				//이동값 전역 변수
    FLOAT g_fRX = 0.0f, g_fRY = 0.0f, g_fRZ = 0.0f;	//회전값 전역 변수
    FLOAT g_fX = 0.0f, g_fY = 0.0f, g_fZ = 0.0f;	//좌표값 전역 변수
private:

};