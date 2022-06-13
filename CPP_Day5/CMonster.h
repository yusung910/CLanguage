#ifndef __MONSTER_H_
#define __MONSTER_H_

#include "CObject.h"
enum E_MONSTER_TYPE {
    GOBLINE = 1,
    COBOLT,
    GREMLINE,
    ORC,
    TROLL,
    MONSTER_MAX,
};

class CMonster : public CObject {

public:
    //생성자
    CMonster();
    //소멸자
	virtual ~CMonster();
    //몬스터의 경험치를 반환한다.
	int GetMonsterExp();
    //몬스터의 정보를 화면에 표현한다.
    void Display();
    void Attack();
protected:

	void init();

private:
    //몬스터 경험치
	int m_nMonsterExp;
    //몬스터 체력
    int	m_nHP;
    //몬스터 마나
    int	m_nMana;
    //몬스터 레벨
    int	m_nLEVEL;
    //몬스터 공격력
    int m_nAttack;
    //몬스터 종류
    int m_nMobInfo;
};
#endif