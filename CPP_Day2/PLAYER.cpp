#include <iostream>
#include "player.h"

using namespace std;
//������
CPlayer::CPlayer(int nHp, int nMana, char* cName) {
	m_nHp = nHp;
    m_nMana = nMana;
    m_cName = (char*) malloc(strlen(cName)+sizeof(char));
    strcpy(m_cName, cName);
}

//�Ҹ���
CPlayer::~CPlayer() {
    //�������� ������ �迭�� �����Ѵ�
    free(m_cName);
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