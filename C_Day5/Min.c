#include<stdio.h>

//���޹��� �� int �����͸� ���ؼ�
//�ִ밪�� printf �Ѵ�.
void Min(int a, int b)
{
    int nMin = a < b ? a : b;
    printf("���� ���� %d�Դϴ�.\n", nMin);
}