// WinApi_Day6.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <windows.h>

HINSTANCE g_hInst;
HWND hWndMain;
LPSTR lpszClass = "[ MemoryDC Buffering (Double Buffering) ]";

LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);

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
        __Init(dcScreen);
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
