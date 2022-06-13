#include <iostream>
#include "CObject.h"
#include "CMonster.h"
#include "CUser.h"

void main() {
    CObject* player = new CUser;

    player->SetName("플레이어1");
    player->Display();
}
