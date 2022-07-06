#pragma once
#include <iostream>
#include "Player.h"

using namespace std;

template <typename T>
class Skill {
public:
    //Map 持失切
    Skill();
    //Map 社瑚切
    ~Skill();
    void SetData(T data);
protected:

private:
    T data;

};