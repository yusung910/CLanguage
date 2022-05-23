#include <stdio.h>
#include <stdlib.h>

#include "cnst.h"
#include "doPrintCurrentStatus.h"
#include "setDmgProb.h"
#include "initUser.h"

void doLoadData(CHARACTER** players, float* nDmgProbList, int* nTurn, int* nResurection) {
	FILE* in;
	in = fopen("save.bin", "rb");
	if (in != NULL) {
		char answer = '\0';
		while (1) {
			printf("���� ���̺� ������ �����մϴ�. �ҷ����ڽ��ϱ�?(Y,N) : ");
			scanf("%c", &answer);
			if (answer == 'Y' || answer == 'y') {
				int nBeforeDmg = 0;
				int nBeforeLife = 0;
				int nDeath = 0;
				int loadTurn = 0;
                int loadRe = 0;
				for (int i = 0; i < 100; i++) {

					fseek(in, (4 * i), SEEK_SET);
					fread(&nBeforeDmg, 1, sizeof(int), in);
					fseek(in, 400 + (4 * i), SEEK_SET);
					fread(&nBeforeLife, 1, sizeof(int), in);

					nBeforeDmg -= 100;
					nBeforeLife -= 100;
					if (nBeforeDmg == 0 && nBeforeLife == 0) {
						players[i] = NULL;
                        nDeath += 1;
					}
					else {
						players[i] = (CHARACTER*)malloc(sizeof(CHARACTER));
						players[i]->nLife = nBeforeLife;
						players[i]->nDamage = nBeforeDmg;
					}
				}

				//�ϼ� ����
				fseek(in, -8, SEEK_END);
				fread(&loadTurn, 1, sizeof(int), in);
				*nTurn = loadTurn - 100;

                //��Ȱ �� ����
                fseek(in, -4, SEEK_END);
                fread(&loadRe, 1, sizeof(int), in);
                *nResurection = loadRe - 100;

				//�������� Ȯ���� �����Ѵ�.
				setDmgProb(nDmgProbList, *nTurn);
				printf("Turn : %d\n", *nTurn);

				doPrintCurrentStatus(players, nDmgProbList, *nResurection, (nDeath+(*nResurection)));
				break;
			}
			else if (answer == 'N' || answer == 'n') {
				//ĳ���� �ʱ� �����Ѵ�.
				initUser(players);
				break;
			}
			else {
				puts("Y �Ǵ� N�� �Է����ּ���.");
			}
		}
		fclose(in);
	}
	else {
		initUser(players);
	}


}