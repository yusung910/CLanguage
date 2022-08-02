#include <windows.h>
#include "__debug.h"
#include "InitDisplay.h"
#include "SetScroll.h"
#include "SetTool.h"
#include "Draw.h"
#include "GetToolPos.h"

HINSTANCE g_hInst;

int nPRed = 0, nPGreen = 0, nPBlue = 0, nBrRed = 0, nBrGreen = 0, nBrBlue = 0, nPenBorder = 1;

int n_CurrentTool = 0;

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

    //HINSTANCE를 글로벌 변수에 저장한다.
    g_hInst = hInstance;

    //// 윈도 생성
    hWnd = CreateWindow(szAppName,
        szAppName,
        WS_OVERLAPPEDWINDOW,
        100, 100, 1600, 1000,
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
 //   HDC			hdc;
	//PAINTSTRUCT ps;

	static char string[256];
	static int	nLen = 0;
    static int n_barSize = 255;

	static BOOL bDrawing = FALSE;
    static BOOL bScrollClick = FALSE;
	static short int  x1, y1, x2, y2, clientX, clientY;
    static short int N_TOOL = 0, N_PEN = 7, N_BRUSH = 10;

    //스크롤바 맥스 변수
    int n_HscrollMax = 0;

    //임시
    int TempPos;

    switch (message)
    {
    case WM_CREATE:
        //스크롤바 생성
        SetScroll(hWnd, g_hInst);
        break;

	case WM_PAINT:
        clientX = LOWORD(lParam);
        clientY = HIWORD(lParam);
        //그림판 화면 초기화

        InitDisplay(hWnd, clientX, clientY, n_barSize);
        SetTool(hWnd, N_TOOL, N_PEN, N_BRUSH, n_CurrentTool, RGB(nPRed, nPGreen, nPBlue), RGB(nBrRed, nBrGreen, nBrBlue), nPenBorder);
		break;

	case WM_SIZE:
        clientX = LOWORD(lParam);
        clientY = HIWORD(lParam);
        //그림판 화면 초기화
		
        InitDisplay(hWnd, clientX, clientY, n_barSize);
        SetTool(hWnd, N_TOOL, N_PEN, N_BRUSH, n_CurrentTool, RGB(nPRed, nPGreen, nPBlue), RGB(nBrRed, nBrGreen, nBrBlue), nPenBorder);
		break;

    case WM_HSCROLL:
        bScrollClick = TRUE;
        if ((HWND)lParam == pRed) TempPos = nPRed;
        if ((HWND)lParam == pGreen) TempPos = nPGreen;
        if ((HWND)lParam == pBlue) TempPos = nPBlue;

        if ((HWND)lParam == brRed) TempPos = nBrRed;
        if ((HWND)lParam == brGreen) TempPos = nBrGreen;
        if ((HWND)lParam == brBlue) TempPos = nBrBlue;

        if ((HWND)lParam == penBorder) {
            TempPos = nPenBorder;
            n_HscrollMax = 30;
        }
        else {
            n_HscrollMax = 255;
        }

        SetTool(hWnd, N_TOOL, N_PEN, N_BRUSH, n_CurrentTool, RGB(nPRed, nPGreen, nPBlue), RGB(nBrRed, nBrGreen, nBrBlue), nPenBorder);

        switch (LOWORD(wParam)) {
        case SB_LINELEFT:
            TempPos = max(0, TempPos - 1);
            break;
        case SB_LINERIGHT:
            TempPos = min(n_HscrollMax, TempPos + 1);
            break;
        case SB_PAGELEFT:
            TempPos = max(0, TempPos - 10);
            break;
        case SB_PAGERIGHT:
            TempPos = min(n_HscrollMax, TempPos + 10);
            break;
        case SB_THUMBTRACK:
            TempPos = HIWORD(wParam);
            break;
        }
        if ((HWND)lParam == pRed) nPRed = TempPos;
        if ((HWND)lParam == pGreen) nPGreen = TempPos;
        if ((HWND)lParam == pBlue) nPBlue = TempPos;

        if ((HWND)lParam == brRed) nBrRed = TempPos;
        if ((HWND)lParam == brGreen) nBrGreen = TempPos;
        if ((HWND)lParam == brBlue) nBrBlue = TempPos;

        if ((HWND)lParam == penBorder) nPenBorder = TempPos;

        SetScrollPos((HWND)lParam, SB_CTL, TempPos, TRUE);
	case WM_LBUTTONDOWN:
		x1 = x2 = (short) LOWORD(lParam);
		y1 = y2 = (short) HIWORD(lParam);
		if (y2 > n_barSize) {
			SetCapture(hWnd);
			SetCursor(LoadCursor(NULL, IDC_CROSS));
			bDrawing = TRUE;
		}
		else { 
			//툴 버튼을 클릭할 경우 이벤트 발생
            //스크롤을 클릭하지 않을 경우에만 실행
            if (!bScrollClick) {
                n_CurrentTool = GetToolPos(x1, y1);

                if (n_CurrentTool <= 4) {
                    N_TOOL = n_CurrentTool;
                }
                else if (n_CurrentTool > 4 && n_CurrentTool <= 9) {
                    N_PEN = n_CurrentTool;
                }
                else if (n_CurrentTool > 9 && n_CurrentTool <= 16) {
                    N_BRUSH = n_CurrentTool;
                }

                SetTool(hWnd, N_TOOL, N_PEN, N_BRUSH, n_CurrentTool, RGB(nPRed, nPGreen, nPBlue), RGB(nBrRed, nBrGreen, nBrBlue), nPenBorder);
            }
		}
		break;

	case WM_MOUSEMOVE:
        bScrollClick = FALSE;
		if (bDrawing)
		{
			SetCursor(LoadCursor(NULL, IDC_CROSS));
            Draw(hWnd, N_TOOL, N_PEN, N_BRUSH, x1, y1, x2, y2, nPenBorder, RGB(nPRed, nPGreen, nPBlue), RGB(nBrRed, nBrGreen, nBrBlue), FALSE);
			//// 이전에 그린 선을 지운다(반전색으로 그린다)
			//   단, 최초에는 좌표가 동일하므로 그리지 않는다
			x2 = (short) LOWORD(lParam);
			y2 = ((short) HIWORD(lParam) < n_barSize) ? n_barSize : (short)HIWORD(lParam);
            Draw(hWnd, N_TOOL, N_PEN, N_BRUSH, x1, y1, x2, y2, nPenBorder, RGB(nPRed, nPGreen, nPBlue), RGB(nBrRed, nBrGreen, nBrBlue), FALSE);
		}

		if (GetToolPos((short)LOWORD(lParam), (short)HIWORD(lParam)) > -1) {
			SetCursor(LoadCursor(NULL, IDC_HAND));
		}
		break;

	case WM_LBUTTONUP:
		if (bDrawing)
	    {
		    //// 이전에 그린 선을 지운다
            Draw(hWnd, N_TOOL, N_PEN, N_BRUSH, x1, y1, x2, y2, nPenBorder, RGB(nPRed, nPGreen, nPBlue), RGB(nBrRed, nBrGreen, nBrBlue), FALSE);
		    bDrawing = FALSE;
		    ReleaseCapture();
		    //// 사각영역을 채운다
            Draw(hWnd, N_TOOL, N_PEN, N_BRUSH, x1, y1, x2, y2, nPenBorder, RGB(nPRed, nPGreen, nPBlue), RGB(nBrRed, nBrGreen, nBrBlue), TRUE);
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


