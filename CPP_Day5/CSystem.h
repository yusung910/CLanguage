#ifndef __SYSTEM_H_
#define __SYSTEM_H_

#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "CObject.h"
#include "CMonster.h"
#include "CUser.h"
#include "CDrawing.h"
#include "CBattle.h"


enum E_DIR_KEY {
    UP = 72,
    DOWN = 80,
    LEFT = 75,
    RIGHT = 77
};


class CSystem {
    public:
        CSystem();
        ~CSystem();
        //���� �÷��̾� ������ ����
        void GameUserCharacterCreate();
        //���� ���� ������ �ε�
        void GameBasicLoad();

        //���� ����
        void GamePlaying();

		//���� �� ��ȣ�ۿ�
		void GameInterPlay();

        //���� ���
        int n_currentBg = E_BACKGROUND_TYPE::VILLAGE;

        //���� ���� ���� �÷���
        int b_GameEndFlag = 1;

        CDrawing* drawingObj;
        CUser* user;
        CMonster* monster;
        CBattle* battle;
    private:
    public:
};
#endif