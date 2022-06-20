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
    //기본 공격력과 힘(10퍼센트)에 비례한 데미지를 계산하여 리턴한다.
	return m_Damage + (m_Str * 0.1);
}

void CUser::Display() {

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