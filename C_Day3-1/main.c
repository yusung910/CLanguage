#include <stdio.h>
#include <stdlib.h> // rand() �Լ�
#include <conio.h>  // getch() �Լ�
#include <time.h>   // time() �Լ�

void main()
{
	int nRd;
	int inputN = 0;
	int inputCnt = 0;

	//// ����� ���� �ٸ� ���� �߻���Ű�� ���� �ð��� ����
	//// ���α׷� ����� ���� �ѹ��� ���ش�
	//���α׷��� ����ǰ� �ٽ� �����ص�
	//���� �޸� �ּҸ� ��� �ֱ� ������
	//������ �ð� ������ ���ؼ� ������ �߻� ���Ѿ��Ѵ�
	srand((unsigned)time(NULL));

	//���� % 9 �� 0~9
	//���� +1�� �������ν�
	//�ּҰ��� �ִ밪�� +1�� ���ش�
	//������ 1~10������ ������ ������
	nRd = (rand() % 9) + 1;

	puts("1���� 10���� ���ڰ� ������ ���ڰ� �����˴ϴ�.");
	puts("������ ������ ���ڸ� ���纸����!");
	puts("��ȸ�� �ι�, �Է��Ͻ� ���ڿ� ������ ���ڰ� ���� ���� ���");
	puts("�� ����� �˷��帳�ϴ�.");

	printf("���ڸ� �Է��Ͽ� �ּ��� :");
	scanf("%d", &inputN);

	if (nRd > inputN)
	{
		printf("%d ���� Ů�ϴ�.\n", inputN);
	}
	else if (nRd < inputN) {
		printf("%d ���� �۽��ϴ�.\n", inputN);
	}
	else
	{
		printf("�����Դϴ�!");
	}

	printf("�ٽ� ���ڸ� �Է��Ͽ� �ּ��� :");
	scanf("%d", &inputN);
	if (nRd == inputN)
	{
		printf("�����Դϴ�!");
	}
	else
	{
		printf("Ʋ�Ƚ��ϴ�, �����Ǽ��� %d �Դϴ�!", nRd);
	}

}