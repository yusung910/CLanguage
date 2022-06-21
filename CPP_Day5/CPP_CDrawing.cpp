#include <iostream>
#include <windows.h>

#include "CObject.h"
#include "CMonster.h"
#include "CUser.h"
#include "CDrawing.h"
#include "CSkill.h"

using namespace std;

CDrawing::CDrawing() {
}

CDrawing::~CDrawing() {
}
void CDrawing::SetBackground() {
    //배경 그리기전 화면을 초기화한다.
    cout << "\x1B[2J\x1B[H";
    COORD cdStart = { 0, 0 };
    COORD cdEnd = { 150, 50 };
    PrintSquare(cdStart, cdEnd);
}

int CDrawing::GetUserPosBuild(COORD pos, int nCurrentMap) {
    int n_retMap = E_BACKGROUND_TYPE::VILLAGE;
    if (nCurrentMap == E_BACKGROUND_TYPE::VILLAGE) {
        if (pos.X >= cdInnStart.X &&
            pos.X <= cdInnEnd.X &&
            pos.Y >= cdInnStart.Y &&
            pos.Y <= cdInnEnd.Y) {
            n_retMap = E_BACKGROUND_TYPE::INN;
        }
        else if (pos.X >= cdStoreStart.X &&
            pos.X <= cdStoreEnd.X &&
            pos.Y >= cdStoreStart.Y &&
            pos.Y <= cdStoreEnd.Y) {
            n_retMap = E_BACKGROUND_TYPE::STORE;
        }
        else if (pos.X >= cdDungeonStart.X &&
            pos.X <= cdDungeonEnd.X &&
            pos.Y >= cdDungeonStart.Y &&
            pos.Y <= cdDungeonEnd.Y) {
            n_retMap = E_BACKGROUND_TYPE::DUNGEON;
        }
    }
    else if (nCurrentMap == E_BACKGROUND_TYPE::DUNGEON) {
        n_retMap = E_BACKGROUND_TYPE::DUNGEON;
        if (pos.X >= cdExitDungeonStart.X &&
            pos.X <= cdExitDungeonEnd.X &&
            pos.Y >= cdExitDungeonStart.Y &&
            pos.Y <= cdExitDungeonEnd.Y) {
            n_retMap = E_BACKGROUND_TYPE::VILLAGE;
        }
    }
    return n_retMap;
}

void CDrawing::PrintOfHome() {
    //기본 배경을 그린다.
    SetBackground();

    //여관 건물을 그린다.
    PrintSquare(cdInnStart, cdInnEnd);
    COORD cdInnTitle = { 23, 17 };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cdInnTitle);
    cout << "여관";

    //상점 건물을 그린다.
    PrintSquare(cdStoreStart, cdStoreEnd);
    COORD cdStoreTitle = { 73, 17 };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cdStoreTitle);
    cout << "상점";

    //상점 건물을 그린다.
    PrintSquare(cdDungeonStart, cdDungeonEnd);
    COORD cdDungeonTitle = { 123, 17 };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cdDungeonTitle);
    cout << "던전";
}

//던전 그리기
void CDrawing::PrintDungeon() {
    //배경 그리기
    SetBackground();

    COORD cdExitTitle = { 5, 5 };
    PrintSquare(cdExitDungeonStart, cdExitDungeonEnd);
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cdExitTitle);
    cout << "출구";
    
}

void CDrawing::PrintSquare(COORD cdStartPos, COORD cdEndPos) {
    //사각형 그리기.

    //그리기 위한 pos
    COORD m_backPos;
    for (int i = cdStartPos.X; i < cdEndPos.X; i++) {
        m_backPos.X = i;
        m_backPos.Y = cdStartPos.Y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_backPos);
        cout << "*";
    }

    for (int j = cdStartPos.Y; j < cdEndPos.Y; j++) {
        m_backPos.Y = j;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_backPos);
        cout << "*";
    }

    for (int a = (cdEndPos.X - 1); a >= cdStartPos.X; a--) {
        m_backPos.X = a;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_backPos);
        cout << "*";
    }

    for (int b = (cdEndPos.Y - 1); b >= cdStartPos.Y; b--) {
        m_backPos.Y = b;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_backPos);
        cout << "*";
    }
}


void CDrawing::SetMsgPos(COORD pos) {
	m_cdMsgPos = pos;
}

void CDrawing::PrintOfCombatInfo(CUser* user) {
    //유저정보 출력
	m_cdMsgPos.Y += 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdMsgPos);
    cout << "[캐릭터 정보]";
	m_cdMsgPos.Y += 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdMsgPos);
    cout << "캐릭명: " << user->m_cName;
	m_cdMsgPos.Y += 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdMsgPos);
    cout << "체력 : " << user->GetUserHp();
	m_cdMsgPos.Y += 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdMsgPos);
    cout << "공격력 : " << user->GetUserDmg();
	m_cdMsgPos.Y += 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdMsgPos);
    cout << "레벨 : " << user->GetUserLvl();
}

void CDrawing::PrintOfCombatInfo(CMonster* monster) {
	//몬스터 정보 출력
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdMsgPos);
	cout << "[몬스터 정보]";
	m_cdMsgPos.Y += 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdMsgPos);
	cout << "이름 : " << monster->m_cName;
	m_cdMsgPos.Y += 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdMsgPos);
	cout << "체력 : " << monster->GetMonsterHP();
	m_cdMsgPos.Y += 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdMsgPos);
	cout << "공격력 : " << monster->GetMonsterAttack();
}

void CDrawing::PrintUserSkillList(CSkill* skill) {
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdMsgPos);
    cout << "[스킬 목록]";
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
	cout << "\"" << user->m_cName << "\"의 [" << user->GetSkillName(user->GetUsingSkill()) << "] !!";
	Sleep(100);
	m_cdMsgPos.Y += 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdMsgPos);
	cout << "[" << monster->m_cName << "] 에게 " << user->Attack() << "의 데미지를 입혔습니다.";
}

void CDrawing::PrintMonsterAttack(CUser* user, CMonster* monster) {
	Sleep(100);
	m_cdMsgPos.Y += 2;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdMsgPos);
	cout << "\"" << monster->m_cName << "\"의 [ 공격 ] !!";
	Sleep(100);
	m_cdMsgPos.Y += 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdMsgPos);
	cout << "[" << user->m_cName << "] 에게 " << monster->Attack() << "의 데미지를 입혔습니다.";
}

void CDrawing::PrintCombatRslt(CUser* user, CMonster* monster) {
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdMsgPos);
	cout << "[전투 결과]";
    if (monster->GetMonsterHP() <= 0) {
		m_cdMsgPos.Y += 1;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdMsgPos);
        cout << "[" << user->m_cName << "] 승리!";
		m_cdMsgPos.Y += 1;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdMsgPos);
        cout << "획득 경험치 : " << monster->GetMonsterExp();
        m_cdMsgPos.Y += 1;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdMsgPos);
        cout << "아무 키나 눌러 계속 진행하세요.";
    }
    else if (user->GetUserHp() <= 0) {
        //플레이어가 죽었을 경우
		m_cdMsgPos.Y += 1;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdMsgPos);
        cout << "[" << user->m_cName << "] 사망";

		m_cdMsgPos.Y += 1;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdMsgPos);
		cout << "XXX 골드와 XXX 경험치를 잃어버렸습니다.";
        m_cdMsgPos.Y += 1;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdMsgPos);
        cout << "아무 키나 눌러주세요, 마을 여관으로 이동 됩니다.";
    }

}