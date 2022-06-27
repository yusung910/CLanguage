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

		PrintSelectedMenu(nMainMenu, true);


		if (GetAsyncKeyState(VK_RETURN)) {
			//플레이어가 엔터키를 눌렀을 경우
			switch (nMainMenu) {
			case E_MAIN_MENU::NEW_GAME:
				//새로운 게임 시작
				GameStart();
				break;
			case E_MAIN_MENU::CONTINUE_GAME:
				//저장된 게임을 불러온다.
				break;
			case E_MAIN_MENU::CREDIT:
				//제작자 내용을 출력
				break;
			}
		}
	}
};

void CSystem::GameStart() {
	//시스템 메세지 출력 화면을 초기화한다.
	ClearDisplay(E_DISPLAY::SYSTEM);
	//cout << "게임을 시작합니다, 잠시만 기다려주세요...";
}