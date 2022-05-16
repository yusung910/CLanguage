#include <stdlib.h> // rand() 함수
#include <time.h>   // time() 함수
#include <malloc.h>

#include "cnst.h"

void initUser(CHARACTER* players) {
    players = (CHARACTER*)malloc(sizeof(CHARACTER) * 100);
    for (int i = 0; i < 100; i++) {
        players->nLife = (rand() % 51) + 50;
        players->nDamage = 0;
        players++;
    }

}