#pragma once
#include "CPoint.h"
#include "CString.h"

enum E_BACKGROUND {
    LAND = 0,
    WALL, 
    DOOR,
	BUILD_INN,
	BUILD_STORE,
	BUILD_DUNGEON,
};

enum E_DISPLAY {
    GAME = 1,
    SYSTEM,
};

enum E_MAIN_MENU {
	NEW_GAME = 1,
	CONTINUE_GAME,
	CREDIT,
};

class CDrawing : public CPoint, public CString {
public:
    //������
    CDrawing();
    //�Ҹ���
    ~CDrawing();

    //���� ȭ���� �⺻ �׵θ��� �׸��� �Լ�
    void PrintDisplayRound();

	//����ȭ�鿡 ������ �޴��� ����Ѵ�
	void PrintDisplayMenu();

	//����ȭ���� ������ �޴��� �Ű������� �޾� �ش� �޴��� ���� ���θ� ����Ѵ�
	void PrintSelectedMenu(int n, bool bDrawingFlag);

	//������ ���� ����� �׸���.
	void PrintVillageBackground();

    //�Ű������� ���� �����÷��� ȭ�� �Ǵ� �ý��۸޼��� ȭ���� Ŭ�����Ѵ�.
    void ClearDisplay(int n);

	//�ٸ� �Լ����� �̿��� ������ �׸��� �Լ�
	void PrintSquare(COORD cdPosA, COORD cdPosB);
	//v_flag�� ���� a,b ���� �ش��ϴ� ���μ� �Ǵ� ���μ��� �׸���
	void PrintBorderLine(COORD cdPosA, COORD cdPosB, int n_side);
	void PrintChar(COORD pos, CString s, int n_bgType);
	//�Ϻ� ������ �ٸ� ������ �̵��� ���� �׸���.
	void PrintDoor(COORD posA, COORD posB, int n_DoorType);
	//���ڿ��� �Ű������� �޾� ���̰��� ���� �߾������� ���� left ��ġ ���� ����Ѵ�
	int GetStringCenterX(const char* s);
	int GetStringCenterX(int n);

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