#ifndef DATE_H_
#define DATE_H_
#include <iostream>
using std::ostream;
class Date
{
private:
    int year;
    int month;
    int day;
    // static int months[12];
public:
    Date();
    Date(int yr, int mn, int dy);
    ~Date();
    Date & setDate(int yr, int mn, int dy);
    int getyear() { return year; }
    int getmonth() { return month; }
    int getday() { return day; }
    friend std::ostream & operator<<(std::ostream & os, const Date & d);
    Date operator+(int dy);
    Date operator++();
    Date operator++(int);
    Date & operator+=(int dy); 
    bool operator<(const Date & b) const;
};
#endif

#include <iostream>
// #include "date.h"
static int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date()
{
    year = 1900;
    month = 1;
    day = 1;
}
Date::Date(int yr, int mn, int dy)
{
    if ((yr < 0 || mn <= 0) || mn >= 13)
    {
        year = 1900;
        month = 1;
        day = 1;  
    }
    bool isLegal = true;
    bool isM = false;
    if (yr % 40 == 0 || yr % 100 != 0 && yr % 4 == 0)
        isM = true;
    if (mn == 2){
        if (isM && dy > 29)
            isLegal = false;
        else if ((!isM) && dy > 28)
            isLegal = false;
    }
    else if (dy > months[mn-1])
        isLegal = false;

    if (isLegal)
    {
        year = yr;
        month = mn;
        day = dy;
    }
    else
    {
        year = 1900;
        month = 1;
        day = 1;
    }
}
Date::~Date()
{
}
Date & Date::setDate(int yr, int mn, int dy)
{
    *this = Date(yr, mn, dy);
    return *this;
}

std::ostream & operator<<(std::ostream & os, const Date & d)
{
    os << d.year << "-" << d.month << "-" << d.day;
    return os;
}

Date Date::operator+(int dy)
{
    Date tmp = *this;
    Date ans;
    day += dy;
    bool isM = false;
    if (year % 40 == 0 || year % 100 != 0 && year % 4 == 0)
        isM = true;
    if (month == 2){
        if (isM && day > 29){
            day = day - 29;
            month++;
        }
        else if ((!isM) && day > 28){
            day = day - 28;
            month++;
        }
    }
    else{
        if (day > months[month-1]){
            day = day - months[month-1];
            month++;
        }
        if (month > 12){
            month = month - 12;
            year++;
        }
    }
    ans = *this;
    *this = tmp;
    return ans;
}
Date Date::operator++()
{
    *this = *this + 1;
    return *this;
}
Date Date::operator++(int)
{
    Date tmp = *this;
    *this = *this + 1;
    return tmp;
}
Date & Date::operator+=(int dy)
{
    *this = *this + dy;
    return *this;
}
bool Date::operator<(const Date & b) const
{
    if (year < b.year)
        return true;
    else if (year > b. year)
        return false;
    if (month < b.month)
        return true;
    else if (month > b.month)
        return false;
    if (day < b.day)
        return true;
    else if (day > b.day)
        return false;
    return true;
}

#include<iostream>
using namespace std;

int main()
{
     int day,month,year;
     cin>>year>>month>>day;
     Date d1; // 默认值为1900年1月1日
     Date d2(year,month,day); 
     cin>>year>>month>>day;
     Date d3(year,month,day); 

     cout << "d1 is " << d1 << "\nd2 is " << d2 << "\nd3 is " << d3<<endl;
     cout << "d2+=7 is " << ( d2 += 7 )<<endl;

     d3.setDate( d3.getyear(),d3.getmonth(), d3.getday()+5);//重新设置日期，如果新日期非法，则保持原日期不变
     cout << "d3 is " << d3<<endl; //
     cout << "++d3 is " << ++d3 <<endl;

     Date d4( 2002,6,20 );

     cout << "d4 is " << d4 << endl;                        
     cout << "d4++ is " << d4++ << endl;                    
     cout << "d4 is " << d4 << endl;     
     cout << "d3<d4 is "<<((d3<d4)?"true":"false")<<endl;       
     return 0;
}