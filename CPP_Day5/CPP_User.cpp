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
	//cout << "CUser :: ��ü �Ҹ���" << endl;
}

void CUser::Attack() {
    //����
}

void CUser::Display() {
    //ȭ�� ǥ��
    cout << "ĳ����: " << m_cName << endl;
    cout << "ü�� : " << m_nHP << ", ���ݷ� : " << m_Damage << endl;
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