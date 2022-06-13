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
    //���� ���� �Լ�
    virtual void Attack() = 0;

    //��ü�� Ÿ���� �����ϴ� �Լ�.
	int GetType() { return m_nType; }
    //���� ����
    int m_nDungeonLvl;
    //��ü�� ����
    void SetName(const char* s);
    //��ü ��ġ
	int m_nPosArry[2];
    //��ü��
	char* m_nName;
    //��ü Ÿ��
	int	m_nType;
};

#endif