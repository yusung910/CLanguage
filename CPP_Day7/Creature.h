#pragma once
#include <windows.h>

#include "String.h"
#include "HashMap.h"

//�÷��̾�, ���� �� ����ü Ŭ����
enum E_CREATURE_BASIC_STAT {
	HP = 0,
	MANA,
	ATTACK,
	LEVEL,
	STAT_CNT,
};

class Creature : public String{
public:
	//������
	Creature();

	//�Ҹ���
	~Creature();

	//���� ���� �Լ�
	virtual int Attack(int n_skill) = 0;
	//ũ���� �̸� ���� �����Լ�
	virtual void SetName(String s) = 0;

	//�̸� ���
	void DisplayName();
	//ũ���� ��ü�� ���� ������ ī����
	static int n_CreatureCnt;
protected:
	//ũ���� ��ü�� �̸�
	String n_sName;

	//ũ������ �⺻���� ������ ����� HashMap
    HashMap<int, String, int> hm_BasicStat;
private:
};