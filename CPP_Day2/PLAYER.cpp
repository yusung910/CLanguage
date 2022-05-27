#include <iostream>
#include "player.h"

using namespace std;
//상수 m_nUser 초기화
int CPlayer::m_nUser = 0;

//생성자
CPlayer::CPlayer(int nHp, int nMana, char* cName) {
	//플레이어 초기 체력
	m_nHp = nHp;
	//플레이어 초기 마나
    m_nMana = nMana;
	//플레이어명
    m_cName = (char*) malloc(strlen(cName)+sizeof(char));
	strcpy(m_cName, cName);
	//플레이어 위치(X)
	m_nXpos = 0;
	//플레이어 위치(Y)
	m_nYpos = 0;
	//플레이어 수 증가
	m_nUser++;
}

//소멸자
CPlayer::~CPlayer() {
    //동적으로 생성한 배열을 해제한다
    free(m_cName);
	//플레이어가 제거 되면 플레이어 수를 하나 줄인다
	m_nUser--;
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
void CPlayer::ShowPos() {
	printf("X: %d, Y: %d", m_nXpos, m_nYpos);
}
