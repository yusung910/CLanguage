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
    printf("���� �ΰ��� �Է��Ͽ��ּ���:");
    scanf("%d %d", &a, &b);
    printf("�Ǽ� �ΰ��� �Է��Ͽ��ּ���:");
    scanf("%f %f", &c, &d);
	printf("�� �Ǽ��� ���� %10.2f�Դϴ�.\n", FloatSum(c, d));
	printf("�� ������ ���� %d�Դϴ�.\n", Sum(a, b));
	printf("�� ���� �� ���� ���ڴ� %d�Դϴ�.\n", Min(a, b));
	printf("�� ���� �� ū ���ڴ� %d�Դϴ�.", Max(a, b));
}