#include <stdio.h>
#include "__strlen.h"
#include "__strcpy.h"
#include "__strcpyEx.h"
#include "__strcat.h"

void main()
{
    char inputStr[] = "TEST";
    printf("\'%s\'���ڿ��� ���̴� %d�Դϴ�.\n", inputStr, __strlen(inputStr));

    char *copyStr1 = "";
    const char *copyStr2 = "CopyText";

    printf("copyStr1 : %s\n", copyStr1);
    printf("copyStr2 : %s\n", copyStr2);
    __strcpy(&copyStr1, &copyStr2);
    printf("copyStr1 : %s\n", copyStr1);
    printf("copyStr2 : %s\n", copyStr2);

    char *copyExStr = "";
    printf("%s", __strcpyEx(copyExStr, "ABCDTEST"));

    char *catStr1 = "ABCD";
    char *catStr2 = "EFGH";
    printf("%s", __strcat(catStr1, catStr2));
}