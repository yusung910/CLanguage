#pragma once
#include "CDrawing.h"
#include "CMessage.h"
#include "CPlayer.h"

class CSystem : public CMessage{
public:
    //생성자
    CSystem();
    //소멸자
    ~CSystem();
	//메인화면 메뉴 선택기능
	void SelectedMainMenu();
	//
	void CreatePlayerData();
    void LoadPlayerData();

private:

protected:
    CPlayer* o_player;
};