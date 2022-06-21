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
	//배경그리기
	drawingObj->SetBackground();

	int doFightFlag = 1;
	//몬스터 정보를 초기화 한다.
	monster->init();


	//출력을 위해 임의로 생성한 몬스터와 유저 객체를
	//동적캐스팅(dynamic_cast)해서 할당한다.
	CSkill* tmpUserSkillObj = dynamic_cast<CSkill*>(user);

	//몬스터 정보 위치 세팅
	COORD cdMonsterInfoPos = { 90, 10 };
	drawingObj->SetMsgPos(cdMonsterInfoPos);
	drawingObj->PrintOfCombatInfo(monster);

	//유저 정보 위치 세팅 후 출력
	COORD cdUserInfo = { 30, 9 };
	drawingObj->SetMsgPos(cdUserInfo);
	drawingObj->PrintOfCombatInfo(user);
	//전투 메세지 출력위치
	COORD cdCombatMsgPos = { 70, 25 };
	//시스템 메세지 출력 위치
	COORD cdSystemMsgPos = { 35, 25 };

	drawingObj->SetMsgPos(cdSystemMsgPos);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cdSystemMsgPos);
	//전투 여부를 묻는다.
	cout << "싸우시겠습니까? (1. 전투, 2.도망가기) :";

	while (doFightFlag) {

		int intputFightMenu = _getch();

		if (intputFightMenu == 49) {

			//화면을 초기화 하고 몬스터의 정보와 유저의 세부 정보를 화면에 표시한다.
			//배경그리기
			drawingObj->SetBackground();

			//유저, 몬스터 정보 출력
			drawingObj->SetMsgPos(cdUserInfo);
			drawingObj->PrintOfCombatInfo(user);
			drawingObj->SetMsgPos(cdMonsterInfoPos);
			drawingObj->PrintOfCombatInfo(monster);

			//유저가 사용할 수 있는 기술 목록 출력
			drawingObj->SetMsgPos(cdSystemMsgPos);
			drawingObj->PrintUserSkillList(tmpUserSkillObj);

			//스킬 선택하는 구문
			int n_doUseSkillFlag = 1;

			while (n_doUseSkillFlag) {

				//사용자가 공격스킬을 선택한다.
				int n_useSkill = (_getch() - 48);

				//사용자가 입력한 값에 해당하는 스킬명을 가져온다.
				char* useSkill = tmpUserSkillObj->GetSkillName(n_useSkill);

				//배경그리기
				drawingObj->SetBackground();

				//유저, 몬스터 정보 출력
				drawingObj->SetMsgPos(cdUserInfo);
				drawingObj->PrintOfCombatInfo(user);
				drawingObj->SetMsgPos(cdMonsterInfoPos);
				drawingObj->PrintOfCombatInfo(monster);

				if (useSkill == NULL) {
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cdSystemMsgPos);
					cout << "사용할 수 없는 기술입니다. 다시 입력하여주세요.";
					drawingObj->PrintUserSkillList(tmpUserSkillObj);
				}
				else {
					//배경그리기
					drawingObj->SetBackground();

					//플레이어가 사용한 공격 스킬을 세팅한다.
					user->SetUsingSkill(n_useSkill);

					//플레이어의 공격내용을 화면에 출력한다.
					drawingObj->SetMsgPos(cdCombatMsgPos);
					drawingObj->PrintUserSkillAttack(user, monster);

					//몬스터의 체력을 감소한다.
					monster->SetMonsterHP(monster->GetMonsterHP() - user->Attack());

					//몬스터의 공격내용을 화면에 출력한다.
					drawingObj->PrintMonsterAttack(user, monster);
					//플레이어의 체력을 감소한다.
					user->SetUserHP(user->GetUserHp() - monster->Attack());

					//유저, 몬스터 정보 출력
					drawingObj->SetMsgPos(cdUserInfo);
					drawingObj->PrintOfCombatInfo(user);
					drawingObj->SetMsgPos(cdMonsterInfoPos);
					drawingObj->PrintOfCombatInfo(monster);

					//사용 기술 정보 출력
					drawingObj->SetMsgPos(cdSystemMsgPos);
					drawingObj->PrintUserSkillList(tmpUserSkillObj);

					//플레이어 또는 몬스터의 체력 상태를 확인한다
					if (user->GetUserHp() <= 0 && monster->GetMonsterHP() <= 0) {
						//플레이어가 죽었을 경우.
						drawingObj->SetMsgPos(cdSystemMsgPos);
						drawingObj->PrintCombatRslt(user, monster);

						//스킬 사용 종료
						n_doUseSkillFlag = 0;

						//전투 종료
						doFightFlag = 0;
					}
					else if (monster->GetMonsterHP() <= 0) {
						//몬스터가 죽었을 경우.
						//배경그리기
						drawingObj->SetBackground();

						//유저, 몬스터 정보 출력
						drawingObj->SetMsgPos(cdUserInfo);
						drawingObj->PrintOfCombatInfo(user);
						drawingObj->SetMsgPos(cdMonsterInfoPos);
						drawingObj->PrintOfCombatInfo(monster);

						//전투 결과 출력
						drawingObj->SetMsgPos(cdSystemMsgPos);
						drawingObj->PrintCombatRslt(user, monster);

						//스킬 사용 종료
						n_doUseSkillFlag = 0;

						//전투 종료
						doFightFlag = 0;
					}
				}
			}
		}
		else if (intputFightMenu == 50) {
			//배경그리기
			drawingObj->SetBackground();

			user->SetPos(pos);
			user->Move();
			doFightFlag = 0;
		}
	}
}