#ifndef MYVECT_H_
#define MYVECT_H_
#include <iostream>
#include <cmath>
using std::istream;
using std::ostream;
class MyVect
{
private:
    int length;
    double norm;
    int * p;
    static int count;
    static int living;
    void setNorm();
public:
    MyVect(int l);
    MyVect(const MyVect & v);
    ~MyVect();

    int getlength() const { return length; }
    double getnorm() const { return norm; }
    static int getliving() { return living; }   // 静态成员函数不允许用const

    double operator-(double a) const;
    MyVect operator+(const MyVect & v) const;
    MyVect operator++();
    MyVect operator++(int);
    MyVect & operator=(const MyVect & v);
    bool operator==(const MyVect &) const;
    int operator[](int n);   

    friend istream & operator>>(istream &, MyVect & v);
    friend ostream & operator<<(ostream &, const MyVect & v);
};
#endif