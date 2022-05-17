#include <stdio.h>

#include "cnst.h"
#include "setDmgToUser.h"

void setDmgToUser(CHARACTER** players, float* nDmgProbList) {
	//������ ���
	for (int j = 0; j < 100; j++) {
		if (players[j] != '\0') {
			//��� player�鿡�� ������ �������� �ο��Ѵ�. 100.00
			//�� ���� �ݺ��� ���� ���� �������� ���� �� �ֵ��� ���̵��� ���� ����ȭ �Ѵ�.
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
				//�������� ���� ������ ���ó��
				free(players[j]);
				players[j] = NULL;
			}
		}
	}
}