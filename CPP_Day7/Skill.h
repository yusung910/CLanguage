#pragma once
#include <iostream>
#include "Player.h"

using namespace std;

template <typename T>
class Skill {
public:
    //Map ������
    Skill();
    //Map �Ҹ���
    ~Skill();
    void SetData(T data);
protected:

private:
    T data;

};