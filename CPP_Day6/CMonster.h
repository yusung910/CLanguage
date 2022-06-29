#pragma once
#include "CUnit.h"
enum E_1_MONSTER {
    SLIME_1 = 0,
    GOBLIN_1,
    GIANT_RAT_1,
    MAX_CNT_1,
};

enum E_2_MONSTER {
    SLIME_2 = 0,
    GOBLIN_2,
    ARCHER_GOBLIN_2,
    LIZARD_2,
    MAX_CNT_2
};

enum E_3_MONSTER {
    GOBLIN_3 = 0,
    ARCHER_GOBLIN_3,
    LIZARD_3,
    SKELETON_3,
    MAX_CNT_3,
};

enum E_MONSTER_SKILL {
    BASIC_ATTACK = 0,
    SHOOT_ARROW,
    SKILL_CNT
};

class CMonster : public CUnit {
public:
    CMonster(int nDungeonLvl);
    ~CMonster();
    //���� ���� �ʱ�ȭ
    void init();
    //���� Ÿ���� �����Ѵ�
    void SetMonsterType();
    //���� ������ ������ �Ǵ� ���� ����
    int nDungeonLvl;
    //���� Ÿ��
    int nMonsterType;
};
