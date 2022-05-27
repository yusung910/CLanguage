#include <iostream>
#include "player.h"

using namespace std;
//��� m_nUser �ʱ�ȭ
int CPlayer::m_nUser = 0;

//������
CPlayer::CPlayer(int nHp, int nMana, char* cName) {
	//�÷��̾� �ʱ� ü��
	m_nHp = nHp;
	//�÷��̾� �ʱ� ����
    m_nMana = nMana;
	//�÷��̾��
    m_cName = (char*) malloc(strlen(cName)+sizeof(char));
	strcpy(m_cName, cName);
	//�÷��̾� ��ġ(X)
	m_nXpos = 0;
	//�÷��̾� ��ġ(Y)
	m_nYpos = 0;
	//�÷��̾� �� ����
	m_nUser++;
}

//�Ҹ���
CPlayer::~CPlayer() {
    //�������� ������ �迭�� �����Ѵ�
    free(m_cName);
	//�÷��̾ ���� �Ǹ� �÷��̾� ���� �ϳ� ���δ�
	m_nUser--;
}

void CPlayer::SetHp(int dmg) {
    m_nHp =+ dmg;
}
void CPlayer::SetMana(int dmg) {
    m_nMana = +dmg;
}
void CPlayer::ShowStatus() {
    printf("ĳ���� ��: %s\n", m_cName);
    printf("HP: %d\n", m_nHp);
    printf("MANA: %d\n", m_nMana);
}
void CPlayer::ShowPos() {
	printf("X: %d, Y: %d", m_nXpos, m_nYpos);
}
