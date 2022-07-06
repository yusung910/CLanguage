#include "Drawing.h"

Drawing::Drawing() {
    m_Handle = GetStdHandle(STD_OUTPUT_HANDLE);

    if (m_Handle == INVALID_HANDLE_VALUE) cout << "Err, INVALID_HANDLE_VALUE\n";
};

Drawing::Drawing(HANDLE hd) {
    m_Handle = hd;
};

Drawing::~Drawing() {
    m_Handle = NULL;
}

void Drawing::Locate() {
    COORD cdPos = { n_posX, n_posY };

    SetConsoleCursorPosition(m_Handle, cdPos);
}

void Drawing::Locate(int x, int y) {
    COORD cdPos = { x, y };

    SetConsoleCursorPosition(m_Handle, cdPos);
}

void Drawing::Locate(COORD pos) {
	SetConsoleCursorPosition(m_Handle, pos);
}

void Drawing::HideConsoleCursor() {
    //커서 숨기기
    cursorInfo.dwSize = 1; //커서 굵기 (1 ~ 100)
    cursorInfo.bVisible = FALSE; //커서 Visible TRUE(보임) FALSE(숨김)

    //커서 세팅
    SetConsoleCursorInfo(m_Handle, &cursorInfo);
}

void Drawing::ShowConsoleCursor() {
    //커서 숨기기
    cursorInfo.dwSize = 1; //커서 굵기 (1 ~ 100)
    cursorInfo.bVisible = TRUE; //커서 Visible TRUE(보임) FALSE(숨김)

    //커서 세팅
    SetConsoleCursorInfo(m_Handle, &cursorInfo);
}

void Drawing::PrintCtnt(int x, int y) {
    SetPos(x, y);
    Locate();
    Display();
}

void Drawing::PrintCtnt(int x, int y, const char* s) {
    SetPos(x, y);
    SetString(s);
    Locate();
    Display();
}

void Drawing::PrintCtnt(int x, int y, int n) {
	switch (n) {
	case E_BG_TILE::WALL_VERTICAL:
		PrintCtnt(x, y, "│");
		break;
	case E_BG_TILE::WALL_HORIZONTAL:
		PrintCtnt(x, y, "─");
		break;
	case E_BG_TILE::WALL_LEFT_TOP:
		PrintCtnt(x, y, "┌");
		break;
	case E_BG_TILE::WALL_RIGHT_TOP:
		PrintCtnt(x, y, "┐");
		break;
	case E_BG_TILE::WALL_LEFT_BOTTOM:
		PrintCtnt(x, y, "└");
		break;
	case E_BG_TILE::WALL_RIGHT_BOTTOM:
		PrintCtnt(x, y, "┘");
		break;
	case E_BG_TILE::WALL_TYPE_A:
		PrintCtnt(x, y, "├");
		break;
	case E_BG_TILE::WALL_TYPE_B:
		PrintCtnt(x, y, "┤");
		break;
	case E_BG_TILE::WALL_TYPE_C:
		PrintCtnt(x, y, "┴");
		break;
	case E_BG_TILE::WALL_TYPE_D:
		PrintCtnt(x, y, "┬");
		break;
	case E_BG_TILE::WALL_TYPE_E:
		PrintCtnt(x, y, "┼");
		break;
	}
}

void Drawing::PrintCtnt(int x, int y, int n, bool bDevMod) {
	char c = n + 48;
	SetPos(x, y);
	SetString(c, 1);
	Locate();
	Display();
}

void Drawing::ClearArea(int n) {
	COORD cdStart;
	COORD cdEnd;
	switch (n) {
	case 1:
		cdStart = cdArea1Start;
		cdEnd = cdArea1end;
		break;
	case 2:
		cdStart = cdArea2Start;
		cdEnd = cdArea2end;
		break;
	case 3:
		cdStart = cdArea3Start;
		cdEnd = cdArea3end;
		break;
	case 4:
		cdStart = cdArea4Start;
		cdEnd = cdArea4end;
		break;
	}

	for (int i = cdStart.X; i < cdEnd.X; i++) {
		for (int j = cdStart.Y; j < cdEnd.Y; j++) {
			PrintCtnt(i, j, " ");
			m_nBackground[j][i] = E_BG_TILE::LAND;
		}
	}
}

void Drawing::PrintCtntCenter(int y, String s) {
    int x = (m_nDisplayX - s.GetLength()) / 2;
    PrintCtnt(x, y, s.GetString());
}

void Drawing::DisplayClear() {
    system("cls");
}


void Drawing::PrintPlayerInfo(Player* player) {
    int* pBasicStat = player->GetBasicStat();
    Locate(118, 39);
    cout << "이름 : ";
    player->DisplayName();
    Locate(118, 40);
    cout << "레벨 : " << pBasicStat[E_CREATURE_BASIC_STAT::LEVEL];
    Locate(118, 41);
    cout << "체력 : " << pBasicStat[E_CREATURE_BASIC_STAT::HP];
    Locate(118, 42);
    cout << "마나 : " << pBasicStat[E_CREATURE_BASIC_STAT::MANA];
    Locate(118, 43);
    cout << "경험치 : " << player->GetExp();
    Locate(118, 44);
    cout << "소지금 : " << player->GetGold();
}

void Drawing::MovingPlayerIcon(COORD pos) {
	Locate(pos);
	cout << "◎";
};

void Drawing::MovingPlayerIcon(COORD prevPos, COORD nextPos) {
	Locate(prevPos);
	cout << "  ";
	Locate(nextPos);
	cout << "◎";
};