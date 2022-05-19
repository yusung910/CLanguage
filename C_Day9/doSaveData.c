#include <stdio.h>
#include <stdlib.h>

#include "cnst.h"

BOOL doSaveData(CHARACTER** players, int* nTurn, int* nResurection) {
	char cSaveFlag = '\0';
	BOOL retFlag = FALSE;
	while (1) {
		printf("게임을 종료하시기 전 마지막 정보를 저장하시겠습니까?(Y, N):");
		scanf(" %c", &cSaveFlag);
		if (cSaveFlag == 'Y' || cSaveFlag == 'y') {
			//게임 종료시 마지막 정보를 save.bin에 저장
			FILE *out;
			out = fopen("save.bin", "wb");

			int saveDmg[100];
			int saveLife[100];
			int saveTurn = (*nTurn) + 100;
            int saveRe = (*nResurection) + 100;
			for (int i = 0; i < 100; i++) {
				//캐릭터가 살아 있을 경우에 변수 값을 할당.
				if (players[i] != NULL) {
					saveDmg[i] = players[i]->nDamage + 100;
					saveLife[i] = players[i]->nLife + 100;
				}
				else {
					saveDmg[i] = 100;
					saveLife[i] = 100;
				}
			}
            //데미지 목록
			fwrite(saveDmg, 1, sizeof(saveDmg), out);
            //생명력 목록
			fwrite(saveLife, 1, sizeof(saveLife), out);
            //턴 정보
            fwrite(&saveTurn, 1, sizeof(saveTurn), out);
            //부활 수
			fwrite(&saveRe, 1, sizeof(saveRe), out);

			fclose(out);
			printf("\n게임 정보가 저장되었습니다!");
			retFlag = TRUE;
			break;
		}
		else if (cSaveFlag == 'N' || cSaveFlag == 'n') {
			printf("\ngame 종료!");
			retFlag = TRUE;
			break;
		}
		else if (cSaveFlag != '\0') {
			printf("\nY 또는 N을 입력하여주세요.\n");
			retFlag = FALSE;
		}
	}
	return retFlag;
}