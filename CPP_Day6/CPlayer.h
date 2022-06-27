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
class CPlayer : CUnit {
public:
    CPlayer();
    ~CPlayer();
    
    void SetPlayerName(CString name);
    CString GetPlayerName() { return m_cName; };
protected:
    //플레이어 스탯 배열
    int m_nStat[E_PLAYER_STAT::E_STAT_CNT];
    //캐릭터의 클래스
    int m_nPlayerClass;
private:

};