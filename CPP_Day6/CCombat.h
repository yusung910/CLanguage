#pragma once
#include "CMessage.h"
#include "CMonster.h"
enum E_BATTLE_MENU {
	BEGIN = 1,
	RUN
};
class CCombat : public CMessage{
public:
	//생성자
	CCombat();

	//소멸자
	~CCombat();

	//전투 시작 초기화
	void initCombat(CPlayer* player, CMonster* monster);
	//전투에 필요한 정보를 출력한다.
	void PrintCombatInfo();
	//전투 메뉴 선택
	int StartCombat();
    //스킬 선택
    void SelectPlayerSkill();
    
    //플레이어 객체
    CPlayer* o_player;
    //몬스터 객체
    CMonster* o_monster;
};