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

    hwnd = CreateWindow(szAppName,                  // 윈도우 클래스 이름
        "Win32-예제",               // 윈도우 켑션
        WS_OVERLAPPEDWINDOW,        // 윈도우 모양
        CW_USEDEFAULT,              // X 출력위치
        CW_USEDEFAULT,              // Y 출력위치
        300,						  // 윈도우 넓이
        300,						  // 윈도우 높이
        NULL,                       // 부모 윈도우 핸들
        NULL,                       // 윈도우 메뉴 핸들
        hInstance,                  // 인스턴트 핸들
        NULL);                     // 사용되지 않음

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
    HDC			hdc;	// DC에 대한 핸들
    PAINTSTRUCT ps;
    char		*szText = "윈도우 문자열 출력1";
    static int	cyChar = 0, nVscrollPos = 0, cyClient = 0, nHscrollPos = 0, widthClient = 0, widthCharAvg = 0, maxCharWidth = 0, n_maxVscroll = 0, n_maxHscroll = 0, n_maxCharWidth = 0;
    char		strBuff[255];
    int			x, y, i;
    TEXTMETRIC  tm;

    switch (message)
    {
    case WM_CREATE:

        // 폰트 크기
        hdc = GetDC(hwnd);
        GetTextMetrics(hdc, &tm);
        cyChar = tm.tmHeight;
        widthCharAvg = tm.tmAveCharWidth;
        maxCharWidth = tm.tmMaxCharWidth;
        ReleaseDC(hwnd, hdc);

        return 0;

    case WM_SIZE:
        // lParam의 상위 2바이트 : 클라이언트 영역의 높이 
        cyClient = HIWORD(lParam);
        widthClient = LOWORD(lParam);
        //문자 최대 길이
        //tm.tmMaxCharWidth
        //cyChar * NUMLINES
        int n_maxHeight = cyChar * NUMLINES;
        n_maxVscroll = (n_maxHeight - cyClient) <  0 ? 0 : ((n_maxHeight - cyClient) / cyChar) + 1;

        nVscrollPos = (n_maxHeight < cyClient )? 0 : nVscrollPos;
        //현재 화면에 출력된 문자 라인 수 : cyClient / cyChar
        //숨어있는 문자열 수 nVscrollPos
        //현재 페이지에 출력된 문자 라인 : NUMLINES - nVscrollPos
        int outPutHeight = (NUMLINES - nVscrollPos) * cyChar;
        nVscrollPos = outPutHeight + cyChar < cyClient ? nVscrollPos - 1 : nVscrollPos;
        nVscrollPos = (nVscrollPos < 0) ? 0 : nVscrollPos;
        SetScrollRange(hwnd,			//	윈도우 핸들 or 콘트롤 핸들 ( SB_CTL )
            SB_VERT,		            //	수직
            0,			                //	최소
            n_maxVscroll,	            //	최대
            FALSE);		                //	redraw 여부

        SetScrollPos(hwnd,
            SB_VERT,
            nVscrollPos,	// thumb 위치
            FALSE);		    // redraw 여부

        n_maxHscroll = (widthClient > n_maxCharWidth) ? 0 : ((n_maxCharWidth - widthClient) / widthCharAvg) + 1;
        
        //숨겨진 문자 길이
        int n_hideWidth = nHscrollPos * widthCharAvg;
        nHscrollPos = (nHscrollPos > 0 && widthClient >= (n_maxCharWidth - n_hideWidth)) ? nHscrollPos - 1 : nHscrollPos;

        nHscrollPos = (n_maxCharWidth < widthClient) ? 0 : nHscrollPos;

        //수평 스크롤
        SetScrollRange(hwnd,			//	윈도우 핸들 or 콘트롤 핸들 ( SB_CTL )
            SB_HORZ,		            //	수직
            0,			                //	최소
            n_maxHscroll,	            //	최대
            FALSE);		                //	redraw 여부

        SetScrollPos(hwnd,
            SB_HORZ,
            nHscrollPos,	// thumb 위치
            FALSE);		    // redraw 여부

        return 0;

    case WM_VSCROLL:
        //// wParam의 하위 2바이트 : 눌린버튼
        ////          상위 2바이트 : thumb의 위치
        //// lParam : 윈도우 핸들
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

        //// 갱신될 포지션과 현재 포지션과의 불일치 여부
        // nVscrollPos는 아직 스크롤포지션에 반영되지 않았다
        nVscrollPos = (nVscrollPos > n_maxVscroll) ? n_maxVscroll : nVscrollPos;
        if (nVscrollPos != GetScrollPos(hwnd, SB_VERT))
        {
            //// 포지션 재설정
            SetScrollPos(hwnd, SB_VERT, nVscrollPos, TRUE);
            //// 무효화
            InvalidateRect(hwnd,
                NULL,	// NULL이면 전체 클라이언트 영역
                TRUE);	// 무효영역을 지울지 여부							   
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
        //// 갱신될 포지션과 현재 포지션과의 불일치 여부
        // nVscrollPos는 아직 스크롤포지션에 반영되지 않았다
        if (nHscrollPos != GetScrollPos(hwnd, SB_HORZ))
        {
            //// 포지션 재설정
            SetScrollPos(hwnd, SB_HORZ, nHscrollPos, TRUE);
            //// 무효화
            InvalidateRect(hwnd,
                NULL,	// NULL이면 전체 클라이언트 영역
                TRUE);	// 무효영역을 지울지 여부							   
        }

        return 0;

    case WM_PAINT:
        //// DC 핸들을 얻고, 전체 클라이언트 영역이 유효화된다
        //// 무효 영역을 유효화하여 다시 WM_PAINT 메시지가 호출되지 않도록 한다
        hdc = BeginPaint(hwnd, &ps);
        {
			static int n_TmpWidthA = 0;

            x = (widthCharAvg * nHscrollPos) * -1;
            for (i = 0; i < NUMLINES; i++)
            {
                y = cyChar * (i - nVscrollPos);
                
                //// 서식형으로 문자열을 만든다				
                wsprintf(strBuff, "Scrollbar %2d, VSPos %2d, y %3d", i, nVscrollPos, y);

                TextOut(hdc, x, y, strBuff, strlen(strBuff));

				//출력되는 문자열에서 가장 큰값을 찾기위해 임시로 저장하는 변수
				
				GetTextExtentPoint32(hdc, strBuff, strlen(strBuff), &n_TmpWidthA);
				n_maxCharWidth = (n_maxCharWidth > n_TmpWidthA) ? n_maxCharWidth : n_TmpWidthA;
            }

        }

        //// DC 핸들 해제
        EndPaint(hwnd, &ps);
        return 0;
    case WM_DESTROY:
        PostQuitMessage(WM_QUIT);
        return 0;
    }

    return DefWindowProc(hwnd, message, wParam, lParam);
}
