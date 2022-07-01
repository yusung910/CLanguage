#pragma comment(lib, "winmm.lib")
#include "CDrawing.h"
#include "CPlayer.h"
#include "CMonster.h"
#include "CCombat.h"

class CSystem : public CCombat{
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