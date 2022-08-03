#include <windows.h>
#include "__debug.h"
#include "InitDisplay.h"
#include "SetTool.h"
#include "Draw.h"
#include "GetToolPos.h"

#define ID_PENSCRRED 100
#define ID_PENSCRGREEN 101
#define ID_PENSCRBLUE 102
#define ID_BRSCRRED 103
#define ID_BRSCRGREEN 104
#define ID_BRSCRBLUE 105
#define ID_SCRBORDER 106

HINSTANCE g_hInst;

HWND pRed, pGreen, pBlue, brRed, brGreen, brBlue, penBorder;

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
    HDC			hdc;
	PAINTSTRUCT ps;

	static char string[256];
	static int	nLen = 0;
    static int n_barSize = 255;
    static RECT winRec;
	static BOOL bDrawing = FALSE;
    static BOOL bScrollClick = FALSE;
	static short int  x1, y1, x2, y2, clientX, clientY;
    static short int n_textX, n_textY;
    static short int N_TOOL = 0, N_PEN = 7, N_BRUSH = 10, N_TEXT = 0;
    static HWND selectScrollHwnd;
    //스크롤바 맥스 변수
    int n_HscrollMax = 0;

    static int nTextPenR, nTextPenG, nTextPenB, nTextBrR, nTextBrG, nTextBrB;

    //임시
    int TempPos;

    switch (message)
    {
    case WM_CREATE:
        clientX = LOWORD(lParam);
        clientY = HIWORD(lParam);
        //스크롤바 생성
        //펜 RGB 스크롤 생성
        pRed = CreateWindow("scrollbar", NULL, WS_CHILD | WS_VISIBLE | SBS_HORZ,
            800, 50, 256, 20, hWnd, (HMENU)ID_PENSCRRED, g_hInst, NULL);
        pGreen = CreateWindow("scrollbar", NULL, WS_CHILD | WS_VISIBLE | SBS_HORZ,
            800, 90, 256, 20, hWnd, (HMENU)ID_PENSCRGREEN, g_hInst, NULL);
        pBlue = CreateWindow("scrollbar", NULL, WS_CHILD | WS_VISIBLE | SBS_HORZ,
            800, 130, 256, 20, hWnd, (HMENU)ID_PENSCRBLUE, g_hInst, NULL);

        //펜 굵기 스크롤 생성
        penBorder = CreateWindow("scrollbar", NULL, WS_CHILD | WS_VISIBLE | SBS_HORZ,
            780, 190, 256, 20, hWnd, (HMENU)ID_SCRBORDER, g_hInst, NULL);

        //브러시 RGB 스크롤 생성
        brRed = CreateWindow("scrollbar", NULL, WS_CHILD | WS_VISIBLE | SBS_HORZ,
            1110, 50, 256, 20, hWnd, (HMENU)ID_BRSCRRED, g_hInst, NULL);
        brGreen = CreateWindow("scrollbar", NULL, WS_CHILD | WS_VISIBLE | SBS_HORZ,
            1110, 90, 256, 20, hWnd, (HMENU)ID_BRSCRGREEN, g_hInst, NULL);
        brBlue = CreateWindow("scrollbar", NULL, WS_CHILD | WS_VISIBLE | SBS_HORZ,
            1110, 130, 256, 20, hWnd, (HMENU)ID_BRSCRBLUE, g_hInst, NULL);

        SetScrollRange(pRed, SB_CTL, 0, 255, TRUE);
        SetScrollPos(pRed, SB_CTL, 0, TRUE);
        SetScrollRange(pGreen, SB_CTL, 0, 255, TRUE);
        SetScrollPos(pGreen, SB_CTL, 0, TRUE);
        SetScrollRange(pBlue, SB_CTL, 0, 255, TRUE);
        SetScrollPos(pBlue, SB_CTL, 0, TRUE);

        SetScrollRange(penBorder, SB_CTL, 0, 30, TRUE);
        SetScrollPos(penBorder, SB_CTL, 0, TRUE);

        SetScrollRange(brRed, SB_CTL, 0, 255, TRUE);
        SetScrollPos(brRed, SB_CTL, 0, TRUE);
        SetScrollRange(brGreen, SB_CTL, 0, 255, TRUE);
        SetScrollPos(brGreen, SB_CTL, 0, TRUE);
        SetScrollRange(brBlue, SB_CTL, 0, 255, TRUE);
        SetScrollPos(brBlue, SB_CTL, 0, TRUE);
        break;
    case WM_MOVE:
        GetClientRect(hWnd, &winRec);
        clientX = winRec.right;
        clientY = winRec.bottom;
        //그림판 화면 초기화

        InitDisplay(hWnd, clientX, clientY, n_barSize);
        SetTool(hWnd, N_TOOL, N_PEN, N_BRUSH, n_CurrentTool, RGB(nPRed, nPGreen, nPBlue), RGB(nBrRed, nBrGreen, nBrBlue), nPenBorder);
        break;
	case WM_PAINT:

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
        selectScrollHwnd = (HWND)lParam;
        if (selectScrollHwnd == pRed) TempPos = nPRed;
        if (selectScrollHwnd == pGreen) TempPos = nPGreen;
        if (selectScrollHwnd == pBlue) TempPos = nPBlue;

        if (selectScrollHwnd == brRed) TempPos = nBrRed;
        if (selectScrollHwnd == brGreen) TempPos = nBrGreen;
        if (selectScrollHwnd == brBlue) TempPos = nBrBlue;

        if (selectScrollHwnd == penBorder) TempPos = nPenBorder;

        if ((HWND)lParam == penBorder) {
            TempPos = nPenBorder;
            n_HscrollMax = 30;
        }
        else {
            n_HscrollMax = 255;
        }

        if (n_CurrentTool <= 18) {
            SetTool(hWnd, N_TOOL, N_PEN, N_BRUSH, n_CurrentTool, RGB(nPRed, nPGreen, nPBlue), RGB(nBrRed, nBrGreen, nBrBlue), nPenBorder);
        }
        else {

            hdc = GetDC(hWnd);

            switch (n_CurrentTool) {
            case 19:
                TextOut(hdc, 550, 120, "기본 문자배경", 13);
                break;
            case 20:
                SetBkMode(hdc, TRANSPARENT);
                TextOut(hdc, 550, 120, "투명한 문자배경", 15);
                break;
            case 21:
                SetBkMode(hdc, OPAQUE);
                SetBkColor(hdc, RGB(nBrRed, nBrGreen, nBrBlue));
                SetTextColor(hdc, RGB(nPRed, nPGreen, nPBlue));
                TextOut(hdc, 550, 120, "불투명한 문자배경", 17);
                break;
            }
        }

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
            if (N_TEXT > 0) {
                //문자열 길이 초기화
                nLen = 0;
                for (int i = 0; i < sizeof(string); i++) {
                    string[i] = '\0';
                }
                n_textX = (short)LOWORD(lParam);
                n_textY = ((short)HIWORD(lParam) < n_barSize) ? n_barSize : (short)HIWORD(lParam);
            }
            else {
                SetCapture(hWnd);
                SetCursor(LoadCursor(NULL, IDC_CROSS));
                bDrawing = TRUE;
            }
		}
		else { 
			//툴 버튼을 클릭할 경우 이벤트 발생
            //스크롤을 클릭하지 않을 경우에만 실행
            if (!bScrollClick) {
                n_CurrentTool = GetToolPos(x1, y1);
                if (n_CurrentTool > -1) {
                    if (n_CurrentTool <= 4) {
                        N_TOOL = n_CurrentTool;
                    }
                    else if (n_CurrentTool > 4 && n_CurrentTool <= 9) {
                        N_PEN = n_CurrentTool;
                    }
                    else if (n_CurrentTool > 9 && n_CurrentTool <= 16) {
                        N_BRUSH = n_CurrentTool;
                    }
                    else if (n_CurrentTool == 17) {
                        //지우개
                        N_PEN = n_CurrentTool;
                        N_TOOL = 0;
                        N_BRUSH = 10;
                    }
                    else if (n_CurrentTool == 18) {
                        //전체지우개
                        //사각형
                        hdc = GetDC(hWnd);
                        SelectObject(hdc, GetStockObject(WHITE_BRUSH));
                        SelectObject(hdc, GetStockObject(WHITE_PEN));

                        Rectangle(hdc, 0, n_barSize + 1, clientX, clientY);

                    }
                    else if (n_CurrentTool > 18 && n_CurrentTool <= 21) {
                        //텍스트 입력
                        N_TEXT = n_CurrentTool;
                        //미리보기 초기화 
                        HPEN newPen, oldPen;

                        hdc = GetDC(hWnd);

                        //미리보기 영역 500, 30, 750, 235
                        //미리보기 영역 클리어
                        newPen = CreatePen(PS_SOLID, 1, RGB(200, 200, 200));
                        oldPen = SelectObject(hdc, newPen);

                        //문자열 디자인 영역
                        SelectObject(hdc, GetStockObject(WHITE_BRUSH));
                        Rectangle(hdc, 500, 30, 750, 235);

                        //미리보기 타이틀 출력
                        TextOut(hdc, 520, 23, "미리보기", 8);

                        switch (N_TEXT) {
                        case 19:
                            TextOut(hdc, 550, 120, "기본 문자배경", 13);
                            break;
                        case 20:
                            SetBkMode(hdc, TRANSPARENT);
                            TextOut(hdc, 550, 120, "투명한 문자배경", 15);
                            break;
                        case 21:
                            SetBkMode(hdc, OPAQUE);
                            SetBkColor(hdc, RGB(nBrRed, nBrGreen, nBrBlue));
                            SetTextColor(hdc, RGB(nPRed, nPGreen, nPBlue));
                            TextOut(hdc, 550, 120, "불투명한 문자배경", 17);
                            break;
                        }
                    }
                    if (n_CurrentTool <= 18) {
                        N_TEXT = 0;
                        SetTool(hWnd, N_TOOL, N_PEN, N_BRUSH, n_CurrentTool, RGB(nPRed, nPGreen, nPBlue), RGB(nBrRed, nBrGreen, nBrBlue), nPenBorder);
                    }
                }
            }
		}
		break;

	case WM_MOUSEMOVE:
        bScrollClick = FALSE;
		if (bDrawing)
		{
			if (N_TOOL == 0) {
                N_TEXT = 0;
				hdc = GetDC(hWnd);
				HPEN newPen, oldPen;

				newPen = CreatePen(PS_DASH, nPenBorder, RGB(nPRed, nPGreen, nPBlue));

				//펜 설정
				switch (N_PEN) {
				case 5:
					newPen = CreatePen(PS_DASH, nPenBorder, RGB(nPRed, nPGreen, nPBlue));
					break;
				case 6:
					newPen = CreatePen(PS_DOT, nPenBorder, RGB(nPRed, nPGreen, nPBlue));
					break;
				case 7:
					newPen = CreatePen(PS_SOLID, nPenBorder, RGB(nPRed, nPGreen, nPBlue));
					break;
				case 8:
					newPen = CreatePen(PS_DASHDOT, nPenBorder, RGB(nPRed, nPGreen, nPBlue));
					break;
				case 9:
					newPen = CreatePen(PS_DASHDOTDOT, nPenBorder, RGB(nPRed, nPGreen, nPBlue));
					break;
				case 17:
					newPen = CreatePen(PS_DASH, nPenBorder, RGB(255, 255, 255));
                    break;
				}

				oldPen = SelectObject(hdc, newPen);

				MoveToEx(hdc, x1, y1, NULL);
				x1 = (short)LOWORD(lParam);
				y1 = ((short)HIWORD(lParam) < n_barSize) ? n_barSize : (short)HIWORD(lParam);
				LineTo(hdc, x1, y1);

				SelectObject(hdc, oldPen);
				DeleteObject(newPen);

				ReleaseDC(hWnd, hdc);
			}
			else {
                N_TEXT = 0;
				SetCursor(LoadCursor(NULL, IDC_CROSS));
				Draw(hWnd, N_TOOL, N_PEN, N_BRUSH, x1, y1, x2, y2, nPenBorder, RGB(nPRed, nPGreen, nPBlue), RGB(nBrRed, nBrGreen, nBrBlue), FALSE);
				//// 이전에 그린 선을 지운다(반전색으로 그린다)
				//   단, 최초에는 좌표가 동일하므로 그리지 않는다
				x2 = (short)LOWORD(lParam);
				y2 = ((short)HIWORD(lParam) < n_barSize) ? n_barSize : (short)HIWORD(lParam);
				Draw(hWnd, N_TOOL, N_PEN, N_BRUSH, x1, y1, x2, y2, nPenBorder, RGB(nPRed, nPGreen, nPBlue), RGB(nBrRed, nBrGreen, nBrBlue), FALSE);
			}


		}

		if (GetToolPos((short)LOWORD(lParam), (short)HIWORD(lParam)) > -1) {
			SetCursor(LoadCursor(NULL, IDC_HAND));
		}
		break;

	case WM_LBUTTONUP:
		if (bDrawing)
	    {
			if (N_TOOL == 0) {
				bDrawing = FALSE;
				ReleaseCapture();
			}
			else {
				//// 이전에 그린 선을 지운다
				Draw(hWnd, N_TOOL, N_PEN, N_BRUSH, x1, y1, x2, y2, nPenBorder, RGB(nPRed, nPGreen, nPBlue), RGB(nBrRed, nBrGreen, nBrBlue), FALSE);
				bDrawing = FALSE;
				ReleaseCapture();
				//// 사각영역을 채운다
				Draw(hWnd, N_TOOL, N_PEN, N_BRUSH, x1, y1, x2, y2, nPenBorder, RGB(nPRed, nPGreen, nPBlue), RGB(nBrRed, nBrGreen, nBrBlue), TRUE);
			}

			UpdateWindow(hWnd);	
	    }
	break;

	case WM_KEYDOWN:
		//// ( winuser.h )
		//// wParam : virtual-key code
		//// lParam : key data
		TRACE2("WM_KEYDOWN %d %c\n", wParam, wParam);
        if (N_TEXT > 0) {
            hdc = GetDC(hWnd);

            switch (n_CurrentTool) {
            case 20:
                SetBkMode(hdc, TRANSPARENT);
                break;
            case 21:
                SetBkMode(hdc, OPAQUE);
                SetBkColor(hdc, RGB(nBrRed, nBrGreen, nBrBlue));
                SetTextColor(hdc, RGB(nPRed, nPGreen, nPBlue));
                break;
            }

            TextOut(hdc, n_textX, n_textY, string, nLen);

            ReleaseDC(hWnd, hdc);
        }
		break;

	case WM_CHAR:
		TRACE2("WM_CHAR %d %c\n", wParam, wParam);
        if (N_TEXT > 0) {
            string[nLen++] = (char)wParam;
            InvalidateRect(hWnd, NULL, FALSE);
        }

		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}


