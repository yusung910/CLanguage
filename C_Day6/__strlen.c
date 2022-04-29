//문자열 길이 구하는 함수
int __strlen(char* pStr)
{
    int nRetStrlen = 0;

    while (1)
    {
        if (pStr[nRetStrlen] != '\0') {
            nRetStrlen += 1;
        }else{
            break;
        }
        
    }
    return nRetStrlen;
}
