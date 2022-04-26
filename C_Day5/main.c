#include<stdio.h>
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
    scanf(" %d %d", &a, &b);
    printf("실수 두개를 입력하여주세요:");
    scanf(" %f %f", &c, &d);
    FloatSum(c, d);
    Sum(a, b);
    Min(a, b);
    Max(a, b);
}