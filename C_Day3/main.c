#include <stdio.h>

void main()
{
    float flA = 0;
    float flB = 0;
    char chrSign = '\0';
    float flRslt = 0;



    printf("����(+,-,*,/)�� �Է��Ͽ��ּ��� : ");
    scanf("%f %c %f", &flA, &chrSign, &flB);
    //���� 1-1
    if (chrSign == '+')
    {
        flRslt = flA + flB;
        printf("���� ����� %.5f�Դϴ�.", flRslt);
    }
    else if(chrSign == '-')
    {
        flRslt = flA - flB;
        printf("���� ����� %.5f�Դϴ�.", flRslt);
    }
    else if (chrSign == '*')
    {
        flRslt = flA * flB;
        printf("���� ����� %.5f�Դϴ�.", flRslt);
    }
    else if (chrSign == '/')
    {
        flRslt = flA * flB;
        printf("���� ����� %.5f�Դϴ�.", flRslt);
    }
    else
    {
        puts("��ȿ���� ���� �����Դϴ�.");
    }



    //���� 1-2
    //switch(chrSign){
    //    case '+':
    //        flRslt = flA + flB;
    //        printf("���� ����� %.5f�Դϴ�.", flRslt);
    //        break;

    //    case '-':
    //        flRslt = flA - flB;
    //        printf("���� ����� %.5f�Դϴ�.", flRslt);
    //        break;
    //    case '*':
    //        flRslt = flA * flB;
    //        printf("���� ����� %.5f�Դϴ�.", flRslt);
    //        break;
    //    case '/':
    //        flRslt = flA * flB;
    //        printf("���� ����� %.5f�Դϴ�.", flRslt);
    //        break;
    //    default:
    //        puts("��ȿ���� ���� �����Դϴ�.");
    //        break;
    //}

}

