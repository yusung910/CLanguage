#pragma once
#include "CDrawing.h"
#include "CPlayer.h"

class CMessage : public CDrawing
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