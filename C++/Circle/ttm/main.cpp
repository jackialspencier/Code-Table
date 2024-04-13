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

int count = 0;
int living = 0;
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

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    MyVect v1(n);
    double x;
    cin >> v1;
    cout << "Now v1 is: "<< v1 << endl;
    cout << "The length of v1 is " << v1.getlength() << endl;
    cout << "The norm of v1 is " << v1.getnorm() << endl;
    x = v1 - 1.0;
    cout << "The norm of v1 minus 1 is " << x << endl;
    MyVect v2 = v1;
    cout << "Now v2 is: " << v2 << endl;
    //cout << "The number of vectors is: " << v1.getcount() << endl;
    cout << endl;
    {
        MyVect v3(n);
        v3= v1 + v2;
        cout << "The result of v1+v2 is: " << v3 << endl;
        cout << "The 1st element of v3 is " << v3[1] << endl;
        //cout << "The number of vectors is: " << MyVect::getcount() << endl;
    }
    cout << endl;
    cout << "The number of living vectors is: " << v1.getliving() << endl;
    //cout << "The number of total vector is: " << v1.getcount() << endl;
    cout << "The result of v1++ is: " << v1++ << endl;
    cout << "The result of v1==v2 is " << (v1==v2) << endl;
    cout << "The result of ++v2 is: " << ++v2 << endl;
    cout << "The result of v1==v2 is " << (v1==v2) << endl;
    return 0;
}