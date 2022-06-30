#include "CPlayer.h"

//생성자
CPlayer::CPlayer() {
    //플레이어의 스텟을 5로 초기화 한다.
    for (int i = 0; i < E_PLAYER_STAT::E_STAT_CNT; i++) {
		switch (i) {

		case E_PLAYER_STAT::E_GOLD:
		case E_PLAYER_STAT::E_EXP:
			m_nStat[i] = 0;
			break;
		default:
			m_nStat[i] = 5;
			break;
		}
    }

    //플레이어의 기본 정보를 세팅한다.
    for (int j = 0; j < E_UNIT_INFO::E_INFO_CNT; j++) {
        int n = 0;
        switch (j) {
		case E_UNIT_INFO::E_LVL:
			n = 1;
			break;
        case E_UNIT_INFO::E_HP:
        case E_UNIT_INFO::E_MAX_HP:
            n = 100;
            break;
        case E_UNIT_INFO::E_MANA:
        case E_UNIT_INFO::E_MAX_MANA:
            n = 50;
            break;
        case E_UNIT_INFO::E_DAMAGE:
            n = 5;
            break;

        }
        m_nUnitInfo[j] = n;
    }

    //플레이어의 기술 목록을 세팅
    m_nSkillList = new int[E_PLAYER_SKILL::PLAYER_SKILL_CNT];
    memset(m_nSkillList, NULL, E_PLAYER_SKILL::PLAYER_SKILL_CNT);
    m_nSkillList[0] = E_PLAYER_SKILL::ESCAPE;
    m_nSkillList[1] = E_PLAYER_SKILL::BASIC_ATTACK;
}

//소멸자
CPlayer::~CPlayer() {
}

void CPlayer::SetPlayerPos(COORD pos) {
    cdPosPlayer = pos;
}

void CPlayer::SetPlayerPos(int x, int y) {
    COORD tmp = { x, y };
    cdPosPlayer = tmp;
}
//플레이어 위치 값을 가져온다.
COORD CPlayer::GetPlayerPos() {
    return cdPosPlayer;
}

int* CPlayer::GetPlayerStat() {
    return m_nStat;
}