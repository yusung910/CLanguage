#ifndef __MONSTER_H_
#define __MONSTER_H_

//#include "CObject.h"
#include "CSkill.h"
enum E_MONSTER_TYPE {
    GOBLINE = 1,
    COBOLT,
    GREMLINE,
    ORC,
    TROLL,
    MONSTER_MAX,
};

class CMonster : public CSkill {

public:
    //생성자
    CMonster();
    //소멸자
	virtual ~CMonster();
    //몬스터의 경험치를 반환한다.
	int GetMonsterExp();
    //몬스터의 정보를 화면에 표현한다.
    void Display();
	//몬스터의 공격을 실행하고 데미지 값을 리턴받는다.
    int Attack();
	//몬스터가 가지고 있는 스킬목록을 호출한다
	void ShowSkillList();
	//몬스터명을 세팅
	void SetMonsterName();
    //몬스터명을 리턴
    char* GetMonsterName();
	//몬스터 정보를 세팅한다.
	void init();
    //이동 함수를 구현화
    void Move();
    //몬스터 체력을 리턴한다.
    int GetMonsterHP();
	//몬스터의 체력을 세팅한다
	void SetMonsterHP(int n);
    //몬스터의 공격력을 리턴한다.
    int GetMonsterAttack() { return m_nAttack; };
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