#include <windows.h>
#include "Image.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
HWND hWndMain;
LPSTR lpszClass = "WinApi_Day51";

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance
    , LPSTR lpszCmdParam, int nCmdShow)
{
    HWND hWnd;
    MSG Message;
    WNDCLASS WndClass;
    g_hInst = hInstance;

    WndClass.cbClsExtra = 0;
    WndClass.cbWndExtra = 0;
    WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    WndClass.hInstance = hInstance;
    WndClass.lpfnWndProc = (WNDPROC)WndProc;
    WndClass.lpszClassName = lpszClass;
    WndClass.lpszMenuName = NULL;
    WndClass.style = CS_HREDRAW | CS_VREDRAW;
    RegisterClass(&WndClass);

    hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
        NULL, (HMENU)NULL, hInstance, NULL);
    ShowWindow(hWnd, nCmdShow);
    hWndMain = hWnd;

    while (GetMessage(&Message, 0, 0, 0)) {
        TranslateMessage(&Message);
        DispatchMessage(&Message);
    }
    return Message.wParam;
}

#include "resource.h"
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{


	Image img;

    static int Alpha = 128;

    switch (iMessage)
    {
    case WM_PAINT:
		img = Image(hWnd, g_hInst);
		//img.PutImageBlend(Alpha);
		img.PutSprite(RGB(147, 187, 236));
            //// 스프라이트

 //// 메모리DC에 대해 최초 비트맵 오브젝트로 선택
		img.DeleteImage();

        
        return 0;

    case WM_LBUTTONDOWN:
        Alpha -= 20;
        if (Alpha < 0) Alpha = 0;

		

        InvalidateRect(hWnd, NULL, TRUE);
        return TRUE;
    case WM_RBUTTONDOWN:
        Alpha += 20;
        if (Alpha > 255) Alpha = 255;

        InvalidateRect(hWnd, NULL, TRUE);
        return TRUE;

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}