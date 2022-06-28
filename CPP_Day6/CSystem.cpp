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

		//�޴� ���
		PrintSelectedMenu(nMainMenu, true);

		if (GetAsyncKeyState(VK_RETURN)) {
			//�÷��̾ ����Ű�� ������ ���
			switch (nMainMenu) {

			case E_MAIN_MENU::NEW_GAME:
				//���ο� ���� ������ ���� ������ ����
                CreatePlayerData();
			case E_MAIN_MENU::CONTINUE_GAME:
				//����� ������ �ҷ��´�.
				
				//���� ���� ���� ȭ���� �ʱ�ȭ�Ѵ�.
				ClearDisplay(E_DISPLAY::GAME);
				ClearDisplay(E_DISPLAY::SYSTEM);

				//ó�� ���� ȭ���� �׸���
				PrintVillageBackground();
                //�÷��̾��� ��
                o_player->SetPlayerPos({40, 18});
                //�÷��̸� �����Ѵ�
                PlayGame();


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
    //�÷��̾� ĳ���� ���� �Է¿�û�ϱ� ���� �޼��� ���
    PrintCreatePlayerMsg();
    //�ӽ÷� ĳ���͸��� ������ �迭�� ����
    char c_tmpCharName[200];
    scanf(" %s", c_tmpCharName);
    //ĳ���͸��� ����� CString Ŭ���� ����
    o_player->SetName(CString(c_tmpCharName));
    //�ý��� �޼����� Ŭ�����Ѵ�.
    ClearDisplay(E_DISPLAY::SYSTEM);
}

void CSystem::LoadPlayerData() {

}

void CSystem::PlayGame() {

    int nMoveChar = 1;

    while (nMoveChar) {
        //�÷��̾��� ��ġ
        COORD cdPlayerPos = o_player->GetPlayerPos();

        int n_playX = cdPlayerPos.X;
        int n_playY = cdPlayerPos.Y;

        //����� �Է� Ű
        int inputKey = _getch();
        if (GetAsyncKeyState(VK_UP) & 0x0001) {
            n_playY -= 1;
        }
        if (GetAsyncKeyState(VK_DOWN) & 0x0001) {
            n_playY += 1;
        }
        if (GetAsyncKeyState(VK_LEFT) & 0x0001) {
            n_playX -= 1;
        }
        if (GetAsyncKeyState(VK_RIGHT) & 0x0001) {
            n_playX += 1;
        }

        if (m_nLend[n_playY][n_playX] != E_BACKGROUND::WALL) {
            COORD cdNextPos = { n_playX, n_playY };
            o_player->SetPlayerPos(cdNextPos);
            MovePlayer(cdPlayerPos, cdNextPos);
        }
    }
}

void CSystem::MovePlayer(COORD cdPrevPos, COORD cdNextPos) {
    //�̵��ϱ� �� ��ġ ���� �Ű������� �޾� �����
    if (m_nLend[cdPrevPos.Y][cdPrevPos.X] != E_BACKGROUND::WALL) {
        SetPos(cdPrevPos);
        cout << "  ";
        SetPos(cdNextPos);
        cout << "��";
    }

}