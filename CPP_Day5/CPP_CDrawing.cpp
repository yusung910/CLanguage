#include <iostream>
#include <windows.h>

#include "CObject.h"
#include "CMonster.h"
#include "CUser.h"
#include "CDrawing.h"
#include "CSkill.h"

using namespace std;

CDrawing::CDrawing() {
	//기본 지형의 값이 저장된 2차원 배열의 값을 초기화한다.
	//memset(nArryMap, 0, sizeof(nArryMap));
}

CDrawing::~CDrawing() {
}

void CDrawing::SetBackground() {
    //배경 그리기전 화면을 초기화한다.
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
	//여관
    PrintBuilding(cdInnStart, cdInnEnd);
    gotoxy(13, 12);
    cout << "여관";
	//상점
    PrintBuilding(cdStoreStart, cdStoreEnd);
    gotoxy(38, 12);
    cout << "상점";
	//던전
    PrintBuilding(cdDungeonStart, cdDungeonEnd);
    gotoxy(63, 12);
    cout << "던전";
}

//던전 그리기
void CDrawing::PrintDungeon() {
	//사냥터 출구 
    COORD cdExitTitle = { 3, 3 };

    PrintBuilding(cdExitDungeonStart, cdExitDungeonEnd);
    gotoxy(3, 2);
    cout << "출구";
    
}

void CDrawing::PrintSquare(COORD cdStartPos, COORD cdEndPos) {
    //사각형 그리기.

    //그리기 위한 pos
    COORD m_backPos;
    for (int i = cdStartPos.X; i < cdEndPos.X; i++) {
        m_backPos.X = i;
        m_backPos.Y = cdStartPos.Y;
		gotoxy(m_backPos.X, m_backPos.Y);
		nArryMap[m_backPos.Y][m_backPos.X] = 1;
        cout << "*";
    }

    for (int j = cdStartPos.Y; j < cdEndPos.Y; j++) {
        m_backPos.Y = j;
		gotoxy(m_backPos.X, m_backPos.Y);
		nArryMap[m_backPos.Y][m_backPos.X] = 1;
        cout << "*";
    }

    for (int a = (cdEndPos.X - 1); a >= cdStartPos.X; a--) {
        m_backPos.X = a;
		gotoxy(m_backPos.X, m_backPos.Y);
		nArryMap[m_backPos.Y][m_backPos.X] = 1;
        cout << "*";
    }

    for (int b = (cdEndPos.Y - 1); b >= cdStartPos.Y; b--) {
        m_backPos.Y = b;
		gotoxy(m_backPos.X, m_backPos.Y);
		nArryMap[m_backPos.Y][m_backPos.X] = 1;
        cout << "*";
    }
}

void CDrawing::PrintBuilding(COORD cdStartPos, COORD cdEndPos) {
    //그리기 위한 pos
    COORD m_backPos;
    for (int i = cdStartPos.X; i < cdEndPos.X; i++) {
        m_backPos.X = i;
        m_backPos.Y = cdStartPos.Y;
        gotoxy(m_backPos.X, m_backPos.Y);
        nArryMap[m_backPos.Y][m_backPos.X] = 1;
        cout << "*";
    }

    for (int j = cdStartPos.Y; j < cdEndPos.Y; j++) {
        m_backPos.Y = j;
        gotoxy(m_backPos.X, m_backPos.Y);
		nArryMap[m_backPos.Y][m_backPos.X] = 1;
        cout << "*";
    }

    for (int a = (cdEndPos.X - 1); a >= cdStartPos.X; a--) {
        m_backPos.X = a;
        gotoxy(m_backPos.X, m_backPos.Y);

        if (a > (cdEndPos.X - 10)) {
            cout << " ";
        }
        else {
			nArryMap[m_backPos.Y][m_backPos.X] = 1;
            cout << "*";
        }
        
    }

    for (int b = (cdEndPos.Y - 1); b >= cdStartPos.Y; b--) {
        m_backPos.Y = b;
        gotoxy(m_backPos.X, m_backPos.Y);
		nArryMap[m_backPos.Y][m_backPos.X] = 1;
        cout << "*";
    }
}

void CDrawing::PrintOfCombatInfo(CUser* user) {
	//유저 정보 위치 세팅 후 출력
	COORD cdUserInfo = { 50, 9 };
	int x = 50;
	int y = 9;
	gotoxy(x, y);
    cout << "[캐릭터 정보]";
	y += 1;
	gotoxy(x, y);
    cout << "캐릭명: " << user->m_cName;
	y += 1;
	gotoxy(x, y);
    cout << "체력 : " << user->GetUserHp();
	y += 1;
	gotoxy(x, y);
    cout << "공격력 : " << user->GetUserDmg();
	y += 1;
	gotoxy(x, y);
    cout << "레벨 : " << user->GetUserLvl();
}

void CDrawing::PrintOfCombatInfo(CMonster* monster) {
	//몬스터 정보 출력
	int x = 20;
	int y = 10;

	gotoxy(x, y);
	cout << "[몬스터 정보]";
	y += 1;
	gotoxy(x, y);
	cout << "이름 : " << monster->m_cName;
	y += 1;
	gotoxy(x, y);
	cout << "체력 : " << monster->GetMonsterHP();
	y += 1;
	gotoxy(x, y);
	cout << "공격력 : " << monster->GetMonsterAttack();
}

void CDrawing::PrintUserSkillList(CUser* user) {
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdMsgPos);
    cout << "[스킬 목록]";
    int* skillList = user->GetSkillList();
    for (int i = 0; i < E_SKILL::MAX_SKILL_CNT; i++) {
        if (skillList[i] > -1) {
			m_cdMsgPos.Y += 1;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdMsgPos);
            cout << i << ". " << user->GetSkillName(skillList[i]);
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


void CDrawing::PrintOutInnMsg(CUser* user) {
    int x = 10;
    int y = 22;
    gotoxy(x, y);
	cout << "1. 회복 - XXX 골드 소모";
    y += 1;
    gotoxy(x, y);
	cout << "2. 돌아가기";
}

void CDrawing::PrintOutCompleteMsg() {
	gotoxy(cdSystemStart);
	cout << "회복이 완료되었습니다, 아무키나 눌러 진행하세요.";
}

void CDrawing::gotoxy(int x, int y) {
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void CDrawing::gotoxy(COORD pos) {
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void CDrawing::ClearMsgArea() {
	
    for(int j= cdSystemStart.Y; j< cdSystemEnd.Y; j++){
        for (int i = cdSystemStart.X; i < cdSystemEnd.X; i++) {
            gotoxy(i, j);
            printf(" ");
        }
    }
}