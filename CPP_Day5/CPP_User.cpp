#include <iostream>
#include "CUser.h"

using namespace std;

CUser::CUser() {
    //������
    init();
	//cout << "CUser :: ��ü ������" << endl;
}

CUser::~CUser() {
    //�Ҹ���
	//�����迭���� �Ҹ��Ѵ�
	//cout << "CUser :: ��ü �Ҹ���" << endl;
}

int CUser::Attack() {
    //����
	return 0;
}

void CUser::Display() {
    //ȭ�� ǥ��
    m_cdMenuPos.Y += 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdMenuPos);
    cout << "[ĳ���� ����]";
    m_cdMenuPos.Y += 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdMenuPos);
    cout << "ĳ����: " << m_cName;
    m_cdMenuPos.Y += 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdMenuPos);
    cout << "ü�� : " << m_nHP;
    m_cdMenuPos.Y += 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdMenuPos);
    cout << "���ݷ� : " << m_Damage;
    m_cdMenuPos.Y += 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdMenuPos);
    cout << "���� : " << m_nLEVEL;
}

void CUser::init() {
    //�ʱ� ����
    m_nExp = 0;
    //ü��
    m_nHP = 100;
    //����
    m_nMana = 20;
    //����
    m_nLEVEL = 1;
    //��
    m_Str = 5;
    //����
    m_Int = 5;
    //��ø
    m_Dex = 5;
    //���ݷ�
    m_Damage = 5;
	//��ü Ÿ�� ����
	m_nType = TYPE::E_C_USER;
}

void CUser::Move() {
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdPos);
	if (m_cdPos.X < 70) {
		cout << "*<-(" << m_cName << ")";
	}
	else {
		cout << "(" << m_cName << ")->*";
	}
    
}