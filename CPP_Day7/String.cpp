#include "String.h"


String::String() {
	m_tmpChr = NULL;
	m_nChrLength = 0;
	//cout << "String 클래스 기본 생성자";
}

String::String(const char* s) {
	//매개변수로 받은 문자열의 길이 값을 저장
	m_nChrLength = strlen(s);
	//매개변수의 문자열 길이 + 1만큼 char 객체 생성
	m_tmpChr = new char[m_nChrLength + 1];
	//문자를 복사하여 저장한다.
	::strcpy(m_tmpChr, s);
}
String::String(const String& s) {
	//매개변수로 받은 문자열의 길이 값을 저장
	m_nChrLength = strlen(s.m_tmpChr);
	//매개변수의 문자열 길이 + 1만큼 char 객체 생성
	m_tmpChr = new char[m_nChrLength + 1];
	//문자를 복사하여 저장한다.
	::strcpy(m_tmpChr, s.m_tmpChr);
}
String::String(char ch, int n) {
	m_nChrLength = n;
	//매개변수의 문자열 길이 + 1만큼 char 객체 생성
	m_tmpChr = new char[n + 1];
	//문자를 복사하여 저장한다.
	::memset(m_tmpChr, ch, n);
	m_tmpChr[n] = '\0';
}

//소멸자
String::~String() {
	if (m_tmpChr != NULL) {
		delete m_tmpChr;
		m_tmpChr = NULL;
	}
}

//문자열 셋
void String::SetString(const char* s) {
    //매개변수로 받은 문자열의 길이 값을 저장
    m_nChrLength = strlen(s);
    //매개변수의 문자열 길이 + 1만큼 char 객체 생성
    m_tmpChr = new char[m_nChrLength + 1];
    //문자를 복사하여 저장한다.
    ::strcpy(m_tmpChr, s);
}

//대입연산자
//String 객체를 매개변수로 전달 받아 복사 한 후 리턴한다.
const String& String::operator=(const String& s) {
	if (&s == this) return *this;
	if (m_tmpChr) {
		delete m_tmpChr;
		m_tmpChr = NULL;
	}

	m_nChrLength = s.m_nChrLength;
	m_tmpChr = new char[s.m_nChrLength + 1];
	::strcpy(m_tmpChr, s.m_tmpChr);

	return *this;
}
//대입연산자
//char 값을 매개변수로 전달받아 복사한 후 리턴한다.
const String& String::operator=(const char* chr) {
	if (m_tmpChr) {
		delete m_tmpChr;
		m_tmpChr = NULL;
	}

	m_nChrLength = strlen(chr);
	m_tmpChr = new char[m_nChrLength + 1];
	::strcpy(m_tmpChr, chr);

	return *this;
}

//+연산을 통해 문자열을 합친다.
const String String::operator+(const String& s) const
{
	char* buf = new char[m_nChrLength + s.m_nChrLength + 1];
	::strcpy(buf, m_tmpChr);
	::strcat(buf, s.m_tmpChr);

	String retVal(buf);
	delete[] buf;

	return retVal;
}
//+연산을 통해 String 객체와 char 매개변수를 합친다.
const String String::operator+(const char* chr) const
{
	char* buf = new char[m_nChrLength + strlen(chr) + 1];
	::strcpy(buf, m_tmpChr);
	::strcat(buf, chr);

	String retVal(buf);
	delete[] buf;

	return retVal;
}


int String::operator==(const String& s) const
{
	//비교연산
	//문자열 두개를 비교하여 결과 값을 리턴한다
	//대소문자를 구분한다.
	return strcmp(m_tmpChr, s.m_tmpChr) == 0;
}

int String::operator==(const char* chr) const
{
	return strcmp(m_tmpChr, chr) == 0;
}

int String::operator!=(const String& s) const
{
    //비교연산
    //문자열 두개를 비교하여 결과 값을 리턴한다
    //대소문자를 구분한다.
    return strcmp(m_tmpChr, s.m_tmpChr) != 0;
}

int String::operator!=(const char* chr) const
{
    return strcmp(m_tmpChr, chr) != 0;
}

//전역함수
String operator+(const char* s1, const String& s2){
    char* buf = new char[strlen(s1) + s2.m_nChrLength + 1];
    ::strcpy(buf, s2.m_tmpChr);
    ::strcat(buf, s1);

    String retVal(buf);
    delete[] buf;

    return retVal;
}

//전역함수
int operator==(const char* s1, const String& s2) {
    return strcmp(s1, s2.m_tmpChr) == 0;
}

//전역함수
int operator!=(const char* s1, const String& s2) {
    return strcmp(s1, s2.m_tmpChr) != 0;
}



//문자열을 출력하는 함수
void String::Display() {
	cout << m_tmpChr;
}

//저장된 문자열에서 배열번호를 매개변수로 전달하여 해당 위치의 문자열을 리턴한다.
char& String::operator[](int i) const {
    if (i >= 0 && i < m_nChrLength) {
        return m_tmpChr[i];
    }
    else {
        return m_tmpChr[0];
    }
}

//문자열 길이값을 리턴
int String::GetLength() {
    return m_nChrLength;
}
