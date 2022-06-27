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

enum E_MAIN_MENU {
	NEW_GAME = 1,
	CONTINUE_GAME,
	CREDIT,
};

class CDrawing : CPoint, CString {
public:
    //생성자
    CDrawing();
    //소멸자
    ~CDrawing();

    //게임 화면의 기본 테두리를 그리는 함수
    void PrintDisplayRound();

	//메인화면에 보여줄 메뉴를 출력한다
	void PrintDisplayMenu();

	//메인화면의 보여줄 메뉴를 매개변수로 받아 해당 메뉴의 선택 여부를 출력한다
	void PrintSelectedMenu(int n, bool bDrawingFlag);


    //매개변수에 따라 게임플레이 화면 또는 시스템메세지 화면을 클리어한다.
    void ClearDisplay(int n);

	

	//문자열을 매개변수로 받아 길이값에 따라 중앙정렬을 위한 left 위치 값을 계산한다
	int GetStringCenterX(const char* s);
	int GetStringCenterX(int n);

    //맵 지형이 저장될 2차원 배열
    int m_nLend[30][80];
    //화면 X 값
    int m_nScreenX;
    //화면 Y 값
    int m_nScreenY;
    //게임 플레이 화면 시작
    COORD m_cdPlayScreenStart;
    //게임 플레이 화면 종료
    COORD m_cdPlayScreenEnd;
    //시스템 메시지 화면 시작
    COORD m_nSystemScreenStart;
    //시스템 메시지 화면 종료
    COORD m_nSystemScreenEnd;
};