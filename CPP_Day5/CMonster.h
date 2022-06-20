#ifndef __MONSTER_H_
#define __MONSTER_H_

//#include "CObject.h"
#include "CSkill.h"
enum E_MONSTER_TYPE {
    GOBLINE = 1,
    COBOLT,
    GREMLINE,
    ORC,
    TROLL,
    MONSTER_MAX,
};

class CMonster : public CSkill {

public:
    //������
    CMonster();
    //�Ҹ���
	virtual ~CMonster();
    //������ ����ġ�� ��ȯ�Ѵ�.
	int GetMonsterExp();
    //������ ������ ȭ�鿡 ǥ���Ѵ�.
    void Display();
	//������ ������ �����ϰ� ������ ���� ���Ϲ޴´�.
    int Attack();
	//���Ͱ� ������ �ִ� ��ų����� ȣ���Ѵ�
	void ShowSkillList();
	//���͸��� ����
	void SetMonsterName();
    //���͸��� ����
    char* GetMonsterName();
	//���� ������ �����Ѵ�.
	void init();
    //�̵� �Լ��� ����ȭ
    void Move();
    //���� ü���� �����Ѵ�.
    int GetMonsterHP();
	//������ ü���� �����Ѵ�
	void SetMonsterHP(int n);
    //������ ���ݷ��� �����Ѵ�.
    int GetMonsterAttack() { return m_nAttack; };
private:
    //���� ����ġ
	int m_nMonsterExp;
    //���� ü��
    int	m_nHP;
    //���� ����
    int	m_nMana;
    //���� ����
    int	m_nLEVEL;
    //���� ���ݷ�
    int m_nAttack;
    //���� ����
    int m_nMobInfo;
};
#endif