#ifndef __USER_H_
#define __USER_H_

#include "CObject.h"
enum E_USER_EQUIP {
    E_U_HEAD, //����
    E_U_WEAPON, //����
    E_U_SHILD, //����
    E_U_GLOVE, //�尩
    E_U_BOOTS, //�Ź�
    E_U_BELT, //��Ʈ
    E_U_RING1, //����1
    E_U_RING2, //����2
    E_U_AMULET, //�����
};
class CUser : public CObject {

public:
    //������
    CUser();
    //�Ҹ���
    virtual ~CUser();
    //������ ������ ȭ�鿡 ǥ���Ѵ�.
    void Display();
    //����
    void Attack();
    //�ʱ�ȭ
    void init();

private:
    //����ġ
    int m_nExp;
    //ü��
    int	m_nHP;
    //����
    int	m_nMana;
    //����
    int	m_nLEVEL;
    //��
    int m_Str;
    //����
    int m_Int;
    //��ø
    int m_Dex;
    //���ݷ�
    int m_Damage;
};
#endif