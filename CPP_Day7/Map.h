#pragma once
#include "Drawing.h"
enum E_BACKGROUND {
    VILLAGE,
    INN,
    STORE,
    DEONGUN,
};

enum E_BUILD_TYPE {
	BUILD_INN = 1,
	BUILD_STORE,
	BUILD_DUNGEON,
	BUILD_OBSTACLE,
};

class Map : public Drawing {
public :
    //생성자
    Map();
    //소멸자
    ~Map();

    //게임 플레이 화면에 맵을 그리는 함수
    void SetPlayerCharacterMap(Player* player);
    void PrintMapData();
    //특정 지도를 세팅한다
    void SetMap(int n);

    int GetMapSizeX();
    int GetMapSizeY();

	//COORD 값을 매개변수로 받아 맵 2차원 배열에 세팅
	void SetDataToMap(COORD pos, int n);
	void SetDataToMap(int x, int y, int n);

	//마을에 건물을 생성한다.
	//매개변수로 E_BUILD_TYPE에 해당하는 정수 값을 받는다.
	void SetBuild(COORD s, COORD e, int n);


protected:
    //맵 사이즈
    int n_mMapSizeX = 299;
    int n_mMapSizeY = 99;
    int n_mMapSize[100][300];

    //게임 화면에 출력할 맵의 시작 좌표 값
    int n_PrintMapStartX = 0;
    int n_PrintMapStartY = 0;

    //게임 화면에 출력할 맵의 마지막 좌표 값
    int n_PrintMapEndX = 0;
    int n_PrintMapEndY = 0;
private:

};