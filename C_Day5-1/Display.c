//구구단 출력
#include<stdio.h>

extern int nInput;

int Display()
{
    //결과를 리턴할 변수
    int nRet = 0;
    //구구단의 마지막 값이 저장된 변수.
    int nLast = 9;

    for (int a = 1; a <= nLast; a++) {
        printf("%d * %d = %d\n", nInput, a, a * nInput);
        if (a == (nLast - 1))
        {
            //구구단의 마지막 곱셈 전의 결과(a * 8) 값을 리턴한다.
            nRet = a * nInput;
        }
    }

    return nRet;
}