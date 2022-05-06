#include <malloc.h>
#include <stdlib.h> // rand() �Լ�
#include <time.h>   // time() �Լ�

#include "__randmem.h"

unsigned char* __randmem(int nSize) {
	//���� �迭 ����
	unsigned char* retMem;

	//���� ���� ���� ����
	int nRd;

	//�迭�� �Ҵ��� ���� ����
	int chrSize = (sizeof(char)*nSize) * 4;
	//���๮�� ����
	int nEnter = (chrSize / 4) / 10;
	//������ �迭�� ������
	int memSize = chrSize + nEnter;
	//�޸� ���� �Ҵ�
	retMem = (unsigned char*)malloc(memSize);

	if (NULL == retMem)
	{
		printf("�޸� �Ҵ� ����\n");
		return;
	}

	//���� ����
	srand((unsigned)time(NULL));

	//65 ~ 90������ ������ �����Ͽ�
	//char ������ ĳ�����Ѵ�
	//0 : 0 ~ 40
	//1 : 40 ~ 80
	//2 : 80 ~ 120
	//0~39  : ����
	//40    : ���๮��
	//41~81 : ����
	//82    : ���๮��
	//������ڸ�ŭ �ݺ�
	for (int a = 0; a < nEnter; a++) {
		int nStart = a * 40;
		int nEnd = nEnter * 40;
	}
	for (int i = 0; i < memSize; i++) {
		if (i % 4 == 0) {
			nRd = (rand() % 25) + 65;
		}

		retMem[i] = (char)nRd;
		if (i % 40 == 0 && i != 0) {
			retMem[i] = '\n';
		}
		
	}
	retMem[memSize] = '\0';

	return retMem;
}