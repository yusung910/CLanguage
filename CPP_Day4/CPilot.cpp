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
    cout << "À¯Àú À¯´Ö À¯Çü Ãâ·Â" << endl;
    cout << "¸ñ¼û : " << m_nLife << ", ºñÇà±âÃ¼ À¯Çü: " << m_nPilotType << ", ÆøÅº ¼ö : " << m_nBomb  << ", Á¡¼ö : " << m_nRankScore << endl;
}