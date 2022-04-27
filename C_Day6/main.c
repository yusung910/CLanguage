#include <stdio.h>

#include "__strlen.h"
#include "__strcpy.h"
#include "__strcpyEx.h"
#include "__strcat.h"
#include "__strrot.h"

void main()
{
    char inputStr[] = "TEST";
    printf("\'%s\'���ڿ��� ���̴� %d�Դϴ�.\n", inputStr, __strlen(inputStr));

    char* copyStr1 = "";
    const char* copyStr2 = "CopyText";

    printf("copyStr1 : %s\n", copyStr1);
    printf("copyStr2 : %s\n", copyStr2);
    __strcpy(&copyStr1, &copyStr2);
    printf("copyStr1 : %s\n", copyStr1);
    printf("copyStr2 : %s\n", copyStr2);

    char *copyExStr = "";
    printf("strcpyEx: %s\n", __strcpyEx(copyExStr, "ABCDTEST"));

    char* catStr1 = "ABCD";
    const char* catStr2 = "EFGH";

    printf("strcat : %s\n", __strcat(catStr1, catStr2)); ;

    char* strrot = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    printf("strrot : %s\n", __strrot(strrot));
}

