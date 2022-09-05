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

    if (GetKeyState('R') & 0x80) {
        n_test += n_RSpeed;
    }
    if (GetKeyState('F') & 0x80) {
        n_test -= n_RSpeed;
    }
};

void Init::SetObj() {
	D3DXMatrixIdentity(&tmWorld);
    //g_pd3dDevice->GetTransform(D3DTS_WORLD, &tmWorld);
	D3DXMatrixTranslation(&tmTrans, 0.0f, -1.0f, 0.0f );
	D3DXMatrixRotationX(&tmRotX, D3DXToRadian(n_x));
	//D3DXMatrixTranslation(&tmWorld, 0.0f, 0.0f, 0.0f);

	//D3DXMatrixMultiply(&tmWorld, &tmWorld, &tmTrans);
	//D3DXMatrixMultiply(&tmWorld, &tmRotX, &tmWorld);

	g_pd3dDevice->SetTransform(D3DTS_WORLD, &(tmWorld * tmTrans * tmRotX));
    
}