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

	//// 가상함수
    //객체 정보를 화면에 출력한다.
	virtual void Display() = 0;
    //가상 공격 함수
    virtual void Attack() = 0;

    //객체의 타입을 리턴하는 함수.
	int GetType() { return m_nType; }
    //던전 레벨
    int m_nDungeonLvl;
    //객체명 세팅
    void SetName(const char* s);
    //객체 위치
	int m_nPosArry[2];
    //객체명
	char* m_nName;
    //객체 타입
	int	m_nType;
};

#endif