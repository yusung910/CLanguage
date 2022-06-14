#include <iostream>
#include <conio.h>
#include "CObject.h"
#include "CMonster.h"
#include "CUser.h"

using namespace std;

void main() {
	CObject* playerObj = new CUser;
	CObject* mob = new CMonster;
	

	//나중에 사용자 이름을 입력받아서 넣어보자!
	playerObj->SetName("플레이어");
	int doLoopFlag = 1;
	while (doLoopFlag) {
		cout << "진행 시킬 메뉴를 입력하세요(1-3)." << endl;
		cout << "1. 몬스터 탐색, 2. 캐릭터정보, 3. 게임 종료" << endl;
		int inputTxt = _getch();
		switch (inputTxt) {
		case 49:
			mob->Display();
			cout << "전투를 진행하시겠습니까?(1. 싸운다 2. 도망친다) :" << endl;
			break;
		case 50:
			cout << "캐릭터 정보" << endl;
			playerObj->Display();
			break;
		case 51:
			cout << "게임 종료";
			doLoopFlag = 0;
			break;
		default:
			cout << "잘못 입력하셨습니다, 다시 입력해주세요." << endl;
			break;
		}

	}
	

	//for (int i = 0; i < 2; i++) {
	//	switch (listObj[i]->GetType())
	//	{
	//	case TYPE::E_C_USER :
	//		listObj[i]->SetName("플레이어1");
	//		break;
	//	case TYPE::E_C_MONSTER :
	//		break;
	//	}
	//	listObj[i]->Display();
	//}

	////게임종료를 위한 객체 제거
	//for (int a = 0; a < 2; a++) {
	//	delete listObj[a];
	//}
}
