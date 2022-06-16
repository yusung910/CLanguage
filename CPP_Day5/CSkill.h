#ifndef __SKILL_H_
#define __SKILL_H_

#include "CObject.h"

enum E_SKILL {
	ATTACK = 0,
	DOUBLE_ATTACK,
	BASH,
	STRIKE,
	MAX_SKILL_CNT,
};


class CSkill : public CObject {

public:
	//생성자
	CSkill();
	//소멸자
	virtual ~CSkill();
	//유저의 정보를 화면에 표현한다.
	void Display();
	//공격
	int Attack();
	//초기화
	void init();
	//사용 가능한 스킬목록을 불러온다.
	void ShowSkillList();
	//스킬명을 한글명으로 가져온다
	char* GetSkillName(int n);
protected:
	//사용 가능한 스킬목록;
	int* n_SkillList;
	//스킬명
	char* c_SkillName;
};

#endif