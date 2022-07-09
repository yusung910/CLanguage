#include "CSystem.h"    

CSystem::CSystem() {
    //시스템 생성자
    system("mode con: cols=151 lines=50");

    //메인 메뉴 
    ShowMainMenu();
}

CSystem::~CSystem() {
    //시스템 소멸자
}

void CSystem::ShowMainMenu() {
    //커서 숨기기
    HideConsoleCursor();
    //반복문 플래그
    int doSelectMainMenu = 1;
    //메인 선택메뉴
    int selectedMainMenu = 0;

    while (doSelectMainMenu) {
        unsigned long Timer = GetTickCount();

        if (GetTickCount() >= Timer + (1000 / m_nFrame)) {

            PrintCtntCenter(12, String("Game Title!!"));
            PrintCtntCenter(38, String("새로시작"));
            PrintCtntCenter(39, String("계속하기"));
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
                PrintCtnt(68, 38, "■");
                break;
            case E_MAIN_MENU::E_CONTINUE:
                PrintCtnt(68, 39, "■");
                break;
            case E_MAIN_MENU::E_CREDIT:
                PrintCtnt(69, 40, "■");
                break;
            }

            if (GetAsyncKeyState(VK_RETURN)) {
                //반복문 중단
                doSelectMainMenu = 0;
                switch (selectedMainMenu) {
                case E_MAIN_MENU::E_NEW_START:
                    //플레이어 생성
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

    //화면 클리어
    DisplayClear();
    //메뉴선택화면에서 입력된 enter값 때문에 입력 버퍼 클리어
    getchar();

    PrintCtntCenter(24, "플레이어 이름을 입력하여 주세요: ");
    scanf(" %s", &chr);

    //플레이어 객체 생성
    m_player->SetName(chr);

    //커서 숨기기
    HideConsoleCursor();

    //플레이어 생성 후 클리어
    DisplayClear();

    //게임 플레이 영역을 그린다.
    InitBasicDisplayArea();
}

void CSystem::InitBasicDisplayArea() {
    //배경 영역을 land로 기본 초기화
    for (int i = 0; i < m_nDisplayX; i++) {
        for (int j = 0; j < m_nDisplayY; j++) {
            m_nBackground[j][i] = E_BG_TILE::LAND;
        }
    }

    //테두리 그리기
    //사각형 윗면
    for (int a = 0; a < m_nDisplayX; a++) {
        m_nBackground[0][a] = E_BG_TILE::WALL_HORIZONTAL;
        m_nBackground[1][a] = E_BG_TILE::WALL;
    }

    //사각형 오른쪽 면
    for (int b = 0; b < m_nDisplayY; b++) {
        m_nBackground[b][m_nDisplayX - 1] = E_BG_TILE::WALL_VERTICAL;
        m_nBackground[b][m_nDisplayX - 2] = E_BG_TILE::WALL;
    }

    //사각형 아랫면
    for (int c = m_nDisplayX - 1; c >= 0; c--) {
        m_nBackground[m_nDisplayY - 1][c] = E_BG_TILE::WALL_HORIZONTAL;
        if (c < (m_nDisplayX - 1)) {
            m_nBackground[m_nDisplayY - 2][c] = E_BG_TILE::WALL;
        }
        
    }

    //사각형 왼쪽면
    for (int d = m_nDisplayY - 1; d >= 0; d--) {
        int n_wall = (d < 2) ? 1 : d - 1;
        m_nBackground[d][0] = E_BG_TILE::WALL_VERTICAL;
        m_nBackground[n_wall][1] = E_BG_TILE::WALL;
    }

    //테두리의 귀퉁이들을 설정
    //왼쪽 위
    m_nBackground[0][0] = E_BG_TILE::WALL_LEFT_TOP;
    //오른쪽 위
    m_nBackground[0][m_nDisplayX - 1] = E_BG_TILE::WALL_RIGHT_TOP;
    //왼쪽 아래
    m_nBackground[m_nDisplayY - 1][0] = E_BG_TILE::WALL_LEFT_BOTTOM;
    //오른쪽 아래
    m_nBackground[m_nDisplayY - 1][m_nDisplayX - 1] = E_BG_TILE::WALL_RIGHT_BOTTOM;

	//화면 분할 메세지 영역 그리기
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


    //배경 출력
    for (int i = 0; i < m_nDisplayX; i++) {
        for (int j = 0; j < m_nDisplayY; j++) {
			PrintCtnt(i, j, m_nBackground[j][i]);
        }
    }

    //플레이어 정보 출력
    PrintPlayerInfo(m_player);
	//게임 시작
	PlayGame();
}


void CSystem::PlayGame() {
    //맵 객체 생성
    Map map;
    int doPlayFlag = 1;
	//화면에 표시할 캐릭터 위치 세팅 112, 32
    //300, 90
    //화면 상 캐릭터의 위치
	m_player->SetPlayerPos(56, 16);

    COORD cdPlayerPos = m_player->GetPlayerPos();
    COORD cdPlayerNextPos;

    //초기 맵 세팅
    map.SetMap(1);

    while (doPlayFlag) {
        unsigned long Timer = GetTickCount();

        cdPlayerPos = m_player->GetPlayerPos();
        if (GetTickCount() >= Timer + (1000 / m_nFrame)) {

            //초당 매번 캐릭터의 위치를 가져와야 함
            int n_PlayerPosX = cdPlayerPos.X;
            int n_PlayerPosY = cdPlayerPos.Y;

			//사용자 입력 키
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
            
            //캐릭터가 이동한 만큼 맵을 추가하여 그린다
            m_player->SetPlayerPos(n_PlayerPosX, n_PlayerPosY);

            //캐릭터 위치의 좌표를 출력
            PrintCoord(m_player->GetPlayerPos());

            //map.InitMapData(m_player->GetPlayerPos(), );
        }
    }
}