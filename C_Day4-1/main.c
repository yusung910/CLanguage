#include<stdio.h>
#include <stdlib.h> // rand() 함수
#include <conio.h>  // getch() 함수
#include <time.h>   // time() 함수

void main() {
	//난수 저장 변수
	int nRd;
	//사용자가 입력할 값 저장 변수
	int inputN = 0;
	//게임 진행 횟수 누적 카운트
	int nCount = 0;
	//사용자 점수
	int nScore = 0;
	//게임 플레이 여부
	int nFlag = 0;

	//시간 값을 이용하여 난수 세팅
	srand((unsigned)time(NULL));

	//난수 생성
	nRd = (rand() % 9) + 1;

	puts("1부터 10까지 숫자가 임의의 숫자가 생성됩니다.");
	puts("생성된 임의의 숫자를 맞춰보세요!");
	puts("기회는 3번, 입력하신 숫자와 임의의 숫자가 맞지 않을 경우");
	puts("비교 결과를 알려드립니다.");

	while (1) {
		printf("현재 점수 : %d\n", nScore);
		printf("숫자를 입력하여 주세요 :");
		scanf(" %d", &inputN);

		++nCount;

		if (nRd == inputN  || nCount == 3){
			if (nRd == inputN) {
				//맞출 경우 10점을 더한다.
				nScore += 10;
				puts("정답입니다!");
			}else {
				printf("틀렸습니다, 임의의 수는 %d 입니다!\n", nRd);
			}

			printf("현재 점수 : %d\n", nScore);
			printf("계속 하시겠습니까?(다시: 엔터키, 종료: ESC키)\n ");
			int nUserInputKey = _getch();

			if (nUserInputKey == 13) {
				nRd = (rand() % 9) + 1;
				nCount = 0;
			}else if(nUserInputKey == 27) {
				puts("게임이 종료됩니다.");
				break;
			}
		}else if (nRd > inputN){
			printf("%d 보다 큽니다.\n", inputN);
		}else if (nRd < inputN){
			printf("%d 보다 작습니다.\n", inputN);
		}
	}
}