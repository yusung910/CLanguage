#include "CDungeon.h"

CDungeon::CDungeon() {
	m_nDungeonLvl = 0;
}

CDungeon::~CDungeon() {

}

void CDungeon::PrintDungeonMap() {

    //Ÿ��Ʋ ���
    //�ý��۸޼��� ������ ���� ��ġ�� ���
    ClearDisplay(E_DISPLAY::MAP_TITLE);
    SetPos(10, 21);
    cout << "���� ��ġ : ���� " << m_nDungeonLvl << "��";
	//�ⱸ �׸���
	PrintDoor({ 0, 3 }, { 3, 7 }, E_BACKGROUND::PREV_DUNGEON_LVL);
    //������ �׸���
    PrintDoor({ 74, 10 }, { 77, 13 }, E_BACKGROUND::NEXT_DUNGEON_LVL);

}