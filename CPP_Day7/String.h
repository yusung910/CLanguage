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

    //문자열 세팅
    void SetString(const char* s);

    //대입연산
	const String& operator=(const String& s);
	const String& operator=(const char* chr);

    //문자열 합치기
	const String operator+(const String& s) const;
	const String operator+(const char* chr) const;

    

    //전역함수
    friend String operator+(const char* s1, const String& s2);
    friend int operator==(const char* s1, const String& s2);
    friend int operator!=(const char* s1, const String& s2);

    //문자열 비교연산
	int operator==(const String& s) const;
	int operator==(const char* chr) const;
    int operator!=(const String& s) const;
    int operator!=(const char* chr) const;

    
    char& operator[](int i) const;

	void Display();
    //문자열 길이 값을 리턴한다.
    int GetLength();
protected:

private:
	int m_nChrLength;
	char* m_tmpChr;
};