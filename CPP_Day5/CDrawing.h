#ifndef __DRAWING_H_
#define __DRAWING_H_

#include "CObject.h"
#include "CMonster.h"
#include "CUser.h"
#include "CSkill.h"

enum E_BACKGROUND_TYPE {
    VILLAGE = 0,
    DUNGEON,
    STORE,
    INN,
};

class CDrawing {
public:
    //������ �Ҹ���.
    CDrawing();
    ~CDrawing();
    //����� �����ϴ� �Լ�
    void SetBackground();

    void PrintOfHome();
    //�簢�� �׸��� �Լ�
    void PrintSquare(COORD cdStartPos, COORD cdEndPos);

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

    //���� �׸���
    void PrintDungeon();

	//���������� ǥ���� ��ü ����
	void SetMsgPos(COORD pos);

    //�÷��̾ ��ġ�ϰ� �ִ� �ǹ��� �����´�.
    int GetUserPosBuild(COORD pos, int nCurrentMap);

	//���������� �޼��� ���
	void PrintOutInnMsg(CUser* user);

	//��ġ�� �����Ѵ�
	void gotoxy(int x, int y);
    void gotoxy(COORD pos);

    //���� �ǹ��� �׸���.
    void PrintBuilding(COORD cdStartPos, COORD cdEndPos);

    //�޼��� ����ϴ� ������ �ʱ�ȭ�Ѵ�.
    void ClearMsgArea();

    //����ϱ� ���� ��ġ�� �����ϴ� ����.
    COORD m_cdMsgPos;

    //���� ��ǥ
    COORD cdInnStart = { 5, 10 };
    COORD cdInnEnd = { 25, 20 };
    

    //������ǥ
    COORD cdStoreStart = { 30, 10 };
    COORD cdStoreEnd = { 50, 20 };

    //����� ��ǥ
    COORD cdDungeonStart = { 55, 10 };
    COORD cdDungeonEnd = { 75, 20 };

    //����� �ⱸ ��ǥ
    COORD cdExitDungeonStart = { 0, 0 };
    COORD cdExitDungeonEnd = { 10, 10 };

	int nArryMap[80][30];
protected:
private:

};
#endif