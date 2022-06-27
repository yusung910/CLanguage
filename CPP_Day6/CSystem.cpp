#include "CSystem.h"

CSystem::CSystem() {
    //������
    //ȭ�� ũ�� ����
    system("mode con: cols=80 lines=30");

    //ȭ���� �⺻ �׵θ��� �׸���.
    PrintDisplayRound();
	//���� �޴� ��� ����
	SelectedMainMenu();
};

CSystem::~CSystem() {

}

void CSystem::SelectedMainMenu() {
	//�÷��̾��� �޴� ���� ���� ����
	int doSelectedMenuFlag = 1;
	//������ ���� �޴�
	int nMainMenu = 1;
	//����ȭ�鿡 �޴��� ����Ѵ�.
	PrintDisplayMenu();

	PrintSelectedMenu(nMainMenu, true);
	while (doSelectedMenuFlag) {
		//����� �Է� Ű
		int inputKey = _getch();
		PrintSelectedMenu(nMainMenu, false);
		//����ڰ� �Է��� ����Ű�� ���� �޴� ������ �����δ�.
		if (GetAsyncKeyState(VK_UP) & 0x0001) {
			nMainMenu = (nMainMenu > E_MAIN_MENU::NEW_GAME) ? nMainMenu -= 1 : E_MAIN_MENU::NEW_GAME;
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x0001) {
			nMainMenu = (nMainMenu < E_MAIN_MENU::CREDIT) ? nMainMenu += 1 : E_MAIN_MENU::CREDIT;
		}

		PrintSelectedMenu(nMainMenu, true);


		if (GetAsyncKeyState(VK_RETURN)) {
			//�÷��̾ ����Ű�� ������ ���
			switch (nMainMenu) {
			case E_MAIN_MENU::NEW_GAME:
				//���ο� ���� ����
				GameStart();
				break;
			case E_MAIN_MENU::CONTINUE_GAME:
				//����� ������ �ҷ��´�.
				break;
			case E_MAIN_MENU::CREDIT:
				//������ ������ ���
				break;
			}
		}
	}
};

void CSystem::GameStart() {
	//�ý��� �޼��� ��� ȭ���� �ʱ�ȭ�Ѵ�.
	ClearDisplay(E_DISPLAY::SYSTEM);
	//cout << "������ �����մϴ�, ��ø� ��ٷ��ּ���...";
}