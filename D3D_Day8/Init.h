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
    D3DXMATRIX tempTM1, tempTM2, tempTM3, tempTM4;
    LPDIRECT3DDEVICE9       g_pd3dDevice;
    LPDIRECT3DINDEXBUFFER9  g_pIB;
    D3DXVECTOR3 g_vector3;
    float f_ObjectPos[2];
    float f_Speed = 0.05f;
    int n_RSpeed = 1;
    int n_x = 0;
    int n_y = 0;
    int n_z = 0;
private:

};