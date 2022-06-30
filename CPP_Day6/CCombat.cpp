#include "CCombat.h"
//������
CCombat::CCombat() {

}

//�Ҹ���
CCombat::~CCombat() {
}

int CCombat::BeginCombat(CPlayer* player, CMonster* monster) {

	//�÷��̾� ����
	int* aPlayerInfo = player->GetUnitInfo();
	//�÷��̾� ����
	int* aPlayerStat = player->GetPlayerStat();
	//���� ����
	int* aMonsterInfo = monster->GetUnitInfo();
	//�÷��̾� ���� ��ġ
	int n_PlayerInfoX = 15;
	int n_PlayerInfoY = 3;
	//���� ���� x ��ġ
	int n_MonsterInfoX = 45;
	int n_MonsterInfoY = 3;

	ClearDisplay(E_DISPLAY::GAME);
	//������ �ٽ� �׸���.
	PrintDisplayRound();

	//���� �÷��� ȭ�鿡 �÷��̾� ������ ���
	SetPos(n_PlayerInfoX, n_PlayerInfoY);
	cout << "[�÷��̾� ����]";

	SetPos(n_PlayerInfoX, (n_PlayerInfoY + 1));
	cout << "���� : ";
	cout << aPlayerInfo[E_UNIT_INFO::E_LVL];

	SetPos(n_PlayerInfoX, (n_PlayerInfoY + 2));
	cout << "ü�� : ";
	cout << aPlayerInfo[E_UNIT_INFO::E_HP];

	SetPos(n_PlayerInfoX, (n_PlayerInfoY + 3));
	cout << "���� : ";
	cout << aPlayerInfo[E_UNIT_INFO::E_MANA];

	SetPos(n_PlayerInfoX, (n_PlayerInfoY + 4));
	cout << "���ݷ� : ";
	cout << aPlayerInfo[E_UNIT_INFO::E_DAMAGE];

	//���� ���� ���
	SetPos(n_MonsterInfoX, (n_MonsterInfoY));
	cout << "[���� ����]";

	SetPos(n_MonsterInfoX, (n_MonsterInfoY + 1));
	cout << "�̸� : ";
	monster->GetName().Display();

	SetPos(n_MonsterInfoX, (n_MonsterInfoY + 2));
	cout << "���� : ";
	cout << aMonsterInfo[E_UNIT_INFO::E_LVL];

	SetPos(n_MonsterInfoX, (n_MonsterInfoY + 3));
	cout << "ü�� : ";
	cout << aMonsterInfo[E_UNIT_INFO::E_HP];

	SetPos(n_MonsterInfoX, (n_MonsterInfoY + 4));
	cout << "���� : ";
	cout << aMonsterInfo[E_UNIT_INFO::E_MANA];

	SetPos(n_MonsterInfoX, (n_MonsterInfoY + 5));
	cout << "���ݷ� : ";
	cout << aMonsterInfo[E_UNIT_INFO::E_DAMAGE];

	//�÷��̾ ������ �� �ִ� ����� �����Ѵ�.
	SelectCombatMenu();
	return 1;
}

void CCombat::SelectCombatMenu() {

	//�ý��� �޼��� ���� �ʱ�ȭ
	ClearDisplay(E_DISPLAY::SYSTEM);

	SetPos(10, 22);
	cout << "���� �߻�!, ������ �����Ͻðڽ��ϱ�?";
	SetPos(10, 24);
	cout << "�� �ο��.";
	SetPos(12, 25);
	cout << " ����ģ��.";

	//�����޴� ���ÿ���
	int n_DoFightSelect = 1;
	//�����޴� ����
	int n_SelectFightMenu = E_BATTLE_MENU::BEGIN;
	while (n_DoFightSelect) {

		int n_input = _getch();
		
		//����ڰ� �Է��� ����Ű�� ���� �޴� ������ �����δ�.
		if (GetAsyncKeyState(VK_UP) & 0x0001) {
			n_SelectFightMenu = (n_SelectFightMenu > E_BATTLE_MENU::BEGIN) ? n_SelectFightMenu -= 1 : E_BATTLE_MENU::BEGIN;
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x0001) {
			n_SelectFightMenu = (n_SelectFightMenu < E_BATTLE_MENU::RUN) ? n_SelectFightMenu += 1 : E_BATTLE_MENU::RUN;
		}

		switch (n_SelectFightMenu) {
		case E_BATTLE_MENU::BEGIN:
			SetPos(10, 25);
			cout << "  ";
			SetPos(10, 24);
			cout << "��";
			break;
		case E_BATTLE_MENU::RUN:
			SetPos(10, 24);
			cout << "  ";
			SetPos(10, 25);
			cout << "��";
			break;
		}

		//�޴� ���� �� ����Ű ���� ���
		if (GetAsyncKeyState(VK_RETURN)) {
			if (n_SelectFightMenu == E_BATTLE_MENU::BEGIN) {

			}
			else if (n_SelectFightMenu == E_BATTLE_MENU::RUN) {
				n_DoFightSelect = 0;
			}
		}
	}
}