#include <stdio.h>
#include "cnst.h"

int setResurrectionChar(CHARACTER** players, int nDeathUserCnt) {

	//�� �� ���� �߻��� ������� �� ��ŭ ���� �迭�� ����
	//���� �迭�� �̿��Ͽ� ���� �� ������
	//������ ����� ����� ����� �ѹ� �ʱ�ȭ ����� �� �ʿ䰡 �ֱ� ����.
	//������ �迭(int d[100])�� �̿��Ͽ� ���� �� ���
	//������ ���� ������ ���� ����
	//���� ������ �󸶵��� ��Ȱ �� �� �ֱ� ������
	//�� turn���� ����� ����� �ʱ�ȭ �ؾ���.
	int* nDeathNote = (int*)malloc(sizeof(int) * (nDeathUserCnt));
	int nResurection;
	//��� ĳ���� �� ī�����ϰ�
	//����� ĳ���Ͱ� ���� ���
	//�ش� ����ŭ ���� int �迭�� ������ ��
	//��� ĳ���� ��ȣ�� int �迭�� �����Ѵ�.
	int nDeathCharNum = 0;
	for (int a = 0; a < 100; a++) {
		if (players[a] == NULL) {
			nDeathNote[nDeathCharNum] = a;
			nDeathCharNum += 1;
		}
	}

	//����� �� 10�ۼ�Ʈ ��Ȱ �Ѵ�.
	nResurection = nDeathUserCnt / 10;

	//��Ȱ ��ų ����� �� ��ŭ �ݺ����� ����.            
	for (int c = 0; c < nResurection; c++) {
		//0���� ����� �ο� �� ������ ������ ���� ����
		int nPlayer = rand() % nDeathUserCnt;
		//������ ���� ����� ���� �ε����� character ����ü�� �������� �ٽ� �����Ѵ�.
		players[nDeathNote[nPlayer]] = (CHARACTER*)malloc(sizeof(CHARACTER));
		players[nDeathNote[nPlayer]]->nLife = (rand() % 51) + 50;
		players[nDeathNote[nPlayer]]->nDamage = 0;
	}

	//�迭�� �޸𸮿��� ���������� �� ������ �����͸� �ʱ�ȭ�Ѵ�.
	free(nDeathNote);

	return nResurection;
}