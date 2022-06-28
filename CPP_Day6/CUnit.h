#pragma once
#include <windows.h>
#include "CString.h"
enum E_UNIT_TYPE {
    E_PLAYER = 1,
    E_NPC,
    E_MONSTER
};
class CUnit {
public:
    //������
    CUnit();
    //�Ҹ���
    ~CUnit();

    //��ü ���� ����
    static int m_nOrganismCnt;

	void SetName(CString name);
	CString GetName() { return m_cName; };

protected:
    //�����
    int m_nHp;
    //�ִ� �����
    int m_nMaxHp;
    //����
    int m_nMana;
    //�ִ� ����
    int m_maxMana;
    //���·�
    int m_nDamage;
    //���� Ÿ��
    int m_nUnitType;
    //��ü�� �̸�
    CString m_cName;
private:
};