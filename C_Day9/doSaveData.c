#include <stdio.h>
#include <stdlib.h>

#include "cnst.h"

BOOL doSaveData(CHARACTER** players, int* nTurn, int* nResurection) {
	char cSaveFlag = '\0';
	BOOL retFlag = FALSE;
	while (1) {
		printf("������ �����Ͻñ� �� ������ ������ �����Ͻðڽ��ϱ�?(Y, N):");
		scanf(" %c", &cSaveFlag);
		if (cSaveFlag == 'Y' || cSaveFlag == 'y') {
			//���� ����� ������ ������ save.bin�� ����
			FILE *out;
			out = fopen("save.bin", "wb");

			int saveDmg[100];
			int saveLife[100];
			int saveTurn = (*nTurn) + 100;
            int saveRe = (*nResurection) + 100;
			for (int i = 0; i < 100; i++) {
				//ĳ���Ͱ� ��� ���� ��쿡 ���� ���� �Ҵ�.
				if (players[i] != NULL) {
					saveDmg[i] = players[i]->nDamage + 100;
					saveLife[i] = players[i]->nLife + 100;
				}
				else {
					saveDmg[i] = 100;
					saveLife[i] = 100;
				}
			}
            //������ ���
			fwrite(saveDmg, 1, sizeof(saveDmg), out);
            //����� ���
			fwrite(saveLife, 1, sizeof(saveLife), out);
            //�� ����
            fwrite(&saveTurn, 1, sizeof(saveTurn), out);
            //��Ȱ ��
			fwrite(&saveRe, 1, sizeof(saveRe), out);

			fclose(out);
			printf("\n���� ������ ����Ǿ����ϴ�!");
			retFlag = TRUE;
			break;
		}
		else if (cSaveFlag == 'N' || cSaveFlag == 'n') {
			printf("\ngame ����!");
			retFlag = TRUE;
			break;
		}
		else if (cSaveFlag != '\0') {
			printf("\nY �Ǵ� N�� �Է��Ͽ��ּ���.\n");
			retFlag = FALSE;
		}
	}
	return retFlag;
}