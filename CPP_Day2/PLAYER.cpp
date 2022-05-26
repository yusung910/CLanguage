#include <iostream>
#include "player.h"

using namespace std;
//持失切
CPlayer::CPlayer(int nHp, int nMana, char* cName) {
	m_nHp = nHp;
    m_nMana = nMana;
	strcpy(m_cName, cName);
}

//社瑚切
CPlayer::~CPlayer() {

}

void CPlayer::SetHp(int dmg) {

}
void CPlayer::SetMana(int dmg) {
}