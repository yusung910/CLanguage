#include "SetScroll.h"

void SetScroll(HWND hWnd, HINSTANCE g_hInst) {
    
    //奇 RGB 胶农费 积己
    pRed = CreateWindow("scrollbar", NULL, WS_CHILD | WS_VISIBLE | SBS_HORZ,
        800, 50, 256, 20, hWnd, (HMENU)ID_SCRRED, g_hInst, NULL);
    pGreen = CreateWindow("scrollbar", NULL, WS_CHILD | WS_VISIBLE | SBS_HORZ,
        800, 90, 256, 20, hWnd, (HMENU)ID_SCRGREEN, g_hInst, NULL);
    pBlue = CreateWindow("scrollbar", NULL, WS_CHILD | WS_VISIBLE | SBS_HORZ,
        800, 130, 256, 20, hWnd, (HMENU)ID_SCRBLUE, g_hInst, NULL);

    //奇 苯扁 胶农费 积己
    penBorder = CreateWindow("scrollbar", NULL, WS_CHILD | WS_VISIBLE | SBS_HORZ,
        780, 190, 256, 20, hWnd, (HMENU)ID_SCRBORDER, g_hInst, NULL);
    

    SetScrollRange(pRed, SB_CTL, 0, 255, TRUE);
    SetScrollPos(pRed, SB_CTL, 0, TRUE);
    SetScrollRange(pGreen, SB_CTL, 0, 255, TRUE);
    SetScrollPos(pGreen, SB_CTL, 0, TRUE);
    SetScrollRange(pBlue, SB_CTL, 0, 255, TRUE);
    SetScrollPos(pBlue, SB_CTL, 0, TRUE);

    SetScrollRange(penBorder, SB_CTL, 0, 30, TRUE);
    SetScrollPos(penBorder, SB_CTL, 0, TRUE);

    //宏矾矫 RGB 胶农费 积己
    brRed = CreateWindow("scrollbar", NULL, WS_CHILD | WS_VISIBLE | SBS_HORZ,
        1110, 50, 256, 20, hWnd, (HMENU)ID_SCRRED, g_hInst, NULL);
    brGreen = CreateWindow("scrollbar", NULL, WS_CHILD | WS_VISIBLE | SBS_HORZ,
        1110, 90, 256, 20, hWnd, (HMENU)ID_SCRGREEN, g_hInst, NULL);
    brBlue = CreateWindow("scrollbar", NULL, WS_CHILD | WS_VISIBLE | SBS_HORZ,
        1110, 130, 256, 20, hWnd, (HMENU)ID_SCRBLUE, g_hInst, NULL);

    SetScrollRange(brRed, SB_CTL, 0, 255, TRUE);
    SetScrollPos(brRed, SB_CTL, 0, TRUE);
    SetScrollRange(brGreen, SB_CTL, 0, 255, TRUE);
    SetScrollPos(brGreen, SB_CTL, 0, TRUE);
    SetScrollRange(brBlue, SB_CTL, 0, 255, TRUE);
    SetScrollPos(brBlue, SB_CTL, 0, TRUE);


}