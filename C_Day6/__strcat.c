#include "__strlen.h"

char* __strcat(char* pDst, const char* pSrc)
{
    int nPSrcLen = __strlen(pSrc);
    int nPDstLen = __strlen(pDst);
    for (int i = 0; i < nPSrcLen; i++) {
        pDst[nPSrcLen+i]= pSrc[i];

    }

    return pDst;
}