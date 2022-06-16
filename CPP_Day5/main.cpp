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
	CObject* objList[2] = { new CUser, new CMonster };

	char userName[20];
	cout << "ĳ���͸��� �Է��� �� EnterŰ�� �Է��Ͽ��ּ���.(10���� �̳�) : ";
	scanf(" %s", userName);

	objList[0]->SetName(userName);

	//���� ���� ����
	bool b_EndFlag = 1;

	COORD pos;

	pos.X = 0;
	pos.Y = 0;

	system("cls");

	cout << "*<-(" << objList[0]->GetName() << ")";

	while (b_EndFlag) {
		//����� �Է� Ű
		int inputKey = _getch();
		//���� �� Ȯ�� ����� ���� ���� ����
		int n_ProDropMob = (rand() % 50) + 1;
		if (inputKey == 224) {
			inputKey = _getch();
			switch (inputKey) {
			case E_DIR_KEY::UP :
				pos.Y = (pos.Y > 0) ? pos.Y - 1 : 0;
				break;
			case E_DIR_KEY::DOWN :
				pos.Y += 1;
				break;
			case E_DIR_KEY::LEFT:
				pos.X = (pos.X > 0) ? pos.X - 1 : 0;
				break;
			case E_DIR_KEY::RIGHT:
				pos.X += 1;
				break;
			}
			system("cls");
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
			cout << "*<-(" << objList[0]->GetName() << ")";
			//20�ۼ�Ʈ Ȯ���� �� ��
			if (n_ProDropMob <= 5) {
				int doFightFlag = 1;
				//���� ���� �ʱ�ȭ
				objList[1]->SetPos(pos);
				objList[1]->init();
				objList[1]->Display();
				COORD tmp = objList[1]->GetPos();
				tmp.Y += 1;
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), tmp);
				cout << "�ο�ðڽ��ϱ�?(1. �ο��, 2. ����ģ��) :";

				while (doFightFlag) {

					int intputFightMenu = _getch();

					if (intputFightMenu == 49) {

					} else if (intputFightMenu == 50) {
                        system("cls");
                        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
                        cout << "*<-(" << objList[0]->GetName() << ")";
                        doFightFlag = 0;
					} else{

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
