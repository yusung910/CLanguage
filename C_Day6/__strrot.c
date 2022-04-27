#include "__strlen.h"

char* __strrot(char *pStr) {
    int pStrlen = __strlen(pStr);

    char chrFirst = pStr[0];
    char chrLast = pStr[pStrlen-1];
    pStr[0] = chrLast;
    pStr[pStrlen - 1] = chrFirst;
    return pStr;
}