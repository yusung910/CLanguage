#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
                int nBeforeDmg = 0;
                int nBeforeLife = 0;
                int nAfDmg = 0;
                int nAfLife = 0;
                int nR = 0;
                int loadTurn = 0;
                for (int i = 0; i < 100; i++) {
                    fseek(in, (4 * i), SEEK_SET);
                    fread(&nBeforeDmg, 1, sizeof(int), in);
                    fseek(in, 400 + (4 *i), SEEK_SET);
                    fread(&nBeforeLife, 1, sizeof(int), in);

                    nAfDmg = nBeforeDmg - 100;
                    nAfLife = nBeforeLife - 100;
                    if (nAfDmg == 0 && nAfLife == 0) {
                        players[i] = NULL;
                    } else {
                        players[i] = (CHARACTER*)malloc(sizeof(CHARACTER));
                        players[i]->nLife = nAfLife;
                        players[i]->nDamage = nAfDmg;
                        nR += 1;
                    }
                }

                //턴수 저장
                fseek(in, -4, SEEK_END);
                fread(&loadTurn, 1, sizeof(int), in);
                nTurn = loadTurn - 100;

                //데미지별 확률을 세팅한다.
                setDmgProb(nDmgProbList, nTurn);
                printf("Turn : %d\n", nTurn);

                doPrintCurrentStatus(players, nDmgProbList, nR, (100- nR));
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
		fclose(in);
    }else {
        initUser(players);
    }
    

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

            int saveDmg[100];
            int saveLife[100];
            int saveTurn = nTurn + 100;
			for (int i = 0; i < 100; i++) {
                //캐릭터가 살아 있을 경우에 변수 값을 할당.
                if (players[i] != NULL) {
                    saveDmg[i] = players[i]->nDamage + 100;
                    saveLife[i] = players[i]->nLife + 100;
                }else{
                    saveDmg[i] = 100;
                    saveLife[i] = 100;
                }
			}
            fwrite(saveDmg, 1, sizeof(saveDmg), out);
            fwrite(saveLife, 1, sizeof(saveLife), out);
            fwrite(&saveTurn, 1, sizeof(saveTurn), out);
            
            fclose(out);

            puts("game 종료!");
            break;
        }
    }
}