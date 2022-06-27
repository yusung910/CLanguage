#include "CDrawing.h"

CDrawing::CDrawing() {

    m_nScreenX = 80;
    m_nScreenY = 30;

    //플레이 영역 좌표 설정
    m_cdPlayScreenStart = { 2, 1 };
    m_cdPlayScreenEnd = { 77, 19 };

    //시스템 메세지 영역 좌표 설정
    m_nSystemScreenStart = { 2, 21 };
    m_nSystemScreenEnd = { 77, 28 };

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
