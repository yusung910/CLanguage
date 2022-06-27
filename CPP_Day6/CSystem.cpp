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
				//���ο� ���� ������ ���� ������ ����
                CreatePlayerData();
				break;
			case E_MAIN_MENU::CONTINUE_GAME:
				//����� ������ �ҷ��´�.
				break;
			case E_MAIN_MENU::CREDIT:
				//������ ������ ���
				break;
			}
            doSelectedMenuFlag = 0;
		}
	}
};

void CSystem::CreatePlayerData() {
	//�ý��� �޼��� ��� ȭ���� �ʱ�ȭ�Ѵ�.
	ClearDisplay(E_DISPLAY::SYSTEM);
    //�÷��̾� ��ü ����
    o_player = new CPlayer;
    //�÷��̾� ĳ���� ���� �Է�.
    PrintCreatePlayerMsg();
    //�ӽ÷� ĳ���͸��� ������ �迭�� ����
    char c_tmpCharName[200];
    scanf(" %s", c_tmpCharName);
    //ĳ���͸��� ����� CString Ŭ���� ����
    o_player->SetPlayerName(CString(c_tmpCharName));
    //�ý��� �޼����� Ŭ�����Ѵ�.
    ClearDisplay(E_DISPLAY::SYSTEM);
}

void CSystem::LoadPlayerData() {

}