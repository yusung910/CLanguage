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
	int nA = 7, nB = 7, nC=7;
    //���� ����
    unsigned int nInitScore = 10;
    //���Ըӽ� ����� ���� ����� ������ �����ϴ� ����.
    int nModifyScore = 0;

	//�ð� ���� �̿��Ͽ� ���� ����
	srand((unsigned)time(NULL));

    printf("[%d] [%d] [%d]\n", nA, nB, nC);

    while(1){

        printf("ȹ�� ���� : %d\n", nModifyScore);

        printf("���� ���� : %d\n", nInitScore);

        nModifyScore = -5;

        printf("�ݺ� Ƚ���� �Է��Ͻø� ������ ���۵˴ϴ�:");
        scanf("%d", &nRepeat);

        
        if (nA != -1 && nB != -1 && nC != -1) {
            system("cls");
        }

        for (int i = 0; i < nRepeat; i++) {
            nA = rand() % 9;
            nB = rand() % 9;
            nC = rand() % 9;
            printf("\r[%d] [%d] [%d]", nA, nB, nC);
            _sleep(10*i);
        }

        printf("\n");

        //���� 3�� �� �ΰ��� ������ 10���� ���Ѵ�.
        if (nA == nB || nB == nC || nA == nC) {
            nModifyScore = 10;
        }
        //���� 3���� �� ������ 50���� ���Ѵ�.
        if (nA == nB && nB == nC && nA == nC) {
            nModifyScore = 50;
        }

        if (nA == 7 && nB == 7 && nC == 7) {
            nModifyScore = 1000;
        }

        nInitScore = nInitScore + nModifyScore;

        if (nInitScore == 0) {
            puts("��� ������ �Ҿ���Ƚ��ϴ�!");
            printf("�ٽ��Ͻðڽ��ϱ�?(Enter Key�� �����ּ���)");
            char cInputKey = _getch();
            if (cInputKey == 13) {
                system("cls");
                nInitScore = 10;
                nModifyScore = 5;
                printf("[7] [7] [7]\n");
            }else {
                break;
            }
        }
    }
}