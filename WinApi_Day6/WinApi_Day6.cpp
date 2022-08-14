#include <windows.h>
#include "Monster.h"
#include "Image.h"
#include "Init.h"
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
VOID CALLBACK CharRunAni(HWND, UINT, UINT, DWORD);
VOID CALLBACK CharJumpAni(HWND, UINT, UINT, DWORD);
void CharAniProc(HWND);
HINSTANCE g_hInst;
HWND hWndMain;

Init init;

BOOL bChrMirror = FALSE;
BOOL bCharAni = FALSE;
BOOL bJumpAni = FALSE;

int g_nMonIdx = 0;				// 

int n_mapFloor = 600;
int n_maxJump = n_mapFloor - 100;

LPSTR lpszClass = "[ MemoryDC Buffering (Double Buffering) ]";

#define ID_TM_ANIMATION 1
#define ID_TM_JUMP_ANIMATION 2


int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance
    , LPSTR lpszCmdParam, int nCmdShow)
{
    HWND hWnd;
    MSG msg;
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
    while (TRUE) {
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            if (msg.message == WM_QUIT) break;
            DispatchMessage(&msg);
        }
        else
        {
            Sleep(10);
            CharAniProc(hWnd);
        }
    }
    return msg.wParam;
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
        SetTimer(hWnd, ID_TM_ANIMATION, 100, CharRunAni);
        SetTimer(hWnd, ID_TM_JUMP_ANIMATION, 10, CharJumpAni);
        //
        return 0;
    case WM_SETFOCUS:
        ::OutputDebugString("WM_SETFOCUS");
        return 0;

    case WM_MOUSEMOVE:
        return 0;


    case WM_DESTROY:
        KillTimer(hWnd, ID_TM_ANIMATION);
        KillTimer(hWnd, ID_TM_JUMP_ANIMATION);
        init.DestroyAll();
        PostQuitMessage(0);
        return 0;
    }

    return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}

void CALLBACK CharRunAni(HWND hWnd, UINT message, UINT iTimerID, DWORD dwTime) {
    if (bCharAni) {
        init.SetAniInt();
    }
    else {
        init.SetAniInt(0);
    }
}

int n_flag = -1;
int nCharY = 0;
void CALLBACK CharJumpAni(HWND hWnd, UINT message, UINT iTimerID, DWORD dwTime) {
    // n_mapFloor: 600
    // n_maxJump : 550
    nCharY = init.GetCharPosY();
    if(bJumpAni){
        nCharY = (n_flag * 10) + nCharY;
        if (nCharY == n_maxJump) {
            n_flag = 1;
        }

        if (nCharY == n_mapFloor) {
            n_flag = -1;
        }
    }
    else {
        nCharY = (nCharY < n_mapFloor) ? nCharY + 10 : nCharY;
        n_flag = -1;
    }

    init.SetCharPosY(nCharY);
    
}
void CharAniProc(HWND hWnd) {
	
    bCharAni = FALSE;
    bJumpAni = FALSE;
    if (GetKeyState(VK_LEFT) & 0x80)
    {
        bCharAni = TRUE;
		
		init.SetBgPos(5, 0);
    }
    if (GetKeyState(VK_RIGHT) & 0x80) {
        bCharAni = TRUE;
		init.SetBgPos(-5, 0);
    }
    if (GetKeyState(VK_SPACE) & 0x80) {
        bJumpAni = TRUE;
    }

	init.MoveBg(hWnd);
}