#include "__strlen.h"

char* __strrot(char* pStr) {
	int pStrLen = __strlen(pStr);
    char chrFrist = pStr[0];

	
	for (int i = 0; i < pStrLen;i++) {
		pStr[i] = pStr[i + 1];
	}
	
	pStr[pStrLen - 1] = chrFrist;
    return pStr;
}