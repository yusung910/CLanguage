#include "__strlen.h"

//배열을 특정 문자로 초기화 한다.
char* __strset(char* pStr, int c) {
	int pStrLen = __strlen(pStr);
	for (int i = 0; i < pStrLen; i++) {
		pStr[i] = c;
	}

	return pStr;
}