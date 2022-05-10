#include <stdio.h>
#include <stdlib.h> // rand() 함수
#include <time.h>   // time() 함수

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

    CHARACTER players[100], *player;
    int nTurn = 0;
    player = players;

    //난수 세팅
    srand((unsigned)time(NULL));

    for (int i = 0; i < 100; i++) {
        (player + i)->bIsLive = TRUE;
        (player + i)->nLife = (rand() % 51) + 50;
        (player + i)->nDamage = 0;
    }

    while (1) {
        nTurn += 1;
        printf("Turn : %d", nTurn);
        //사망자 명단 저장 배열
        int nDeathNote[100];
        //매 턴마다 발생하는 사망자 수
        int nDeathNum = 0;
        //사망자 배열 길이
        int nDeathNumLen = 0;
        //부활 유저 수
        int nResurection = 0;
        //데미지 계산
        for (int j = 0; j < 100; j++) {

            int nDmg = (rand() % 11);
            int userLife = (player + j)->nLife;
            

            (player + j)->nDamage = nDmg;
            (player + j)->nLife = userLife - nDmg;

            if ((player + j)->nLife <= 0) {
                //데미지를 입은 유저를 사망처리
                (player + j)->bIsLive = FALSE;
                nDeathNote[nDeathNum] = j;
                nDeathNum += 1;
            }
        }

        //사망자 수 에서 10%인원을 부활한다.
        nDeathNumLen = __strlen(nDeathNote);

        nResurection = nDeathNumLen / 10;

        for (int a = 0; a < nResurection; a++) {
            int nResurectionPlayer = (rand() % nDeathNumLen);
            player[nResurectionPlayer].bIsLive = TRUE;
            player[nResurectionPlayer].nLife = (rand() % 51) + 50;
            player[nResurectionPlayer].nDamage = 0;
        }
        //결과 출력
        for (int b = 0; b < 100; b++) {
            char heartFlag = (player[b].bIsLive) ? '♥' : '♡';
            printf("%d / %c / %d / %d\n", b, heartFlag, player[b].nLife, player[b].nDamage);
        }
    }
}