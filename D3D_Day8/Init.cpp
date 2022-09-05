#include "Init.h"
Init::Init() {
    //생성자
}

Init::~Init() {
    //소멸자
}


void Init::SetInitGlobal(LPDIRECT3DDEVICE9 device, LPDIRECT3DINDEXBUFFER9 ib) {
    //생성자
    g_pd3dDevice = device;
    g_pIB = ib;
}

void Init::SetPos() {

    if (GetKeyState(VK_LEFT) & 0x80) {
        nFXmove -= f_Speed;
    }
    if (GetKeyState(VK_RIGHT) & 0x80) {
        nFXmove += f_Speed;
    }
    if (GetKeyState(VK_UP) & 0x80) {
        nFZmove += f_Speed;
    }
    if (GetKeyState(VK_DOWN) & 0x80) {
        nFZmove -= f_Speed;
    }

    if (GetKeyState('Q') & 0x80) {
        nRx += n_RSpeed;
    }
    if (GetKeyState('A') & 0x80) {
        nRx -= n_RSpeed;
    }

    if (GetKeyState('W') & 0x80) {
        nRy += n_RSpeed;
    }
    if (GetKeyState('S') & 0x80) {
        nRy -= n_RSpeed;
    }

    if (GetKeyState('E') & 0x80) {
        nRz += n_RSpeed;
    }
    if (GetKeyState('D') & 0x80) {
        nRz -= n_RSpeed;
    }
};

void Init::SetObj() {

    D3DXMatrixIdentity(&tempTM1);
    g_pd3dDevice->SetTransform(D3DTS_VIEW, &tempTM1);

    D3DXMATRIX tempProjection;
    D3DXMatrixPerspectiveFovLH(&tempProjection, 1.3f, 1 / 1, 2.0f, 1000.0f);
    g_pd3dDevice->SetTransform(D3DTS_PROJECTION, &tempProjection);


    D3DXMatrixTranslation(&tempTM1, nFXmove, 0.0f, nFZmove);	// 1. 메트릭스 이동

    D3DXMatrixRotationYawPitchRoll(&tempTM2, nRx, nRy, nRz);	            // 2. 메트릭스 회전
    D3DXMatrixMultiply(&tempTM1, &tempTM1, &tempTM2);					    // 3. 이동 후 회전 순서로 곱산				

    nCx += tempTM1._41;
    nCy += tempTM1._42;
    nCz += tempTM1._43;
    nFXmove = 0;
    nFZmove = 0;

    D3DXMatrixRotationYawPitchRoll(&tempTM1, nRx, nRy, nRz);	            // 5. 다시 메트릭스 회전
    D3DXMatrixTranslation(&tempTM2, nCx, nCy, nCz);	                        // 6. 전역 좌표 변수의 값으로 이동
    D3DXMatrixMultiply(&tempTM1, &tempTM1, &tempTM2);					    // 7. 회전 후 이동 순서로 곱산

    D3DXMatrixTranslation(&tempTM2, 0, 0, 5.5f);					        // 8. 카메라의 정면 위치로 이동

    D3DXMatrixMultiply(&tempTM1, &tempTM1, &tempTM2);					    // 9. 이동값 곱산



    g_pd3dDevice->SetTransform(D3DTS_WORLD, &tempTM1);
}