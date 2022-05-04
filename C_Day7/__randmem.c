#include <malloc.h>
#include <stdlib.h> // rand() �Լ�
#include <time.h>   // time() �Լ�

unsigned char* __randmem(int nSize) {
	//���� �迭 ����
	unsigned char* retMem;

	//���� ���� ���� ����
	int nRd;

	//���� �迭�� �������� �Ҵ�.
	int retSize = (sizeof(char)*nSize);

	retMem = (unsigned char*)malloc(retSize + sizeof(char));

	if (NULL == retMem)
	{
		printf("�޸� �Ҵ� ����\n");
		return;
	}

	//���� ����
	srand((unsigned)time(NULL));

	//65 ~ 90������ ������ �����Ͽ�
	//char ������ ĳ�����Ѵ�
	for (int i = 0; i < nSize; i++) {
		if (i % 4 == 0) {
			//�ߺ� ������ ���� ��� �ٽ� �����Ѵ�.
			int reTryFlag = 0;
			nRd = (rand() % 25) + 65;
			for (int j = 0; j < nSize; j++) {
				if (retMem[j] == nRd) {
					nRd = (rand() % 25) + 65;
				}
			}
		}
		retMem[i] = (char) nRd;
	}
	retMem[retSize] = '\0';

	return retMem;
}