#include <stdlib.h> // rand() 함수
#include <conio.h>  // getch() 함수
#include <time.h>   // time() 함수
#include <stdio.h>

#pragma warning ( disable : 4996 )
//슬롯머신 게임 만들기!
void main() {
	//사용자가 입력한 반복횟수 저장 변수
	int nRepeat = 0;
	//슬롯머신 결과 3개의 숫자값이 저장될 변수.
	int nA = 7, nB = 7, nC=7;
    //유저 점수
    unsigned int nInitScore = 10;
    //슬롯머신 결과에 따라 변경될 점수를 저장하는 변수.
    int nModifyScore = 0;

	//시간 값을 이용하여 난수 세팅
	srand((unsigned)time(NULL));

    printf("[%d] [%d] [%d]\n", nA, nB, nC);

    while(1){

        printf("획득 점수 : %d\n", nModifyScore);

        printf("현재 점수 : %d\n", nInitScore);

        nModifyScore = -5;

        printf("반복 횟수를 입력하시면 게임이 시작됩니다:");
        scanf("%d", &nRepeat);

        
        if (nA != -1 && nB != -1 && nC != -1) {
            system("cls");
        }

        for (int i = 0; i < nRepeat; i++) {
            nA = rand() % 9;
            nB = rand() % 9;
            nC = rand() % 9;
            printf("\r[%d] [%d] [%d]", nA, nB, nC);
            _sleep(10*i);
        }

        printf("\n");

        //점수 3개 중 두개가 같으면 10점을 더한다.
        if (nA == nB || nB == nC || nA == nC) {
            nModifyScore = 10;
        }
        //점수 3개가 다 같으면 50점을 더한다.
        if (nA == nB && nB == nC && nA == nC) {
            nModifyScore = 50;
        }

        if (nA == 7 && nB == 7 && nC == 7) {
            nModifyScore = 1000;
        }

        nInitScore = nInitScore + nModifyScore;

        if (nInitScore == 0) {
            puts("모든 점수를 잃어버렸습니다!");
            printf("다시하시겠습니까?(Enter Key를 눌러주세요)");
            char cInputKey = _getch();
            if (cInputKey == 13) {
                system("cls");
                nInitScore = 10;
                nModifyScore = 5;
                printf("[7] [7] [7]\n");
            }else {
                break;
            }
        }
    }
}