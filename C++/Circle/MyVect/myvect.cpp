#include "myvect.h"
int MyVect::count = 0;
int MyVect::living = 0;
void MyVect::setNorm()
{
    double temp = 0;
    for (int i = 0; i < length; i++)
        temp += p[i] * p[i];
    norm = sqrt(temp);  
}

MyVect::MyVect(int l)
{
    length = l;
    norm = 0.0;
    p = new int[length];
    count++;
    living++;
}

MyVect::MyVect(const MyVect & v)
{
    length = v.length;
    norm = v.norm;
    p = new int[length];
    for (int i = 0; i < length; i++)
        p[i] = v.p[i];
    count++;
    living++;//调用的析构函数会减，这里自然要加
}


MyVect::~MyVect()
{
    delete [] p;
    living--;
}

double MyVect::operator-(double a) const
{
    return (norm - 1);
}

MyVect MyVect::operator+(const MyVect & v) const
{
    MyVect temp(length);
    for (int i = 0; i < length; i++)
        temp.p[i] = p[i] + v.p[i];
    temp.setNorm();
    return temp;
}

MyVect MyVect::operator++()
{
    for (int i = 0; i < length; i++)
        p[i]++;
    setNorm();
    return *this;
}

MyVect MyVect::operator++(int)
{
    MyVect temp(*this);
    for (int i = 0; i < length; i++)
        p[i]++;
    setNorm();
    return temp;
}

MyVect & MyVect::operator=(const MyVect & v)
{
    if (this == &v)
        return *this;
    length = v.length;
    norm = v.norm;
    delete [] p;
    p = new int[length];
    for (int i = 0; i < length; i++)
        p[i] = v.p[i];
    return *this;
}

bool MyVect::operator==(const MyVect & v) const
{
    if (length != v.length)
        return false;
    for (int i = 0; i < length; i++)
        if (p[i] != v.p[i])
            return false;
    return true;
}

int MyVect::operator[](int n)
{
    return p[n];
}

istream & operator>>(istream & is, MyVect & v)
{
    for (int i = 0; i < v.length; i++)
        is >> v.p[i];   // 这里不是std::cin!!!!!!!!!!!!!!!!!!!!!!!
    v.setNorm();
    return is;
}

ostream & operator<<(ostream & os, const MyVect & v)
{
    for (int i = 0; i < v.length; i++)
        os << v.p[i] << " ";
    return os;
}
