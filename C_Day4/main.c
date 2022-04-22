#include<stdio.h>

void main(){

	//구구단 출력 과제

	//메뉴 번호 저장 변수
	int nUserDat = 0;
	//출력할 구구단 변수
	int nOutNum = 0;

	while (1) {

		puts("원하시는 메뉴를 입력하세요.");
		printf("1. 구구단 모두 출력, 2. 원하는 구구단 출력. 3. 종료 : ");
		scanf("%d", &nUserDat);

		switch (nUserDat) {
		case 1:
			//반복문 중첩 실행
			for (int i = 1; i <= 9; i++) {
				for (int j = 2; j <= 9; j++) {
					printf("%d X %d = %d  ", j, i, i*j);
				}
				printf("\n");
			}
			break;
		case 2:
			printf("원하시는 구구단 숫자를 입력하여주세요 :");
			scanf("%d", &nOutNum);
			for (int a = 1; a <= 9; a++) {
				printf("%d X %d = %d\n", nOutNum, a, a*nOutNum);
			}
			break;
		case 3:
			goto END;
		}
	}

END:
	puts("프로그램 종료!");
}