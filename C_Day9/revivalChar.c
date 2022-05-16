#pragma once
#include <malloc.h>
#include "characterStruct.h"
#include "revivalChar.h"

int revivalChar(CHARACTER* charList[100], int nDeathNum) {

	//��� �÷��̾ �����ϱ����� �迭
	int* nDeathNote;

	//��Ȱ ���� ��
	int nResurection = 0;

	//�� �� ���� �߻��� ������� �� ��ŭ ���� �迭�� ����
	//���� �迭�� �̿��Ͽ� ���� �� ������
	//������ ����� ����� ����� �ѹ� �ʱ�ȭ ����� �� �ʿ䰡 �ֱ� ����.
	//������ �迭(int d[100])�� �̿��Ͽ� ���� �� ���
	//������ ���� ������ ���� ����
	//���� ������ �󸶵��� ��Ȱ �� �� �ֱ� ������
	//�� turn���� ����� ����� �ʱ�ȭ �ؾ���.
	nDeathNote = (int*)malloc((nDeathNum + 1) * sizeof(int));
	//������ �迭�� ����ڸ� �����Ѵ�.
	int nDeathNoteArry = 0;
	for (int f = 0; f < 100; f++) {
		if (charList[f] == NULL) {
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
		charList[nDeathNote[nPlayer]] = (CHARACTER*)malloc(sizeof(CHARACTER));
		charList[nDeathNote[nPlayer]]->nLife = (rand() % 51) + 50;
		charList[nDeathNote[nPlayer]]->nDamage = 0;
	}
	//����� �÷��̾��� ����� ����� ������ �迭�� �����Ѵ�,
	//�迭�� �޸𸮿��� ���������� �� ������ �����͸� �ʱ�ȭ�Ѵ�.
	free(nDeathNote);

	//��Ȱ�� ĳ���� ���� �����Ѵ�.
	return nResurection;
}