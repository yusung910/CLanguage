#include <malloc.h>
#include <stdlib.h> // rand() 함수
#include <time.h>   // time() 함수

#include "__randmem.h"

unsigned char* __randmem(int nSize) {
	//리턴 배열 선언
	unsigned char* retMem;

	//난수 저장 변수 선언
	int nRd;

	//배열에 할당할 문자 길이
	int chrSize = (sizeof(char)*nSize) * 4;
	//개행문자 갯수
	int nEnter = (chrSize / 4) / 10;
	//생성할 배열의 사이즈
	int memSize = chrSize + nEnter;
	//메모리 동적 할당
	retMem = (unsigned char*)malloc(memSize);

	if (NULL == retMem)
	{
		printf("메모리 할당 실패\n");
		return;
	}

	//난수 세팅
	srand((unsigned)time(NULL));

	//65 ~ 90사이의 난수를 생성하여
	//char 변수로 캐스팅한다
	//0 : 0 ~ 40
	//1 : 40 ~ 80
	//2 : 80 ~ 120
	//0~39  : 문자
	//40    : 개행문자
	//41~81 : 문자
	//82    : 개행문자
	//개행숫자만큼 반복
	for (int a = 0; a < nEnter; a++) {
		int nStart = a * 40;
		int nEnd = nEnter * 40;
	}
	for (int i = 0; i < memSize; i++) {
		if (i % 4 == 0) {
			nRd = (rand() % 25) + 65;
		}

		retMem[i] = (char)nRd;
		if (i % 40 == 0 && i != 0) {
			retMem[i] = '\n';
		}
		
	}
	retMem[memSize] = '\0';

	return retMem;
}