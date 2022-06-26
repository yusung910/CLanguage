#include "CSystem.h"

CSystem::CSystem() {
    //생성자
    //화면 크기 조절
    system("mode con: cols=80 lines=30");

    //화면의 기본 테두리를 그린다.
    PrintDisplayRound();
};

CSystem::~CSystem() {

}