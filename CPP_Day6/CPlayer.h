#pragma once
#include "CUnit.h"
//플레이어 클래스
enum E_PLAYER_STAT {
    E_STR = 0,
    E_DEX,
    E_INT,
    E_LIFE,
    E_STAT_CNT,
};

enum E_PLAYER_SKILL {
    ESCAPE = 0,
    BASIC_ATTACK,
    BASH,
    DOUBLE_ATTACK,
    PLAYER_SKILL_CNT,
};

class CPlayer : public CUnit {
public:
    CPlayer();
    ~CPlayer();
    //플레이어 위치 값을 세팅
    void SetPlayerPos(COORD pos);
    void SetPlayerPos(int x, int y);
    //플레이어의 스탯 배열을 가져온다
    int* GetPlayerStat();

    //플레이어 위치 값을 가져온다.
    COORD GetPlayerPos();

protected:
    //플레이어 스탯 배열
    int m_nStat[E_PLAYER_STAT::E_STAT_CNT];
    //캐릭터의 클래스
    int m_nPlayerClass;
    //캐릭터의 위치
    COORD cdPosPlayer;

private:


};