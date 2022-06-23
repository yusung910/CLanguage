#ifndef __BATTLE_H_
#define __BATTLE_H_

#include <iostream>
#include <windows.h>
#include <conio.h>
#include "CObject.h"
#include "CMonster.h"
#include "CUser.h"
#include "CBattle.h"
#include "CDrawing.h"

class CBattle {
public:
	CBattle();
	~CBattle();

	void DoBattle(CDrawing* drawingObj, CUser* user, CMonster* monster);
private:
	
};

#endif