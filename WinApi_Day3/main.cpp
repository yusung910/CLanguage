
#include <windows.h>

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
		100, 100, 250, 250,
		NULL, NULL, hInstance, NULL);

	if (!hWnd) return FALSE;

	//// ������ ������ ȭ�鿡 ǥ��
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	//// �޽��� ����
	while (GetMessage(&msg, NULL, 0, 0))
	{
		DispatchMessage(&msg);
	}
	return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message,
	WPARAM wParam, LPARAM lParam)
{
	int			  i;
	HDC			  hdc;
	PAINTSTRUCT   ps;

	switch (message)
	{
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		for (i = 0; i < 10000; i++)
		{
			SetPixel(hdc,
				rand() % 300, rand() % 300,
				RGB(rand() % 256,
					rand() % 256,
					rand() % 256));
		}
		EndPaint(hWnd, &ps);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}