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
    //���� ����
    unsigned int nInitScore = 10;
    //���Ըӽ� ����� ���� ����� ������ �����ϴ� ����.
    int nModifyScore = 0;

	//�ð� ���� �̿��Ͽ� ���� ����
	srand((unsigned)time(NULL));

    while(1){
        nModifyScore = -5;
        printf("\r�������� : %d\n", nInitScore);
        printf("\r�ݺ� Ƚ���� �Է��Ͻø� ������ ���۵˴ϴ�:");
        scanf("%d", &nRepeat);

        for (int i = 0; i < nRepeat; i++) {
            nA = rand() % 9;
            nB = rand() % 9;
            nC = rand() % 9;
            printf("\r[%d] [%d] [%d]", nA, nB, nC);
            _sleep(100);
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

        printf("ȹ�� ���� : %d\n", nModifyScore);
        nInitScore = nInitScore + nModifyScore;

        if (nInitScore == 0) {
            puts("��� ������ �Ҿ���Ƚ��ϴ�!");
            printf("�ٽ��Ͻðڽ��ϱ�?(Enter Key�� �����ּ���)");
            char cInputKey = _getch();
            if (cInputKey == 13) {
                system("cls");
                nInitScore = 10;
            }else {
                break;
            }
        }
    }
}