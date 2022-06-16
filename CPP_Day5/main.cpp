#include <iostream>
#include <conio.h>
#include <windows.h>
#include "CObject.h"
#include "CMonster.h"
#include "CUser.h"

using namespace std;

enum E_DIR_KEY{
	UP = 72,
	DOWN = 80,
	LEFT = 75,
	RIGHT = 77
};

void main() {
	CObject* objList[2] = { new CUser, new CMonster };

	char userName[20];
	cout << "캐릭터명을 입력한 후 Enter키를 입력하여주세요.(10글자 이내) : ";
	scanf(" %s", userName);

	objList[0]->SetName(userName);

	//게임 종료 여부
	bool b_EndFlag = 1;

	COORD pos;

	pos.X = 0;
	pos.Y = 0;

	system("cls");

	cout << "*<-(" << objList[0]->GetName() << ")";

	while (b_EndFlag) {
		//사용자 입력 키
		int inputKey = _getch();
		//몬스터 젠 확률 계산을 위한 난수 생성
		int n_ProDropMob = (rand() % 50) + 1;
		if (inputKey == 224) {
			inputKey = _getch();
			switch (inputKey) {
			case E_DIR_KEY::UP :
				pos.Y = (pos.Y > 0) ? pos.Y - 1 : 0;
				break;
			case E_DIR_KEY::DOWN :
				pos.Y += 1;
				break;
			case E_DIR_KEY::LEFT:
				pos.X = (pos.X > 0) ? pos.X - 1 : 0;
				break;
			case E_DIR_KEY::RIGHT:
				pos.X += 1;
				break;
			}

            //유저 캐릭터를 이동한다.
            objList[0]->SetPos(pos);
            objList[0]->Move();

			//20퍼센트 확률로 몹 젠
			if (n_ProDropMob <= 5) {
				int doFightFlag = 1;
                //몬스터 정보를 초기화 한다.
                objList[1]->init();

				//몬스터 정보를 출력할 위치값을 설정
                objList[1]->SetMenuPos(pos);
                //몬스터정보 출력
				objList[1]->Display();

                //메뉴 출력을 위한 위치값 호출
                COORD tmpMpos = objList[1]->GetMenuPos();
                tmpMpos.Y += 1;
                objList[0]->SetMenuPos(tmpMpos);
                objList[0]->Display();

                tmpMpos = objList[0]->GetMenuPos();
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), tmpMpos);
                cout << "싸우시겠습니까? (1. 전투, 2.도망가기) :";

				while (doFightFlag) {
                    
					int intputFightMenu = _getch();
                    
					if (intputFightMenu == 49) {
                        system("cls");
                        //현재 화면에서 몬스터 정보와 스킬 목록을 출력한다.
					} else if (intputFightMenu == 50) {
                        system("cls");
                        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
                        cout << "*<-(" << objList[0]->GetName() << ")";
                        doFightFlag = 0;
					}
				}
			}
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
