#include <iostream>
#include <windows.h>

#include "CObject.h"
#include "CMonster.h"
#include "CUser.h"
#include "CDrawing.h"
#include "CSkill.h"

using namespace std;

void CDrawing::SetBackground() {
    //배경 그리기전 화면을 초기화한다.
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
		m_cdMsgPos.Y += 2;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdMsgPos);
		cout << "다음 진행할 메뉴를 선택하여주세요:";
		m_cdMsgPos.Y += 1;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdMsgPos);
		cout << "1. 계속 진행.";
		m_cdMsgPos.Y += 1;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdMsgPos);
		cout << "2. 마을로 돌아간다.";
    }
    else if (user->GetUserHp() <= 0) {
        //몬스터가 죽었을 경우
		m_cdMsgPos.Y += 1;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdMsgPos);
        cout << "[" << user->m_cName << "] 사망";
		//몬스터가 죽었을 경우
		m_cdMsgPos.Y += 1;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdMsgPos);
		cout << "XXX 골드와 XXX 경험치를 잃어버렸습니다.";
		m_cdMsgPos.Y += 1;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdMsgPos);
		cout << "1. 마을로 돌아간다.";
    }
}