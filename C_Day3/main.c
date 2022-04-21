#include <stdio.h>

void main()
{
    float flA = 0;
    float flB = 0;
    char chrSign = '\0';
    float flRslt = 0;

	int flagSign = 0;

    printf("계산식(+,-,*,/)을 입력하여주세요 : ");
    scanf("%f %c %f", &flA, &chrSign, &flB);
    //과제 1-1
    if (chrSign == '+')
    {
        flRslt = flA + flB;
    }
    else if(chrSign == '-')
    {
        flRslt = flA - flB;
    }
    else if (chrSign == '*')
    {
        flRslt = flA * flB;
    }
    else if (chrSign == '/')
    {
        flRslt = flA * flB;
	}
	else {
		flagSign = 1;
	}

	if (flagSign)
	{
		puts("유효하지 않은 계산식입니다.");
	}
    else
    {
		printf("계산식 결과는 %.5f입니다.", flRslt);
    }

	//과제 1-2
	switch (chrSign) {
		case '+':
			flRslt = flA + flB;
			printf("계산식 결과는 %.5f입니다.", flRslt);
			break;
		case '-':
			flRslt = flA - flB;
			printf("계산식 결과는 %.5f입니다.", flRslt);
			break;
		case '*':
			flRslt = flA * flB;
			printf("계산식 결과는 %.5f입니다.", flRslt);
			break;
		case '/':
			flRslt = flA * flB;
			printf("계산식 결과는 %.5f입니다.", flRslt);
			break;
		default:
			puts("유효하지 않은 계산식입니다.");
			break;
	}
}

