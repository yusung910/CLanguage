#include "__strlen.h"

//문자열과, 문자(ascii)값을 전달받아 
//해당 문자가 있는 주소값을 리턴한다.
int __strchr(const char* pStr, int c) {
	int pStrLen = __strlen(pStr);
	int retChrPos = -1;
	for (int i = 0; i < pStrLen; i++) {
		if (pStr[i] == c) {
			retChrPos = i;
		}
	}

	return retChrPos;
}