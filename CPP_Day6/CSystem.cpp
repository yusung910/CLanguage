#include "CSystem.h"

CSystem::CSystem() {
    //생성자
    //화면 크기 조절
    system("mode con: cols=80 lines=30");
    m_nScreenX = 80;
    m_nScreenY = 30;
    PrintBorderLine();
};

CSystem::~CSystem() {

};

void CSystem::PrintBorderLine() {
    SetPos(0, 0);
    cout << "┌";
    SetPos(0, 78);
    cout << "┐";
    SetPos(29, 0);
    cout << "└";
    SetPos(29, 78);
    cout << "┘";
}