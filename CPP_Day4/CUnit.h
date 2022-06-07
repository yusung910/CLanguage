#pragma once
int CUnit::m_nNum = 0;
class CUnit
{
public:
	CUnit(const char* s);
	~CUnit();

	void Move(int x, int y);
	char* GetName();
protected:
	char* m_cName;
	int m_nHp;
	int m_nMana;
	int m_nDamage;
	int m_aPos[2];
	static int m_nNum;
};