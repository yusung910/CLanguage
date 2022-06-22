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

	//여관에서의 메세지 출력
	void PrintOutInnMsg(CUser* user);

	//위치를 지정한다
	void gotoxy(int x, int y);
    void gotoxy(COORD pos);

    //상점 건물을 그린다.
    void PrintBuilding(COORD cdStartPos, COORD cdEndPos);

    //메세지 출력하는 구역을 초기화한다.
    void ClearMsgArea();

    //출력하기 위한 위치를 저장하는 변수.
    COORD m_cdMsgPos;

    //여관 좌표
    COORD cdInnStart = { 5, 10 };
    COORD cdInnEnd = { 25, 20 };
    

    //상점좌표
    COORD cdStoreStart = { 30, 10 };
    COORD cdStoreEnd = { 50, 20 };

    //사냥터 좌표
    COORD cdDungeonStart = { 55, 10 };
    COORD cdDungeonEnd = { 75, 20 };

    //사냥터 출구 좌표
    COORD cdExitDungeonStart = { 0, 0 };
    COORD cdExitDungeonEnd = { 10, 10 };

	int nArryMap[80][30];
protected:
private:

};
#endif