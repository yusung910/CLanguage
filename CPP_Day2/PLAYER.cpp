#include <iostream>
#include "player.h"

using namespace std;
//������
CPlayer::CPlayer(int nHp, int nMana, char* cName) {
	m_nHp = nHp;
    m_nMana = nMana;
	strcpy(m_cName, cName);
}

//�Ҹ���
CPlayer::~CPlayer() {

}

void CPlayer::SetHp(int dmg) {

}
void CPlayer::SetMana(int dmg) {
}