#include <iostream>
#include <conio.h>
#include "CObject.h"
#include "CMonster.h"
#include "CUser.h"

using namespace std;

void main() {
	CObject* playerObj = new CUser;
	CObject* mob = new CMonster;
	

	//���߿� ����� �̸��� �Է¹޾Ƽ� �־��!
	playerObj->SetName("�÷��̾�");
	int doLoopFlag = 1;
	while (doLoopFlag) {
		cout << "���� ��ų �޴��� �Է��ϼ���(1-3)." << endl;
		cout << "1. ���� Ž��, 2. ĳ��������, 3. ���� ����" << endl;
		int inputTxt = _getch();
		switch (inputTxt) {
		case 49:
			mob->Display();
			cout << "������ �����Ͻðڽ��ϱ�?(1. �ο�� 2. ����ģ��) :" << endl;
			break;
		case 50:
			cout << "ĳ���� ����" << endl;
			playerObj->Display();
			break;
		case 51:
			cout << "���� ����";
			doLoopFlag = 0;
			break;
		default:
			cout << "�߸� �Է��ϼ̽��ϴ�, �ٽ� �Է����ּ���." << endl;
			break;
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
