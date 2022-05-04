#include <stdio.h>
#include <malloc.h>

#include "__crossmemcpy.h"
#include "__randmem.h"
#include "__scanmem.h"
#include "__strlen.h"

void main()
{
    unsigned char strList1[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    unsigned char strList2[] = "ZYXWVUT";
    //unsigned char strList2[] = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
    //AZBYCXDWEVFUGTHIJKLMNOPQRSTUVWXYZ
    int nArryLen = __strlen(strList1) + __strlen(strList2);

	unsigned char* rsltArry;

	unsigned char* rndChrArry;

    //과제1번
    rsltArry = __crossmemcpy(strList1, strList2, nArryLen);

    printf("%s\n", rsltArry);

    //과제 2번
    int creatMemSize = 40;
	rndChrArry = __randmem(creatMemSize);

	printf("%s\n", rndChrArry);

    //과제3번
    __scanmem(rndChrArry, creatMemSize);

	free(rsltArry);
	free(rndChrArry);

    
}