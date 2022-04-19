#include <stdio.h>

void main()
{
    //sizeof();
    //������ ���� �ִ� ������ ũ���� ���� �˷���

	//���� 1-1��
	int iArry[4] = { 0, 1, 8, 2 };
	float fArry[4] = { 1.12f, 3.12f, 2.241f, 1.112f };
	char chrArry[] = { 'G', 'A', 'M', 'E'};

    //���� Ÿ�� �� �迭 ������ ���
    printf("char sizeof %d\n", sizeof(char));
    printf("int sizeof %d\n", sizeof(int));
    printf("float sizeof %d\n", sizeof(float));
    printf("long sizeof %d\n", sizeof(long));
    printf("chrArry[] sizeof %d\n", sizeof(chrArry));


	printf("���� 1�� ��� ��� : %.2f %.2f %.3f %.3f\n", fArry[0], fArry[1], fArry[2], fArry[3]);
	printf("���� 1�� ��� ��� : %c %c %c %c\n", chrArry[0], chrArry[1], chrArry[2], chrArry[3]);

	//���� 1-2��
	int iChr[4] = { 'D', 'E', 'A', 'E' };
	float fChr[4] = { 'C', 'F', 'O', 'P' };

	printf("���� 2-1�� ��� ��� : %d %d %d %d\n", iChr[0], iChr[1], iChr[2], iChr[3]);
	printf("���� 2-2�� ��� ��� : %2.1f %2.1f %1.1f %1.5f\n", fChr[0], fChr[1], fChr[2], fChr[3]);

	//���� 1-3��
	char string[] = { 'C', 'L', 'A', 'N', 'G', 'U', 'A', 'G', 'E' };
	printf("���� 3�� ��� ��� : %c %c %c %c %c %c %c %c %c\n", string[0], string[1], string[2], string[3], string[4], string[5], string[6], string[7], string[8]);

	//���� 2-1��
	int a, b, c, e, f;

	a = 0;
	b = 5;
	c = 10;

	//���� c�� b�� ��
	//���� c�� b ũ�� ������(��) b * ++c - 10 * 2�� ����
	// -10 * 2
    // b * ++c
	// b * (c = c + 1)
	// 5 * 11
	// 55 - 20
	// e = 35
	e = c > b ? b * ++c - 10 * 2 : c-- * b + 10 * 2;

	//���� 10�� ���� c�� ��
	//10 == 11��ġ���� �ʱ� ������(����) c-- * b + 10 * 2 ����
	//c * b + 10 * 2
    //c = c - 1
	//11 * 5 + 10 * 2
	//f = 55 + 20
	//f = 75
    //c = 10
	f = 10 == c ? b * ++c - 10 * 2 : c-- * b + 10 * 2;

	printf("e= %d\n", e);
	printf("f= %d\n", f);



	//���� 2-2
	int nOP1[4], nOP2[4];
	float fOP1[4], fOP2[4];

	printf("������ �Է��Ͽ��ּ��� : ");
	scanf("%d", &nOP1[0]);
	printf("������ �Է��Ͽ��ּ��� : ");
	scanf(" %d", &nOP1[1]);
	printf("������ �Է��Ͽ��ּ��� : ");
	scanf(" %d", &nOP1[2]);
	printf("������ �Է��Ͽ��ּ��� : ");
	scanf(" %d", &nOP1[3]);

	printf("������ �Է��Ͽ��ּ��� : ");
	scanf("%d", &nOP2[0]);
	printf("������ �Է��Ͽ��ּ��� : ");
	scanf(" %d", &nOP2[1]);
	printf("������ �Է��Ͽ��ּ��� : ");
	scanf(" %d", &nOP2[2]);
	printf("������ �Է��Ͽ��ּ��� : ");
	scanf(" %d", &nOP2[3]);

	printf("�ε��� ����(�Ǽ�)�� �Է��Ͽ��ּ��� : ");
	scanf("%f", &fOP1[0]);
	printf("�ε��� ����(�Ǽ�)�� �Է��Ͽ��ּ��� : ");
	scanf(" %f", &fOP1[1]);
	printf("�ε��� ����(�Ǽ�)�� �Է��Ͽ��ּ��� : ");
	scanf(" %f", &fOP1[2]);
	printf("�ε��� ����(�Ǽ�)�� �Է��Ͽ��ּ��� : ");
	scanf(" %f", &fOP1[3]);

	printf("�ε��� ����(�Ǽ�)�� �Է��Ͽ��ּ��� : ");
	scanf("%f", &fOP2[0]);
	printf("�ε��� ����(�Ǽ�)�� �Է��Ͽ��ּ��� : ");
	scanf(" %f", &fOP2[1]);
	printf("�ε��� ����(�Ǽ�)�� �Է��Ͽ��ּ��� : ");
	scanf(" %f", &fOP2[2]);
	printf("�ε��� ����(�Ǽ�)�� �Է��Ͽ��ּ��� : ");
	scanf(" %f", &fOP2[3]);

	//���� �迭 ��Ģ���� ��� ���� �迭
	int rsltIOPArry[4];
	//�ε��� ����(�Ǽ�) ��Ģ���� ��� �迭
	int rsltFOPArry[4];

	//���� �迭 ��Ģ���� ��� ����
	rsltIOPArry[0] = nOP1[0] + nOP2[0];
	rsltIOPArry[1] = nOP1[1] + nOP2[1];
	rsltIOPArry[2] = nOP1[2] + nOP2[2];
	rsltIOPArry[3] = nOP1[3] + nOP2[3];

	//�ε��� ����(�Ǽ�) �迭 ��Ģ���� ��� ����(ĳ����)
	rsltFOPArry[0] = (int)fOP1[0] + (int)fOP2[0];
	rsltFOPArry[1] = (int)fOP1[1] + (int)fOP2[1];
	rsltFOPArry[2] = (int)fOP1[2] + (int)fOP2[2];
	rsltFOPArry[3] = (int)fOP1[3] + (int)fOP2[3];

	//��Ģ���� ��� ���
	printf("%d + %d = %d\n", nOP1[0], nOP2[0], rsltIOPArry[0]);
	printf("%d + %d = %d\n", nOP1[1], nOP2[1], rsltIOPArry[1]);
	printf("%d + %d = %d\n", nOP1[2], nOP2[2], rsltIOPArry[2]);
	printf("%d + %d = %d\n", nOP1[3], nOP2[3], rsltIOPArry[3]);

	printf("%f + %f = %d\n", fOP1[0], fOP2[0], rsltFOPArry[0]);
	printf("%f + %f = %d\n", fOP1[1], fOP2[1], rsltFOPArry[1]);
	printf("%f + %f = %d\n", fOP1[2], fOP2[2], rsltFOPArry[2]);
	printf("%f + %f = %d", fOP1[3], fOP2[3], rsltFOPArry[3]);
}