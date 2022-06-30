#include "CCombat.h"
//생성자
CCombat::CCombat() {

}

//소멸자
CCombat::~CCombat() {
}

int CCombat::BeginCombat(CPlayer* player, CMonster* monster) {

	//플레이어 정보
	int* aPlayerInfo = player->GetUnitInfo();
	//플레이어 스탯
	int* aPlayerStat = player->GetPlayerStat();
	//몬스터 정보
	int* aMonsterInfo = monster->GetUnitInfo();
	//플레이어 정보 위치
	int n_PlayerInfoX = 15;
	int n_PlayerInfoY = 3;
	//몬스터 정보 x 위치
	int n_MonsterInfoX = 45;
	int n_MonsterInfoY = 3;

	ClearDisplay(E_DISPLAY::GAME);
	//라인을 다시 그린다.
	PrintDisplayRound();

	//게임 플레이 화면에 플레이어 정보를 출력
	SetPos(n_PlayerInfoX, n_PlayerInfoY);
	cout << "[플레이어 정보]";

	SetPos(n_PlayerInfoX, (n_PlayerInfoY + 1));
	cout << "레벨 : ";
	cout << aPlayerInfo[E_UNIT_INFO::E_LVL];

	SetPos(n_PlayerInfoX, (n_PlayerInfoY + 2));
	cout << "체력 : ";
	cout << aPlayerInfo[E_UNIT_INFO::E_HP];

	SetPos(n_PlayerInfoX, (n_PlayerInfoY + 3));
	cout << "마나 : ";
	cout << aPlayerInfo[E_UNIT_INFO::E_MANA];

	SetPos(n_PlayerInfoX, (n_PlayerInfoY + 4));
	cout << "공격력 : ";
	cout << aPlayerInfo[E_UNIT_INFO::E_DAMAGE];

	//몬스터 정보 출력
	SetPos(n_MonsterInfoX, (n_MonsterInfoY));
	cout << "[몬스터 정보]";

	SetPos(n_MonsterInfoX, (n_MonsterInfoY + 1));
	cout << "이름 : ";
	monster->GetName().Display();

	SetPos(n_MonsterInfoX, (n_MonsterInfoY + 2));
	cout << "레벨 : ";
	cout << aMonsterInfo[E_UNIT_INFO::E_LVL];

	SetPos(n_MonsterInfoX, (n_MonsterInfoY + 3));
	cout << "체력 : ";
	cout << aMonsterInfo[E_UNIT_INFO::E_HP];

	SetPos(n_MonsterInfoX, (n_MonsterInfoY + 4));
	cout << "마나 : ";
	cout << aMonsterInfo[E_UNIT_INFO::E_MANA];

	SetPos(n_MonsterInfoX, (n_MonsterInfoY + 5));
	cout << "공격력 : ";
	cout << aMonsterInfo[E_UNIT_INFO::E_DAMAGE];

	//플레이어가 선택할 수 있는 기능을 실행한다.
	SelectCombatMenu();
	return 1;
}

void CCombat::SelectCombatMenu() {

	//시스템 메세지 영역 초기화
	ClearDisplay(E_DISPLAY::SYSTEM);

	SetPos(10, 22);
	cout << "전투 발생!, 전투를 진행하시겠습니까?";
	SetPos(10, 24);
	cout << "→ 싸운다.";
	SetPos(12, 25);
	cout << " 도망친다.";

	//전투메뉴 선택여부
	int n_DoFightSelect = 1;
	//전투메뉴 정보
	int n_SelectFightMenu = E_BATTLE_MENU::BEGIN;
	while (n_DoFightSelect) {

		int n_input = _getch();
		
		//사용자가 입력한 방향키에 따라 메뉴 선택을 움직인다.
		if (GetAsyncKeyState(VK_UP) & 0x0001) {
			n_SelectFightMenu = (n_SelectFightMenu > E_BATTLE_MENU::BEGIN) ? n_SelectFightMenu -= 1 : E_BATTLE_MENU::BEGIN;
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x0001) {
			n_SelectFightMenu = (n_SelectFightMenu < E_BATTLE_MENU::RUN) ? n_SelectFightMenu += 1 : E_BATTLE_MENU::RUN;
		}

		switch (n_SelectFightMenu) {
		case E_BATTLE_MENU::BEGIN:
			SetPos(10, 25);
			cout << "  ";
			SetPos(10, 24);
			cout << "→";
			break;
		case E_BATTLE_MENU::RUN:
			SetPos(10, 24);
			cout << "  ";
			SetPos(10, 25);
			cout << "→";
			break;
		}

		//메뉴 선택 후 엔터키 누를 경우
		if (GetAsyncKeyState(VK_RETURN)) {
			if (n_SelectFightMenu == E_BATTLE_MENU::BEGIN) {

			}
			else if (n_SelectFightMenu == E_BATTLE_MENU::RUN) {
				n_DoFightSelect = 0;
			}
		}
	}
}