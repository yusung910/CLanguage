#pragma once
#include <windows.h>

#include "String.h"
#include "HashMap.h"

//플레이어, 몬스터 등 생명체 클래스
enum E_CREATURE_BASIC_STAT {
	HP = 0,
	MANA,
	ATTACK,
	LEVEL,
	STAT_CNT,
};

class Creature : public String{
public:
	//생성자
	Creature();

	//소멸자
	~Creature();

	//공격 가상 함수
	virtual int Attack(int n_skill) = 0;
	//크리쳐 이름 세팅 가상함수
	virtual void SetName(String s) = 0;

	//이름 출력
	void DisplayName();
	//크리쳐 객체의 생성 개수를 카운팅
	static int n_CreatureCnt;
protected:
	//크리쳐 객체의 이름
	String n_sName;

	//크리쳐의 기본스탯 정보가 저장된 HashMap
    HashMap<int, String, int> hm_BasicStat;
private:
};