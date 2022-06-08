#ifndef __UNIT_H__
#define __UNIT_H__

class CUnit
{
public:
	CUnit();
	~CUnit();

	void Move(int x = 10, int y = 10);
    void Attack();
	
    void Display();
    int GetUnitCnt();

	int m_nDamage;
	int m_aPos[2];
	static int m_nNum;

    int m_UnitType;

    enum _E_UNIT_TYPE{
        PILOT = 1,
        SCORE_OBJCT,
        MONSTER_S_RARE,
        MONSTER_S,
        MONSTER_M,
        MONSTER_L,
        MONSTER_B,
    };
};

#endif