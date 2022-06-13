#include <iostream>
#include "CObject.h"

using namespace std;

//생성자
CObject::CObject()
{
	m_nType = E_C_NONE;
}

CObject::~CObject()
{
    //소멸자
    if (m_nName)
    {
        delete m_nName;
        m_nName = NULL;
    }
}
void CObject::SetName(const char* s) {
    //몬스터 명 길이
    int nTmpNameLength = strlen(s);
    //캐릭터명 동적 배열 생성
    m_nName = new char[nTmpNameLength + 1];
    strcpy(m_nName, s);
}

