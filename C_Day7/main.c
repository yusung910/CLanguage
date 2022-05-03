#include <stdio.h>
#include "__crossmemcpy.h"
#include "__strlen.h"

void main()
{
    unsigned char strList1[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    //unsigned char strList2[] = "ZYXWVUT";
    unsigned char strList2[] = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
    //AZBYCXDWEVFUGTHIJKLMNOPQRSTUVWXYZ
    int nArryLen = __strlen(strList1) + __strlen(strList2);

    printf("%s", __crossmemcpy(&strList1, &strList2, nArryLen));

    
}