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

	const String& operator=(const String& s);

protected:

private:
	int m_nChrLength;
	char* m_tmpChr;
};