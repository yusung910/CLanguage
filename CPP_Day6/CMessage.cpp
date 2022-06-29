#include "CMessage.h"

CMessage::CMessage() {
}

CMessage::~CMessage() {
}

void CMessage::PrintCreatePlayerMsg() {
    SetPos(20, 24);
    cout << "캐릭터 명을 입력하여 주세요:";
}

void CMessage::PrintPlayerInfoMsg(CPlayer* player) {
    int* aPlayerStat = player->GetPlayerStat();
    int* aPlayerInfo = player->GetUnitInfo();
    SetPos(10, 23);
    cout << "캐릭명 : ";
    player->GetName().Display();
    
    for (int i = 0; i < E_PLAYER_STAT::E_STAT_CNT; i++) {
        SetPos(10, (24+i));
        switch (i) {
        case E_PLAYER_STAT::E_STR:
            cout << "힘 : ";
            break; 
        case E_PLAYER_STAT::E_DEX:
            cout << "민첩 : ";
            break;
        case E_PLAYER_STAT::E_INT:
            cout << "지력 : ";
            break;
        case E_PLAYER_STAT::E_LIFE:
            cout << "생명력 : ";
            break;
        }
        cout << aPlayerStat[i];
    }


    for (int j = 0; j < E_UNIT_INFO::E_INFO_CNT; j++) {
        SetPos(50, (23 + j));
        switch (j) {
        case E_UNIT_INFO::E_HP:
            cout << "체력 : ";
            break;
        case E_UNIT_INFO::E_MAX_HP:
            cout << "최대 체력 : ";
            break;
        case E_UNIT_INFO::E_MANA:
            cout << "마나 : ";
            break;
        case E_UNIT_INFO::E_MAX_MANA:
            cout << "최대 마나 : ";
            break;
        case E_UNIT_INFO::E_DAMAGE:
            cout << "공격력 : ";
            break;
        }
        cout << aPlayerInfo[j];
    }
}