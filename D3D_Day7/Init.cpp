#include "Init.h"

Init::Init() {

}

Init::~Init() {
    //社瑚切
}

void Init::SetInitGlobal(LPDIRECT3DDEVICE9 device, LPDIRECT3DINDEXBUFFER9 ib) {
    //持失切
    float f_MaxPos = 5.0f;
    for (int i = 0; i < n_TmCnt; i++) {
        f_TmMovePosList[i][0] = (rand() % 100 - 50) / 20;
        f_TmMovePosList[i][1] = (rand() % 100 - 50) / 20;
    };
    g_pd3dDevice = device;
    g_pIB = ib;
}

void Init::SetObjectInit() {
    for (int i = 0; i < n_TmCnt; i++) {
		SetObject(tempTM[i], f_TmMovePosList[i][0], f_TmMovePosList[i][1]);
    }
}

void Init::SetPos() {

    if (GetKeyState(VK_LEFT) & 0x80) {
        f_TmMovePosList[0][0] -= 0.1f;
    }
    if (GetKeyState(VK_RIGHT) & 0x80) {
        f_TmMovePosList[0][0] += 0.1f;
    }
    if (GetKeyState(VK_UP) & 0x80) {
        f_TmMovePosList[0][1] += 0.1f;
    }
    if (GetKeyState(VK_DOWN) & 0x80) {
        f_TmMovePosList[0][1] -= 0.1f;
    }

	SetObject(tempTM[0], f_TmMovePosList[0][0], f_TmMovePosList[0][1]);
};

void Init::SetObject(D3DXMATRIX obj, float x, float y) {
	D3DXMatrixIdentity(&obj);
	g_pd3dDevice->SetTransform(D3DTS_VIEW, &obj);
	D3DXMatrixTranslation(&obj, x, y, 1.0f);
	g_pd3dDevice->SetTransform(D3DTS_WORLD, &obj);
	g_pd3dDevice->SetIndices(g_pIB);
	g_pd3dDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 8, 0, 12);
}
