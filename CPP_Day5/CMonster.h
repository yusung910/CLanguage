#ifndef __MONSTER_H_
#define __MONSTER_H_

#include "CCharacter.h"

class CMonster : CCharacter {

public:

	CMonster();
	virtual ~CMonster();
	int GetMonsterExp();

protected:

	void init();

private:

	int m_nMonsterExp;

};
#endif