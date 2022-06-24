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

	//배경그리기
	drawingObj->SetBackground();

	int doFightFlag = 1;
	//몬스터 정보를 초기화 한다.
	monster->init();

	drawingObj->PrintOfCombatInfo(monster);
	drawingObj->PrintOfCombatInfo(user);

	//전투 메세지 출력위치
	//COORD cdCombatMsgPos = { 50, 25 };
	//시스템 메세지 출력 위치
	//COORD cdSystemMsgPos = { 15, 25 };

	
	//전투 여부를 묻는다.
	drawingObj->PrintOutCombatStartMsg();

	while (doFightFlag) {

		int intputFightMenu = _getch();

		if (intputFightMenu == 49) {

			//화면을 초기화 하고 몬스터의 정보와 유저의 세부 정보를 화면에 표시한다.

			drawingObj->PrintOfCombatInfo(user);
			drawingObj->PrintOfCombatInfo(monster);

			//유저가 사용할 수 있는 기술 목록 출력
			drawingObj->PrintUserSkillList(user, false);

			//스킬 선택하는 구문
			int n_doUseSkillFlag = 1;

			while (n_doUseSkillFlag) {

				//사용자가 공격스킬을 선택한다.
				int n_useSkill = (_getch() - 48);

				//사용자가 입력한 값에 해당하는 스킬명을 가져온다.
				char* useSkill = user->GetSkillName(n_useSkill);

				//유저, 몬스터 정보 출력
				drawingObj->PrintOfCombatInfo(user);
				drawingObj->PrintOfCombatInfo(monster);

				if (useSkill == NULL) {
					drawingObj->PrintUserSkillList(user, (useSkill == NULL));
				}
				else {
					//배경그리기
					drawingObj->SetBackground();

					//플레이어가 사용한 공격 스킬을 세팅한다.
					user->SetUsingSkill(n_useSkill);

					drawingObj->PrintUserSkillAttack(user, monster);

					//몬스터의 체력을 감소한다.
					monster->SetMonsterHP(monster->GetMonsterHP() - user->Attack());

					//몬스터의 공격내용을 화면에 출력한다.
					drawingObj->PrintMonsterAttack(user, monster);
					//플레이어의 체력을 감소한다.
					user->SetUserHP(user->GetUserHp() - monster->Attack());

					//유저, 몬스터 정보 출력
					drawingObj->PrintOfCombatInfo(user);
					drawingObj->PrintOfCombatInfo(monster);

					//사용 기술 정보 출력
					drawingObj->PrintUserSkillList(user, false);

					//플레이어 또는 몬스터의 체력 상태를 확인한다
					if (user->GetUserHp() <= 0 && monster->GetMonsterHP() <= 0) {
						//플레이어가 죽었을 경우.
						drawingObj->PrintCombatRslt(user, monster);

						//스킬 사용 종료
						n_doUseSkillFlag = 0;

						//전투 종료
						doFightFlag = 0;
                        //결과 화면을 보기 위한 getch();
                        _getch();
					}
					else if (monster->GetMonsterHP() <= 0) {
						//몬스터가 죽었을 경우.
						//배경그리기
						drawingObj->SetBackground();

						//유저, 몬스터 정보 출력
						drawingObj->PrintOfCombatInfo(user);
						drawingObj->PrintOfCombatInfo(monster);

						//전투 결과 출력
						drawingObj->PrintCombatRslt(user, monster);

						//스킬 사용 종료
						n_doUseSkillFlag = 0;

						//전투 종료
						doFightFlag = 0;

                        //결과 화면을 보기 위한 getch();
                        _getch();
					}
				}
			}
		}
		else if (intputFightMenu == 50) {
			//배경그리기
			drawingObj->SetBackground();

			//user->SetPos(pos);
			user->Move();
			doFightFlag = 0;
		}
	}
}