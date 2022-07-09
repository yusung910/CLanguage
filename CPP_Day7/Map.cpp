#include "Map.h"

Map::Map() {
    //생성자
    //맵 변수를 0으로 초기화한다.
    for (int i = 0; i < n_mMapSizeY; i++) {
        memset(n_mMapSize[i], 0, sizeof(int)*n_mMapSizeX);
    }
}

Map::~Map() {
    //소멸자
}

void Map::SetMap(int n) {
    //각각 귀퉁이 맵 넣기
}

int Map::GetMapSizeX() {
    return n_mMapSizeX;
}

int Map::GetMapSizeY() {
    return n_mMapSizeY;
}

void Map::SetPlayerCharacterMap(Player* player) {

    //화면의 크기 int a[32][112]
    //맵의 크기 int b[100][300]
    //플레이어의 위치 : cdPlayerPos
    //게임 화면의 센터 좌표
    //int cdArea1CenterX, int cdArea1CenterY
    COORD cdPlayerPos = player->GetPlayerPos();

    int n_PlayerPosX = cdPlayerPos.X;
    int n_PlayerPosY = cdPlayerPos.Y;

    n_PrintMapStartX = (n_PlayerPosX - cdArea1CenterX) <= 0 ? 0 : n_PlayerPosX - cdArea1CenterX;
    n_PrintMapStartY = (n_PlayerPosY - cdArea1CenterY) <= 0 ? 0 : n_PlayerPosY - cdArea1CenterY;

    //게임 화면에 출력할 맵의 마지막 X 좌표 값
    if (n_PlayerPosX <= cdArea1CenterX) {
        n_PrintMapEndX = cdArea1end.X - cdArea1Start.X;
    }
    else {
        if ((n_PlayerPosX + cdArea1CenterX) >= n_mMapSizeX) {
            n_PrintMapEndX = n_mMapSizeX;
            n_PrintMapStartX = n_mMapSizeX - (cdArea1CenterX * 2);
        }
        else {
            n_PrintMapEndX = n_PlayerPosX + cdArea1CenterX;
        }
    }

    //게임 화면에 출력할 맵의 마지막 Y 좌표 값
    if (n_PlayerPosY <= cdArea1CenterY) {
        n_PrintMapEndY = cdArea1end.Y - cdArea1Start.Y;
    }
    else {
        if ((n_PlayerPosY + cdArea1CenterY) >= n_mMapSizeY) {
            n_PrintMapEndY = n_mMapSizeY;
            n_PrintMapStartY = n_mMapSizeY - (cdArea1CenterY * 2);
        }
        else {
            n_PrintMapEndY = n_PlayerPosY + cdArea1CenterY;
        }
    }

    //맵에 캐릭터까지 세팅한다.
    //n_mMapSize[n_PlayerPosY][n_PlayerPosX] = 1;

    PrintMapData();
}

void Map::PrintMapData() {
    int m_nDisplayStartX = 2;
    for (int i = n_PrintMapStartX; i <= n_PrintMapEndX; i++) {
        int m_nDisplayStartY = 2;
        for (int j = n_PrintMapStartY; j <= n_PrintMapEndY; j++) {
            PrintCtnt(m_nDisplayStartX, m_nDisplayStartY, n_mMapSize[j][i]);
            m_nDisplayStartY++;
        }
        m_nDisplayStartX++;
    }
}