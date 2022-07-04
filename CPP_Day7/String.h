#pragma once

#include <iostream>
#include <string.h>

using namespace std;

class String {
public:

	String();
	String(const char* s);
	String(const String& s);
	String(char ch, int n);
	~String();

    //���ڿ� ����
    void SetString(const char* s);

    //���Կ���
	const String& operator=(const String& s);
	const String& operator=(const char* chr);

    //���ڿ� ��ġ��
	const String operator+(const String& s) const;
	const String operator+(const char* chr) const;

    

    //�����Լ�
    friend String operator+(const char* s1, const String& s2);
    friend int operator==(const char* s1, const String& s2);
    friend int operator!=(const char* s1, const String& s2);

    //���ڿ� �񱳿���
	int operator==(const String& s) const;
	int operator==(const char* chr) const;
    int operator!=(const String& s) const;
    int operator!=(const char* chr) const;

    
    char& operator[](int i) const;

	void Display();
    //���ڿ� ���� ���� �����Ѵ�.
    int GetLength();
protected:

private:
	int m_nChrLength;
	char* m_tmpChr;
};