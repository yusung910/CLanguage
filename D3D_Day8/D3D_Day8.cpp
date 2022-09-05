#include <d3dx9math.h>

/*------------------------------------------------------------------------------
 * 전역변수
 *------------------------------------------------------------------------------
 */
LPDIRECT3D9             g_pD3D = NULL;
LPDIRECT3DDEVICE9       g_pd3dDevice = NULL;
LPDIRECT3DVERTEXBUFFER9 g_pVB = NULL;
LPDIRECT3DINDEXBUFFER9  g_pIB = NULL;
LPDIRECT3DTEXTURE9		g_ppTexture = NULL;

FLOAT g_fXmove = 0.0f, g_fZmove = 0.0f;				//이동값 전역 변수
FLOAT g_fRX = 0.0f, g_fRY = 5.0f, g_fRZ = 0.0f;	//회전값 전역 변수
FLOAT g_fX = 0.0f, g_fY = 0.0f, g_fZ = 0.0f;	//좌표값 전역 변수

#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZ | D3DFVF_TEX1)

struct CUSTOMVERTEX
{
	FLOAT x, y, z;
	FLOAT tu, tv;
};
struct MYINDEX
{
    WORD _0, _1, _2;
};



/*------------------------------------------------------------------------------
 * Direct3D 초기화 : 자세히 살펴봐야 할 가장 중요한 함수.
 *------------------------------------------------------------------------------
 */
HRESULT InitD3D(HWND hWnd)
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

/*
*-------------------------------------------------------------------------------
* Vertex초기화
*-------------------------------------------------------------------------------
*/
HRESULT InitVB() {
    //VERTEX
    CUSTOMVERTEX vertices[] =
    {
        { -0.5F,  0.5F, -0.5F, 0.0F, 0.0F },                  // 0
        {  0.5F,  0.5F, -0.5F, 1.0F, 0.0F },                  // 1
        { -0.5F, -0.5F, -0.5F, 0.0F, 1.0F },                  // 2
        {  0.5F, -0.5F, -0.5F, 1.0F, 1.0F },                  // 3
        


        { -0.5F,  0.5F, 0.5F, 1.0F, 0.0F },                  // 4
        {  0.5F,  0.5F, 0.5F, 0.0F, 0.0F },                  // 5
        { -0.5F, -0.5F, 0.5F, 1.0F, 1.0F },                  // 6
        {  0.5F, -0.5F, 0.5F, 0.0F, 1.0F },                  // 7
        

    };

	//VERTEX BUFFER 생성
	if (g_pd3dDevice->CreateVertexBuffer(
		8 * sizeof(vertices),
		0,
        D3DFVF_CUSTOMVERTEX,
		D3DPOOL_DEFAULT,
		&g_pVB,
		NULL))
	{
		return E_FAIL;
	};


	VOID* pVertices;
	//생성된 VERTEX BUFFER를 LOCK()하여 내용을 넣는다.
	if (FAILED(g_pVB->Lock(0, sizeof(vertices), (void**)&pVertices, 0)))
	{
		return E_FAIL;
	}

	//BUFFER(pVertices)에 값들을 저장한다.
	memcpy(pVertices, vertices, sizeof(vertices));

	//메모리 잠금 해제
	g_pVB->Unlock();
}

//Index Buffer 초기화
HRESULT InitIB() {

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

//texture 초기화
HRESULT InitTexture() {
	if (FAILED(D3DXCreateTextureFromFile(g_pd3dDevice, "plane.bmp", &g_ppTexture))) {
		return E_FAIL;
	}

}

/*------------------------------------------------------------------------------
 * 초기화된 객체들을 소거한다.
 *------------------------------------------------------------------------------
 */
VOID Cleanup()
{
	// 해제 순서. 해제시 반드시 생성 순서의 역순으로 해제 해줄 것. 
    if (g_ppTexture != NULL)
        g_ppTexture->Release();
    if (g_pIB != NULL)
        g_pIB->Release();
    if (g_pVB != NULL)
        g_pVB->Release();
    if (g_pd3dDevice != NULL)
		g_pd3dDevice->Release();
	if (g_pD3D != NULL)
		g_pD3D->Release();
}

/**-----------------------------------------------------------------------------------
* 키보드 입력
*------------------------------------------------------------------------------------
*/

void KeyControl()
{
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
VOID Render()
{
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
        g_pd3dDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 8, 0, 12);

        g_pd3dDevice->EndScene();
	}

	g_pd3dDevice->Present(NULL, NULL, NULL, NULL);
}


/*
 *------------------------------------------------------------------------------
 * 윈도우 프로시져
 *------------------------------------------------------------------------------
 */
LRESULT WINAPI MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		Cleanup();
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}


/*------------------------------------------------------------------------------
 * 이 프로그램의 시작점
 *------------------------------------------------------------------------------
 */
INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, INT)
{
    /// 윈도우 클래스 등록
    WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_CLASSDC, MsgProc, 0L, 0L, GetModuleHandle(NULL), NULL, NULL, NULL, NULL,
        "D3D Tutorial", NULL };
    RegisterClassEx(&wc);
    /// 윈도우 생성
    HWND hWnd = CreateWindow("D3D Tutorial", "D3D Tutorial 07: IndexBuffer", WS_OVERLAPPEDWINDOW, 100, 100, 500, 500,
        GetDesktopWindow(), NULL, wc.hInstance, NULL);
    /// Direct3D 초기화
    if (SUCCEEDED(InitD3D(hWnd)))
    {
        /// 버텍스 버퍼 초기화
        if (SUCCEEDED(InitVB()))
        {
            /// 인덱스 버퍼 초기화
            if (SUCCEEDED(InitIB()))
            {
                /// 텍스처 초기화
                if (SUCCEEDED(InitTexture()))
                {
                    /// 윈도우 출력
                    ShowWindow(hWnd, SW_SHOWDEFAULT);
                    UpdateWindow(hWnd);
                    /// 메시지 루프
                    MSG msg;
                    ZeroMemory(&msg, sizeof(msg));
                    while (msg.message != WM_QUIT)
                    {
                        // 메시지 큐에 메시지가 있으면 메시지 처리
                        if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
                        {
                            TranslateMessage(&msg);
                            DispatchMessage(&msg);
                        }
                        else
                        {
                            KeyControl();	//키보드 입력 처리
                            Render();		//렌더 처리
                        }
                    }
                }
            }
        }
    }
    // 등록된 클래스 소거
    UnregisterClass("D3D Tutorial", wc.hInstance);
    return 0;
}