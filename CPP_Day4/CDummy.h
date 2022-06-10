#ifndef __CDUMMY_H
#define __CDUMMY_H

#include "CUnit.h"

class CDummy {
public:
	CDummy();
	~CDummy();
	int GetDummyScore();
	int GetDummyCnt();
	void Display();
private:
	int m_nHp;
	int m_aPos[2];
	int m_nAddScore;
	static int m_nDummyCnt;
};

#endif