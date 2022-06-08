#include <iostream>
#include "CUnit.h"
#include "CMonster.h"
#include "CPilot.h"
#include "CDummy.h"

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
	userPilot->SetName("YUS");
    userPilot->Display();

    cout << "���� �� ���� �� : " << mobOne->GetUnitCnt() << endl;

    //CUnit* objUnit = new CUnit;

    //CMonster* pTestCast = static_cast<CMonster*>(objUnit);
    
    //delete pTestCast;
    //delete objUnit;


	CDummy dummies[5] = {
		CDummy(),
		CDummy(),
		CDummy(),
		CDummy(),
		CDummy(),
	};

	for (int i = 0; i < 5; i++) {
		dummies[i].Display();
	}

    delete mobTwo;
    delete userPilot;
    delete mobOne;
}