#ifndef __CHARACTER_H__
#define __CHARACTER_H__

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

    //��ü�� Ÿ���� �����ϴ� �Լ�.
	int GetType() { return m_nType; }
    //���� ����
    int m_nDungeonLvl;
    //��ü�� ����
    void SetName(const char* s);
    //��ü ��ġ
	int m_nPosArry[2];
    //��ü��
	char* m_cName;
    //��ü Ÿ��
	int	m_nType;
	//��ü ����
	static int m_nObjCnt;
};

#endif