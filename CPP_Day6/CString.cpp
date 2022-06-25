#include <iostream>
#include <String.h>
#include "CString.h"

using namespace std;

CString::CString() {
    m_pChar = NULL;
    m_nLength = 0;
};

CString::CString(const char* s) {
    m_nLength = strlen(s);
    m_pChar = new char[m_nLength + 1];
    ::strcpy(m_pChar, s);
};

CString::CString(const CString& s) {
    m_nLength = s.m_nLength;
    m_pChar = new char[m_nLength + 1];
    ::strcpy(m_pChar, s.m_pChar);
};

CString::CString(char ch, int n) {
    m_nLength = n;
    m_pChar = new char[m_nLength + 1];
    ::memset(m_pChar, ch, m_nLength);
    m_pChar[m_nLength] = '\0';
};

CString::~CString() {
    if (m_pChar) delete m_pChar;
};

const CString& CString::operator=(const CString& s) {
    if (&s == this) return *this;
    if (m_pChar) {
        m_nLength = 0;
        delete m_pChar;
    }

    m_nLength = s.m_nLength;
    m_pChar = new char[m_nLength + 1];
    ::strcpy(m_pChar, s.m_pChar);
    return *this;
};

int CString::GetLength(void) const {
    return m_nLength;
}

//Ãâ·Â
void CString::Display(void) const
{
    cout << m_pChar;
}