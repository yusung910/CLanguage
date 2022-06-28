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
    //생성자
    CUnit();
    //소멸자
    ~CUnit();

    //객체 생성 갯수
    static int m_nOrganismCnt;

	void SetName(CString name);
	CString GetName() { return m_cName; };

protected:
    //생명력
    int m_nHp;
    //최대 생명력
    int m_nMaxHp;
    //마나
    int m_nMana;
    //최대 마나
    int m_maxMana;
    //공력력
    int m_nDamage;
    //유닛 타입
    int m_nUnitType;
    //객체의 이름
    CString m_cName;
private:
};