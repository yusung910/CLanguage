#include <stdio.h>
#include "Display.h";
int nInput;

void main()
{
    printf("출력할 구구단 숫자를 입력하여주세요.");
    scanf("%d", &nInput);
    printf("%d단의 마지막 전 값은 %d 입니다.", nInput, Display());
}