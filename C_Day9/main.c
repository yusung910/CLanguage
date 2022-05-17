#include <stdio.h>
#include <stdlib.h> // rand() �Լ�
#include <time.h>   // time() �Լ�
#include <malloc.h>
#include <windows.h>

#include "cnst.h"
#include "initUser.h"
#include "setDmgToUser.h"
#include "setDmgProb.h"
#include "getDeathUserCnt.h"
#include "setResurrectionChar.h"


void main() {
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

            //�� �ϸ��� �߻��ϴ� ����� ��
            int nDeathNum = 0;
            //��Ȱ ���� ��
            int nResurection = 0;
            //ȸ�� ������ ��
            int nDodge = 0;

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

            printf("User / Live / Life / Dmg , User / Live / Life / Dmg , User / Live / Life / Dmg , User / Live / Life / Dmg , User / Live / Life / Dmg\n");

            //��� ���
            for (int b = 0; b < 100; b++) {

                char* heartFlag = (players[b] == NULL) ? "\u2661" : "\u2665";
                int nPlayerLife = (players[b] == NULL) ? 0 : players[b]->nLife;
                int nPlayerDamaged = (players[b] == NULL) ? 0 : players[b]->nDamage;
                int nTextColor = (players[b] == NULL) ? 0 : 3;

                //������ ���� �� �������� 0 �Ծ��� ��� ��������� ����
                if (nTextColor == 3) {
                    switch (players[b]->nDamage) {
                    case 0:
                        //�������� ȸ�� ���� ���.
                        nTextColor = 6;
                        break;
                    case 10:
                        //�ƽ�������(ũ��Ƽ����Ʈ)�� ������ ���
                        nTextColor = 4;
                    }

                }

                //ȸ�ǵ������� �߻� �� ��� ī����
                if (players[b] != NULL) {
                    if (players[b]->nDamage == 0) nDodge += 1;
                }

                //������� ��� ���� ����
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), nTextColor);

                printf("%4d / %4s / %4d / %3d , ", (b + 1), heartFlag, nPlayerLife, nPlayerDamaged);
                if (b % 5 == 4) {
                    printf("\n");
                }
            }

            //����� �÷��̾��� ����� ����� ������ �迭�� �����Ѵ�,
            //�迭�� �޸𸮿��� ���������� �� ������ �����͸� �ʱ�ȭ�Ѵ�.

            //���๮�� �߰�
            printf("\n");
            //ȭ�� ���� ���� ����
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

            //�����Ȳ ���
            printf("���� ĳ���� %d�� ��� ĳ���� %d��\n", (100 - nDeathNum), nDeathNum);
            printf("��Ȱ ĳ���� %d��\n", nResurection);
            printf("�̹� �������� ���� ĳ���� %d��\n", nDeathNum);
            printf("�̹� ���ݿ� ���� ���� ���� ĳ���� %d��\n", nDodge);

            //�������� Ȯ�� ���
            printf("������ �� Ȯ�� :\n");
            float rateSum = 0.0f;
            for (int z = 0; z < 11; z++) {
                printf("%2d : %6.3f%% / ", z, (nDmgProbList[z] * 100));

                rateSum = rateSum + (nDmgProbList[z] * 100);

                if (z % 5 == 0 && z != 0)
                    printf("\n");
            }
            printf("\nȮ�� ���� %.3f%%", rateSum);
        }
        else if (inputKeyVal == 27) {
            puts("game ����!");
            break;
        }

    }
}