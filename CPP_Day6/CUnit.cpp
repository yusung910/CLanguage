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