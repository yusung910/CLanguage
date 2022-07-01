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
    //생명력
    E_HP,
    //최대 생명력
    E_MAX_HP,
    //마나
    E_MANA,
    //최대마나
    E_MAX_MANA,
    //데미지
    E_DAMAGE,
    E_INFO_CNT,
};
class CUnit{
public:
    //생성자
    CUnit();
    //소멸자
    ~CUnit();

    //객체 생성 갯수
    static int m_nOrganismCnt;

    //유닛의 이름을 세팅한다.
	void SetName(CString name);

    //유닛 세부 정보를 리턴한다
    unsigned int* GetUnitInfo();

    //유닛의 스킬 목록을 리턴한다
    int* GetUnitSkillList();

	//유닛의 체력을 세팅한다
	void SetUnitHp(int n);
	//유닛의 체력을 리턴한다
	int GetUnitHp();
	//유닛의 마나를 세팅한다.
	void SetUnitMana(int n);
	//유닛의 마나를 리턴한다
	int GetUnitMana();

    //유닛 이름을 리턴한다.
	CString GetName() { return m_cName; };

protected:
    //유닛 타입
    int m_nUnitType;

    //유닛의 기본 정보가 저장된 배열
    unsigned int m_nUnitInfo[E_UNIT_INFO::E_INFO_CNT];

    //유닛 기술 정보가 저장된 배열
    int* m_nSkillList;
    
    //유닛별로 사용 기술을 매개변수로 받아 공격력을 계산하여 리턴한다
    virtual int GetDamage(int m_UseSkill) = 0;

    //객체의 이름
    CString m_cName;
private:
};