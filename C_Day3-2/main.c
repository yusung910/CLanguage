#include <stdio.h>
#include <stdlib.h> // rand() �Լ�
#include <conio.h>  // getch() �Լ�
#include <time.h>   // time() �Լ�

void main()
{
    int  nRandom;
	// ����� ���� �ٸ� ���� �߻���Ű�� ���� �ð��� ����
	// ���α׷� ����� ���� �ѹ��� ���ش�
	srand((unsigned)time(NULL));

    printf(">> ����Ű�� ������ ������ �߻��մϴ� ( 0 ~ 7 ) << ");

    char c = _getch();

    printf("\n");
    //����Ű�� ������ �����. �׿ܿ� ������� �ʴ´�.
    if(c == 13)
	{
        //// ������ �������� 0~7������ ������ �߻�
        nRandom = rand() % 8;

        if (nRandom == 0)
            puts("������ 0�Դϴ�");
        else if (nRandom == 1)
            puts("������ 1�Դϴ�");
        else if (nRandom == 2)
            puts("������ 2�Դϴ�");
        else if (nRandom == 3)
            puts("������ 3�Դϴ�");
        else if (nRandom >= 4 && nRandom <= 5)
            puts("������ 4 ~ 5�Դϴ�");
        else
            puts("������ 6 ~ 7�Դϴ�");
	}
	else 
	{
		puts("����Ű�� �����ּ���.");
	}
}