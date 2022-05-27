#pragma once
class CPlayer
{
public:
	//생성자
	CPlayer(int nHp, int nMana, char* cName);
	//소멸자
	~CPlayer();
	//멤버함수
	void SetHp(int dmg = 0);
	void SetMana(int dmg = 0);
    void ShowStatus();
	void ShowPos();
	int GetUserCnt() { return m_nUser; }
private:
	int m_nHp, m_nMana, m_nXpos, m_nYpos;
	static int m_nUser;
	char* m_cName;
};