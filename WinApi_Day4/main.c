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

    //HINSTANCE�� �۷ι� ������ �����Ѵ�.
    g_hInst = hInstance;

    //// ���� ����
    hWnd = CreateWindow(szAppName,
        szAppName,
        WS_OVERLAPPEDWINDOW,
        100, 100, 1600, 1000,
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
 //   HDC			hdc;
	//PAINTSTRUCT ps;

	static char string[256];
	static int	nLen = 0;
    static int n_barSize = 255;

	static BOOL bDrawing = FALSE;
    static BOOL bScrollClick = FALSE;
	static short int  x1, y1, x2, y2, clientX, clientY;
    static short int N_TOOL = 0, N_PEN = 7, N_BRUSH = 10;

    //��ũ�ѹ� �ƽ� ����
    int n_HscrollMax = 0;

    //�ӽ�
    int TempPos;

    switch (message)
    {
    case WM_CREATE:
        //��ũ�ѹ� ����
        SetScroll(hWnd, g_hInst);
        break;

	case WM_PAINT:
        clientX = LOWORD(lParam);
        clientY = HIWORD(lParam);
        //�׸��� ȭ�� �ʱ�ȭ

        InitDisplay(hWnd, clientX, clientY, n_barSize);
        SetTool(hWnd, N_TOOL, N_PEN, N_BRUSH, n_CurrentTool, RGB(nPRed, nPGreen, nPBlue), RGB(nBrRed, nBrGreen, nBrBlue), nPenBorder);
		break;

	case WM_SIZE:
        clientX = LOWORD(lParam);
        clientY = HIWORD(lParam);
        //�׸��� ȭ�� �ʱ�ȭ
		
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
			//�� ��ư�� Ŭ���� ��� �̺�Ʈ �߻�
            //��ũ���� Ŭ������ ���� ��쿡�� ����
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
			//// ������ �׸� ���� �����(���������� �׸���)
			//   ��, ���ʿ��� ��ǥ�� �����ϹǷ� �׸��� �ʴ´�
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
		    //// ������ �׸� ���� �����
            Draw(hWnd, N_TOOL, N_PEN, N_BRUSH, x1, y1, x2, y2, nPenBorder, RGB(nPRed, nPGreen, nPBlue), RGB(nBrRed, nBrGreen, nBrBlue), FALSE);
		    bDrawing = FALSE;
		    ReleaseCapture();
		    //// �簢������ ä���
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


