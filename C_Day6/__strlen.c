//���ڿ� ���� ���ϴ� �Լ�
int __strlen(char* pStr)
{
    int nRetStrlen = 0;
    while (1)
    {
        if (*pStr != '\0') {
            nRetStrlen += 1;
            pStr++;
        }else{
            break;
        }
        
    }
    return nRetStrlen;
}
