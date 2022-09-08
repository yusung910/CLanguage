#pragma once
#include "Init.h"
class SetupD3D : Init {
public:
    SetupD3D();
    ~SetupD3D();

    //D3D �ʱ�ȭ
    HRESULT InitD3D(HWND hWnd);
    //vertex buffer �ʱ�ȭ
    HRESULT InitVB();
    //index buffer �ʱ�ȭ
    HRESULT InitIB();
    //texture �ʱ�ȭ
    HRESULT InitTexture();
    //�ʱ�ȭ
    VOID CleanUp();

protected:

private:

};