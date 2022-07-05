#pragma once
#include <stdio.h>
#include <conio.h>
#include "Drawing.h"
#include "Player.h"

enum E_MAIN_MENU {
    E_NEW_START = 0,
    E_CONTINUE,
    E_CREDIT,
};

class CSystem : public Drawing {
public:
    //������
    CSystem();
    //�Ҹ���
    ~CSystem();
    //�⺻ ��� ����
    void InitBasicDisplayArea();
    //���� ���� �޴�
    void ShowMainMenu();

    //�÷��̾� ����
    void CreatePlayerObject();

    //���� �÷��� ����
    void PlayGame();

protected:
    //�÷��̾ü
    Player* m_player;

private:

};