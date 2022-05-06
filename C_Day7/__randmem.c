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
	int memSize = chrSize + nEnter + (sizeof(char));
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
	//1 : 41 ~ 82
	//2 : 83 ~ 124
    //3 : 125 ~ 166
    //4 : 207 ~ 248
    //5 : 249 ~ 290
    //6 : 330 ~ 371
	//0~39  : 문자
	//40    : 개행문자
	//41~82 : 문자
	//82    : 개행문자
	//개행숫자만큼 반복
    //#define STD_CHR_CNT 40 
    int addedEnterCnt = 0;
    int nStart = 0;
    int nEnd = 40;
	for (int a = 0; a < nEnter; a++) {
        int nChrCnt = 0;
        for (int b = nStart; b < nEnd; b++) {
            if (nChrCnt % 4 == 0) {
                nRd = (rand() % 25) + 65;
            }
            nChrCnt += 1;
            retMem[b] = (char)nRd;
        }
        retMem[nEnd] = '\n';
        nStart = nStart + STD_CHR_CNT + 1;
        nEnd = nEnd + STD_CHR_CNT + 1;
	}
	retMem[memSize-1] = '\0';

	return retMem;
}