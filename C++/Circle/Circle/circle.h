#ifndef CIRCLE_H
#define CIRCLE_H
class Circle{
    int x;
    int y;
    int r;
public:
    Circle(int tx, int ty, int tr);
    void getO(int &cx, int &cy);
    int getR();
    void move(int mv, int my);
    void setR(int nr);
};
#endif