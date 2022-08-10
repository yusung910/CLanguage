#include <windows.h>
#include "Monster.h"
#include "Image.h"
#include "Init.h"
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
VOID CALLBACK MainLoopProc(HWND, UINT, UINT, DWORD);

HINSTANCE g_hInst;
HWND hWndMain;

Init init;
SURFACEINFO g_sfBack = init.GetSfBack();
SURFACEINFO g_sfBG = init.GetSfBg();
Monster g_objCar[2];

POINTS g_ptMouse;				// 마우스 좌표 

int g_nFrame = 0;					// 화면 갱신 카운트
int g_nMonIdx = 0;				// 

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
        CW_USEDEFAULT, CW_USEDEFAULT, 640, 480,
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
		g_objCar[0].nAni = 0;
		g_objCar[1].nAni = 1;

        ////
        ::Sleep(100);

        //// 타이머 생성		
        // 60 FPS ( 1000ms / 60fps = 16.6ms )
        // 정밀도 NT : 10ms ( 100 fps )
        //        98 : 55ms (  18 fps )
        SetTimer(hWnd, ID_TM_MAINLOOP, 16, MainLoopProc);
        SetTimer(hWnd, ID_TM_ANIMATION, 160, NULL);

        return 0;

    case WM_SETFOCUS:
        ::OutputDebugString("WM_SETFOCUS");
        return 0;

    case WM_MOUSEMOVE: g_ptMouse = MAKEPOINTS(lParam);
        return 0;


    case WM_TIMER:
        if (wParam == ID_TM_ANIMATION)
        {
            //// 애니메이션 인덱스
            g_objCar[0].nAni++;
            g_objCar[1].nAni++;
            if (g_objCar[0].nAni >= 7) g_objCar[0].nAni = 0;
            if (g_objCar[1].nAni >= 7) g_objCar[1].nAni = 0;
        }
        return 0;

    case WM_DESTROY:
        KillTimer(hWnd, ID_TM_MAINLOOP);
        KillTimer(hWnd, ID_TM_ANIMATION);
        __DestroyAll();
        PostQuitMessage(0);
        return 0;
    }

    return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}

static int nBgY = 1;
void CALLBACK MainLoopProc(HWND hWnd, UINT message, UINT iTimerID, DWORD dwTime)
{
	char  strBuff[24];
	HDC   dcScreen;
	BOOL  bRval;
	Image img;


	//// 연산부
	nBgY -= 2;
	if (nBgY < -480) nBgY = 0;

	//// 출력부
	dcScreen = GetDC(hWnd);
	{
		//// 배경
		img.PutImage(g_sfBack.GetDcSurface(), 0, nBgY, &g_sfBG);
		img.PutImage(g_sfBack.GetDcSurface(), 0, nBgY + 480, &g_sfBG);

		//__PutImageBlend(g_sfBack.dcSurface, 0, 0, &g_sfBG, 128);

		//// 오브젝트 및 기타 인터페이스창
		bRval = img.PutSprite(g_sfBack.GetDcSurface(), 100, 100, &(g_objCar[0].g_sfCar[g_objCar[0].nAni]));
		if (!bRval)	::OutputDebugString("__PutSprite - fail");

		bRval = img.PutSprite(g_sfBack.GetDcSurface(), g_ptMouse.x, g_ptMouse.y, &(g_objCar[1].g_sfCar[g_objCar[1].nAni]));
		if (!bRval) ::OutputDebugString("__PutSprite - fail");

		////				
		::wsprintf(strBuff, "Frame %d", ++g_nFrame);
		::TextOut(g_sfBack.GetDcSurface(), 10, 10, strBuff, strlen(strBuff));

		//// 출력 완료
		img.CompleteBlt(dcScreen, g_sfBack, &g_sfBack);
	}
	ReleaseDC(hWnd, dcScreen);
}