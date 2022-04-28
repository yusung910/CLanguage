#include <stdio.h>

#include "__strlen.h"
#include "__strcpy.h"
#include "__strcpyEx.h"
#include "__strcat.h"
#include "__strrot.h"

void main()
{
    char inputStr[] = "TEST";
    printf("\'%s\'문자열의 길이는 %d입니다.\n", inputStr, __strlen(inputStr));

    char* copyStr1 = "";
    const char* copyStr2 = "CopyText";

    printf("copyStr1 : %s\n", copyStr1);
    printf("copyStr2 : %s\n", copyStr2);
    __strcpy(&copyStr1, &copyStr2);
    printf("copyStr1 : %s\n", copyStr1);
    printf("copyStr2 : %s\n", copyStr2);

    char *copyExStr = "";
    printf("strcpyEx: %s\n", __strcpyEx(copyExStr, "ABCDTEST"));

    char catStr1[9] = "ABCD";
    char catStr2[] = "EFGH";

    printf("str1 : %s\n", catStr1);
    printf("str2 : %s\n", catStr2);
    printf("strcat : %s\n", __strcat(&catStr1, &catStr2));
    printf("\n");

	char strArry[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char* strrot = &strArry;
	printf("strrot : %s\n", __strrot(strrot));
	for (int i = 0; i < __strlen(strArry); i++) {
		printf("strrot : %s\n", __strrot(strrot));
	}
}

