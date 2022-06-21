#ifndef __DRAWING_H_
#define __DRAWING_H_

#include "CObject.h"
#include "CMonster.h"
#include "CUser.h"
#include "CSkill.h"

enum E_BACKGROUND_TYPE {
    VILLAGE = 0,
    DUNGEON,
    STORE,
    INN,
};

class CDrawing {
public:
    //생성자 소멸자.
    CDrawing();
    ~CDrawing();
    //배경을 세팅하는 함수
    void SetBackground();

    void PrintOfHome();
    //사각형 그리기 함수
    void PrintSquare(COORD cdStartPos, COORD cdEndPos);

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

    //던전 그리기
    void PrintDungeon();

	//유저정보를 표시할 객체 세팅
	void SetMsgPos(COORD pos);

    //플레이어가 위치하고 있는 건물을 가져온다.
    int GetUserPosBuild(COORD pos, int nCurrentMap);
    //출력하기 위한 위치를 저장하는 변수.
    COORD m_cdMsgPos;

    //여관 좌표
    COORD cdInnStart = { 10, 10 };
    COORD cdInnEnd = { 40, 25 };

    //상점좌표
    COORD cdStoreStart = { 60, 10 };
    COORD cdStoreEnd = { 90, 25 };

    //사냥터 좌표
    COORD cdDungeonStart = { 110, 10 };
    COORD cdDungeonEnd = { 140, 25 };
    //사냥터 출구 좌표
    COORD cdExitDungeonStart = { 0, 0 };
    COORD cdExitDungeonEnd = { 15, 10 };
protected:
private:

};
#endif