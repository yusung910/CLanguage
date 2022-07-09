#pragma once
#include "Drawing.h"
enum E_BACKGROUND {
    VILLAGE,
    INN,
    STORE,
    DEONGUN,
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