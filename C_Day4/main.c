#include<stdio.h>

void main(){

	//������ ��� ����

	//�޴� ��ȣ ���� ����
	int nUserDat = 0;
	//����� ������ ����
	int nOutNum = 0;

	while (1) {

		puts("���Ͻô� �޴��� �Է��ϼ���.");
		printf("1. ������ ��� ���, 2. ���ϴ� ������ ���. 3. ���� : ");
		scanf("%d", &nUserDat);

		switch (nUserDat) {
		case 1:
			//�ݺ��� ��ø ����
			for (int i = 1; i <= 9; i++) {
				for (int j = 2; j <= 9; j++) {
					printf("%d X %d = %d  ", j, i, i*j);
				}
				printf("\n");
			}
			break;
		case 2:
			printf("���Ͻô� ������ ���ڸ� �Է��Ͽ��ּ��� :");
			scanf("%d", &nOutNum);
			for (int a = 1; a <= 9; a++) {
				printf("%d X %d = %d\n", nOutNum, a, a*nOutNum);
			}
			break;
		case 3:
			goto END;
		}
	}

END:
	puts("���α׷� ����!");
}