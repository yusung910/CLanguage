// adding complete operator= member function and copy constructor

#include <iostream>
#include <string.h>
#include "str.h"

#pragma warning ( disable : 4996 )

using namespace std;

int String::m_nNum = 0;

String::String()
{
	m_cName = NULL;
	m_nHp = 100;
	m_nNum++;

	cout << this << " ����Ʈ������\n";
}

String::String(const char* s, int n)
{
    //�Ϸù�ȣ �ڸ��� �ʱⰪ
    int n_pos = 1;
    //�Ϸù�ȣ ����
    m_nNum++;
    //�ӽ� ĳ���͸� ����
    int nTmpNameLength = strlen(s);
	//�ӽ÷� �Ϸù�ȣ�� ������ ������ �����Ѵ�
	int nTmpSerial = m_nNum;
    while (1)
    {
		nTmpSerial = nTmpSerial / 10;
        if (nTmpSerial > 0) {
            n_pos++;
        } else {
            break;
        }
    }
    //ĳ���͸� �迭 ����
    m_cName = new char[nTmpNameLength + n_pos + 1];

    //ĳ���͸� ����
    ::strcpy(m_cName, s);

    for (int i = 0; i < n_pos; i++) {
        int nTmpNum = m_nNum;
        if (i > 0) {
            nTmpNum = nTmpNum / 10;
        }
        m_cName[nTmpNameLength + ((n_pos - i) - 1)] = (nTmpNum % 10) + 48;
    }

    m_cName[nTmpNameLength + n_pos] = '\0';

    //ĳ���͸� + �Ϸù�ȣ�� ���� ���ڿ� ���̰��� �ٽ� �����Ѵ�.
    m_nLength = strlen(m_cName);
    m_nHp = n;
	cout << this << " �����ͻ�����\n";
}

String::~String()
{
	if (m_cName)
	{
		delete m_cName;
		m_cName = NULL;
	}
	m_nNum--;
	cout << this << " �Ҹ���\n";
}

//// ������ ���۷����� �Ͽ� ���ߴ��Թ��� ���� ( str3 = str2 = str1 )                               
const String& String::operator=(const String& s)
{
	cout << this << " operator= ����Լ�\n";

	if (&s == this) return *this;

	if (m_cName)
	{
		delete m_cName;
		m_cName = NULL;
	}
	m_nLength = s.m_nLength;
	m_cName = new char[m_nLength + 1];
	::strcpy(m_cName, s.m_cName);

	return *this;
}


int String::GetLength(void) const
{
	return m_nLength;
}

void String::Display(void) const
{
	cout << " ĳ���� : " << m_cName << ", HP : " << m_nHp << endl;
}