#include <stdlib.h> // rand() �Լ�
#include <conio.h>  // getch() �Լ�
#include <time.h>   // time() �Լ�
#include <stdio.h>

#pragma warning ( disable : 4996 )
//���Ըӽ� ���� �����!
void main() {
	//����ڰ� �Է��� �ݺ�Ƚ�� ���� ����
	int nRepeat = 0;
	//���Ըӽ� ��� 3���� ���ڰ��� ����� ����.
	int nA, nB, nC;

	//�ð� ���� �̿��Ͽ� ���� ����
	srand((unsigned)time(NULL));
	
	puts("----���Ըӽ�----");
	printf("�ݺ� Ƚ���� �Է��Ͻø� ������ ���۵˴ϴ�:");
	scanf("%d", &nRepeat);
	while(1) {
		nA = (rand() % 9) + 1;
		nB = (rand() % 9) + 1;
		nC = (rand() % 9) + 1;
		printf("\r[%d] [%d] [%d]", nA, nB, nC);
		_sleep(100);
	}
}