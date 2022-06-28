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
    SetPos(10, 2);
    cout << "캐릭명 : ";
    player->GetName().Display();
}