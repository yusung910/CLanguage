#include "Creature.h"

int Creature::n_CreatureCnt = 0;
//������
Creature::Creature() {
	//��ü ������ ��ü ������ ����.
	n_CreatureCnt++;
}

//�Ҹ���
Creature::~Creature() {
	n_CreatureCnt--;
}


void Creature::DisplayName() {
	//��ü�� �̸��� ����Ѵ�.
	n_sName.Display();
}