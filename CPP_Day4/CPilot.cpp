#include "CPilot.h"
#include <iostream>

using namespace std;

CPilot::CPilot(int nPilotType) : m_nPilotType(nPilotType){
    m_nPower = 1;
    m_nBomb = 2;
    m_nLife = 1;
    m_nRankScore = 0;
    m_UnitType = PILOT;
}

CPilot::~CPilot() {
	if (m_cName)
	{
		delete m_cName;
		m_cName = NULL;
	}
}

void CPilot::Display() {
    cout << "주소 값 " << this <<" 유저 유닛 유형 출력" << endl;
	cout << "이름 : " << m_cName << endl;
    cout << "목숨 : " << m_nLife << ", 비행기체 유형: " << m_nPilotType << ", 폭탄 수 : " << m_nBomb  << ", 점수 : " << m_nRankScore << endl;
}

char* CPilot::GetName() {
	return m_cName;
}

void CPilot::SetName(const char* s) {
	int nTmpNameLength = strlen(s);

	//캐릭터명 동적 배열 생성
	m_cName = new char[nTmpNameLength + 1];
	strcpy(m_cName, s);
}

//// 리턴을 레퍼런스로 하여 다중대입문을 구현 ( unit1 = unit2 = unit3 )                               
const CPilot& CPilot::operator=(const CPilot& p)
{
	cout << this << " operator= 멤버함수\n";

	if (&p == this) return *this;

	if (m_cName)
	{
		delete m_cName;
		m_cName = NULL;
	}
	m_cName = new char[strlen(p.m_cName) + 1];
	//점수 초기화
	m_nRankScore = 0;
	//랭킹 등록 파일럿명 복사
	::strcpy(m_cName, p.m_cName);

	return *this;
}