#pragma once
#include <windows.h>
#define ID_SCRRED 100
#define ID_SCRGREEN 101
#define ID_SCRBLUE 102
#define ID_SCRBORDER 103

HWND pRed, pGreen, pBlue, brRed, brGreen, brBlue, penBorder;

int nPRed, nPGreen, nPBlue, nBrRed, nBrGreen, nBrBlue, nPenBorder;

void SetScroll(HWND hWnd, HINSTANCE g_hInst);