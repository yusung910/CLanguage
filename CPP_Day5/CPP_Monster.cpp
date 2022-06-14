#include <iostream>
#include "CMonster.h"

using namespace std;

//생성자
CMonster::CMonster()
{
    m_nType = E_C_MONSTER;
	//몬스터 정보 초기화
	init();
	//cout << "CMonster :: 객체 생성자" << endl;
}

//소멸자
CMonster::~CMonster()
{
	//cout << "CMonster :: 객체 소멸자" << endl;
}
//죽은 몬스터의 경험치를 계산하여 리턴한다.
int CMonster::GetMonsterExp() {
    return 0;
}
//몬스터 정보를 화면에 표시
void CMonster::Display() {
	cout << "몬스터 : " << m_cName << endl;
	cout << "체력 : " << m_nHP << endl;
	cout << "공격력 : " << m_nAttack << endl;
}
//몬스터 객체 초기화 함수
void CMonster::init() {
    m_nMobInfo = (rand() % MONSTER_MAX) + 1;
    //몬스터의 경험치
    m_nMonsterExp = 0;
    //몬스터의 체력
    m_nHP = (rand() % 50) + 50;
    //몬스터의 마나
    m_nMana = 0;
    //몬스터의 레벨
    m_nLEVEL = 0;
    //몬스터의 공격력
    m_nAttack = (rand() % 10 ) + 1;
	//객체 타입 설정
	m_nType = TYPE::E_C_MONSTER;
	//몬스터명 세팅
	SetMonsterName();
}
char* CMonster::SetMonsterName() {
	m_nMobInfo = (rand() % E_MONSTER_TYPE::MONSTER_MAX) + 1;
	switch (m_nMobInfo) {
	case E_MONSTER_TYPE::COBOLT:
		SetName("코볼트");
		break;
	case E_MONSTER_TYPE::GOBLINE:
		SetName("고블린");
		break;
	case E_MONSTER_TYPE::GREMLINE:
		SetName("그렘린");
		break;
	case E_MONSTER_TYPE::ORC:
		SetName("오크");
		break;
	case E_MONSTER_TYPE::TROLL:
		SetName("트롤");
		break;
	}
	return m_cName;
}
void CMonster::Attack() {
    //공격!
}