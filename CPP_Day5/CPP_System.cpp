#include <iostream>
#include "CSystem.h"

using namespace std;

CSystem::CSystem() {
    //생성자
    //화면 크기 조절
    system("mode con: cols=80 lines=30");

    drawingObj = new CDrawing;
    user = new CUser;
    monster = new CMonster;
    battle = new CBattle;

    GameUserCharacterCreate();
}

CSystem::~CSystem() {
    //소멸자
    //동적배열들을 소멸한다
    //cout << "CUser :: 객체 소멸자" << endl;
}
void CSystem::GameUserCharacterCreate() {
    //배경그리기
    drawingObj->SetBackground();

    //게임 종료 여부
    bool b_GameEndFlag = 1;

    //사용자 플레이어 명을 받는다.
    char userName[20];
    drawingObj->gotoxy(5, 13);
    cout << "캐릭터명을 입력한 후 Enter키를 입력하여주세요.(10글자 이내) : ";
    scanf(" %s", userName);
    user->SetName(userName);

    GameBasicLoad();
};

void CSystem::GameBasicLoad() {

    //배경그리기
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
    //초기 유저의 위치를 세팅
    COORD cdUserPos = user->GetUserPos();

    while (b_GameEndFlag) {
        //사용자 입력 키
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