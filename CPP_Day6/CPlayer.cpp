#include "CPlayer.h"

//������
CPlayer::CPlayer() {
    //�÷��̾��� ������ 5�� �ʱ�ȭ �Ѵ�.
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

    //�÷��̾��� �⺻ ������ �����Ѵ�.
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

    //�÷��̾��� ��� ����� ����
    m_nSkillList = new int[E_PLAYER_SKILL::PLAYER_SKILL_CNT];

    //�÷��̾ ���� �ִ� ��� ����� -1�� �ʱ�ȭ�Ѵ�. 
    for (int i = 0; i < E_PLAYER_SKILL::PLAYER_SKILL_CNT; i++) {
        m_nSkillList[i] = -1;
    }

    m_nSkillList[0] = E_PLAYER_SKILL::ESCAPE;
    m_nSkillList[1] = E_PLAYER_SKILL::BASIC_ATTACK;
}

//�Ҹ���
CPlayer::~CPlayer() {
}

void CPlayer::SetPlayerPos(COORD pos) {
    cdPosPlayer = pos;
}

void CPlayer::SetPlayerPos(int x, int y) {
    COORD tmp = { x, y };
    cdPosPlayer = tmp;
}
//�÷��̾� ��ġ ���� �����´�.
COORD CPlayer::GetPlayerPos() {
    return cdPosPlayer;
}

int* CPlayer::GetPlayerStat() {
    return m_nStat;
}

CString* CPlayer::GetPlayerSkillNameList() {
    return sSkillNameList;
}

int CPlayer::GetDamage(int m_UseSkill) {
    int n_RetDamage = m_nStat[E_UNIT_INFO::E_DAMAGE];

    if (m_UseSkill == E_PLAYER_SKILL::BASIC_ATTACK) {
        n_RetDamage += 1;
    }
    else if (m_UseSkill == E_PLAYER_SKILL::BASH) {
        n_RetDamage += 10;

    }
    else if (m_UseSkill == E_PLAYER_SKILL::DOUBLE_ATTACK) {
        n_RetDamage += 15;
    }
    
    return n_RetDamage;
}