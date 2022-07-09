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
    //������
    Map();
    //�Ҹ���
    ~Map();

    //���� �÷��� ȭ�鿡 ���� �׸��� �Լ�
    void SetPlayerCharacterMap(Player* player);
    void PrintMapData();
    //Ư�� ������ �����Ѵ�
    void SetMap(int n);

    int GetMapSizeX();
    int GetMapSizeY();

protected:
    //�� ������
    int n_mMapSizeX = 299;
    int n_mMapSizeY = 99;
    int n_mMapSize[100][300];

    //���� ȭ�鿡 ����� ���� ���� ��ǥ ��
    int n_PrintMapStartX = 0;
    int n_PrintMapStartY = 0;

    //���� ȭ�鿡 ����� ���� ������ ��ǥ ��
    int n_PrintMapEndX = 0;
    int n_PrintMapEndY = 0;
private:

};