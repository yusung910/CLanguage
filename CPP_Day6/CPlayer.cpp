#include "CPlayer.h"

//������
CPlayer::CPlayer() {
    //�÷��̾��� ������ 5�� �ʱ�ȭ �Ѵ�.
    memset(m_nStat, 5, E_PLAYER_STAT::E_STAT_CNT);
}

//�Ҹ���
CPlayer::~CPlayer() {

}

void CPlayer::SetPlayerPos(COORD pos) {
    cdPosPlayer = pos;
}

void CPlayer::SetPlayerPos(int x, int y) {
    COORD tmp = { x, y };
    cdPosPlayer = tmp;
}
//�÷��̾� ��ġ ���� �����´�.
COORD CPlayer::GetPlayerPos() {
    return cdPosPlayer;
}
