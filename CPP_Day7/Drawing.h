#pragma once
#include <windows.h>

#include "Point.h"
#include "String.h"

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

    void Locate(void);

    void PrintCtnt(int x, int y);
    void PrintCtnt(int x, int y, const char* chr);
    void PrintCtnt(int x, int y, int n);
	//개발자 모드
	void PrintCtnt(int x, int y, int n, bool bDevMod);
	//구역별로 화면을 클리어하는 함수
	void ClearArea(int n);

protected:

	int m_nBackground[50][150];
	int m_nDisplayX = 150;
	int m_nDisplayY = 50;

	COORD cdArea1Start = {2,2};
	COORD cdArea1end = {114, 34};

	COORD cdArea2Start = { 117,3 };
	COORD cdArea2end = { 148, 33 };

	COORD cdArea3Start = { 2,36 };
	COORD cdArea3end = { 114, 49 };

	COORD cdArea4Start = { 117, 37 };
	COORD cdArea4end = { 148, 48 };

private:
    HANDLE m_Handle;

};