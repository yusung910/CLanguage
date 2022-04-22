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
	int nA, nB, nC;

	//시간 값을 이용하여 난수 세팅
	srand((unsigned)time(NULL));
	
	puts("----슬롯머신----");
	printf("반복 횟수를 입력하시면 게임이 시작됩니다:");
	scanf("%d", &nRepeat);
	while(1) {
		nA = (rand() % 9) + 1;
		nB = (rand() % 9) + 1;
		nC = (rand() % 9) + 1;
		printf("\r[%d] [%d] [%d]", nA, nB, nC);
		_sleep(100);
	}
}