#include <stdio.h>
#include "Display.h";
int nInput;

void main()
{
    printf("����� ������ ���ڸ� �Է��Ͽ��ּ���.");
    scanf("%d", &nInput);
    printf("%d���� ������ �� ���� %d �Դϴ�.", nInput, Display());
}