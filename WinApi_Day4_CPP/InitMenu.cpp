#include "InitMenu.h"

InitMenu::InitMenu() {
    //������

}

InitMenu::~InitMenu() {
    //�Ҹ���
}

void InitMenu::SetClientSize(HWND hWnd) {
    //Ŭ���̾�Ʈ ����� ����Ѵ�.
    GetClientRect(hWnd, &winRec);
    clientX = winRec.right;
    clientY = winRec.bottom;
}



void InitMenu::DrawTool(HWND hWnd) {
    hdc = BeginPaint(hWnd, &ps);

    newPen = CreatePen(PS_SOLID, 1, RGB(200, 200, 200));
    oldPen = (HPEN) SelectObject(hdc, newPen);

    // LineTo, PolyLineTo ���� �Լ��� ���� ���� ��ǥ�� ����Ѵ�
    MoveToEx(hdc, 0, nToolBarHeight, NULL);	// ���� ��ǥ�� �����ޱ� ���� POINT����ü�� ������
    // ���� ��ġ���� �������� ���� �ߴ´�. �̶� ������ ������ ���ܵȴ�
    LineTo(hdc, clientX, nToolBarHeight);

    //������ �� �ִ� �޴� ���� ���
    DrawBoundary(hdc, nDrawToolBoundaryList, ((sizeof(nDrawToolBoundaryList)) / 4) / 4);
    DrawBoundary(hdc, nLineToolBoundaryList, ((sizeof(nLineToolBoundaryList)) / 4) / 4);
    DrawBoundary(hdc, nBrushToolBoundaryList, ((sizeof(nBrushToolBoundaryList)) / 4) / 4);
    DrawBoundary(hdc, nEraseToolBoundaryList, ((sizeof(nToolBoundaryList)) / 4) / 4);
    DrawBoundary(hdc, nToolBoundaryList, ((sizeof(nToolBoundaryList)) / 4) / 4);
    
    newPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
    oldPen = (HPEN)SelectObject(hdc, newPen);

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
    oldPen = (HPEN) SelectObject(hdc, newPen);
    MoveToEx(hdc, 35, 110, NULL);
    LineTo(hdc, 80, 155);

    //�� ����3 ������ �׸���
    newPen = CreatePen(PS_DOT, 1, RGB(0, 0, 0));
    oldPen = (HPEN) SelectObject(hdc, newPen);
    MoveToEx(hdc, 95, 110, NULL);
    LineTo(hdc, 140, 155);

    //�� ����4 ������ �׸���
    newPen = CreatePen(PS_DASHDOT, 1, RGB(0, 0, 0));
    oldPen = (HPEN) SelectObject(hdc, newPen);
    MoveToEx(hdc, 215, 110, NULL);
    LineTo(hdc, 260, 155);

    //�� ����5 ������ �׸���
    newPen = CreatePen(PS_DASHDOTDOT, 1, RGB(0, 0, 0));
    oldPen = (HPEN) SelectObject(hdc, newPen);
    MoveToEx(hdc, 275, 110, NULL);
    LineTo(hdc, 320, 155);

    //�귯�� ���� ������ �׸���
    newPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
    oldPen = (HPEN) SelectObject(hdc, newPen);

    SelectObject(hdc, GetStockObject(BLACK_BRUSH));
    Ellipse(hdc, 35, 185, 80, 230);

    //�귯�� ����1 ������ �׸���
    for (int i = 0; i < 6; i++) {
        int n_icon = ((i + 1) * 60) + 35;
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

void InitMenu::DrawBoundary(HDC hdc, int(*n_posList)[4], int size) {
    for (int i = 0; i < size; i++) {
        Rectangle(hdc, n_posList[i][0], n_posList[i][1], n_posList[i][2], n_posList[i][3]);
    }
}

BOOL InitMenu::GetMouseToolFlag(LPARAM lParam) {
    BOOL retBool = FALSE;
    n_mouseX = (short)LOWORD(lParam);
    n_mouseY = (short)HIWORD(lParam);

    if (GetPosFlag(nDrawToolBoundaryList, ((sizeof(nDrawToolBoundaryList)) / 4) / 4) || 
        GetPosFlag(nLineToolBoundaryList, ((sizeof(nLineToolBoundaryList)) / 4) / 4) ||
        GetPosFlag(nBrushToolBoundaryList, ((sizeof(nBrushToolBoundaryList)) / 4) / 4) ||
        GetPosFlag(nTextToolBtnPosList, ((sizeof(nTextToolBtnPosList)) / 4) / 4)) {
        SetCursor(LoadCursor(NULL, IDC_HAND));
        retBool = TRUE;
    }

    return retBool;
};

BOOL InitMenu::GetPosFlag(int(*n_posList)[4], int size) {
    BOOL retBool = FALSE;
    for (int i = 0; i < size; i++) {
        if (n_mouseX > n_posList[i][0] &&
            n_mouseX < n_posList[i][2] &&
            n_mouseY > n_posList[i][1] &&
            n_mouseY < n_posList[i][3]) {
            retBool = TRUE;
        }
    }

    return retBool;
}