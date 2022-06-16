#include <iostream>
#include "CObject.h"

using namespace std;
int CObject::m_nObjCnt = 0;
//생성자
CObject::CObject()
{
	m_nType = E_C_NONE;
	//객체 갯수가 저장된 static 변수의 값을 증가
	m_nObjCnt++;
	//cout << "객체 생성자" << endl;
}

CObject::~CObject()
{
    //소멸자
    if (m_cName)
    {
        delete m_cName;
		m_cName = NULL;
    }
	//객체 갯수가 저장된 static 변수의 값을 감소
	//cout << "객체 소멸자" << endl;
}
void CObject::SetName(const char* s) {
    //몬스터 명 길이
    int nTmpNameLength = strlen(s);
    //캐릭터명 동적 배열 생성
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