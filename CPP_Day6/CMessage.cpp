#include "CMessage.h"

CMessage::CMessage() {
}

CMessage::~CMessage() {
}

void CMessage::PrintCreatePlayerMsg() {
    SetPos(20, 25);
    cout << "ĳ���� ���� �Է��Ͽ� �ּ���:";
}

void CMessage::PrintPlayerInfoMsg(CPlayer* player) {
    SetPos(10, 2);
    cout << "ĳ���� : ";
    player->GetPlayerName().Display();
}