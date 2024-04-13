#include "circle.h"
Circle::Circle(int tx, int ty, int tr)
{
    x = tx;
    y = ty;
    r = tr;
}
void Circle::getO(int &cx, int &cy){
    cx = x;
    cy = y;
}
int Circle::getR(){
    return r;
}
void Circle::move(int mx, int my){
    x += mx;
    y += my;
}
void Circle::setR(int nr){
    r = nr;
}
