#include "characterStruct.h"
#include "initCharacter.h"

void initCharacter(CHARACTER* charList[100], int initCnt) {

	for (int i = 0; i < initCnt; i++) {
		charList[i] = (CHARACTER*)malloc(sizeof(CHARACTER));
		charList[i]->nLife = (rand() % 51) + 50;
		charList[i]->nDamage = 0;
	}
}