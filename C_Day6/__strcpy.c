#include "__strlen.h"

void __strcpy(char* pDst, const char* pSrc)
{
	int pSrcLen = __strlen(pSrc);
	for (int i = 0; i < pSrcLen; i++) {
		pDst[i] = pSrc[i];
	}
}