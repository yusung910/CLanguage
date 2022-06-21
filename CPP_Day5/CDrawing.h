#ifndef __DRAWING_H_
#define __DRAWING_H_

#include "CObject.h"
#include "CMonster.h"
#include "CUser.h"
#include "CSkill.h"

class CDrawing {
public:
    //����� �����ϴ� �Լ�
    void SetBackground();


    //���� �߻� �� ������ ���� ������ ���
	void PrintOfCombatInfo(CUser* user);
    void PrintOfCombatInfo(CMonster* monster);

    //������ ����� �� �ִ� ��ų ������ ����Ѵ�.
    void PrintUserSkillList(CSkill* skill);

	//������ ����� ����� ����Ѵ�.
	void PrintUserSkillAttack(CUser* user, CMonster* monster);

	//���Ͱ� ������ ������ ����Ѵ�
	void PrintMonsterAttack(CUser* user, CMonster* monster);

    //���� ���� �޼��� ���
    void PrintCombatRslt(CUser* user, CMonster* monster);

	//���������� ǥ���� ��ü ����
	void SetMsgPos(COORD pos);

    //����ϱ� ���� ��ġ�� �����ϴ� ����.
    COORD m_cdMsgPos;

	//���� ��ü
	CUser* user;

	//���� ��ü
	CMonster* monster;
protected:
private:
};
#endif