// 第八章 函数探幽
// 8.1 内联函数
// inline
// 内联函数不能调用自己
// 程序清单8.1 inline.cpp
// inline.cpp -- using an inline function
// #include <iostream>

// an inline function definition
// inline double square(double x){ return x * x; }

// int main()
// {
//     using namespace std;
//     double a, b;
//     double c = 13.0;
//     a = square(5.0);
//     b = square(4.5 + 7.5); // can pass expressions
//     cout << "a = " << a << ", b = " << b << "\n";
//     cout << "c = " << c;
//     cout << ", c aquared = " << square(c++) << "\n";
//     cout << "Now c = " << c << "\n";
//     return 0;
// }

// 8.2 引用变量
// 主要用途：用作函数的形参
// step1:如何工作（而不是典型用法）
// 8.2.1 创建引用变量
// 程序清单8.2 firstref.cpp
// firstref.cpp -- defining and using a reference
// #include <iostream>
// int main()
// {
//     using namespace std;
//     int rats = 101;
//     int & rodents = rats;
//     cout << "rats = " << rats;
//     cout << ", rodents = " << rodents << endl;
//     rodents++;
//     cout << "rats = " << rats;
//     cout << ", rodents = " << rodents << endl;

// //some implementations require type casting and the following//？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？
// //adresses to type unsigned
//     cout << "rats address = " << &rats;
//     cout << ", rodents address = " << &rodents << endl;
//     return 0;
// }

//与指针的区别
// besides表示法
//1. 必须在声明引用时初始化（不可以如指针先声明再赋值）

// 程序清单8.3 seeref.cpp
// secref.cpp -- defining and using an reference
// #include <iostream>
// int main()
// {
//     using namespace std;
//     int rats = 101;
//     int & rodents = rats; //rodents is a reference

//     cout << "rats = " << rats;
//     cout << ", rodents = " << rodents << endl;

//     cout << "rats address = " << &rats;
//     cout << ", rodents address = " << &rodents << endl;

//     int bunnies = 50;
//     rodents = bunnies;//rats = bunnies
//     cout << "bunnies = " << bunnies;
//     cout << ", rats = " << rats;
//     cout << ", rodents = " << rodents << endl;

//     cout << "bunnies address = " << &bunnies;
//     cout << ", rodents address = " << &rodents << endl;
//     return 0;
// }

//8.2.2 将引用用作函数参数
// 一个常见的的计算机问题——交换两个变量的值，对使用引用和使用指针做一下比较。
// 按值传递
// 按指针传递（
// 按引用传递
// 程序清单8.4 swaps.cpp
// swaps.cpp -- swapping with references and with pointers
// #include <iostream>
// void swapr(int & a, int & b);// a, b are aliases for ints
// void swapp(int * p, int * q);// p, q are addresses of ints
// void swapv(int a, int b);// a, b are new variables
// int main()
// {
//     using namespace std;
//     int wallet1 = 300;
//     int wallet2 = 350;
//     cout << "wallet1 = $" << wallet1;
//     cout << " wallet2 = $" << wallet2 << endl;

//     cout << "Using references to swap contents:\n";
//     swapr(wallet1, wallet2); // pass variables
//     cout << "wallet1 = $" << wallet1;
//     cout << " wallet2 = $" << wallet2 << endl;

//     cout << "Using pointers to swap contents again:\n";
//     swapp(&wallet1, &wallet2);// pass addresses of variables
//     cout << "wallet1 = $" << wallet1;
//     cout << " wallet2 = $" << wallet2 << endl;

//     cout << "Trying to use passing by value:\n";
//     swapv(wallet1, wallet2);// pass values of variables
//     cout << "wallet1 = $" << wallet1;
//     cout << " wallet2 = $" << wallet2 << endl;
//     return 0;
// }
// void swapr(int & a, int & b)//use references
// {
//     int temp = a;//use a, b for values of variables
//     a = b;
//     b = temp;
// }
// void swapp(int * p, int * q) //use pointers
// {
//     int temp = *p;
//     *p = *q;// use *p, *q for values of variables
//     *q = temp;
// }
// void swapv(int a, int b)//try using values
// {
//     int temp;
//     temp = a;   //use a, b for values of variables
//     a = b;
//     b = temp;
// }
//函数调用使用实参初始化形参

//8.2.3 引用的属性和特别之处
// 程序清单8.5 cubes.cpp
// 使用两个函数来计算参数的立方，
// 其中一个函数接受double类型的参数，另一个接受double引用。
// cubes.cpp -- regular and reference arguments
// #include <iostream>
// double cube(double a);
// double refcube(double &ra);
// int main()
// {
//     using namespace std;
//     double x = 3.0;

//     cout << cube(x);
//     cout << " = cube of " << x << endl;
//     cout << refcube(x);
//     cout << " = cube of " << x << endl;
//     return 0;
// }
// double cube(double a)
// {
//     a *= a * a;
//     return a;
// }
// double refcube(double &ra)
// {
//     ra *= ra * ra;
//     return ra;
// }

// double refcube(const double &ra);

// double z = refcube(x + 3.0); // should not compile
//例如不能把值赋给表达式：
// x + 3.0 = 5.0; //nonsensical
//临时变量、引用参数和const
//不是左值/类型不匹配-->创建类型正确的临时匿名变量
//右值引用
// double &&rref = std::sqrt(36.00); //not allowed for double &

//8.2.4 将引用用于结构
//程序清单8.6 strtref.cpp
//strt_ref.cpp -- using structure references
// #include <iostream>
// #include <string>
// struct free_throws
// {
//     std::string name;
//     int made;
//     int attempts;
//     float percent;
// };

// void display(const free_throws & ft);
// void set_pc(free_throws & ft);
// free_throws & accumulate(free_throws & target, const free_throws & source);

// int main()
// {
// //partial initialization - remaining members set to 0
//     free_throws one = {"Ifelsa Branch", 13, 14};
//     free_throws two = {"Andor Knott", 10, 16};
//     free_throws three = {"Minnie Max", 7, 9};
//     free_throws four = {"Whily Looper", 5, 9};
//     free_throws five = {"Long Long", 6, 14};
//     free_throws team = {"Throwgoods", 0, 0};
// //mo initialiazation
//     free_throws dup;

//     set_pc(one);
//     display(one);
//     accumulate(team, one);
//     display(team);
// //use return value as argument
//     display(accumulate(team, two));
//     accumulate(accumulate(team, three), four);
//     display(team);
// //use return value in assignment
//     dup = accumulate(team, five);
//     std::cout << "Displaying team:\n";
//     display(team);
//     std::cout << "Displaying dup after assignment:\n";
//     display(dup);

//     set_pc(four);
// //ill-advised assignment
//     accumulate(dup, five) = four;//这条语句将值赋给函数调用，这是可行的，因为函数的返回值是一个引用。如果函数accumulate()按值返回，这条语句将不能通过编译
//     std::cout << "Displaying dup after ill-advised assignment:\n";
//     display(dup);
//     return 0;
// }

// void display(const free_throws & ft)
// {
//     using std::cout;
//     cout << "Name: " << ft.name << '\n';
//     cout << "  Made: " << ft.made << '\t';
//     cout << "Attempts: " << ft.attempts << '\t';
//     cout << "Percents: " << ft.percent << '\n';
// }
// void set_pc(free_throws & ft)
// {
//     if (ft.attempts != 0)
//         ft.percent = 100.0 * float(ft.made)/float(ft.attempts);
//     else
//         ft.percent = 0;
// }

// free_throws & accumulate(free_throws & target, const free_throws & source)
// {
//     target.attempts += source.attempts;
//     target.made += source.made;
//     set_pc(target);
//     return target;
// }

//1.程序说明
// 用指针
// set_pcp(&one);
// ...
// void set_pcp(free_throws * pt)
// {
//     if (pt -> attempts != 0)
//         pt -> percent = 100.0 * (float)pt -> made / (float)pt -> attempts;
//     else
//         pt -> percent = 0;
// }

// 2. 为何要返回引用
// 传统返回机制与按值传递函数参数类似：计算关键字return后面的表达式，并将结果返回给调用函数。
// 返回引用的函数实际上是被引用变量的别名

// 3.返回引用时需要注意的问题
//避免返回函数终止时不再存在的内存单元引用//避免返回指向临时变量的指针

// 返回一个作为参数传递给函数的引用。
// 作为参数的引用将指向调用函数使用的数据，因此返回的引用也将指向这些数据。

// const free_throws & clone(free_throws & ft)
// {
//     free_throws * pt = new free_throws;
//     *pt = ft;
//     return *pt;
// }
// 但函数声明表明，该函数实际上将返回这个结构的引用。这样，便可以这样使用该函数：
// free_throws & jolly = clone(three);
// 返回结构为什么不行呢？

// 4. 为什么将const用于引用返回类型
// accumulate(dup, five) = four;    

// const返回引用team，但team后面还能改？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？

//8.2.5 将引用用于类对象
// strquote.cpp -- different designs
// #include <iostream>
// #include <string>
// using namespace std;
// string version1(const string & s1, const string & s2);
// const string & version2(string & s1, const string & s2);// has side effect
// const string & version3(string & s1, const string & s2);// bad designe

// int main()
// {
//     string input;
//     string copy;
//     string result;

//     cout << "Enter a string: ";
//     getline(cin, input);//???
//     copy = input;
//     cout << "Your string as entered: " << input << endl;
//     result = version1(input, "***");
//     cout << "Your string enhanced: " << result << endl;
//     cout << "Your original string: " << input << endl;

//     result = version2(input, "###");
//     cout << "Your string enhanced: " << result << endl;
//     cout << "Your original string: " << input << endl;

//     cout << "Resetting original string.\n";
//     input = copy;
//     result = version3(input, "@@@");
//     cout << "Your string enhanced: " << result << endl;
//     cout << "Your original string: " << input << endl;

//     return 0;
// }

// string version1(const string & s1, const string & s2)
// {
//     string temp;
//     temp = s2 + s1 + s2;
//     return temp;
// }

// const string & version2(string & s1, const string & s2)// had side effect
// {
//     s1 = s2 + s1 + s2;
// // safe to return reference passed to function
//     return s1;
// }
// const string & version3(string & s1, const string & s2)// bad design
// {
//     string temp;
//     temp = s2 + s1 + s2;
// //unsafe to return reference to local variable
//     ret         
// 8.2.6 对象、继承和引用
// 继承，基类，派生类
// 基类引用可以指向派生类对象

// 程序清单8.8 
// 调用同一个函数将数据写入文件、显示到屏幕上
//计算放大倍数
// 一些格式化方法（用于cout和ofstream对象时作用相同）
// filefuc.cpp --function with ostream & parameter
// #include <iostream>
// #include <fstream>
// #include <cstdlib>
// using namespace std;

// void file_it(ostream & os, double fo, const double fe[], int n);
// const int LIMIT = 5;
// int main()
// {
//     ofstream fout;
//     const char * fn = "ep=data.txt";
//     fout.open(fn);
//     if (!fout.is_open())
//     {
//         cout << "Can't open " << fn << ". Bye.\n";
//         exit(EXIT_FAILURE);
//     }
//     double objective;
//     cout << "Enter the focal length of your telescope objective in mm: ";
//     cin >> objective;
//     double eps[LIMIT];
//     cout << "Enter the focal lengths, in mm, of " << LIMIT
//         << " eyepieces:\n";
//     for (int i = 0; i < LIMIT; i++)
//     {
//         cout << "Eyepiece #" << i+1 << ": ";
//         cin >> eps[i];
//     }
//     file_it(fout, objective, eps, LIMIT);
//     file_it(cout, objective, eps, LIMIT);
//     cout << "Done\n";
//     return 0;
// }

// void file_it(ostream & os, double fo, const double fe[], int n)
// {
//     ios_base::fmtflags initial;
//     initial = os.setf(ios_base::fixed);// save initial formatting state
//     os.precision(0);
//     os << "Focal length of objective: " << fo << " mm\n";
//     os.setf(ios::showpoint);//一直不变
//     os.precision(1);//一直不变
//     os.width(12);//下一次
//     os << "f.l. eyepiece";
//     os.width(15);
//     os << "magnification" << endl;
//     for (int i = 0; i < n; i++)
//     {
//         os.width(12);
//         os << fe[i];
//         os.width(15);
//         os << int (fo/fe[i] + 0.5) << endl;
//     }
//     os.setf(initial); //restore initial formatting state
// }

// 当然，这只是一些指导原则，很可能有充分的理由做出其他的选择。例如，对于基本类型，cin使用引用，因此可以使用cin>>n，而不是cin >> &n。？？？？？？？？？？？？？

//8.3默认参数
//函数原型
//从右向左
// #include <iostream>
// const int ArSize = 80;
// char * left(const char * str, int n = 1);
// int main()
// {
//     using namespace std;
//     char sample[ArSize];

//     cout << "Enter a string:\n";
//     cin.get(sample, ArSize);
//     char *ps = left(sample, 4);
//     cout << ps << endl;
//     delete [] ps;       //free old string
//     ps = left(sample);
//     cout << ps << endl;
//     delete [] ps;       //free new string
//     return 0;
// }

// //This function returns a pointer to a new string
// //consisting of the first n characters in the str string.
// char * left(const char * str, int n)
// {
//     if (n < 0)
//         n = 0;
//     char * p = new char[n+1];
//     int i;
//     for (i = 0; i < n && str[i]; i++)
//     //表达式str[i]，是要复制的字符的编码。遇到空值字符（其编码为0）后，循环将结束
//     //这样，while循环将使字符串以空值字符结束，并将余下的空间（如果有的话）设置为空值字符。
//         p[i] = str[i];
//     while(i <= n)
//         p[i++] = '\0';
//     return p;
// }
// 不合作的用户要求的字符数目可能为负
// 不负责任的用户要求的字符数目可能多于字符串包含的字符数

// 另一种设置新字符串长度的方法是
// int len = strlen(str);
// n = (n < len )? n : len;//the lesser of n and len
// char * p = new char[n+1];

// int m = 0;
// while (m <= n && str[m] != '\0') //while(m <= n &7 str[m])
//     m++;
// char * p = new char[m+1];
//use m instead of n in the rest of code

//8.4 函数重载
// void sink(double & r1);      //matches modifiable lvalue 
// void sank(const double & r2);//matches modifiable or const lvalue, rvalue
// void sunk(double && r3);     // matches rvalue

//调用——最匹配的版本
// void staff(double & rs); // matches modifiable lvalue
// void staff(const double & rcs); // matches const lvalue, rvalue
// void stove(double & r1);//matches modifiable lvalue
// void stove(const double & r2);//matches const lvalue
// void stove(double && r3);//matches rvalue
//如果没有定义函数stove(double &&)，stove(x+y)将调用函数stove(const double &)。

// 8.4.1 重载示例
// 将数字除以10便可以去掉一位，因此可以使用除法来计算数位。
// unsigned digits = 1;
// while (n / 10)//每除以10次就删除数字的最后一位。
//     digits++;
//上述循环计算每次删除n中的一位时，需要多少次才能删除所有的位。
//（删到剩一位就不循环力）

// 程序清单8.10 leftover.cpp
// leftover.cpp -- overloading the left() function
// #include <iostream>
// unsigned long left(unsigned long num, unsigned ct);
// char * left(const char * str, int n = 1);
// int main()
// {
//     using namespace std;
//     char * trip = "Hawaii!!";   //test value    //warningw
//     unsigned long n = 12345678; //test value
//     int i;
//     char * temp;

//     for (i = 1; i < 10; i++)
//     {
//         cout << left(n, i) << endl;
//         temp = left(trip, i);
//         cout << temp << endl;
//         delete [] temp;// point to temporary storage
//     }
//     return 0;
// }
// //This function returns the first ct digits of number num;
// // unsigned long left(unsigned long num, unsigned ct)
// // {
// //     int digits = 1;
// //     int n = num;
// //     while (n /= 10)
// //         digits++;
// //     ct = digits - ct;
// //     while (ct--)
// //         num /= 10;
// //     return num;
// // }
// unsigned long left(unsigned long num, unsigned ct)
// {
//     unsigned digits = 1;
//     unsigned long n = num;
//     if (num == 0 || ct == 0)
//         return 0;   //return 0 if no digits
//     while (n /= 10)
//         digits++;
//     if (digits > ct)
//     {
//         ct = digits - ct;
//         while (ct--)
//             num /=10;
//         return num;//return left ct digits
//     }
//     else            //if ct >= number of digits
//         return num; //return whole num
// }
// // This function returns a pointer to a new string
// // consisting of the first n characters in the string
// char * left(const char * str, int n)
// {
//     if (n < 0)
//         n = 0;
//     char * p = new char[n+1];
//     int i;
//     for (i = 0; i < n && str[i]; i++)
//         p[i] = str[i];
//     while (i <= n)
//         p[i++] = '\0';
//     return p;
// }

//8.4.2 何时使用重载
// 名称修饰or名称矫正

// 8.5 函数模板
// 泛型
// 通用编程、参数化类型
// template <typename AnyType>//指出，要建立一个模板，并将其类型命名为Anytype
// void Swap(AnyType &a, AnyType &b)
// {
//     AnyType temp;
//     temp = a;
//     a = b;
//     b = temp;
// }
// 关键字template和typename是必需的，除非可以使用关键字class代替typename。
// 另外，必须使用尖括号。类型名可以任意选择（这里为AnyType），
// 只要遵守C++命名规则即可；许多程序员都使用简单的名称，如T。
// template <class T>
// void Swap(AnyType &a, AnyType &b)
// {
//     AnyType temp;
//     temp = a;
//     a = b;
//     b = temp;
// }
// 如果不考虑向后兼容的问题，并愿意键入较长的单词，
// 则声明类型参数时，应使用关键字typename而不使用class

//向后兼容？

// 程序清单8.11 funtemp.cpp
// 在文件的开始位置提供模板函数的原型，并在main( )后面提供模板函数的定义
// funtemp.cpp -- using a function template
// #include <iostream>
// // function templaye prototype
// template <typename T> // or class T
// void Swap(T &a, T &b);

// int main()
// {
//     using namespace std;
//     int i = 10;
//     int j = 20;
//     cout << "i, j = " << i << ", " << j << ".\n";
//     cout << "Using compiler-generated int swapper:\n";
//     Swap(i, j);//generates void Swap(int&, int &)
//     cout << "Now i, j = " << i << ", " << j << ".\n";

//     double x = 24.5;
//     double y = 81.7;
//     cout << "x, y = " << x << ", " << y << ".\n";
//     cout << "Using compiler-generated double swapper:\n";
//     Swap(x, y);//generates void Swap(double &, double &);
//     cout << "Now x, y = " << x << ", " << y << ".\n";
    
//     return 0;
// }

//function template definition
// template <typename T> // or class T
// void Swap (T &a, T&b)
// {
//     T temp;
//     temp = a;// a = temp...你在干什么啊?
//     a = b;
//     b = temp;
// }

// 函数模板不能缩短可执行程序。对于程序清单8.11，
// 最终仍将由两个独立的函数定义，就像以手工方式定义了这些函数一样。

// 最终的代码不包含任何模板，而只包含了为程序生成的实际函数。
// 使用模板的好处是，它使生成多个函数定义更简单、更可靠。

// 8.5.1 重载的模板
// 并非所有的模板参数都必须是模板参数类型
// 程序清单8.12 twotemps.cpp
// twotemps.cpp -- using overloaded template functions
// #include <iostream>
// template <typename T>
// void Swap(T &a, T &b);

// template <typename T>//original template
// void Swap(T *a, T *b, int n);

// void Show(int a[]); //new template
// const int Lim = 8;
// int main()
// {
//     using namespace std;
//     int i = 10, j = 20;
//     cout << "i, j = " << i << ", " << j << ".\n";
//     cout << "Using compiler-generated int swapper:\n";
//     Swap(i, j); //matches original template
//     cout << "Now i, j = " << i << ", " << j << ".\n";

//     int d1[Lim] = {0, 7, 0, 4, 1, 7, 7, 6};
//     int d2[Lim] = {0, 7, 2, 0, 1, 9, 6, 9};
//     cout << "Original arrays:\n";
//     Show(d1);
//     Show(d2);
//     Swap(d1, d2, Lim);
//     cout << "Swapped arrays:\n";
//     Show(d1);
//     Show(d2);

//     return 0;
// }
// template <typename T>
// void Swap(T &a, T&b)
// {
//     T temp;
//     temp = a;
//     a = b;
//     b = temp;
// }

// template <typename T>
// void Swap(T a[], T b[], int n)
// {
//     T temp;
//     for (int i = 0; i < n; i++)
//     {
//         temp = a[i];
//         a[i] = b[i];
//         b[i] = temp;
//     }
// }

// void Show(int a[])
// {
//     using namespace std;
//     cout << a[0] << a[1] << "/";
//     cout << a[2] << a[3] << "/";
//     for (int i = 4; i < Lim; i++)
//         cout << a[i];
//     cout << endl;
// }

// 一个T一个Q算特征标不同吗？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？


// 8.5.2 模板的局限性
// 解决方案
// 运算符重载
// 为特定类型具体化模板定义

// 8.5.3 显式具体化
// struct job
// {
//     char name[40];
//     double salary;
//     int floor;
// };
// 可以提供一个具体化函数定义——显式具体化
// 当编译器找到与函数调用匹配的具体化定义时，将使用该定义，不在寻找模板

//1.第三代具体化（ISO/ANSI C++标准）
//非模板函数、模板函数、具体化的原型
//non template function prototype
// void Swap(job &a, job &b);

//template prototype
// template <typename T>
// void Swap(T &, T &);

//explicit specialization for job type
// template<> void Swap<job>(job &, job &);
// Swap<job>中的<job>是可选的，因为函数的参数类型表明，这是job的一个具体化。
// 所以原型又可以写为
// template<> void Swap(job &, job &); //simpler form
// 如果有多个原型，则编译器在选择原型时，非模板版本优先于显式具体化和模板版本，
// 而显式具体化优先于使用模板生成的版本

// 2.显式具体化示例
// 显式具体化的工作方式
// 程序清单8.13 twoswap.cpp
// twosswap.cpp -- specialization overrides a template
// #include <iostream>
// template <typename T>
// void Swap(T &a, T &b);

// struct job
// {
//     char name[40];
//     double salary;
//     int floor;
// };

// //explicit specialization
// template<> void Swap<job>(job &j1, job & j2);
// void Show(job &j);

// int main()
// {
//     using namespace std;
//     cout.precision(2);
//     cout.setf(ios_base::fixed, ios::floatfield);
//     int i = 10, j = 20;
//     cout << "i, j = " << i << ", " << j << ".\n";
//     cout << "Using compiler-generated int swapper:\n";
//     Swap(i, j);
//     cout << "Now i, j = " << i << ", " << j << ".\n";

//     job sue = {"Susan Yaffee", 73000.60, 7};
//     job sidney = {"Sidney Taffee", 78060.72, 9};
//     cout << "Before job swapping:\n";
//     Show(sue);
//     Show(sidney);
//     Swap(sue, sidney);//use void Sswap(job &, job &)
//     cout << "After job swapping:\n";
//     Show(sue);
//     Show(sidney);

//     return 0;
// }

// template <typename T>
// void Swap(T &a, T &b) //general version
// {
//     T temp;
//     temp = a;
//     a = b;
//     b = temp;
// }

//swaps just salary and floor fields of a job structure
// template<> void Swap<job>(job &j1, job &j2) // specialization
// {
//     double t1;
//     int t2;
//     t1 = j1.salary;
//     t2 = j1.floor;
//     j1.salary = j2.salary;
//     j1.floor = j2.floor;
//     j2.salary = t1;
//     j2.floor = t2;//也可以先交换完salary再交换floor
// }
// void Show(job &j)
// {
//     using namespace std;
//     cout << j.name << ": $" << j.salary
//         << " on floor " << j.floor << endl;
// }

// 8.5.4 实例化和具体化

// 8.5.5 编译器选择使用哪个版本
// 重载解析
// 创建候选函数列表
// 使用候选函数列表创建可行函数列表
// 确定是否有最佳的可行函数（你是懂最佳的（（）


// 考虑只有一个函数参数的情况，如
// may('B');
// 首先，编译器寻找候选者——名为may()的函数和函数模板
// 然后寻找那些可以用一个参数调用的函数
// void may(int);
// float may(float, float = 3);
// void may(char);
// char * may(const char *);//不可行，整数类型不能被隐式地转换为指针类型(即没有显示强制类型转换)
// char may(const char &);
// template<class T> void may(const T &);
// template<class T> void may(T *);//不可行，整数类型不能被隐式地转换为指针类型(即没有显示强制类型转换)

//接下来，编译器必须确定哪个可行函数最佳
// 查看为使函数调用参数与可行的候选函数的参数匹配所需要进行的转换。通常，从最佳到最差
// 1．完全匹配，但常规函数优先于模板。

// 2．提升转换（例如，char和shorts自动转换为int，float自动转换为double）。（参见第三章）

// 3．标准转换（例如，int转换为char，long转换为double）。（参见第三章）

// 4．用户定义的转换，如类声明中定义的转换。

//1.完全匹配和最佳匹配
// const和非const——指针和引用
// 非模板函数，模板函数，模板具体化    最具体 —— 部分排序规则示例

//2.部分排序规则示例
//程序清单8.14 temptempober.cpp
// 显示数组内容
// 第一个定义（模板A）假设作为参数传递的数组中包含了要显示的数据；
// 第二个定义（模板B）假设数组元素为指针，指向要显示的数据。
// tempover.cpp -- tenplate overloading
// #include <iostream>

// template <typename T>       //template A
// void ShowArray(T arr[], int n);

// template <typename T>       //template B
// void ShowArray(T * arr[], int n); 

// struct debts
// {
//     char name[50];
//     double amount;
// };

// int main()
// {
//     using namespace std;
//     int things[6] = {13, 31, 103, 301, 310, 130};
//     struct debts mr_E[3] =
//     {
//         {"Ima, Wolfe", 2400.0},
//         {"Ura Foxe", 1300.0},
//         {"Iby Stout", 1800.0}
//     };
//     double * pd[3];

//     // set pointers to the amount numbers of structures in mr_E
//     for (int i = 0; i < 3; i++)
//         pd[i] = &mr_E[i].amount;
    
//     cout << "Listing Mr. E's counts of things:\n";
//     //tuhings is an array of int
//     ShowArray(things, 6);
//     cout << "Listing Mr. E's debts:\n";
//     //pd is an array of pointers to double
//     ShowArray(pd, 3);

//     return 0;
// }

// template <typename T>
// void ShowArray(T arr[], int n)
// {
//     using namespace std;
//     cout << "template A\n";
//     for (int i = 0; i < n; i++)
//         cout << arr[i] << ' ';
//     cout << endl;
// }

// template <typename T>
// void ShowArray(T * arr[], int n)
// {
//     using namespace std;
//     cout << "template B\n";
//     for (int i = 0; i < n; i++)
//         cout << *arr[i] << ' ';
//     cout << endl;
// }

// 3. 自己选择
// 在有些情况下，可通过编写合适的函数调用，引导编译器做出您希望的选择。
// 程序清单8.15 choices.cpp
// choices.cpp -- choosing a template
// #include <iostream>

// template <class T> 
// //or template <typename T>
// T lesser(T a, T b)          // #1
// {
//     return a < b ? a : b;
// }

// int lesser (int a, int b)   // #2
// {
//     a = a < 0 ? -a : a;
//     b = b < 0 ? -b : b;
//     return a < b ? a : b;
// }

// int main()
// {
//     using namespace std;
//     int m = 20;
//     int n = -30;
//     double x = 15.5;
//     double y = 25.9;

//     cout << lesser(m, n) << endl;// use #2 
//     cout << lesser(x, y) << endl;// use #1 with double
//     cout << lesser<>(m, n) << endl; //use #1 with int
//     cout << lesser<int>(x, y) << endl; //use #1 with int

//     return 0;                 
// }

// 4．多个参数的函数
// 如果找到比其他可行函数都合适的函数，则选择该函数。
// 一个函数要比其他函数都合适，其所有参数的匹配程度都必须不比其他函数差，
// 同时至少有一个参数的匹配程度比其他函数都高。

// 本书并不是要解释复杂示例的匹配过程，
// 这些规则只是为了让任何一组函数原型和模板都存在确定的结果。

// 8.5.6 模板函数的发展
