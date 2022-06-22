#ifndef __SYSTEM_H_
#define __SYSTEM_H_

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
        //게임 플레이어 데이터 생성
        void GameUserCharacterCreate();
        //게임 기초 데이터 로드
        void GameBasicLoad();

        //게임 진행
        void GamePlaying();

        //현재 배경
        int n_currentBg = E_BACKGROUND_TYPE::VILLAGE;

        //게임 진행 여부 플래그
        int b_GameEndFlag = 1;

        CDrawing* drawingObj;
        CUser* user;
        CMonster* monster;
        CBattle* battle;
    private:
    public:
};
#endif