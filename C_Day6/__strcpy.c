#include "__strlen.h"

void __strcpy(char* pDst, const char* pSrc)
{
	//���� ���ڿ� ����
	int pSrcLen = __strlen(pSrc);

	//���ڿ� ���� �迭 ����
	int pDstLen = __strlen(pDst);

	//������ ���ڿ��� ���̿� ����� ���ڸ� ������
	//���ڿ��� ���̸� ���Ͽ� �ʱ�ȭ ���࿩�θ� ���� ��
	//���ο� ���� ����� ���ڸ� ������ ���� �迭�� �ʱ�ȭ �Ѵ�.
	if (pSrcLen < pDstLen) {
		//���� ��� �迭 �ʱ�ȭ
		for (int j = 0; j < pDstLen; j++) {
			pDst[j] = '\0';
		}
	}
	

	for (int i = 0; i < pSrcLen; i++) {
		pDst[i] = pSrc[i];
	}
}