#pragma once
#include "CPoint.h"
#include "CString.h"

enum E_BACKGROUND {
    LAND = 0,
    WALL, 
    DOOR,
};

enum E_DISPLAY {
    GAME = 1,
    SYSTEM,
};

class CDrawing : CPoint, CString {
public:
    //������
    CDrawing();
    //�Ҹ���
    ~CDrawing();

    //���� ȭ���� �⺻ �׵θ��� �׸��� �Լ�
    void PrintDisplayRound();

    //�Ű������� ���� �����÷��� ȭ�� �Ǵ� �ý��۸޼��� ȭ���� Ŭ�����Ѵ�.
    void ClearDisplay(int n);

    //�� ������ ����� 2���� �迭
    int m_nLend[30][80];
    //ȭ�� X ��
    int m_nScreenX;
    //ȭ�� Y ��
    int m_nScreenY;
    //���� �÷��� ȭ�� ����
    COORD m_cdPlayScreenStart;
    //���� �÷��� ȭ�� ����
    COORD m_cdPlayScreenEnd;
    //�ý��� �޽��� ȭ�� ����
    COORD m_nSystemScreenStart;
    //�ý��� �޽��� ȭ�� ����
    COORD m_nSystemScreenEnd;
};