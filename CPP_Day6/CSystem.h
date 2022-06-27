#pragma once
#include "CDrawing.h"

class CSystem : CDrawing{
public:
    //생성자
    CSystem();
    //소멸자
    ~CSystem();
	//메인화면 메뉴 선택기능
	void SelectedMainMenu();
	//
	void GameStart();
private:

protected:
};