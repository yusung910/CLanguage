#include <d3dx9math.h>
#include "SetupD3D.h"
#include "Render.h"
/*------------------------------------------------------------------------------
 * 전역변수
 *------------------------------------------------------------------------------
 */
SetupD3D setupD3D;


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
        setupD3D.CleanUp();
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
    if (SUCCEEDED(setupD3D.InitD3D(hWnd)))
    {
        /// 버텍스 버퍼 초기화
        if (SUCCEEDED(setupD3D.InitVB()))
        {
            /// 인덱스 버퍼 초기화
            if (SUCCEEDED(setupD3D.InitIB()))
            {
                /// 텍스처 초기화
                if (SUCCEEDED(setupD3D.InitTexture()))
                {
                    /// 윈도우 출력
                    ShowWindow(hWnd, SW_SHOWDEFAULT);
                    UpdateWindow(hWnd);
                    /// 메시지 루프
                    MSG msg;
                    //render;
                    Render render;
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
                            render.KeyControl();	//키보드 입력 처리
                            render.MainRender();		//렌더 처리
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