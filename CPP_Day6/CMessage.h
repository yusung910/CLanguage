#pragma once
#include "CDrawing.h"
#include "CPlayer.h"
#include "CDungeon.h"

class CMessage : public CDungeon
{
public:
    //������
    CMessage();
    //�Ҹ���
    ~CMessage();

    //�÷��̾� ĳ���� ���� �ޱ� ���� �޼��� ���
    void PrintCreatePlayerMsg();

    //�÷��̾� ���� ���
    void PrintPlayerInfoMsg(CPlayer* player);
protected:
private:
};