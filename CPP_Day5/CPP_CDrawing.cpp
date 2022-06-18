#include <iostream>
#include <windows.h>
#include "CMonster.h"
#include "CUser.h"
#include "CDrawing.h"

using namespace std;

void CDrawing::SetBackground() {
    //��� �׸����� ȭ���� �ʱ�ȭ�Ѵ�.
    cout << "\x1B[2J\x1B[H";
    int x = 150;
    int y = 50;
    COORD m_backPos = { 0, 0 };
    for (int i = 0; i < 150; i++) {
        m_backPos.X = i;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_backPos);
        cout << "*";
        //Sleep(1);
    }

    for (int j = 0; j < 50; j++) {
        m_backPos.Y = j;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_backPos);
        cout << "*";
        //Sleep(1);
    }

    for (int a = 149; a > 0; a--) {
        m_backPos.X = a;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_backPos);
        cout << "*";
        //Sleep(1);
    }

    for (int b = 49; b > 0; b--) {
        m_backPos.Y = b;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_backPos);
        cout << "*";
        //Sleep(1);
    }
}

void CDrawing::SetCdDrawingPos(COORD pos) {
    m_cdDrawingPos = pos;
}

COORD CDrawing::GetCdDrawingPos() {
    return m_cdDrawingPos;
}

void CDrawing::PrintOfInfo(CUser* user) {
    //ȭ�� ǥ��
    m_cdDrawingPos.Y += 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdDrawingPos);
    cout << "[ĳ���� ����]";
    m_cdDrawingPos.Y += 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdDrawingPos);
    cout << "ĳ����: " << user->m_cName;
    m_cdDrawingPos.Y += 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdDrawingPos);
    cout << "ü�� : " << user->GetUserHp();
    m_cdDrawingPos.Y += 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdDrawingPos);
    cout << "���ݷ� : " << user->GetUserDmg();
    m_cdDrawingPos.Y += 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdDrawingPos);
    cout << "���� : " << user->GetUserLvl();
}

void CDrawing::PrintOfInfo(CMonster* monster) {
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdDrawingPos);
    cout << "[���� ����]";
    m_cdDrawingPos.Y += 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdDrawingPos);
    cout << "�̸� : " << monster->m_cName;
    m_cdDrawingPos.Y += 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdDrawingPos);
    cout << "ü�� : " << monster->GetMonsterHP();
    m_cdDrawingPos.Y += 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdDrawingPos);
    cout << "���ݷ� : " << monster->GetMonsterAttack();
}

void CDrawing::PrintOfInfo(CMonster* monster, CUser* user) {
}