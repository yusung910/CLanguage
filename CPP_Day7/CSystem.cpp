#include "CSystem.h"    

CSystem::CSystem() {
    //�ý��� ������
    system("mode con: cols=151 lines=50");

    //���� �޴� 
    ShowMainMenu();
}

CSystem::~CSystem() {
    //�ý��� �Ҹ���
}

void CSystem::ShowMainMenu() {
    //Ŀ�� �����
    HideConsoleCursor();
    //�ݺ��� �÷���
    int doSelectMainMenu = 1;
    //���� ���ø޴�
    int selectedMainMenu = 0;

    while (doSelectMainMenu) {
        unsigned long Timer = GetTickCount();

        if (GetTickCount() >= Timer + (1000 / m_nFrame)) {

            PrintCtntCenter(12, String("Game Title!!"));
            PrintCtntCenter(38, String("���ν���"));
            PrintCtntCenter(39, String("����ϱ�"));
            PrintCtntCenter(40, String("Credit"));

            if (GetAsyncKeyState(VK_UP) & 0x0001) {
                selectedMainMenu = (selectedMainMenu > E_MAIN_MENU::E_NEW_START) ? selectedMainMenu -= 1 : E_MAIN_MENU::E_NEW_START;
            }
            if (GetAsyncKeyState(VK_DOWN) & 0x0001) {
                selectedMainMenu = (selectedMainMenu < E_MAIN_MENU::E_CREDIT) ? selectedMainMenu += 1 : E_MAIN_MENU::E_CREDIT;
            }

            PrintCtnt(68, 38, "  ");
            PrintCtnt(68, 39, "  ");
            PrintCtnt(69, 40, "  ");

            switch (selectedMainMenu) {
            case E_MAIN_MENU::E_NEW_START:
                PrintCtnt(68, 38, "��");
                break;
            case E_MAIN_MENU::E_CONTINUE:
                PrintCtnt(68, 39, "��");
                break;
            case E_MAIN_MENU::E_CREDIT:
                PrintCtnt(69, 40, "��");
                break;
            }

            if (GetAsyncKeyState(VK_RETURN)) {
                //�ݺ��� �ߴ�
                doSelectMainMenu = 0;
                switch (selectedMainMenu) {
                case E_MAIN_MENU::E_NEW_START:
                    //�÷��̾� ����
                    CreatePlayerObject();
                    break;
                case E_MAIN_MENU::E_CONTINUE:
                    break;
                case E_MAIN_MENU::E_CREDIT:
                    break;
                }
            }
        }
    }
}

void CSystem::CreatePlayerObject() {
    char chr[200];
    m_player = new Player;

    ShowConsoleCursor();

    //ȭ�� Ŭ����
    DisplayClear();
    //�޴�����ȭ�鿡�� �Էµ� enter�� ������ �Է� ���� Ŭ����
    getchar();

    PrintCtntCenter(24, "�÷��̾� �̸��� �Է��Ͽ� �ּ���: ");
    scanf(" %s", &chr);

    //�÷��̾� ��ü ����
    m_player->SetName(chr);

    //Ŀ�� �����
    HideConsoleCursor();

    //�÷��̾� ���� �� Ŭ����
    DisplayClear();

    //���� �÷��� ������ �׸���.
    InitBasicDisplayArea();
}

void CSystem::InitBasicDisplayArea() {
    //��� ������ land�� �⺻ �ʱ�ȭ
    for (int i = 0; i < m_nDisplayX; i++) {
        for (int j = 0; j < m_nDisplayY; j++) {
            m_nBackground[j][i] = E_BG_TILE::LAND;
        }
    }

    //�׵θ� �׸���
    //�簢�� ����
    for (int a = 0; a < m_nDisplayX; a++) {
        m_nBackground[0][a] = E_BG_TILE::WALL_HORIZONTAL;
        m_nBackground[1][a] = E_BG_TILE::WALL;
    }

    //�簢�� ������ ��
    for (int b = 0; b < m_nDisplayY; b++) {
        m_nBackground[b][m_nDisplayX - 1] = E_BG_TILE::WALL_VERTICAL;
        m_nBackground[b][m_nDisplayX - 2] = E_BG_TILE::WALL;
    }

    //�簢�� �Ʒ���
    for (int c = m_nDisplayX - 1; c >= 0; c--) {
        m_nBackground[m_nDisplayY - 1][c] = E_BG_TILE::WALL_HORIZONTAL;
        if (c < (m_nDisplayX - 1)) {
            m_nBackground[m_nDisplayY - 2][c] = E_BG_TILE::WALL;
        }
        
    }

    //�簢�� ���ʸ�
    for (int d = m_nDisplayY - 1; d >= 0; d--) {
        int n_wall = (d < 2) ? 1 : d - 1;
        m_nBackground[d][0] = E_BG_TILE::WALL_VERTICAL;
        m_nBackground[n_wall][1] = E_BG_TILE::WALL;
    }

    //�׵θ��� �����̵��� ����
    //���� ��
    m_nBackground[0][0] = E_BG_TILE::WALL_LEFT_TOP;
    //������ ��
    m_nBackground[0][m_nDisplayX - 1] = E_BG_TILE::WALL_RIGHT_TOP;
    //���� �Ʒ�
    m_nBackground[m_nDisplayY - 1][0] = E_BG_TILE::WALL_LEFT_BOTTOM;
    //������ �Ʒ�
    m_nBackground[m_nDisplayY - 1][m_nDisplayX - 1] = E_BG_TILE::WALL_RIGHT_BOTTOM;

	//ȭ�� ���� �޼��� ���� �׸���
	for (int e = 1; e < 149; e++) {
		m_nBackground[34][e] = E_BG_TILE::WALL;
		m_nBackground[35][e] = E_BG_TILE::WALL_HORIZONTAL;
	}

	int n_splitX = 115;
	for (int f = 0; f < 50; f++) {
		if (f < 35) {
			m_nBackground[f][n_splitX - 1] = E_BG_TILE::WALL;
		}
		m_nBackground[f][n_splitX] = E_BG_TILE::WALL_VERTICAL;
	}
	m_nBackground[0][n_splitX] = E_BG_TILE::WALL_TYPE_D;
	m_nBackground[49][n_splitX] = E_BG_TILE::WALL_TYPE_C;


    //��� ���
    for (int i = 0; i < m_nDisplayX; i++) {
        for (int j = 0; j < m_nDisplayY; j++) {
			PrintCtnt(i, j, m_nBackground[j][i]);
        }
    }

    //�÷��̾� ���� ���
    PrintPlayerInfo(m_player);
	//���� ����
	PlayGame();
}


void CSystem::PlayGame() {
    //�� ��ü ����
    Map map;
    int doPlayFlag = 1;
	//ȭ�鿡 ǥ���� ĳ���� ��ġ ���� 112, 32
    //300, 90
    //ȭ�� �� ĳ������ ��ġ
	m_player->SetPlayerPos(56, 16);

    COORD cdPlayerPos = m_player->GetPlayerPos();
    COORD cdPlayerNextPos;

    //�ʱ� �� ����
    map.SetMap(1);

    while (doPlayFlag) {
        unsigned long Timer = GetTickCount();

        cdPlayerPos = m_player->GetPlayerPos();
        if (GetTickCount() >= Timer + (1000 / m_nFrame)) {

            //�ʴ� �Ź� ĳ������ ��ġ�� �����;� ��
            int n_PlayerPosX = cdPlayerPos.X;
            int n_PlayerPosY = cdPlayerPos.Y;

			//����� �Է� Ű
			if (GetAsyncKeyState(VK_UP) & 0x8001) {
				n_PlayerPosY = (n_PlayerPosY <= 0) ? 0 : n_PlayerPosY - 1;
			}
			if (GetAsyncKeyState(VK_DOWN) & 0x8001) {
				n_PlayerPosY = (n_PlayerPosY >= (map.GetMapSizeY())) ? map.GetMapSizeY() : n_PlayerPosY + 1;
			}
			if (GetAsyncKeyState(VK_LEFT) & 0x8001) {
                n_PlayerPosX = (n_PlayerPosX <= 0) ? 0 : n_PlayerPosX - 1;
			}
			if (GetAsyncKeyState(VK_RIGHT) & 0x8001) {
                n_PlayerPosX = (n_PlayerPosX >= (map.GetMapSizeX())) ? map.GetMapSizeX() : n_PlayerPosX + 1;
            }
            
            //ĳ���Ͱ� �̵��� ��ŭ ���� �߰��Ͽ� �׸���
            m_player->SetPlayerPos(n_PlayerPosX, n_PlayerPosY);

            //ĳ���� ��ġ�� ��ǥ�� ���
            PrintCoord(m_player->GetPlayerPos());

            //map.InitMapData(m_player->GetPlayerPos(), );
        }
    }
}