#include <windows.h>

#define NUMLINES	30

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    PSTR szCmdLine, int iCmdShow)
{
    static CHAR szAppName[] = "GP";
    HWND         hwnd;
    MSG          msg;
    WNDCLASS     wndclass;

    wndclass.style = CS_HREDRAW | CS_VREDRAW;
    wndclass.lpfnWndProc = WndProc;
    wndclass.cbClsExtra = 0;
    wndclass.cbWndExtra = 0;
    wndclass.hInstance = hInstance;
    wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wndclass.lpszMenuName = NULL;
    wndclass.lpszClassName = szAppName;

    RegisterClass(&wndclass);

    hwnd = CreateWindow(szAppName,                  // ������ Ŭ���� �̸�
        "Win32-����",               // ������ �μ�
        WS_OVERLAPPEDWINDOW,        // ������ ���
        CW_USEDEFAULT,              // X �����ġ
        CW_USEDEFAULT,              // Y �����ġ
        300,						  // ������ ����
        300,						  // ������ ����
        NULL,                       // �θ� ������ �ڵ�
        NULL,                       // ������ �޴� �ڵ�
        hInstance,                  // �ν���Ʈ �ڵ�
        NULL);                     // ������ ����

    ShowWindow(hwnd, iCmdShow);
    UpdateWindow(hwnd);

    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HDC			hdc;	// DC�� ���� �ڵ�
    PAINTSTRUCT ps;
    char		*szText = "������ ���ڿ� ���1";
    static int	cyChar = 0, nVscrollPos = 0, cyClient = 0, nHscrollPos = 0, widthClient = 0, widthCharAvg = 0, maxCharWidth = 0, n_maxVscroll = 0, n_maxHscroll = 0, n_maxCharWidth = 0;
    char		strBuff[255];
    int			x, y, i;
    TEXTMETRIC  tm;

    switch (message)
    {
    case WM_CREATE:

        // ��Ʈ ũ��
        hdc = GetDC(hwnd);
        GetTextMetrics(hdc, &tm);
        cyChar = tm.tmHeight;
        widthCharAvg = tm.tmAveCharWidth;
        maxCharWidth = tm.tmMaxCharWidth;
        ReleaseDC(hwnd, hdc);

        return 0;

    case WM_SIZE:
        // lParam�� ���� 2����Ʈ : Ŭ���̾�Ʈ ������ ���� 
        cyClient = HIWORD(lParam);
        widthClient = LOWORD(lParam);
        //���� �ִ� ����
        //tm.tmMaxCharWidth
        //cyChar * NUMLINES
        int n_maxHeight = cyChar * NUMLINES;
        n_maxVscroll = (n_maxHeight - cyClient) <  0 ? 0 : ((n_maxHeight - cyClient) / cyChar) + 1;

        nVscrollPos = (n_maxHeight < cyClient )? 0 : nVscrollPos;
        //���� ȭ�鿡 ��µ� ���� ���� �� : cyClient / cyChar
        //�����ִ� ���ڿ� �� nVscrollPos
        //���� �������� ��µ� ���� ���� : NUMLINES - nVscrollPos
        int outPutHeight = (NUMLINES - nVscrollPos) * cyChar;
        nVscrollPos = outPutHeight + cyChar < cyClient ? nVscrollPos - 1 : nVscrollPos;
        nVscrollPos = (nVscrollPos < 0) ? 0 : nVscrollPos;
        SetScrollRange(hwnd,			//	������ �ڵ� or ��Ʈ�� �ڵ� ( SB_CTL )
            SB_VERT,		            //	����
            0,			                //	�ּ�
            n_maxVscroll,	            //	�ִ�
            FALSE);		                //	redraw ����

        SetScrollPos(hwnd,
            SB_VERT,
            nVscrollPos,	// thumb ��ġ
            FALSE);		    // redraw ����

        n_maxHscroll = (widthClient > n_maxCharWidth) ? 0 : ((n_maxCharWidth - widthClient) / widthCharAvg) + 1;
        
        //������ ���� ����
        int n_hideWidth = nHscrollPos * widthCharAvg;
        nHscrollPos = (nHscrollPos > 0 && widthClient >= (n_maxCharWidth - n_hideWidth)) ? nHscrollPos - 1 : nHscrollPos;

        nHscrollPos = (n_maxCharWidth < widthClient) ? 0 : nHscrollPos;

        //���� ��ũ��
        SetScrollRange(hwnd,			//	������ �ڵ� or ��Ʈ�� �ڵ� ( SB_CTL )
            SB_HORZ,		            //	����
            0,			                //	�ּ�
            n_maxHscroll,	            //	�ִ�
            FALSE);		                //	redraw ����

        SetScrollPos(hwnd,
            SB_HORZ,
            nHscrollPos,	// thumb ��ġ
            FALSE);		    // redraw ����

        return 0;

    case WM_VSCROLL:
        //// wParam�� ���� 2����Ʈ : ������ư
        ////          ���� 2����Ʈ : thumb�� ��ġ
        //// lParam : ������ �ڵ�
        switch (LOWORD(wParam))
            //switch ((WORD)wParam)
        {
        case SB_LINEUP:
            nVscrollPos -= 1;
            break;

        case SB_LINEDOWN:
            nVscrollPos += 1;
            break;

        case SB_PAGEUP:
            nVscrollPos -= cyClient / cyChar;
            break;

        case SB_PAGEDOWN:
            nVscrollPos += cyClient / cyChar;
            break;

        case SB_THUMBPOSITION:
            nVscrollPos = HIWORD(wParam);
            //nVscrollPos = ((wParam & 0xFFFF0000) >> 16);
            break;
		case SB_THUMBTRACK:
			nVscrollPos = HIWORD(wParam);
			break;

        default:
            break;
        }

        nVscrollPos = max(0, min(nVscrollPos, NUMLINES - 1));
        //if (nVscrollPos < 0)			nVscrollPos = 0;
        //if (nVscrollPos > NUMLINES-1) nVscrollPos = NUMLINES-1;

        //// ���ŵ� �����ǰ� ���� �����ǰ��� ����ġ ����
        // nVscrollPos�� ���� ��ũ�������ǿ� �ݿ����� �ʾҴ�
        nVscrollPos = (nVscrollPos > n_maxVscroll) ? n_maxVscroll : nVscrollPos;
        if (nVscrollPos != GetScrollPos(hwnd, SB_VERT))
        {
            //// ������ �缳��
            SetScrollPos(hwnd, SB_VERT, nVscrollPos, TRUE);
            //// ��ȿȭ
            InvalidateRect(hwnd,
                NULL,	// NULL�̸� ��ü Ŭ���̾�Ʈ ����
                TRUE);	// ��ȿ������ ������ ����							   
        }
        return 0;

    case WM_HSCROLL:
        //nHscrollPos
        switch (LOWORD(wParam)) {
        case SB_LINEUP:
            nHscrollPos -= 1;
            break;
        case SB_LINEDOWN:
            nHscrollPos += 1;
            break;

        case SB_PAGEUP:
            nHscrollPos -= widthCharAvg;
            break;

        case SB_PAGEDOWN:
            nHscrollPos += widthCharAvg;
            break;

        case SB_THUMBPOSITION:
            nHscrollPos = HIWORD(wParam);
            //nVscrollPos = ((wParam & 0xFFFF0000) >> 16);
            break;
		case SB_THUMBTRACK:
			nHscrollPos = HIWORD(wParam);
			break;
        default:
            break;
        }

        nHscrollPos = max(0, min(nHscrollPos, NUMLINES - 1));

        nHscrollPos = (nHscrollPos > n_maxHscroll) ? n_maxHscroll : nHscrollPos;
        //// ���ŵ� �����ǰ� ���� �����ǰ��� ����ġ ����
        // nVscrollPos�� ���� ��ũ�������ǿ� �ݿ����� �ʾҴ�
        if (nHscrollPos != GetScrollPos(hwnd, SB_HORZ))
        {
            //// ������ �缳��
            SetScrollPos(hwnd, SB_HORZ, nHscrollPos, TRUE);
            //// ��ȿȭ
            InvalidateRect(hwnd,
                NULL,	// NULL�̸� ��ü Ŭ���̾�Ʈ ����
                TRUE);	// ��ȿ������ ������ ����							   
        }

        return 0;

    case WM_PAINT:
        //// DC �ڵ��� ���, ��ü Ŭ���̾�Ʈ ������ ��ȿȭ�ȴ�
        //// ��ȿ ������ ��ȿȭ�Ͽ� �ٽ� WM_PAINT �޽����� ȣ����� �ʵ��� �Ѵ�
        hdc = BeginPaint(hwnd, &ps);
        {
			static int n_TmpWidthA = 0;

            x = (widthCharAvg * nHscrollPos) * -1;
            for (i = 0; i < NUMLINES; i++)
            {
                y = cyChar * (i - nVscrollPos);
                
                //// ���������� ���ڿ��� �����				
                wsprintf(strBuff, "Scrollbar %2d, VSPos %2d, y %3d", i, nVscrollPos, y);

                TextOut(hdc, x, y, strBuff, strlen(strBuff));

				//��µǴ� ���ڿ����� ���� ū���� ã������ �ӽ÷� �����ϴ� ����
				
				GetTextExtentPoint32(hdc, strBuff, strlen(strBuff), &n_TmpWidthA);
				n_maxCharWidth = (n_maxCharWidth > n_TmpWidthA) ? n_maxCharWidth : n_TmpWidthA;
            }

        }

        //// DC �ڵ� ����
        EndPaint(hwnd, &ps);
        return 0;
    case WM_DESTROY:
        PostQuitMessage(WM_QUIT);
        return 0;
    }

    return DefWindowProc(hwnd, message, wParam, lParam);
}
