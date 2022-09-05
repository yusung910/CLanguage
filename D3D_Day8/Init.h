#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include <iostream>
#include <cstdlib>
class Init {
public:
    Init();
    ~Init();

    void SetInitGlobal(LPDIRECT3DDEVICE9 g_pd3dDevice, LPDIRECT3DINDEXBUFFER9  g_pIB);
    void SetPos();
    void SetObj();
protected:
    D3DXMATRIX tempTM1, tempTM2;
    LPDIRECT3DDEVICE9       g_pd3dDevice;
    LPDIRECT3DINDEXBUFFER9  g_pIB;
    
    FLOAT f_Speed = 0.1f;
    FLOAT n_RSpeed = 0.1f;
    FLOAT nFXmove = 0.0f;
    FLOAT nFZmove = 0.0f;
    FLOAT nRx = 0.0f, nRy = 0.0f, nRz = 0.0f;
    FLOAT nCx = 0.0f, nCy = 0.0f, nCz = 0.0f;
private:

};