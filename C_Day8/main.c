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
    int* nDeathNote;
    int nTurn = 0;

    //���� ����
    srand((unsigned)time(NULL));

    for (int i = 0; i < 100; i++) {
		players[i] = (CHARACTER*) malloc(sizeof(CHARACTER));
		players[i]->nLife = (rand() % 51) + 50;
		players[i]->nDamage = 0;
    }
	
    while (1) {
		printf("\rEnter Key�� ���� Turn�� ��������ּ���.\n");
		if(getch() == 13){
            system("cls");
			nTurn += 1;
			printf("Turn : %d\n", nTurn);
			//����� ��� ���� �迭
			
			//�� �ϸ��� �߻��ϴ� ����� ��
			int nDeathNum = 0;
			//��Ȱ ���� ��
			int nResurection = 0;
			//ȸ�� ������ ��
			int nDodge = 0;
			//������ ���
			for (int j = 0; j < 100; j++) {
				if (players[j] != NULL) {
					int nDmg = (rand() % 11);
					int userLife = players[j]->nLife;

					players[j]->nDamage = nDmg;
					players[j]->nLife = userLife - nDmg;

					if (nDmg == 0) {
						nDodge += 1;
					}

                    if (players[j]->nLife <= 0) {
                        //�������� ���� ������ ���ó��
                        free(players[j]);
                        players[j] = NULL;
                    }
				}
			}

            //����� �� ���� 10% �ο��� ��Ȱ�Ѵ�.
            //����ڸ� ī�����Ѵ�.
			for (int a = 0; a < 100; a++) {
                if (players[a] == NULL) {
                    nDeathNum += 1;
                }
			}

            nDeathNote = (int*)malloc((nDeathNum+1) * sizeof(int));
            int nDeathNoteArry = 0;
            for (int f = 0; f < 100; f++) {
                if (players[f] == NULL) {
                    nDeathNote[nDeathNoteArry] = f;
                    nDeathNoteArry += 1;
                }
            }

            nResurection = nDeathNum / 10;
            //����� �� 10�ۼ�Ʈ ��Ȱ �Ѵ�.
            for (int c = 0; c < nResurection; c++) {

                int nPlayer = rand() % nDeathNoteArry;
                players[nDeathNote[nPlayer]] = (CHARACTER*)malloc(sizeof(CHARACTER));
                players[nDeathNote[nPlayer]]->nLife = (rand() % 51) + 50;
                players[nDeathNote[nPlayer]]->nDamage = 0;
            }

			//��� ���
			int nSurrival = 0;
			int nDieUser = 0;

			for (int b = 0; b < 100; b++) {

				char* heartFlag = (players[b] == NULL) ? "\u2665" : "\u2661";
                int nPlayerLife = (players[b] == NULL) ? 0 : players[b]->nLife;
                int nPlayerDamaged = (players[b] == NULL) ? 0 : players[b]->nDamage;
				if (players[b] == NULL) {
					nSurrival += 1;
				}else {
					nDieUser += 1;
				}
				printf("%3d / %s / %3d / %3d , ", b, heartFlag, nPlayerLife, nPlayerDamaged);
				if (b % 5 == 4) {
					printf("\n");
				}
			}

            free(nDeathNote);

			printf("\n");
			printf("\r���� ĳ���� %d�� ��� ĳ���� %d��\n", nSurrival, nDieUser);
			printf("\r��Ȱ ĳ���� %d��\n", nResurection);
			printf("\r�̹� �������� ���� ĳ���� %d��\n", nDeathNum);
			printf("\r�̹� ���ݿ� ���� ���� ���� ĳ���� %d��\n", nDodge);
		}else {
			puts("game ����!");
			break;
		}

    }
}