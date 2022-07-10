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

	//COORD ���� �Ű������� �޾� �� 2���� �迭�� ����
	void SetDataToMap(COORD pos, int n);
	void SetDataToMap(int x, int y, int n);

	//������ �ǹ��� �����Ѵ�.
	//�Ű������� E_BUILD_TYPE�� �ش��ϴ� ���� ���� �޴´�.
	void SetBuild(COORD s, COORD e, int n);


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