#include <stdio.h>
#include <stdlib.h> // rand() 함수
#include <time.h>   // time() 함수
#include <malloc.h>

#include "cnst.h"
#include "doPrintCurrentStatus.h"
#include "getDeathUserCnt.h"
#include "initUser.h"
#include "setDmgToUser.h"
#include "setDmgProb.h"
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

    //세이브파일 검사
    FILE *in;
    in = fopen("save.bin", "rb");
    if (in != NULL) {
        char answer = '\0';
        while (1) {
            printf("기존 세이브 파일이 존재합니다. 불러오겠습니까?(Y,N) : ");
            scanf("%c", &answer);
            if (answer == 'Y' || answer == 'y') {
                for (int i = 0; i < 100; i++) {
                    players[i] = (CHARACTER*)malloc(sizeof(CHARACTER));
                    fseek(in, i * sizeof(CHARACTER), SEEK_CUR);
                    fread(players[i], 1, sizeof(CHARACTER), in);
                }
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
    }else {
        initUser(players);
    }
    fclose(in);

    printf("Enter Key(시작), Esc 키(종료)\n");
    while (1) {
        int inputKeyVal = getch();
        if (inputKeyVal == 13) {
            system("cls");
            printf("Enter Key를 눌러 Turn을 진행시켜주세요, Esc키를 누를 경우 게임이 종료됩니다.\n");
            nTurn += 1;
            printf("Turn : %d\n", nTurn);

			//부활 캐릭터 수
			int nResurection = 0;
			//사망 캐릭터 수
			int nDeathNum = 0;
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

			//현재 상황을 출력한다.
			doPrintCurrentStatus(players, nDmgProbList, nResurection, nDeathNum);
        }else if (inputKeyVal == 27) {
            //게임 종료시 마지막 정보를 save.bin에 저장
            FILE *out;
            out = fopen("save.bin", "wb");

            //플레이어 정보 저장
            fwrite(players, 1, sizeof(players), out);

            //현재 턴 정보 저장
            //fwrite(&nTurn, 1, sizeof(nTurn), out);

            //파일 연결 종료
            fclose(out);
            puts("game 종료!");
            break;
        }

    }
}