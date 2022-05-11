#include <stdio.h>
#include <stdlib.h> // rand() �Լ�
#include <time.h>   // time() �Լ�
#include <malloc.h>

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
    //�÷��̾� �迭
    CHARACTER* players[100];
    //��� �÷��̾ �����ϱ����� �迭
    int* nDeathNote;
    //�÷��̾� �� ��
    int nTurn = 0;

    //���� ����
    srand((unsigned)time(NULL));

    for (int i = 0; i < 100; i++) {
		players[i] = (CHARACTER*) malloc(sizeof(CHARACTER));
		players[i]->nLife = (rand() % 51) + 50;
		players[i]->nDamage = 0;
    }
	
    while (1) {
        printf("Enter Key�� ���� Turn�� ��������ּ���.\n");
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
                    //��� player�鿡�� ������ �������� �ο��Ѵ�.
					int nDmg = (rand() % 11);
					int userLife = players[j]->nLife;

					players[j]->nDamage = nDmg;
					players[j]->nLife = userLife - nDmg;

                    //ȸ�ǵ������� �߻� �� ��� ī����
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
            //�� �� ���� �߻��� ������� �� ��ŭ ���� �迭�� ����
            //���� �迭�� �̿��Ͽ� ���� �� ������
            //������ ����� ����� ����� �ѹ� �ʱ�ȭ ����� �� �ʿ䰡 �ֱ� ����.
            //������ �迭(int d[100])�� �̿��Ͽ� ���� �� ���
            //������ ���� ������ ���� ����
            //���� ������ �󸶵��� ��Ȱ �� �� �ֱ� ������
            //�� turn���� ����� ����� �ʱ�ȭ �ؾ���.
            nDeathNote = (int*)malloc((nDeathNum+1) * sizeof(int));
            //������ �迭�� ����ڸ� �����Ѵ�.
            int nDeathNoteArry = 0;
            for (int f = 0; f < 100; f++) {
                if (players[f] == NULL) {
                    nDeathNote[nDeathNoteArry] = f;
                    nDeathNoteArry += 1;
                }
            }
            //����� �� 10�ۼ�Ʈ ��Ȱ �Ѵ�.
            nResurection = nDeathNum / 10;
            //��Ȱ ��ų ����� �� ��ŭ �ݺ����� ����.            
            for (int c = 0; c < nResurection; c++) {
                //0���� ����� �ο� �� ������ ������ ���� ����
                int nPlayer = rand() % nDeathNoteArry;
                //������ ���� ����� ���� �ε����� character ����ü�� �������� �ٽ� �����Ѵ�.
                players[nDeathNote[nPlayer]] = (CHARACTER*)malloc(sizeof(CHARACTER));
                players[nDeathNote[nPlayer]]->nLife = (rand() % 51) + 50;
                players[nDeathNote[nPlayer]]->nDamage = 0;
            }

			//��� ���
			for (int b = 0; b < 100; b++) {

				char* heartFlag = (players[b] == NULL) ? "\u2665" : "\u2661";
                int nPlayerLife = (players[b] == NULL) ? 0 : players[b]->nLife;
                int nPlayerDamaged = (players[b] == NULL) ? 0 : players[b]->nDamage;

				printf("%3d / %s / %3d / %3d , ", b, heartFlag, nPlayerLife, nPlayerDamaged);
				if (b % 5 == 4) {
					printf("\n");
				}
			}

            //����� �÷��̾��� ����� ����� ������ �迭�� �����Ѵ�.
            free(nDeathNote);

			printf("\n");
			printf("\r���� ĳ���� %d�� ��� ĳ���� %d��\n", (100- nDeathNoteArry), nDeathNoteArry);
			printf("\r��Ȱ ĳ���� %d��\n", nResurection);
			printf("\r�̹� �������� ���� ĳ���� %d��\n", nDeathNum);
			printf("\r�̹� ���ݿ� ���� ���� ���� ĳ���� %d��\n", nDodge);
		}else {
			puts("game ����!");
			break;
		}

    }
}