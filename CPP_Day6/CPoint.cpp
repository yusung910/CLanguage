#include "CPoint.h"


CPoint::CPoint(HANDLE hOutput) {
    m_nHandle = hOutput;
}

CPoint::CPoint() {
    m_nHandle = GetStdHandle(STD_OUTPUT_HANDLE);

    if (m_nHandle == INVALID_HANDLE_VALUE) cout << "Err, INVALID_HANDLE_VALUE\n";
}

CPoint::~CPoint() {
    m_nHandle = NULL;
}

void CPoint::SetPos(int x, int y) {
    COORD m_pos = { x, y };
    m_nPosX = x;
    m_nPosY = y;
    SetConsoleCursorPosition(m_nHandle, m_pos);
}

void CPoint::SetPos(COORD pos) {
    m_nPosX = pos.X;
    m_nPosY = pos.Y;
    SetConsoleCursorPosition(m_nHandle, pos);
}

int CPoint::GetPosX() {
    return m_nPosX;
}

int CPoint::GetPosY() {
    return m_nPosY;
}