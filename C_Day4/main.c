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

        //������ ���۰�
        int nStart = 2;
        //������ ���ᰪ
        int nEnd = 0;

		switch (nUserDat) {
		case 1:
            // 1 : i = 2 and i <= 4
            // 2 : i = 5 and i <= 7
            // 3 : i = 8 and i <= 9
			//�ݺ��� ��ø ����
            
			for (int a = 1; a <= 3; a++) {
                nEnd = (a == 3) ? nStart + 2 : nStart + 3;
				for (int i = 1; i <= 9; i++) {
					for (int j = nStart; j < nEnd; j++) {
						//������ ��� ���� �ٸ� ���� ���
						if ((i*j) < 10) {
							printf("%d X %d = %2d  ", j, i, i*j);
						}else {
							printf("%d X %d = %1d  ", j, i, i*j);
						}
					}
					printf("\n");
				}
                printf("\n");
                nStart += 3;
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