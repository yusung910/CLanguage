#include "CDungeon.h"

CDungeon::CDungeon() {
	m_nDungeonLvl = 0;
}

CDungeon::~CDungeon() {

}

void CDungeon::PrintDungeonMap() {

	//출구와, 다음층 입구를 그린다.
	//문 그리기
	PrintDoor({ 0, 3 }, { 3, 7 }, E_BACKGROUND::PREV_DUNGEON_LVL);


}