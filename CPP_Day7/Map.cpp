#include "Map.h"

Map::Map() {
    n_mMapSizeX = 300;
    n_mMapSizeY = 100;

    n_mMapSize = new int*[n_mMapSizeY];
    //생성자
    //맵 변수를 0으로 초기화한다.
    for (int i = 0; i < n_mMapSizeY; i++) {
        n_mMapSize[i] = new int[n_mMapSizeX];
        memset(n_mMapSize[i], 0, sizeof(int)*n_mMapSizeX);
    }
}

Map::~Map() {
    //소멸자
    for (int i = 0; i < n_mMapSizeY; i++) {
        delete[] n_mMapSize[i];
    }

    delete[] n_mMapSize;
    n_mMapSize = NULL;
}

int** Map::GetMapArry() {
    return n_mMapSize;
}
void Map::SetMapArry(int** arr) {
    for (int i = 0; i < sizeof(arr)/sizeof(int); i++) {
        for (int j = 0; j<sizeof(arr[i])/sizeof(int); j++) {
            n_mMapSize[i][j] = arr[i][j];
        }
    }
};

void Map::SetMap(int n) {
    //지형에 맞는 맵을 넣는다.
	if (n == E_BACKGROUND::VILLAGE) {
		//inn 위치
		COORD s = { 100, 15 };
		COORD e = { 135, 30 };
		SetBuild(s, e, E_BUILD_TYPE::BUILD_INN);

	}
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
    COORD cdPlayerPos = player->GetPlayerPos();
	//캐릭터의 이전 위치
	COORD cdPlayerPrevPos = player->GetPlayerPosPrev();

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

    n_mMapSize[n_PlayerPosY][n_PlayerPosX] = E_BG_TILE::CHARACTOR;
    if (!CompareCoord(cdPlayerPos, cdPlayerPrevPos)) {
        SetDataToMap(cdPlayerPrevPos, E_BG_TILE::LAND);
    }
    

    PrintMapData();
}

void Map::PrintMapData() {
    int m_nDisplayStartX = 2;
    for (int i = n_PrintMapStartX; i <= n_PrintMapEndX; i++) {
        int m_nDisplayStartY = 2;
        for (int j = n_PrintMapStartY; j <= n_PrintMapEndY; j++) {
            PrintCtnt(m_nDisplayStartX, m_nDisplayStartY, n_mMapSize[j][i], true);
            m_nDisplayStartY++;
        }
        m_nDisplayStartX++;
    }
}

void Map::SetDataToMap(COORD pos, int n) {
	int nMapX = pos.X;
	int nMapY = pos.Y;
	n_mMapSize[nMapY][nMapX] = n;
}

void Map::SetDataToMap(int x, int y, int n) {
	n_mMapSize[y][x] = n;
}

void Map::SetBuild(COORD s, COORD e, int n) {
	int n_StartX = s.X;
	int n_StartY = s.Y;

	int n_EndX = e.X;
	int n_EndY = e.Y;

	//LEFT_TOP
    SetDataToMap(n_StartX - 1, n_StartY, E_BG_TILE::WALL);
    SetDataToMap(n_StartX, n_StartY - 1, E_BG_TILE::WALL);

	SetDataToMap(s, E_BG_TILE::WALL_LEFT_TOP);

    for (int a = (n_StartX + 1); a < n_EndX; a++) {
        SetDataToMap(a, n_StartY, E_BG_TILE::WALL_HORIZONTAL);
        SetDataToMap(a, n_StartY-1, E_BG_TILE::WALL);
    }

    //RIGHT_TOP
    SetDataToMap(n_EndX + 1, n_StartY, E_BG_TILE::WALL);
    SetDataToMap(n_EndX, n_StartY - 1, E_BG_TILE::WALL);
    SetDataToMap(n_EndX, n_StartY, E_BG_TILE::WALL_RIGHT_TOP);

    for (int b = (n_StartY + 1); b < n_EndY; b++) {
        SetDataToMap(n_EndX, b, E_BG_TILE::WALL_VERTICAL);
        SetDataToMap(n_EndX+1, b, E_BG_TILE::WALL);
    }

    //RIGHT_BOTTOM
    SetDataToMap(n_EndX + 1, n_EndY, E_BG_TILE::WALL);
    SetDataToMap(n_EndX, n_EndY + 1, E_BG_TILE::WALL);
    SetDataToMap(e, E_BG_TILE::WALL_RIGHT_BOTTOM);

    for (int d = (n_StartX + 1); d < n_EndX; d++) {
        SetDataToMap(d, n_EndY, E_BG_TILE::WALL_HORIZONTAL);
        SetDataToMap(d, n_EndY + 1, E_BG_TILE::WALL);
    }


	//LEFT_BOTTOM
    SetDataToMap(n_StartX - 1, n_EndY, E_BG_TILE::WALL);
    SetDataToMap(n_StartX, n_EndY + 1, E_BG_TILE::WALL);
	SetDataToMap(n_StartX, n_EndY, E_BG_TILE::WALL_LEFT_BOTTOM);

    for (int b = (n_StartY + 1); b < n_EndY; b++) {
        SetDataToMap(n_StartX, b, E_BG_TILE::WALL_VERTICAL);
        SetDataToMap(n_StartX - 1, b, E_BG_TILE::WALL);
    }

    //방해물이 아닌 일반 건물 생성시 입구를 그려준다.
    if (n != E_BUILD_TYPE::BUILD_OBSTACLE) {
        for (int d = (n_StartX + 3); d < (n_EndX - 2); d++) {
            SetDataToMap(d, n_EndY, E_BG_TILE::WALL);
            SetDataToMap(d, n_EndY + 1, E_BG_TILE::E_DOOR_INN);
        }
    }
};