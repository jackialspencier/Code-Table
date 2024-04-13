// 第九章 内存模型和名称空间
//new定位运算符
//控制访问权的另一种方式（名称空间）
// 9.1 单独编译
// 9.2 存储持续性、作用域和链接
// 9.3 名称空间

// 9.1 单独编译
// 程序清单9.1 coordin.h
// coordin.h -- structure templates and function prototypes
// structure templates
// #ifndef COORDIN_H_
// #define  COORDIN_H_

// struct polar
// {
//     double distance;
//     double angle;
// };
// struct rect
// {
//     double x;
//     double y;
// };

// //prototype
// polar rect_to_polar(rect xypos);
// void show_polar(polar dapos);
// #endif

// // 程序清单9.2 file1.cpp
// // file1.cpp -- exanple of a threee-file program
// #include <iostream>
// #include "coordin.h"// structure templates, function prototypes
// using namespace std;
// int main()
// {
//     rect rplace;
//     polar pplace;

//     cout << "Enter the x and y values: ";
//     while (cin >> rplace.x >> rplace.y) //slick use of cin
//     {
//         pplace = rect_to_polar(rplace);
//         show_polar(pplace);
//         cout << "Next two numbers (q to quit): ";
//     }
//     cout << "Bye!\n";
//     return 0;
// }

// // 程序清单 9.3 file2.cpp
// //file2.cpp -- contains functions called in file1.cpp
// #include <iostream>
// #include <cmath>
// #include "coordin.h" // structure templates, function prototypes
// //convert rectangular to polar coordinates
// polar rect_to_polar(rect xypos)
// {
//     using namespace std;
//     polar answer;

//     answer.distance = 
//         sqrt(xypos.x * xypos.x + xypos.y * xypos.y);
//     answer.angle = atan2(xypos.y, xypos.x);
//     return answer;  // return a polar structure
// }

// // show polar coordinates, converting angle to degrees
// void show_polar(polar dapos)
// {
//     using namespace std;
//     const double Rad_to_deg = 57.29577951;

//     cout << "distance = " << dapos.distance;
//     cout << ", angle = " << dapos.angle * Rad_to_deg;
//     cout << " degrees\n";
// }

// 9.2 存储持续性、作用域和链接
// 9.2.1 作用于和链接
// 作用域描述了名称在文件(翻译单元)的多大可见范围
// 连接性描述了名称如何在不同单元中共享
//自动变量,静态变量
//函数原型作用域
//类,名称空间(全局)
//函数的作用域

//9.2.2自动存持续性
//默认情况,存储持续性为自动,作用域为局部,没有链接性
// 程序清单 9.4 auto.cpp
// autoscp.cpp -- illustrating scope of automatic variables
// #include <iostream>
// void oil(int x);
// int main()
// {
//     using namespace std;
//     int texas = 31;
//     int year = 2011;
//     cout << "In main(), texas = " << texas << ", &texas = ";
//     cout << &texas << endl;
//     cout << "In main(), year = " << texas << ", &year = ";
//     cout << &year << endl;
//     oil(texas);
//     cout << "In main(), texas = " << texas << ", &texas = ";
//     cout << &texas << endl;
//     cout << "In main(), year = " << year << ", &year = ";
//     cout << &year << endl;
//     return 0;
// }
// void oil(int x)
// {
//     using namespace std;
//     int texas = 5;

//     cout << "In oil(), texas = " << texas << ", texas = ";
//     cout << &texas << endl;
//     cout << "In oil(), x = " << x << ", &x = ";
//     cout << &x << endl;
//     {
//         int texas = 113;
//         cout << "In block, texas = " << texas;
//         cout << ", &texas = " << &texas << endl;
//                 cout << "In block, x = " << x << ", &x = ";
//         cout << &x << endl;
//     }                               // end a block
//     cout << "Post-block texas = " << texas;
//     cout << ", &texas = " << &texas << endl;
// }
//使用C++11中的auto
//1.自动变量的初始化
//2.自动变量和栈
//3.寄存器变量

// 9.2.3静态持续变量
//三种链接性:外部链接性,内部链接性,无链接性
//零初始化,常量初始化(静态初始化),动态初始化

//9.2.4 静态持续性,外部持续性
//在每个使用外部变量的文件,都要声明
//单定义规则
// 定义声明 引用声明
// 引用声明:extern,不初始化--否则分配存储空间
// 程序清单9.5 external.cpp
// external.cpp -- external variables
// compile with support.cpp

// 9.3.名称空间
// 程序清单9.5 external.cpp
// external.cpp -- external variables
// compile with support.cpp
// #include <iostream>
// using namespace std;
// // external variable
// double warming = 0.3; //warming defined
// //function prototypes
// void update(double dt);
// void local();

// int main()              //uses global variable
// {
//     cout << "Global warming is " << warming << " degrees.\n";
//     update(0.1);
//     cout << "Global warming is " << warming << " degrees.\n";
//     local();
//     cout << "Global warming is " << warming << " degrees.\n";
//     return 0;
// }

// // 程序清单support.cpp
// // support.cpp -- use external variable
// // compile with external.cpp
// #include <iostream>
// extern double warming; // use warming from another file

// // function prototype
// void update(double dt);
// void local();

// using std::cout;
// void update(double dt)          //modifies global variables
// {         
//     extern double warming;      //optional redeclaration
//     warming += dt;              //uses global warming
//     cout << "Updating global warming to " << warming;
//     cout << " degrees.\n";

// }

// void local()
// {
//     double warming = 0.8;//new variable hides external one

//     cout << "Local warming = " << warming << " degrees.\n";
//         //Access global variable with the
//         //scope resolution operator
//     cout << "But global warming = " << ::warming;
//     cout << " degrees.\n";
// }

// 9.2.5 静态持续性、内部链接性
// static
// C++如何处理链接性为外部和内部的变量
// 程序清单9.7 twofile.cpp
// twofile1.cpp -- variables with external and internal linkage
// #include <iostream>     // to be compiled with two file2.cpp
// int tom = 3;            //external variable definition
// int dick = 30;          //external variable definition
// static int harry = 300; //static, internal linkage

// //fuction prototype
// void remote_access();

// int main()
// {
//     using namespace std;
//     cout << "main() reports the following addresses:\n";
//     cout << &tom << " = &tom, " << &dick << " = &dick, ";
//     cout << &harry << " = &harry\n";
//     remote_access();
//     return 0;
// }

// 程序清单9.8 twofile2.cpp
// twofile2.cpp -- variables with internal and external linkage
// #include <iostream>
// extern int tom;         //tom defined elsewhere
// static int dick = 10;   //overrides external dick
// int harry = 200;        //external variable definition
//                         //no conflict with twofile1 harry

// void remote_access()
// {
//     using namespace std;
//     cout << "remote_access() reports the following addresses:\n";
//     cout << &tom << " = &tom, " << &dick << " = &dick, ";
//     cout << &harry << " = &harry\n";
// }

// 9.2.6 静态存储持续性、无链接性
// 程序清单9.9 static.cpp
// static.cpp -- using a static local vatiable
// #include <iostream>
// // constants
// const int ArSize = 10;

// //function prototypes
// void strcount(const char * str);

// int main()
// {
//     using namespace std;
//     char input[ArSize];
//     char next;

//     cout << "Enter a line:\n";
//     cin.get(input, ArSize);
//     while(cin)
//     {
//         cin.get(next);
//         while(next != '\n')     //string didn't fit
//             cin.get(next);// dispose of remainder
//         strcount(input);
//         cout << "Enter next line (empty line to quit):\n";
//         cin.get(input, ArSize);
//     }
//     cout << "Bye\n";
//     return 0;
// }

// void strcount(const char * str)
// {
//     using namespace std;
//     static int total = 0;   //statice local variable
//     int count = 0;          //automatic local variable

//     cout << "\"" << str << "\" contains ";
//     while(*str++)           //go to end of string
//         count++;
//     total += count;
//     cout << count << " characters\n";
//     cout << total << " characters total\n";
// }

// 9.2.7 说明符和限定符
//存储说明符， cv限定符
// 存储说明符
// auto register static extern thread——local mutable
// 1 cv限定符
// const volatile

// 2 mutable
// 即使结构或类的变量为const，其某个成员也可以修改

// 3 const
// 作用于外部变量使之默认的外链接性变为内链接性
// 作用于内部变量使作用域为代码块？？？？？？？？？？？？？？？？？？？？？？本来不就是了吗?

//9.2.8 函数和链接性
// 静态存储持续性
// 外部链接性
// static——内部链接性       同名，覆盖
// 内联函数，可放在头文件，多个定义，（不受单定义规则约束）但需要相同
// C++在哪里查找函数 该文件or所有文件-》库

// 9.2.9 语言链接性
// 连接程序要求每个不同的函数有不同的符号名
// C语言链接性：C语言，一个名称对应一个函数——of course
// C++语言链接：C++，同一个函数可能对应多个函数———名称矫正，名称修饰，为重载函数生成不同的符号名称

// 9.2.10 存储方案和动态分配
// 受new和delete控制，不受作用域和链接规则控制
// 存储方案不适用于动态内存，适用于跟踪动态内存的自动和静态指针变量
// 返回/传递地址，或指针链接性为外部
// 程序结束，new分配的内存被释放/不会自动释放

// 1.使用new运算符初始化
// 括号语法初始化——标量类型
// 列表初始化——常规结构，数组，单值变量
// 2.new失败时
// 引发异常std::bad_alloc (以前是返回空指针)
// 3.new:运算符函数和替换函数
// 4.定位new运算符
// new在堆中找到一个符合要求的内存块
// 定位new运算符，指定要使用的位置
// 可以跟也可以不跟方括号
// new的四种用法
// #include <new>
// struct chaff
// {
//     char dross[20];
//     int slag;
// };
// char buffer1[50];
// char buffer2[50];
// int main()
// {
//     chaff *p1, *p2;
//     int *p3, *p4;
// // first, the regular forms of new
//     p1 = new chaff;     //place structure in heap
//     p3 = new int[20];   //place int array in heap
// // now, the two forms of placement new
//     p2 = new (buffer1) chaff;       // place structure in buffer1
//     p4 = new (buffer2) int[20];     // place int array in buffer2
// // ...
// }

// 程序清单9.10 newplace.cpp
// newplace.cpp -- using placement new
// #include <iostream>
// #include <new>
// const int BUF = 12;     // for placement new
// const int N = 5;        
// char buffer[BUF];       // chunk of memory
// int main()
// {
//     using namespace std;
//     double *pd1, *pd2;
//     int i;
//     cout << "Calling new and placement new:\n";
//     pd1 = new double[N];
//     pd2 = new (buffer) double[N];   // use buffer array
//     for (int i = 0; i < N; i++)
//         pd2[i] = pd1[i] = 1000 + 20.0 * i;
//     cout << "Memory address:\n" << "  heap: " << pd1
//         << "  static: " << (void *) buffer << endl;//？？？？？？？？？？？？？
//     cout << "Memory contents:\n";
//     for (i = 0; i < N; i++)
//     {
//         cout << pd1[i] << " at " << &pd1[i] << "; ";
//         cout << pd2[i] << " at " << &pd2[i] << endl;
//     }

//     cout << "\nCalling new and placement new a second time:\n";
//     double *pd3, *pd4;
//     pd3 = new double[N];            //find new address
//     pd4 = new (buffer) double[N];   //overwrite old data
//     for (i = 0; i < N; i++)
//         pd4[i] = pd3[i] = 1000 + 40.0 * i;
//     cout << "Memory contents:\n";
//     for (i = 0; i < N; i++)
//     {
//         cout << pd3[i] << " at " << &pd3[i] << "; ";
//         cout << pd4[i] << " at " << &pd4[i] << endl;
//     }

//     cout << "\nCalling new and placement new a third time:\n";
//     delete [] pd1;
//     pd1 = new double[N];
//     pd2 = new (buffer + N * sizeof(double)) double[N];
//     for (i = 0; i < N; i++)
//         pd2[i] = pd1[i] = 1000 + 60.0 * i;
//     cout << "Memory contents:\n";
//     for (i = 0; i < N; i++)
//     {
//         cout << pd1[i] << " at " << &pd1[i] << "; ";
//         cout << pd2[i] << " at " << &pd2[i] << endl;
//     }
//     delete [] pd1;
//     delete [] pd3;
//     return 0;
// }

// 9.3 名称空间
// 9.3.1 传统的C++名称空间
// 声明区域
// 潜在作用域
// 作用域

// 9.3.2 新的名称空间特性
// 1 using声明和using编译指令
    //
// 2 using编译指令和using声明之比较
    //大量使用作用域解析运算符（会被局部变量覆盖）//会不会覆盖全局变量啊？？？？？？？？？？？？？？？？？？？？？？？
    //声明
// 3名称空间的其他特性
    //嵌套
    //名称空间中使用using编译指令和using声明//using编译指令可传递
    //创建别名，简化对嵌套名称空间的使用
// 4未命名的名称空间
    // 像后面跟跟着using指令一样，潜在作用域为声明点到声明区域末尾
    // 内部链接性的静态变量的替代品

// 9.3.3 名称空间示例
// 程序清单 9.11 namesp.h
// namesp.h
// #include <iostream>
// // create the pers and debts namespaces
// namespace pers
// {
//     struct Person
//     {
//         std::string fname;
//         std::string lname;
//     };
//     void getPerson(Person &);
//     void showPerson(const Person &);
// }

// namespace debts
// {
//     using namespace pers;
//     struct Debt
//     {
//         Person name;
//         double amount;
//     };
//     void getDebt(Debt &);
//     void showDebt(const Debt &);
//     double sumDebts(const Debt ar[], int n);
// }

// // 程序清单9.12 namesp.cpp
// // namesp.cpp -- namespaces
// #include <iostream>
// // #include "namesp.h"
// namespace pers
// {
//     using std::cout;
//     using std::cin;
//     void getPerson(Person & rp)
//     {
//         cout << "Enter first name: ";
//         cin >> rp.fname;
//         cout << "Enter last name: ";
//         cin >> rp.lname;
//     }
//     void showPerson(const Person & rp)
//     {
//         std::cout << rp.lname << ", " << rp.fname;
//     }
// }
// namespace debts
// {
//     void getDebt(Debt & rd)
//     {
//         getPerson(rd.name);
//         std::cout << "Enter debt: ";
//         std::cin >> rd.amount;
//     }
//     void showDebt(const Debt & rd)
//     {
//         showPerson(rd.name);
//         std::cout << ": $" << rd.amount << std::endl;
//     }
//     double sumDebts(const Debt ar[], int n)
//     {
//         double total = 0;
//         for(int i = 0; i < n; i++)
//             total += ar[i].amount;
//         return total;
//     }
// }

// // 程序清单9.13 namespp.cpp
// // namespp.cpp -- using namespaces
// #include <iostream>
// #include "namesp.h"
// void other(void);
// void another(void);
// int main(void)
// {
//     using debts::Debt;

//     using debts::showDebt;
//     Debt golf = {{"Benny", "Goatsniff"}, 120.0};
//     showDebt(golf);
//     other();
//     another();
//     return 0;
// }

// void other(void)
// {
//     using std::cout;
//     using std::endl;
//     using namespace debts;
//     Person dg = {"Doodles", "Glister"};
//     showPerson(dg);
//     cout << endl;
//     Debt zippy[3];
//     int i;
//     for (i = 0; i < 3; i++)
//         getDebt(zippy[i]);
    
//     for (i = 0; i < 3; i++)
//         showDebt(zippy[i]);
//     cout << "Total debt: $" << sumDebts(zippy, 3) << endl;
//     return;
// }
// void another(void)
// {
//     using pers::Person;
//     Person collector = {"Millo", "rightshift"};
//     pers::showPerson(collector);
//     std::cout << std::endl;
// }

//9.3.4 名称空间及其前途
