#include "Player.h"

//������
Player::Player() {
	//�÷��̾� ��ü�� �⺻ ������ �Ҵ��Ѵ�.
	n_lPlayerBasicStat[E_CREATURE_BASIC_STAT::HP] = 100;
	n_lPlayerBasicStat[E_CREATURE_BASIC_STAT::MANA] = 50;
	n_lPlayerBasicStat[E_CREATURE_BASIC_STAT::ATTACK] = 3;
	n_lPlayerBasicStat[E_CREATURE_BASIC_STAT::LEVEL] = 1;

	//�÷��̾��� �߰� ����
	n_lPlayerStat[E_PLAYER_STAT::MAX_HP] = 100;
	n_lPlayerStat[E_PLAYER_STAT::MAX_MANA] = 50;
	n_lPlayerStat[E_PLAYER_STAT::STR] = 5;
	n_lPlayerStat[E_PLAYER_STAT::DEX] = 5;
	n_lPlayerStat[E_PLAYER_STAT::P_INT] = 5;
	n_lPlayerStat[E_PLAYER_STAT::LIFE] = 5;

	//�÷��̾� �߰� ���� �̸�
	m_lPlayerStatName[E_PLAYER_STAT::MAX_HP] = String("�ִ� ü��");
	m_lPlayerStatName[E_PLAYER_STAT::MAX_MANA] = String("�ִ� ����");
	m_lPlayerStatName[E_PLAYER_STAT::STR] = String("��");
	m_lPlayerStatName[E_PLAYER_STAT::DEX] = String("��ø");
	m_lPlayerStatName[E_PLAYER_STAT::P_INT] = String("����");
	m_lPlayerStatName[E_PLAYER_STAT::LIFE] = String("�����");

	//�÷��̾� ��� �̸�
	m_lPlayerSkillName[E_PLAYER_BASIC_SKILL::ESCAPE] = String("����ġ��");
	m_lPlayerSkillName[E_PLAYER_BASIC_SKILL::BASIC_ATTACK] = String("�⺻����");
	m_lPlayerSkillName[E_PLAYER_BASIC_SKILL::BASH] = String("�转");
	//�⺻ ��� ����� 1�� �ʱ�ȭ�Ѵ�.
	memset(n_lPlayerSkillList, 1, sizeof(n_lPlayerSkillList));
	cout << n_lPlayerSkillList[0];
}

//�Ҹ���
Player::~Player() {

}

void Player::SetName(String s) {
	n_sName = s;
}
int Player::Attack(int n_skill) {
	return n_lPlayerBasicStat[E_CREATURE_BASIC_STAT::ATTACK];
}