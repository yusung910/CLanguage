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
    //Ŀ�� �����
    cursorInfo.dwSize = 1; //Ŀ�� ���� (1 ~ 100)
    cursorInfo.bVisible = FALSE; //Ŀ�� Visible TRUE(����) FALSE(����)

    //Ŀ�� ����
    SetConsoleCursorInfo(m_Handle, &cursorInfo);
}

void Drawing::ShowConsoleCursor() {
    //Ŀ�� �����
    cursorInfo.dwSize = 1; //Ŀ�� ���� (1 ~ 100)
    cursorInfo.bVisible = TRUE; //Ŀ�� Visible TRUE(����) FALSE(����)

    //Ŀ�� ����
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
    case E_BG_TILE::CHARACTOR:
        PrintCtnt(x, y, "��");
        break;
    case E_BG_TILE::LAND:
        PrintCtnt(x, y, " ");
        break;
	case E_BG_TILE::WALL_VERTICAL:
		PrintCtnt(x, y, "��");
		break;
	case E_BG_TILE::WALL_HORIZONTAL:
		PrintCtnt(x, y, "��");
		break;
	case E_BG_TILE::WALL_LEFT_TOP:
		PrintCtnt(x, y, "��");
		break;
	case E_BG_TILE::WALL_RIGHT_TOP:
		PrintCtnt(x, y, "��");
		break;
	case E_BG_TILE::WALL_LEFT_BOTTOM:
		PrintCtnt(x, y, "��");
		break;
	case E_BG_TILE::WALL_RIGHT_BOTTOM:
		PrintCtnt(x, y, "��");
		break;
	case E_BG_TILE::WALL_TYPE_A:
		PrintCtnt(x, y, "��");
		break;
	case E_BG_TILE::WALL_TYPE_B:
		PrintCtnt(x, y, "��");
		break;
	case E_BG_TILE::WALL_TYPE_C:
		PrintCtnt(x, y, "��");
		break;
	case E_BG_TILE::WALL_TYPE_D:
		PrintCtnt(x, y, "��");
		break;
	case E_BG_TILE::WALL_TYPE_E:
		PrintCtnt(x, y, "��");
		break;
	}
}

void Drawing::PrintCtnt(int x, int y, int n, bool bDevMod) {
	char c = (n == 0) ? ' ' : n + 48;
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
    //Locate(120, 38);
    //cout << "�̸� : ";
    //player->DisplayName();
    //Locate(120, 39);
    //cout << "���� : " << pBasicStat[E_CREATURE_BASIC_STAT::LEVEL];
    //Locate(120, 40);
    //cout << "ü�� : " << pBasicStat[E_CREATURE_BASIC_STAT::HP];
    //Locate(120, 41);
    //cout << "���� : " << pBasicStat[E_CREATURE_BASIC_STAT::MANA];
    //Locate(120, 42);
    //cout << "����ġ : " << player->GetExp();
    //Locate(120, 43);
    //cout << "������ : " << player->GetGold();
}

void Drawing::PrintCoord(COORD cd) {
    PrintCtnt(120, 44, "x : ");
    Locate(123, 44);
    cout << "    ";
    Locate(123, 44);
    cout << cd.X;
    PrintCtnt(120, 45, "y : ");
    Locate(123, 45);
    cout << "    ";
    Locate(123, 45);
    cout << cd.Y;
}

BOOL Drawing::CompareCoord(COORD a, COORD b) {
    return (a.X == b.X && a.Y == b.Y) ? true : false;
}