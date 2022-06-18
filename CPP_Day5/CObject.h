#ifndef __CHARACTER_H__
#define __CHARACTER_H__
#include <windows.h>
enum TYPE {
	E_C_NONE = -1,
	E_C_USER,
	E_C_MONSTER,
    E_C_BUILD,
	E_C_MAX,
};

class CObject
{
public:
    CObject();
	virtual ~CObject();

	//// �����Լ�
    //��ü ������ ȭ�鿡 ����Ѵ�.
	virtual void Display() = 0;
    //���� �����Լ�
    virtual int Attack() = 0;
	//�ʱ�ȭ �����Լ�
	virtual void init() = 0;
	//��ų��� �����Լ�
	virtual void ShowSkillList() = 0;
    //�̵� �����Լ�
    virtual void Move() = 0;

	//ȭ�鿡 ǥ���� COORD ��ü ���� �����Ѵ�
	void SetPos(COORD pos);
	//���õ� coord��ü���� �����Ѵ�
	COORD GetPos();

    //ȭ�鿡 ǥ���� �޴��� COORD ��ü ���� �����Ѵ�.
    void SetMenuPos(COORD menuPos);
    //���õ� �޴��� coord ��ü ���� �����Ѵ�.
    COORD GetMenuPos();

    //��ü�� Ÿ���� �����ϴ� �Լ�.
	int GetType() { return m_nType; }
    //���� ����
    int m_nDungeonLvl;
    //��ü�� ����
    void SetName(const char* s);
	//��ü�� ����
	char* GetName();
    //��ü ��ġ
	COORD m_cdPos;
    //�޴��� ����� ��ġ
    COORD m_cdMenuPos;
    //��ü��
	char* m_cName;
    //��ü Ÿ��
	int	m_nType;
	//��ü ����
	static int m_nObjCnt;
};

#endif