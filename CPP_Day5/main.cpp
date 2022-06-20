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
			if (n_ProDropMob < 10) {
                //배경그리기
                drawingObj->SetBackground();
                int doFightFlag = 1;
                //몬스터 정보를 초기화 한다.
                objList[1]->init();


                //출력을 위해 임의로 생성한 몬스터와 유저 객체를
                //동적캐스팅(dynamic_cast)해서 할당한다.
                CMonster* tmpMonsterObj = dynamic_cast<CMonster*>(objList[1]);
                CUser* tmpUserObj = dynamic_cast<CUser*>(objList[0]);
                CSkill* tmpUserSkillObj = dynamic_cast<CSkill*>(objList[0]);

				//몬스터 정보 출력
				COORD cdMonsterInfoPos = { 90, 10 };
                drawingObj->SetCdDrawingPos(cdMonsterInfoPos);
                drawingObj->PrintOfInfo(tmpMonsterObj);

				//유저 정보 출력
				COORD cdUserInfo = { 30, 9 };
                drawingObj->SetCdDrawingPos(cdUserInfo);
                drawingObj->PrintOfInfo(tmpUserObj);

				//전투 여부를 묻는다.
                COORD cdFightMenuPos = { 45, 25 };
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cdFightMenuPos);
                cout << "싸우시겠습니까? (1. 전투, 2.도망가기) :";

				while (doFightFlag) {
                    
					int intputFightMenu = _getch();
                    
					if (intputFightMenu == 49) {

                        //화면을 초기화 하고 몬스터의 정보와 유저의 세부 정보를 화면에 표시한다.
                        //배경그리기
                        drawingObj->SetBackground();
                        //몬스터 정보 출력
                        drawingObj->SetCdDrawingPos(cdMonsterInfoPos);
                        drawingObj->PrintOfInfo(tmpMonsterObj);
                        //유저 정보 출력
                        drawingObj->SetCdDrawingPos(cdUserInfo);
                        drawingObj->PrintOfInfo(tmpUserObj);

						//유저가 사용할 수 있는 기술 목록 출력
                        drawingObj->SetCdDrawingPos(cdFightMenuPos);
                        drawingObj->PrintUserSkillList(tmpUserSkillObj);


						//스킬 선택하는 구문
						int n_doUseSkillFlag = 1;

						while (n_doUseSkillFlag) {
						
							//사용자가 공격스킬을 선택한다.
							int n_useSkill = (_getch() - 48);

							//사용자가 입력한 값에 해당하는 스킬명을 가져온다.
							char* useSkill = tmpUserSkillObj->GetSkillName(n_useSkill);

							//배경그리기
							drawingObj->SetBackground();

							//몬스터 정보 출력
							drawingObj->SetCdDrawingPos(cdMonsterInfoPos);
							drawingObj->PrintOfInfo(tmpMonsterObj);

							//유저 정보 출력
							drawingObj->SetCdDrawingPos(cdUserInfo);
							drawingObj->PrintOfInfo(tmpUserObj);

							if (useSkill == NULL) {
								drawingObj->SetCdDrawingPos(cdFightMenuPos);
								SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cdFightMenuPos);
								cout << "사용할 수 없는 기술입니다. 다시 입력하여주세요.";
								drawingObj->SetCdDrawingPos(cdFightMenuPos);
								drawingObj->PrintUserSkillList(tmpUserSkillObj);
							} else {
								//배경그리기
								drawingObj->SetBackground();

								//플레이어가 사용한 공격 스킬을 세팅한다.
								tmpUserObj->SetUsingSkill(n_useSkill);
								//플레이어의 공격내용을 화면에 출력한다.
								drawingObj->PrintUserSkillAttack(tmpUserObj, tmpMonsterObj);
								//몬스터의 체력을 감소한다.
								tmpMonsterObj->SetMonsterHP(tmpMonsterObj->GetMonsterHP() - tmpUserObj->Attack());

								//몬스터의 공격내용을 화면에 출력한다.
								drawingObj->PrintMonsterAttack(tmpUserObj, tmpMonsterObj);
								//플레이어의 체력을 감소한다.
								tmpUserObj->SetUserHP(tmpUserObj->GetUserHp() - tmpMonsterObj->Attack());

								//몬스터 정보 출력
								drawingObj->SetCdDrawingPos(cdMonsterInfoPos);
								drawingObj->PrintOfInfo(tmpMonsterObj);

								//유저 정보 출력
								drawingObj->SetCdDrawingPos(cdUserInfo);
								drawingObj->PrintOfInfo(tmpUserObj);

								//사용 기술 정보 출력
								drawingObj->SetCdDrawingPos(cdFightMenuPos);
								drawingObj->PrintUserSkillList(tmpUserSkillObj);
							}
						}
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
}
