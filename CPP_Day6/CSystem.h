#pragma once
#include "CDrawing.h"
#include "CMessage.h"
#include "CPlayer.h"
#include "CMonster.h"

class CSystem : public CMessage{
public:
    //생성자
    CSystem();
    //소멸자
    ~CSystem();
	//메인화면 메뉴 선택기능
	void SelectedMainMenu();
	//플레이어 캐릭터 생성
	void CreatePlayerData();
    //저장 데이터 불러오기
    void LoadPlayerData();
    //게임 플레이 시작
    void PlayGame();
    //플레이어 이동
    void MovePlayer(COORD cdPrevPos, COORD cdNextPos);

private:

protected:
    CPlayer* o_player;
};