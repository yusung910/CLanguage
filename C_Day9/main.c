#include <stdio.h>
#include <stdlib.h> // rand() �Լ�
#include <time.h>   // time() �Լ�
#include <malloc.h>
#include <windows.h>

#include "characterStruct.h"
#include "initCharacter.h"
#include "revivalChar.h"
#include "setDmgProb.h"

#define TRUE	1
#define FALSE	0


//8���� ��������
//9���� ������ �����ϱ� ���� ������Ʈ
void main() {

	//�÷��̾� �迭
	CHARACTER* players[100];

	//�÷��̾� �� ��
	int nTurn = 0;

	//������ Ȯ��
	float nDmgProbList[11];

	//��Ȱ ĳ���� ��
	int nResurection = 0;

	//����� ��
	int nDeathNum = 0;

	//���� �Ͽ� �߻��� ����� ��
	int nNowturnDeath = 0;

	//���� ����
	srand((unsigned)time(NULL));

	//100���� ĳ���� �ʱ�ȭ
	initCharacter(players, 100);

	//������ Ȯ�� ����
	setDmgProb(nDmgProbList, nTurn);

	printf("Enter Key(����), Esc Ű(����)\n");
	while (1) {
		int inputKeyVal = getch();

		//���� �� ����� �ʱ�ȭ
		nNowturnDeath = 0;
		//����� �� �ʱ�ȭ
		nDeathNum = 0;

		if (inputKeyVal == 13) {
			system("cls");
			printf("Enter Key�� ���� Turn�� ��������ּ���, EscŰ�� ���� ��� ������ ����˴ϴ�.\n");
			nTurn += 1;
			printf("Turn : %d\n", nTurn);

			//ȸ�� ������ ��
			int nDodge = 0;

			//Ȯ�� ����
			setDmgProb(nDmgProbList, nTurn);

			//������ ���
			for (int j = 0; j < 100; j++) {
				if (players[j] != NULL) {
					//��� player�鿡�� ������ �������� �ο��Ѵ�. 100.00
					//�� ���� �ݺ��� ���� ���� �������� ���� �� �ֵ��� ���̵��� ���� ����ȭ �Ѵ�.
					float nFlagDmg = (float)(rand() % 10000) / 100;

					int nDmg = 0;
					float nBegin = 0;
					float nEnd = 0;

					for (int i = 0; i < 11; i++) {
						float nProb = nDmgProbList[i] * 100;
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
						nNowturnDeath += 1;
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

			//���� ĳ���� ��Ȱ ó��
			nResurection = revivalChar(players, nDeathNum);

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


			//���๮�� �߰�
			printf("\n");
			//ȭ�� ���� ���� ����
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

			//�����Ȳ ���
			printf("���� ĳ���� %d�� ��� ĳ���� %d��\n", (100 - nDeathNum), nDeathNum);
			printf("��Ȱ ĳ���� %d��\n", nResurection);
			printf("�̹� �������� ���� ĳ���� %d��\n", nNowturnDeath);
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