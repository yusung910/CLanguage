#include <iostream>
#include "CMonster.h"

using namespace std;

//������
CMonster::CMonster()
{
    m_nType = E_C_MONSTER;
	//���� ���� �ʱ�ȭ
	init();
	//cout << "CMonster :: ��ü ������" << endl;
}

//�Ҹ���
CMonster::~CMonster()
{
	//cout << "CMonster :: ��ü �Ҹ���" << endl;
}
//���� ������ ����ġ�� ����Ͽ� �����Ѵ�.
int CMonster::GetMonsterExp() {
    return 0;
}
//���� ������ ȭ�鿡 ǥ��
void CMonster::Display() {
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdMenuPos);
	cout << "[���� ����]";
    m_cdMenuPos.Y += 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdMenuPos);
	cout << "�̸� : " << m_cName; 
    m_cdMenuPos.Y += 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdMenuPos);
	cout << "ü�� : " << m_nHP;
    m_cdMenuPos.Y += 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), m_cdMenuPos);
	cout << "���ݷ� : " << m_nAttack;
}
//���� ��ü �ʱ�ȭ �Լ�
void CMonster::init() {
    m_nMobInfo = (rand() % MONSTER_MAX) + 1;
    //������ ����ġ
    m_nMonsterExp = 0;
    //������ ü��
    m_nHP = (rand() % 50) + 50;
    //������ ����
    m_nMana = 0;
    //������ ����
    m_nLEVEL = 0;
    //������ ���ݷ�
    m_nAttack = (rand() % 10 ) + 1;
	//��ü Ÿ�� ����
	m_nType = TYPE::E_C_MONSTER;
	//���͸� ����
	SetMonsterName();
}
char* CMonster::SetMonsterName() {
	m_nMobInfo = (rand() % E_MONSTER_TYPE::MONSTER_MAX) + 1;
	switch (m_nMobInfo) {
	case E_MONSTER_TYPE::COBOLT:
		SetName("�ں�Ʈ");
		break;
	case E_MONSTER_TYPE::GOBLINE:
		SetName("���");
		break;
	case E_MONSTER_TYPE::GREMLINE:
		SetName("�׷���");
		break;
	case E_MONSTER_TYPE::ORC:
		SetName("��ũ");
		break;
	case E_MONSTER_TYPE::TROLL:
		SetName("Ʈ��");
		break;
	}
	return m_cName;
}
int CMonster::Attack() {
    //����!
	return 0;
}
//��ų ����� ȣ���Ѵ�.
void CMonster::ShowSkillList() {
}

//���� �̵� �Լ�
void CMonster::Move() {

}