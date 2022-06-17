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

//ȭ�鿡 ǥ���� �޴��� COORD ��ü ���� �����Ѵ�.
void CObject::SetMenuPos(COORD menuPos) {
    m_cdMenuPos = menuPos;
}
//���õ� �޴��� coord ��ü ���� �����Ѵ�.
COORD CObject::GetMenuPos() {
    return m_cdMenuPos;
}

//��� ȭ���� �׸���
void CObject::DrawingBackGround() {
	//��� �׸����� ȭ���� �ʱ�ȭ�Ѵ�.
	cout << "\x1B[2J\x1B[H";
	int x = 150;
	int y = 50;
	COORD m_backPos = { 0, 0 };
	for (int i = 0; i < 150; i++) {
		m_backPos.X = i;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_backPos);
		cout << "*";
		//Sleep(1);
	}

	for (int j = 0; j < 50; j++) {
		m_backPos.Y = j;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_backPos);
		cout << "*";
		//Sleep(1);
	}

	for (int a = 149; a > 0 ; a--) {
		m_backPos.X = a;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_backPos);
		cout << "*";
		//Sleep(1);
	}

	for (int b = 49; b > 0; b--) {
		m_backPos.Y = b;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_backPos);
		cout << "*";
		//Sleep(1);
	}
}