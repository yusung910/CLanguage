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
	cout << "더미 생성자" << endl;
}
CDummy:: ~CDummy() {
	m_nDummyCnt--;
	cout << "더미 소멸자" << endl;
}

int CDummy::GetDummyCnt() {
	return m_nDummyCnt;
}

void CDummy::Display() {
	cout << "점수 더미 OBJCT" << endl;
	cout << "점수 : " << m_nAddScore << ", HP : " << m_nHp << ", 더미 개수 : " << m_nDummyCnt << endl;
}

int CDummy::GetDummyScore() {
	return m_nAddScore;
}