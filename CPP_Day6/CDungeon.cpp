#include "CDungeon.h"

CDungeon::CDungeon() {
	m_nDungeonLvl = 0;
}

CDungeon::~CDungeon() {

}

void CDungeon::PrintDungeonMap() {

    //타이틀 출력
    //시스템메세지 영역에 현재 위치를 출력
    ClearDisplay(E_DISPLAY::MAP_TITLE);
    SetPos(10, 21);
    cout << "현재 위치 : 던전 " << m_nDungeonLvl << "층";
	//출구 그리기
	PrintDoor({ 0, 3 }, { 3, 7 }, E_BACKGROUND::PREV_DUNGEON_LVL);
    //다음층 그리기
    PrintDoor({ 74, 10 }, { 77, 13 }, E_BACKGROUND::NEXT_DUNGEON_LVL);

}