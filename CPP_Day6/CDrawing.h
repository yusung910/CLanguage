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
	NEXT_DUNGEON_LVL,
	PREV_DUNGEON_LVL,
};

enum E_DISPLAY {
    GAME = 1,
    SYSTEM,
    MAP_TITLE
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
    int m_nScreenX = 80;
    //ȭ�� Y ��
    int m_nScreenY = 30;
    //���� �÷��� ȭ�� ����
    COORD m_cdPlayScreenStart = { 2, 1 };
    //���� �÷��� ȭ�� ����
    COORD m_cdPlayScreenEnd = { 76, 19 };
    //�ý��� �޽��� ȭ�� ����
    COORD m_nSystemScreenStart = { 2, 21 };
    //�ý��� �޽��� ȭ�� ����
    COORD m_nSystemScreenEnd = { 76, 28 };

    //�� Ÿ��Ʋ ���� 
    COORD m_nMapTitleStart = { 2, 21 };
    COORD m_nMapTitleEnd = { 76, 21 };
};