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

void Init::SetObject() {
    for (int i = 0; i < n_TmCnt; i++) {
        D3DXMatrixIdentity(&tempTM[i]);
        g_pd3dDevice->SetTransform(D3DTS_VIEW, &tempTM[i]);
        D3DXMatrixTranslation(&tempTM[i], f_TmMovePosList[i][0], f_TmMovePosList[i][1], 1.0f);
        g_pd3dDevice->SetTransform(D3DTS_WORLD, &tempTM[i]);
        g_pd3dDevice->SetIndices(g_pIB);
        g_pd3dDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 8, 0, 12);
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

    D3DXMatrixIdentity(&tempTM[0]);
    g_pd3dDevice->SetTransform(D3DTS_VIEW, &tempTM[0]);
    D3DXMatrixTranslation(&tempTM[0], f_TmMovePosList[0][0], f_TmMovePosList[0][1], 1.0f);
    g_pd3dDevice->SetTransform(D3DTS_WORLD, &tempTM[0]);
    g_pd3dDevice->SetIndices(g_pIB);
    g_pd3dDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 8, 0, 12);
};
