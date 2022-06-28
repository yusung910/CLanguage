#include "CPlayer.h"

//생성자
CPlayer::CPlayer() {
    //플레이어의 스텟을 5로 초기화 한다.
    memset(m_nStat, 5, E_PLAYER_STAT::E_STAT_CNT);
}

//소멸자
CPlayer::~CPlayer() {

}
