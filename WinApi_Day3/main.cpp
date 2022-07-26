
#include <windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void __Line(HDC hdc, int x1, int y1, int x2, int y2, COLORREF crPen);
void __Ellipse(HDC hdc, int x1, int y1, int x2, int y2, COLORREF crPen, COLORREF crBrush);
void __Rectangle(HDC hdc, int x1, int y1, int x2, int y2, COLORREF crPen, COLORREF crBrush);
void RandDraw();
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
		100, 100, 250, 250,
		NULL, NULL, hInstance, NULL);

	if (!hWnd) return FALSE;

	//// 생성된 윈도를 화면에 표시
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	//// 메시지 루프
	while (TRUE)
	{
        if (PeekMessage(&msg, NULL, 0, 0,
            PM_REMOVE)) // 메시지 큐에서 메시지 제거
        {
            if (msg.message == WM_QUIT) break;
            DispatchMessage(&msg);
        }
        else // 메시지가 없으면
        {
            //__Line(GetDC(hWnd), 20, 20, 100, 100, RGB(121,152,122));
            //Sleep(100);
        }
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


//라인을 그리는 함수
void __Line(HDC hdc, int x1, int y1, int x2, int y2, COLORREF crPen) {
    HPEN oldPen, newPen;
    newPen = CreatePen(PS_SOLID, 1, crPen);
    oldPen = (HPEN)SelectObject(hdc, newPen);

    MoveToEx(hdc, x1, y1, NULL);
    LineTo(hdc, x2, y2);
    SelectObject(hdc, oldPen);

    DeleteObject(newPen);
}

void __Ellipse(HDC hdc, int x1, int y1, int x2, int y2, COLORREF crPen, COLORREF crBrush) {
    HBRUSH newBrush, oldBrush;

    newBrush = CreateSolidBrush(crBrush);
    oldBrush = (HBRUSH)SelectObject(hdc, newBrush);
    Ellipse(hdc, x1, y1, x2, y2);

    SelectObject(hdc, oldBrush);
    DeleteObject(newBrush);
    //ReleaseDC(hWnd, hdc);
    //ValidateRect(hWnd, NULL);
}

void __Rectangle(HDC hdc, int x1, int y1, int x2, int y2, COLORREF crPen, COLORREF crBrush) {
    HBRUSH newBrush, oldBrush;

    newBrush = CreateSolidBrush(crBrush);
    oldBrush = (HBRUSH)SelectObject(hdc, newBrush);
    Rectangle(hdc, x1, y1, x2, y2);

    SelectObject(hdc, oldBrush);
    DeleteObject(newBrush);
}

void RandDraw() {
    //랜덤의 범위는 그려질 도형, 브러쉬, 펜, 폰트, 전경색, 배경색, 크기, 좌표

    
}