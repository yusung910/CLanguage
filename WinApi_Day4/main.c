#include <windows.h>

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

    //// 윈도 생성
    hWnd = CreateWindow(szAppName,
        szAppName,
        WS_OVERLAPPEDWINDOW,
        100, 100, 250, 200,
        NULL, NULL, hInstance, NULL);

    if (!hWnd) return FALSE;

    //// 생성된 윈도를 화면에 표시
    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    //// 메시지 루프
    while (GetMessage(&msg, NULL, 0, 0))
    {
        DispatchMessage(&msg);
    }
    return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message,
    WPARAM wParam, LPARAM lParam)
{
    HDC			hdc;
    static char string[256];

    switch (message)
    {
    case WM_KEYDOWN:
        wsprintf(string, "Virtual-Key Code %d", wParam);
        hdc = GetDC(hWnd);
        TextOut(hdc, 50, 10, string, strlen(string));
        ReleaseDC(hWnd, hdc);
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}