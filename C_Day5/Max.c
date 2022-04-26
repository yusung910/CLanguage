#include<stdio.h>

//전달받은 두 int 데이터를 비교해서
//최대값을 printf 한다.
void Max(int a, int b)
{
    int nMax = a > b ? a : b;
    printf("큰 수는 %d입니다.\n", nMax);
}