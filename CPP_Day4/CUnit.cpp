#include "CUnit.h"
#include <iostream>

using namespace std;

CUnit::CUnit(const char* s)
{
	strcpy(m_cName, s);
	m_nHp = 0;
	m_nMana = 0;
	m_nDamage = 0;
	m_aPos[0] = 0;
	m_aPos[1] = 0;
	m_nNum++;
}
CUnit::~CUnit() {
	if (m_cName)
	{
		delete m_cName;
		m_cName = NULL;
	}
	m_nNum--;
}

void CUnit::Move(int x, int y)
{
	m_aPos[0] = x;
	m_aPos[1] = y;
}

char* CUnit::GetName() {
	return m_cName;
}