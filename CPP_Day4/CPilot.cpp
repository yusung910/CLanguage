#include "CPilot.h"
#include <iostream>

using namespace std;

CPilot::CPilot(int nPilotType) {
    m_nPower = 1;
    m_nBomb = 2;
    m_nLife = 1;
    m_nRankScore = 0;
    m_nPilotType = nPilotType;
    m_UnitType = PILOT;
}

CPilot::~CPilot() {
    
}

void CPilot::Display() {
    cout << "���� ���� ���� ���" << endl;
    cout << "��� : " << m_nLife << ", �����ü ����: " << m_nPilotType << ", ��ź �� : " << m_nBomb  << ", ���� : " << m_nRankScore << endl;
}