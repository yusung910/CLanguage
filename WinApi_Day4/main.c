#include <windows.h>
#include "__debug.h"
#include "DrawRect.h"
#include "InitDisplay.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//// WinMain �Լ� : ������ ���α׷��� ���� ������ ( Entry Point )
int WINAPI WinMain(HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPTSTR	  lpCmdLine,
    int		  nCmdShow)
{
    char	  szAppName[] = "����";
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

    //// ���� Ŭ���� ���
    RegisterClass(&wndclass);

    //// ���� ����
    hWnd = CreateWindow(szAppName,
        szAppName,
        WS_OVERLAPPEDWINDOW,
        100, 100, 1024, 800,
        NULL, NULL, hInstance, NULL);

    if (!hWnd) return FALSE;

    //// ������ ������ ȭ�鿡 ǥ��
    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    //// �޽��� ����
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
		//�׸��� ȭ�� �ʱ�ȭ
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
			//// ������ �׸� ���� �����(���������� �׸���)
			//   ��, ���ʿ��� ��ǥ�� �����ϹǷ� �׸��� �ʴ´�
			DrawRect(hWnd, x1, y1, x2, y2, FALSE);
			x2 = LOWORD(lParam);
			y2 = HIWORD(lParam);
			//// ���ο� ��ǥ�� ���� �׸���
			DrawRect(hWnd, x1, y1, x2, y2, FALSE);
		}
		break;

	case WM_LBUTTONUP:
		//if (bDrawing)	// ???
	{
		//// ������ �׸� ���� �����
		DrawRect(hWnd, x1, y1, x2, y2, FALSE);
		bDrawing = FALSE;

		//// �簢������ ä���
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


