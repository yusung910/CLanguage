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

	//���� ���� �ʱ�ȭ
	void initCombat(CPlayer* player, CMonster* monster);
	//������ �ʿ��� ������ ����Ѵ�.
	void PrintCombatInfo();
	//���� �޴� ����
	int StartCombat();
    //��ų ����
    void SelectPlayerSkill();
    
    //�÷��̾� ��ü
    CPlayer* o_player;
    //���� ��ü
    CMonster* o_monster;
};