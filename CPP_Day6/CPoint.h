
#ifndef __POINT_H__
#define __POINT_H__

#include <windows.h>
#include <iostream>
#include <conio.h>

using namespace std;
//�ܼ� ȭ�鿡 Ŀ�� ��ġ�� �����ϱ� ���� Ŭ����
class CPoint
{
public:
    //HANDLE ��ü�� �޴� ������
    CPoint(HANDLE hOutput);
    //�Ű������� ���� ������.
    CPoint();
    //�Ҹ���
    ~CPoint();
    //X,Y�� �Ű������� �޾� �����Ѵ�.
    void SetPos(int x, int y);
    //coord�� �Ű������� �޾� �����Ѵ�.
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