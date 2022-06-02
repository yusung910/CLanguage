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

	cout << this << " 디폴트생성자\n";
}

String::String(const char* s, int n)
{
    //일련번호 자릿수 초기값
    int n_pos = 1;
    //일련번호 증가
    m_nNum++;
    //임시 캐릭터명 길이
    int nTmpNameLength = strlen(s);
	//임시로 일련번호를 별도의 변수에 저장한다
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
    //캐릭터명 배열 생성
    m_cName = new char[nTmpNameLength + n_pos + 1];

    //캐릭터명 복사
    ::strcpy(m_cName, s);

    for (int i = 0; i < n_pos; i++) {
        int nTmpNum = m_nNum;
        if (i > 0) {
            nTmpNum = nTmpNum / 10;
        }
        m_cName[nTmpNameLength + ((n_pos - i) - 1)] = (nTmpNum % 10) + 48;
    }

    m_cName[nTmpNameLength + n_pos] = '\0';

    //캐릭터명 + 일련번호를 붙인 문자열 길이값을 다시 저장한다.
    m_nLength = strlen(m_cName);
    m_nHp = n;
	cout << this << " 포인터생성자\n";
}

String::~String()
{
	if (m_cName)
	{
		delete m_cName;
		m_cName = NULL;
	}
	m_nNum--;
	cout << this << " 소멸자\n";
}

//// 리턴을 레퍼런스로 하여 다중대입문을 구현 ( str3 = str2 = str1 )                               
const String& String::operator=(const String& s)
{
	cout << this << " operator= 멤버함수\n";

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
	cout << " 캐릭명 : " << m_cName << ", HP : " << m_nHp << endl;
}