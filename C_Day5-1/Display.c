//������ ���
#include<stdio.h>

extern int nInput;

int Display()
{
    //����� ������ ����
    int nRet = 0;
    //�������� ������ ���� ����� ����.
    int nLast = 9;

    for (int a = 1; a <= nLast; a++) {
        printf("%d * %d = %d\n", nInput, a, a * nInput);
        if (a == (nLast - 1))
        {
            //�������� ������ ���� ���� ���(a * 8) ���� �����Ѵ�.
            nRet = a * nInput;
        }
    }

    return nRet;
}