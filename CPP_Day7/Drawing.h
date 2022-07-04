#pragma once
#include <windows.h>

#include "Point.h"
#include "String.h"

using namespace std;

enum E_BG_TILE {
    LAND = 0,
    WALL,
    WALL_VERTICAL,  
    WALL_HORIZONTAL,
    WALL_LEFT_TOP,  
    WALL_RIGHT_TOP, 
    WALL_LEFT_BOTTOM,
    WALL_RIGHT_BOTTOM,
};

class Drawing : public Point, public String
{

public:

    Drawing(HANDLE hd);
    Drawing();
    ~Drawing();

    void Locate(void);

    void PrintString(int x, int y);
    void PrintString(int x, int y, const char* chr);
    //void PrintInteger(int x, int y, int n);

protected:

private:
    HANDLE m_Handle;
};