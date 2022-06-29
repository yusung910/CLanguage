#include "CDrawing.h"

CDrawing::CDrawing() {
//2차원 배열의 지형을 기본값(LAND = 0)으로 세팅한다.
    for (int i = 0; i < m_nScreenY; i++) {
        memset(m_nLend[i], E_BACKGROUND::LAND, m_nScreenX);
    }
};

CDrawing::~CDrawing() {

}

void CDrawing::PrintDisplayRound() {

    //테두리 출력
    SetPos(0, 0);
    cout << "┌";
    for (int a = 1; a < (m_nScreenX - 2); a++) {
        SetPos(a, 0);
        cout << "─";
    }

    SetPos(78, 0);
    cout << "┐";

    for (int b = 1; b < (m_nScreenY - 1); b++) {
        SetPos(m_nScreenX - 2, b);
        cout << "│";
    }
    SetPos(m_nScreenX - 2, 29);
    cout << "┘";

    for (int c = (m_nScreenX - 3); c >= 1; c--) {
        SetPos(c, (m_nScreenY - 1));
        cout << "─";
    }

    SetPos(0, 29);
    cout << "└";

    for (int d = (m_nScreenY - 2); d >= 1; d--) {
        SetPos(0, d);
        cout << "│";
    }

    //시스템 메뉴를 출력하는 영역을 그린다.
    SetPos(0, 20);
    cout << "├";
    SetPos((m_nScreenX-2), 20);
    cout << "┤";

    for (int e = 1; e < (m_nScreenX - 2); e++) {
        SetPos(e, 20);
        cout << "─";
    }

    for (int i = 0; i < m_nScreenX; i++) {
        //m_nLend[30][80];
        m_nLend[0][i] = E_BACKGROUND::WALL;
        m_nLend[1][i] = E_BACKGROUND::WALL;

        m_nLend[19][i] = E_BACKGROUND::WALL;
        m_nLend[20][i] = E_BACKGROUND::WALL;

        m_nLend[m_nScreenY - 1][i] = E_BACKGROUND::WALL;
        m_nLend[m_nScreenY - 2][i] = E_BACKGROUND::WALL;
    }

    for (int j = 0; j < m_nScreenY; j++) {
        m_nLend[j][0] = E_BACKGROUND::WALL;
        m_nLend[j][1] = E_BACKGROUND::WALL;

        m_nLend[j][m_nScreenX - 1] = E_BACKGROUND::WALL;
        m_nLend[j][m_nScreenX - 2] = E_BACKGROUND::WALL;
        m_nLend[j][m_nScreenX - 3] = E_BACKGROUND::WALL;
    }
}

void CDrawing::PrintDisplayMenu() {
	//메인 화면에서 플레이어가 선택할 수 있는 메뉴를 출력한다.
	SetPos(GetStringCenterX("새로하기"), 23);
	CString("새로하기").Display();
	SetPos(GetStringCenterX("이어하기"), 24);
	CString("이어하기").Display();
	SetPos(GetStringCenterX("Credit"), 25);
	CString("Credit").Display();
};

void CDrawing::PrintSelectedMenu(int n, bool bDrawingFlag) {

	int n_arrowPosX = 0;
	int n_arrowPosY = 0;

	switch (n) {
		case E_MAIN_MENU::NEW_GAME:
			n_arrowPosX = GetStringCenterX("새로하기") - 4;
			n_arrowPosY = 23;
		break;
		case E_MAIN_MENU::CONTINUE_GAME:
			n_arrowPosX = GetStringCenterX("이어하기") - 4;
			n_arrowPosY = 24;
		break;
		case E_MAIN_MENU::CREDIT:
			n_arrowPosX = GetStringCenterX("Credit") - 4;
			n_arrowPosY = 25;
		break;
	}

	SetPos(n_arrowPosX, n_arrowPosY);
	if (bDrawingFlag) {
		cout << "◆";
	}
	else {
		cout << "  ";
	}
	
};

void CDrawing::ClearDisplay(int n) {
    COORD cdClearStart;
    COORD cdClearEnd;

    if (n == E_DISPLAY::GAME) {
        cdClearStart = m_cdPlayScreenStart;
        cdClearEnd = m_cdPlayScreenEnd;
    }
    else if (n == E_DISPLAY::SYSTEM) {
        cdClearStart = m_nSystemScreenStart;
        cdClearEnd = m_nSystemScreenEnd;
    }
    else if (n == E_DISPLAY::MAP_TITLE) {
        cdClearStart = m_nMapTitleStart;
        cdClearEnd = m_nMapTitleEnd;
    }

    for (int i = cdClearStart.X; i <= cdClearEnd.X; i++) {
        for (int j = cdClearStart.Y; j <= cdClearEnd.Y; j++) {
            SetPos(i,j);
            cout << " ";
            m_nLend[j][i] = E_BACKGROUND::LAND;
        }
    }
}

int CDrawing::GetStringCenterX(const char* s) {
	int n_strLength = strlen(s);
	return (m_nScreenX - n_strLength) / 2;
}

int CDrawing::GetStringCenterX(int n) {
	return (m_nScreenX - n) / 2;
}

//마을을 그리는 함수
void CDrawing::PrintVillageBackground() {
	PrintDisplayRound();
	//여관 사각형 건물 그리기
	PrintSquare({ 12, 6 }, { 26, 14 });
	//문 그리기
	PrintDoor({ 14, 14 }, { 23, 14 }, E_BACKGROUND::BUILD_INN);
	//여관 타이틀 출력
	SetPos(18, 8);
	CString("여관").Display();

	//상점
	PrintSquare({ 31, 6 }, { 45, 14 });
	//문 그리기
	PrintDoor({ 33, 14 }, { 42, 14 }, E_BACKGROUND::BUILD_STORE);
	//상점 타이틀 출력
	SetPos(37, 8);
	CString("상점").Display();

	//던전
	PrintSquare({ 50, 6 }, { 64, 14 });
	//문 그리기
	PrintDoor({ 52, 14 }, { 61, 14 }, E_BACKGROUND::BUILD_DUNGEON);
	//던전 타이틀 출력
	SetPos(56, 8);
	CString("던전").Display();

    //시스템메세지 영역에 현재 위치를 출력
    ClearDisplay(E_DISPLAY::MAP_TITLE);
    SetPos(10, 21);
    cout << "현재 위치 : 마을";
}

void CDrawing::PrintSquare(COORD cdPosA, COORD cdPosB) {
	COORD cdPointA = cdPosA;
	COORD cdPointB = { cdPosB.X, cdPosA.Y };
	COORD cdPointC = cdPosB;
	COORD cdPointD = { cdPosA.X, cdPosB.Y };

	PrintBorderLine(cdPointA, cdPointB, 1);
	PrintBorderLine(cdPointB, cdPointC, 2);
	PrintBorderLine(cdPointD, cdPointC, 3);
	PrintBorderLine(cdPointA, cdPointD, 4);

	PrintChar(cdPointA, CString("┌"), E_BACKGROUND::WALL);
	PrintChar(cdPointB, CString("┐"), E_BACKGROUND::WALL);
	PrintChar(cdPointC, CString("┘"), E_BACKGROUND::WALL);
	PrintChar(cdPointD, CString("└"), E_BACKGROUND::WALL);
}


//사각형의 직선을 그리는 함수
//n_side 그려질 면의 번호
void CDrawing::PrintBorderLine(COORD cdPosA, COORD cdPosB, int n_side) {

	int a = (n_side == 1 || n_side == 3) ? cdPosA.X : cdPosA.Y;
	int b = (n_side == 1 || n_side == 3) ? cdPosB.X : cdPosB.Y;

	int c = (n_side == 1 || n_side == 3) ? cdPosA.Y : cdPosA.X;
    int c_1;

    switch (n_side) {
    case 1:
        c_1 = c + 1;
        break;
    case 2:
        c_1 = c + 1;
        break;
    case 3:
        c_1 = c - 1;
        break;
    case 4:
        c_1 = c - 1;
        break;
    }
    
	for (int i = a; i <= b; i++) {
		if (n_side == 1 || n_side == 3) {
			SetPos(i, c);
			m_nLend[c][i] = E_BACKGROUND::WALL;
            m_nLend[c_1][i] = E_BACKGROUND::WALL;
			cout << "─";
		}
		else {
			SetPos(c, i);
			m_nLend[i][c] = E_BACKGROUND::WALL;
            m_nLend[i][c_1] = E_BACKGROUND::WALL;
			cout << "│";
		}
	}

}

void CDrawing::PrintChar(COORD pos, CString s, int n_bgType) {
	SetPos(pos);
	s.Display();
}

void CDrawing::PrintDoor(COORD posA, COORD posB, int n_DoorType) {
	for (int i = posA.X; i <= posB.X; i++) {
		for (int j = posA.Y; j <= posB.Y; j++) {
			SetPos(i, j);
			cout << "  ";
			m_nLend[j][i] = n_DoorType;
		}
	}
    m_nLend[posA.Y][posA.X] = E_BACKGROUND::WALL;
}