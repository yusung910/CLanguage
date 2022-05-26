#include <iostream>
#include "player.h"

using namespace std;
//생성자
CPlayer::CPlayer(int nHp, int nMana, char* cName) {
	m_nHp = nHp;
    m_nMana = nMana;
    m_cName = (char*) malloc(strlen(cName)+sizeof(char));
    strcpy(m_cName, cName);
}

//소멸자
CPlayer::~CPlayer() {
    //동적으로 생성한 배열을 해제한다
    free(m_cName);
}

void CPlayer::SetHp(int dmg) {
    m_nHp =+ dmg;
}
void CPlayer::SetMana(int dmg) {
    m_nMana = +dmg;
}
void CPlayer::ShowStatus() {
    printf("캐릭터 명: %s\n", m_cName);
    printf("HP: %d\n", m_nHp);
    printf("MANA: %d\n", m_nMana);
}