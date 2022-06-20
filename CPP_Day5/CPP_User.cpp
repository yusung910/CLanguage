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
    //�⺻ ���ݷ°� ��(10�ۼ�Ʈ)�� ����� �������� ����Ͽ� �����Ѵ�.
	return m_Damage + (m_Str * 0.1);
}

void CUser::Display() {

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