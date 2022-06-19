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
    //null ������ memset�Ѵ�
    memset(n_SkillList, -1, E_SKILL::MAX_SKILL_CNT);
	//�⺻ ��ų�� �ִ´�.
	n_SkillList[0] = E_SKILL::ATTACK;
}
//��� ������ ��ų����� �ҷ��´�.
int* CSkill::GetSkillList() {
    return n_SkillList;
}

char* CSkill::GetSkillName(int n) {
	char* c_retChr = NULL;
	switch (n) {
	case E_SKILL::ATTACK:
		c_retChr = new char[strlen("�⺻����") + 1];
		strcpy(c_retChr, "�⺻����");
		break;
	case E_SKILL::BASH:
		c_retChr = new char[strlen("�转") + 1];
		strcpy(c_retChr, "�转");
		break;
	case E_SKILL::DOUBLE_ATTACK:
		c_retChr = new char[strlen("�������") + 1];
		strcpy(c_retChr, "�������");
		break;
	case E_SKILL::STRIKE:
		c_retChr = new char[strlen("��Ʈ����ũ") + 1];
		strcpy(c_retChr, "��Ʈ����ũ");
		break;
	}
	return c_retChr;
}