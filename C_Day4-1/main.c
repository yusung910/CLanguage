#include<stdio.h>
#include <stdlib.h> // rand() �Լ�
#include <conio.h>  // getch() �Լ�
#include <time.h>   // time() �Լ�

void main() {
	//���� ���� ����
	int nRd;
	//����ڰ� �Է��� �� ���� ����
	int inputN = 0;
	//���� ���� Ƚ�� ���� ī��Ʈ
	int nCount = 0;
	//����� ����
	int nScore = 0;
	//���� �÷��� ����
	int nFlag = 0;

	//�ð� ���� �̿��Ͽ� ���� ����
	srand((unsigned)time(NULL));

	//���� ����
	nRd = (rand() % 9) + 1;

	puts("1���� 10���� ���ڰ� ������ ���ڰ� �����˴ϴ�.");
	puts("������ ������ ���ڸ� ���纸����!");
	puts("��ȸ�� 3��, �Է��Ͻ� ���ڿ� ������ ���ڰ� ���� ���� ���");
	puts("�� ����� �˷��帳�ϴ�.");

	while (1) {
		printf("���� ���� : %d\n", nScore);
		printf("���ڸ� �Է��Ͽ� �ּ��� :");
		scanf(" %d", &inputN);

		++nCount;

		if (nRd == inputN  || nCount == 3){
			if (nRd == inputN) {
				//���� ��� 10���� ���Ѵ�.
				nScore += 10;
				puts("�����Դϴ�!");
			}else {
				printf("Ʋ�Ƚ��ϴ�, ������ ���� %d �Դϴ�!\n", nRd);
			}

			printf("���� ���� : %d\n", nScore);
			printf("��� �Ͻðڽ��ϱ�?(�ٽ�: ����Ű, ����: ESCŰ)\n ");
			int nUserInputKey = _getch();

			if (nUserInputKey == 13) {
				nRd = (rand() % 9) + 1;
				nCount = 0;
			}else if(nUserInputKey == 27) {
				puts("������ ����˴ϴ�.");
				break;
			}
		}else if (nRd > inputN){
			printf("%d ���� Ů�ϴ�.\n", inputN);
		}else if (nRd < inputN){
			printf("%d ���� �۽��ϴ�.\n", inputN);
		}
	}
}