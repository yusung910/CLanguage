#include "SetTool.h"
//툴 버튼을 클릭할 경우
//해당 툴을 사용할 준비와 미리보기를 생성한다.
void SetTool(HWND hWnd, int N_TOOL, int N_PEN, int N_BRUSH, int n_tool, COLORREF pColor, COLORREF brColor, int n_pBorder) {

    HDC hdc;
    PAINTSTRUCT ps;
    HPEN newPen, oldPen;
    HBRUSH newBrush, oldBrush;

    hdc = GetDC(hWnd);

    //미리보기 영역 500, 30, 750, 235
    //미리보기 영역 클리어
    newPen = CreatePen(PS_SOLID, 1, RGB(200, 200, 200));
    oldPen = SelectObject(hdc, newPen);

    //문자열 디자인 영역
    SelectObject(hdc, GetStockObject(WHITE_BRUSH));
    Rectangle(hdc, 500, 30, 750, 235);

    newPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
    oldPen = SelectObject(hdc, newPen);

    //미리보기 타이틀 출력
    TextOut(hdc, 520, 23, "미리보기", 8);
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

    //미리보기
    oldBrush = (HBRUSH)SelectObject(hdc, newBrush);

    switch (N_TOOL) {
    case 0:
        //펜
        MoveToEx(hdc, 550, 80, NULL);

        LineTo(hdc, 560, 150);
        LineTo(hdc, 590, 170);
        LineTo(hdc, 670, 180);
        LineTo(hdc, 690, 200);

        break;
    case 1:
        //직선
        MoveToEx(hdc, 510, 40, NULL);
        LineTo(hdc, 740, 225);
        break;
    case 2:
        //원
        Ellipse(hdc, 550, 90, 690, 175);
        break;
    case 3:
        //사각형
        Rectangle(hdc, 550, 90, 690, 175);
        break;
    case 4:
        //타원사각형
        RoundRect(hdc, 550, 90, 690, 175, 20, 20);
        break;
    }

    SelectObject(hdc, oldPen);
    DeleteObject(newPen);

    SelectObject(hdc, oldBrush);
    DeleteObject(newBrush);

    EndPaint(hWnd, &ps);
}