#ifndef __DRAWING_H_
#define __DRAWING_H_

#include "CMonster.h"
#include "CUser.h"
#include "CSkill.h"

class CDrawing {
public:
    //배경을 세팅하는 함수
    void SetBackground();
    //멤버변수 m_cdDrawingPos를 세팅
    void SetCdDrawingPos(COORD pos);

    //몬스터정보를 출력한다.
    void PrintOfInfo(CMonster* monster);

    //유저정보를 출력한다.
    void PrintOfInfo(CUser* user);

    //유저가 사용할 수 있는 스킬 정보를 출력한다.
    void PrintUserSkillList(CSkill* skill);

	//유저가 사용한 기술을 출력한다.
	void PrintUserSkillAttack(CUser* user, CMonster* monster);

	//몬스터가 공격한 내용을 출력한다
	void PrintMonsterAttack(CUser* user, CMonster* monster);

    //전투 종료 메세지 출력
    void PrintCombatEnd(CUser* user, CMonster* monster);

    //세팅된 멤버변수 m_cdDrawingPos를 리턴
    COORD GetCdDrawingPos();

    //출력하기 위한 위치를 저장하는 변수.
    COORD m_cdDrawingPos;
protected:
private:
};
#endif