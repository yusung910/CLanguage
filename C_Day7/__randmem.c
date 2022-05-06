#include <malloc.h>
#include <stdlib.h> // rand() �Լ�
#include <time.h>   // time() �Լ�

#include "__randmem.h"

unsigned char* __randmem(int nSize) {
	//���� �迭 ����
	unsigned char* retMem;

	//���� ���� ���� ����
	int nRd;

	//���� �迭�� �������� �Ҵ�.
	int memSize = (sizeof(char)*nSize) * 4;
	//���๮�� ����
	int nEnter = (memSize <= 40) ? 0 : (memSize / 4) / 10;
	retMem = (unsigned char*)malloc(memSize + sizeof(char) + nEnter);

	if (NULL == retMem)
	{
		printf("�޸� �Ҵ� ����\n");
		return;
	}

	//���� ����
	srand((unsigned)time(NULL));

	//65 ~ 90������ ������ �����Ͽ�
	//char ������ ĳ�����Ѵ�
	for (int i = 0; i < memSize; i++) {
		if (i % 4 == 0) {
			//�ߺ� ������ ���� ��� �ٽ� �����Ѵ�.
			int reTryFlag = 0;
			nRd = (rand() % 25) + 65;
			for (int j = 0; j < memSize; j++) {
				if (retMem[j] == nRd) {
					nRd = (rand() % 25) + 65;
				}
			}
		}
		if (i % 40 == 0 && i != 0) {
			retMem[i] = '\n';
		}
		else
		{
			retMem[i] = (char)nRd;
		}
		
	}
	retMem[memSize] = '\0';

	return retMem;
}