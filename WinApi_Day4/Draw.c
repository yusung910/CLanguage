#include "Draw.h"
#include "__debug.h"
void Draw(HWND hWnd, int N_TOOL, int N_PEN, int N_BRUSH, int x1, int y1, int x2, int y2, int n_pBorder, COLORREF pColor, COLORREF brColor, BOOL bFill)
{
	int nStockBrush = NULL_BRUSH;

	HDC hdc = GetDC(hWnd);
    HPEN newPen, oldPen;
    HBRUSH newBrush, oldBrush;

	if (bFill)
		nStockBrush = BLACK_BRUSH;
	else
		SetROP2(hdc, R2_NOT);

    newPen = CreatePen(PS_DASH, n_pBorder, pColor);


    //펜 설정
    switch (N_PEN) {
    case 5:
        newPen = CreatePen(PS_DASH, n_pBorder, pColor);
        break;
    case 6:
        newPen = CreatePen(PS_DOT, n_pBorder, pColor);
        break;
    case 7:
        newPen = CreatePen(PS_SOLID, n_pBorder, pColor);
        break;
    case 8:
        newPen = CreatePen(PS_DASHDOT, n_pBorder, pColor);
        break;
    case 9:
        newPen = CreatePen(PS_DASHDOTDOT, n_pBorder, pColor);
        break;
    }

    oldPen = SelectObject(hdc, newPen);

    newBrush = CreateSolidBrush(brColor);
    //브러시 설정
    switch (N_BRUSH) {
    case 10:
        newBrush = CreateSolidBrush(brColor);
        break;
    case 11:
        newBrush = CreateHatchBrush(HS_HORIZONTAL, brColor);
        break;
    case 12:
        newBrush = CreateHatchBrush(HS_VERTICAL, brColor);
        break;
    case 13:
        newBrush = CreateHatchBrush(HS_BDIAGONAL, brColor);
        break;
    case 14:
        newBrush = CreateHatchBrush(HS_FDIAGONAL, brColor);
        break;
    case 15:
        newBrush = CreateHatchBrush(HS_CROSS, brColor);
        break;
    case 16:
        newBrush = CreateHatchBrush(HS_DIAGCROSS, brColor);
        break;
    }

    oldBrush = (HBRUSH)SelectObject(hdc, newBrush);

    switch (N_TOOL) {
    case 1:
        //직선
        MoveToEx(hdc, x1, y1, NULL);
        LineTo(hdc, x2, y2);
        break;
    case 2:
        //원
        Ellipse(hdc, x1, y1, x2, y2);
        break;
    case 3:
        //사각형
        Rectangle(hdc, x1, y1, x2, y2);
        break;
    case 4:
        //타원사각형
        RoundRect(hdc, x1, y1, x2, y2, 20, 20);
        break;
    }

    SelectObject(hdc, oldPen);
    SelectObject(hdc, oldBrush);

    DeleteObject(newBrush);
    DeleteObject(newPen);

	ReleaseDC(hWnd, hdc);
}