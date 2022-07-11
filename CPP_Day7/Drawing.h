#pragma once
#include <windows.h>

#include "Point.h"
#include "String.h"
#include "Player.h"

using namespace std;

enum E_BG_TILE {
    LAND = 0,
    E_DOOR_DUNGEON,
    E_DOOR_VILLAGE,
    E_DOOR_STORE,
    E_DOOR_INN,
    CHARACTOR,
    WALL,
    WALL_VERTICAL,  
    WALL_HORIZONTAL,
    WALL_LEFT_TOP,  
    WALL_RIGHT_TOP, 
    WALL_LEFT_BOTTOM,
    WALL_RIGHT_BOTTOM,
	WALL_TYPE_A,
	WALL_TYPE_B,
	WALL_TYPE_C,
	WALL_TYPE_D,
	WALL_TYPE_E,
	BG_MAX_CNT,
};

class Drawing : public Point, public String
{

public:

    Drawing(HANDLE hd);
    Drawing();
    ~Drawing();

    //Ŀ�� ��ġ
    void Locate(void);
    void Locate(int x, int y);
	void Locate(COORD pos);

    //Ŀ�� �����
    void HideConsoleCursor();
    //Ŀ�� �����ֱ�
    void ShowConsoleCursor();

    //���� ��� �Լ�
    void PrintCtnt(int x, int y);
    void PrintCtnt(int x, int y, const char* chr);
    void PrintCtnt(int x, int y, int n);

	//������ ���
	void PrintCtnt(int x, int y, int n, bool bDevMod);

    //�÷��̾� ���� �����ϴ� ���
    void PrintPlayerInfo(Player* player);

    void PrintCoord(COORD cd);

    //�������� ���
    void PrintCtntCenter(int y, String s);
	//�������� ȭ���� Ŭ�����ϴ� �Լ�
	void ClearArea(int n);
    void DisplayClear();

    //coord ���� ���Ͽ� ����
    BOOL CompareCoord(COORD a, COORD b);

protected:
	//��� ����
	int m_nBackground[50][150];
	//ȭ�� ũ�� x
	int m_nDisplayX = 150;
	//ȭ�� ũ�� y
	int m_nDisplayY = 50;

	COORD cdArea1Start = {2, 2};
	COORD cdArea1end = {114, 34};

    int cdArea1CenterX = (cdArea1end.X - cdArea1Start.X) / 2;
    int cdArea1CenterY = (cdArea1end.Y - cdArea1Start.Y) / 2;

	COORD cdArea2Start = { 117,3 };
	COORD cdArea2end = { 148, 33 };

	COORD cdArea3Start = { 2,36 };
	COORD cdArea3end = { 114, 49 };

	COORD cdArea4Start = { 117, 37 };
	COORD cdArea4end = { 148, 48 };

    COORD cdArea5Start = { 0, 0 };
    COORD cdArea5end = { 150, 50 };



private:
    HANDLE m_Handle;
    //�ܼ� Ŀ�� ��ü
    CONSOLE_CURSOR_INFO cursorInfo = { 0, };
};