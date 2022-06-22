#include <iostream>
#include <windows.h>

#include "CObject.h"
#include "CMonster.h"
#include "CUser.h"
#include "CDrawing.h"
#include "CSkill.h"

using namespace std;

CDrawing::CDrawing() {
	//�⺻ ������ ���� ����� 2���� �迭�� ���� �ʱ�ȭ�Ѵ�.
	//memset(nArryMap, 0, sizeof(nArryMap));
}

CDrawing::~CDrawing() {
}

void CDrawing::SetBackground() {
    //��� �׸����� ȭ���� �ʱ�ȭ�Ѵ�.
    memset(nArryMap, 0, sizeof(nArryMap));
    cout << "\x1B[2J\x1B[H";
    COORD cdStart = { 0, 0 };
    COORD cdEnd = { 80, 30 };
    PrintSquare(cdStart, cdEnd);
}

int CDrawing::GetUserPosBuild(COORD pos, int nCurrentMap) {
    int n_retMap = E_BACKGROUND_TYPE::VILLAGE;
    if (nCurrentMap == E_BACKGROUND_TYPE::VILLAGE) {
        if (pos.X >= cdInnStart.X &&
            pos.X < cdInnEnd.X &&
            pos.Y >= cdInnStart.Y &&
            pos.Y < cdInnEnd.Y) {
            n_retMap = E_BACKGROUND_TYPE::INN;
        }
        else if (pos.X >= cdStoreStart.X &&
            pos.X < cdStoreEnd.X &&
            pos.Y >= cdStoreStart.Y &&
            pos.Y < cdStoreEnd.Y) {
            n_retMap = E_BACKGROUND_TYPE::STORE;
        }
        else if (pos.X >= cdDungeonStart.X &&
            pos.X < cdDungeonEnd.X &&
            pos.Y >= cdDungeonStart.Y &&
            pos.Y < cdDungeonEnd.Y) {
            n_retMap = E_BACKGROUND_TYPE::DUNGEON;
        }
    }
    else if (nCurrentMap == E_BACKGROUND_TYPE::DUNGEON) {
        n_retMap = E_BACKGROUND_TYPE::DUNGEON;
        if (pos.X >= cdExitDungeonStart.X &&
            pos.X < cdExitDungeonEnd.X &&
            pos.Y >= cdExitDungeonStart.Y &&
            pos.Y < cdExitDungeonEnd.Y) {
            n_retMap = E_BACKGROUND_TYPE::VILLAGE;
        }
    }
    return n_retMap;
}

void CDrawing::PrintOfHome() {
	//����
    PrintBuilding(cdInnStart, cdInnEnd);
    gotoxy(13, 12);
    cout << "����";
	//����
    PrintBuilding(cdStoreStart, cdStoreEnd);
    gotoxy(38, 12);
    cout << "����";
	//����
    PrintBuilding(cdDungeonStart, cdDungeonEnd);
    gotoxy(63, 12);
    cout << "����";
}

//���� �׸���
void CDrawing::PrintDungeon() {
    COORD cdExitTitle = { 3, 3 };
    PrintBuilding(cdExitDungeonStart, cdExitDungeonEnd);
    gotoxy(3, 2);
    cout << "�ⱸ";
    
}

void CDrawing::PrintSquare(COORD cdStartPos, COORD cdEndPos) {
    //�簢�� �׸���.

    //�׸��� ���� pos
    COORD m_backPos;
    for (int i = cdStartPos.X; i < cdEndPos.X; i++) {
        m_backPos.X = i;
        m_backPos.Y = cdStartPos.Y;
		gotoxy(m_backPos.X, m_backPos.Y);
		nArryMap[m_backPos.X][m_backPos.Y] = 1;
        cout << "*";
    }

    for (int j = cdStartPos.Y; j < cdEndPos.Y; j++) {
        m_backPos.Y = j;
		gotoxy(m_backPos.X, m_backPos.Y);
		nArryMap[m_backPos.X][m_backPos.Y] = 1;
        cout << "*";
    }

    for (int a = (cdEndPos.X - 1); a >= cdStartPos.X; a--) {
        m_backPos.X = a;
		gotoxy(m_backPos.X, m_backPos.Y);
		nArryMap[m_backPos.X][m_backPos.Y] = 1;
        cout << "*";
    }

    for (int b = (cdEndPos.Y - 1); b >= cdStartPos.Y; b--) {
        m_backPos.Y = b;
		gotoxy(m_backPos.X, m_backPos.Y);
		nArryMap[m_backPos.X][m_backPos.Y] = 1;
        cout << "*";
    }
}

void CDrawing::PrintBuilding(COORD cdStartPos, COORD cdEndPos) {
    //�׸��� ���� pos
    COORD m_backPos;
    for (int i = cdStartPos.X; i < cdEndPos.X; i++) {
        m_backPos.X = i;
        m_backPos.Y = cdStartPos.Y;
        gotoxy(m_backPos.X, m_backPos.Y);
        nArryMap[m_backPos.X][m_backPos.Y] = 1;
        cout << "*";
    }

    for (int j = cdStartPos.Y; j < cdEndPos.Y; j++) {
        m_backPos.Y = j;
        gotoxy(m_backPos.X, m_backPos.Y);
        nArryMap[m_backPos.X][m_backPos.Y] = 1;
        cout << "*";
    }

    for (int a = (cdEndPos.X - 1); a >= cdStartPos.X; a--) {
        m_backPos.X = a;
        gotoxy(m_backPos.X, m_backPos.Y);

        if (a > (cdEndPos.X - 10)) {
            cout << " ";
        }
        else {
            nArryMap[m_backPos.X][m_backPos.Y] = 1;
            cout << "*";
        }
        
    }

    for (int b = (cdEndPos.Y - 1); b >= cdStartPos.Y; b--) {
        m_backPos.Y = b;
        gotoxy(m_backPos.X, m_backPos.Y);
        nArryMap[m_backPos.X][m_backPos.Y] = 1;
        cout << "*";

        
    }
}


void CDrawing::SetMsgPos(COORD pos) {
	m_cdMsgPos = pos;
}

void CDrawing::PrintOfCombatInfo(CUser* user) {
    //�������� ���
	m_cdMsgPos.Y += 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdMsgPos);
    cout << "[ĳ���� ����]";
	m_cdMsgPos.Y += 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdMsgPos);
    cout << "ĳ����: " << user->m_cName;
	m_cdMsgPos.Y += 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdMsgPos);
    cout << "ü�� : " << user->GetUserHp();
	m_cdMsgPos.Y += 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdMsgPos);
    cout << "���ݷ� : " << user->GetUserDmg();
	m_cdMsgPos.Y += 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdMsgPos);
    cout << "���� : " << user->GetUserLvl();
}

void CDrawing::PrintOfCombatInfo(CMonster* monster) {
	//���� ���� ���
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdMsgPos);
	cout << "[���� ����]";
	m_cdMsgPos.Y += 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdMsgPos);
	cout << "�̸� : " << monster->m_cName;
	m_cdMsgPos.Y += 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdMsgPos);
	cout << "ü�� : " << monster->GetMonsterHP();
	m_cdMsgPos.Y += 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdMsgPos);
	cout << "���ݷ� : " << monster->GetMonsterAttack();
}

void CDrawing::PrintUserSkillList(CSkill* skill) {
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdMsgPos);
    cout << "[��ų ���]";
    int* skillList = skill->GetSkillList();
    for (int i = 0; i < E_SKILL::MAX_SKILL_CNT; i++) {
        if (skillList[i] > -1) {
			m_cdMsgPos.Y += 1;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdMsgPos);
            cout << i << ". " << skill->GetSkillName(skillList[i]);
        }
    }
}

void CDrawing::PrintUserSkillAttack(CUser* user, CMonster* monster) {
	Sleep(100);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdMsgPos);
	cout << "\"" << user->m_cName << "\"�� [" << user->GetSkillName(user->GetUsingSkill()) << "] !!";
	Sleep(100);
	m_cdMsgPos.Y += 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdMsgPos);
	cout << "[" << monster->m_cName << "] ���� " << user->Attack() << "�� �������� �������ϴ�.";
}

void CDrawing::PrintMonsterAttack(CUser* user, CMonster* monster) {
	Sleep(100);
	m_cdMsgPos.Y += 2;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdMsgPos);
	cout << "\"" << monster->m_cName << "\"�� [ ���� ] !!";
	Sleep(100);
	m_cdMsgPos.Y += 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdMsgPos);
	cout << "[" << user->m_cName << "] ���� " << monster->Attack() << "�� �������� �������ϴ�.";
}

void CDrawing::PrintCombatRslt(CUser* user, CMonster* monster) {
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdMsgPos);
	cout << "[���� ���]";
    if (monster->GetMonsterHP() <= 0) {
		m_cdMsgPos.Y += 1;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdMsgPos);
        cout << "[" << user->m_cName << "] �¸�!";
		m_cdMsgPos.Y += 1;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdMsgPos);
        cout << "ȹ�� ����ġ : " << monster->GetMonsterExp();
        m_cdMsgPos.Y += 1;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdMsgPos);
        cout << "�ƹ� Ű�� ���� ��� �����ϼ���.";
    }
    else if (user->GetUserHp() <= 0) {
        //�÷��̾ �׾��� ���
		m_cdMsgPos.Y += 1;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdMsgPos);
        cout << "[" << user->m_cName << "] ���";

		m_cdMsgPos.Y += 1;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdMsgPos);
		cout << "XXX ���� XXX ����ġ�� �Ҿ���Ƚ��ϴ�.";
        m_cdMsgPos.Y += 1;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdMsgPos);
        cout << "�ƹ� Ű�� �����ּ���, ���� �������� �̵� �˴ϴ�.";
    }

}


void CDrawing::PrintOutInnMsg(CUser* user) {
    int x = 10;
    int y = 22;
    gotoxy(x, y);
	cout << "1. ȸ�� - XXX ��� �Ҹ�";
    y += 1;
    gotoxy(x, y);
	cout << "2. ���ư���";
}

void CDrawing::gotoxy(int x, int y) {
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void CDrawing::gotoxy(COORD pos) {
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void CDrawing::ClearMsgArea() {
    COORD start = { 10, 22 };
    COORD end = { 79, 29 };

    for(int j=start.Y; j<end.Y; j++){
        for (int i = start.X; i < end.X; i++) {
            gotoxy(i, j);
            printf(" ");
        }
    }
}