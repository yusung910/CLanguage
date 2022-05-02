#include <stdio.h>

#include "__strlen.h"
#include "__strcpy.h"
#include "__strcpyEx.h"
#include "__strcat.h"
#include "__strrot.h"
#include "__strchr.h"
#include "__strset.h"

void main()
{
	//과제 1번
    char inputStr[] = "TEST";
    printf("문자열 \'%s\'의 길이는 %d입니다.\n", inputStr, __strlen(inputStr));

	//과제2번
	char copyStr1[20] = "ABCD";
    char copyStr2[] = "CopyText";

    printf("copyStr1 : %s\n", copyStr1);
    printf("copyStr2 : %s\n", copyStr2);
    __strcpy(copyStr1, copyStr2);
    printf("copyStr1 : %s\n", copyStr1);
    printf("copyStr2 : %s\n", copyStr2);
	
	//과제3번
    char copyExStr[9] = "\0";
    printf("strcpyEx: %s\n", __strcpyEx(copyExStr, "ABCDTEST"));

	//과제4번
    char catStr1[9] = "ABCD";
    char catStr2[] = "EFGH";

    printf("str1 : %s\n", catStr1);
    printf("str2 : %s\n", catStr2);
    printf("strcat : %s\n", __strcat(catStr1, catStr2));
    printf("\n");

	//과제5번
	char strArry[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	printf("strrot : %s\n", strArry);
	for (int i = 0; i < __strlen(strArry); i++) {
		printf("strrot : %s\n", __strrot(strArry));
	}

	//문자열 찾기
	char strFind[] = "I have learn C Language";
	char findStr = 'A';
	int posNum = __strchr(strFind, findStr);

	printf("Base str : \"%s\"\n", strFind);

	if (posNum > 0) {
		printf("Char \'%c\' posisition is %d\n", findStr, posNum);
	}else {
		printf("Char \'%c\' posisition is not found\n", findStr);
	}

	//문자열 초기화
	char strBefore[] = "I having study a Toeic for get a job";
	printf("Strset Before string : \"%s\" \n", strBefore);
	printf("Strset After string : \"%s\" \n", __strset(strBefore, '\0'));

	
}

