#include <iostream>
#include <windows.h>
#include <conio.h>
#include "CObject.h"
#include "CMonster.h"
#include "CUser.h"
#include "CBattle.h"
#include "CDrawing.h"

using namespace std;
CBattle::CBattle() {
}

CBattle::~CBattle() {

}

void CBattle::DoBattle(CDrawing* drawingObj, CUser* user, CMonster* monster) {

	//���׸���
	drawingObj->SetBackground();

	int doFightFlag = 1;
	//���� ������ �ʱ�ȭ �Ѵ�.
	monster->init();

	//����� ���� ���Ƿ� ������ ���Ϳ� ���� ��ü��
	//����ĳ����(dynamic_cast)�ؼ� �Ҵ��Ѵ�.
	//user->getS
	//CSkill* tmpUserSkillObj = dynamic_cast<CSkill*>(user);

	drawingObj->PrintOfCombatInfo(monster);


	drawingObj->PrintOfCombatInfo(user);
	//���� �޼��� �����ġ
	COORD cdCombatMsgPos = { 50, 25 };
	//�ý��� �޼��� ��� ��ġ
	COORD cdSystemMsgPos = { 15, 25 };

	drawingObj->gotoxy(cdSystemMsgPos);
	//���� ���θ� ���´�.
	cout << "�ο�ðڽ��ϱ�? (1. ����, 2.��������) :";

	while (doFightFlag) {

		int intputFightMenu = _getch();

		if (intputFightMenu == 49) {

			//ȭ���� �ʱ�ȭ �ϰ� ������ ������ ������ ���� ������ ȭ�鿡 ǥ���Ѵ�.

			drawingObj->PrintOfCombatInfo(user);
			drawingObj->PrintOfCombatInfo(monster);

			//������ ����� �� �ִ� ��� ��� ���
			drawingObj->gotoxy(cdSystemMsgPos);
			drawingObj->PrintUserSkillList(user);

			//��ų �����ϴ� ����
			int n_doUseSkillFlag = 1;

			while (n_doUseSkillFlag) {

				//����ڰ� ���ݽ�ų�� �����Ѵ�.
				int n_useSkill = (_getch() - 48);

				//����ڰ� �Է��� ���� �ش��ϴ� ��ų���� �����´�.
				char* useSkill = user->GetSkillName(n_useSkill);

				//����, ���� ���� ���
				drawingObj->PrintOfCombatInfo(user);
				drawingObj->PrintOfCombatInfo(monster);

				if (useSkill == NULL) {
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cdSystemMsgPos);
					cout << "����� �� ���� ����Դϴ�. �ٽ� �Է��Ͽ��ּ���.";
					drawingObj->PrintUserSkillList(user);
				}
				else {
					//���׸���
					drawingObj->SetBackground();

					//�÷��̾ ����� ���� ��ų�� �����Ѵ�.
					user->SetUsingSkill(n_useSkill);

					//�÷��̾��� ���ݳ����� ȭ�鿡 ����Ѵ�.
					drawingObj->gotoxy(cdCombatMsgPos);
					drawingObj->PrintUserSkillAttack(user, monster);

					//������ ü���� �����Ѵ�.
					monster->SetMonsterHP(monster->GetMonsterHP() - user->Attack());

					//������ ���ݳ����� ȭ�鿡 ����Ѵ�.
					drawingObj->PrintMonsterAttack(user, monster);
					//�÷��̾��� ü���� �����Ѵ�.
					user->SetUserHP(user->GetUserHp() - monster->Attack());

					//����, ���� ���� ���
					drawingObj->PrintOfCombatInfo(user);
					drawingObj->PrintOfCombatInfo(monster);

					//��� ��� ���� ���
					drawingObj->gotoxy(cdSystemMsgPos);
					drawingObj->PrintUserSkillList(user);

					//�÷��̾� �Ǵ� ������ ü�� ���¸� Ȯ���Ѵ�
					if (user->GetUserHp() <= 0 && monster->GetMonsterHP() <= 0) {
						//�÷��̾ �׾��� ���.
						drawingObj->gotoxy(cdSystemMsgPos);
						drawingObj->PrintCombatRslt(user, monster);

						//��ų ��� ����
						n_doUseSkillFlag = 0;

						//���� ����
						doFightFlag = 0;
                        //��� ȭ���� ���� ���� getch();
                        _getch();
					}
					else if (monster->GetMonsterHP() <= 0) {
						//���Ͱ� �׾��� ���.
						//���׸���
						drawingObj->SetBackground();

						//����, ���� ���� ���
						drawingObj->PrintOfCombatInfo(user);
						drawingObj->PrintOfCombatInfo(monster);

						//���� ��� ���
						drawingObj->gotoxy(cdSystemMsgPos);
						drawingObj->PrintCombatRslt(user, monster);

						//��ų ��� ����
						n_doUseSkillFlag = 0;

						//���� ����
						doFightFlag = 0;

                        //��� ȭ���� ���� ���� getch();
                        _getch();
					}
				}
			}
		}
		else if (intputFightMenu == 50) {
			//���׸���
			drawingObj->SetBackground();

			//user->SetPos(pos);
			user->Move();
			doFightFlag = 0;
		}
	}
}