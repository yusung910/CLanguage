#include <iostream>
#include "CUnit.h"
#include "CMonster.h"
#include "CPilot.h"
#include "CDummy.h"

using namespace std;

void main() {
    CUnit* mobTwo;
    CMonster* mobOne;
    CPilot userPilot(99);
	CPilot secUserPilot(45);
    
    //userPilot = new CPilot(99);
	//secUserPilot = new CPilot(45);
    mobOne = new CMonster;
    mobTwo = new CMonster;

    mobOne->CUnit::Display();
    mobTwo->Display();
	userPilot.SetName("YoooSung");
    userPilot.Display();

	secUserPilot.SetName("RGAEM");
	userPilot = secUserPilot;
	userPilot.Display();
	


    cout << "积己 等 蜡粗 荐 : " << mobOne->GetUnitCnt() << endl;

    CUnit* objUnit = new CUnit;

	//Static casting 包访 角青
    //CMonster* pTestCast = static_cast<CMonster*>(objUnit);
	//pTestCast->m_nDps = 0;
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
    //delete userPilot;
    delete mobOne;
}