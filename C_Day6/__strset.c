#pragma once
#include "__strlen.h"
char* __strset(char* pStr, int c) {
	int pStrLen = __strlen(pStr);
	for (int i = 0; i < pStrLen; i++) {
		pStr[i] = c;
	}

	return pStr;
}