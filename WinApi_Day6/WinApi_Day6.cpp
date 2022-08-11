#include <windows.h>
#include "Monster.h"
#include "Image.h"
#include "Init.h"
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
VOID CALLBACK MainLoopProc(HWND, UINT, UINT, DWORD);

HINSTANCE g_hInst;
HWND hWndMain;

Init init;
BOOL bChrMirror = FALSE;

int g_nMonIdx = 0;				// 
int x = 10;
int y = 600;
LPSTR lpszClass = "[ MemoryDC Buffering (Double Buffering) ]";

#define ID_TM_MAINLOOP	1
#define ID_TM_ANIMATION 2


int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance
    , LPSTR lpszCmdParam, int nCmdShow)
{
    HWND hWnd;
    MSG Message;
    WNDCLASS WndClass;
    g_hInst = hInstance;

    WndClass.cbClsExtra = 0;
    WndClass.cbWndExtra = 0;
    WndClass.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH);
    WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    WndClass.hInstance = hInstance;
    WndClass.lpfnWndProc = (WNDPROC)WndProc;
    WndClass.lpszClassName = lpszClass;
    WndClass.lpszMenuName = NULL;
    WndClass.style = CS_HREDRAW | CS_VREDRAW;

    RegisterClass(&WndClass);

    hWnd = CreateWindow(lpszClass, lpszClass, WS_SYSMENU | WS_CAPTION, //WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 1360, 862,
        NULL, (HMENU)NULL, hInstance, NULL);
    ShowWindow(hWnd, nCmdShow);
    hWndMain = hWnd;

    while (GetMessage(&Message, 0, 0, 0)) {
        TranslateMessage(&Message);
        DispatchMessage(&Message);
    }
    return Message.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
    HDC dcScreen;
	
    switch (iMessage)
    {
    case WM_CREATE:
        //// 표면 생성 및 기타
        dcScreen = GetDC(hWnd);
		init.Begin(dcScreen);
        ReleaseDC(hWnd, dcScreen);

        ////
        ::Sleep(100);

        //// 타이머 생성		
        // 60 FPS ( 1000ms / 60fps = 16.6ms )
        // 정밀도 NT : 10ms ( 100 fps )
        //        98 : 55ms (  18 fps )
        SetTimer(hWnd, ID_TM_MAINLOOP, 16, MainLoopProc);
        SetTimer(hWnd, ID_TM_ANIMATION, 160, NULL);

        return 0;

	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_LEFT:
		case VK_NUMPAD4:
			bChrMirror = TRUE;
			x -= 2;
			init.SetAniInt();
			break;
		case VK_RIGHT:
		case VK_NUMPAD6:
			bChrMirror = FALSE;
			x += 2;
			init.SetAniInt();
			break;
		}
		
    case WM_SETFOCUS:
        ::OutputDebugString("WM_SETFOCUS");
        return 0;

    case WM_MOUSEMOVE:
        return 0;


    case WM_TIMER:
        if (wParam == ID_TM_ANIMATION)
        {
            //init.SetAniInt();
        }
        return 0;

    case WM_DESTROY:
        KillTimer(hWnd, ID_TM_MAINLOOP);
        KillTimer(hWnd, ID_TM_ANIMATION);
        init.DestroyAll();
        PostQuitMessage(0);
        return 0;
    }

    return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}

static int nBgX = 1;
void CALLBACK MainLoopProc(HWND hWnd, UINT message, UINT iTimerID, DWORD dwTime)
{
	HDC dcScreen;
	//// 출력부
	dcScreen = GetDC(hWnd);

	//// 연산부
	nBgX -= 2;
	if (nBgX < -1380) nBgX = 0;

	init.SetBackground(dcScreen, nBgX, x, y);
	init.MoveChar(dcScreen, x, y, bChrMirror);

	init.ImgOutComplete(hWnd, dcScreen);
}