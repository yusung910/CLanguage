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

            //���� ĳ���͸� �̵��Ѵ�.
            objList[0]->SetPos(pos);
            objList[0]->Move();

			//20�ۼ�Ʈ Ȯ���� �� ��
			if (n_ProDropMob <= 5) {
				int doFightFlag = 1;
                //���� ������ �ʱ�ȭ �Ѵ�.
                objList[1]->init();

				//���� ������ ����� ��ġ���� ����
                objList[1]->SetMenuPos(pos);
                //�������� ���
				objList[1]->Display();

                //�޴� ����� ���� ��ġ�� ȣ��
                COORD tmpMpos = objList[1]->GetMenuPos();
                tmpMpos.Y += 1;
                objList[0]->SetMenuPos(tmpMpos);
                objList[0]->Display();

                tmpMpos = objList[0]->GetMenuPos();
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), tmpMpos);
                cout << "�ο�ðڽ��ϱ�? (1. ����, 2.��������) :";

				while (doFightFlag) {
                    
					int intputFightMenu = _getch();
                    
					if (intputFightMenu == 49) {
                        system("cls");
                        //���� ȭ�鿡�� ���� ������ ��ų ����� ����Ѵ�.
					} else if (intputFightMenu == 50) {
                        system("cls");
                        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
                        cout << "*<-(" << objList[0]->GetName() << ")";
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
