#pragma once
#include <iostream>
#include "String.h"

using namespace std;

//ĳ������ ���������� �����ϱ� ���� ������ �� ��ü
template <typename T1, typename T2, typename T3>
class HashMap {
public:
    //Map ������
    HashMap();
    //Map �Ҹ���
    ~HashMap();

    //�� ������ �ֱ�
    void Put(T1 k, T2 v, T3 sv);
    void Put(T1 k, T3 sv);
    void Put(T1 k, T2 v);

    //�� �����Ͱ� ������ ����� �����͸� �޾Ƽ� ��ü�� �Ҵ��Ѵ�.
    void Put(T2* v, T3* sv, int n_size);

    //�� �����Ϳ� �������� �迭�� �ø���
    void SetArryAdd();

    //�� �����͸� ã�Ƽ� �����´�
    T2 GetValue(T1 k);

    //value ���� �̿��ؼ� key ���� �����´�
    T1 GetKey(T2 v);

    //key���� value�� �Ҵ� �Ǿ��ִ��� Ȯ���ϴ� �Լ�
    bool Is_valid(T1 k);

    //HashMap�� ����� ������ ũ�⸦ ����
    int GetSize();

protected:
    
private:
    int m_nSize;
    T1* m_Key;
    T2* m_Value;
    T3* m_SubValue;
};