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

        //구구단 시작값
        int nStart = 2;
        //구구단 종료값
        int nEnd = 0;

		switch (nUserDat) {
		case 1:
            // 1 : i = 2 and i <= 4
            // 2 : i = 5 and i <= 7
            // 3 : i = 8 and i <= 9
			//반복문 중첩 실행
            
			for (int a = 1; a <= 3; a++) {
                nEnd = (a == 3) ? nStart + 2 : nStart + 3;
				for (int i = 1; i <= 9; i++) {
					for (int j = nStart; j < nEnd; j++) {
						//구구단 결과 값에 다른 여백 출력
						if ((i*j) < 10) {
							printf("%d X %d = %2d  ", j, i, i*j);
						}else {
							printf("%d X %d = %1d  ", j, i, i*j);
						}
					}
					printf("\n");
				}
                printf("\n");
                nStart += 3;
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