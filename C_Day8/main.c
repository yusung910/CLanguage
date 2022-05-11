#include <stdio.h>
#include <stdlib.h> // rand() �Լ�
#include <time.h>   // time() �Լ�

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

    CHARACTER players[100], *player;
    int nTurn = 0;
    player = players;

    //���� ����
    srand((unsigned)time(NULL));

    for (int i = 0; i < 100; i++) {
        (player + i)->bIsLive = TRUE;
        (player + i)->nLife = (rand() % 51) + 50;
        (player + i)->nDamage = 0;
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
				if ((player + j)->bIsLive) {
					int nDmg = (rand() % 11);
					int userLife = (player + j)->nLife;

				
					(player + j)->nDamage = nDmg;
					(player + j)->nLife = userLife - nDmg;

					if (nDmg == 0) {
						nDodge += 1;
					}
				}

				if ((player + j)->nLife <= 0) {
					//�������� ���� ������ ���ó��
					(player + j)->bIsLive = FALSE;
					(player + j)->nLife = 0;
					nDeathNote[nDeathNum] = j;
					nDeathNum += 1;
				}
			}

			//����� �� ���� 10%�ο��� ��Ȱ�Ѵ�.
			nResurection = nDeathNum / 10;

			for (int a = 0; a < nResurection; a++) {
				int nResurectionPlayer = (rand() % nResurection);
				player[nResurectionPlayer].bIsLive = TRUE;
				player[nResurectionPlayer].nLife = (rand() % 51) + 50;
				player[nResurectionPlayer].nDamage = 0;
			}
			//��� ���
			int nSurrival = 0;
			int nDieUser = 0;

			for (int b = 0; b < 100; b++) {
				char* heartFlag = (player[b].bIsLive) ? "\u2665" : "\u2661";
				if (player[b].bIsLive) {
					nSurrival += 1;
				}else {
					nDieUser += 1;
				}
				printf("%d / %s / %d / %d\n", b, heartFlag, player[b].nLife, player[b].nDamage);
			}

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