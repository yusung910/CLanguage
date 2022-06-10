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
    cout << "���� ���� ���� ���" << endl;
	cout << "�̸� : " << m_cName << endl;
    cout << "��� : " << m_nLife << ", �����ü ����: " << m_nPilotType << ", ��ź �� : " << m_nBomb  << ", ���� : " << m_nRankScore << endl;
}

char* CPilot::GetName() {
	return m_cName;
}

void CPilot::SetName(const char* s) {
	int nTmpNameLength = strlen(s);

	//ĳ���͸� �迭 ����
	m_cName = new char[nTmpNameLength + 1];
	strcpy(m_cName, s);
}