#ifndef __DRAWING_H_
#define __DRAWING_H_

#include "CMonster.h"
#include "CUser.h"
#include "CSkill.h"

class CDrawing {
public:
    //����� �����ϴ� �Լ�
    void SetBackground();
    //������� m_cdDrawingPos�� ����
    void SetCdDrawingPos(COORD pos);

    //���������� ����Ѵ�.
    void PrintOfInfo(CMonster* monster);

    //���������� ����Ѵ�.
    void PrintOfInfo(CUser* user);

    //������ ����� �� �ִ� ��ų ������ ����Ѵ�.
    void PrintUserSkilList(CSkill* skill);

    //���õ� ������� m_cdDrawingPos�� ����
    COORD GetCdDrawingPos();

    //����ϱ� ���� ��ġ�� �����ϴ� ����.
    COORD m_cdDrawingPos;
protected:
private:
};
#endif