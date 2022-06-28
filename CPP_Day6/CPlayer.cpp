#include "CPlayer.h"

//생성자
CPlayer::CPlayer() {
    //플레이어의 스텟을 5로 초기화 한다.
    memset(m_nStat, 5, E_PLAYER_STAT::E_STAT_CNT);
}

//소멸자
CPlayer::~CPlayer() {

}

void CPlayer::SetPlayerPos(COORD pos) {
    cdPosPlayer = pos;
}

void CPlayer::SetPlayerPos(int x, int y) {
    COORD tmp = { x, y };
    cdPosPlayer = tmp;
}
//플레이어 위치 값을 가져온다.
COORD CPlayer::GetPlayerPos() {
    return cdPosPlayer;
}
