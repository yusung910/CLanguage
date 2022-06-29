#pragma once
#include "CDrawing.h"
#include "CMessage.h"
#include "CPlayer.h"
#include "CMonster.h"

class CSystem : public CMessage{
public:
    //������
    CSystem();
    //�Ҹ���
    ~CSystem();
	//����ȭ�� �޴� ���ñ��
	void SelectedMainMenu();
	//�÷��̾� ĳ���� ����
	void CreatePlayerData();
    //���� ������ �ҷ�����
    void LoadPlayerData();
    //���� �÷��� ����
    void PlayGame();
    //�÷��̾� �̵�
    void MovePlayer(COORD cdPrevPos, COORD cdNextPos);

private:

protected:
    CPlayer* o_player;
};