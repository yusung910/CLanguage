#include "__strlen.h"

char* __strcpyEx(char *pDst, const char *pSrc) {

	int pSrcLen = __strlen(pSrc);

	for (int i = 0; i < pSrcLen; i++) {
		pDst[i] = pSrc[i];
	}
    return pDst;
}