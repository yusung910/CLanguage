#include <iostream>
#include "CSystem.h"

using namespace std;

CSystem::CSystem() {
    //������
    //ȭ�� ũ�� ����
    system("mode con: cols=80 lines=30");

    drawingObj = new CDrawing;
    user = new CUser;
    monster = new CMonster;
    battle = new CBattle;

    GameUserCharacterCreate();
}

CSystem::~CSystem() {
    //�Ҹ���
    //�����迭���� �Ҹ��Ѵ�
    //cout << "CUser :: ��ü �Ҹ���" << endl;
}
void CSystem::GameUserCharacterCreate() {
    //���׸���
    drawingObj->SetBackground();

    //���� ���� ����
    bool b_GameEndFlag = 1;

    //����� �÷��̾� ���� �޴´�.
    char userName[20];
    drawingObj->gotoxy(5, 13);
    cout << "ĳ���͸��� �Է��� �� EnterŰ�� �Է��Ͽ��ּ���.(10���� �̳�) : ";
    scanf(" %s", userName);
    user->SetName(userName);

    GameBasicLoad();
};

void CSystem::GameBasicLoad() {

    //���׸���
    drawingObj->SetBackground();

    switch (n_currentBg) {
    case E_BACKGROUND_TYPE::VILLAGE:
    case E_BACKGROUND_TYPE::INN:
    case E_BACKGROUND_TYPE::STORE:
        drawingObj->PrintOfHome();
        break;
    case E_BACKGROUND_TYPE::DUNGEON:
        drawingObj->PrintDungeon();
    }

    drawingObj->gotoxy(user->GetUserPos());
    user->Move();

    GamePlaying();
}

void CSystem::GamePlaying() {
    //�ʱ� ������ ��ġ�� ����
    COORD cdUserPos = user->GetUserPos();

    while (b_GameEndFlag) {
        //����� �Է� Ű
        int inputKey = _getch();

        drawingObj->gotoxy(cdUserPos);

        printf(" ");

        if (inputKey == 224) {
            inputKey = _getch();
            switch (inputKey) {
            case E_DIR_KEY::UP:
                cdUserPos.Y -= 1;
                if (drawingObj->nArryMap[cdUserPos.X][cdUserPos.Y] == 1) {
                    cdUserPos.Y += 1;
                }
                break;
            case E_DIR_KEY::DOWN:
                cdUserPos.Y += 1;
                if (drawingObj->nArryMap[cdUserPos.X][cdUserPos.Y] == 1) {
                    cdUserPos.Y -= 1;
                }
                break;
            case E_DIR_KEY::LEFT:
                cdUserPos.X -= 1;
                if (drawingObj->nArryMap[cdUserPos.X][cdUserPos.Y] == 1) {
                    cdUserPos.X += 1;
                }
                break;
            case E_DIR_KEY::RIGHT:
                cdUserPos.X += 1;
                if (drawingObj->nArryMap[cdUserPos.X][cdUserPos.Y] == 1) {
                    cdUserPos.X -= 1;
                }
                break;
            }

            drawingObj->gotoxy(cdUserPos);

            user->Move();

            int n_loadMap = drawingObj->GetUserPosBuild(cdUserPos, n_currentBg);
            if (n_currentBg != n_loadMap) {
                n_currentBg = n_loadMap;
                switch (n_currentBg) {
                case E_BACKGROUND_TYPE::DUNGEON:
                    user->SetUserPos(10, 10);
                    GameBasicLoad();
                    break;
                case E_BACKGROUND_TYPE::VILLAGE:
                    user->SetUserPos(10, 25);
                    GameBasicLoad();
                    break;
                }
                
            }
        }
    }
}