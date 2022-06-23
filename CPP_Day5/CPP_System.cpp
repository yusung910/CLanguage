#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>

#include "CSystem.h"
#include "CObject.h"
#include "CMonster.h"
#include "CUser.h"
#include "CDrawing.h"
#include "CBattle.h"

using namespace std;

CSystem::CSystem() {
    //생성자
    //화면 크기 조절
    system("mode con: cols=80 lines=30");

    drawingObj = new CDrawing;
    user = new CUser;
    monster = new CMonster;
    battle = new CBattle;

    GameUserCharacterCreate();
}

CSystem::~CSystem() {
    //소멸자
    //동적배열들을 소멸한다
    //cout << "CUser :: 객체 소멸자" << endl;
}
void CSystem::GameUserCharacterCreate() {
    //배경그리기
    drawingObj->SetBackground();

    //게임 종료 여부
    bool b_GameEndFlag = 1;

    //사용자 플레이어 명을 받는다.
    char userName[20];
    drawingObj->gotoxy(5, 13);
    cout << "캐릭터명을 입력한 후 Enter키를 입력하여주세요.(10글자 이내) : ";
    scanf(" %s", userName);
    user->SetName(userName);

    GameBasicLoad();
};

void CSystem::GameBasicLoad() {

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

    drawingObj->gotoxy(user->GetUserPos());

    user->Move();

    GamePlaying();
}

void CSystem::GamePlaying() {
    //초기 유저의 위치를 세팅
    COORD cdUserPos = user->GetUserPos();

    while (b_GameEndFlag) {
        //사용자 입력 키
        int inputKey = _getch();

		drawingObj->gotoxy(cdUserPos);

        printf(" ");
		//사용자가 입력한 방향키에 따라 플레이어의 캐릭터를 이동한다.
		if (GetAsyncKeyState(VK_UP)){
            cdUserPos.Y -= 1;
            if (drawingObj->nArryMap[cdUserPos.Y][cdUserPos.X] == 1) {
                cdUserPos.Y += 1;
            }
		}
		if (GetAsyncKeyState(VK_DOWN)) {
			cdUserPos.Y += 1;
			if (drawingObj->nArryMap[cdUserPos.Y][cdUserPos.X] == 1) {
				cdUserPos.Y -= 1;
			}
		}
		if (GetAsyncKeyState(VK_LEFT)) {
			cdUserPos.X -= 1;
			if (drawingObj->nArryMap[cdUserPos.Y][cdUserPos.X] == 1) {
				cdUserPos.X += 1;
			}
		}
		if (GetAsyncKeyState(VK_RIGHT)) {
			cdUserPos.X += 1;
			if (drawingObj->nArryMap[cdUserPos.Y][cdUserPos.X] == 1) {
				cdUserPos.X -= 1;
			}
		}

        drawingObj->gotoxy(cdUserPos);

        user->Move();

        int n_loadMap = drawingObj->GetUserPosBuild(cdUserPos, n_currentBg);

        if (n_currentBg != n_loadMap) {
            n_currentBg = n_loadMap;
            switch (n_currentBg) {
            case E_BACKGROUND_TYPE::DUNGEON:
                user->SetUserPos(10, 10);
                GameBasicLoad();
                break;
            case E_BACKGROUND_TYPE::VILLAGE:
                user->SetUserPos(10, 20);
                GameBasicLoad();
                break;
			case E_BACKGROUND_TYPE::INN:
				GameInterPlay();
				break;
            }
        }

		//던전에서 사냥 진행
		if (n_currentBg == E_BACKGROUND_TYPE::DUNGEON) {
			int n_mobGenProp = (rand() & 50) + 1;

			if (n_mobGenProp <= 5) {
				battle->DoBattle(drawingObj, user, monster);
			}
		}
    }
}

//게임 내 상호작용 진행
void CSystem::GameInterPlay() {
	int n_interPlayFlag = 1;
	while (n_interPlayFlag) {
		int n_userInput = _getch();
		drawingObj->PrintOutInnMsg(user);
		switch (n_userInput) {
		case 49:
			//플레이어의 체력을 최대치까지 회복한다.
			user->SetUserHP(user->GetUserMaxHp());
			drawingObj->ClearMsgArea();
			drawingObj->PrintOutCompleteMsg();
			_getch();
		case 50:
			drawingObj->ClearMsgArea();

			user->SetUserPos(10, 20);
			user->Move();
			
			n_interPlayFlag = 0;
			break;
		}
	}
}