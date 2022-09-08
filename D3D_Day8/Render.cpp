#include "Render.h"

Render::Render() {

}
Render::~Render() {

}
/*
 *------------------------------------------------------------------------------
 * 화면을 그린다.
 * Render() 함수 알고리즘
 * 1. 먼저 화면을 깨끗이 지운다. ( Clear() )
 * 2. 폴리곤을 그리겠다고 D3D에게 알림.( BeginScene() )
 * 3. 폴리곤을 다 그렸다고 D3D에게 알림.( EndScene() )
 * 4. 화면에 나타나게 한다. ( Present() )
 *------------------------------------------------------------------------------
 */
VOID Render::MainRender() {
    g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(123, 123, 123), 1.0f, 0);
    if (SUCCEEDED(g_pd3dDevice->BeginScene()))
    {
        D3DXMATRIX tempTM, tempTM2;

        D3DXMatrixIdentity(&tempTM);
        g_pd3dDevice->SetTransform(D3DTS_VIEW, &tempTM);

        D3DXMATRIX tempProjection;
        D3DXMatrixPerspectiveFovLH(&tempProjection, 1.3f, 1 / 1, 2.f, 10000.0f);
        g_pd3dDevice->SetTransform(D3DTS_PROJECTION, &tempProjection);


        {
            D3DXMatrixTranslation(&tempTM, g_fXmove, 0.0f, g_fZmove);		// 1. 메트릭스 이동

            D3DXMatrixRotationYawPitchRoll(&tempTM2, g_fRY, g_fRX, g_fRZ);	// 2. 메트릭스 회전
            D3DXMatrixMultiply(&tempTM, &tempTM, &tempTM2);					// 3. 이동 후 회전 순서로 곱산				

            g_fX += tempTM._41;
            g_fY += tempTM._42;
            g_fZ += tempTM._43;
            g_fXmove = 0;
            g_fZmove = 0;													// 4. 이동후의 좌표를 전역 좌표 변수 더한후 이동값 초기화

            D3DXMatrixRotationYawPitchRoll(&tempTM, g_fRY, g_fRX, g_fRZ);	// 5. 다시 메트릭스 회전
            D3DXMatrixTranslation(&tempTM2, g_fX, g_fY, g_fZ);				// 6. 전역 좌표 변수의 값으로 이동
            D3DXMatrixMultiply(&tempTM, &tempTM, &tempTM2);					// 7. 회전 후 이동 순서로 곱산

            D3DXMatrixTranslation(&tempTM2, 0, 0, 5.5f);					// 8. 카메라의 정면 위치로 이동
            D3DXMatrixMultiply(&tempTM, &tempTM, &tempTM2);					// 9. 이동값 곱산
        }

        g_pd3dDevice->SetStreamSource(0, g_pVB, 0, sizeof(CUSTOMVERTEX));
        g_pd3dDevice->SetTexture(0, g_ppTexture);
        g_pd3dDevice->SetFVF(D3DFVF_CUSTOMVERTEX);

        g_pd3dDevice->SetTransform(D3DTS_WORLD, &tempTM);
        g_pd3dDevice->SetIndices(g_pIB);
        g_pd3dDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 12, 0, 14);

        g_pd3dDevice->EndScene();
    }

    g_pd3dDevice->Present(NULL, NULL, NULL, NULL);
}

VOID Render::KeyControl() {
    if (::GetKeyState(VK_LEFT) & 0x80) g_fXmove -= 0.1f;	//방향키 왼쪽 : -X로 이동
    if (::GetKeyState(VK_RIGHT) & 0x80) g_fXmove += 0.1f;	//방향키 오른쪽 : +X로 이동
    if (::GetKeyState(VK_UP) & 0x80) g_fZmove += 0.1f;		//방향키 위쪽 : +Z로 이동
    if (::GetKeyState(VK_DOWN) & 0x80) g_fZmove -= 0.1f;	//방향키 아래쪽 : -Z로 이동

    if (::GetKeyState('W') & 0x80) g_fRY -= 0.1f;	//숫자 패드 1 : Y축을 기준으로 -회전
    if (::GetKeyState('S') & 0x80) g_fRY += 0.1f;	//숫자 패드 3 : Y축을 기준으로 +회전
    if (::GetKeyState('Q') & 0x80)
        g_fRX -= 0.1f;	//숫자 패드 5 : X축을 기준으로 -회전
    if (::GetKeyState('A') & 0x80) g_fRX += 0.1f;	//숫자 패드 2 : X축을 기준으로 +회전
    if (::GetKeyState('E') & 0x80) g_fRZ += 0.1f;	//숫자 패드 4 : Z축을 기준으로 +회전
    if (::GetKeyState('D') & 0x80) g_fRZ -= 0.1f;	//숫자 패드 6 : Z축을 기준으로 -회전

    if (::GetKeyState(VK_SPACE) & 0x80)						//스페이드 입력시 위치 초기화
    {
        g_fXmove = 0.0f;
        g_fZmove = 0.0f;

        g_fRX = 0.0f;
        g_fRY = 0.0f;
        g_fRZ = 0.0f;

        g_fX = 0.0f;
        g_fY = 0.0f;
        g_fZ = 0.0f;
    }
}