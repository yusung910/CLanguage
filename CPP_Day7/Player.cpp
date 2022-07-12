#include "Player.h"

//생성자
Player::Player() {
	//플레이어 객체에 기본 스탯을 할당한다.
	//n_PlayerBStat
	//플레이어의 추가 스텟
	n_lPlayerStat[E_PLAYER_STAT::MAX_HP] = 100;
	n_lPlayerStat[E_PLAYER_STAT::MAX_MANA] = 50;
	n_lPlayerStat[E_PLAYER_STAT::STR] = 5;
	n_lPlayerStat[E_PLAYER_STAT::DEX] = 5;
	n_lPlayerStat[E_PLAYER_STAT::P_INT] = 5;
	n_lPlayerStat[E_PLAYER_STAT::LIFE] = 5;

    //플레이어 추가 스탯 이름
    m_lPlayerStatName[E_PLAYER_STAT::MAX_HP] = String("최대 체력");
    m_lPlayerStatName[E_PLAYER_STAT::MAX_MANA] = String("최대 마나");
    m_lPlayerStatName[E_PLAYER_STAT::STR] = String("힘");
    m_lPlayerStatName[E_PLAYER_STAT::DEX] = String("민첩");
    m_lPlayerStatName[E_PLAYER_STAT::P_INT] = String("지식");
    m_lPlayerStatName[E_PLAYER_STAT::LIFE] = String("생명력");

    //플레이어 기술 이름
    m_lPlayerSkillName[E_PLAYER_BASIC_SKILL::ESCAPE] = String("도망치기");
    m_lPlayerSkillName[E_PLAYER_BASIC_SKILL::BASIC_ATTACK] = String("기본공격");
    m_lPlayerSkillName[E_PLAYER_BASIC_SKILL::BASH] = String("배쉬");
    m_lPlayerSkillName[E_PLAYER_BASIC_SKILL::DOUBLE_ATTACK] = String("더블어택");

	//기본 기술 레벨 목록을 0으로 초기화한다.
	memset(n_lPlayerSkillList, 0, sizeof(n_lPlayerSkillList));

    n_lPlayerSkillList[E_PLAYER_BASIC_SKILL::ESCAPE] = 1;
    n_lPlayerSkillList[E_PLAYER_BASIC_SKILL::BASIC_ATTACK] = 1;
}

//소멸자
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