#include<stdio.h>

void main()
{
	
	int nA = 0;
	int nB = 0;
	int nC = 0;
	int nD = 0;
	float fE = 0.0f;


	unsigned char ch1 = 'G';
	unsigned char ch2 = 'A';
	unsigned char ch3 = 'M';
	unsigned char ch4 = 'E';
	unsigned char ch5 = '\0';

	nA = 10;
	nB = 10;

	printf("���ڿ� %c�� ASCII CODE �� %d\n", ch1, ch1);
	printf("���ڿ� %c�� ASCII CODE �� %d\n", ch2, ch2);
	printf("���ڿ� %c�� ASCII CODE �� %d\n", ch3, ch3);
	printf("���ڿ� %c�� ASCII CODE �� %d\n", ch4, ch4);

	printf("���� 4���� �Է��Ͽ��ּ��� : ");
	scanf("%d %d %d %d", &nA, &nB, &nC, &nD);
	printf("�Ǽ� 1���� �Է��Ͽ��ּ��� : ");
	scanf("%f", &fE);

	
	printf("���� �ټ����� �Է��Ͽ��ּ��� : ");
	ch1 = '\0';

	//���ڿ� �Է� �� �� �տ��� �Է� ���� �Ǽ� �� ���� ������� enter �Է�����
	//scanf �տ� �������� �ʱ�ȭ �Ǵ�  getchar()�� �Է� ���۸� �ʱ�ȭ �ؾ���
	getchar();
	scanf("%c %c %c %c %c", &ch1, &ch2, &ch3, &ch4, &ch5);

	printf("%d�� 10���� : %d, 16���� : %x\n", nA, nA, nA);
	printf("%d�� 10���� : %d, 16���� : %x\n", nB, nB, nB);
	printf("%d�� 10���� : %d, 16���� : %x\n", nC, nC, nC);
	printf("%d�� 10���� : %d, 16���� : %x\n", nD, nD, nD);
	printf("%f�� 10���� : %d, 16���� : %x\n\n", fE, *(unsigned int *)&fE, *(unsigned int *)&fE);
	printf("�Ҽ��� 2�ڸ� [%5.2f]\n", fE);	// �ʵ��� 5, �Ҽ����̸� 2
	printf("�Ҽ��� 3�ڸ� [%5.3f]\n", fE);	// �ʵ��� 5, �Ҽ����̸� 3
	printf("�Ҽ��� 3�ڸ� [%.3f]\n\n", fE);	// �Ҽ����̸� 3 ( �����Ҽ���ǥ�� )	

	printf("%c�� 10���� : %d, 16���� : %x\n", ch1, ch1, ch1);
	printf("%c�� 10���� : %d, 16���� : %x\n", ch2, ch2, ch2);
	printf("%c�� 10���� : %d, 16���� : %x\n", ch3, ch3, ch3);
	printf("%c�� 10���� : %d, 16���� : %x\n", ch4, ch4, ch4);
	printf("%c�� 10���� : %d, 16���� : %x\n\n", ch5, ch5, ch5);

	printf("%020d\n", ch1);
	printf("%-50d\n\n", ch2);

	printf("[%020d]\n\n", ch4);
}