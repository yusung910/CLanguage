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
	system("mode con: cols=150 lines=50");
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

	COORD pos;

	pos.X = 5;
	pos.Y = 5;

	//사용자 플레이어 명을 받는다.
	char userName[20];
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	cout << "캐릭터명을 입력한 후 Enter키를 입력하여주세요.(10글자 이내) : ";
	scanf(" %s", userName);

	//유저 캐릭터를 이동한다.
	cout << "\x1B[2J\x1B[H";
	//배경그리기
    drawingObj->SetBackground();

	user->SetName(userName);

	while (b_EndFlag) {

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

        user->SetPos(pos);
        user->Move();

		//사용자 입력 키
		int inputKey = _getch();
		//몬스터 젠 확률 계산을 위한 난수 생성
		CONSOLE_SCREEN_BUFFER_INFO presentCur;
		//현재 커서 위치를 저장한다.
		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &presentCur);

		
		if (inputKey == 224) {
			inputKey = _getch();
			switch (inputKey) {
			case E_DIR_KEY::UP :
				pos.Y = (pos.Y > 1) ? pos.Y - 5 : 1;
				break;
			case E_DIR_KEY::DOWN :
				pos.Y = (pos.Y < 48) ? pos.Y + 5 : 48;
				break;
			case E_DIR_KEY::LEFT:
				pos.X = (pos.X > 2) ? pos.X - 5 : 1;
				break;
			case E_DIR_KEY::RIGHT:
				pos.X = (pos.X < 147) ? pos.X + 5 : 147;
				break;
			}

            user->SetPos(pos);
            user->Move();

			//20퍼센트 확률로 몹 젠
            //Enter키를 누를 경우 현재 위치가 어디인지 확인한다.

            int nMap = drawingObj->GetUserPosBuild(pos, n_currentBg);

            int n_ProDropMob = (rand() % 50) + 1;
            n_currentBg = nMap;
            if (nMap == E_BACKGROUND_TYPE::DUNGEON) {
                drawingObj->PrintDungeon();
                
                if (n_ProDropMob < 5) {
                    battle->DoBattle(user, monster, pos);
                }
            }
            else {
                drawingObj->PrintOfHome();
                if (nMap == E_BACKGROUND_TYPE::INN) {
                    
                }
            }
        }
	}
}
