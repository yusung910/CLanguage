#include "CPlayer.h"

//������
CPlayer::CPlayer() {
    //�÷��̾��� ������ 5�� �ʱ�ȭ �Ѵ�.
    memset(m_nStat, 5, E_PLAYER_STAT::E_STAT_CNT);
}

//�Ҹ���
CPlayer::~CPlayer() {

}
