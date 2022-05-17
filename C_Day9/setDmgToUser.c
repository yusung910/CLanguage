#include <stdio.h>

#include "cnst.h"
#include "setDmgToUser.h"

void setDmgToUser(CHARACTER** players, float* nDmgProbList) {
	//데미지 계산
	for (int j = 0; j < 100; j++) {
		if (players[j] != '\0') {
			//모든 player들에게 임의의 데미지를 부여한다. 100.00
			//매 턴이 반복될 수록 높은 데미지를 입을 수 있도록 난이도를 상향 평준화 한다.
			float nFlagDmg = (float)(rand() % 10000) / 100;

			int nDmg = 0;
			float nBegin = 0;
			float nEnd = 0;

			for (int i = 0; i < 11; i++) {
				float nProb = nDmgProbList[i] * 100;
				nBegin = (i == 0) ? 0 : nEnd;
				nEnd = nEnd + (nProb);

				if (nBegin <= nFlagDmg && nFlagDmg < nEnd) {
					nDmg = i;
				}
			}


            int userLife = players[j]->nLife;

			players[j]->nDamage = nDmg;
			players[j]->nLife = userLife - nDmg;

			if (players[j]->nLife <= 0) {
				//데미지를 입은 유저를 사망처리
				free(players[j]);
				players[j] = NULL;
			}
		}
	}
}