#pragma once

#ifndef _CREATURE_
#define _CREATURE_

#include "Creature.h"
enum E_PLAYER_STAT {
	MAX_HP = 0,
	MAX_MANA,
	STR,
	DEX,
	P_INT,
	LIFE,
	P_STAT_CNT
};

enum E_PLAYER_BASIC_SKILL {
	ESCAPE = 0,
	BASIC_ATTACK,
	BASH,
	P_BASIC_SKILL_CNT
};

class Player : public Creature {
public:

	Player();
	~Player();

	//공격함수
	int Attack(int n_skill);
	//플레이어 이름 세팅
	void SetName(String s);
protected:

	//초기 소지 골드
	int n_mGold = 100;

	//경험치
	int n_mExp = 0;

	//크리쳐 객체에서 상속받은 기본 스택
	int n_lPlayerBasicStat[E_CREATURE_BASIC_STAT::STAT_CNT];

	//플레이어의 추가 스탯
	int n_lPlayerStat[E_PLAYER_STAT::P_STAT_CNT];

	//플레이어의 기술 목록
	int n_lPlayerSkillList[E_PLAYER_BASIC_SKILL::P_BASIC_SKILL_CNT];

	//플레이어 추가 스탯 이름
	String m_lPlayerStatName[E_PLAYER_STAT::P_STAT_CNT];

	//플레이어 스킬 이름
	String m_lPlayerSkillName[E_PLAYER_BASIC_SKILL::P_BASIC_SKILL_CNT];

private:
};
#endif