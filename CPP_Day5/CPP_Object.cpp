#include <iostream>
#include "CObject.h"

using namespace std;

//������
CObject::CObject()
{
	m_nType = E_C_NONE;
}

CObject::~CObject()
{
    //�Ҹ���
    if (m_nName)
    {
        delete m_nName;
        m_nName = NULL;
    }
}
void CObject::SetName(const char* s) {
    //���� �� ����
    int nTmpNameLength = strlen(s);
    //ĳ���͸� ���� �迭 ����
    m_nName = new char[nTmpNameLength + 1];
    strcpy(m_nName, s);
}

