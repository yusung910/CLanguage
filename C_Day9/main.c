#include <stdio.h>
#include <stdlib.h> // rand() 함수
#include <time.h>   // time() 함수
#include <malloc.h>
#include <windows.h>

#include "characterStruct.h"
#include "initCharacter.h"
#include "revivalChar.h"
#include "setDmgProb.h"

#define TRUE	1
#define FALSE	0


//8일차 과제에서
//9일차 과제를 적용하기 위한 프로젝트
void main() {

	//플레이어 배열
	CHARACTER* players[100];

	//플레이어 턴 수
	int nTurn = 0;

	//데미지 확률
	float nDmgProbList[11];

	//부활 캐릭터 수
	int nResurection = 0;

	//사망자 수
	int nDeathNum = 0;

	//현재 턴에 발생한 사망자 수
	int nNowturnDeath = 0;

	//난수 세팅
	srand((unsigned)time(NULL));

	//100개의 캐릭터 초기화
	initCharacter(players, 100);

	//데미지 확률 세팅
	setDmgProb(nDmgProbList, nTurn);

	printf("Enter Key(시작), Esc 키(종료)\n");
	while (1) {
		int inputKeyVal = getch();

		//현재 턴 사망자 초기화
		nNowturnDeath = 0;
		//사망자 수 초기화
		nDeathNum = 0;

		if (inputKeyVal == 13) {
			system("cls");
			printf("Enter Key를 눌러 Turn을 진행시켜주세요, Esc키를 누를 경우 게임이 종료됩니다.\n");
			nTurn += 1;
			printf("Turn : %d\n", nTurn);

			//회피 데미지 수
			int nDodge = 0;

			//확률 세팅
			setDmgProb(nDmgProbList, nTurn);

			//데미지 계산
			for (int j = 0; j < 100; j++) {
				if (players[j] != NULL) {
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
						nNowturnDeath += 1;
						free(players[j]);
						players[j] = NULL;
					}
				}
			}

			//사망자 수 에서 10% 인원을 부활한다.
			//사망자를 카운팅한다.
			for (int a = 0; a < 100; a++) {
				if (players[a] == NULL) {
					nDeathNum += 1;
				}
			}

			//죽은 캐릭터 부활 처리
			nResurection = revivalChar(players, nDeathNum);

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
			printf("이번 공격으로 죽은 캐릭터 %d명\n", nNowturnDeath);
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
			printf("\n확률 총합 %.3f%%", rateSum);
		}
		else if (inputKeyVal == 27) {
			puts("game 종료!");
			break;
		}

	}
}