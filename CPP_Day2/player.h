#pragma once
class CPlayer
{
public:
	//������
	CPlayer(int nHp, int nMana, char* cName);
	//�Ҹ���
	~CPlayer();
	//����Լ�
	void SetHp(int dmg = 0);
	void SetMana(int dmg = 0);
    void ShowStatus();
private:
	int m_nHp, m_nMana;
	char* m_cName;
};