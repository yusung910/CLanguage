#include "__strlen.h"

void __strcpy(char* pDst, const char* pSrc)
{
	//복사 문자열 길이
	int pSrcLen = __strlen(pSrc);

	//문자열 저장 배열 길이
	int pDstLen = __strlen(pDst);

	//복사할 문자열의 길이와 복사된 문자를 저장할
	//문자열의 길이를 비교하여 초기화 진행여부를 정한 뒤
	//여부에 따라 복사된 문자를 저장할 문자 배열을 초기화 한다.
	if (pSrcLen < pDstLen) {
		//복사 대상 배열 초기화
		for (int j = 0; j < pDstLen; j++) {
			pDst[j] = '\0';
		}
	}
	

	for (int i = 0; i < pSrcLen; i++) {
		pDst[i] = pSrc[i];
	}
}