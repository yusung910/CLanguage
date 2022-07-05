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
    //������
	Player();
    //�Ҹ���
	~Player();

	//�����Լ�
	int Attack(int n_skill);
    //����ġ get, set
    void SetExp(int n);
    int GetExp();
    //������ get, set
    void SetGold(int n);
    int GetGold();
    //�⺻���� get,set
    void SetBasicStat(int* nList);
    int* GetBasicStat();
	//�÷��̾� �̸� ����
	void SetName(String s);
protected:

	//�ʱ� ���� ���
	int n_mGold = 100;

	//����ġ
	int n_mExp = 0;

	//ũ���� ��ü���� ��ӹ��� �⺻ ����
	int n_lPlayerBasicStat[E_CREATURE_BASIC_STAT::STAT_CNT];

	//�÷��̾��� �߰� ����
	int n_lPlayerStat[E_PLAYER_STAT::P_STAT_CNT];

	//�÷��̾��� ��� ���� ���
	int n_lPlayerSkillList[E_PLAYER_BASIC_SKILL::P_BASIC_SKILL_CNT];

    //�÷��̾� �߰� ���� �̸�
    String m_lPlayerStatName[E_PLAYER_STAT::P_STAT_CNT];

    //�÷��̾� ��ų �̸�
    String m_lPlayerSkillName[E_PLAYER_BASIC_SKILL::P_BASIC_SKILL_CNT];

private:
};
#endif