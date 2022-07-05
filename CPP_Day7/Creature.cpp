#include "Creature.h"

int Creature::n_CreatureCnt = 0;
//생성자
Creature::Creature() {
	//객체 생성시 객체 개수를 증가.
	n_CreatureCnt++;
}

//소멸자
Creature::~Creature() {
	n_CreatureCnt--;
}


void Creature::DisplayName() {
	//객체의 이름을 출력한다.
	n_sName.Display();
}