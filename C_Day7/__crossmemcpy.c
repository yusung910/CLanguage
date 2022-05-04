#include <malloc.h>
#include "__strlen.h"

unsigned char* __crossmemcpy(const unsigned char* pSrc1, const unsigned char* pSrc2, int nSize) {

    //���� �迭 ����
    unsigned char* pMem;
    //pSrc1 �迭 ����
    int nPSrcLen1 = __strlen(pSrc1);
    //pSrc2 �迭 ����
    int nPSrcLen2 = __strlen(pSrc2);
    //pSrc1, pSrc2 �� �迭 ���� ���� �� ū ���� �����ϴ� ����
    int nArryEnd = (nPSrcLen1 < nPSrcLen2) ? nPSrcLen1 : nPSrcLen2;
    //pSrc1, pSrc2 �� �迭�� �� �迭�� ����
    const unsigned char* longArry = (nPSrcLen1 > nPSrcLen2) ? pSrc1 : pSrc2;
    //���� �迭�� ����Ǵ� ��ȣ
    int nDataInputNum = 0;

    pMem = (unsigned char*)malloc((sizeof(char)*nSize) + (sizeof(char) * 1));

    //�޸� �Ҵ��� ���� �� ��� ����ó��
    if (NULL == pMem)
    {
        printf("�޸� �Ҵ� ����\n");
        return;
    }

    for (int a = 0; a < (nArryEnd * 2); a=a+2)
    {
        pMem[a] = pSrc1[nDataInputNum];
        pMem[a + 1] = pSrc2[nDataInputNum];
        
        ++nDataInputNum;
    }

    for (int b = (nArryEnd * 2); b < nSize; b++) {
        pMem[b] = longArry[nDataInputNum];

        ++nDataInputNum;
    }

    pMem[nSize] = '\0';

    return pMem;
}