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
	int memSize = chrSize + nEnter + (sizeof(char));
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
	//1 : 41 ~ 82
	//2 : 83 ~ 124
    //3 : 125 ~ 166
    //4 : 207 ~ 248
    //5 : 249 ~ 290
    //6 : 330 ~ 371
	//0~39  : ����
	//40    : ���๮��
	//41~82 : ����
	//82    : ���๮��
	//������ڸ�ŭ �ݺ�
    //#define STD_CHR_CNT 40 
    int addedEnterCnt = 0;
    int nStart = 0;
    int nEnd = 40;
	for (int a = 0; a < nEnter; a++) {
        int nChrCnt = 0;
        for (int b = nStart; b < nEnd; b++) {
            if (nChrCnt % 4 == 0) {
                nRd = (rand() % 25) + 65;
            }
            nChrCnt += 1;
            retMem[b] = (char)nRd;
        }
        retMem[nEnd] = '\n';
        nStart = nStart + STD_CHR_CNT + 1;
        nEnd = nEnd + STD_CHR_CNT + 1;
	}
	retMem[memSize-1] = '\0';

	return retMem;
}