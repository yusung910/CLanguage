#include <stdlib.h> // rand() �Լ�
#include <time.h>   // time() �Լ�
#include <malloc.h>

#include "cnst.h"

void initUser(CHARACTER** players) {
	for (int i = 0; i < 100; i++){
		players[i] = (CHARACTER*)malloc(sizeof(CHARACTER));
		players[i]->nLife = (rand() % 51) + 50;
		players[i]->nDamage = 0;
	}
}