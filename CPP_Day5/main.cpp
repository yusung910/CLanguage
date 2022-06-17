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
	//ȭ�� ũ�� ����
	system("mode con: cols=150 lines=50");

	CObject* objList[2] = { new CUser, new CMonster };

	//���׸���
	objList[0]->DrawingBackGround();

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
	objList[0]->DrawingBackGround();

	objList[0]->SetName(userName);
	objList[0]->SetPos(pos);
	objList[0]->Move();

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
			objList[0]->DrawingBackGround();

            objList[0]->SetPos(pos);
            objList[0]->Move();

			//20�ۼ�Ʈ Ȯ���� �� ��
			if (n_ProDropMob < 2) {
				int doFightFlag = 1;
                //���� ������ �ʱ�ȭ �Ѵ�.
                objList[1]->init();

				//���� ���� ���
				COORD cdMonsterInfo = { 90, 10 };
				objList[1]->SetMenuPos(cdMonsterInfo);
				objList[1]->Display();

				//���� ���� ���
				COORD cdUserInfo = { 30, 9 };
				objList[0]->SetMenuPos(cdUserInfo);
				objList[0]->Display();

				//���� Ŀ�� ��ġ���� Y���� �����Ѵ�.
				presentCur.dwCursorPosition.Y += 1;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), presentCur.dwCursorPosition);
				
                cout << "�ο�ðڽ��ϱ�? (1. ����, 2.��������) :";

				while (doFightFlag) {
                    
					int intputFightMenu = _getch();
                    
					if (intputFightMenu == 49) {
                        //ȭ���� �ʱ�ȭ �ϰ� ������ ������ ������ ���� ������ ȭ�鿡 ǥ���Ѵ�.

						//������ ����� �� �ִ� ��� ��� ���
					} else if (intputFightMenu == 50) {
						//���׸���
						objList[0]->DrawingBackGround();

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
	//		listObj[i]->SetName("�÷��̾�1");
	//		break;
	//	case TYPE::E_C_MONSTER :
	//		break;
	//	}
	//	listObj[i]->Display();
	//}

	////�������Ḧ ���� ��ü ����
	//for (int a = 0; a < 2; a++) {
	//	delete listObj[a];
	//}
}
