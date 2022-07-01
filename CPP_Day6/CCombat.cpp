#include "CCombat.h"
//생성자
CCombat::CCombat() {

}

//소멸자
CCombat::~CCombat() {
}

void CCombat::initCombat(CPlayer* player, CMonster* monster) {
    //플레이어 객체를 저장
    o_player = player;
    //몬스터 객체를 저장
    o_monster = monster;
}

void CCombat::PrintCombatInfo() {
	//플레이어 정보
	unsigned int* aPlayerInfo = o_player->GetUnitInfo();
	//플레이어 스탯
	int* aPlayerStat = o_player->GetPlayerStat();
	//몬스터 정보
	unsigned int* aMonsterInfo = o_monster->GetUnitInfo();
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
	o_monster->GetName().Display();

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
}

int CCombat::StartCombat() {

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
		if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
			if (n_SelectFightMenu == E_BATTLE_MENU::BEGIN) {
                ClearDisplay(E_DISPLAY::SYSTEM);
                n_DoFightSelect = 0;
                SelectPlayerSkill();
			}
			else if (n_SelectFightMenu == E_BATTLE_MENU::RUN) {
				n_DoFightSelect = 0;
			}
		}
	}

	return 1;
}

void CCombat::SelectPlayerSkill() {
    //스킬 선택 진행 while 플래그
    int doPlayerSkillFlag = 1;
    //플레이어 스킬
    int nPlayerSkill = E_PLAYER_SKILL::ESCAPE;
    //플레이어의 마지막 스킬
    int nEndPlayerSkill;
    //플레이어가 소유하고 있는 기술 목록
    int* n_UserSkillList = o_player->GetUnitSkillList();
    //플레이어 스킬명이 저장 되어있는 변수
    CString* s_UserSkillNmList = o_player->GetPlayerSkillNameList();

    SetPos(10, 22);
    cout << "[스킬목록]";
    //플레이어의 사용 가능한 기술 목록을 출력한다.
    for (int i = 0; i < E_PLAYER_SKILL::PLAYER_SKILL_CNT; i++) {
        if (n_UserSkillList[i] > -1) {

            if (i == 0) {
                SetPos(10, (23 + i));
                cout << "→";
            }

            SetPos(12, (23 + i));
            s_UserSkillNmList[i].Display();


            //플레이어가 갖고 있는 마지막 스킬넘버를 저장한다.
            nEndPlayerSkill = i;
        }
    }
    
    while (doPlayerSkillFlag) {

        int nInput = _getch();

        //사용자가 입력한 방향키에 따라 스킬 선택 메뉴를 움직인다.
        if (GetAsyncKeyState(VK_UP) & 0x0001) {
            nPlayerSkill = (nPlayerSkill > E_PLAYER_SKILL::ESCAPE) ? nPlayerSkill -= 1 : E_PLAYER_SKILL::ESCAPE;
        }

        if (GetAsyncKeyState(VK_DOWN) & 0x0001) {
            nPlayerSkill = (nPlayerSkill < nEndPlayerSkill) ? nPlayerSkill += 1 : nEndPlayerSkill;
        }

        //플레이어가 선택한 스킬에 화살표를 표시한다.
        for (int a = 0; a < E_PLAYER_SKILL::PLAYER_SKILL_CNT; a++) {
            SetPos(10, (23 + a));
            cout << "  ";
            if (n_UserSkillList[a] > -1 && n_UserSkillList[a] == nPlayerSkill) {
                SetPos(10, (23 + a));
                cout << "→";
            }
        }

        if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
            if (nPlayerSkill == E_PLAYER_SKILL::ESCAPE) {
                doPlayerSkillFlag = 0;
            }
            else {
				//플레이어의 공격력
				int n_playerDmg = o_player->GetDamage(doPlayerSkillFlag);
				//몬스터의 데미지
				int n_monsterDmg = o_monster->GetDamage(doPlayerSkillFlag);
				//플레이어의 체력
				unsigned int n_playerHp = (o_player->GetUnitHp() - n_monsterDmg) < 0 ? 0 : o_player->GetUnitHp() - n_monsterDmg;
				//몬스터의 체력
				unsigned int n_monsterHp = (o_monster->GetUnitHp() - n_playerDmg) < 0 ? 0 : o_monster->GetUnitHp() - n_playerDmg;

				int n_logStartX = 10;
				int n_logStartY = 13;

				//몬스터의 체력에 플레이어 데미지를 빼고 저장
				o_monster->SetUnitHp(n_monsterHp);
				//플레이어의 체력에 몬스터 데미지를 빼고 저장
				o_player->SetUnitHp(n_playerHp);

				//전투 정보를 출력
				PrintCombatInfo();

				//전투로그 출력
				SetPos(n_logStartX, n_logStartY);
				cout << "[전투 기록]";

				n_logStartY++;
				SetPos(n_logStartX, n_logStartY);
				cout << "\'";
				o_player->GetName().Display();
				cout << "\'의 [";
				s_UserSkillNmList[nPlayerSkill].Display();
				cout << "]";

				n_logStartY++;
				SetPos(n_logStartX, n_logStartY);
				cout << n_playerDmg << " 데미지 를 [";
				o_monster->GetName().Display();
				cout << "]에게 입혔습니다.";

				n_logStartY++;
				SetPos(n_logStartX, n_logStartY);
				cout << "\'";
				o_monster->GetName().Display();
				cout << "\' 공격!";

				n_logStartY++;
				SetPos(n_logStartX, n_logStartY);
				cout << "\'";
				o_player->GetName().Display();
				cout << "\'에게 "<< n_monsterDmg << " 데미지를 입혔습니다.";
            }
        }
    }
}