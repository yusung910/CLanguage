#include "CSystem.h"

CSystem::CSystem() {
    //생성자
    //화면 크기 조절
    system("mode con: cols=80 lines=30");

    //화면의 기본 테두리를 그린다.
    PrintDisplayRound();
	//메인 메뉴 기능 실행
	SelectedMainMenu();
};

CSystem::~CSystem() {

}

void CSystem::SelectedMainMenu() {
	//플레이어의 메뉴 선택 여부 변수
	int doSelectedMenuFlag = 1;
	//선택한 메인 메뉴
	int nMainMenu = 1;
	//메인화면에 메뉴를 출력한다.
	PrintDisplayMenu();

	PrintSelectedMenu(nMainMenu, true);
	while (doSelectedMenuFlag) {
		//사용자 입력 키
		int inputKey = _getch();
		PrintSelectedMenu(nMainMenu, false);
		//사용자가 입력한 방향키에 따라 메뉴 선택을 움직인다.
		if (GetAsyncKeyState(VK_UP) & 0x0001) {
			nMainMenu = (nMainMenu > E_MAIN_MENU::NEW_GAME) ? nMainMenu -= 1 : E_MAIN_MENU::NEW_GAME;
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x0001) {
			nMainMenu = (nMainMenu < E_MAIN_MENU::CREDIT) ? nMainMenu += 1 : E_MAIN_MENU::CREDIT;
		}

		//메뉴 출력
		PrintSelectedMenu(nMainMenu, true);

		if (GetAsyncKeyState(VK_RETURN)) {
			//플레이어가 엔터키를 눌렀을 경우
			switch (nMainMenu) {

			case E_MAIN_MENU::NEW_GAME:
				//새로운 게임 시작을 위한 데이터 생성
                CreatePlayerData();
			case E_MAIN_MENU::CONTINUE_GAME:
				//저장된 게임을 불러온다.
				
				//게임 시작 전에 화면을 초기화한다.
				ClearDisplay(E_DISPLAY::GAME);
				ClearDisplay(E_DISPLAY::SYSTEM);

				//처음 마을 화면을 그린다
				PrintVillageBackground();
                //플레이어의 취
                o_player->SetPlayerPos({40, 18});
                //플레이를 시작한다
                PlayGame();


				break;
			case E_MAIN_MENU::CREDIT:
				//제작자 내용을 출력
				break;
			}
            doSelectedMenuFlag = 0;
		}
	}
};

void CSystem::CreatePlayerData() {
	//시스템 메세지 출력 화면을 초기화한다.
	ClearDisplay(E_DISPLAY::SYSTEM);
    //플레이어 객체 생성
    o_player = new CPlayer;
    //플레이어 캐릭터 명을 입력요청하기 위한 메세지 출력
    PrintCreatePlayerMsg();
    //임시로 캐릭터명을 저장할 배열을 생성
    char c_tmpCharName[200];
    scanf(" %s", c_tmpCharName);
    //캐릭터명이 저장된 CString 클래스 생성
    o_player->SetName(CString(c_tmpCharName));
    //시스템 메세지를 클리어한다.
    ClearDisplay(E_DISPLAY::SYSTEM);
}

void CSystem::LoadPlayerData() {

}

void CSystem::PlayGame() {

    int nMoveChar = 1;

    while (nMoveChar) {
        //플레이어의 위치
        COORD cdPlayerPos = o_player->GetPlayerPos();

        int n_playX = cdPlayerPos.X;
        int n_playY = cdPlayerPos.Y;

        //사용자 입력 키
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
    //이동하기 전 위치 값을 매개변수로 받아 지운다
    if (m_nLend[cdPrevPos.Y][cdPrevPos.X] != E_BACKGROUND::WALL) {
        SetPos(cdPrevPos);
        cout << "  ";
        SetPos(cdNextPos);
        cout << "■";
    }

}