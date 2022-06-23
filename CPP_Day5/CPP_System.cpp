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
    //������
    //ȭ�� ũ�� ����
    system("mode con: cols=80 lines=30");

    drawingObj = new CDrawing;
    user = new CUser;
    monster = new CMonster;
    battle = new CBattle;

    GameUserCharacterCreate();
}

CSystem::~CSystem() {
    //�Ҹ���
    //�����迭���� �Ҹ��Ѵ�
    //cout << "CUser :: ��ü �Ҹ���" << endl;
}
void CSystem::GameUserCharacterCreate() {
    //���׸���
    drawingObj->SetBackground();

    //���� ���� ����
    bool b_GameEndFlag = 1;

    //����� �÷��̾� ���� �޴´�.
    char userName[20];
    drawingObj->gotoxy(5, 13);
    cout << "ĳ���͸��� �Է��� �� EnterŰ�� �Է��Ͽ��ּ���.(10���� �̳�) : ";
    scanf(" %s", userName);
    user->SetName(userName);

    GameBasicLoad();
};

void CSystem::GameBasicLoad() {

    //���׸���
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
    //�ʱ� ������ ��ġ�� ����
    COORD cdUserPos = user->GetUserPos();

    while (b_GameEndFlag) {
        //����� �Է� Ű
        int inputKey = _getch();

		drawingObj->gotoxy(cdUserPos);

        printf(" ");
		//����ڰ� �Է��� ����Ű�� ���� �÷��̾��� ĳ���͸� �̵��Ѵ�.
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

		//�������� ��� ����
		if (n_currentBg == E_BACKGROUND_TYPE::DUNGEON) {
			int n_mobGenProp = (rand() & 50) + 1;

			if (n_mobGenProp <= 5) {
				battle->DoBattle(drawingObj, user, monster);
			}
		}
    }
}

//���� �� ��ȣ�ۿ� ����
void CSystem::GameInterPlay() {
	int n_interPlayFlag = 1;
	while (n_interPlayFlag) {
		int n_userInput = _getch();
		drawingObj->PrintOutInnMsg(user);
		switch (n_userInput) {
		case 49:
			//�÷��̾��� ü���� �ִ�ġ���� ȸ���Ѵ�.
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