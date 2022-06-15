#include <iostream>
#include "CSkill.h"

using namespace std;

//생성자
CSkill::CSkill() {
	init();
}
//소멸자
CSkill::~CSkill() {

}
//유저의 정보를 화면에 표현한다.
void CSkill::Display() {
}
//공격
int CSkill::Attack() {
	return 0;
}
//초기화
void CSkill::init() {
	//유저가 가지고 있는 스킬 목록을 초기화한다.
	n_SkillList = new int[E_SKILL::MAX_SKILL_CNT];
	//기본 스킬을 넣는다.
	n_SkillList[0] = E_SKILL::ATTACK;
}
//사용 가능한 스킬목록을 불러온다.
void CSkill::ShowSkillList() {
	cout << "기술 목록 :: " << endl;
	int n_skillListSize = sizeof(n_SkillList) / sizeof(int);
	for (int i = 0; i < n_skillListSize; i++) {
		switch (n_SkillList[i]) {
		case E_SKILL::ATTACK:
			break;
		}
		cout << "스킬명 : " << n_SkillList[i] << endl;
	}
}