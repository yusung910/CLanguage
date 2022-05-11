#include <stdio.h>
#include <stdlib.h> // rand() �Լ�
#include <time.h>   // time() �Լ�
#include <malloc.h>

#include "__strlen.h"

#define TRUE	1
#define FALSE	0

typedef int	BOOL;

typedef struct
{
    BOOL bIsLive;  // ���� ����
    int	nDamage;      // ���� ���� ����
    int	nLife;        // ����
} CHARACTER;

void main() {

    CHARACTER* players[100];
    int nTurn = 0;

    //���� ����
    srand((unsigned)time(NULL));

    for (int i = 0; i < 100; i++) {
		players[i] = (CHARACTER*) malloc(sizeof(CHARACTER));
		players[i]->bIsLive = TRUE;
		players[i]->nLife = (rand() % 51) + 50;
		players[i]->nDamage = 0;
    }
	
    while (1) {
		printf("Enter Key�� ���� Turn�� ��������ּ���.\n");
		if(getch() == 13){
			nTurn += 1;
			printf("Turn : %d\n", nTurn);
			//����� ��� ���� �迭
			int nDeathNote[100];
			//�� �ϸ��� �߻��ϴ� ����� ��
			int nDeathNum = 0;
			//��Ȱ ���� ��
			int nResurection = 0;
			//ȸ�� ������ ��
			int nDodge = 0;
			//������ ���
			for (int j = 0; j < 100; j++) {
				if (players[j]->bIsLive) {
					int nDmg = (rand() % 11);
					int userLife = players[j]->nLife;

				
					players[j]->nDamage = nDmg;
					players[j]->nLife = userLife - nDmg;

					if (nDmg == 0) {
						nDodge += 1;
					}
				}

				if (players[j]->nLife <= 0) {
					//�������� ���� ������ ���ó��
					nDeathNote[nDeathNum] = j;
					nDeathNum += 1;
					free(players[j]);
				}
			}

			//����� �� ���� 10%�ο��� ��Ȱ�Ѵ�.
			nResurection = nDeathNum / 10;

			for (int a = 0; a < nResurection; a++) {
				int nResurectionPlayer = (rand() % nResurection);
				//player[nResurectionPlayer].bIsLive = TRUE;
				//player[nResurectionPlayer].nLife = (rand() % 51) + 50;
				//player[nResurectionPlayer].nDamage = 0;
			}
			//��� ���
			int nSurrival = 0;
			int nDieUser = 0;

			for (int b = 0; b < 100; b++) {

				char* heartFlag = (players[b]->bIsLive) ? "\u2665" : "\u2661";
				if (players[b]->bIsLive) {
					nSurrival += 1;
				}else {
					nDieUser += 1;
				}
				printf("%d / %s / %d / %d , ", b, heartFlag, players[b]->nLife, players[b]->nDamage);
				if (b > 0 && b % 5 == 0) {
					printf("\n");
				}
			}
			printf("\n");
			printf("���� ĳ���� %d�� ��� ĳ���� %d��\n", nSurrival, nDieUser);
			printf("��Ȱ ĳ���� %d��\n", nResurection);
			printf("�̹� �������� ���� ĳ���� %d��\n", nDeathNum);
			printf("�̹� ���ݿ� ���� ���� ���� ĳ���� %d��\n", nDodge);
		}else {
			puts("game ����!");
			break;
		}

    }
}