#include <iostream>
#include <conio.h>
#include <windows.h>
#include "CObject.h"
#include "CMonster.h"
#include "CUser.h"
#include "CDrawing.h"

using namespace std;

enum E_DIR_KEY{
	UP = 72,
	DOWN = 80,
	LEFT = 75,
	RIGHT = 77
};

void main() {
	//화면 크기 조절
	system("mode con: cols=150 lines=50");
    CDrawing* drawingObj = new CDrawing;
	CObject* objList[2] = { new CUser, new CMonster };

	//배경그리기
    drawingObj->SetBackground();

	//게임 종료 여부
	bool b_EndFlag = 1;

	COORD pos;

	pos.X = 30;
	pos.Y = 15;

	//사용자 플레이어 명을 받는다.
	char userName[20];
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	cout << "캐릭터명을 입력한 후 Enter키를 입력하여주세요.(10글자 이내) : ";
	scanf(" %s", userName);

	//유저 캐릭터를 이동한다.
	cout << "\x1B[2J\x1B[H";
	//배경그리기
    drawingObj->SetBackground();

	objList[0]->SetName(userName);
	objList[0]->SetPos(pos);
	objList[0]->Move();

	while (b_EndFlag) {
		//사용자 입력 키
		int inputKey = _getch();
		//몬스터 젠 확률 계산을 위한 난수 생성
		CONSOLE_SCREEN_BUFFER_INFO presentCur;
		//현재 커서 위치를 저장한다.
		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &presentCur);

		int n_ProDropMob = (rand() % 50) + 1;
		if (inputKey == 224) {
			inputKey = _getch();
			switch (inputKey) {
			case E_DIR_KEY::UP :
				pos.Y = (pos.Y > 1) ? pos.Y - 1 : 1;
				break;
			case E_DIR_KEY::DOWN :
				pos.Y = (pos.Y < 48) ? pos.Y + 1 : 48;
				break;
			case E_DIR_KEY::LEFT:
				pos.X = (pos.X > 2) ? pos.X - 1 : 2;
				break;
			case E_DIR_KEY::RIGHT:
				pos.X = (pos.X < 140) ? pos.X + 1 : 140;
				break;
			}

			//배경그리기
            drawingObj->SetBackground();

            objList[0]->SetPos(pos);
            objList[0]->Move();

			//20퍼센트 확률로 몹 젠
			if (n_ProDropMob < 2) {
                //배경그리기
                drawingObj->SetBackground();
                int doFightFlag = 1;
                //몬스터 정보를 초기화 한다.
                objList[1]->init();


                //출력을 위해 임의로 생성한 몬스터와 유저 객체를
                //동적캐스팅(dynamic_cast)해서 할당한다.
                CMonster* tmpMonsterObj = dynamic_cast<CMonster*>(objList[1]);
                CUser* tmpUserObj = dynamic_cast<CUser*>(objList[0]);

				//몬스터 정보 출력
				COORD cdMonsterInfoPos = { 90, 10 };
                drawingObj->SetCdDrawingPos(cdMonsterInfoPos);
                drawingObj->PrintOfInfo(tmpMonsterObj);

				//유저 정보 출력
				COORD cdUserInfo = { 30, 9 };
                drawingObj->SetCdDrawingPos(cdUserInfo);
                drawingObj->PrintOfInfo(tmpUserObj);

				//현재 커서 위치에서 Y값을 증가한다.
                COORD cdFightMenuPos = { 45, 25 };
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cdFightMenuPos);
                cout << "싸우시겠습니까? (1. 전투, 2.도망가기) :";

				while (doFightFlag) {
                    
					int intputFightMenu = _getch();
                    
					if (intputFightMenu == 49) {
                        //화면을 초기화 하고 몬스터의 정보와 유저의 세부 정보를 화면에 표시한다.

						//유저가 사용할 수 있는 기술 목록 출력
					} else if (intputFightMenu == 50) {
						//배경그리기
                        drawingObj->SetBackground();

						objList[0]->SetPos(pos);
						objList[0]->Move();
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
