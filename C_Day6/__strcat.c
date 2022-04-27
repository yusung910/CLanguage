
char* __strcat(char* pDst, const char* pSrc)
{
    char rsltArry[20];
    int npDst = 0;
    while (1)
    {
        if (*pSrc != '\0')
        {
            rsltArry[npDst] = *pSrc;
            *pSrc++;
            npDst++;
        }
        else
        {
            break;
        }
    }

    return pDst;
}