#include<stdio.h>
#include "Display.h";
int nInput;

void main()
{
    printf("출력할 구구단 숫자를 입력하여주세요.");
    scanf("%d", &nInput);
    printf("마지막의 전 결과 값은 %d 입니다.", Display());
}