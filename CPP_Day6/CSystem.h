#pragma once
#include "CDrawing.h"
#include "CMessage.h"
#include "CPlayer.h"

class CSystem : public CMessage{
public:
    //������
    CSystem();
    //�Ҹ���
    ~CSystem();
	//����ȭ�� �޴� ���ñ��
	void SelectedMainMenu();
	//
	void CreatePlayerData();
    void LoadPlayerData();

private:

protected:
    CPlayer* o_player;
};