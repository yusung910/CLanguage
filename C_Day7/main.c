#include <stdio.h>
#include <malloc.h>

#include "__crossmemcpy.h"
#include "__strlen.h"

void main()
{
    unsigned char strList1[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    unsigned char strList2[] = "ZYXWVUT";
    //unsigned char strList2[] = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
    //AZBYCXDWEVFUGTHIJKLMNOPQRSTUVWXYZ
    int nArryLen = __strlen(strList1) + __strlen(strList2);

	unsigned char* rsltArry = __crossmemcpy(&strList1, &strList2, nArryLen);

    printf("%s\n", rsltArry);


	unsigned char* rndChrArry = __randmem(40);

	printf("%s", rndChrArry);

	free(rsltArry);
	free(rndChrArry);

    
}