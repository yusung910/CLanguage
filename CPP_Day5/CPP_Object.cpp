#include <iostream>
#include "CObject.h"

using namespace std;
int CObject::m_nObjCnt = 0;
//������
CObject::CObject()
{
	m_nType = E_C_NONE;
	//��ü ������ ����� static ������ ���� ����
	m_nObjCnt++;
	//cout << "��ü ������" << endl;
}

CObject::~CObject()
{
    //�Ҹ���
    if (m_cName)
    {
        delete m_cName;
		m_cName = NULL;
    }
	//��ü ������ ����� static ������ ���� ����
	//cout << "��ü �Ҹ���" << endl;
}
void CObject::SetName(const char* s) {
    //���� �� ����
    int nTmpNameLength = strlen(s);
    //ĳ���͸� ���� �迭 ����
	m_cName = new char[nTmpNameLength + 1];
    strcpy(m_cName, s);
}

char* CObject::GetName() {
	return m_cName;
}

void CObject::SetPos(COORD pos) {
	m_cdPos = pos;
}

COORD CObject::GetPos() {
	return m_cdPos;
}