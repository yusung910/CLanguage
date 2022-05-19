#include <stdio.h>
#include <windows.h>
#include "cnst.h"
void doPrintCurrentStatus(CHARACTER** players, float* nDmgProbList, int nResurection, int nDeathNum) {
	//회피 데미지 수
	int nDodge = 0;

	printf("User / Live / Life / Dmg , User / Live / Life / Dmg , User / Live / Life / Dmg , User / Live / Life / Dmg , User / Live / Life / Dmg\n");

	//결과 출력
	for (int b = 0; b < 100; b++) {

		char* heartFlag = (players[b] == NULL) ? "\u2661" : "\u2665";
		int nPlayerLife = (players[b] == NULL) ? 0 : players[b]->nLife;
		int nPlayerDamaged = (players[b] == NULL) ? 0 : players[b]->nDamage;
		int nTextColor = (players[b] == NULL) ? 0 : 3;

		//생존한 유저 중 데미지를 0 입었을 경우 노란색으로 지정
		if (nTextColor == 3) {
			switch (players[b]->nDamage) {
			case 0:
				//데미지를 회피 했을 경우.
				nTextColor = 6;
				break;
			case 10:
				//맥스데미지(크리티컬히트)가 터졌을 경우
				nTextColor = 4;
			}

		}

		//회피데미지가 발생 할 경우 카운팅
		if (players[b] != NULL) {
			if (players[b]->nDamage == 0) nDodge += 1;
		}

		//사망했을 경우 색상 변경
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), nTextColor);

		printf("%4d / %4s / %4d / %3d , ", (b + 1), heartFlag, nPlayerLife, nPlayerDamaged);
		if (b % 5 == 4) {
			printf("\n");
		}
	}

	//개행문자 추가
	printf("\n");
	//화면 글자 색상 변경
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

	//현재상황 출력
	printf("생존 캐릭터 %d명 사망 캐릭터 %d명\n", (100 - nDeathNum), nDeathNum);
	printf("부활 캐릭터 %d명\n", nResurection);
	printf("이번 공격으로 죽은 캐릭터 %d명\n", nDeathNum);
	printf("이번 공격에 공격 받지 않은 캐릭터 %d명\n", nDodge);

	//데미지별 확률 출력
	printf("데미지 별 확률 :\n");
	float rateSum = 0.0f;
	for (int z = 0; z < 11; z++) {
		printf("%2d : %6.3f%% / ", z, (nDmgProbList[z] * 100));

		rateSum = rateSum + (nDmgProbList[z] * 100);

		if (z % 5 == 0 && z != 0)
			printf("\n");
	}
	printf("\n확률 총합 %.3f%%\n", rateSum);
}