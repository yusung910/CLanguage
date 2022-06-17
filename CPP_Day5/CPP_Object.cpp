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

//화면에 표시할 메뉴의 COORD 객체 값을 세팅한다.
void CObject::SetMenuPos(COORD menuPos) {
    m_cdMenuPos = menuPos;
}
//세팅된 메뉴의 coord 객체 값을 리턴한다.
COORD CObject::GetMenuPos() {
    return m_cdMenuPos;
}

//배경 화면을 그린다
void CObject::DrawingBackGround() {
	//배경 그리기전 화면을 초기화한다.
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