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
	//ȭ�� ũ�� ����
	system("mode con: cols=80 lines=30");
    CDrawing* drawingObj = new CDrawing;
	CUser* user = new CUser;
	CMonster* monster =  new CMonster;
    CBattle* battle = new CBattle;

    //���� ���
    int n_currentBg = E_BACKGROUND_TYPE::VILLAGE;

	//���׸���
    drawingObj->SetBackground();

	//���� ���� ����
	bool b_EndFlag = 1;

	//����� �÷��̾� ���� �޴´�.
	char userName[20];
	drawingObj->gotoxy(5,13);
	cout << "ĳ���͸��� �Է��� �� EnterŰ�� �Է��Ͽ��ּ���.(10���� �̳�) : ";
	scanf(" %s", userName);
	user->SetName(userName);

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

	int nUserX = 5;
	int nUserY = 20;
	drawingObj->gotoxy(nUserX, nUserY);
	user->Move();

	while (b_EndFlag) {

		//����� �Է� Ű
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

			//20�ۼ�Ʈ Ȯ���� �� ��

			int n_ProDropMob = (rand() % 50) + 1;
            if (n_currentBg == E_BACKGROUND_TYPE::DUNGEON) {
                drawingObj->PrintDungeon();
                
                //if (n_ProDropMob < 5) {
                //    battle->DoBattle(user, monster, pos);
                //}
            }
		}
		else if (inputKey == 13) {
			////������ �ǹ��� ��ġ�� �� ����Ű�� ������� �̺�Ʈ�� �߻�
			////EnterŰ�� ���� ��� ���� ��ġ�� ������� Ȯ���Ѵ�.
			//int nMap = drawingObj->GetUserPosBuild(pos, n_currentBg);
			//n_currentBg = nMap;
			//if (nMap == E_BACKGROUND_TYPE::VILLAGE) {

			//	//drawingObj->PrintOfHome();

			//	if (nMap == E_BACKGROUND_TYPE::INN) {
			//		//ü�� ȸ�� ���θ� ���� ������ ȭ�鿡 ǥ���ϰ�
			//		//���� ��ȭ�� �Ҹ��� �� ü���� �ִ�ġ ���� ȸ���Ѵ�.
			//		COORD cdInnMsgPos = { 45, 26 };
			//		drawingObj->SetMsgPos(cdInnMsgPos);
			//		drawingObj->PrintOutInnMsg(user);
			//		int nInputInn = _getch();
			//		if (nInputInn == 49) {
			//			//������ ü���� �ִ�ġ ��ŭ ȸ���Ѵ�.
			//			user->SetUserHP(user->GetUserMaxHp());
			//			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cdInnMsgPos);
			//			cout << "ȸ���� �Ϸ�Ǿ����ϴ�, �ƹ� Ű�� ���� ��� �����ϼ���.";
			//			_getch();
			//		}
			//	}
			//}
		}
		else if (inputKey == 27) {
			//escŰ�� ������ ��� ����� ������ �� �� �ִ� �޴��� ����Ѵ�.
			COORD cdUserInfoPos = { 75, 30 };
			drawingObj->SetMsgPos(cdUserInfoPos);
			drawingObj->PrintOfCombatInfo(user);
			_getch();
		}
	}
}
