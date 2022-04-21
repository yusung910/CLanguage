#include <stdio.h>
#include <stdlib.h> // rand() 함수
#include <conio.h>  // getch() 함수
#include <time.h>   // time() 함수

void main()
{
    int  nRandom;
	// 실행시 마다 다른 수를 발생시키기 위해 시간을 적용
	// 프로그램 실행시 최초 한번만 해준다
	srand((unsigned)time(NULL));

    printf(">> 엔터키를 누르면 난수가 발생합니다 ( 0 ~ 7 ) << ");

    char c = _getch();

    printf("\n");
    //엔터키를 눌러야 실행됨. 그외엔 실행되지 않는다.
    if(c == 13)
	{
        //// 나머지 연산으로 0~7까지의 난수를 발생
        nRandom = rand() % 8;

        if (nRandom == 0)
            puts("난수는 0입니다");
        else if (nRandom == 1)
            puts("난수는 1입니다");
        else if (nRandom == 2)
            puts("난수는 2입니다");
        else if (nRandom == 3)
            puts("난수는 3입니다");
        else if (nRandom >= 4 && nRandom <= 5)
            puts("난수는 4 ~ 5입니다");
        else
            puts("난수는 6 ~ 7입니다");
	}
	else 
	{
		puts("엔터키를 눌러주세요.");
	}
}