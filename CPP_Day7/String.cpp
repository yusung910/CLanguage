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

String::~String() {
	if (m_tmpChr != NULL) {
		delete m_tmpChr;
		m_tmpChr = NULL;
	}
}


const String& String::operator=(const String& s) {
	if (&s == this) return *this;
}