#ifndef __DRAWING_H_
#define __DRAWING_H_

#include "CObject.h"
#include "CMonster.h"
#include "CUser.h"
#include "CSkill.h"

class CDrawing {
public:
    //배경을 세팅하는 함수
    void SetBackground();


    //전투 발생 시 유저와 몬스터 정보를 출력
	void PrintOfCombatInfo(CUser* user);
    void PrintOfCombatInfo(CMonster* monster);

    //유저가 사용할 수 있는 스킬 정보를 출력한다.
    void PrintUserSkillList(CSkill* skill);

	//유저가 사용한 기술을 출력한다.
	void PrintUserSkillAttack(CUser* user, CMonster* monster);

	//몬스터가 공격한 내용을 출력한다
	void PrintMonsterAttack(CUser* user, CMonster* monster);

    //전투 종료 메세지 출력
    void PrintCombatRslt(CUser* user, CMonster* monster);

	//유저정보를 표시할 객체 세팅
	void SetMsgPos(COORD pos);

    //출력하기 위한 위치를 저장하는 변수.
    COORD m_cdMsgPos;

	//유저 객체
	CUser* user;

	//몬스터 객체
	CMonster* monster;
protected:
private:
};
#endif