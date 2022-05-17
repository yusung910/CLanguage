#include <stdio.h>
#include <stdlib.h> // rand() �Լ�
#include <time.h>   // time() �Լ�
#include <malloc.h>


#include "cnst.h"
#include "doPrintCurrentStatus.h"
#include "getDeathUserCnt.h"
#include "initUser.h"
#include "setDmgToUser.h"
#include "setDmgProb.h"
#include "setResurrectionChar.h"

void main() {
    //���̺����� �˻�
    FILE *in;
    in = fopen("save.bin", "rb");
    if (in != NULL) {
        char answer = '\0';
        while (1) {
            printf("���� ���̺� ������ �����մϴ�. �ҷ����ڽ��ϱ�?(Y,N) : ");
            scanf("%c", &answer);
            if (answer == 'Y' || answer=='y') {
                printf("do Load");
                break;
            }else if (answer == 'N' || answer == 'n') {
                break;
            }else {
                puts("Y �Ǵ� N�� �Է����ּ���.");
            }
        }
    }


    //�÷��̾� �迭
    CHARACTER* players[100];
    //��� �÷��̾ �����ϱ����� �迭
	int* nDeathNote;
    //�÷��̾� �� ��
    int nTurn = 0;
    //������ Ȯ��
    float nDmgProbList[11];

    //���� ����
    srand((unsigned)time(NULL));

    //ĳ���� �ʱ� �����Ѵ�.
	initUser(players);		

    printf("Enter Key(����), Esc Ű(����)\n");
    while (1) {
        int inputKeyVal = getch();
        if (inputKeyVal == 13) {
            system("cls");
            printf("Enter Key�� ���� Turn�� ��������ּ���, EscŰ�� ���� ��� ������ ����˴ϴ�.\n");
            nTurn += 1;
            printf("Turn : %d\n", nTurn);

			//��Ȱ ĳ���� ��
			int nResurection = 0;
			//��� ĳ���� ��
			int nDeathNum = 0;
			//�������� Ȯ���� �����Ѵ�.
			setDmgProb(nDmgProbList, nTurn);

			//ĳ���Ϳ��� �������� ���Ѵ�.
			setDmgToUser(players, nDmgProbList);

			//��� ĳ���� ���� �����´�.
			nDeathNum = getDeathUserCnt(players);

			//����� ĳ���Ͱ� ���� ��� ��Ȱ ĳ���͸� �۾��Ѵ�.
			if (nDeathNum > 0) {
				//����� �� ���� 10% �ο��� ��Ȱ�Ѵ�.
				nResurection = setResurrectionChar(players, nDeathNum);
			}

			//���� ��Ȳ�� ����Ѵ�.
			doPrintCurrentStatus(players, nDmgProbList, nResurection, nDeathNum);
        }else if (inputKeyVal == 27) {
            //���� ����� ������ ������ save.bin�� ����
            FILE *out;
            out = fopen("save.bin", "wb");

            //�÷��̾� ���� ����
            fwrite(players, 1, sizeof(players), out);

            //���� �� ���� ����
            fwrite(&nTurn, 1, sizeof(nTurn), out);

            //�������� Ȯ�� ���� ����
            fwrite(nDmgProbList, 1, sizeof(nDmgProbList), out);

            //���� ���� ����
            fclose(out);
            puts("game ����!");
            break;
        }

    }
}