#include <malloc.h>
#include <stdio.h>
#include "__scanmem.h"

#define TRUE 1
#define FALSE 0
#define BOOL int

BOOL __scanmem(unsigned char* pMem, int nSize) {
    //변경 문자열 목록
    char chngChrList[3][5] = { "GAME", "PIKA" };
    //변경 여부 변수 및 리턴값을 위한 변수
    BOOL chngFlag = FALSE;
    //pMem이 할당되지 않을경우 FALSE를 리턴한다.
    if (pMem == NULL) {
        return FALSE;
    }

    //문자열 4씩 증가해서 반복한다.
    //전달받은 pMem 문자열은 4개씩 같은 문자열이 반복되서 전달 받는다
    for (int i = 0; i < nSize; i=i+4) {
        //변경할 문자열이 2차원 배열[3][5] 형태로 저장되어 있다.
        for (int j = 0; j < 5; j++) {
            //매개변수로 전달받은 문자열과 일치하는 문자열이 있을경우
            if (pMem[i] == chngChrList[0][j]){
                //전달받은 문자열(pMem)에서 변경할 문자열과 일치하는 값의 자리 번호를 저장한다.
                int pMemChrNum = i;
                while (pMem[pMemChrNum] == chngChrList[0][j]) {
                    //해당번호에서 1씩 증가하면서 해당하는 문자와 일치할때까지 문자열을 바꿔 저장한다.
                    pMem[pMemChrNum] = chngChrList[1][j];
                    pMemChrNum++;
                }
                chngFlag = TRUE;
            }
        }
    }

    if (chngFlag) {
        printf("change success : %s\n", pMem);
    }
    else {
        puts("change fail!");
    }

    return chngFlag;
	
}