#ifndef __PILOT_H
#define __PILOT_H

#include "CUnit.h"

class CPilot : public CUnit {
public:
    CPilot(int nPilotType);
    ~CPilot();

    void Display();

	void SetName(const char* s);
	char* GetName();
    int m_nRankScore;
private:

	char* m_cName;
    int m_nPower;
    int m_nBomb;
    int m_nLife;
    const int m_nPilotType;
    
};

#endif