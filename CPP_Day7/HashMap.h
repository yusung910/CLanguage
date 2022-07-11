#pragma once
#include <iostream>
#include "String.h"

using namespace std;

//캐릭터의 스텟정보를 저장하기 위한 일종의 맵 객체
template <typename T1, typename T2, typename T3>
class HashMap {
public:
    //Map 생성자
    HashMap();
    //Map 소멸자
    ~HashMap();

    //맵 데이터 넣기
    void Put(T1 k, T2 v, T3 sv);
    void Put(T1 k, T3 sv);
    void Put(T1 k, T2 v);

    //맵 데이터가 여러건 저장된 포인터를 받아서 객체에 할당한다.
    void Put(T2* v, T3* sv, int n_size);

    //맵 데이터에 동적으로 배열을 늘린다
    void SetArryAdd();

    //맵 데이터를 찾아서 가져온다
    T2 GetValue(T1 k);

    //value 값을 이용해서 key 값을 가져온다
    T1 GetKey(T2 v);

    //key값에 value가 할당 되어있는지 확인하는 함수
    bool Is_valid(T1 k);

    //HashMap에 저장된 데이터 크기를 리턴
    int GetSize();

protected:
    
private:
    int m_nSize;
    T1* m_Key;
    T2* m_Value;
    T3* m_SubValue;
};