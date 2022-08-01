#include "DrawRect.h"
void DrawRect(HWND hWnd, int x1, int y1, int x2, int y2, BOOL bFill)
{
	int nStockBrush = NULL_BRUSH;

	HDC hdc = GetDC(hWnd);
	if (bFill)
		nStockBrush = BLACK_BRUSH;
	else
		SetROP2(hdc, R2_NOT);
	SelectObject(hdc, GetStockObject(nStockBrush));
	Rectangle(hdc, x1, y1, x2, y2);
	ReleaseDC(hWnd, hdc);
}