#include <iostream>
#include "CMonster.h"

using namespace std;

//������
CMonster::CMonster()
{
    m_nType = E_C_MONSTER;
}

//�Ҹ���
CMonster::~CMonster()
{

}
//���� ������ ����ġ�� ����Ͽ� �����Ѵ�.
int CMonster::GetMonsterExp() {
    return 0;
}
//���� ������ ȭ�鿡 ǥ��
void CMonster::Display() {

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
}

void CMonster::Attack() {
    //����!
}