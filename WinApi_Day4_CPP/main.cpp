
#include <windows.h>
#include "InitMenu.h"
#include "Draw.h"
#include "__debug.h"

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
        100, 100, 1420, 1000,
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

    InitMenu im;
	Draw draw;

	static char string[256];
	static int	nLen = 0;
	static BOOL bCursorFlag = false;

	switch (message)
	{
    case WM_MOUSEMOVE:
		bCursorFlag = im.GetMouseToolFlag(lParam);
		if (bCursorFlag) {
			SetCursor(LoadCursor(NULL, IDC_HAND));
		}
        break;

    case WM_LBUTTONDOWN:
		if (bCursorFlag) {
			//Ŀ�� ��� ����
			SetCursor(LoadCursor(NULL, IDC_HAND));
		}
        im.GetMouseToolFlag(lParam);

        //TRACE2("X: %d, Y: %d", (short)LOWORD(lParam), (short)HIWORD(lParam));
        break;
    case WM_LBUTTONUP:
		if (bCursorFlag) {
			//Ŀ�� ��� ����
			SetCursor(LoadCursor(NULL, IDC_HAND));
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

	case WM_PAINT:
        im.SetClientSize(hWnd);

        im.DrawTool(hWnd);

		//hdc = BeginPaint(hWnd, &ps);
		//TextOut(hdc, 10, 10, string, nLen);
		//EndPaint(hWnd, &ps);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}