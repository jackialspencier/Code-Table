// 程序清单9.1 coordin.h
// coordin.h -- structure templates and function prototypes
// structure templates
#ifndef COORDIN_H_
#define  COORDIN_H_

struct polar
{
    double distance;
    double angle;
};
struct rect
{
    double x;
    double y;
};

//prototype
polar rect_to_polar(rect xypos);
void show_polar(polar dapos);
#endif