#ifndef __BATTLE_H_
#define __BATTLE_H_

#include "CObject.h"
#include "CMonster.h"
#include "CUser.h"

class CBattle {
public:
	CBattle();
	~CBattle();
	void DoBattle(CUser* user, CMonster* monster, COORD pos);
private:
	
};

#endif __BATTLE_H_