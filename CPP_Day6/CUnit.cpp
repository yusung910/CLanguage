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
}

//
void CUnit::SetName(CString name) {
	m_cName = name;
}

int* CUnit::GetUnitInfo() {
    return m_nUnitInfo;
}

int* CUnit::GetUnitSkillList() {
    return m_nSkillList;
}