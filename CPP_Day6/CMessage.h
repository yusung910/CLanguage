#pragma once
#include "CDrawing.h"
#include "CPlayer.h"

class CMessage : public CDrawing
{
public:
    //생성자
    CMessage();
    //소멸자
    ~CMessage();

    //플레이어 캐릭터 명을 받기 위한 메세지 출력
    void PrintCreatePlayerMsg();

    //플레이어 정보 출력
    void PrintPlayerInfoMsg(CPlayer* player);
protected:
private:
};