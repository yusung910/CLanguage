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
    printf("���� �ΰ��� �Է��Ͽ��ּ���:");
    scanf(" %d %d", &a, &b);
    printf("�Ǽ� �ΰ��� �Է��Ͽ��ּ���:");
    scanf(" %f %f", &c, &d);
    FloatSum(c, d);
    Sum(a, b);
    Min(a, b);
    Max(a, b);
}