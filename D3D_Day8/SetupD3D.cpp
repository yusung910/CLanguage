#include "SetupD3D.h"

//생성자
SetupD3D::SetupD3D() {
    
}

//소멸자
SetupD3D::~SetupD3D() {
}


/*
 *------------------------------------------------------------------------------
 * Direct3D 초기화 : 자세히 살펴봐야 할 가장 중요한 함수.
 *------------------------------------------------------------------------------
 */
HRESULT SetupD3D::InitD3D(HWND hWnd)
{
    // 디바이스를 생성하기위한 D3D객체 생성
    if (NULL == (g_pD3D = Direct3DCreate9(D3D_SDK_VERSION)))
        return E_FAIL;
    D3DPRESENT_PARAMETERS d3dpp;
    ZeroMemory(&d3dpp, sizeof(d3dpp));
    d3dpp.Windowed = TRUE;
    d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
    d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
    d3dpp.EnableAutoDepthStencil = TRUE;
    d3dpp.AutoDepthStencilFormat = D3DFMT_D16;


    /* 디바이스를 다음과 같은 설정으로 생성한다.
         1. 디폴트 비디오카드를 사용(대부분은 비디오카드가 1개 이다.)
         2. HAL디바이스를 생성한다.(HW가속장치를 사용하겠다는 의미)
         3. 정점처리는 모든 카드에서 지원하는 SW처리로 생성한다.(HW로 생성할경우 더욱 높은 성능을 낸다.) */

         // 실제 디바이스를 생성하는 함수. (중요하다.)
    if (FAILED(g_pD3D->CreateDevice(D3DADAPTER_DEFAULT,
        D3DDEVTYPE_HAL,
        hWnd,
        D3DCREATE_SOFTWARE_VERTEXPROCESSING,
        &d3dpp,
        &g_pd3dDevice)))
    {
        return E_FAIL;
    }


    // 디바이스 상태정보를 처리할경우 여기에서 한다.
    g_pd3dDevice->SetRenderState(D3DRS_LIGHTING, FALSE);

    return S_OK;
}
//Index Buffer 초기화
HRESULT SetupD3D::InitIB() {

    MYINDEX iNumberOfIndex[] = {
        { 0, 1, 2 },{ 2, 1, 3 },
        { 1, 5, 3 },{ 3, 5, 7 },
        { 5, 4, 7 },{ 7, 4, 6 },
        { 4, 0, 6 },{ 6, 0, 2 },
        { 4, 5, 0 },{ 0, 5, 1 },
        { 2, 3, 6 },{ 6, 3, 7 },
    };
    g_pd3dDevice->CreateIndexBuffer(
        sizeof(iNumberOfIndex),
        0,
        D3DFMT_INDEX16,
        D3DPOOL_DEFAULT,
        &g_pIB,
        NULL);

    VOID *pIndices;

    if (g_pIB->Lock(0, sizeof(iNumberOfIndex), (void**)&pIndices, 0))
    {
        return E_FAIL;
    }

    //BUFFER(pVertices)에 값들을 저장한다.
    memcpy(pIndices, iNumberOfIndex, sizeof(iNumberOfIndex));

    g_pIB->Unlock();
}


//Texture 초기화
HRESULT SetupD3D::InitTexture() {
    if (FAILED(D3DXCreateTextureFromFile(g_pd3dDevice, "plane.bmp", &g_ppTexture))) {
        return E_FAIL;
    }
}

/*
 *------------------------------------------------------------------------------
 * 초기화된 객체들을 소거한다.
 *------------------------------------------------------------------------------
 */
VOID SetupD3D::CleanUp()
{
    // 해제 순서. 해제시 반드시 생성 순서의 역순으로 해제 해줄 것. 
    if (g_ppTexture != NULL)
        g_ppTexture->Release();
    if (g_pIB != NULL)
        g_pIB->Release();
    if (g_pd3dDevice != NULL)
        g_pd3dDevice->Release();
    if (g_pVB != NULL)
        g_pVB->Release();
    if (g_pD3D != NULL)
        g_pD3D->Release();


}

VOID SetupD3D::MainRender()
{
    g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(123, 123, 123), 1.0f, 0);
    if (SUCCEEDED(g_pd3dDevice->BeginScene()))
    {

        D3DXMATRIX tempTM, tempTM2, floorTM;

        D3DXMatrixIdentity(&tempTM);

        D3DXMATRIX tempViewTM;
        D3DXVECTOR3 v3Eye(10.0f, 10.0f, 10.0f);
        D3DXVECTOR3 v3LookAt(g_fRY, g_fRX, g_fRZ);
        D3DXVECTOR3 v3Up(0.0f, 1.0f, 0.0f);
        D3DXMatrixLookAtLH(&tempViewTM, &v3Eye, &v3LookAt, &v3Up);
        g_pd3dDevice->SetTransform(D3DTS_VIEW, &tempViewTM);


        D3DXMATRIX tempProjection;
        D3DXMatrixPerspectiveFovLH(&tempProjection, 1.3f, 1 / 1, 2.f, 10000.0f);
        g_pd3dDevice->SetTransform(D3DTS_PROJECTION, &tempProjection);

        g_pd3dDevice->SetStreamSource(0, g_pVB, 0, sizeof(CUSTOMVERTEX));
        g_pd3dDevice->SetTexture(0, g_ppTexture);
        g_pd3dDevice->SetFVF(D3DFVF_CUSTOMVERTEX);
        {
            //메인 객체 생성
            D3DXMatrixTranslation(&tempTM, g_fXmove, g_fZmove, 0.0f);		// 1. 메트릭스 이동

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

            g_pd3dDevice->SetTransform(D3DTS_WORLD, &tempTM);
            g_pd3dDevice->SetIndices(g_pIB);
            g_pd3dDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 8, 0, 14);


            g_pd3dDevice->SetTexture(0, NULL);
            D3DXMatrixTranslation(&floorTM, -1.0f, 1.0f, 10.0f);
            D3DXMatrixScaling(&floorTM, 10.0f, -.1f, 10.1f);
            g_pd3dDevice->SetTransform(D3DTS_WORLD, &floorTM);
            g_pd3dDevice->SetIndices(g_pIB);
            g_pd3dDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 8, 0, 14);

            //바닥 그리기
            


        }


        g_pd3dDevice->EndScene();
    }

    g_pd3dDevice->Present(NULL, NULL, NULL, NULL);
}

VOID SetupD3D::KeyControl() {
    if (::GetKeyState(VK_LEFT) & 0x80) g_fXmove -= 0.1f;	//방향키 왼쪽 : -X로 이동
    if (::GetKeyState(VK_RIGHT) & 0x80) g_fXmove += 0.1f;	//방향키 오른쪽 : +X로 이동
    if (::GetKeyState(VK_UP) & 0x80) g_fZmove += 0.1f;		//방향키 위쪽 : +Z로 이동
    if (::GetKeyState(VK_DOWN) & 0x80) g_fZmove -= 0.1f;	//방향키 아래쪽 : -Z로 이동

    if (::GetKeyState('W') & 0x80) g_fRY -= 0.1f;	//숫자 패드 1 : Y축을 기준으로 -회전
    if (::GetKeyState('S') & 0x80) g_fRY += 0.1f;	//숫자 패드 3 : Y축을 기준으로 +회전
    if (::GetKeyState('Q') & 0x80) g_fRX -= 0.1f;	//숫자 패드 5 : X축을 기준으로 -회전
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