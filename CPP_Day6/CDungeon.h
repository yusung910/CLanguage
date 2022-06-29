#pragma once
#include "CDrawing.h"

class CDungeon : public CDrawing {
public:
	//持失切
	CDungeon();
	//社瑚切
	~CDungeon();
	void PrintDungeonMap();
protected:
	int m_nDungeonLvl;
private:
};