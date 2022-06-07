#ifndef __PILOT_H
#define __PILOT_H

#include "CUnit.h"

class CPilot : public CUnit {
public:
    CPilot(int nPilotType);
    ~CPilot();

    void Display();

    int m_nRankScore;
private:
    int m_nPower;
    int m_nBomb;
    int m_nLife;
    int m_nPilotType;
    
};

#endif