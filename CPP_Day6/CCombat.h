#pragma once
#include "CMessage.h"
#include "CMonster.h"
enum E_BATTLE_MENU {
	BEGIN = 1,
	RUN
};
class CCombat : public CMessage{
public:
	//������
	CCombat();

	//�Ҹ���
	~CCombat();

	//���� ���� ��
	int BeginCombat(CPlayer* player, CMonster* monster);
	//���� �޴� ����
	void SelectCombatMenu();
    //��ų ����
    void SelectPlayerSkill();
    
    //�÷��̾� ��ü
    CPlayer* o_player;
    //���� ��ü
    CMonster* o_monster;
};