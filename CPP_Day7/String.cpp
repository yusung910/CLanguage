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

//�Ҹ���
String::~String() {
	if (m_tmpChr != NULL) {
		delete m_tmpChr;
		m_tmpChr = NULL;
	}
}

//���ڿ� ��
void String::SetString(const char* s) {
    //�Ű������� ���� ���ڿ��� ���� ���� ����
    m_nChrLength = strlen(s);
    //�Ű������� ���ڿ� ���� + 1��ŭ char ��ü ����
    m_tmpChr = new char[m_nChrLength + 1];
    //���ڸ� �����Ͽ� �����Ѵ�.
    ::strcpy(m_tmpChr, s);
}

//���Կ�����
//String ��ü�� �Ű������� ���� �޾� ���� �� �� �����Ѵ�.
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
//���Կ�����
//char ���� �Ű������� ���޹޾� ������ �� �����Ѵ�.
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

//+������ ���� ���ڿ��� ��ģ��.
const String String::operator+(const String& s) const
{
	char* buf = new char[m_nChrLength + s.m_nChrLength + 1];
	::strcpy(buf, m_tmpChr);
	::strcat(buf, s.m_tmpChr);

	String retVal(buf);
	delete[] buf;

	return retVal;
}
//+������ ���� String ��ü�� char �Ű������� ��ģ��.
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
	//�񱳿���
	//���ڿ� �ΰ��� ���Ͽ� ��� ���� �����Ѵ�
	//��ҹ��ڸ� �����Ѵ�.
	return strcmp(m_tmpChr, s.m_tmpChr) == 0;
}

int String::operator==(const char* chr) const
{
	return strcmp(m_tmpChr, chr) == 0;
}

int String::operator!=(const String& s) const
{
    //�񱳿���
    //���ڿ� �ΰ��� ���Ͽ� ��� ���� �����Ѵ�
    //��ҹ��ڸ� �����Ѵ�.
    return strcmp(m_tmpChr, s.m_tmpChr) != 0;
}

int String::operator!=(const char* chr) const
{
    return strcmp(m_tmpChr, chr) != 0;
}

//�����Լ�
String operator+(const char* s1, const String& s2){
    char* buf = new char[strlen(s1) + s2.m_nChrLength + 1];
    ::strcpy(buf, s2.m_tmpChr);
    ::strcat(buf, s1);

    String retVal(buf);
    delete[] buf;

    return retVal;
}

//�����Լ�
int operator==(const char* s1, const String& s2) {
    return strcmp(s1, s2.m_tmpChr) == 0;
}

//�����Լ�
int operator!=(const char* s1, const String& s2) {
    return strcmp(s1, s2.m_tmpChr) != 0;
}



//���ڿ��� ����ϴ� �Լ�
void String::Display() {
	cout << m_tmpChr;
}

//����� ���ڿ����� �迭��ȣ�� �Ű������� �����Ͽ� �ش� ��ġ�� ���ڿ��� �����Ѵ�.
char& String::operator[](int i) const {
    if (i >= 0 && i < m_nChrLength) {
        return m_tmpChr[i];
    }
    else {
        return m_tmpChr[0];
    }
}

//���ڿ� ���̰��� ����
int String::GetLength() {
    return m_nChrLength;
}
