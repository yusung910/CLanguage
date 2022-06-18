#ifndef __DRAWING_H_
#define __DRAWING_H_

#include "CMonster.h"
#include "CUser.h"

class CDrawing {
public:
    //배경을 세팅하는 함수
    void SetBackground();
    //멤버변수 m_cdDrawingPos를 세팅
    void SetCdDrawingPos(COORD pos);

    //몬스터정보를 출력한다.
    void PrintOfInfo(CMonster* monster);

    //유저정보를 출력한다.
    void PrintOfInfo(CUser* user);
    
    //몬스터와 유저정보를 모두 출력
    void PrintOfInfo(CMonster* monster, CUser* user);

    //세팅된 멤버변수 m_cdDrawingPos를 리턴
    COORD GetCdDrawingPos();


    //출력하기 위한 위치를 저장하는 변수.
    COORD m_cdDrawingPos;
protected:
private:
};
#endif