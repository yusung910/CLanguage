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

	//전투 시작 전
	int BeginCombat(CPlayer* player, CMonster* monster);
	//전투 메뉴 선택
	void SelectCombatMenu();
    //스킬 선택
    void SelectPlayerSkill();
    
    //플레이어 객체
    CPlayer* o_player;
    //몬스터 객체
    CMonster* o_monster;
};