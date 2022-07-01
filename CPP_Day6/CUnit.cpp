#include <iostream>
#include "CUnit.h"

using namespace std;

int CUnit::m_nOrganismCnt = 0;
//생성자
CUnit::CUnit() {
   //객체 갯수 증가
    m_nOrganismCnt++;
}

//소멸자
CUnit::~CUnit() {
    //객체 갯수 감소
    m_nOrganismCnt--;
    //동적배열 삭제
    delete m_nSkillList;
	m_nSkillList = NULL;
}

//
void CUnit::SetName(CString name) {
	m_cName = name;
}

unsigned int* CUnit::GetUnitInfo() {
    return m_nUnitInfo;
}

int* CUnit::GetUnitSkillList() {
    return m_nSkillList;
}

int CUnit::GetUnitHp() {
	return m_nUnitInfo[E_UNIT_INFO::E_HP];
}

void CUnit::SetUnitHp(int n) {
	m_nUnitInfo[E_UNIT_INFO::E_HP] = n;
}

int CUnit::GetUnitMana() {
	return m_nUnitInfo[E_UNIT_INFO::E_MANA];
}

void CUnit::SetUnitMana(int n) {
	m_nUnitInfo[E_UNIT_INFO::E_MANA] = n;
}


