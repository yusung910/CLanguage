#include "Player.h"

//������
Player::Player() {
	//�÷��̾� ��ü�� �⺻ ������ �Ҵ��Ѵ�.
	//n_PlayerBStat
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
    m_lPlayerSkillName[E_PLAYER_BASIC_SKILL::DOUBLE_ATTACK] = String("�������");

	//�⺻ ��� ���� ����� 0���� �ʱ�ȭ�Ѵ�.
	memset(n_lPlayerSkillList, 0, sizeof(n_lPlayerSkillList));

    n_lPlayerSkillList[E_PLAYER_BASIC_SKILL::ESCAPE] = 1;
    n_lPlayerSkillList[E_PLAYER_BASIC_SKILL::BASIC_ATTACK] = 1;
}

//�Ҹ���
Player::~Player() {
}

void Player::SetName(String s) {
    n_sName = s;
}
int Player::Attack(int n_skill) {
	return 0;
}

void Player::SetExp(int n) {
    n_mExp = n;
};
int Player::GetExp() {
    return n_mExp;
};

void Player::SetGold(int n) {
    n_mGold = n;
};
int Player::GetGold() {
    return n_mGold;
};

void Player::SetPlayerPos(COORD pos) {
	m_PlayerPos = pos;
}

void Player::SetPlayerPos(int x, int y) {
	COORD tmpPos = { x, y };
	m_PlayerPos = tmpPos;
}

COORD Player::GetPlayerPos() {
	return m_PlayerPos;
}

void Player::SetPlayerPosPrev(COORD pos){
	m_PlayerPrevPos = pos;
}

void Player::SetPlayerPosPrev(int x, int y) {
	COORD tmpPos = { x, y };
	m_PlayerPrevPos = tmpPos;
}

COORD Player::GetPlayerPosPrev() {
	return m_PlayerPrevPos;
}