#include <iostream>
#include "CUnit.h"
#include "CMonster.h"
#include "CPilot.h"

using namespace std;

void main() {
    CUnit* mobTwo;
    CMonster* mobOne;
    CPilot* userPilot;
    
    userPilot = new CPilot(1);
    mobOne = new CMonster;
    mobTwo = new CMonster;

    mobOne->CUnit::Display();
    mobTwo->Display();
    userPilot->Display();

    cout << "생성 된 유닛 수 : " << mobOne->GetUnitCnt() << endl;

    //CUnit* objUnit = new CUnit;

    //CMonster* pTestCast = static_cast<CMonster*>(objUnit);
    
    //delete pTestCast;
    //delete objUnit;

    delete mobTwo;
    delete userPilot;
    delete mobOne;
}