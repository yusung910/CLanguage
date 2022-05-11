#include <stdio.h>
#include <stdlib.h> // rand() 함수
#include <time.h>   // time() 함수
#include <malloc.h>

#include "__strlen.h"

#define TRUE	1
#define FALSE	0

typedef int	BOOL;

typedef struct
{
    BOOL bIsLive;  // 생존 여부
    int	nDamage;      // 공격 받은 정도
    int	nLife;        // 생명
} CHARACTER;

void main() {

    CHARACTER* players[100];
    int* nDeathNote;
    int nTurn = 0;

    //난수 세팅
    srand((unsigned)time(NULL));

    for (int i = 0; i < 100; i++) {
		players[i] = (CHARACTER*) malloc(sizeof(CHARACTER));
		players[i]->nLife = (rand() % 51) + 50;
		players[i]->nDamage = 0;
    }
	
    while (1) {
		printf("\rEnter Key를 눌러 Turn을 진행시켜주세요.\n");
		if(getch() == 13){
            system("cls");
			nTurn += 1;
			printf("Turn : %d\n", nTurn);
			//사망자 명단 저장 배열
			
			//매 턴마다 발생하는 사망자 수
			int nDeathNum = 0;
			//부활 유저 수
			int nResurection = 0;
			//회피 데미지 수
			int nDodge = 0;
			//데미지 계산
			for (int j = 0; j < 100; j++) {
				if (players[j] != NULL) {
					int nDmg = (rand() % 11);
					int userLife = players[j]->nLife;

					players[j]->nDamage = nDmg;
					players[j]->nLife = userLife - nDmg;

					if (nDmg == 0) {
						nDodge += 1;
					}

                    if (players[j]->nLife <= 0) {
                        //데미지를 입은 유저를 사망처리
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

            nDeathNote = (int*)malloc((nDeathNum+1) * sizeof(int));
            int nDeathNoteArry = 0;
            for (int f = 0; f < 100; f++) {
                if (players[f] == NULL) {
                    nDeathNote[nDeathNoteArry] = f;
                    nDeathNoteArry += 1;
                }
            }

            nResurection = nDeathNum / 10;
            //사망자 중 10퍼센트 부활 한다.
            for (int c = 0; c < nResurection; c++) {

                int nPlayer = rand() % nDeathNoteArry;
                players[nDeathNote[nPlayer]] = (CHARACTER*)malloc(sizeof(CHARACTER));
                players[nDeathNote[nPlayer]]->nLife = (rand() % 51) + 50;
                players[nDeathNote[nPlayer]]->nDamage = 0;
            }

			//결과 출력
			int nSurrival = 0;
			int nDieUser = 0;

			for (int b = 0; b < 100; b++) {

				char* heartFlag = (players[b] == NULL) ? "\u2665" : "\u2661";
                int nPlayerLife = (players[b] == NULL) ? 0 : players[b]->nLife;
                int nPlayerDamaged = (players[b] == NULL) ? 0 : players[b]->nDamage;
				if (players[b] == NULL) {
					nSurrival += 1;
				}else {
					nDieUser += 1;
				}
				printf("%3d / %s / %3d / %3d , ", b, heartFlag, nPlayerLife, nPlayerDamaged);
				if (b % 5 == 4) {
					printf("\n");
				}
			}

            free(nDeathNote);

			printf("\n");
			printf("\r생존 캐릭터 %d명 사망 캐릭터 %d명\n", nSurrival, nDieUser);
			printf("\r부활 캐릭터 %d명\n", nResurection);
			printf("\r이번 공격으로 죽은 캐릭터 %d명\n", nDeathNum);
			printf("\r이번 공격에 공격 받지 않은 캐릭터 %d명\n", nDodge);
		}else {
			puts("game 종료!");
			break;
		}

    }
}