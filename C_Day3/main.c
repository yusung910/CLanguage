#include <stdio.h>

void main(){
    float flA = 0;
    float flB = 0;
    char chrSign = '\0';
    float flRslt = 0;
	int nSwitchFlag = 0;

	int flagSign = 0;

    printf("����(+,-,*,/)�� �Է��Ͽ��ּ��� : ");
    scanf("%f %c %f", &flA, &chrSign, &flB);
    //���� 1-1
    if (chrSign == '+')
    {
        flRslt = flA + flB;
    }
    else if(chrSign == '-')
    {
        flRslt = flA - flB;
    }
    else if (chrSign == '*')
    {
        flRslt = flA * flB;
    }
    else if (chrSign == '/')
    {
        flRslt = flA * flB;
	}
	else {
		flagSign = 1;
	}

	if (flagSign)
	{
		puts("��ȿ���� ���� �����Դϴ�.");
	}
    else
    {
		printf("���� ����� %.5f�Դϴ�.", flRslt);
    }

	//���� 1-2
	//switch (chrSign) {
	//	case '+':
	//		flRslt = flA + flB;
	//		break;
	//	case '-':
	//		flRslt = flA - flB;
	//		break;
	//	case '*':
	//		flRslt = flA * flB;
	//		break;
	//	case '/':
	//		flRslt = flA * flB;
	//		break;
	//	default:
	//		nSwitchFlag = 1;
	//		puts("��ȿ���� ���� �����Դϴ�.");
	//		break;
	//}

	//if (nSwitchFlag)
	//	printf("���� ����� %.5f�Դϴ�.", flRslt);
}

