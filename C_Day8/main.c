#include <stdio.h>
#include <stdlib.h> // rand() 함수
#include <time.h>   // time() 함수
#include <malloc.h>
#include <windows.h>

#define TRUE	1
#define FALSE	0

//typedef int	BOOL;

typedef struct
{
//    BOOL bIsLive;  // 생존 여부
    int	nDamage;      // 공격 받은 정도
    int	nLife;        // 생명
} CHARACTER;

void main() {
    //플레이어 배열
    CHARACTER* players[100];
    //사망 플레이어를 저장하기위한 배열
    int* nDeathNote;
    //플레이어 턴 수
    int nTurn = 0;
    //데미지 확률
    float nDmgProbList[] = { 0.05, 0.05, 0.05, 0.11, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.14 };

    //난수 세팅
    srand((unsigned)time(NULL));

    for (int i = 0; i < 100; i++) {
		players[i] = (CHARACTER*) malloc(sizeof(CHARACTER));
		players[i]->nLife = (rand() % 51) + 50;
		players[i]->nDamage = 0;
    }
	printf("Enter Key(시작), Esc 키(종료)\n");
    while (1) {
		int inputKeyVal = getch();
		if(inputKeyVal == 13){
            system("cls");
			printf("Enter Key를 눌러 Turn을 진행시켜주세요, Esc키를 누를 경우 게임이 종료됩니다.\n");
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
                    //모든 player들에게 임의의 데미지를 부여한다.
					//매 턴이 반복될 수록 높은 데미지를 입을 수 있도록 난이도를 상향 평준화 한다.
					int nFlagDmg = (rand() % 100);

					
					int nDmg = 0;
                    int nBegin = 0;
                    int nEnd = 0;

					for (int i = 0; i < 11; i++) {
						//0: 0<= a < 5, 0.05
						//1: 5<= a < 10, 0.05
						//2: 10<= a < 15, 0.2
						//3: 30<= a < 40, 0.1
						//4: 40<= a < 50, 0.1
						//5: 50<= a < 60, 0.1
                        int nProb = nDmgProbList[i] * 100;
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
            //매 턴 마다 발생한 사망자의 수 만큼 동적 배열을 생성
            //동적 배열을 이용하여 생성 한 이유는
            //기존에 저장된 사망자 명단을 한번 초기화 해줘야 할 필요가 있기 때문.
            //기존의 배열(int d[100])을 이용하여 생성 할 경우
            //기존에 죽은 유저가 남아 있음
            //죽은 유저는 얼마든지 부활 할 수 있기 때문에
            //매 turn마다 사망자 목록을 초기화 해야함.
            nDeathNote = (int*)malloc((nDeathNum+1) * sizeof(int));
            //생성된 배열에 사망자를 저장한다.
            int nDeathNoteArry = 0;
            for (int f = 0; f < 100; f++) {
                if (players[f] == NULL) {
                    nDeathNote[nDeathNoteArry] = f;
                    nDeathNoteArry += 1;
                }
            }
            //사망자 중 10퍼센트 부활 한다.
            nResurection = nDeathNum / 10;
            //부활 시킬 대상자 수 만큼 반복문을 실행.            
            for (int c = 0; c < nResurection; c++) {
                //0부터 사망한 인원 수 사이의 임의의 수를 생성
                int nPlayer = rand() % nDeathNoteArry;
                //임의의 수에 저장된 유저 인덱스에 character 구조체를 동적으로 다시 생성한다.
                players[nDeathNote[nPlayer]] = (CHARACTER*)malloc(sizeof(CHARACTER));
                players[nDeathNote[nPlayer]]->nLife = (rand() % 51) + 50;
                players[nDeathNote[nPlayer]]->nDamage = 0;
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
				if (players[b] != NULL ){
					if(players[b]->nDamage == 0) nDodge += 1;
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
            free(nDeathNote);

			printf("\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("\r생존 캐릭터 %d명 사망 캐릭터 %d명\n", (100- nDeathNoteArry), nDeathNoteArry);
			printf("\r부활 캐릭터 %d명\n", nResurection);
			printf("\r이번 공격으로 죽은 캐릭터 %d명\n", nDeathNum);
			printf("\r이번 공격에 공격 받지 않은 캐릭터 %d명\n", nDodge);
		}else if(inputKeyVal == 27){
			puts("game 종료!");
			break;
		}

    }
}