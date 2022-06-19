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
    //null 값으로 memset한다
    memset(n_SkillList, -1, E_SKILL::MAX_SKILL_CNT);
	//기본 스킬을 넣는다.
	n_SkillList[0] = E_SKILL::ATTACK;
}
//사용 가능한 스킬목록을 불러온다.
int* CSkill::GetSkillList() {
    return n_SkillList;
}

char* CSkill::GetSkillName(int n) {
	char* c_retChr = NULL;
	switch (n) {
	case E_SKILL::ATTACK:
		c_retChr = new char[strlen("기본공격") + 1];
		strcpy(c_retChr, "기본공격");
		break;
	case E_SKILL::BASH:
		c_retChr = new char[strlen("배쉬") + 1];
		strcpy(c_retChr, "배쉬");
		break;
	case E_SKILL::DOUBLE_ATTACK:
		c_retChr = new char[strlen("더블어택") + 1];
		strcpy(c_retChr, "더블어택");
		break;
	case E_SKILL::STRIKE:
		c_retChr = new char[strlen("스트라이크") + 1];
		strcpy(c_retChr, "스트라이크");
		break;
	}
	return c_retChr;
}