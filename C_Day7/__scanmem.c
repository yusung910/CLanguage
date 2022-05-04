#include <malloc.h>
#include <stdio.h>
#include "__scanmem.h"

#define TRUE 1
#define FALSE 0
#define BOOL int

BOOL __scanmem(unsigned char* pMem, int nSize) {
    //���� ���ڿ� ���
    char chngChrList[3][5] = { "GAME", "PIKA" };
    //���� ���� ���� �� ���ϰ��� ���� ����
    BOOL chngFlag = FALSE;
    //pMem�� �Ҵ���� ������� FALSE�� �����Ѵ�.
    if (pMem == NULL) {
        return FALSE;
    }

    //���ڿ� 4�� �����ؼ� �ݺ��Ѵ�.
    //���޹��� pMem ���ڿ��� 4���� ���� ���ڿ��� �ݺ��Ǽ� ���� �޴´�
    for (int i = 0; i < nSize; i=i+4) {
        //������ ���ڿ��� 2���� �迭[3][5] ���·� ����Ǿ� �ִ�.
        for (int j = 0; j < 5; j++) {
            //�Ű������� ���޹��� ���ڿ��� ��ġ�ϴ� ���ڿ��� �������
            if (pMem[i] == chngChrList[0][j]){
                //���޹��� ���ڿ�(pMem)���� ������ ���ڿ��� ��ġ�ϴ� ���� �ڸ� ��ȣ�� �����Ѵ�.
                int pMemChrNum = i;
                while (pMem[pMemChrNum] == chngChrList[0][j]) {
                    //�ش��ȣ���� 1�� �����ϸ鼭 �ش��ϴ� ���ڿ� ��ġ�Ҷ����� ���ڿ��� �ٲ� �����Ѵ�.
                    pMem[pMemChrNum] = chngChrList[1][j];
                    pMemChrNum++;
                }
                chngFlag = TRUE;
            }
        }
    }

    if (chngFlag) {
        printf("change success : %s\n", pMem);
    }
    else {
        puts("change fail!");
    }

    return chngFlag;
	
}