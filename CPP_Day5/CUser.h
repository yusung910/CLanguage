#ifndef __USER_H_
#define __USER_H_

#include "CObject.h"
enum E_USER_EQUIP {
    E_U_HEAD, //투구
    E_U_WEAPON, //무기
    E_U_SHILD, //방패
    E_U_GLOVE, //장갑
    E_U_BOOTS, //신발
    E_U_BELT, //벨트
    E_U_RING1, //반지1
    E_U_RING2, //반지2
    E_U_AMULET, //목걸이
};
class CUser : public CObject {

public:
    //생성자
    CUser();
    //소멸자
    virtual ~CUser();
    //유저의 정보를 화면에 표현한다.
    void Display();
    //공격
    void Attack();
    //초기화
    void init();

private:
    //경험치
    int m_nExp;
    //체력
    int	m_nHP;
    //마나
    int	m_nMana;
    //레벨
    int	m_nLEVEL;
    //힘
    int m_Str;
    //지능
    int m_Int;
    //민첩
    int m_Dex;
    //공격력
    int m_Damage;
};
#endif