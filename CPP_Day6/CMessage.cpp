#include "CMessage.h"

CMessage::CMessage() {
}

CMessage::~CMessage() {
}

void CMessage::PrintCreatePlayerMsg() {
    SetPos(20, 24);
    cout << "ĳ���� ���� �Է��Ͽ� �ּ���:";
}

void CMessage::PrintPlayerInfoMsg(CPlayer* player) {
    int* aPlayerStat = player->GetPlayerStat();
    int* aPlayerInfo = player->GetUnitInfo();
    SetPos(10, 23);
    cout << "ĳ���� : ";
    player->GetName().Display();
    
    for (int i = 0; i < E_PLAYER_STAT::E_STAT_CNT; i++) {
        SetPos(10, (24+i));
        switch (i) {
        case E_PLAYER_STAT::E_STR:
            cout << "�� : ";
            break; 
        case E_PLAYER_STAT::E_DEX:
            cout << "��ø : ";
            break;
        case E_PLAYER_STAT::E_INT:
            cout << "���� : ";
            break;
        case E_PLAYER_STAT::E_LIFE:
            cout << "����� : ";
            break;
        }
        cout << aPlayerStat[i];
    }


    for (int j = 0; j < E_UNIT_INFO::E_INFO_CNT; j++) {
        SetPos(50, (23 + j));
        switch (j) {
        case E_UNIT_INFO::E_HP:
            cout << "ü�� : ";
            break;
        case E_UNIT_INFO::E_MAX_HP:
            cout << "�ִ� ü�� : ";
            break;
        case E_UNIT_INFO::E_MANA:
            cout << "���� : ";
            break;
        case E_UNIT_INFO::E_MAX_MANA:
            cout << "�ִ� ���� : ";
            break;
        case E_UNIT_INFO::E_DAMAGE:
            cout << "���ݷ� : ";
            break;
        }
        cout << aPlayerInfo[j];
    }
}