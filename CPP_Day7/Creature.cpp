#include "Creature.h"

int Creature::n_CreatureCnt = 0;
//생성자
Creature::Creature() {
	//객체 생성시 객체 개수를 증가.
	n_CreatureCnt++;
    //크리쳐 객체 생성에 기본 스텟명을 저장한다.
    String sStatNameList[E_CREATURE_BASIC_STAT::STAT_CNT] = {
        String("체력"),
        String("마나"),
        String("레벨"),
        String("공격력")
    };

    int fStatValueList[E_CREATURE_BASIC_STAT::STAT_CNT] = { 0, 0, 0, 0 };

    hm_BasicStat.Put(sStatNameList, fStatValueList, E_CREATURE_BASIC_STAT::STAT_CNT);
}

//소멸자
Creature::~Creature() {
	n_CreatureCnt--;
}


void Creature::DisplayName() {
	//객체의 이름을 출력한다.
	n_sName.Display();
}