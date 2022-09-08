#pragma once
#include "Init.h"
class SetupD3D : Init {
public:
    SetupD3D();
    ~SetupD3D();

    //D3D 초기화
    HRESULT InitD3D(HWND hWnd);
    //vertex buffer 초기화
    HRESULT InitVB();
    //index buffer 초기화
    HRESULT InitIB();
    //texture 초기화
    HRESULT InitTexture();
    //초기화
    VOID CleanUp();

protected:

private:

};