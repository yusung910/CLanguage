#ifndef __MONTER_H
#define __MONTER_H

#include "CUnit.h"

class CMonster : public CUnit {
public:
    CMonster();
    ~CMonster();

    void Display();
    void Init();

private:
    int m_nDps;
    int m_nHp;
};

#endif