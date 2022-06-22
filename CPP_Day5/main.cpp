#include <iostream>
#include <conio.h>
#include <windows.h>
#include "CObject.h"
#include "CMonster.h"
#include "CUser.h"
#include "CDrawing.h"
#include "CBattle.h"

using namespace std;

enum E_DIR_KEY{
	UP = 72,
	DOWN = 80,
	LEFT = 75,
	RIGHT = 77
};


void main() {
	//화면 크기 조절
	system("mode con: cols=80 lines=30");
    CDrawing* drawingObj = new CDrawing;
	CUser* user = new CUser;
	CMonster* monster =  new CMonster;
    CBattle* battle = new CBattle;

    //현재 배경
    int n_currentBg = E_BACKGROUND_TYPE::VILLAGE;

	//배경그리기
    drawingObj->SetBackground();

	//게임 종료 여부
	bool b_EndFlag = 1;

	//사용자 플레이어 명을 받는다.
	char userName[20];
	drawingObj->gotoxy(5,13);
	cout << "캐릭터명을 입력한 후 Enter키를 입력하여주세요.(10글자 이내) : ";
	scanf(" %s", userName);
	user->SetName(userName);

	//배경그리기
	drawingObj->SetBackground();

	switch (n_currentBg) {
	case E_BACKGROUND_TYPE::VILLAGE:
	case E_BACKGROUND_TYPE::INN:
	case E_BACKGROUND_TYPE::STORE:
		drawingObj->PrintOfHome();
		break;
	case E_BACKGROUND_TYPE::DUNGEON:
		drawingObj->PrintDungeon();

	}

	int nUserX = 5;
	int nUserY = 20;
	drawingObj->gotoxy(nUserX, nUserY);
	user->Move();

	while (b_EndFlag) {

		//사용자 입력 키
		int inputKey = _getch();

		drawingObj->gotoxy(nUserX, nUserY);
		printf("  ");
		
		if (inputKey == 224) {
			
			inputKey = _getch();
			switch (inputKey) {
			case E_DIR_KEY::UP :
				nUserY = (nUserY > 1) ? nUserY - 2 : 1;
				break;
			case E_DIR_KEY::DOWN :
				nUserY = (nUserY < 48) ? nUserY + 2 : 48;
				break;
			case E_DIR_KEY::LEFT:
				nUserX = (nUserX > 2) ? nUserX - 2 : 1;
				break;
			case E_DIR_KEY::RIGHT:
				nUserX = (nUserX < 147) ? nUserX + 2 : 147;
				break;
			}
			

			drawingObj->gotoxy(nUserX, nUserY);
			
            user->Move();

			//20퍼센트 확률로 몹 젠

			int n_ProDropMob = (rand() % 50) + 1;
            if (n_currentBg == E_BACKGROUND_TYPE::DUNGEON) {
                drawingObj->PrintDungeon();
                
                //if (n_ProDropMob < 5) {
                //    battle->DoBattle(user, monster, pos);
                //}
            }
		}
		else if (inputKey == 13) {
			////마을의 건물에 위치한 후 엔터키를 누를경우 이벤트를 발생
			////Enter키를 누를 경우 현재 위치가 어디인지 확인한다.
			//int nMap = drawingObj->GetUserPosBuild(pos, n_currentBg);
			//n_currentBg = nMap;
			//if (nMap == E_BACKGROUND_TYPE::VILLAGE) {

			//	//drawingObj->PrintOfHome();

			//	if (nMap == E_BACKGROUND_TYPE::INN) {
			//		//체력 회복 여부를 묻는 질문을 화면에 표시하고
			//		//일정 재화를 소모한 뒤 체력을 최대치 까지 회복한다.
			//		COORD cdInnMsgPos = { 45, 26 };
			//		drawingObj->SetMsgPos(cdInnMsgPos);
			//		drawingObj->PrintOutInnMsg(user);
			//		int nInputInn = _getch();
			//		if (nInputInn == 49) {
			//			//유저의 체력을 최대치 만큼 회복한다.
			//			user->SetUserHP(user->GetUserMaxHp());
			//			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cdInnMsgPos);
			//			cout << "회복이 완료되었습니다, 아무 키나 눌러 계속 진행하세요.";
			//			_getch();
			//		}
			//	}
			//}
		}
		else if (inputKey == 27) {
			//esc키를 눌렀을 경우 사용자 정보를 볼 수 있는 메뉴를 출력한다.
			COORD cdUserInfoPos = { 75, 30 };
			drawingObj->SetMsgPos(cdUserInfoPos);
			drawingObj->PrintOfCombatInfo(user);
			_getch();
		}
	}
}
