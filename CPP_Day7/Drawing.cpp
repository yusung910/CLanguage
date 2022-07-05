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
		PrintCtnt(x, y, "¦¢");
		break;
	case E_BG_TILE::WALL_HORIZONTAL:
		PrintCtnt(x, y, "¦¡");
		break;
	case E_BG_TILE::WALL_LEFT_TOP:
		PrintCtnt(x, y, "¦£");
		break;
	case E_BG_TILE::WALL_RIGHT_TOP:
		PrintCtnt(x, y, "¦¤");
		break;
	case E_BG_TILE::WALL_LEFT_BOTTOM:
		PrintCtnt(x, y, "¦¦");
		break;
	case E_BG_TILE::WALL_RIGHT_BOTTOM:
		PrintCtnt(x, y, "¦¥");
		break;
	case E_BG_TILE::WALL_TYPE_A:
		PrintCtnt(x, y, "¦§");
		break;
	case E_BG_TILE::WALL_TYPE_B:
		PrintCtnt(x, y, "¦©");
		break;
	case E_BG_TILE::WALL_TYPE_C:
		PrintCtnt(x, y, "¦ª");
		break;
	case E_BG_TILE::WALL_TYPE_D:
		PrintCtnt(x, y, "¦¨");
		break;
	case E_BG_TILE::WALL_TYPE_E:
		PrintCtnt(x, y, "¦«");
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