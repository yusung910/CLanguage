#include <iostream>
#include "CObject.h"
#include "CMonster.h"
#include "CUser.h"

void main() {
    CObject* player = new CUser;

    player->SetName("�÷��̾�1");
    player->Display();
}
