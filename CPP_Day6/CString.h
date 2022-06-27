#pragma once
class CString
{
public:
    CString();
    CString(const char* s);
    CString(const CString& s);
    CString(char ch, int n);
    ~CString();

    const CString& operator=(const CString& s); // operator= member fucntion

    int GetLength() const;

    void Display() const;
    int m_nLength;
    char* m_pChar;

private:
};