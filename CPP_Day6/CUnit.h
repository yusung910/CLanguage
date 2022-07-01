#pragma once
#include <windows.h>
#include "CString.h"
#include "CPoint.h"
enum E_UNIT_TYPE {
    E_PLAYER = 1,
    E_NPC,
    E_MONSTER
};

enum E_UNIT_INFO {
	E_LVL = 0, 
    //�����
    E_HP,
    //�ִ� �����
    E_MAX_HP,
    //����
    E_MANA,
    //�ִ븶��
    E_MAX_MANA,
    //������
    E_DAMAGE,
    E_INFO_CNT,
};
class CUnit{
public:
    //������
    CUnit();
    //�Ҹ���
    ~CUnit();

    //��ü ���� ����
    static int m_nOrganismCnt;

    //������ �̸��� �����Ѵ�.
	void SetName(CString name);

    //���� ���� ������ �����Ѵ�
    unsigned int* GetUnitInfo();

    //������ ��ų ����� �����Ѵ�
    int* GetUnitSkillList();

	//������ ü���� �����Ѵ�
	void SetUnitHp(int n);
	//������ ü���� �����Ѵ�
	int GetUnitHp();
	//������ ������ �����Ѵ�.
	void SetUnitMana(int n);
	//������ ������ �����Ѵ�
	int GetUnitMana();

    //���� �̸��� �����Ѵ�.
	CString GetName() { return m_cName; };

protected:
    //���� Ÿ��
    int m_nUnitType;

    //������ �⺻ ������ ����� �迭
    unsigned int m_nUnitInfo[E_UNIT_INFO::E_INFO_CNT];

    //���� ��� ������ ����� �迭
    int* m_nSkillList;
    
    //���ֺ��� ��� ����� �Ű������� �޾� ���ݷ��� ����Ͽ� �����Ѵ�
    virtual int GetDamage(int m_UseSkill) = 0;

    //��ü�� �̸�
    CString m_cName;
private:
};