#include "InitDisplay.h"

void InitDisplay(HWND hWnd, int clientX, int clientY, int n_barSize) {
    

    HDC hdc;
    PAINTSTRUCT ps;
    HPEN newPen, oldPen;
    HBRUSH newBrush, oldBrush;

    static int nHS[6] = { HS_HORIZONTAL, HS_VERTICAL,
                          HS_BDIAGONAL,  HS_FDIAGONAL,
                          HS_CROSS,      HS_DIAGCROSS };

    hdc = BeginPaint(hWnd, &ps);
    
    newPen = CreatePen(PS_SOLID, 1, RGB(200, 200, 200));
    oldPen = SelectObject(hdc, newPen);

    // LineTo, PolyLineTo ���� �Լ��� ���� ���� ��ǥ�� ����Ѵ�
    MoveToEx(hdc, 0, n_barSize, NULL);	// ���� ��ǥ�� �����ޱ� ���� POINT����ü�� ������
    // ���� ��ġ���� �������� ���� �ߴ´�. �̶� ������ ������ ���ܵȴ�
    LineTo(hdc, clientX, n_barSize);

    //������ �� �ִ� �޴� ���
    //�� ���� ��ư
    Rectangle(hdc, 30, 30, 85, 85);
    //���� ���� ��ư
    Rectangle(hdc, 90, 30, 145, 85);
    //�� ���� ��ư
    Rectangle(hdc, 150, 30, 205, 85);
    //�簢�� ���� ��ư
    Rectangle(hdc, 210, 30, 265, 85);
    //���� �簢�� ���� ��ư
    Rectangle(hdc, 270, 30, 325, 85);

    //���׸��� Ÿ��1
    Rectangle(hdc, 30, 105, 85, 160);
    //���׸��� Ÿ��2
    Rectangle(hdc, 90, 105, 145, 160);
    //���׸��� Ÿ��3
    Rectangle(hdc, 150, 105, 205, 160);
    //���׸��� Ÿ��4
    Rectangle(hdc, 210, 105, 265, 160);
    //���׸��� Ÿ��5
    Rectangle(hdc, 270, 105, 325, 160);

    //�귯��1
    Rectangle(hdc, 30, 180, 85, 235);
    //�귯��2
    Rectangle(hdc, 90, 180, 145, 235);
    //�귯��3
    Rectangle(hdc, 150, 180, 205, 235);
    //�귯��4
    Rectangle(hdc, 210, 180, 265, 235);
    //�귯��5
    Rectangle(hdc, 270, 180, 325, 235);
    //�귯��6
    Rectangle(hdc, 330, 180, 385, 235);
    //�귯��7
    Rectangle(hdc, 390, 180, 445, 235);

    //�̸����� ���� �׸���
    Rectangle(hdc, 500, 30, 750, 235);

    //�� RGB ���� �׸���
    Rectangle(hdc, 770, 30, 1070, 165);

    //�귯�� RGB ���� �׸���
    Rectangle(hdc, 1080, 30, 1380, 165);

    //�� �β� ��ũ�� ���� �׸���
    Rectangle(hdc, 770, 180, 1050, 215);

	//���찳
	Rectangle(hdc, 1260, 180, 1315, 235);
	//ȭ�������
	Rectangle(hdc, 1325, 180, 1380, 235);

    //���ڿ� ������ ����
    Rectangle(hdc, 340, 30, 490, 160);

    newPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
    oldPen = SelectObject(hdc, newPen);

    //�̸����� Ÿ��Ʋ ���
    TextOut(hdc, 520, 23, "�̸�����", 8);

	//���찳 Ÿ��Ʋ ���
	TextOut(hdc, 1264, 200, "���찳", 6);

	//��ä���찳 Ÿ��Ʋ ���
	TextOut(hdc, 1329, 200, "�ʱ�ȭ", 6);

    //�ؽ�Ʈ ��� ��Ÿ�� Ÿ��Ʋ ���
    TextOut(hdc, 345, 25, "�ؽ�Ʈ ��Ÿ��", 13);
    TextOut(hdc, 350, 50, "�⺻ ���� ���", 14);
    TextOut(hdc, 350, 90, "���� ���� ���", 14);
    TextOut(hdc, 350, 130, "������ ���� ���", 16);

    //�� RGB Ÿ��Ʋ ���
    TextOut(hdc, 780, 23, "�� RGB", 6);
    SetTextColor(hdc, RGB(255, 0, 0));
    TextOut(hdc, 780, 52, "R", 1);
    SetTextColor(hdc, RGB(0, 255, 0));
    TextOut(hdc, 780, 92, "G", 1);
    SetTextColor(hdc, RGB(0, 0, 255));
    TextOut(hdc, 780, 132, "B", 1);

    //�� RGB Ÿ��Ʋ ���
    SetTextColor(hdc, RGB(0, 0, 0));
    TextOut(hdc, 1090, 23, "�귯�� RGB", 10);
    SetTextColor(hdc, RGB(255, 0, 0));
    TextOut(hdc, 1090, 52, "R", 1);
    SetTextColor(hdc, RGB(0, 255, 0));
    TextOut(hdc, 1090, 92, "G", 1);
    SetTextColor(hdc, RGB(0, 0, 255));
    TextOut(hdc, 1090, 132, "B", 1);

    //�� �β� ��ũ�� Ÿ��Ʋ ���
    SetTextColor(hdc, RGB(0, 0, 0));
    TextOut(hdc, 780, 170, "�� �β�", 7);

    //�� ������ �׸���
    MoveToEx(hdc, 35, 35, NULL);
    LineTo(hdc, 45, 50);
    LineTo(hdc, 55, 60);
    LineTo(hdc, 65, 70);
    LineTo(hdc, 80, 80);

    //���� �׸���
    MoveToEx(hdc, 95, 35, NULL);
    LineTo(hdc, 140, 80);

    //�� �׸���
    Ellipse(hdc, 155, 35, 200, 80);

    //�簢�� �׸���
    Rectangle(hdc, 215, 35, 260, 80);

    //Ÿ���簢��
    RoundRect(hdc, 275, 35, 320, 80, 10, 10);

    //�� ����1 ������ �׸���
    MoveToEx(hdc, 155, 110, NULL);
    LineTo(hdc, 200, 155);

    //�� ����2 ������ �׸���
    newPen = CreatePen(PS_DASH, 1, RGB(0, 0, 0));
    oldPen = SelectObject(hdc, newPen);
    MoveToEx(hdc, 35, 110, NULL);
    LineTo(hdc, 80, 155);

    //�� ����3 ������ �׸���
    newPen = CreatePen(PS_DOT, 1, RGB(0, 0, 0));
    oldPen = SelectObject(hdc, newPen);
    MoveToEx(hdc, 95, 110, NULL);
    LineTo(hdc, 140, 155);

    //�� ����4 ������ �׸���
    newPen = CreatePen(PS_DASHDOT, 1, RGB(0, 0, 0));
    oldPen = SelectObject(hdc, newPen);
    MoveToEx(hdc, 215, 110, NULL);
    LineTo(hdc, 260, 155);

    //�� ����5 ������ �׸���
    newPen = CreatePen(PS_DASHDOTDOT, 1, RGB(0, 0, 0));
    oldPen = SelectObject(hdc, newPen);
    MoveToEx(hdc, 275, 110, NULL);
    LineTo(hdc, 320, 155);

    //�귯�� ���� ������ �׸���
    newPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
    oldPen = SelectObject(hdc, newPen);

    SelectObject(hdc, GetStockObject(BLACK_BRUSH));
    Ellipse(hdc, 35, 185, 80, 230);

    //�귯�� ����1 ������ �׸���
    for (int i = 0; i < 6;i++) {
        int n_icon = ((i + 1) * 60 ) + 35;
        newBrush = CreateHatchBrush(nHS[i], RGB(0, 0, 0));
        oldBrush = (HBRUSH)SelectObject(hdc, newBrush);
        Ellipse(hdc, n_icon, 185, (n_icon + 45), 230);
        SelectObject(hdc, oldBrush);
        DeleteObject(newBrush);
    }

    SelectObject(hdc, oldPen);

    DeleteObject(newPen);



    EndPaint(hWnd, &ps);

    
}