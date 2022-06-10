#include "CMonster.h"
#include <iostream>

using namespace std;

int CMonster::m_nMonsterCnt = 0;

CMonster::CMonster() {
    Init();
}
CMonster::~CMonster() {
	m_nMonsterCnt--;
}

void CMonster::Init() {
	m_nMonsterCnt++;
    m_aPos[0] = rand() % 100;
    m_aPos[1] = rand() % 100;
    m_UnitType = (rand() % 4) + MONSTER_S;
}

void CMonster::Display() {
    cout << "몬스터 정보 출력" << endl;
    cout << "X : " << m_aPos[0] << ", Y: " << m_aPos[1] << ", Type : " << m_UnitType << endl;
}