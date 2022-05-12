#include <stdio.h>
#include <stdlib.h> // rand() �Լ�
#include <time.h>   // time() �Լ�
#include <malloc.h>
#include <windows.h>

#define TRUE	1
#define FALSE	0

//typedef int	BOOL;

typedef struct
{
//    BOOL bIsLive;  // ���� ����
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
    //������ Ȯ��
    float nDmgProbList[] = { 0.05, 0.05, 0.05, 0.11, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.14 };

    //���� ����
    srand((unsigned)time(NULL));

    for (int i = 0; i < 100; i++) {
		players[i] = (CHARACTER*) malloc(sizeof(CHARACTER));
		players[i]->nLife = (rand() % 51) + 50;
		players[i]->nDamage = 0;
    }
	printf("Enter Key(����), Esc Ű(����)\n");
    while (1) {
		int inputKeyVal = getch();
		if(inputKeyVal == 13){
            system("cls");
			printf("Enter Key�� ���� Turn�� ��������ּ���, EscŰ�� ���� ��� ������ ����˴ϴ�.\n");
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
					//�� ���� �ݺ��� ���� ���� �������� ���� �� �ֵ��� ���̵��� ���� ����ȭ �Ѵ�.
					int nFlagDmg = (rand() % 100);

					
					int nDmg = 0;
                    int nBegin = 0;
                    int nEnd = 0;

					for (int i = 0; i < 11; i++) {
						//0: 0<= a < 5, 0.05
						//1: 5<= a < 10, 0.05
						//2: 10<= a < 15, 0.2
						//3: 30<= a < 40, 0.1
						//4: 40<= a < 50, 0.1
						//5: 50<= a < 60, 0.1
                        int nProb = nDmgProbList[i] * 100;
                        nBegin = (i == 0) ? 0 : nEnd;
                        nEnd = nEnd + (nProb);

                        if (nBegin <= nFlagDmg && nFlagDmg < nEnd) {
                            nDmg = i;
                        }
					}


					int userLife = players[j]->nLife;

					players[j]->nDamage = nDmg;
					players[j]->nLife = userLife - nDmg;

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
				if (players[b] != NULL ){
					if(players[b]->nDamage == 0) nDodge += 1;
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
            free(nDeathNote);

			printf("\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("\r���� ĳ���� %d�� ��� ĳ���� %d��\n", (100- nDeathNoteArry), nDeathNoteArry);
			printf("\r��Ȱ ĳ���� %d��\n", nResurection);
			printf("\r�̹� �������� ���� ĳ���� %d��\n", nDeathNum);
			printf("\r�̹� ���ݿ� ���� ���� ���� ĳ���� %d��\n", nDodge);
		}else if(inputKeyVal == 27){
			puts("game ����!");
			break;
		}

    }
}