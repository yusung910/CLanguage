#include <iostream>
#include <conio.h>
#include "CObject.h"
#include "CMonster.h"
#include "CUser.h"

using namespace std;

void main() {
	CObject* objList[2] = { new CUser, new CMonster };
	

	//���߿� ����� �̸��� �Է¹޾Ƽ� �־��!
	objList[0]->SetName("�÷��̾�");
	int doLoopFlag = 1;
	while (doLoopFlag) {
		cout << "���� ��ų �޴��� �Է��ϼ���(1-3)." << endl;
		cout << "1. ���� Ž��, 2. ĳ��������, 3. ���� ����" << endl;
		int inputTxt = _getch();
		if (inputTxt == 49) {
			int doFightFlag = 1;
			//���͸� ����Ѵ�
			objList[1]->init();
			
			while (doFightFlag) {
				objList[1]->Display();
				cout << "������ �����Ͻðڽ��ϱ�?(1. �ο�� 2. ����ģ��) :" << endl;
				int nSelectFight = _getch();
				
				if (nSelectFight == 49) {
					//������ ��ų ����� ȣ���Ѵ�.
					objList[0]->ShowSkillList();
				}
				else if (nSelectFight == 50) {
					doFightFlag = 0;
				}
				else {
					cout << "�߸� �Է��ϼ̽��ϴ�, �ٽ� �Է����ּ���." << endl;
				}
			}
		}
		else if (inputTxt == 50) {
			cout << "ĳ���� ����" << endl;
			objList[0]->Display();
		}
		else if (inputTxt == 51) {
			cout << "���� ����";
			doLoopFlag = 0;
		}
		else {
			cout << "�߸� �Է��ϼ̽��ϴ�, �ٽ� �Է����ּ���." << endl;
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
