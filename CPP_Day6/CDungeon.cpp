#include "CDungeon.h"

CDungeon::CDungeon() {
	m_nDungeonLvl = 0;
}

CDungeon::~CDungeon() {

}

void CDungeon::PrintDungeonMap() {

	//�ⱸ��, ������ �Ա��� �׸���.
	//�� �׸���
	PrintDoor({ 0, 3 }, { 3, 7 }, E_BACKGROUND::PREV_DUNGEON_LVL);


}