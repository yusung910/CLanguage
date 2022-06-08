#include "CUnit.h"
#include <iostream>

using namespace std;

int CUnit::m_nNum = 0;

CUnit::CUnit()
{
	m_nDamage = 0;
	m_aPos[0] = 0;
	m_aPos[1] = 0;
	m_nNum++;
	cout << "CUnit 생성자" << endl;
}
CUnit::~CUnit() {
	m_nNum--;
    cout << "CUnit 소멸자" << endl;
}

void CUnit::Move(int x, int y)
{
	m_aPos[0] = x;
	m_aPos[1] = y;
}

void CUnit::Attack() {

}

void CUnit::Display() {
    cout << "유닛 위치 X : " << m_aPos[0] << ", Y : " << m_aPos[1] << ", 타입 : " << m_UnitType << endl;
}

int CUnit::GetUnitCnt() {
    return m_nNum;
}