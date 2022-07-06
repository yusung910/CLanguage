#pragma comment(lib, "Winmm.lib")
#include <stdio.h>
#include <conio.h>
#include "Drawing.h"
#include "Player.h"
#include "Skill.h"

enum E_MAIN_MENU {
    E_NEW_START = 0,
    E_CONTINUE,
    E_CREDIT,
};
class CSystem : public Drawing {
public:
    //생성자
    CSystem();
    //소멸자
    ~CSystem();
    //기본 배경 세팅
    void InitBasicDisplayArea();
    //게임 시작 메뉴
    void ShowMainMenu();

    //플레이어 생성
    void CreatePlayerObject();

    //게임 플레이 시작
    void PlayGame();

protected:
    //플레이어객체
    Player* m_player;
	//초당 프레임 수
	int m_nFrame = 600;
private:

};