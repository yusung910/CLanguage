#pragma once
#include "String.h"
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
	//���ݺ� ��Ī ����
	String n_lStatNm[E_CREATURE_BASIC_STAT::STAT_CNT] = {
		String("ü��"),
		String("����"),
		String("����"),
		String("���ݷ�")
	};
private:
};