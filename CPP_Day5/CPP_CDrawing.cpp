#include <iostream>
#include <windows.h>
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

void CDrawing::SetCdDrawingPos(COORD pos) {
    m_cdDrawingPos = pos;
}

COORD CDrawing::GetCdDrawingPos() {
    return m_cdDrawingPos;
}

void CDrawing::PrintOfInfo(CUser* user) {
    //화면 표시
    m_cdDrawingPos.Y += 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdDrawingPos);
    cout << "[캐릭터 정보]";
    m_cdDrawingPos.Y += 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdDrawingPos);
    cout << "캐릭명: " << user->m_cName;
    m_cdDrawingPos.Y += 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdDrawingPos);
    cout << "체력 : " << user->GetUserHp();
    m_cdDrawingPos.Y += 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdDrawingPos);
    cout << "공격력 : " << user->GetUserDmg();
    m_cdDrawingPos.Y += 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdDrawingPos);
    cout << "레벨 : " << user->GetUserLvl();
}

void CDrawing::PrintOfInfo(CMonster* monster) {
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdDrawingPos);
    cout << "[몬스터 정보]";
    m_cdDrawingPos.Y += 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdDrawingPos);
    cout << "이름 : " << monster->m_cName;
    m_cdDrawingPos.Y += 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdDrawingPos);
    cout << "체력 : " << monster->GetMonsterHP();
    m_cdDrawingPos.Y += 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdDrawingPos);
    cout << "공격력 : " << monster->GetMonsterAttack();
}

void CDrawing::PrintUserSkillList(CSkill* skill) {
	m_cdDrawingPos.Y += 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdDrawingPos);
    cout << "[스킬 목록]";
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
	cout << "\"" << user->m_cName << "\"의 [" << user->GetSkillName(user->GetUsingSkill()) << "] !!";
	Sleep(100);
	m_cdDrawingPos.Y += 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdDrawingPos);
	cout << "[" << monster->m_cName << "] 에게 " << user->Attack() << "의 데미지를 입혔습니다.";
}

void CDrawing::PrintMonsterAttack(CUser* user, CMonster* monster) {
	Sleep(100);
	m_cdDrawingPos.Y += 2;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdDrawingPos);
	cout << "\"" << monster->m_cName << "\"의 [ 공격 ] !!";
	Sleep(100);
	m_cdDrawingPos.Y += 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdDrawingPos);
	cout << "[" << user->m_cName << "] 에게 " << monster->Attack() << "의 데미지를 입혔습니다.";
}

void CDrawing::PrintCombatEnd(CUser* user, CMonster* monster) {
    m_cdDrawingPos.Y += 2;
    cout << "[전투 종료]";
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdDrawingPos);
    if (monster->GetMonsterHP() <= 0) {
        m_cdDrawingPos.Y += 1;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdDrawingPos);
        cout << "[" << user->m_cName << "] 승리!";
        m_cdDrawingPos.Y += 1;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdDrawingPos);
        cout << "획득 경험치 : " << monster->GetMonsterExp();
    }
    else if (user->GetUserHp() <= 0) {
        //몬스터가 죽었을 경우
        m_cdDrawingPos.Y += 1;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdDrawingPos);
        cout << "플레이어 : [" << user->m_cName << "]";
        m_cdDrawingPos.Y += 1;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdDrawingPos);
        cout << "사망 하셨습니다.";
    }
    
}