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

	//변수에 따른 배경을 그린다.
	void PrintVillageBackground();

    //매개변수에 따라 게임플레이 화면 또는 시스템메세지 화면을 클리어한다.
    void ClearDisplay(int n);

	//다른 함수들을 이용한 스퀘어 그리기 함수
	void PrintSquare(COORD cdPosA, COORD cdPosB);
	//v_flag에 따라 a,b 값에 해당하는 가로선 또는 세로선을 그린다
	void PrintBorderLine(COORD cdPosA, COORD cdPosB, int n_side);
	void PrintChar(COORD pos, CString s, int n_bgType);
	//일부 영역에 다른 맵으로 이동할 문을 그린다.
	void PrintDoor(COORD posA, COORD posB, int n_DoorType);
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