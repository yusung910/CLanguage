
#include <windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void __Line(HDC hdc, int x1, int y1, int x2, int y2, COLORREF crPen);
void __Ellipse(HDC hdc, int x1, int y1, int x2, int y2, COLORREF crPen, COLORREF crBrush);
void __Rectangle(HDC hdc, int x1, int y1, int x2, int y2, COLORREF crPen, COLORREF crBrush);
//주어지는 화면 크기 내에서 랜덤으로 도형 생성
void RandRect(HDC hdc, int nClientWitdh, int nClientHeight);
void RandDraw(HDC hdc, int nClientWitdh, int nClientHeight);

void CopyPixelQuater(HDC hdc);

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
		100, 100, 800, 800,
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
            RandDraw(GetDC(hWnd), 800, 800);
            //__Line(GetDC(hWnd), 20, 20, 100, 100, RGB(121,152,122));
            Sleep(100);
        }
	}
	return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message,
	WPARAM wParam, LPARAM lParam)
{
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
void RandRect(HDC hdc, int nClientWitdh, int nClientHeight) {
    HBRUSH newBrush, oldBrush;
    COLORREF colorVal = RGB(rand() % 256, rand() % 256, rand() % 256);
    int hatchBrushFlag = rand() % 2;
    if (hatchBrushFlag == 1) {
        static int nHS[6] = { HS_HORIZONTAL, HS_VERTICAL,
                              HS_BDIAGONAL,  HS_FDIAGONAL,
                              HS_CROSS,      HS_DIAGCROSS };

        newBrush = CreateHatchBrush(rand() % 6, colorVal);
    }
    else {
        newBrush = CreateSolidBrush(colorVal);
    }

    oldBrush = (HBRUSH)SelectObject(hdc, newBrush);

    RoundRect(hdc, rand() % nClientWitdh, rand() % nClientHeight, nClientWitdh, nClientHeight, rand() % 50, rand() % 50);

    SelectObject(hdc, oldBrush);
    DeleteObject(newBrush);
};


void RandDraw(HDC hdc, int nClientWitdh, int nClientHeight) {
    //랜덤의 범위는 그려질 도형, 브러쉬, 펜, 폰트, 전경색, 배경색, 크기, 좌표
    HPEN newPen, oldPen;
    HBRUSH newBrush, oldBrush;
    COLORREF colorVal = RGB(rand() % 256, rand() % 256, rand() % 256);

    int n_randCase = rand() % 10;

    int x1 = rand() % (nClientWitdh / 2);
    int y1 = rand() % (nClientHeight / 2);
    int x2 = rand() % (nClientWitdh / 2);
    int y2 = rand() % (nClientHeight / 2);

    MoveToEx(hdc, x1, y1, NULL);
    switch (n_randCase) {
    case 0:
        //라인그리기
        newPen = CreatePen(rand() % 5, 1, colorVal);
        oldPen = (HPEN)SelectObject(hdc, newPen);
        LineTo(hdc, x2, y2);
        SelectObject(hdc, oldPen);

        DeleteObject(newPen);
        break; 
    case 1:
        //사각형 그리기
        newBrush = (HBRUSH)GetStockObject(rand() % 6);
        oldBrush = (HBRUSH)SelectObject(hdc, newBrush);
        newPen = (HPEN)GetStockObject((rand() % 2) + 6);
        oldPen = (HPEN)SelectObject(hdc, newPen);
        Rectangle(hdc, x1, y1, x2, y2);
        SelectObject(hdc, oldPen);
        SelectObject(hdc, oldBrush);
        break;
    case 2:
        //원 그리기
        newBrush = CreateSolidBrush(colorVal);
        oldBrush = (HBRUSH)SelectObject(hdc, newBrush);
        Ellipse(hdc, x1, x1, y2, y2);
        SelectObject(hdc, oldBrush);
        DeleteObject(newBrush);
        break;
    case 3:
        //CreateHatchBrush 원 그리기
        newBrush = CreateHatchBrush(rand() % 6, colorVal);
        oldBrush = (HBRUSH)SelectObject(hdc, newBrush);
        Ellipse(hdc, x1, x2, y1, y2);
        SelectObject(hdc, oldBrush);
        DeleteObject(newBrush);
        break;
    case 4:
        newBrush = CreateSolidBrush(RGB(0, 255, 0));
        oldBrush = (HBRUSH)SelectObject(hdc, newBrush);
        Rectangle(hdc, 0, 0, x2, y2);
        SelectObject(hdc, oldBrush);

        //텍스트 관련 내용 출력
        TextOut(hdc, 20, 50, "기본 문자배경", 13);

        SetBkMode(hdc, TRANSPARENT);
        TextOut(hdc, 20, 80, "투명한 문자배경", 15);

        SetBkMode(hdc, OPAQUE);
        SetBkColor(hdc, RGB(0, 0, 255));
        SetTextColor(hdc, colorVal);
        TextOut(hdc, 20, 110, "불투명한 문자배경", 17);
        break;
    }

    CopyPixelQuater(hdc);
}

void CopyPixelQuater(HDC hdc) {
    //2사분면에 복사 붙여 넣기
    for (int i = 0; i < 400; i++) {
        for (int j = 0; j < 400; j++) {
            SetPixel(hdc, i+400, j, GetPixel(hdc, i, j));
        }
    }
    //3사분면 좌우 반전 복사 붙여넣기
    for (int i = 0; i < 400; i++) {
        for (int j = 0; j < 400; j++) {
            SetPixel(hdc, (400 - i), j + 400, GetPixel(hdc, i, j));
        }
    }

    //4사분면 상하 반전 복사 붙여넣기
    for (int i = 0; i < 400; i++) {
        for (int j = 0; j < 400; j++) {
            SetPixel(hdc, i + 400, (800 - j), GetPixel(hdc, i, j));
        }
    }
}