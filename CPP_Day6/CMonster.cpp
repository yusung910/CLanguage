#include "CMonster.h"

//몬스터 생성자
//현재 던전 레벨에 따라 몬스터를 다르게 초기화 한다.
CMonster::CMonster(int n) {
    nDungeonLvl = n;
    init();
}

CMonster::~CMonster() {

}

void CMonster::init() {
    //몬스터 타입을 던전 층수에 따라 임의로 지정한다
    for (int j = 0; j < E_UNIT_INFO::E_INFO_CNT; j++) {
        int n = 0;
        switch (j) {
		case E_UNIT_INFO::E_LVL:
			n = 1;
			break;
        case E_UNIT_INFO::E_HP:
            n = 30;
            break;
        case E_UNIT_INFO::E_MANA:
            n = 0;
            break;
        case E_UNIT_INFO::E_DAMAGE:
            n = 2;
            break;

        }
        m_nUnitInfo[j] = n;
    }

    //몬스터의 기술을 초기화한다.
    m_nSkillList = new int[E_MONSTER_SKILL::SKILL_CNT];
    memset(m_nSkillList, NULL, E_MONSTER_SKILL::SKILL_CNT);
    m_nSkillList[0] = E_MONSTER_SKILL::M_BASIC_ATTACK;

    SetMonsterType();
}

void CMonster::SetMonsterType() {
    int n_maxNum;
    CString monsterNm;
    if (nDungeonLvl == 1) {
        n_maxNum = E_1_MONSTER::MAX_CNT_1;
        nMonsterType = rand() % n_maxNum;
        switch (nMonsterType) {
        case E_1_MONSTER::SLIME_1:
            monsterNm = CString("슬라임");
            break;
        case E_1_MONSTER::GOBLIN_1:
            monsterNm = CString("고블린");
            break;
        case E_1_MONSTER::GIANT_RAT_1:
            monsterNm = CString("거대 쥐");
            break;
        }
    }
    else if (nDungeonLvl == 2) {
        n_maxNum = E_2_MONSTER::MAX_CNT_2;
        nMonsterType = rand() % n_maxNum;
        switch (nMonsterType) {
        case E_2_MONSTER::SLIME_2:
            monsterNm = CString("슬라임");
            break;
        case E_2_MONSTER::GOBLIN_2:
            monsterNm = CString("고블린");
            break;
        case E_2_MONSTER::ARCHER_GOBLIN_2:
            monsterNm = CString("고블린궁수");
            break;
        case E_2_MONSTER::LIZARD_2:
            monsterNm = CString("리자드맨");
            break;
        }
    }
    else if (nDungeonLvl == 3) {
        n_maxNum = E_3_MONSTER::MAX_CNT_3;
        nMonsterType = rand() % n_maxNum;
        switch (nMonsterType) {
        case E_3_MONSTER::GOBLIN_3:
            monsterNm = CString("고블린");
            break;
        case E_3_MONSTER::ARCHER_GOBLIN_3:
            monsterNm = CString("고블린궁수");
            break;
        case E_3_MONSTER::LIZARD_3:
            monsterNm = CString("리자드맨");
            break;
        case E_3_MONSTER::SKELETON_3:
            monsterNm = CString("스켈레톤");
            break;
        }
    }

    SetName(monsterNm);
}

int CMonster::GetDamage(int m_UseSkill) {
    return m_nUnitInfo[E_UNIT_INFO::E_DAMAGE];
}