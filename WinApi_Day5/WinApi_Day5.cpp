#include <windows.h>

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
    HDC hdc;
    PAINTSTRUCT ps;
    HDC MemDC;
    HBITMAP MyBitmap, OldBitmap;
    int bx, by;
    BITMAP bit;
    BLENDFUNCTION bf;

    static int Alpha = 128;

    switch (iMessage)
    {
    case WM_PAINT:
        hdc = BeginPaint(hWnd, &ps);

        //// 메모리 DC생성
        //// 색상 포맷이 같은 DC끼리는 비트맵을 전송할 수 있다
        //// 리턴값 : HDC
        MemDC = CreateCompatibleDC(hdc);
        //// 리소스에서 비트맵 로드 ( DIB -> DDB )
        MyBitmap = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP1));

        //// 메모리DC에 비트맵선택
        //// 비트맵의 높이와 폭, 색상 포맷을 가지는 그리기 표면 생성
        OldBitmap = (HBITMAP)SelectObject(MemDC, MyBitmap);

        //// 오브젝트에 대한 정보를 조회
        GetObject(MyBitmap,		  // 오브젝트 핸들
            sizeof(BITMAP), // 스트럭쳐크기
            &bit);		  // 비트맵의 폭, 높이, 색상 정보 스트럭쳐 ( 핸들타입에 따라 다르다 )

        bx = bit.bmWidth;
        by = bit.bmHeight;


        //// 같은 포맷의 DC끼리 비트맵 전송
     //   BitBlt(hdc,       // 목적DC
     //       0, 0, bx, by, // 목적 좌표와 폭, 높이 ( 출력 )
     //       MemDC,	  // 소스DC
     //       0, 0,		  // 소스 좌표 ( copy ) , 목적 폭과 높이 참조
     //       SRCCOPY);  // 복사

     //////
     //   BitBlt(hdc,				// 목적DC
     //       0, by + 10, bx, by / 2,
     //       hdc,				// 소스DC
     //       0, by / 2,			// 소스 좌표,  목적 폭과 높이 참조
     //       SRCCOPY);
        // SRCINVERT);
        //

        //// BLENDFUNCTION 초기화
        bf.BlendOp = AC_SRC_OVER;	//
        bf.BlendFlags = 0;				//			
        bf.AlphaFormat = 0;				//
        bf.SourceConstantAlpha = Alpha; // 투명 0 - 255 불투명

        //// 알파 블렌드
        //AlphaBlend(hdc,			// 목적DC
        //    0, 0, bx, by,	// 목적좌표, 폭, 높이
        //    MemDC,		// 소스DC
        //    0, 0, bx, by,	// 
        //    bf);			// BLENDFUNCTION 스트럭쳐 ( alpha-blending )

            //// 스프라이트
        TransparentBlt(hdc,
            0, 0, bx, by,
            MemDC,
            0, 0, bx, by,
            RGB(0, 58, 166)); // color key

 //// 메모리DC에 대해 최초 비트맵 오브젝트로 선택
        SelectObject(MemDC, OldBitmap);

        //// 비트맵 해제
        DeleteObject(MyBitmap);

        //// 메모리 DC해제
        DeleteDC(MemDC);

        EndPaint(hWnd, &ps);
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