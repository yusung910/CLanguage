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
}

//
void CUnit::SetName(CString name) {
	m_cName = name;
}