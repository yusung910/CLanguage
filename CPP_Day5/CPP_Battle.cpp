#include <iostream>
#include <windows.h>
#include <conio.h>
#include "CObject.h"
#include "CMonster.h"
#include "CUser.h"
#include "CBattle.h"
#include "CDrawing.h"

using namespace std;

void CBattle::DoBattle(CUser* user, CMonster* monster, COORD pos) {

	CDrawing* drawingObj = new CDrawing;
	//���׸���
	drawingObj->SetBackground();

	int doFightFlag = 1;
	//���� ������ �ʱ�ȭ �Ѵ�.
	monster->init();


	//����� ���� ���Ƿ� ������ ���Ϳ� ���� ��ü��
	//����ĳ����(dynamic_cast)�ؼ� �Ҵ��Ѵ�.
	CSkill* tmpUserSkillObj = dynamic_cast<CSkill*>(user);

	//���� ���� ��ġ ����
	COORD cdMonsterInfoPos = { 90, 10 };
	drawingObj->SetMsgPos(cdMonsterInfoPos);
	drawingObj->PrintOfCombatInfo(monster);

	//���� ���� ��ġ ���� �� ���
	COORD cdUserInfo = { 30, 9 };
	drawingObj->SetMsgPos(cdUserInfo);
	drawingObj->PrintOfCombatInfo(user);
	//���� �޼��� �����ġ
	COORD cdCombatMsgPos = { 70, 25 };
	//�ý��� �޼��� ��� ��ġ
	COORD cdSystemMsgPos = { 35, 25 };

	drawingObj->SetMsgPos(cdSystemMsgPos);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cdSystemMsgPos);
	//���� ���θ� ���´�.
	cout << "�ο�ðڽ��ϱ�? (1. ����, 2.��������) :";

	while (doFightFlag) {

		int intputFightMenu = _getch();

		if (intputFightMenu == 49) {

			//ȭ���� �ʱ�ȭ �ϰ� ������ ������ ������ ���� ������ ȭ�鿡 ǥ���Ѵ�.
			//���׸���
			drawingObj->SetBackground();

			//����, ���� ���� ���
			drawingObj->SetMsgPos(cdUserInfo);
			drawingObj->PrintOfCombatInfo(user);
			drawingObj->SetMsgPos(cdMonsterInfoPos);
			drawingObj->PrintOfCombatInfo(monster);

			//������ ����� �� �ִ� ��� ��� ���
			drawingObj->SetMsgPos(cdSystemMsgPos);
			drawingObj->PrintUserSkillList(tmpUserSkillObj);

			//��ų �����ϴ� ����
			int n_doUseSkillFlag = 1;

			while (n_doUseSkillFlag) {

				//����ڰ� ���ݽ�ų�� �����Ѵ�.
				int n_useSkill = (_getch() - 48);

				//����ڰ� �Է��� ���� �ش��ϴ� ��ų���� �����´�.
				char* useSkill = tmpUserSkillObj->GetSkillName(n_useSkill);

				//���׸���
				drawingObj->SetBackground();

				//����, ���� ���� ���
				drawingObj->SetMsgPos(cdUserInfo);
				drawingObj->PrintOfCombatInfo(user);
				drawingObj->SetMsgPos(cdMonsterInfoPos);
				drawingObj->PrintOfCombatInfo(monster);

				if (useSkill == NULL) {
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cdSystemMsgPos);
					cout << "����� �� ���� ����Դϴ�. �ٽ� �Է��Ͽ��ּ���.";
					drawingObj->PrintUserSkillList(tmpUserSkillObj);
				}
				else {
					//���׸���
					drawingObj->SetBackground();

					//�÷��̾ ����� ���� ��ų�� �����Ѵ�.
					user->SetUsingSkill(n_useSkill);

					//�÷��̾��� ���ݳ����� ȭ�鿡 ����Ѵ�.
					drawingObj->SetMsgPos(cdCombatMsgPos);
					drawingObj->PrintUserSkillAttack(user, monster);

					//������ ü���� �����Ѵ�.
					monster->SetMonsterHP(monster->GetMonsterHP() - user->Attack());

					//������ ���ݳ����� ȭ�鿡 ����Ѵ�.
					drawingObj->PrintMonsterAttack(user, monster);
					//�÷��̾��� ü���� �����Ѵ�.
					user->SetUserHP(user->GetUserHp() - monster->Attack());

					//����, ���� ���� ���
					drawingObj->SetMsgPos(cdUserInfo);
					drawingObj->PrintOfCombatInfo(user);
					drawingObj->SetMsgPos(cdMonsterInfoPos);
					drawingObj->PrintOfCombatInfo(monster);

					//��� ��� ���� ���
					drawingObj->SetMsgPos(cdSystemMsgPos);
					drawingObj->PrintUserSkillList(tmpUserSkillObj);

					//�÷��̾� �Ǵ� ������ ü�� ���¸� Ȯ���Ѵ�
					if (user->GetUserHp() <= 0 && monster->GetMonsterHP() <= 0) {
						//�÷��̾ �׾��� ���.
						drawingObj->SetMsgPos(cdSystemMsgPos);
						drawingObj->PrintCombatRslt(user, monster);

						//��ų ��� ����
						n_doUseSkillFlag = 0;

						//���� ����
						doFightFlag = 0;
					}
					else if (monster->GetMonsterHP() <= 0) {
						//���Ͱ� �׾��� ���.
						//���׸���
						drawingObj->SetBackground();

						//����, ���� ���� ���
						drawingObj->SetMsgPos(cdUserInfo);
						drawingObj->PrintOfCombatInfo(user);
						drawingObj->SetMsgPos(cdMonsterInfoPos);
						drawingObj->PrintOfCombatInfo(monster);

						//���� ��� ���
						drawingObj->SetMsgPos(cdSystemMsgPos);
						drawingObj->PrintCombatRslt(user, monster);

						//��ų ��� ����
						n_doUseSkillFlag = 0;

						//���� ����
						doFightFlag = 0;
					}
				}
			}
		}
		else if (intputFightMenu == 50) {
			//���׸���
			drawingObj->SetBackground();

			user->SetPos(pos);
			user->Move();
			doFightFlag = 0;
		}
	}
}