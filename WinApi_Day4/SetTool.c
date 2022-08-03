#include "SetTool.h"
//�� ��ư�� Ŭ���� ���
//�ش� ���� ����� �غ�� �̸����⸦ �����Ѵ�.
void SetTool(HWND hWnd, int N_TOOL, int N_PEN, int N_BRUSH, int n_tool, COLORREF pColor, COLORREF brColor, int n_pBorder) {

    HDC hdc;
    PAINTSTRUCT ps;
    HPEN newPen, oldPen;
    HBRUSH newBrush, oldBrush;

    hdc = GetDC(hWnd);

    //�̸����� ���� 500, 30, 750, 235
    //�̸����� ���� Ŭ����
    newPen = CreatePen(PS_SOLID, 1, RGB(200, 200, 200));
    oldPen = SelectObject(hdc, newPen);

    //���ڿ� ������ ����
    SelectObject(hdc, GetStockObject(WHITE_BRUSH));
    Rectangle(hdc, 500, 30, 750, 235);

    newPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
    oldPen = SelectObject(hdc, newPen);

    //�̸����� Ÿ��Ʋ ���
    TextOut(hdc, 520, 23, "�̸�����", 8);
    //�� ����
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
    //�귯�� ����
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

    //�̸�����
    oldBrush = (HBRUSH)SelectObject(hdc, newBrush);

    switch (N_TOOL) {
    case 0:
        //��
        MoveToEx(hdc, 550, 80, NULL);

        LineTo(hdc, 560, 150);
        LineTo(hdc, 590, 170);
        LineTo(hdc, 670, 180);
        LineTo(hdc, 690, 200);

        break;
    case 1:
        //����
        MoveToEx(hdc, 510, 40, NULL);
        LineTo(hdc, 740, 225);
        break;
    case 2:
        //��
        Ellipse(hdc, 550, 90, 690, 175);
        break;
    case 3:
        //�簢��
        Rectangle(hdc, 550, 90, 690, 175);
        break;
    case 4:
        //Ÿ���簢��
        RoundRect(hdc, 550, 90, 690, 175, 20, 20);
        break;
    }

    SelectObject(hdc, oldPen);
    DeleteObject(newPen);

    SelectObject(hdc, oldBrush);
    DeleteObject(newBrush);

    EndPaint(hWnd, &ps);
}