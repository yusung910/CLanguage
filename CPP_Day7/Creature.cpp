#include "Creature.h"

int Creature::n_CreatureCnt = 0;
//������
Creature::Creature() {
	//��ü ������ ��ü ������ ����.
	n_CreatureCnt++;
    //ũ���� ��ü ������ �⺻ ���ݸ��� �����Ѵ�.
    String sStatNameList[E_CREATURE_BASIC_STAT::STAT_CNT] = {
        String("ü��"),
        String("����"),
        String("����"),
        String("���ݷ�")
    };

    int fStatValueList[E_CREATURE_BASIC_STAT::STAT_CNT] = { 0, 0, 0, 0 };

    hm_BasicStat.Put(sStatNameList, fStatValueList, E_CREATURE_BASIC_STAT::STAT_CNT);
}

//�Ҹ���
Creature::~Creature() {
	n_CreatureCnt--;
}


void Creature::DisplayName() {
	//��ü�� �̸��� ����Ѵ�.
	n_sName.Display();
}