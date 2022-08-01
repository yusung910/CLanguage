#include <windows.h>
#include "__debug.h"
#include "DrawRect.h"
#include "InitDisplay.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//// WinMain 함수 : 윈도즈 프로그램의 최초 진입점 ( Entry Point )
int WINAPI WinMain(HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPTSTR	  lpCmdLine,
    int		  nCmdShow)
{
    char	  szAppName[] = "예제";
    HWND	  hWnd;
    MSG      msg;
    WNDCLASS wndclass;

    wndclass.style = CS_HREDRAW | CS_VREDRAW;
    wndclass.lpfnWndProc = WndProc;
    wndclass.cbClsExtra = 0;
    wndclass.cbWndExtra = 0;
    wndclass.hInstance = hInstance;
    wndclass.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wndclass.lpszMenuName = NULL;
    wndclass.lpszClassName = szAppName;

    //// 윈도 클래스 등록
    RegisterClass(&wndclass);

    //// 윈도 생성
    hWnd = CreateWindow(szAppName,
        szAppName,
        WS_OVERLAPPEDWINDOW,
        100, 100, 1024, 800,
        NULL, NULL, hInstance, NULL);

    if (!hWnd) return FALSE;

    //// 생성된 윈도를 화면에 표시
    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    //// 메시지 루프
    while (GetMessage(&msg, NULL, 0, 0))
    {
		TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message,
    WPARAM wParam, LPARAM lParam)
{
    HDC			hdc;
	PAINTSTRUCT ps;
	static char string[256];
	static int	nLen = 0;

	static BOOL bDrawing = FALSE;
	static int  x1, y1, x2, y2, clientX, clientY;

    switch (message)
    {
	case WM_CREATE:
		//그림판 화면 초기화
		clientX = LOWORD(lParam);
		clientY = HIWORD(lParam);
		InitDisplay(hWnd, clientX, clientY);
		break;

	case WM_SIZE:
		break;

	case WM_LBUTTONDOWN:
		x1 = x2 = LOWORD(lParam);
		y1 = y2 = HIWORD(lParam);
		SetCursor(LoadCursor(NULL, IDC_CROSS));
		bDrawing = TRUE;
		break;

	case WM_MOUSEMOVE:
		if (bDrawing)
		{
			SetCursor(LoadCursor(NULL, IDC_CROSS));
			//// 이전에 그린 선을 지운다(반전색으로 그린다)
			//   단, 최초에는 좌표가 동일하므로 그리지 않는다
			DrawRect(hWnd, x1, y1, x2, y2, FALSE);
			x2 = LOWORD(lParam);
			y2 = HIWORD(lParam);
			//// 새로운 좌표에 선을 그린다
			DrawRect(hWnd, x1, y1, x2, y2, FALSE);
		}
		break;

	case WM_LBUTTONUP:
		//if (bDrawing)	// ???
	{
		//// 이전에 그린 선을 지운다
		DrawRect(hWnd, x1, y1, x2, y2, FALSE);
		bDrawing = FALSE;

		//// 사각영역을 채운다
		DrawRect(hWnd, x1, y1, x2, y2, TRUE);
	}
	break;

	case WM_KEYDOWN:
		//// ( winuser.h )
		//// wParam : virtual-key code
		//// lParam : key data
		TRACE2("WM_KEYDOWN %d %c\n", wParam, wParam);
		break;

	case WM_CHAR:
		TRACE2("WM_CHAR %d %c\n", wParam, wParam);
		string[nLen++] = (char)wParam;
		InvalidateRect(hWnd, NULL, FALSE);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}


