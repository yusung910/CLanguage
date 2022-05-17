#include <stdio.h>
#include <stdlib.h> // rand() 함수
#include <time.h>   // time() 함수
#include <malloc.h>
#include <windows.h>

#include "cnst.h"
#include "initUser.h"
#include "setDmgToUser.h"
#include "setDmgProb.h"
#include "getDeathUserCnt.h"
#include "setResurrectionChar.h"


void main() {
    //플레이어 배열
    CHARACTER* players[100];
    //사망 플레이어를 저장하기위한 배열
	int* nDeathNote;
    //플레이어 턴 수
    int nTurn = 0;
    //데미지 확률
    float nDmgProbList[11];

    //난수 세팅
    srand((unsigned)time(NULL));

    //캐릭터 초기 세팅한다.
	initUser(players);		

    printf("Enter Key(시작), Esc 키(종료)\n");
    while (1) {
        int inputKeyVal = getch();
        if (inputKeyVal == 13) {
            system("cls");
            printf("Enter Key를 눌러 Turn을 진행시켜주세요, Esc키를 누를 경우 게임이 종료됩니다.\n");
            nTurn += 1;
            printf("Turn : %d\n", nTurn);

            //매 턴마다 발생하는 사망자 수
            int nDeathNum = 0;
            //부활 유저 수
            int nResurection = 0;
            //회피 데미지 수
            int nDodge = 0;

			//데미지별 확률을 세팅한다.
			setDmgProb(nDmgProbList, nTurn);

			//캐릭터에게 데미지를 가한다.
			setDmgToUser(players, nDmgProbList);

            //사망 캐릭터 수를 가져온다.
            nDeathNum = getDeathUserCnt(players);

			//사망한 캐릭터가 있을 경우 부활 캐릭터를 작업한다.
			if (nDeathNum > 0) {
				//사망자 수 에서 10% 인원을 부활한다.
				nResurection = setResurrectionChar(players, nDeathNum);
			}

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

            //사망한 플레이어의 목록이 저장된 데이터 배열을 해제한다,
            //배열을 메모리에서 해재함으로 써 기존의 데이터를 초기화한다.

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
            printf("\n확률 총합 %.3f%%", rateSum);
        }
        else if (inputKeyVal == 27) {
            puts("game 종료!");
            break;
        }

    }
}