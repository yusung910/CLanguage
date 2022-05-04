#include <malloc.h>
#include <stdlib.h> // rand() 함수
#include <time.h>   // time() 함수

unsigned char* __randmem(int nSize) {
	//리턴 배열 선언
	unsigned char* retMem;

	//난수 저장 변수 선언
	int nRd;

	//리턴 배열을 동적으로 할당.
	int retSize = (sizeof(char)*nSize);

	retMem = (unsigned char*)malloc(retSize + sizeof(char));

	if (NULL == retMem)
	{
		printf("메모리 할당 실패\n");
		return;
	}

	//난수 세팅
	srand((unsigned)time(NULL));

	//65 ~ 90사이의 난수를 생성하여
	//char 변수로 캐스팅한다
	for (int i = 0; i < nSize; i++) {
		if (i % 4 == 0) {
			//중복 난수가 있을 경우 다시 생성한다.
			int reTryFlag = 0;
			nRd = (rand() % 25) + 65;
			for (int j = 0; j < nSize; j++) {
				if (retMem[j] == nRd) {
					nRd = (rand() % 25) + 65;
				}
			}
		}
		retMem[i] = (char) nRd;
	}
	retMem[retSize] = '\0';

	return retMem;
}