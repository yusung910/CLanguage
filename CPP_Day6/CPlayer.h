#pragma once
#include "CUnit.h"
//�÷��̾� Ŭ����
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
    //�÷��̾� ���� �迭
    int m_nStat[E_PLAYER_STAT::E_STAT_CNT];
    //ĳ������ Ŭ����
    int m_nPlayerClass;
private:

};