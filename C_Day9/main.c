#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>

#include "cnst.h"
#include "doPrintCurrentStatus.h"
#include "doLoadData.h"
#include "doSaveData.h"
#include "getDeathUserCnt.h"
#include "initUser.h"
#include "setDmgToUser.h"
#include "setDmgProb.h"
#include "setResurrectionChar.h"

void main() {
    //플레이어 배열
    CHARACTER* players[100];
    //플레이어 턴 수
    int nTurn = 0;
    //데미지 확률
    float nDmgProbList[11];
	//데미지별 확률 초기 세팅
	for (int o = 0; o < 11; o++) {
		nDmgProbList[o] = (float)1 / 11;
	}
    //부활 캐릭터 수
    int nResurection = 0;
    //사망 캐릭터 수
    int nDeathNum = 0;

    //난수 세팅
    srand((unsigned)time(NULL));

    //세이브파일 검사
	doLoadData(players, nDmgProbList, &nTurn, &nResurection);
    
    printf("Enter Key(시작), Esc 키(종료)\n");

    while (1) {
        int inputKeyVal = getch();
        if (inputKeyVal == 13) {
            system("cls");
            printf("Enter Key를 눌러 Turn을 진행시켜주세요, Esc키를 누를 경우 게임이 종료됩니다.\n");
            nTurn += 1;
            printf("Turn : %d\n", nTurn);


			//데미지별 확률을 세팅한다.
			setDmgProb(nDmgProbList, &nTurn);

			//캐릭터에게 데미지를 가한다.
			setDmgToUser(players, nDmgProbList);

			//사망 캐릭터 수를 가져온다.
			nDeathNum = getDeathUserCnt(players);

			//사망한 캐릭터가 있을 경우 부활 캐릭터를 작업한다.
			if (nDeathNum > 0) {
				//사망자 수 에서 10% 인원을 부활한다.
				nResurection = setResurrectionChar(players, nDeathNum);
			}

			//현재 상황을 출력한다.
			doPrintCurrentStatus(players, nDmgProbList, nResurection, nDeathNum);
        }else if (inputKeyVal == 27) {
			//저장 작업을 진행한다
			if (doSaveData(players, &nTurn, &nResurection)) {
				break;
			}
        }
    }
}