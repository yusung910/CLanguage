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

	//���׸���
    drawingObj->SetBackground();

	//���� ���� ����
	bool b_EndFlag = 1;

	COORD pos;

	pos.X = 30;
	pos.Y = 15;

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
	user->SetPos(pos);
	user->Move();

	while (b_EndFlag) {
		//����� �Է� Ű
		int inputKey = _getch();
		//���� �� Ȯ�� ����� ���� ���� ����
		CONSOLE_SCREEN_BUFFER_INFO presentCur;
		//���� Ŀ�� ��ġ�� �����Ѵ�.
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

			//���׸���
            drawingObj->SetBackground();

			user->SetPos(pos);
			user->Move();

			//20�ۼ�Ʈ Ȯ���� �� ��
			if (n_ProDropMob < 10) {
				CBattle* battle = new CBattle;
				battle->DoBattle(user, monster, pos);
			}
		}

	}
}
