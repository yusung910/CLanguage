#pragma once
#include "CDrawing.h"

class CDungeon : public CDrawing {
public:
	//������
	CDungeon();
	//�Ҹ���
	~CDungeon();
	void PrintDungeonMap();
protected:
	int m_nDungeonLvl;
private:
};