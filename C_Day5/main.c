#include <stdio.h>
#include "FloatSum.h"
#include "Sum.h"
#include "Min.h"
#include "Max.h"

void main()
{
    int a = 0;
    int b = 0;
    float c = 0;
    float d = 0;
    printf("정수 두개를 입력하여주세요:");
    scanf("%d %d", &a, &b);
    printf("실수 두개를 입력하여주세요:");
    scanf("%f %f", &c, &d);
	printf("두 실수의 합은 %10.2f입니다.\n", FloatSum(c, d));
	printf("두 정수의 합은 %d입니다.\n", Sum(a, b));
	printf("두 정수 중 작은 숫자는 %d입니다.\n", Min(a, b));
	printf("두 정수 중 큰 숫자는 %d입니다.", Max(a, b));
}