#include "Init.h"
Init::Init() {
    //持失切
}

Init::~Init() {
    //社瑚切
}


void Init::SetInitGlobal(LPDIRECT3DDEVICE9 device, LPDIRECT3DINDEXBUFFER9 ib) {
    //持失切
    g_pd3dDevice = device;
    g_pIB = ib;
}

void Init::SetPos() {

    if (GetKeyState(VK_LEFT) & 0x80) {
        f_ObjectPos[0] -= f_Speed;
    }
    if (GetKeyState(VK_RIGHT) & 0x80) {
        f_ObjectPos[0] += f_Speed;
    }
    if (GetKeyState(VK_UP) & 0x80) {
        f_ObjectPos[1] += f_Speed;
    }
    if (GetKeyState(VK_DOWN) & 0x80) {
        f_ObjectPos[1] -= f_Speed;
    }

    if (GetKeyState('Q') & 0x80) {
        n_x += n_RSpeed;
    }
    if (GetKeyState('A') & 0x80) {
        n_x -= n_RSpeed;
    }

    if (GetKeyState('W') & 0x80) {
        n_y += n_RSpeed;
    }
    if (GetKeyState('S') & 0x80) {
        n_y -= n_RSpeed;
    }

    if (GetKeyState('E') & 0x80) {
        n_z += n_RSpeed;
    }
    if (GetKeyState('D') & 0x80) {
        n_z -= n_RSpeed;
    }

};

void Init::SetObj() {
    D3DXMatrixIdentity(&tempTM1);

    D3DXMatrixTranslation(&tempTM1, f_ObjectPos[0], f_ObjectPos[1], 1.0f);
    D3DXMatrixRotationYawPitchRoll(&tempTM2, D3DXToRadian(n_x), D3DXToRadian(n_y), D3DXToRadian(n_z));
    //D3DXMatrixTranslation(&tempTM3, f_ObjectPos[0], f_ObjectPos[1], 1.0f);

    D3DXMatrixMultiply(&tempTM4, &tempTM1, &tempTM2);
    //D3DXMatrixMultiply(&tempTM4, &tempTM1, &tempTM3);

    g_pd3dDevice->SetTransform(D3DTS_WORLD, &tempTM4);
    g_pd3dDevice->SetIndices(g_pIB);
    g_pd3dDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 8, 0, 12);
}