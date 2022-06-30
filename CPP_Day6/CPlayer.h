#pragma once
#include "CUnit.h"
//�÷��̾� Ŭ����
enum E_PLAYER_STAT {
    E_STR = 0,
    E_DEX,
    E_INT,
    E_LIFE,
	E_EXP,
	E_GOLD,
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
    //�÷��̾� ��ġ ���� ����
    void SetPlayerPos(COORD pos);
    void SetPlayerPos(int x, int y);

    //�÷��̾��� ���� �迭�� �����´�
    int* GetPlayerStat();

    //�÷��̾� ��ġ ���� �����´�.
    COORD GetPlayerPos();

    //�÷��̾��� ����� ����� �����Ѵ�
    CString* GetPlayerSkillNameList();

protected:

    //�÷��̾� ���� �迭
    int m_nStat[E_PLAYER_STAT::E_STAT_CNT];

    //ĳ������ Ŭ����
    int m_nPlayerClass;

    //�������� ����Ѵ�.
    int GetDamage(int m_UseSkill);

    //ĳ������ ��ġ
    COORD cdPosPlayer;

    //��ų���� ����� ����
    CString sSkillNameList[E_PLAYER_SKILL::PLAYER_SKILL_CNT] = {
        CString("����"),
        CString("�⺻����"),
        CString("��Ÿ"),
        CString("�������"),
    };

private:


};