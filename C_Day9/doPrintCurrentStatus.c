#include <stdio.h>
#include <windows.h>
#include "cnst.h"
void doPrintCurrentStatus(CHARACTER** players, float* nDmgProbList, int nResurection, int nDeathNum) {
	//ȸ�� ������ ��
	int nDodge = 0;

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
	printf("\nȮ�� ���� %.3f%%\n", rateSum);
}