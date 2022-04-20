#include <stdio.h>
#include <stdlib.h> // rand() 함수
#include <conio.h>  // getch() 함수
#include <time.h>   // time() 함수

void main()
{
	int nRd;
	int inputN = 0;
	int inputCnt = 0;

	//// 실행시 마다 다른 수를 발생시키기 위해 시간을 적용
	//// 프로그램 실행시 최초 한번만 해준다
	srand((unsigned)time(NULL));

	nRd = rand() % 10;

	puts("1부터 10까지 숫자가 임의의 숫자가 생성됩니다.");
	puts("생성된 임의의 숫자를 맞춰보세요!");
	puts("기회는 두번, 입력하신 숫자와 임의의 숫자가 맞지 않을 경우");
	puts("비교 결과를 알려드립니다.");

	printf("숫자를 입력하여 주세요 :");
	scanf("%d", &inputN);

	if (nRd > inputN)
	{
		printf("%d 보다 큽니다.\n", inputN);
	}
	else if (nRd < inputN) {
		printf("%d 보다 작습니다.\n", inputN);
	}
	else
	{
		printf("정답입니다!");
	}

	printf("다시 숫자를 입력하여 주세요 :");
	scanf("%d", &inputN);
	if (nRd == inputN)
	{
		printf("정답입니다!");
	}
	else
	{
		printf("틀렸습니다, 임의의수는 %d 입니다!", nRd);
	}

}