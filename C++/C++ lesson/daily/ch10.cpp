// #ifndef MATRIX_H_
// #define MATRIX_H_
// #include <iostream>
// class Matrix{
// private:
//     int row;
//     int col;
//     int *p;
// public:
//     Matrix();
//     Matrix(int m, int n);
//     ~Matrix();
//     Matrix operator+(const Matrix & b) const;
//     Matrix operator=(const Matrix & m) const;
//     friend std::ostream & operator<<(std::ostream & os, const Matrix & m);
//     friend std::istream & operator>>(std::istream & oi, const Matrix & m);
// };

// #endif

// Matrix::Matrix()
// {
//     row = col = 0;
//     p = nullptr;
// }

// Matrix::Matrix(int m, int n)
// {
//     row = m;
//     col = n;
//     p = new int[m*n]{0};
// }

//  Matrix::~Matrix()
// {
//     delete [] p;
// }

// Matrix Matrix::operator+(const Matrix & b) const
// {
//     Matrix ans(row, col);
//     for (int i = 0; i < row * col; i++)
//         ans.p[i] = p[i] + b.p[i];
//     return ans;
// }

// Matrix Matrix::operator=(const Matrix & m) const
// {
//     Matrix ans(row, col);
//     for (int i = 0; i < row * col; i++)
//         ans.p[i]
// }
// #include <iostream>
// using std::istream;
// using std::ostream;
// class Matrix
// {
// private:
//     int row;
//     int col;
//     int ** p;
// public:
//     Matrix(int r, int c);  
//     Matrix(const Matrix & m);
//     ~Matrix();
//     friend istream & operator>>(istream &, Matrix & m);
//     friend ostream & operator<<(ostream &, const Matrix & m);
//     Matrix operator+(const Matrix & m);
//     Matrix & operator=(const Matrix & m);
//     int operator()(int x, int y);
// };

// Matrix::Matrix(int r, int c)
// {
//     row = r;
//     col = c;
//     p = new int * [row];
//     for (int i = 0; i < row; i++)
//         p[i] = new int[col];
// }

// Matrix::Matrix(const Matrix & m)
// {
//     row = m.row;
//     col = m.col;
//     p = new int * [row];
//     for (int i = 0; i < row; i++)
//         p[i] = new int[col];
//     for (int i = 0; i < row; i++)
//         for (int j = 0; j < col; j++)
//             p[i][j] = m.p[i][j];
// }

// Matrix::~Matrix()
// {
//     for (int i = 0; i < row; i++)
//         delete [] p[i];
//     delete [] p;
// }

// Matrix Matrix::operator+(const Matrix & m)
// {
//     Matrix tmp(m.row, m.col);
//     for (int i = 0; i < row; i++)
//         for (int j = 0; j < col; j++)
//             tmp.p[i][j] = p[i][j] + m.p[i][j];
//     return tmp;
// }

// Matrix & Matrix::operator=(const Matrix & m)
// {
//     if (this == &m)
//         return *this;

//     // for (int i = 0; i < row; i++)
//     //     delete [] p[i];
//     // delete [] p;
//     // p = new int * [row];
//     // for (int i = 0; i < row; i++)
//     //     p[i] = new int[col];
//     for (int i = 0; i < row; i++)
//         for (int j = 0; j < col; j++)
//             p[i][j] = m.p[i][j];
//     return *this;
// }

// int Matrix::operator()(int x, int y)
// {
//     return p[x][y];
// }

// istream & operator>>(istream & is, Matrix & m)
// {
//     for (int i = 0; i < m.row; i++)
//         for (int j = 0; j < m.col; j++)
//             is >> m.p[i][j];
//     return is;
// }

// ostream & operator<<(ostream & os, const Matrix & m)
// {
//     for (int i = 0; i < m.row; i++)
//     {
//         int j;
//         for (j = 0; j < m.col - 1; j++)
//             os << m.p[i][j] << " ";
//         os << m.p[i][j];
//         os << std::endl;
//     }
//     return os;
// }

// #include<iostream>
// using namespace std;

// int main()
// {
//   int m, n, x, y;
//   cin >> m >> n >> x >> y;
//   Matrix a(m, n), b(m, n);
//   cin >> a >> b;
//   Matrix c = a+b;
//   cout << c;
//   a = b+c;
//   // print element at row-x column-y of Matrix a, row and column count from 0
//   cout << a(x, y) << endl; 
//   return 0;
// }


// #ifndef DATE_H_
// #define DATE_H_
// #include <iostream>
// using std::ostream;
// class Date
// {
// private:
//     int year;
//     int month;
//     int day;
//     // static int months[12];
// public:
//     Date();
//     Date(int yr, int mn, int dy);
//     ~Date();
//     Date & setDate(int yr, int mn, int dy);
//     int getyear() { return year; }
//     int getmonth() { return month; }
//     int getday() { return day; }
//     friend std::ostream & operator<<(std::ostream & os, const Date & d);
//     Date operator+(int dy);
//     Date operator++();
//     Date operator++(int);
//     Date & operator+=(int dy); 
//     bool operator<(const Date & b) const;
// };
// #endif


// #include <iostream>
// // #include "date.h"
// static int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// Date::Date()
// {
//     year = 1900;
//     month = 1;
//     day = 1;
// }
// Date::Date(int yr, int mn, int dy)
// {
//     if ((yr < 0 || mn <= 0) || mn >= 13)
//     {
//         year = 1900;
//         month = 1;
//         day = 1;  
//     }
//     bool isLegal = true;
//     bool isM = false;
//     if (yr % 40 == 0 || (yr % 100 != 0 && yr % 4 == 0))
//         isM = true;
//     if (mn == 2){
//         if (isM && dy > 29)
//             isLegal = false;
//         else if ((!isM) && dy > 28)
//             isLegal = false;
//     }
//     else if (dy > months[mn-1])
//         isLegal = false;

//     if (isLegal)
//     {
//         year = yr;
//         month = mn;
//         day = dy;
//     }
//     else
//     {
//         year = 1900;
//         month = 1;
//         day = 1;
//     }
// }
// Date::~Date()
// {
// }
// Date & Date::setDate(int yr, int mn, int dy)
// {
//     Date temp = *this;
//     *this = Date(yr, mn, dy);
//     if ((temp.year != year || temp.month != month || temp.day != day) 
//         && (year == 1900 && month == 1 && day == 1))
//         *this = temp;
//     return *this;
// }

// std::ostream & operator<<(std::ostream & os, const Date & d)
// {
//     os << d.year << "-" << d.month << "-" << d.day;
//     return os;
// }

// Date Date::operator+(int dy)
// {
//     Date tmp = *this;
//     Date ans;
//     day += dy;
//     bool isM = false;
//     if (year % 40 == 0 || year % 100 != 0 && year % 4 == 0)
//         isM = true;
//     if (month == 2){
//         if (isM && day > 29){
//             day = day - 29;
//             month++;
//         }
//         else if ((!isM) && day > 28){
//             day = day - 28;
//             month++;
//         }
//     }
//     else{
//         if (day > months[month-1]){
//             day = day - months[month-1];
//             month++;
//         }
//         if (month > 12){
//             month = month - 12;
//             year++;
//         }
//     }
//     ans = *this;
//     *this = tmp;
//     return ans;
// }
// Date Date::operator++()
// {
//     *this = *this + 1;
//     return *this;
// }
// Date Date::operator++(int)
// {
//     Date tmp = *this;
//     *this = *this + 1;
//     return tmp;
// }
// Date & Date::operator+=(int dy)
// {
//     *this = *this + dy;
//     return *this;
// }
// bool Date::operator<(const Date & b) const
// {
//     if (year < b.year)
//         return true;
//     else if (year > b. year)
//         return false;
//     if (month < b.month)
//         return true;
//     else if (month > b.month)
//         return false;
//     if (day < b.day)
//         return true;
//     else if (day > b.day)
//         return false;
//     return true;
// }

// #include<iostream>
// // #include "date.h"
// using namespace std;

// int main()
// {
//      int day,month,year;
//      cin>>year>>month>>day;
//      Date d1; // 默认值为1900年1月1日
//      Date d2(year,month,day); 
//      cin>>year>>month>>day;
//      Date d3(year,month,day); 

//      cout << "d1 is " << d1 << "\nd2 is " << d2 << "\nd3 is " << d3<<endl;
//      cout << "d2+=7 is " << ( d2 += 7 )<<endl;

//      d3.setDate( d3.getyear(),d3.getmonth(), d3.getday()+5);//重新设置日期，如果新日期非法，则保持原日期不变
//      cout << "d3 is " << d3 << endl; //
//      cout << "++d3 is " << ++d3 <<endl;

//      Date d4( 2002,6,20 );

//      cout << "d4 is " << d4 << endl;                        
//      cout << "d4++ is " << d4++ << endl;                    
//      cout << "d4 is " << d4 << endl;     
//      cout << "d3<d4 is "<<((d3<d4)?"true":"false")<<endl;       
//      return 0;
// }

#include <iostream>
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
public:
    MyVect(int l);
    MyVect(const MyVect & v);
    ~MyVect();

    int getlength() { return length; }
    double getnorm() { return norm; }
    static int getliving() { return living; }

    double operator-(double a);
    MyVect operator+(const MyVect & v);
    MyVect operator++();
    MyVect operator++(int);
    MyVect & operator=(const MyVect & v);
    bool operator==(const MyVect &) const;
    int operator[](int n);

    friend istream & operator>>(istream &, MyVect & v);
    friend ostream & operator<<(ostream &, const MyVect & v);
};
// ❤❤❤❤❤❤❤❤❤❤❤❤❤❤❤❤❤❤❤❤❤❤❤❤❤❤❤❤❤❤❤❤❤❤❤❤❤❤❤❤❤❤❤❤❤❤❤注意[],++,++,()相对练习较少的几个。

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

