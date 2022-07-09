#include "Map.h"

Map::Map() {
    //������
    //�� ������ 0���� �ʱ�ȭ�Ѵ�.
    for (int i = 0; i < n_mMapSizeY; i++) {
        memset(n_mMapSize[i], 0, sizeof(int)*n_mMapSizeX);
    }
}

Map::~Map() {
    //�Ҹ���
}

void Map::SetMap(int n) {
    //���� ������ �� �ֱ�
}

int Map::GetMapSizeX() {
    return n_mMapSizeX;
}

int Map::GetMapSizeY() {
    return n_mMapSizeY;
}

void Map::SetPlayerCharacterMap(Player* player) {

    //ȭ���� ũ�� int a[32][112]
    //���� ũ�� int b[100][300]
    //�÷��̾��� ��ġ : cdPlayerPos
    //���� ȭ���� ���� ��ǥ
    //int cdArea1CenterX, int cdArea1CenterY
    COORD cdPlayerPos = player->GetPlayerPos();

    int n_PlayerPosX = cdPlayerPos.X;
    int n_PlayerPosY = cdPlayerPos.Y;

    n_PrintMapStartX = (n_PlayerPosX - cdArea1CenterX) <= 0 ? 0 : n_PlayerPosX - cdArea1CenterX;
    n_PrintMapStartY = (n_PlayerPosY - cdArea1CenterY) <= 0 ? 0 : n_PlayerPosY - cdArea1CenterY;

    //���� ȭ�鿡 ����� ���� ������ X ��ǥ ��
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

    //���� ȭ�鿡 ����� ���� ������ Y ��ǥ ��
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

    //�ʿ� ĳ���ͱ��� �����Ѵ�.
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