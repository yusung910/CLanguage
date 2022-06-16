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
	//������
	CSkill();
	//�Ҹ���
	virtual ~CSkill();
	//������ ������ ȭ�鿡 ǥ���Ѵ�.
	void Display();
	//����
	int Attack();
	//�ʱ�ȭ
	void init();
	//��� ������ ��ų����� �ҷ��´�.
	void ShowSkillList();
	//��ų���� �ѱ۸����� �����´�
	char* GetSkillName(int n);
protected:
	//��� ������ ��ų���;
	int* n_SkillList;
	//��ų��
	char* c_SkillName;
};

#endif