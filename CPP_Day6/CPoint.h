
#ifndef __POINT_H__
#define __POINT_H__

#include <windows.h>
#include <iostream>
#include <conio.h>

using namespace std;
//콘솔 화면에 커서 위치를 지정하기 위한 클래스
class CPoint
{
public:
    //HANDLE 객체를 받는 생성자
    CPoint(HANDLE hOutput);
    //매개변수가 없는 생성자.
    CPoint();
    //소멸자
    ~CPoint();
    //X,Y을 매개변수로 받아 세팅한다.
    void SetPos(int x, int y);
    //coord를 매개변수로 받아 세팅한다.
    void SetPos(COORD pos);
    int GetPosX();
    int GetPosY();
    
private:

protected:
    int m_nPosX;
    int m_nPosY;
    HANDLE m_nHandle;
};
#endif