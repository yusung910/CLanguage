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
    cout << "�ּ� �� " << this <<" ���� ���� ���� ���" << endl;
	cout << "�̸� : " << m_cName << endl;
    cout << "��� : " << m_nLife << ", �����ü ����: " << m_nPilotType << ", ��ź �� : " << m_nBomb  << ", ���� : " << m_nRankScore << endl;
}

char* CPilot::GetName() {
	return m_cName;
}

void CPilot::SetName(const char* s) {
	int nTmpNameLength = strlen(s);

	//ĳ���͸� ���� �迭 ����
	m_cName = new char[nTmpNameLength + 1];
	strcpy(m_cName, s);
}

//// ������ ���۷����� �Ͽ� ���ߴ��Թ��� ���� ( unit1 = unit2 = unit3 )                               
const CPilot& CPilot::operator=(const CPilot& p)
{
	cout << this << " operator= ����Լ�\n";

	if (&p == this) return *this;

	if (m_cName)
	{
		delete m_cName;
		m_cName = NULL;
	}
	m_cName = new char[strlen(p.m_cName) + 1];
	//���� �ʱ�ȭ
	m_nRankScore = 0;
	//��ŷ ��� ���Ϸ��� ����
	::strcpy(m_cName, p.m_cName);

	return *this;
}