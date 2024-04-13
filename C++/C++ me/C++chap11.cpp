// 第11章 使用类
// 11.1 运算符重载
// 多态
// 操作数的数目和类型
// 运算符函数
// opratorop(argument-list) // 有效的（已存在的）C++运算符
// oprator函数重载[]运算符，因为[]数组索引运算符？？？？？？？？？？？？？？？？？？？？？？？？？？
// 运算符函数替换上述运算符
// district2 = sid + sara;
// district2 = sid.oprator+(sara);

// 11.2 计算时间：一个重载运算符示例
// 一个使用方法来处理加法的time类
// 一个使用名为Sum的常规方法  => 重载运算符
// 这个方法的类声明
// 程序清单11.1 mytime0.h
// mytime0.h -- Time class before operator overloading
// #ifndef MYTIME0_H_
// #define MYTIME0_H_

// class Time
// {
// private:
//     int hours;
//     int minutes;
// public:
//     Time();
//     Time(int h, int m = 0);                // 原型有默认参数但是定义没有算什么回事啊？？？？？？？？？？？？？？？？？？？
//     void AddMin(int m);     //调整时间
//     void AddHr(int h);      //调整时间
//     void Reset(int h = 0, int m = 0);   // 重新设置时间
//     Time Sum(const Time & t) const;     // 两个时间相加
//     void Show() const;  // 显示时间
// };
// #endif

// // 请注意，当总的分钟数超过59时，AddMin( )和Sum( )方法是如何使用整数除法和求模运算符来调整minutes和hours值的
// // 只用了ostream的cout，且仅一次，故std::cout 比导入整个名称空间更经济

// // 程序清单11.2 mytime0.cpp
// // mytime0.cpp -- implementing Time methods
// #include <iostream>
// // #include "mytime0.h"

// Time::Time()
// {
//     hours = minutes = 0;
// }

// Time::Time(int h, int m) //= 0)
// {
//     hours = h;
//     minutes = m;
// }

// void Time::AddMin(int m)
// {
//     minutes += m;
//     hours += minutes / 60;// 应先对hours处理，不然minutes都变少了，肯定加不了//♥
//     minutes %= 60;//♥//♥//♥//♥//♥//♥//♥//♥//♥//♥//♥//♥//♥//♥//♥//♥//♥//♥//♥//♥//♥//♥//♥//♥//♥
//     // hours += minutes / 60;
// }

// void Time::AddHr(int h)
// {
//     hours += h;
// }

// void Time::Reset(int h, int m) //= 0; int m = 0)
// {
//     hours = h;
//     minutes = m;
// }

// Time Time::Sum(const Time & t) const
// {
//     Time sum;
//     sum.minutes = minutes + t.minutes;
//     sum.hours = hours + t.hours + sum.minutes / 60;
//     // sum.hours += sum.minutes / 60;
//     sum.minutes %= 60;
//     return sum;
// }

// void Time::Show() const
// {
//     std::cout << hours << " hours, " << minutes << " minutes";
// }

// 程序清单11.3 usetime0.cpp
// usetime0.cpp -- using the first draft of the Time class
// compile usetime0.cpp and mytime0.cpp together
// #include <iostream>
// // #include "mytime0.h"

// int main()
// {
//     using std::cout;
//     using std::endl;
//     Time planning;
//     Time coding(2, 40);
//     Time fixing(5, 55);
//     Time total;

//     cout << "planning time = ";
//     planning.Show();
//     cout << endl;

//     cout << "coding time = ";
//     coding.Show();
//     cout << endl;

//     cout << "fixing time = ";
//     fixing.Show();
//     cout << endl;

//     total = coding.Sum(fixing);
//     cout << "coding.Sum(fixing) = ";
//     total.Show();
//     cout << endl;

//     return 0;
// }

// #include <iostream>
// using namespace std;
// void f (int n, int k);

// // void f(int n = 111, int k);

// int main()
// {
//     // f();
//     f(1, 3);
//     f(1);
// }

// void f (int n, int k = 111){
//     cout << n << "\t" << k << endl;
// }
// // void f (int n, int k){
    
// // }

// #include<iostream>

// void f(int n = 1, int k);
// void f(int n, int k = 1);
// // void f(int n, int k);
// // void f(int n, int k);
// // void f(int n, int k);
// // void f(int n, int k);
// int main(){
//     f();
// }
// void f(int n,int k) {
// std::cout << n << "\t"   << k << std::endl;
// }

// 11.2.1 添加加法运算符
// 把Time类转换为重载的加法运算符
// Sum()名称改为opeator+()
// ????????????????????????????????在标识符中使用字母数字下划线之类的其他字符
// 程序清单11.4 mytime1.h
// mytime1.h -- Time class before operator overloading
// #ifndef MYTIME1_H_
// #define MYTIME1_H_
// class Time
// {
// private:
//     int hours;
//     int minutes;
// public:
//     Time();
//     Time(int h, int m = 0);
//     void AddHr(int h);
//     void AddMin(int m);
//     void Reset(int h = 0, int m = 0);
//     Time operator+(const Time & t) const;
//     void Show() const;
// };
// #endif

// // 程序清单11.5 mytime1.cpp
// // mytime1.cpp -- implementing Time methods
// #include <iostream>
// // #include "mytime1.h"

// Time::Time()
// {
//     hours = minutes =0;
// }

// Time::Time(int h, int m)
// {
//     hours = h;
//     minutes = m;
// }

// void Time::AddHr(int h)
// {
//     hours += h;
// }

// void Time::AddMin(int m)
// {
//     minutes += m;
//     hours += minutes / 60;
//     minutes %= 60;
// }

// void Time::Reset(int h, int m)
// {
//     hours = h;
//     minutes = m;
// }

// Time Time::operator+(const Time & t) const
// {
//     Time sum;
//     sum.minutes = minutes + t.minutes;
//     sum.hours = hours + t.hours + sum.minutes / 60;
//     sum. minutes %= 60;
//     return sum;
// }

// void Time::Show() const
// {
//     std::cout << hours << " hours, " << minutes << " minutes";
// }

// 程序清单11.6 usetime1.cpp
// usetime1.cpp -- using the second draft of Time class
// compile usetime1.cpp and mytime1.cpp together
// #include <iostream>
// // #include "mytime1.h"
// int main()
// {
//     using std::cout;
//     using std::endl;
//     Time planning;
//     Time coding(2, 40);
//     Time fixing(5, 55);
//     Time total;

//     cout << "planning time = ";
//     planning.Show();
//     cout << endl;

//     cout << "coding time = ";
//     coding.Show();
//     cout << endl;

//     cout << "fixing time = ";
//     fixing.Show();
//     cout << endl;

//     total = coding + fixing;
//     // operator notation
//     cout << "coding + fixing = ";
//     total.Show();
//     cout << endl;

//     Time morefixing(3, 28);
//     cout << "more fixing time = ";
//     morefixing.Show();
//     cout << endl;
//     total = morefixing.operator+(total);
//     // total += morefixing; //+=另作一个运算符，不可以在重载了+之后就用+=
//     // function notation
//     cout << "morefixing.operator+(total) = ";
//     total.Show();
//     cout << endl;

//     return 0;
// }

// t4 = t1 + t2 + t3; // 可以
// // t4 = (t1.operator+(t2)).operator+(t3);//不是这样的？？？？？？？？？？？！！！！！！！！！！！
// t4 = t1.oeprator+(t2 + t3);//应该不是这个是上面那个吧
// t4 = t1.operator+(t2.operator+(t3));





// #include <iostream>

// using namespace std;

// class Demo {
// private:
// int val;

// public:
//     Demo(const int& x) : val(x) {}

//     Demo operator+(const Demo& rhs) const {
//     cout << "operator+() " << val << " += " << rhs.val << endl;
//     return Demo(val + rhs.val);
//     }

//     friend ostream& operator<<(ostream& os, const Demo& obj) {
//     os << obj.val;
//     return os;
// }
// };

// int main() {
//     Demo a(1);
//     Demo b(2);
//     Demo c(3);

//     Demo d = a + b + c;
//     Demo e = a.operator+(b).operator+(c);

//     cout << d << endl;
//     return 0;
// }

// 11.2.2 重载限制
// 至少一个操作数是用户定义的类型
// 不能违反原来的句法规则
//      不能修改运算符优先级（重载和原来的运算符具有相同优先级）
// 不能创建新的运算符
// 不能重载某些运算符
// 大多运算符可以通过成员函数or非成员函数重载，=，(),[],->只能通过成员函数重载
// 明智限制：名称具有说明性

// 11.2.3 其他重载运算符
// Time operator-(const Time & t) const;// 两个时间相减
// Time operator*(double n) const;         // 时间乘一个因子
// 程序清单11.7 mytime2.h
// mytime2.h -- Time class after operator overloading
// #ifndef MYTIME2_H_
// #define MYTIME2_H_
// class Time
// {
// private:
//     int hours;
//     int minutes;
// public:
//     Time();
//     Time(int h, int m = 0);
//     void AddHr(int h);
//     void AddMin(int m);
//     void Reset(int h = 0, int m = 0);
//     Time operator+(const Time & t) const;
//     Time operator-(const Time & t) const;
//     Time operator*(double n) const;
//     void Show() const;
// };
// #endif

// // 程序清单mytime2.cpp
// // mytime2.cpp -- implementing Time methods
// #include <iostream>
// // #include "mytime2.h"

// Time::Time()
// {
//     hours = minutes = 0;
// }

// Time::Time(int h, int m)
// {
//     hours = h;
//     minutes = m;
// }

// void Time::AddHr(int h)
// {
//     hours += h;
// }

// void Time::AddMin(int m)
// {
//     minutes += m;
//     hours += minutes / 60;
//     minutes %= 60;
// }

// void Time::Reset(int h, int m)
// {
//     hours = h;
//     minutes = m;
// }

// Time Time::operator+(const Time & t) const
// {
//     Time sum;
//     sum.minutes = minutes + t.minutes;
//     sum.hours = hours + t.hours + sum.minutes / 60;
//     sum.minutes %= 60;
//     return sum;
// }

// Time Time::operator-(const Time & t) const
// {
//     Time mi;
//     mi.minutes = minutes - t.minutes;
//     mi.hours = hours - t.hours;
//     if (mi.hours > 0 && mi.minutes < 0){
//         mi.hours--;
//         mi.minutes += 60;
//     }
// }
// Time Time::operator-(const Time & t) const
// {
//     Time diff;
//     int tot1, tot2;
//     tot1 = t.hours * 60 + t.minutes;
//     tot2 = hours * 60 + minutes;//咋额能用两个t的呢
//     diff.hours = (tot2 - tot1) / 60;
//     diff.minutes = (tot2 - tot1) % 60;      // 可以注意一下小减大的会如何处理余数。
//     return diff;//别忘了返回！
// }

// // Time Time::operator*(double n) const
// // {
// //     Time c;
// //     c.minutes = n * minutes;
// //     c.hours = n * hours + c.minutes / 60;            // 这样的话，貌似hoours和minutes都四舍五入，hours四舍五入造成大量损耗
// //     c.minutes %= 60;
// //     return c;//记得该返回的返回呀！
// // }

// Time Time::operator*(double mult) const
// {
//     Time result;
//     long totalminutes = hours * 60 * mult + minutes * mult;
//     result.hours = totalminutes / 60;
//     result.minutes = totalminutes % 60;
//     return result;
// }

// void Time::Show() const
// {
//     std::cout << hours << " hours, " << minutes << " minutes";
// }

// // 程序清单11.9 usetime2.cpp
// // usetime2.cpp -- using the third draft of Time class
// // compile usetime2.cpp and mytime2.cpp together
// #include <iostream>
// // #include "mytime2.h"

// int main()
// {
//     using std::cout;
//     using std::endl;
//     Time weeding(4, 35);
//     Time waxing(2, 47);
//     Time total;
//     Time diff;
//     Time adjusted;

//     cout << "weeding time = ";
//     weeding.Show();
//     cout << endl;

//     cout << "waxing time = ";
//     waxing.Show();
//     cout << endl;

//     cout << "total work time = ";
//     total = weeding + waxing;       // sue operator+()
//     total.Show();
//     cout << endl;

//     diff = weeding - waxing;       // use operator-()
//     cout << "weeding time - waxing time = ";
//     diff.Show();
//     cout << endl;                   // 可以注意一下负的会如何处理。

//     adjusted = total * 1.5;         // use operator*()
//     cout << "adjusted work time = ";
//     adjusted.Show();
//     cout << endl;

//     return 0;
// }

// 11.3 友元
// friend Time operator * (douoble m, const Time & t);  // goes in class declaration
// // 原型放在类声明中，but不是成员函数，不能用成员运算符调用
// // 不是成员函数，but访问权限相同
// // 编写函数定义
// // 不是成员函数，不用Time::运算符，不在定义中使用关键字friend
// Time operator * (double mult, Time const & t)  // friend not used in definition
// {
//     Time result;
//     long totalminutes// long tot;
//     totalminutes = hours * 60 * mult + minutes * mult;// tot = t.hours * 60 + t.minutes;
//     result.hours = totalminutes / 60;// result.hours = tot * mult / 60;
//     result.minutes = totalminutes % 60;// result.minutes = tot * mult % 60;
//     return result;
// }

// A = 2.75 * B;
// A = operator*(2.75, B);

// Time operator*(double m, const Time & t)
// {
//     return t * m;   // use t.operator*(m)
// }
// 显式访问类私有数据——友元
// 用成员函数处理类私有数据——不必是友元
        // 但该版本作友元也是个选择，1作为正式类接口的组成部分，2发现需要函数直接访问私有数据，只需修改函数定义，不必改类原型

// 11.3.2 常用的友元：重载 << 运算符
// 1.<< 的第一种重载版本
// 必须用友元函数（第一个是ostream对象而不是Time对象，不适合在iostream文件里修改）
// ostream & showTime(ostream & os, const Time & t)// 这样命名你重载什么运算符嘛
// {
//     os << t.hours << " hours, " << t.minutes << " minutes";
//     return os;
// }
// 为什么是void，无返回值呢？
// void operator<<(ostream & os, const Time & t)// 为什么os不const？
// {
//     os << t.hours << " hours, " << t.minutes << " minutes";
// }

// 2 << 的第二种版本
// #include <fstream>
// //...
// fstream fout;
// fout.open("savetime.txt");
// Time trip(12, 40);
// fout << trip;

// operator<<(fout, trip);

// // 程序清单11.10 mytime3.h
// // mytime3.h -- Time class with friends
// #ifndef MYTIME3_H_
// #define MYTIME3_H_
// #include <iostream>
// class Time
// {
// private:
//     int hours;
//     int minutes;
// public:
//     Time();
//     Time(int h, int m = 0);
//     void AddMin(int h);
//     void AddHr(int m);
//     void Reset(int h = 0, int m = 0);
//     Time operator+(const Time & t) const;
//     Time operator-(const Time & t) const;
//     Time operator*(double m) const;
//     friend Time operator*(double m, const Time & t)
//         {   return t * m; }     // inline definition
//     friend std::ostream & operator<<(std::ostream & os, const Time & t);
// };    //名称空间限定符std::!!!!!!!!!!!!!
// #endif

// // 程序清单11.11 mytime3.cpp
// //mytime3.cpp -- implementing Time methods
// // #include "mytime3.h"

// Time::Time()
// {
//     hours = minutes = 0;
// }
// Time::Time(int h, int m)
// {
//     hours = h;
//     minutes = m;
// }
// void Time::AddMin(int m)
// {
//     minutes += m;
//     hours += minutes / 60;
//     minutes %= 60;
// }
// void Time::AddHr(int h)
// {
//     hours += h;
// }
// void Time::Reset(int h, int m)
// {
//     hours = h;
//     minutes = m;
// }
// Time Time::operator+(const Time & t) const
// {
//     Time sum;
//     sum.minutes = minutes + t.minutes;
//     sum.hours = hours + t.hours + sum.minutes / 60;
//     sum.minutes %= 60;
//     return sum;
// }
// Time Time::operator-(const Time & t) const
// {
//     Time ans;//diff
//     int tot1, tot2;//不是long
//     tot2 = hours * 60 + minutes;//tot1,tot2顺序
//     tot1 = t.hours * 60 + t.minutes;
//     ans.minutes = (tot2 - tot1) % 60;
//     ans.hours = (tot2 - tot1) / 60;
//     return ans;
// }
// Time Time::operator*(double mult) const
// {
//     Time result;
//     long totalminutes = hours * mult * 60 + minutes * mult;
//     // tot = hours * 60 * mult + minutes * mult;
//     result.hours = totalminutes / 60;
//     result.minutes = totalminutes % 60;
//     return result;
// }
// std::ostream & operator<<(std::ostream & os, const Time & t) 
// {
//     os << t.hours << " hours, " << t.minutes << " minutes";
//     return os;
// }

// // 程序清单11.12 usetime3.cpp
// // usetime3.cpp -- using the fourth draft of Time class
// // compile usetime3.cpp and mytime3.cpp together
// #include <iostream>
// // #include "mytime3.h"

// int main()
// {
//     using std::cout;
//     using std::endl;
//     Time aida(3, 35);
//     Time tosca(2, 48);
//     Time temp;

//     cout << "Aida and Tosca:\n";
//     cout << aida << "; " << tosca << endl;
//     temp = aida + tosca;    // operator+()
//     cout << "Aida + Tosca: " << temp << endl;
//     temp = aida * 1.17;     // member operator*()
//     cout << "Aida * 1.17: " << temp << endl;
//     cout << "10.0 * Tosca: " << 10.0 * tosca << endl;

//     return 0;
// }

// 11.4 重载运算符：作为成员函数还是非成员函数
// 成员函数版本：少一个参数，因为其中一个操作数是被隐式传递的调用的对象
// 非成员函数版本：参数数目与操作数数目相同（一般是友元函数，方可访问类私有数据）
// 二选一，不可同时，否则二义性错误，导致编译错误
// which？
// 有的只能成员函数
// 其他，二者没什么区别
// but有时根据类设计，非成员函数版本可能较好（为类定义类型转换时）（详见“转换与友元”）

// 11.5 再谈重载
// 包含重载运算符和友元的类设计
// 矢量，相加
// 类and重载运算符
// 二维
// 大小+长度，分量x，y
// 1.类描述中将包含两种表示形式
// 2.修改一种表示后，自动更新另一种
// 3.复习名称空间，将类声明放在名称空间中
// 4.枚举创建两个常量，标识两种表示法
// 程序清单1.13 vector.h
// vect.h -- Vector class with <<, mode state
// #ifndef VECTOR_H_
// #define VECTOR_H_
// #include <iostream>
// namespace VECTOR
// {
//     class Vector
//     {
//     public:
//         enum Mode{RECT, POL};
//     // RECT for rectangular, POL for polar modes
//     private:
//         double x;   // horizontal value;
//         double y;   // vertical value
//         double mag; // length of vector
//         double ang; // direction of vector in degrees
//         Mode mode;  // RECT or POL
//     // private methods for setting values
//         void set_mag();
//         void set_ang();
//         void set_x();
//         void set_y();
//     public:
//         Vector();
//         Vector(double n1, double n2, Mode form = RECT);
//         void reset(double n1, double n2, Mode form = RECT);
//         ~Vector();
//         double xval() const { return x; }       // report x value
//         double yval() const { return y; }       // report y value
//         double magval() const { return mag; }   // report magnitude
//         double angval() const { return ang; }   // report angle
//         void polar_mode();      // set mode to POL
//         void rect_mode();       // set mode to RECT
//     // operator overloading
//         Vector operator+(const Vector & b) const;
//         Vector operator-(const Vector & b) const;
//         Vector operator-() const; //?????????????????不懂就问，这是要干什么？
//         Vector operator*(double n) const;
//     // friends
//         friend Vector operator*(double n, const Vector & a);
//         friend std::ostream & 
//                 operator<<(std::ostream & os, const Vector & v);
//     };
// }   // end namespace VECTOR
// #endif

// // 程序清单11.14 vector.cpp
// // 1.名称空间开放性
// // 2.构造函数和Reset函数都设置了矢量的直角坐标和极坐标表示，需要时直接使用
// // 3.C++内置数学类型使用角度时用弧度表示
// //    函数在度和弧度之间转换
// // summ隐藏极坐标和直接坐标之间的转换，弧度与度之间的转换。
// //     用户只需知道：类在<<使用>>角度时以度为单位，可以用两种等价形式表示矢量
// // 程序清单1.14 vector.cpp
// // vect.cpp -- methods for the Vector class
// #include <cmath>
// // #include "vect.h"        // include <iosteam>
// using std::sqrt;
// using std::sin;
// using std::cos;
// using std::atan;
// using std::atan2;
// using std::cout;

// namespace VECTOR
// {
//     // compute degrees in one radian
//     const double Rad_to_deg = 45.0 / atan(1.0);
//     // should be about 57.2957795130823
    
//     // private methods
//     // calculates magnitude from x and y
//     void Vector::set_mag()
//     {
//         mag = sqrt(x * x + y * y);
//     }
//     //  // 自：calculate angle from x and y
//     void Vector::set_ang()
//     {
//         if ( x == 0.0 && y == 0.0)//wow!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!x,y分别为0，atan2内考虑了是吗
//             ang = 0.0;
//         else
//             ang = atan2(y, x);//为什么是atan2？atan1和atan2？？？？？？？？？？？？？？？？？？？？
//     }
//     // set x from polar coordinate
//     void Vector::set_x()
//     {
//         x = mag * cos(ang);
//     }
//     // set y from polar coordinate
//     void Vector::set_y()
//     {
//         y = mag * sin(ang);// y = mag * sin(ang/360 * 2 * PI());
//     }
// // public methods
//     Vector::Vector()            // default constructor
//     {
//         x = y = mag = ang = 0.0;
//         mode = RECT;//别忘了设置mode啊
//     }
    
//     // construct vector from rectangular coordinates if firm is r
//     // (the default) or else from polar coordinates if form is p
//     Vector::Vector(double n1, double n2, Mode form)// 默认参数在函数原型有了就行叭
//     {
//         mode = form;//!!!
//         if (form == RECT)
//         {
//             x = n1;
//             y = n2;
//             set_mag();
//             set_ang();
//         }
//         else if (form == POL)
//         {
//             mag = n1;
//             ang = n2 / Rad_to_deg;
//             set_x();
//             set_y();
//         }
//         else // 来自书
//         {
//             cout << "Incorrect 3rd argument to Vector() -- ";
//             cout << "Vector set to 0\n";
//             x = y = mag = ang = 0.0;
//             mode = RECT;
//         }
//     }

//     // reset vector from rectangular coodinates if form is
//     // RECT (the default) or else from polar coodinates if
//     // form is POL
//     void Vector::reset(double n1, double n2, Mode form)
//     {
//         mode = form;        //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//         if (form == RECT)
//         {
//             x = n1;
//             y = n2;
//             set_mag();
//             set_ang();
//         }
//         else if (form == POL)
//         {
//             mag = n1;
//             ang = n2 / Rad_to_deg;//deg = rad * rad to deg, rad = deg . rad_to_deg
//             set_x();
//             set_y();
//         }
//         else
//         {
//             cout << "Incorrect 3rd argument to Vector() -- ";
//             cout << "vector set to 0\n";
//             x = y = mag = ang = 0.0;
//             mode = RECT;
//         }
//     }
//     Vector::~Vector()   // destructor
//     {
//     }
//     void Vector::polar_mode()
//     {
//         mode = POL;
//     }
//     void Vector::rect_mode()
//     {
//         mode = RECT;
//     }
//     // operator overloading
//     // add two Vectors
//     Vector Vector::operator+(const Vector & b) const
//     {
//         // Vector sum;
//         // sum.x = x + b.x;
//         // sum.y = y + b.y;
//         // sum.set_mag();
//         // sum.set_ang();
//         // return sum;
//         return Vector(x+b.x, y+b.y);
//     }

//     // subtract b from a
//     Vector Vector::operator-(const Vector & b) const
//     {
//         // Vector diff;
//         // diff.x = x - b.x;
//         // diff.y = y - b.y;
//         // diff.set_mag();
//         // diff.set_ang();
//         // return diff;
//         return Vector(x - b.x, y - b.y);
//     }

//     // reverse sign from Vector
//     Vector Vector::operator-() const
//     {
//         return Vector(-x, -y);
//     }

//     Vector Vector::operator*(double n) const
//     {
//         // Vector result;
//         // result.x = x * n;// x *= n;
//         // result.y = y * n;// y *= n;你在干嘛。。。。。。。
//         // result.set_mag();
//         // result.set_ang();
//         return Vector(x * n, y * n);
//     }
//     //friends
//     Vector operator*(double n, const Vector & a)
//     {
//         return a * n;
//     }
//     std::ostream & operator<<(std::ostream & os, const Vector & v)
//     {
//         if (v.mode == Vector::RECT)
//             os << "(x,y) = (" /*<< "(" */<< v.x << ", " << v.y << ")"; //<< std::endl;
//         else if (v.mode == Vector::POL)//友元函数，不可直接用POL
//         {
//             os << "(m,a) = (" << v.mag << ", " 
//                 << v.ang * Rad_to_deg << ")";//"polar: " << "(" << v.mag << ", " << v.ang << ")" << std::endl;
//         }
//         else
//             os << "Vector object mode is invalid";
//         return os;
//     }
// }

// 11.5.1 使用状态成员
// mode,状态成员，描述的是对象所处的状态
// 未限定的名称，全限定名，有原函数也要写明类（至少
// 多种表示方式和类，储存多种表示方式，or存一种，用方法提供其他表示方式，
//      通过内部处理，类允许从本质而不是表达方式上看待一个量

// 11.5.2 为Vector类重载算术运算符
// 两个矢量和相加
// 自己的方法是可以的，先解决x,y,然后解决mag,ang,
// 使用构造函数完成这种工作更简单可靠
// Vector Vector::operator+(const Vector & b) const
// {
//     return Vector(x + b.x, y +b.y);
// }

// 1.乘法
// Vector Vector::operator*(double n) const
// {
//     return Vector(x * n, y * n);
// }
// // 内联友元函数处理double和Vector相乘
// friend/为什么不要写friend？ Vector operator*(double n, const Vector & a) // friend function
// {
//     return a * n;   // convert double times Vector to Vector times double;
//     //retur Vector * n 你是在干嘛
// }

// 2.对已重载的运算符进行重载
// C++中，-已经有两种含义
// 二元运算符，两个操作数，减法运算符
// 一元运算符，一个操作数，负号运算符
// Vector operator-(const Vector & b) const;       // prototype
// Vector Vector::operator-(const Vector & b) const
// {
//     return Vector(x - b.x, y - b.y);
// }
// // 居然是可以把右边的操作数（类对象）作为调用方法的对象吗 //还是说右结合啊？
// Vector operator-() const;// 括号里面还写一个const Vector & b是在干什么啊啊啊啊啊啊
// Vector Vector::operator-() const
// {
//     return Vector(-x, -y);
// }

// 11.5.3 对实现的说明
// 储存了直角坐标和矢量坐标，共有接口不依赖于这一事实
// 考虑所有接口的要求，都只限于能够显示两种表示，返回各个值，——内部实现可以不同
// 正如：只存x，y，返回长度magval方法根据x，y计算长度，而不是查找
// =>改变实现，用户接口不变
// ❤接口与实现分离是OOP的目标之一，这样允许对实现进行调整，而无需修改使用这个类的程序中的代码

// 各有优势，内存，更新，易于查找（常用值时）
// （偶尔使用）另一种只存一对的
// 可以不同的程序用的实现不同，但接口相同

// 11.5.4 使用Vector类来实现漫步
// randwalk.cpp -- using the Vector class
// compile with the vect.cpp file
// #include <iostream>
// #include <cstdlib>      // rand(), srand() prototypes
// #include <ctime>        // time() prototype
// // #include "vect.h"
// int main()
// {
//     using namespace std;
//     using VECTOR::Vector;
//     srand(time(0));     // seed random-number generator
//     double direction;
//     Vector step;
//     Vector result(0.0, 0.0);
//     unsigned long steps = 0;
//     double target;
//     double dstep;
//     cout << "Enter target distance (q to quit): ";
//     while (cin >> target)                                   // ❤❤❤❤❤❤❤❤❤❤❤❤❤❤❤❤❤❤❤❤❤❤❤❤❤❤❤❤❤
//     {
//         cout << "Enter step length: ";
//         if (!(cin >> dstep))
//             break;
        
//         while (result.magval() < target)
//         {
//             direction = rand() % 360;
//             step.reset(dstep, direction, Vector::POL);
//             result = result + step;
//             steps++;
//         }
//         cout << "After " << steps << " steps, the subject "
//                 << "has the following location:\n";
//         cout << result << endl;
//         result.polar_mode();
//         cout << " or\n" << result << endl;
//         cout << "Average outward distance per step = "
//             << result.magval()/steps << endl;
//         steps = 0;
//         result.reset(0.0, 0.0);
//         cout << "Enter target distance (q to quit): ";
//     }
//     cout << "Bye!\n";
//     cin.clear();                                            //值得注意的循环条件和相关处理呢！！！！！！！
//     while (cin.get() != '\n')                               
//         continue;
//     return 0;
// }

// 11.6 类的自动类型转换和强制类型转换
// C++如何处理用户定义类型的转换？
// 回顾：
    // // C++如何处理内置类型转换的
    // // 标注类型变量间赋值，若类型相容，自动类型转换
    // long count = 8;     // int value 8 converted to type long
    // double time = 11;   // int value 11 converted to type double
    // int side = 3.33;    // double value 3.33 converted to type int 3
    // // 1表示相同的东西，2包含用于进行转换的内置规则
    // // 不自动转换不相兼容的类型
    // int * p = 10;   // type clash
    // // 但可以进行强制类型转换
    // int * p = (int *) 10;   // ok, p and (int *) 10 both pointers
    // // 可以将类定义与基本类型或另一个类相关，使得从一种类型转换为另一种类型是有意义的
    // // 那么，程序员可以指示C++如何进行类型转换，或通过强制类型转换来完成
// 两种方式，磅和英石表示重量
// 程序清单11.16 stonewt.h
// 程序清单11.16 stonewt.h
// stonewt.h -- definition for the Stonewt class// stonewt.h -- definition for the stonewt class
// #ifndef STONEWT_H_
// #define STONEWT_H_
// class Stonewt
// {
// private:
//     enum{ Lbs_per_stn = 14 };  // pounds per stone
//     int stone;                 // whole stones
//     double pds_left;           // fractional pounds     // 啥意思，干啥的？
//     double pounds;             // entire weight in punds
// public:
//     Stonewt(double lbs);        // constructor for double pounds
//     Stonewt(int stn, double lbs);   // constructor for stone, lbs
//     Stonewt();                  // default constructor
//     ~Stonewt();
//     void show_lbs() const;      // show weight in punds format
//     void show_stn() const;      // show weight in stone format
// };
// #endif

// // 程序清单11.17 stonewt.cpp
// #include <iostream>
// using std::cout;
// // #include "stonewt.h"

// // construct Stonewt object from double value
// Stonewt::Stonewt(double lbs)
// {
//     stone = int (lbs) / Lbs_per_stn;
//     pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);//这个lbs - int(lbs)就很妙
//     pounds = lbs;
// }
// Stonewt::Stonewt(int stn, double lbs)
// {
//     stone = stn;
//     pds_left = lbs;
//     pounds = stn * Lbs_per_stn + lbs;
// }
// Stonewt::Stonewt()  // default constructor, wt = 0.0
// {
//     stone = pds_left = pounds = 0.0;// 别把int的stone放前面，虽然这里没啥影响
// }
// Stonewt::~Stonewt()     // destructor
// {
// }
// //show weight in stones
// void Stonewt::show_stn() const
// {
//     cout << stone << " stone, " << pds_left << " pounds\n";
// }
// // show weight in pounds
// void Stonewt::show_lbs() const
// {
//     cout << pounds << " pounds\n";
// }

// // 只需一个实参的构造函数可供于类型转换
// // explicit可以禁止其用于用赋值运算符的隐式转换// 显示转换仍可以
// // Stonewt myCat;
// // myCat = 19.6;//隐式自动类型转换，可以对构造函数使用关键字ecplicit来禁止
// // myCat = Stonewt(19.6);//显式调用构造函数
// // mycat = (Stonewt)19.6;//显式强制类型转换

// // 程序清单11.18 stone.cpp
// // stone.cpp -- user-defined conversions
// // compile with stonewt.cpp
// #include <iostream>
// using std::cout;
// // #include "stonewt.h"
// void display(const Stonewt & st, int n);
// int main()
// {
//     Stonewt incognito = 275;    // use constructor to initialize
//     Stonewt wolfe(285.7);       // same as Stonewt wolfe
//     Stonewt taft(21, 8);

//     cout << "The celebrity weighed ";
//     incognito.show_stn();
//     cout << "The detective weighed ";
//     wolfe.show_stn();
//     cout << "The President weighed ";
//     taft.show_lbs();
//     incognito = 276.8;      // uses constructor for conversion
//     taft = 325;             // same as taft = Stonewt(325);
//     cout << "After dinner, the celebrity weighed ";
//     incognito.show_stn();
//     cout << "After dinner, the President weighed ";
//     taft.show_lbs();
//     display(taft, 2);
//     cout << "The wrestler weighed even more.\n";
//     display(422, 2);
//     cout << "No stone left unearned\n";
//     return 0;
// }

// void display(const Stonewt & st, int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         cout << "Wow! ";
//         st.show_stn();
//     }
// }

// 11.6.1 转换函数
// 某种类型到类->构造函数
// 相反的转换（把类转换成某类型）转换函数
// 强制类型转换
// 例如
// Stonewt wolfe(285.7);
// double host = double(wolfe);        // #stntax #1
// double thinker = (double) wolfe;    // #stntax #2
//  也可以让编译器决定怎么做
// Stonest wells(20, 3);
// double star = wells;                // implicit use of conversion function

// 转换函数的形式
// operator typeName();
// typeName指出了要转换成的类型，so不需要指定返回类型 //但不需要指定不是不需要返回
// 转换函数是类方法，即由类对象调用，从而告知函数要转换成的值，因此不需要参数
// 没有常规指定返回类型，但也返回所需的值

// 要将stonewt类型转换成int和double类型，需要在类声明下列函数原型
// operator int();
// operator double();

// 程序清单11.19
// 修改后的类声明
// 程序清单1.19 stonewt1.h
// stonewt1.h -- revised definition for the Stonewt class
#ifndef STONEWT1_H_
#define STONEWT1_H_
class Stonewt
{
private:
    enum {Lbs_per_stn = 14};    // pounds per stone
    int stone;                  // whole stone
    double pds_left;            // fractional pounds
    double pounds;              // entire weight in pounds
public:
    explicit Stonewt(double lbs);
    Stonewt(int stn, double lbs);
    Stonewt();
    ~Stonewt();
    void show_lbs() const;
    void show_stn() const;
// conversion functions
    operator int() const;
    explicit operator double() const;// 只加一个explicit，可以先转int再转double曲线救国
};
#endif

// 程序清单 11.20
// 11.18修改，包括了两个转换函数的定义
// attention:!!没有声明返回类型，但两个函数也返回所需要的值
// 以及！！！！！int将转换为四舍五入的整数，而不是去掉小数部分
#include <iostream>
using std::cout;
// #include "stonewt1.h"

// construct Stonewt object from double value
Stonewt::Stonewt(double lbs)
{
    pounds = lbs;
    stone = int (lbs) / Lbs_per_stn;    // integer division
    //stone = lbs / Lbs_per_stn;  // 否则不是整数除法又如何？
    pds_left = (int) lbs % Lbs_per_stn + lbs - int (lbs); /// pds_left = lbs - stone * Lbs_per_stn;
}
// construct Stonewt object from int, double values
Stonewt::Stonewt(int stn, double lbs)
{
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_per_stn + lbs;
}
Stonewt::Stonewt()      // default constructor, wt = 0
{
    stone = pds_left = pounds = 0.0;
}
Stonewt::~Stonewt()     // destructor
{
}
void Stonewt::show_lbs() const
{
    cout << pounds << " pounds\n";
}
void Stonewt::show_stn() const
{
    cout << stone << " stone, " << pds_left << " pounds\n";
}
// conversion functions
Stonewt::operator double() const
{
    return pounds;
}
// Stonewt::operator int() const
// {
//     if (pds_left * Lbs_per_stn >= 0.5)
//         return stone+1;
//     return stone;
// }
// return的都是pounds计量的，不是一个pounds一个stone计量的
// 条件判断0.5比大小可以，以下方法更简洁
// 妙蛙种子！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
Stonewt::operator int() const
{
    return int (pounds + 0.5);//可以不强制转，自动转吗？
}

// 程序清单11.21 测试，赋值语句隐式转换，cout语句用显示转换
// 程序清单11.21 stone1.cpp
// stone1.cpp -- user-defined conversion functions
#include <iostream>
// #include "stonewt1.h"

int main()
{
    using std::cout;
    Stonewt poppins(9, 2.8);    // 9 stone, 2.8 piounds
    double p_wt = poppins;      // implicit oconversion
    cout << "Convert to double => ";
    cout << "Poppins " << p_wt << " pounds.\n";
    cout << "Convert to int => ";
    cout << "Poppins " << (int)poppins << " pounds.\n";
    return 0;
}

// 区分使用构造函数的隐式和显式表示法
// 以及类型转换的显式与隐式
// 而explixcit是用于控制类型转换方面的显式
// class Stonewt
// {
// // conversion functions
//     explicit operator int() const;
//     explicit operator double() const;
// }

// 防止隐式转换方法1 关键字explicit
// 例如，上面
// 防止隐式转换方法2
//      用一个功能相同的非转换函数替换转换函数，那么只有显式调用时函数才会执行
// 例如，以下
// Stonewt::operator int()
// {
//     return int (pounds + 0.5);
// }
// //替换为
// int Stonewt::Stone_to_Int()
// {
//     return int (pounds + 0.5);
// }
// //那么，以下语句非法
// int plb = poppins;
// //类型转换只能用以下语句
// int plb = poppins.Stone_to_Int();

// 类型转换
// 在函数声明用关键字explicit防止隐式转换，只允许显示转换
// 1.
// 可以只接受一个参数的构造函数，给出实参类型合适时自动调用，
// 使得赋值时将实参转换成类
// 2.
// 转换函数，形式为operator typeName(),无参数无返回值，/ 赋值or强制转换被调用
// 将类（调用对象）转换成typeName类型

// 11.6.2 转换函数和友元函数
// 成员函数（出于简化的目的，假设没有定义operator double()转换函数？？？？？？？？？？？？？？？？？简化了什么？）
Stonewt Stonewt::operator+(const Stonewt & st)
{
    double pds = pounds + st.pounds;
    Stonewt sum(pds);   // 妙啊可以这样用构造函数来简化加法实现，不需要一个个私有数据赋值！
    return sum;
}
// 友元函数
Stonewt operator+(const Stonewt & st1, const Stonewt & st2)
{
    double pds = st1.pounds + st2.pounds;
    Stonewt sum(pds);
    return sum;
}

// 重载加法成员函数不允许double和类相加
// 重载加法友元函数允许double在前和类相加
//      这没有意义，因为只有类对象才可以调用成员函数。C++不会试图将pennyD转换为Stonewt对象。
// 将对成员函数参数进行转换，而不是调用成员函数的对象。
//  （因为类型转换对成员函数参数可以进行，对调用成员函数的对象不可以）

//实现加法的选择
//目的：实现double在前与类相加
//方法1：友元函数接受两个类对象参数，依赖于隐式类型转换
        // 程序短，工作少，出错概率少，
        // 调用构造函数完成隐式类型转换，增加时间和内存开销
        //适合偶尔用此加法
//方法2：一个解决类和double的成员函数，double作为参数
//      一个解决double和类相加的友元函数，double和类依次作为参数
        // 程序长，工作多
        // 运行速度较快
        //适合常用，需要次数多