#include "__strlen.h"
#include "__strset.h"

void __strcpy(char* pDst, const char* pSrc)
{
	//���� ���ڿ� ����
	int pSrcLen = __strlen(pSrc);

	//���ڿ� ���� �迭 ����
	int pDstLen = __strlen(pDst);

	//long len
	int termInt = (pSrcLen > pDstLen) ? pSrcLen : pDstLen;

	for (int i = 0; i < termInt; i++) {
		pDst[i] = (pSrc[i] == '\0') ? '\0' : pSrc[i];
	}
}