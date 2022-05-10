#include <malloc.h>
#include "__scanmem.h"

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
    for (int i = 0; i < nSize; i++) {
        //������ ���ڿ��� 2���� �迭[3][5] ���·� ����Ǿ� �ִ�.
        for (int j = 0; j < 5; j++) {
            //�Ű������� ���޹��� ���ڿ��� ��ġ�ϴ� ���ڿ��� �������
            if (pMem[i] == chngChrList[0][j]){
                //���޹��� ���ڿ�(pMem)���� ������ ���ڿ��� ��ġ�ϴ� ���� �ڸ� ��ȣ�� �����Ѵ�.
				pMem[i] = chngChrList[1][j];
                chngFlag = TRUE;
            }
        }
    }

    return chngFlag;
	
}