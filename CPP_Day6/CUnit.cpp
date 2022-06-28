#include <iostream>
#include "CUnit.h"

using namespace std;

int CUnit::m_nOrganismCnt = 0;
//积己磊
CUnit::CUnit() {
   //按眉 肮荐 刘啊
    m_nOrganismCnt++;
}

//家戈磊
CUnit::~CUnit() {
    //按眉 肮荐 皑家
    m_nOrganismCnt--;
}

//
void CUnit::SetName(CString name) {
	m_cName = name;
}