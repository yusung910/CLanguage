#pragma once
#include <windows.h>

#include "Point.h"
#include "String.h"
#include "Player.h"

using namespace std;

enum E_BG_TILE {
    LAND = 0,
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

    //커서 위치
    void Locate(void);
    void Locate(int x, int y);
	void Locate(COORD pos);

    //커서 숨기기
    void HideConsoleCursor();
    //커서 보여주기
    void ShowConsoleCursor();

    //문자 출력 함수
    void PrintCtnt(int x, int y);
    void PrintCtnt(int x, int y, const char* chr);
    void PrintCtnt(int x, int y, int n);

	//개발자 모드
	void PrintCtnt(int x, int y, int n, bool bDevMod);

    //플레이어 정보 우측하단 출력
    void PrintPlayerInfo(Player* player);

    //센터정렬 출력
    void PrintCtntCenter(int y, String s);
	//구역별로 화면을 클리어하는 함수
	void ClearArea(int n);
    void DisplayClear();

	//플래이어 아이콘을 이동한다
	void MovingPlayerIcon(COORD pos);
	void MovingPlayerIcon(COORD prevPos, COORD nextPos);
protected:
	//배경 정보
	int m_nBackground[50][150];
	//화면 x
	int m_nDisplayX = 150;
	//화면 y
	int m_nDisplayY = 50;

	COORD cdArea1Start = {2,2};
	COORD cdArea1end = {114, 34};

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
    //콘솔 커서 객체
    CONSOLE_CURSOR_INFO cursorInfo = { 0, };
};