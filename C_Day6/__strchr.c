#include "__strlen.h"

//���ڿ���, ����(ascii)���� ���޹޾� 
//�ش� ���ڰ� �ִ� �ּҰ��� �����Ѵ�.
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