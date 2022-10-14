#pragma once
#include "d3d9.h"
#include "d3dx9.h"
#include <d3dx9math.h>
#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZ | D3DFVF_TEX1)

struct CUSTOMVERTEX
{
    FLOAT x, y, z;
    FLOAT tu, tv;
    D3DXVECTOR3 normal;
};

struct MYINDEX
{
    WORD _0, _1, _2;
};

class Init {
public:
    Init();
    ~Init();

protected:

    LPDIRECT3D9             g_pD3D = NULL;
    LPDIRECT3DDEVICE9       g_pd3dDevice = NULL;
    LPDIRECT3DVERTEXBUFFER9 g_pVB = NULL;
    LPDIRECT3DINDEXBUFFER9  g_pIB = NULL;
    LPDIRECT3DTEXTURE9		g_ppTexture = NULL;

private:

};