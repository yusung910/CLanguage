#include "String.h"


String::String() {
	m_tmpChr = NULL;
	m_nChrLength = 0;
	//cout << "String Ŭ���� �⺻ ������";
}

String::String(const char* s) {
	//�Ű������� ���� ���ڿ��� ���� ���� ����
	m_nChrLength = strlen(s);
	//�Ű������� ���ڿ� ���� + 1��ŭ char ��ü ����
	m_tmpChr = new char[m_nChrLength + 1];
	//���ڸ� �����Ͽ� �����Ѵ�.
	::strcpy(m_tmpChr, s);
}
String::String(const String& s) {
	//�Ű������� ���� ���ڿ��� ���� ���� ����
	m_nChrLength = strlen(s.m_tmpChr);
	//�Ű������� ���ڿ� ���� + 1��ŭ char ��ü ����
	m_tmpChr = new char[m_nChrLength + 1];
	//���ڸ� �����Ͽ� �����Ѵ�.
	::strcpy(m_tmpChr, s.m_tmpChr);
}
String::String(char ch, int n) {
	m_nChrLength = n;
	//�Ű������� ���ڿ� ���� + 1��ŭ char ��ü ����
	m_tmpChr = new char[n + 1];
	//���ڸ� �����Ͽ� �����Ѵ�.
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