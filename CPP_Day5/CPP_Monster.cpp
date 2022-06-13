#include <iostream>
#include "CMonster.h"

using namespace std;

//생성자
CMonster::CMonster()
{
    m_nType = E_C_MONSTER;
}

//소멸자
CMonster::~CMonster()
{

}
//죽은 몬스터의 경험치를 계산하여 리턴한다.
int CMonster::GetMonsterExp() {
    return 0;
}
//몬스터 정보를 화면에 표시
void CMonster::Display() {

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
}

void CMonster::Attack() {
    //공격!
}