#include <malloc.h>
#include "__strlen.h"

unsigned char* __crossmemcpy(const unsigned char* pSrc1, const unsigned char* pSrc2, int nSize) {

    //리턴 배열 선언
    unsigned char* pMem;
    //pSrc1 배열 길이
    int nPSrcLen1 = __strlen(pSrc1);
    //pSrc2 배열 길이
    int nPSrcLen2 = __strlen(pSrc2);
    //pSrc1, pSrc2 중 배열 길이 값이 더 큰 값을 저장하는 변수
    int nArryEnd = (nPSrcLen1 < nPSrcLen2) ? nPSrcLen1 : nPSrcLen2;
    //pSrc1, pSrc2 중 배열이 긴 배열을 저장
    const unsigned char* longArry = (nPSrcLen1 > nPSrcLen2) ? pSrc1 : pSrc2;
    //리턴 배열에 저장되는 번호
    int nDataInputNum = 0;

    pMem = (unsigned char*)malloc((sizeof(char)*nSize) + (sizeof(char) * 1));

    //메모리 할당이 실패 할 경우 예외처리
    if (NULL == pMem)
    {
        printf("메모리 할당 실패\n");
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