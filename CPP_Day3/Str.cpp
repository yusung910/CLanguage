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

	//cout << this << " 디폴트생성자\n";
}

String::String(const char* s)
{
	m_nLength = strlen(s);
	m_cName = new char[m_nLength + 1];
	::strcpy(m_cName, s);

	//cout << this << " 포인터생성자\n";
}

String::String(const String& s, int hp)
{
	m_nNum++;

	m_nLength = s.m_nLength;
	m_cName = new char[m_nLength + 1];
	m_nHp = hp;
	

	//캐릭터 넘버 생성
	GetCharName();

	::strcpy(m_cName, s.m_cName);

	//cout << this << " 복사생성자\n";
}

String::String(char ch, int n)
{
	m_nLength = n;
	m_cName = new char[m_nLength + 1];
	::memset(m_cName, ch, m_nLength);
	m_cName[m_nLength] = '\0';
}

String::~String()
{
	if (m_cName)
	{
		delete m_cName;
		m_cName = NULL;
	}
	m_nNum--;
	//cout << this << " 소멸자\n";
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
	cout << " 캐릭명 : " << m_cName << ", HP : " << m_nHp << ", 일련번호 : " << m_nNum << endl;
}

void String::SetCharSerialNum() {
	int n_pos = 1;
	char* charNum;

	while (1)
	{
		if (m_nNum / 10 > 0) {
			n_pos++;
		} else {
			break;
		}
	}

	charNum = (char*)malloc((sizeof(char) * n_pos) + 1);

	for (int i = 0; i < n_pos; i++) {
		int nTmpNum = m_nNum;
		if (i > 1) {
			nTmpNum /= 10;
		}
		charNum[i] = (m_nNum % 10) + 48;
	}

	free(charNum);
}