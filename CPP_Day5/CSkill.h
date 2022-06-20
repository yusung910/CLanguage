#ifndef __SKILL_H_
#define __SKILL_H_

#include "CObject.h"

enum E_SKILL {
	ESCAPE = 0,
	ATTACK,
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
    int* GetSkillList();
	//��ų���� �ѱ۸����� �����´�
	char* GetSkillName(int n);
	//���� �߻� �� ����� ��ų��ȣ�� �����Ѵ�
	void SetUsingSkill(int n);
	//���� �߻� �� ����� ��ų��ȣ�� ����
	int GetUsingSkill();
protected:
	//��� ������ ��ų���;
	int* n_SkillList;
	//��ų��
	char* c_SkillName;
	//���� �߻� �� ����� ��ų��ȣ
	int n_usingSkill;
};

#endif