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
	system("mode con: cols=150 lines=50");
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

	COORD pos;

	pos.X = 5;
	pos.Y = 5;

	//����� �÷��̾� ���� �޴´�.
	char userName[20];
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	cout << "ĳ���͸��� �Է��� �� EnterŰ�� �Է��Ͽ��ּ���.(10���� �̳�) : ";
	scanf(" %s", userName);

	//���� ĳ���͸� �̵��Ѵ�.
	cout << "\x1B[2J\x1B[H";
	//���׸���
    drawingObj->SetBackground();

	user->SetName(userName);

	while (b_EndFlag) {

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

        user->SetPos(pos);
        user->Move();

		//����� �Է� Ű
		int inputKey = _getch();
		//���� �� Ȯ�� ����� ���� ���� ����
		CONSOLE_SCREEN_BUFFER_INFO presentCur;
		//���� Ŀ�� ��ġ�� �����Ѵ�.
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

			//20�ۼ�Ʈ Ȯ���� �� ��
            //EnterŰ�� ���� ��� ���� ��ġ�� ������� Ȯ���Ѵ�.

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
