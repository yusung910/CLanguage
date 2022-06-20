#include <iostream>
#include <windows.h>
#include "CMonster.h"
#include "CUser.h"
#include "CDrawing.h"
#include "CSkill.h"

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

void CDrawing::PrintUserSkillList(CSkill* skill) {
	m_cdDrawingPos.Y += 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdDrawingPos);
    cout << "[��ų ���]";
    int* skillList = skill->GetSkillList();
    for (int i = 0; i < E_SKILL::MAX_SKILL_CNT; i++) {
        if (skillList[i] > -1) {
            m_cdDrawingPos.Y += 1;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdDrawingPos);
            cout << i << ". " << skill->GetSkillName(skillList[i]);
        }
    }
}

void CDrawing::PrintUserSkillAttack(CUser* user, CMonster* monster) {
	Sleep(100);
	m_cdDrawingPos.Y += 2;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdDrawingPos);
	cout << "\"" << user->m_cName << "\"�� [" << user->GetSkillName(user->GetUsingSkill()) << "] !!";
	Sleep(100);
	m_cdDrawingPos.Y += 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdDrawingPos);
	cout << "[" << monster->m_cName << "] ���� " << user->Attack() << "�� �������� �������ϴ�.";
}

void CDrawing::PrintMonsterAttack(CUser* user, CMonster* monster) {
	Sleep(100);
	m_cdDrawingPos.Y += 2;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdDrawingPos);
	cout << "\"" << monster->m_cName << "\"�� [ ���� ] !!";
	Sleep(100);
	m_cdDrawingPos.Y += 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdDrawingPos);
	cout << "[" << user->m_cName << "] ���� " << monster->Attack() << "�� �������� �������ϴ�.";
}

void CDrawing::PrintCombatEnd(CUser* user, CMonster* monster) {
    m_cdDrawingPos.Y += 2;
    cout << "[���� ����]";
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdDrawingPos);
    if (monster->GetMonsterHP() <= 0) {
        m_cdDrawingPos.Y += 1;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdDrawingPos);
        cout << "[" << user->m_cName << "] �¸�!";
        m_cdDrawingPos.Y += 1;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdDrawingPos);
        cout << "ȹ�� ����ġ : " << monster->GetMonsterExp();
    }
    else if (user->GetUserHp() <= 0) {
        //���Ͱ� �׾��� ���
        m_cdDrawingPos.Y += 1;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdDrawingPos);
        cout << "�÷��̾� : [" << user->m_cName << "]";
        m_cdDrawingPos.Y += 1;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdDrawingPos);
        cout << "��� �ϼ̽��ϴ�.";
    }
    
}