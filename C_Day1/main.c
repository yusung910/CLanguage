#include<stdio.h>

void main()
{
	
	int nA = 0;
	int nB = 0;
	int nC = 0;
	int nD = 0;
	float fE = 0.0f;


	unsigned char ch1 = 'G';
	unsigned char ch2 = 'A';
	unsigned char ch3 = 'M';
	unsigned char ch4 = 'E';
	unsigned char ch5 = '\0';

	nA = 10;
	nB = 10;

	printf("문자열 %c의 ASCII CODE 값 %d\n", ch1, ch1);
	printf("문자열 %c의 ASCII CODE 값 %d\n", ch2, ch2);
	printf("문자열 %c의 ASCII CODE 값 %d\n", ch3, ch3);
	printf("문자열 %c의 ASCII CODE 값 %d\n", ch4, ch4);

	printf("정수 4개를 입력하여주세요 : ");
	scanf("%d %d %d %d", &nA, &nB, &nC, &nD);
	printf("실수 1개를 입력하여주세요 : ");
	scanf("%f", &fE);

	
	printf("문자 다섯개를 입력하여주세요 : ");
	ch1 = '\0';

	//문자열 입력 할 때 앞에서 입력 받은 실수 값 이후 사용자의 enter 입력으로
	//scanf 앞에 공백으로 초기화 또는  getchar()로 입력 버퍼를 초기화 해야함
	getchar();
	scanf("%c %c %c %c %c", &ch1, &ch2, &ch3, &ch4, &ch5);

	printf("%d의 10진수 : %d, 16진수 : %x\n", nA, nA, nA);
	printf("%d의 10진수 : %d, 16진수 : %x\n", nB, nB, nB);
	printf("%d의 10진수 : %d, 16진수 : %x\n", nC, nC, nC);
	printf("%d의 10진수 : %d, 16진수 : %x\n", nD, nD, nD);
	printf("%f의 10진수 : %d, 16진수 : %x\n\n", fE, *(unsigned int *)&fE, *(unsigned int *)&fE);
	printf("소수점 2자리 [%5.2f]\n", fE);	// 필드폭 5, 소수점미만 2
	printf("소수점 3자리 [%5.3f]\n", fE);	// 필드폭 5, 소수점미만 3
	printf("소수점 3자리 [%.3f]\n\n", fE);	// 소수점미만 3 ( 고정소수점표기 )	

	printf("%c의 10진수 : %d, 16진수 : %x\n", ch1, ch1, ch1);
	printf("%c의 10진수 : %d, 16진수 : %x\n", ch2, ch2, ch2);
	printf("%c의 10진수 : %d, 16진수 : %x\n", ch3, ch3, ch3);
	printf("%c의 10진수 : %d, 16진수 : %x\n", ch4, ch4, ch4);
	printf("%c의 10진수 : %d, 16진수 : %x\n\n", ch5, ch5, ch5);

	printf("%020d\n", ch1);
	printf("%-50d\n\n", ch2);

	printf("[%020d]\n\n", ch4);
}