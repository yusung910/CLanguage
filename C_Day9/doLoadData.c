#include <stdio.h>
#include <stdlib.h>

#include "cnst.h"
#include "doPrintCurrentStatus.h"
#include "setDmgProb.h"
#include "initUser.h"

void doLoadData(CHARACTER** players, float* nDmgProbList, int* nTurn) {
	FILE* in;
	in = fopen("save.bin", "rb");
	if (in != NULL) {
		char answer = '\0';
		while (1) {
			printf("기존 세이브 파일이 존재합니다. 불러오겠습니까?(Y,N) : ");
			scanf("%c", &answer);
			if (answer == 'Y' || answer == 'y') {
				int nBeforeDmg = 0;
				int nBeforeLife = 0;
				int nR = 0;
				int loadTurn = 0;
				for (int i = 0; i < 100; i++) {

					fseek(in, (4 * i), SEEK_SET);
					fread(&nBeforeDmg, 1, sizeof(int), in);
					fseek(in, 400 + (4 * i), SEEK_SET);
					fread(&nBeforeLife, 1, sizeof(int), in);

					nBeforeDmg -= 100;
					nBeforeLife -= 100;
					if (nBeforeDmg == 0 && nBeforeLife == 0) {
						players[i] = NULL;
					}
					else {
						players[i] = (CHARACTER*)malloc(sizeof(CHARACTER));
						players[i]->nLife = nBeforeLife;
						players[i]->nDamage = nBeforeDmg;
						nR += 1;
					}
				}

				//턴수 저장
				fseek(in, -4, SEEK_END);
				fread(&loadTurn, 1, sizeof(int), in);
				nTurn = loadTurn - 100;

				//데미지별 확률을 세팅한다.
				setDmgProb(nDmgProbList, nTurn);
				printf("Turn : %d\n", nTurn);

				doPrintCurrentStatus(players, nDmgProbList, nR, (100 - nR));
				break;
			}
			else if (answer == 'N' || answer == 'n') {
				//캐릭터 초기 세팅한다.
				initUser(players);
				break;
			}
			else {
				puts("Y 또는 N을 입력해주세요.");
			}
		}
		fclose(in);
	}
	else {
		initUser(players);
	}


}