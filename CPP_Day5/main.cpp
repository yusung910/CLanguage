#include <iostream>
#include <conio.h>
#include <windows.h>
#include "CObject.h"
#include "CMonster.h"
#include "CUser.h"
#include "CDrawing.h"

using namespace std;

enum E_DIR_KEY{
	UP = 72,
	DOWN = 80,
	LEFT = 75,
	RIGHT = 77
};

void main() {
	//ȭ�� ũ�� ����
	system("mode con: cols=150 lines=50");
    CDrawing* drawingObj = new CDrawing;
	CObject* objList[2] = { new CUser, new CMonster };

	//���׸���
    drawingObj->SetBackground();

	//���� ���� ����
	bool b_EndFlag = 1;

	COORD pos;

	pos.X = 30;
	pos.Y = 15;

	//����� �÷��̾� ���� �޴´�.
	char userName[20];
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	cout << "ĳ���͸��� �Է��� �� EnterŰ�� �Է��Ͽ��ּ���.(10���� �̳�) : ";
	scanf(" %s", userName);

	//���� ĳ���͸� �̵��Ѵ�.
	cout << "\x1B[2J\x1B[H";
	//���׸���
    drawingObj->SetBackground();

	objList[0]->SetName(userName);
	objList[0]->SetPos(pos);
	objList[0]->Move();

	while (b_EndFlag) {
		//����� �Է� Ű
		int inputKey = _getch();
		//���� �� Ȯ�� ����� ���� ���� ����
		CONSOLE_SCREEN_BUFFER_INFO presentCur;
		//���� Ŀ�� ��ġ�� �����Ѵ�.
		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &presentCur);

		int n_ProDropMob = (rand() % 50) + 1;
		if (inputKey == 224) {
			inputKey = _getch();
			switch (inputKey) {
			case E_DIR_KEY::UP :
				pos.Y = (pos.Y > 1) ? pos.Y - 1 : 1;
				break;
			case E_DIR_KEY::DOWN :
				pos.Y = (pos.Y < 48) ? pos.Y + 1 : 48;
				break;
			case E_DIR_KEY::LEFT:
				pos.X = (pos.X > 2) ? pos.X - 1 : 2;
				break;
			case E_DIR_KEY::RIGHT:
				pos.X = (pos.X < 140) ? pos.X + 1 : 140;
				break;
			}

			//���׸���
            drawingObj->SetBackground();

            objList[0]->SetPos(pos);
            objList[0]->Move();

			//20�ۼ�Ʈ Ȯ���� �� ��
			if (n_ProDropMob < 10) {
                //���׸���
                drawingObj->SetBackground();
                int doFightFlag = 1;
                //���� ������ �ʱ�ȭ �Ѵ�.
                objList[1]->init();


                //����� ���� ���Ƿ� ������ ���Ϳ� ���� ��ü��
                //����ĳ����(dynamic_cast)�ؼ� �Ҵ��Ѵ�.
                CMonster* tmpMonsterObj = dynamic_cast<CMonster*>(objList[1]);
                CUser* tmpUserObj = dynamic_cast<CUser*>(objList[0]);
                CSkill* tmpUserSkillObj = dynamic_cast<CSkill*>(objList[0]);

				//���� ���� ���
				COORD cdMonsterInfoPos = { 90, 10 };
                drawingObj->SetCdDrawingPos(cdMonsterInfoPos);
                drawingObj->PrintOfInfo(tmpMonsterObj);

				//���� ���� ���
				COORD cdUserInfo = { 30, 9 };
                drawingObj->SetCdDrawingPos(cdUserInfo);
                drawingObj->PrintOfInfo(tmpUserObj);

				//���� ���θ� ���´�.
                COORD cdFightMenuPos = { 45, 25 };
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cdFightMenuPos);
                cout << "�ο�ðڽ��ϱ�? (1. ����, 2.��������) :";

				while (doFightFlag) {
                    
					int intputFightMenu = _getch();
                    
					if (intputFightMenu == 49) {

                        //ȭ���� �ʱ�ȭ �ϰ� ������ ������ ������ ���� ������ ȭ�鿡 ǥ���Ѵ�.
                        //���׸���
                        drawingObj->SetBackground();
                        //���� ���� ���
                        drawingObj->SetCdDrawingPos(cdMonsterInfoPos);
                        drawingObj->PrintOfInfo(tmpMonsterObj);
                        //���� ���� ���
                        drawingObj->SetCdDrawingPos(cdUserInfo);
                        drawingObj->PrintOfInfo(tmpUserObj);

						//������ ����� �� �ִ� ��� ��� ���
                        drawingObj->SetCdDrawingPos(cdFightMenuPos);
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

							//���� ���� ���
							drawingObj->SetCdDrawingPos(cdMonsterInfoPos);
							drawingObj->PrintOfInfo(tmpMonsterObj);

							//���� ���� ���
							drawingObj->SetCdDrawingPos(cdUserInfo);
							drawingObj->PrintOfInfo(tmpUserObj);

							if (useSkill == NULL) {
								drawingObj->SetCdDrawingPos(cdFightMenuPos);
								SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cdFightMenuPos);
								cout << "����� �� ���� ����Դϴ�. �ٽ� �Է��Ͽ��ּ���.";
								drawingObj->SetCdDrawingPos(cdFightMenuPos);
								drawingObj->PrintUserSkillList(tmpUserSkillObj);
							} else {
								//���׸���
								drawingObj->SetBackground();

								//�÷��̾ ����� ���� ��ų�� �����Ѵ�.
								tmpUserObj->SetUsingSkill(n_useSkill);
								//�÷��̾��� ���ݳ����� ȭ�鿡 ����Ѵ�.
								drawingObj->PrintUserSkillAttack(tmpUserObj, tmpMonsterObj);
								//������ ü���� �����Ѵ�.
								tmpMonsterObj->SetMonsterHP(tmpMonsterObj->GetMonsterHP() - tmpUserObj->Attack());

								//������ ���ݳ����� ȭ�鿡 ����Ѵ�.
								drawingObj->PrintMonsterAttack(tmpUserObj, tmpMonsterObj);
								//�÷��̾��� ü���� �����Ѵ�.
								tmpUserObj->SetUserHP(tmpUserObj->GetUserHp() - tmpMonsterObj->Attack());

								//���� ���� ���
								drawingObj->SetCdDrawingPos(cdMonsterInfoPos);
								drawingObj->PrintOfInfo(tmpMonsterObj);

								//���� ���� ���
								drawingObj->SetCdDrawingPos(cdUserInfo);
								drawingObj->PrintOfInfo(tmpUserObj);

								//��� ��� ���� ���
								drawingObj->SetCdDrawingPos(cdFightMenuPos);
								drawingObj->PrintUserSkillList(tmpUserSkillObj);
							}
						}
					} else if (intputFightMenu == 50) {
						//���׸���
                        drawingObj->SetBackground();

						objList[0]->SetPos(pos);
						objList[0]->Move();
                        doFightFlag = 0;
					}
				}
			}
		}

	}
}
