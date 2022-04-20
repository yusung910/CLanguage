#include <stdio.h>  // scanf(), printf() 함수
#include <stdlib.h> // rand() 함수
#include <conio.h>  // getch() 함수
#include <time.h>   // time() 함수

void main()
{
	int nRd;
	int inputN = 0;

	//// 실행시 마다 다른 수를 발생시키기 위해 시간을 적용
	//// 프로그램 실행시 최초 한번만 해준다
	//프로그램이 종료되고 다시 실행해도
	//같은 메모리 주소를 잡고 있긴 때문에
	//별도의 시간 설정을 통해서 난수를 발생 시켜야한다
	srand((unsigned)time(NULL));

	//난수 % 9 는 0~9
	//끝에 +1을 해줌으로써
	//최소값과 최대값에 +1을 해준다
	//때문에 1~10까지의 난수가 생성됨
	//8 ~ 75
	//(75 - 8) + 1
	nRd = (rand() % 9) + 1;

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
	else if (nRd < inputN)
	{
		printf("%d 보다 작습니다.\n", inputN);
	}
	else
	{
		printf("정답입니다!");
	}

	printf("마지막 기회입니다, 다시 숫자를 신중히 입력하여 주세요 :");
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