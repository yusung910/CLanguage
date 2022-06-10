#include "CPilot.h"
#include <iostream>

using namespace std;

CPilot::CPilot(int nPilotType) : m_nPilotType(nPilotType){
    m_nPower = 1;
    m_nBomb = 2;
    m_nLife = 1;
    m_nRankScore = 0;
    //m_nPilotType = nPilotType;
    m_UnitType = PILOT;
}

CPilot::~CPilot() {
	if (m_cName)
	{
		delete m_cName;
		m_cName = NULL;
	}
}

void CPilot::Display() {
    cout << "유저 유닛 유형 출력" << endl;
	cout << "이름 : " << m_cName << endl;
    cout << "목숨 : " << m_nLife << ", 비행기체 유형: " << m_nPilotType << ", 폭탄 수 : " << m_nBomb  << ", 점수 : " << m_nRankScore << endl;
}

char* CPilot::GetName() {
	return m_cName;
}

void CPilot::SetName(const char* s) {
	int nTmpNameLength = strlen(s);

	//캐릭터명 배열 생성
	m_cName = new char[nTmpNameLength + 1];
	strcpy(m_cName, s);
}