#include "CDummy.h"
#include <iostream>

using namespace std;
int CDummy::m_nDummyCnt = 0;

CDummy::CDummy(){
	m_nAddScore = ((rand() & 5) + 1) * 100;
	m_nHp = 2;
	m_aPos[0] = rand() % 100;
	m_aPos[1] = rand() % 100;
	m_nDummyCnt++;
	cout << "���� ������" << endl;
}
CDummy:: ~CDummy() {
	m_nDummyCnt--;
	cout << "���� �Ҹ���" << endl;
}

int CDummy::GetDummyCnt() {
	return m_nDummyCnt;
}

void CDummy::Display() {
	cout << "���� ���� OBJCT" << endl;
	cout << "���� : " << m_nAddScore << ", HP : " << m_nHp << ", ���� ���� : " << m_nDummyCnt << endl;
}

int CDummy::GetDummyScore() {
	return m_nAddScore;
}