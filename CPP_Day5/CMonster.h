#ifndef __MONSTER_H_
#define __MONSTER_H_

#include "CObject.h"
enum E_MONSTER_TYPE {
    GOBLINE = 1,
    COBOLT,
    GREMLINE,
    ORC,
    TROLL,
    MONSTER_MAX,
};

class CMonster : public CObject {

public:
    //������
    CMonster();
    //�Ҹ���
	virtual ~CMonster();
    //������ ����ġ�� ��ȯ�Ѵ�.
	int GetMonsterExp();
    //������ ������ ȭ�鿡 ǥ���Ѵ�.
    void Display();
    void Attack();
protected:

	void init();

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