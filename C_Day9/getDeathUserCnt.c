#include <stdio.h>

#include "cnst.h"
int getDeathUserCnt(CHARACTER** players) {
	int nDeathCharCnt = 0;
	for (int f = 0; f < 100; f++) {
		if (players[f] == NULL) {
			nDeathCharCnt += 1;
		}
	}

	return nDeathCharCnt;
}