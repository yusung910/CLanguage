﻿#include <d3d9.h>
#include <d3dx9.h>
#include "Init.h"
/*------------------------------------------------------------------------------
 * 전역변수
 *------------------------------------------------------------------------------
 */
LPDIRECT3D9             g_pD3D = NULL;
LPDIRECT3DDEVICE9       g_pd3dDevice = NULL;
LPDIRECT3DVERTEXBUFFER9 g_pVB = NULL;
LPDIRECT3DINDEXBUFFER9  g_pIB = NULL;
Init g_init;
#define CUSTOM_D3DFVF (D3DFVF_XYZ | D3DFVF_DIFFUSE)

struct CUSTOMVERTEX
{
	FLOAT x, y, z;
	DWORD color;
};

//VERTEX
CUSTOMVERTEX g_vertices[] =
{
	{ -0.5F,  0.5F,  11.0F , 0xffff0000 },                  // 0
	{  0.5F,  0.5F,  11.0F , 0xff00ff00 },                  // 1
	{  0.5F, -0.5F,  11.0F , 0xffff00ff },                  // 5
	{ -0.5F, -0.5F,  11.0F , 0xff00ffff },                  // 4


	{ -0.5F,  0.5F, 12.0F , 0xffffff00 },                  // 3
	{  0.5F,  0.5F, 12.0F , 0xff0000ff },                  // 2
	{  0.5F, -0.5F, 12.0F , 0xff000000 },                  // 6
	{ -0.5F, -0.5F, 12.0F , 0xffffffff },                  // 7

};

WORD g_iNumberOfIndex[] = {
			0, 1, 2,
			0, 2, 3,
			4, 6, 5,
			4, 7, 6,
			0, 3, 7,
			0, 7, 4,
			1, 5, 6,
			1, 6, 2,
			3, 2, 6,
			3, 6, 7,
			0, 4, 5,
			0, 5, 1
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
	d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
	d3dpp.BackBufferWidth = 1024;
	d3dpp.BackBufferHeight = 768;
	d3dpp.BackBufferCount = 2;

	d3dpp.Flags = D3DPRESENTFLAG_VIDEO;


	d3dpp.EnableAutoDepthStencil = TRUE;
	d3dpp.AutoDepthStencilFormat = D3DFMT_D24S8;

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
	return S_OK;
}

/*
*-------------------------------------------------------------------------------
* Vertex초기화
*-------------------------------------------------------------------------------
*/
HRESULT InitVB() {


	//VERTEX BUFFER 생성
	if (g_pd3dDevice->CreateVertexBuffer(
		8 * sizeof(g_vertices),
		0,
		CUSTOM_D3DFVF,
		D3DPOOL_DEFAULT,
		&g_pVB,
		NULL))
	{
		return E_FAIL;
	};


	VOID* pVertices;
	//생성된 VERTEX BUFFER를 LOCK()하여 내용을 넣는다.
	if (FAILED(g_pVB->Lock(0, sizeof(g_vertices), (void**)&pVertices, 0)))
	{
		return E_FAIL;
	}

	//BUFFER(pVertices)에 값들을 저장한다.
	memcpy(pVertices, g_vertices, sizeof(g_vertices));

	//메모리 잠금 해제
	g_pVB->Unlock();
}

//Index Buffer 초기화
HRESULT InitIB() {

	g_pd3dDevice->CreateIndexBuffer(
		sizeof(g_iNumberOfIndex),
		0,
		D3DFMT_INDEX16,
		D3DPOOL_DEFAULT,
		&g_pIB,
		NULL);

	VOID *pIndices;

	if (g_pIB->Lock(0, sizeof(g_iNumberOfIndex), (void**)&pIndices, 0))
	{
		return E_FAIL;
	}

	//BUFFER(pVertices)에 값들을 저장한다.
	memcpy(pIndices, g_iNumberOfIndex, sizeof(g_iNumberOfIndex));

	g_pIB->Unlock();

}

/*------------------------------------------------------------------------------
 * 초기화된 객체들을 소거한다.
 *------------------------------------------------------------------------------
 */
VOID Cleanup()
{
	// 해제 순서. 해제시 반드시 생성 순서의 역순으로 해제 해줄 것. 
	if (g_pd3dDevice != NULL)
		g_pd3dDevice->Release();
	if (g_pD3D != NULL)
		g_pD3D->Release();
	if (g_pVB != NULL)
		g_pVB->Release();
	if (g_pIB != NULL)
		g_pIB->Release();
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
	if (NULL == g_pd3dDevice)
		return;

	g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(123, 212, 223), 1.0f, 0);

	if (SUCCEEDED(g_pd3dDevice->BeginScene()))
	{
		// 실제 렌더링 명령들이 나열될 곳

		//----------------------------------------------------------------------------
		//render
		//----------------------------------------------------------------------------
		g_pd3dDevice->SetRenderState(D3DRS_LIGHTING, FALSE);
		g_pd3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
		g_pd3dDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
		g_pd3dDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
		//----------------------------------------------------------------------------


		//----------------------------------------------------------------------------
		//transform projection
		//----------------------------------------------------------------------------
		D3DXMATRIX tempProjection;
		D3DXMatrixPerspectiveFovLH(&tempProjection, D3DX_PI / 4, 1.3f, 10.0f, 10000.0f);
		g_pd3dDevice->SetTransform(D3DTS_PROJECTION, &tempProjection);
		g_pd3dDevice->SetStreamSource(0, g_pVB, 0, sizeof(CUSTOMVERTEX));
		g_pd3dDevice->SetFVF(CUSTOM_D3DFVF);
		//----------------------------------------------------------------------------

        //----------------------------------------------------------------------------
        //transform world
        //----------------------------------------------------------------------------
        g_init.SetObjectInit();
        //----------------------------------------------------------------------------
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
	case WM_PAINT:

        g_init.SetInitGlobal(g_pd3dDevice, g_pIB);
        Render();

        ValidateRect(hWnd, NULL);
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
	// 윈도우 클래스 등록
	WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_CLASSDC, MsgProc, 0L, 0L,
					  GetModuleHandle(NULL), NULL, NULL, NULL, NULL,
					  "D3D Day7", NULL };
	RegisterClassEx(&wc);
	// 윈도우 생성
	HWND hWnd = CreateWindow("D3D Day7", "D3D Day7: World Transform",
		WS_OVERLAPPEDWINDOW, 100, 100, 1024, 786,
		GetDesktopWindow(), NULL, wc.hInstance, NULL);
	// Direct3D 초기화
	if (SUCCEEDED(InitD3D(hWnd)))
	{
		if (SUCCEEDED(InitVB()))
		{
			if (SUCCEEDED(InitIB())) {
				// 윈도우 출력
				ShowWindow(hWnd, SW_SHOWDEFAULT);
				UpdateWindow(hWnd);
				// 메시지 루프
				MSG msg;
                while (TRUE) {
                    if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
                    {
                        if (msg.message == WM_QUIT) break;
                        DispatchMessage(&msg);
                    }
                    else
                    {
                        Sleep(10);
                        g_init.SetPos();
                        Render();
                    }
                }
			}
		}
	}
	// 등록된 클래스 소거
	UnregisterClass("D3D Day7", wc.hInstance);
	return 0;
}