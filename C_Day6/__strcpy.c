#include "__strlen.h"
#include "__strset.h"

void __strcpy(char* pDst, const char* pSrc)
{
	//복사 문자열 길이
	int pSrcLen = __strlen(pSrc);

	//문자열 저장 배열 길이
	int pDstLen = __strlen(pDst);

	//long len
	int termInt = (pSrcLen > pDstLen) ? pSrcLen : pDstLen;

	for (int i = 0; i < termInt; i++) {
		pDst[i] = (pSrc[i] == '\0') ? '\0' : pSrc[i];
	}
}