#include "__strlen.h"

//�迭�� Ư�� ���ڷ� �ʱ�ȭ �Ѵ�.
char* __strset(char* pStr, int c) {
	int pStrLen = __strlen(pStr);
	for (int i = 0; i < pStrLen; i++) {
		pStr[i] = c;
	}

	return pStr;
}