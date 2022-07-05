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
    DOUBLE_ATTACK,
	P_BASIC_SKILL_CNT
};

class Player : public Creature {
public:
    //생성자
	Player();
    //소멸자
	~Player();

	//공격함수
	int Attack(int n_skill);
    //경험치 get, set
    void SetExp(int n);
    int GetExp();
    //소지금 get, set
    void SetGold(int n);
    int GetGold();
    //기본스텟 get,set
    void SetBasicStat(int* nList);
    int* GetBasicStat();
	//플레이어 이름 세팅
	void SetName(String s);
protected:

	//초기 소지 골드
	int n_mGold = 100;

	//경험치
	int n_mExp = 0;

	//크리쳐 객체에서 상속받은 기본 스탯
	int n_lPlayerBasicStat[E_CREATURE_BASIC_STAT::STAT_CNT];

	//플레이어의 추가 스탯
	int n_lPlayerStat[E_PLAYER_STAT::P_STAT_CNT];

	//플레이어의 기술 레벨 목록
	int n_lPlayerSkillList[E_PLAYER_BASIC_SKILL::P_BASIC_SKILL_CNT];

    //플레이어 추가 스탯 이름
    String m_lPlayerStatName[E_PLAYER_STAT::P_STAT_CNT];

    //플레이어 스킬 이름
    String m_lPlayerSkillName[E_PLAYER_BASIC_SKILL::P_BASIC_SKILL_CNT];

private:
};
#endif