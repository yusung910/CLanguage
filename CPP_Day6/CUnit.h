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
    //�����
    E_HP = 0,
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
    int* GetUnitInfo();
    //���� �̸��� �����Ѵ�.
	CString GetName() { return m_cName; };

protected:
    //���� Ÿ��
    int m_nUnitType;
    //������ �⺻ ������ ����� �迭
    int m_nUnitInfo[E_UNIT_INFO::E_INFO_CNT];
    //���� ��� ������ ����� �迭
    int* m_nSkillList;
    //��ü�� �̸�
    CString m_cName;
private:
};