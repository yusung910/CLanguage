#include <iostream>
#include "CSkill.h"

using namespace std;

//������
CSkill::CSkill() {
	init();
}
//�Ҹ���
CSkill::~CSkill() {

}
//������ ������ ȭ�鿡 ǥ���Ѵ�.
void CSkill::Display() {
}
//����
int CSkill::Attack() {
	return 0;
}
//�ʱ�ȭ
void CSkill::init() {
	//������ ������ �ִ� ��ų ����� �ʱ�ȭ�Ѵ�.
	n_SkillList = new int[E_SKILL::MAX_SKILL_CNT];
	//�⺻ ��ų�� �ִ´�.
	n_SkillList[0] = E_SKILL::ATTACK;
}
//��� ������ ��ų����� �ҷ��´�.
void CSkill::ShowSkillList() {
	cout << "��� ��� :: " << endl;
	int n_skillListSize = sizeof(n_SkillList) / sizeof(int);
	for (int i = 0; i < n_skillListSize; i++) {
		switch (n_SkillList[i]) {
		case E_SKILL::ATTACK:
			break;
		}
		cout << "��ų�� : " << n_SkillList[i] << endl;
	}
}