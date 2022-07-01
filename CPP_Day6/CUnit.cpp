#include <iostream>
#include "CUnit.h"

using namespace std;

int CUnit::m_nOrganismCnt = 0;
//������
CUnit::CUnit() {
   //��ü ���� ����
    m_nOrganismCnt++;
}

//�Ҹ���
CUnit::~CUnit() {
    //��ü ���� ����
    m_nOrganismCnt--;
    //�����迭 ����
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


