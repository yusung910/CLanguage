#pragma once
#include <windows.h>
#include "__debug.h"

class InitMenu {
public :
    //������
    InitMenu();
    //�Ҹ���
    ~InitMenu();

    //Ŭ���̾�Ʈ ũ�� ����
    void SetClientSize(HWND hWnd);

    //�� ��ư �׸���
    void DrawTool(HWND hWnd);

    //���� �׸���
    void DrawBoundary(HDC hdc, int(*n_posList)[4], int size);

    //���콺 ��ġ ����
    BOOL GetMouseToolFlag(LPARAM lParam);

    //���콺 Ŀ�� ��ġ�� tool �������� Ȯ��
    BOOL GetPosFlag(int(*n_posList)[4], int size);

protected:
    HDC hdc;
    PAINTSTRUCT ps;
    HPEN newPen, oldPen;
    HBRUSH newBrush, oldBrush;
    //������ ������
    RECT winRec;

    int clientX, clientY;
    //���콺 Ŀ�� ��ġ
    int n_mouseX, n_mouseY;

    //�귯�� ��Ÿ�� ����
    int nHS[6] = { HS_HORIZONTAL, HS_VERTICAL,
                   HS_BDIAGONAL,  HS_FDIAGONAL,
                   HS_CROSS,      HS_DIAGCROSS };
    //���� ���� ����
    int nToolBarHeight = 255;

    //��ư ������
    int nToolBtnSize = 55;

    //�̸����� ���� ������
    int nPreviewSize = 200;

    //���� ������ ���� ��ġ
    int nDrawToolBoundaryList[5][4] = {
        {30, 30, 30 + nToolBtnSize, 30 + nToolBtnSize},        //��
        {90, 30, 90 + nToolBtnSize, 30 + nToolBtnSize},        //����
        {150, 30, 150 + nToolBtnSize, 30 + nToolBtnSize},      //��
        {210, 30, 210 + nToolBtnSize, 30 + nToolBtnSize},      //�簢��
        {270, 30, 270 + nToolBtnSize, 30 + nToolBtnSize},      //���� �簢��
    };

    int nLineToolBoundaryList[5][4] = {
        {30, 105, 30 + nToolBtnSize, 105 + nToolBtnSize},      //�� �׸��� Ÿ��1
        {90, 105, 90 + nToolBtnSize, 105 + nToolBtnSize},      //�� �׸��� Ÿ��2
        {150, 105, 150 + nToolBtnSize, 105 + nToolBtnSize},    //�� �׸��� Ÿ��3
        {210, 105, 210 + nToolBtnSize, 105 + nToolBtnSize},    //�� �׸��� Ÿ��4
        {270, 105, 270 + nToolBtnSize, 105 + nToolBtnSize},    //�� �׸��� Ÿ��5
    };

    int nBrushToolBoundaryList[7][4] = {
        {30, 180, 30 + nToolBtnSize, 180 + nToolBtnSize},      //�귯�� Ÿ��1
        {90, 180, 90 + nToolBtnSize, 180 + nToolBtnSize},      //�귯�� Ÿ��2
        {150, 180, 150 + nToolBtnSize, 180 + nToolBtnSize},     //�귯�� Ÿ��3
        {210, 180, 210 + nToolBtnSize, 180 + nToolBtnSize},     //�귯�� Ÿ��4
        {270, 180, 270 + nToolBtnSize, 180 + nToolBtnSize},     //�귯�� Ÿ��5
        {330, 180, 330 + nToolBtnSize, 180 + nToolBtnSize},     //�귯�� Ÿ��6
        {390, 180, 390 + nToolBtnSize, 180 + nToolBtnSize},     //�귯�� Ÿ��7
    };

    int nEraseToolBoundaryList[2][4] = {
        {1260, 180, 1260 + nToolBtnSize, 180 + nToolBtnSize},    //���찳
        {1325, 180, 1325 + nToolBtnSize, 180 + nToolBtnSize},    //��ü ���찳
    };

    int nTextToolBtnPosList[3][4] = {
        {350, 50, 450, 70},
        {350, 90, 450, 110},
        {350, 130, 470, 150},
    };

    int nToolBoundaryList[5][4] = {
        {500, 30, 500 + nPreviewSize + 55, 30 + nPreviewSize},      //�̸����� ����
        {770, 30, 1070, 165},      //�� RGB ��ũ�� ����
        {1080, 30, 1380, 165},     //�귯�� RGB ��ũ�� ����
        {770, 180, 1050, 215},     //�� �β� ��ũ�� ����
        {340, 30, 490, 160}, //���ڿ� ��� ��ư ����
    };
private:

};