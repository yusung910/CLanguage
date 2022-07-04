#pragma once
class Point {
public:
    //»ý¼ºÀÚ
    Point();
    Point(int x, int y);
    ~Point();

    void SetPos(int x, int y);

    int GetX();
    int GetY();
protected:
    int n_posX;
    int n_posY;
private:
};