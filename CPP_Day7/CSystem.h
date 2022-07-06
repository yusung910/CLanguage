#pragma comment(lib, "Winmm.lib")
#include <stdio.h>
#include <conio.h>
#include "Drawing.h"
#include "Player.h"
#include "Skill.h"

enum E_MAIN_MENU {
    E_NEW_START = 0,
    E_CONTINUE,
    E_CREDIT,
};
class CSystem : public Drawing {
public:
    //������
    CSystem();
    //�Ҹ���
    ~CSystem();
    //�⺻ ��� ����
    void InitBasicDisplayArea();
    //���� ���� �޴�
    void ShowMainMenu();

    //�÷��̾� ����
    void CreatePlayerObject();

    //���� �÷��� ����
    void PlayGame();

protected:
    //�÷��̾ü
    Player* m_player;
	//�ʴ� ������ ��
	int m_nFrame = 600;
private:

};