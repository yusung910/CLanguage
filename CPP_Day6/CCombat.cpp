#include "CCombat.h"
//������
CCombat::CCombat() {

}

//�Ҹ���
CCombat::~CCombat() {
}

void CCombat::initCombat(CPlayer* player, CMonster* monster) {
    //�÷��̾� ��ü�� ����
    o_player = player;
    //���� ��ü�� ����
    o_monster = monster;
}

void CCombat::PrintCombatInfo() {
	//�÷��̾� ����
	unsigned int* aPlayerInfo = o_player->GetUnitInfo();
	//�÷��̾� ����
	int* aPlayerStat = o_player->GetPlayerStat();
	//���� ����
	unsigned int* aMonsterInfo = o_monster->GetUnitInfo();
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
	o_monster->GetName().Display();

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
}

int CCombat::StartCombat() {

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
		if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
			if (n_SelectFightMenu == E_BATTLE_MENU::BEGIN) {
                ClearDisplay(E_DISPLAY::SYSTEM);
                n_DoFightSelect = 0;
                SelectPlayerSkill();
			}
			else if (n_SelectFightMenu == E_BATTLE_MENU::RUN) {
				n_DoFightSelect = 0;
			}
		}
	}

	return 1;
}

void CCombat::SelectPlayerSkill() {
    //��ų ���� ���� while �÷���
    int doPlayerSkillFlag = 1;
    //�÷��̾� ��ų
    int nPlayerSkill = E_PLAYER_SKILL::ESCAPE;
    //�÷��̾��� ������ ��ų
    int nEndPlayerSkill;
    //�÷��̾ �����ϰ� �ִ� ��� ���
    int* n_UserSkillList = o_player->GetUnitSkillList();
    //�÷��̾� ��ų���� ���� �Ǿ��ִ� ����
    CString* s_UserSkillNmList = o_player->GetPlayerSkillNameList();

    SetPos(10, 22);
    cout << "[��ų���]";
    //�÷��̾��� ��� ������ ��� ����� ����Ѵ�.
    for (int i = 0; i < E_PLAYER_SKILL::PLAYER_SKILL_CNT; i++) {
        if (n_UserSkillList[i] > -1) {

            if (i == 0) {
                SetPos(10, (23 + i));
                cout << "��";
            }

            SetPos(12, (23 + i));
            s_UserSkillNmList[i].Display();


            //�÷��̾ ���� �ִ� ������ ��ų�ѹ��� �����Ѵ�.
            nEndPlayerSkill = i;
        }
    }
    
    while (doPlayerSkillFlag) {

        int nInput = _getch();

        //����ڰ� �Է��� ����Ű�� ���� ��ų ���� �޴��� �����δ�.
        if (GetAsyncKeyState(VK_UP) & 0x0001) {
            nPlayerSkill = (nPlayerSkill > E_PLAYER_SKILL::ESCAPE) ? nPlayerSkill -= 1 : E_PLAYER_SKILL::ESCAPE;
        }

        if (GetAsyncKeyState(VK_DOWN) & 0x0001) {
            nPlayerSkill = (nPlayerSkill < nEndPlayerSkill) ? nPlayerSkill += 1 : nEndPlayerSkill;
        }

        //�÷��̾ ������ ��ų�� ȭ��ǥ�� ǥ���Ѵ�.
        for (int a = 0; a < E_PLAYER_SKILL::PLAYER_SKILL_CNT; a++) {
            SetPos(10, (23 + a));
            cout << "  ";
            if (n_UserSkillList[a] > -1 && n_UserSkillList[a] == nPlayerSkill) {
                SetPos(10, (23 + a));
                cout << "��";
            }
        }

        if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
            if (nPlayerSkill == E_PLAYER_SKILL::ESCAPE) {
                doPlayerSkillFlag = 0;
            }
            else {
				//�÷��̾��� ���ݷ�
				int n_playerDmg = o_player->GetDamage(doPlayerSkillFlag);
				//������ ������
				int n_monsterDmg = o_monster->GetDamage(doPlayerSkillFlag);
				//�÷��̾��� ü��
				unsigned int n_playerHp = (o_player->GetUnitHp() - n_monsterDmg) < 0 ? 0 : o_player->GetUnitHp() - n_monsterDmg;
				//������ ü��
				unsigned int n_monsterHp = (o_monster->GetUnitHp() - n_playerDmg) < 0 ? 0 : o_monster->GetUnitHp() - n_playerDmg;

				int n_logStartX = 10;
				int n_logStartY = 13;

				//������ ü�¿� �÷��̾� �������� ���� ����
				o_monster->SetUnitHp(n_monsterHp);
				//�÷��̾��� ü�¿� ���� �������� ���� ����
				o_player->SetUnitHp(n_playerHp);

				//���� ������ ���
				PrintCombatInfo();

				//�����α� ���
				SetPos(n_logStartX, n_logStartY);
				cout << "[���� ���]";

				n_logStartY++;
				SetPos(n_logStartX, n_logStartY);
				cout << "\'";
				o_player->GetName().Display();
				cout << "\'�� [";
				s_UserSkillNmList[nPlayerSkill].Display();
				cout << "]";

				n_logStartY++;
				SetPos(n_logStartX, n_logStartY);
				cout << n_playerDmg << " ������ �� [";
				o_monster->GetName().Display();
				cout << "]���� �������ϴ�.";

				n_logStartY++;
				SetPos(n_logStartX, n_logStartY);
				cout << "\'";
				o_monster->GetName().Display();
				cout << "\' ����!";

				n_logStartY++;
				SetPos(n_logStartX, n_logStartY);
				cout << "\'";
				o_player->GetName().Display();
				cout << "\'���� "<< n_monsterDmg << " �������� �������ϴ�.";
            }
        }
    }
}