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
    D3DXMATRIX tmWorld, tmTrans, tmScale, tmRotX, tmRotY, tmRotZ,  tmRotAxis;
    LPDIRECT3DDEVICE9       g_pd3dDevice;
    LPDIRECT3DINDEXBUFFER9  g_pIB;
    D3DXVECTOR3 rotVec = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
    float f_ObjectPos[2];
    float f_Speed = 0.5f;
    float n_RSpeed = 0.5f;
    float n_x = 5.0f;
    float n_y = 0.0f;
    float n_z = 0.0f;
    float n_test = 0.0f;
private:

};