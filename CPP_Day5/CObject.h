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
    //공격 가상함수
    virtual int Attack() = 0;
	//초기화 가상함수
	virtual void init() = 0;
	//스킬목록 가상함수
	virtual void ShowSkillList() = 0;

    //객체의 타입을 리턴하는 함수.
	int GetType() { return m_nType; }
    //던전 레벨
    int m_nDungeonLvl;
    //객체명 세팅
    void SetName(const char* s);
    //객체 위치
	int m_nPosArry[2];
    //객체명
	char* m_cName;
    //객체 타입
	int	m_nType;
	//객체 개수
	static int m_nObjCnt;
};

#endif