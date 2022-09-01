#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

class Init {
public:
    Init();
    ~Init();
    void SetInitGlobal(LPDIRECT3DDEVICE9 g_pd3dDevice, LPDIRECT3DINDEXBUFFER9  g_pIB);
    void SetObjectInit();
	void SetObject(D3DXMATRIX obj, float x, float y);
    void SetPos();

protected:
    D3DXMATRIX tempTM[10];
    LPDIRECT3DDEVICE9       g_pd3dDevice;
    LPDIRECT3DINDEXBUFFER9  g_pIB;

    int n_TmCnt = 10;
    float f_TmMovePosList[10][2];

private:

};