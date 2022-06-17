#include <iostream>
#include "CUser.h"

using namespace std;

CUser::CUser() {
    //생성자
    init();
	//cout << "CUser :: 객체 생성자" << endl;
}

CUser::~CUser() {
    //소멸자
	//동적배열들을 소멸한다
	//cout << "CUser :: 객체 소멸자" << endl;
}

int CUser::Attack() {
    //공격
	return 0;
}

void CUser::Display() {
    //화면 표시
    m_cdMenuPos.Y += 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdMenuPos);
    cout << "[캐릭터 정보]";
    m_cdMenuPos.Y += 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdMenuPos);
    cout << "캐릭명: " << m_cName;
    m_cdMenuPos.Y += 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdMenuPos);
    cout << "체력 : " << m_nHP;
    m_cdMenuPos.Y += 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdMenuPos);
    cout << "공격력 : " << m_Damage;
    m_cdMenuPos.Y += 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdMenuPos);
    cout << "레벨 : " << m_nLEVEL;
}

void CUser::init() {
    //초기 세팅
    m_nExp = 0;
    //체력
    m_nHP = 100;
    //마나
    m_nMana = 20;
    //레벨
    m_nLEVEL = 1;
    //힘
    m_Str = 5;
    //지능
    m_Int = 5;
    //민첩
    m_Dex = 5;
    //공격력
    m_Damage = 5;
	//객체 타입 설정
	m_nType = TYPE::E_C_USER;
}

void CUser::Move() {
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdPos);
	if (m_cdPos.X < 70) {
		cout << "*<-(" << m_cName << ")";
	}
	else {
		cout << "(" << m_cName << ")->*";
	}
    
}