#include "Point.h"

Point::Point() {

}

Point::Point(int x, int y) {

}

Point::~Point() {

}

void Point::SetPos(int x, int y) {
    n_posX = x;
    n_posY = y;
}

int Point::GetX() {
    return n_posX;
}

int Point::GetY() {
    return n_posX;
}