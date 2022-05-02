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
	//���� 1��
    char inputStr[] = "TEST";
    printf("���ڿ� \'%s\'�� ���̴� %d�Դϴ�.\n", inputStr, __strlen(inputStr));

	//����2��
	char copyStr1[20] = "ABCD";
    char copyStr2[] = "CopyText";

    printf("copyStr1 : %s\n", copyStr1);
    printf("copyStr2 : %s\n", copyStr2);
    __strcpy(copyStr1, copyStr2);
    printf("copyStr1 : %s\n", copyStr1);
    printf("copyStr2 : %s\n", copyStr2);
	
	//����3��
    char copyExStr[9] = "\0";
    printf("strcpyEx: %s\n", __strcpyEx(copyExStr, "ABCDTEST"));

	//����4��
    char catStr1[9] = "ABCD";
    char catStr2[] = "EFGH";

    printf("str1 : %s\n", catStr1);
    printf("str2 : %s\n", catStr2);
    printf("strcat : %s\n", __strcat(catStr1, catStr2));
    printf("\n");

	//����5��
	char strArry[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	printf("strrot : %s\n", strArry);
	for (int i = 0; i < __strlen(strArry); i++) {
		printf("strrot : %s\n", __strrot(strArry));
	}

	//���ڿ� ã��
	char strFind[] = "I have learn C Language";
	char findStr = 'A';
	int posNum = __strchr(strFind, findStr);

	printf("Base str : \"%s\"\n", strFind);

	if (posNum > 0) {
		printf("Char \'%c\' posisition is %d\n", findStr, posNum);
	}else {
		printf("Char \'%c\' posisition is not found\n", findStr);
	}

	//���ڿ� �ʱ�ȭ
	char strBefore[] = "I having study a Toeic for get a job";
	printf("Strset Before string : \"%s\" \n", strBefore);
	printf("Strset After string : \"%s\" \n", __strset(strBefore, '\0'));

	
}

