// 程序清单12.1 stringbad.h
// stringbad.h -- flawed string class definition
// #include <iostream>
// #ifndef STRINGBAD_H_
// #define STRINGBAD_H_
// class StringBad
// {
// private:
//     char * str;                 // pointer to string
//     int len;                    // length of string
//     static int num_strings;     // number of objects
// public:
//     StringBad(const char * s);  // constructor
//     StringBad();                // default constructor
//     ~StringBad();               // destructor
// // added functions
//     StringBad(const StringBad & st);
//     StringBad & operator=(const StringBad & st);
// // friend function
//     friend std::ostream & operator<<(std::ostream & os, 
//                         const StringBad & st); 

// };
// #endif

// // 程序清单12.2 stringbad.cpp
// // strngbad.cpp -- StringBad class methods
// #include <cstring>              // string.h for some
// // #include "strngbad.h"
// using std::cout;

// // initializing static class member
// int StringBad::num_strings = 0;

// // class methods
// // construct StringBad from C string
// StringBad::StringBad(const char *s)
// {
//     len = std::strlen(s);   // set size;
//     str = new char [len+1];     // allot storage
//     std::strcpy(str, s);
//     num_strings++;
//     cout << num_strings << ": \"" << str
//          << "\" object created\n";// For your information
// }

// StringBad::StringBad()
// {
//     len = 4;
//     str = new char[4];
//     std::strcpy(str, "C++");
//     num_strings++;
//     cout << num_strings << ": \"" << str
//          << "\" object created\n";
// }

// StringBad::~StringBad()
// {
//     cout << "\"" << str << "\" object deleted, ";   // FYI
//     --num_strings;                      // required
//     cout << num_strings << " left\n";   // FYI
//     delete [] str;                      //required
// }

// std::ostream & operator<<(std::ostream & os, const StringBad & st)
// {
//     os << st.str;
//     return os;
// }

// // 程序清单12.3 vegnews.cpp
// // StringBad的构造函数和析构函数何时运行及如何运行
// // 将对象声明放在内部代码块中，析构函数在定义对象的代码块执行完毕时调用
// // 否则，析构函数将在main()函数执行完毕时调用，导致无法在执行窗口关闭前看到析构函数显示的消息
// // vegnews.cpp -- using new and delete with classes
// // compile with strngbad.cpp
// #include <iostream>
// using std::cout;
// // #include "strngbad.h"

// void callme1(StringBad &);  // pass by reference
// void callme2(StringBad);     // pass by value

// int main()
// {
//     using std::endl;
//     {
//         cout << "Starting an inner block.\n";
//         StringBad headline1("Celery Stalks at Midnight");
//         StringBad headline2("Lettuce Prey");
//         StringBad sports("Spinach Leaves Bowl for Dollars");
//         cout << "headline1: " << headline1 << endl;
//         cout << "headline2: " << headline2 << endl;
//         cout << "sports: " << sports << endl;
//         callme1(headline1);
//         cout << "headline1: " << headline1 << endl;
//         callme2(headline2);
//         cout << "headline2: " << headline2 << endl;
//         cout << "Initialize one object to another:\n";
//         StringBad sailor = sports;
//         cout << "sailor = " << sailor << endl;
//         cout << "Assign one object to another: " << "\n";
//         StringBad knot;
//         knot = headline1;
//         cout << "knot: " << knot << endl;
//         cout << "Exiting the block.\n";
//     }
//     cout << "End of main()\n";
//     return 0;
// }

// void callme1(StringBad & rsb)
// {
//     cout << "String passed by reference:\n";
//     cout << "    \"" << rsb << "\"\n";
// }

// void callme2(StringBad sb)
// {
//     cout << "String passed by value:\n";
//     cout << "    \"" << sb << "\"\n";
// }

// 12.1.2 特殊成员函数
// 1.默认构造函数
// 编译器提供的默认构造函数
// 默认的默认构造函数
// 不接受任何参数
// 不执行任何操作
// 显式定义默认构造函数
// 没有任何参数
// 可以用来设定特定的值
// 或带参但所有参数都有默认值
// ！只能有一个默认构造函数，否则二义性

// 2.复制构造函数
// 初始化过程，包括按值传递参数，而不是常规的赋值过程
// 函数原型
// Class_name(const Class_name &)
// 接受一个指向类对象的常量引用作为参数
// StringBad(const StringBad &);

// keypoints:何时使用，有何功能

// 3.何时调用复制构造函数
// 新建一个对象并将其初始化为同类现有对象
// StringBad ditto(motto); // calls StringBad(const StringBad &)
// StringBad metoo = motto;// calls StringBad(const StringBAd &)
// StringBad also = StringBad(motto);// calls StringBad(const StringBad &)
// StringBad * pStringBad = new StringBad(motto);// calls StringBad(const StringBad &)
// 传参，按值传递对象
// 返回值，函数返回对象
// 生成临时对象（三个Vector相加，其中两个的结果）

// 按引用传递，节省调用构造函数的时间，存储新对象的空间

// 4. 默认复制构造函数的功能
// 逐个赋值非静态成员
// 复制的是成员的值
// 浅复制
// 成员本身是对象，使用类的复制构造函数复制成员对象 
// 静态函数不受影响，属于整个类，而不是各个对象
// （例如不会对静态数据成员更新计数？）

// 12.1.3 回到StringBad：复制构造函数哪里出了问题
// 1.
// 程序使用默认的复制构造函数另外创建了两个对象
// 默认构造函数不更新计数，但是析构函数更新计数
// solution:提供一个显式复制构造函数

// 如果类中包含这样的静态数据成员，即其值将在新对象被创建时发生变化，
// 则应该提供一个显式复制构造函数来处理计数问题。

// 2.
// 深度复制（deep copy）
// 复制字符串，副本地址赋给成员————vs仅仅复制字符串地址
// 每个对象都有自己的字符串而不是引用另一个对象的字符串
// 调用析构函数释放不同的字符串，而不会试图释放已经释放的字符串
// keypoint: 一些类成员是new初始化的指向数据的指针，而不是数据本身
// StringBad::StringBad(const StringBad & st)
// {
//     num_strings++;              // handle static member update
//     len = st.len;               // same length
//     str = new char[len + 1];    // allot space
//     std::strcpy(str, st.str);// copy string to new location
//     cout << num_strings << ": \"" << str
//          << "\" object created\n";  // For Your Information
// }

// StringBad & StringBad::operator=(const StringBad & st)
// {
//     if(this == &st)     // object assigned to itself
//         return *this;   // all done
//     delete [] str;      // free old string
//     len = st.len;
//     str = new char[len + 1];    // get space for new string
//     std::strcpy(str, st.str);        // copy tho string
//     return *this;               // return reference to invoking object
// }

// 12.2 改进后的String类
// int length() const { return len; };
// friend bool operator<(const String &) const;
// friend bool operator=(const String &) const;
// friend bool operator>(const String &) const;
// friend bool operator<(const String & s1, const String & s2);
// friend bool operator=(const String & s1, const String & s2);
// friend bool operator>(const String & s1, const String & s2);
// friend operator<<(std::istream & is, String & st);
// char operator[](int i);
// const char & operator[](int i) const;   // 参数列表一样也能重载？！！！！！！！！！！！！！！！！！？？
// static int Howmany();

// 12.2.1 修订后的默认构造函数
// 新的默认构造函数
// str = new char;
// 与类析构函数不兼容
// str = new char[1];
// 兼容
// delete[]与new[]初始化的指针和空指针都兼容
// str = 0
// 数字0，空指针，编译器和阅读者难以区分————> (void *) 0
// nullptr

//12.2.2 比较成员函数
// 按字母顺序（机器排列顺序）
// strcmp()函数
// 第一个参数在第二个参数前，负值
// 两个字符串相同，0
// 第一个参数位于第二个参数之后，正值
// bool operator<(const String &st1, const String &st2)
// {
//     if (std::strcmp(st1.str, st2.str) < 0)
//         return true;
//     else
//         return false;
// }

// bool operator<(const string &st1, const string &st2)
// {
//     return (std::strcmp(st1.str, st2.str) < 0);
// }

// bool operator>(const string &st1, const string &st2)
// {
//     return st2 < st1;
// }

// bool operator==(const string & st1, const string st2)
// {
//     return (std::strcmp(st1, st2) == 0);
// }

// 12.2.3 是用中括号表示法访问字符
// 第一个操作数在中括号前面，第二个操作数在两个中括号之间
// 该方法的简单实现
// char & String::operator[](int i)
// {
//     return str[i];
// }

// const char & String::operator[](int i) const
// {
//     return str[i];
// }
// 返回的引用也要const,因为是用于const字符串嘛

// 12.2.4 静态类成员函数

// 不能通过对象调用静态成员函数，不能使用this指针
// static int Howmany(){ return num_strings; }
// 调用

// 不与对象相关联

// int count = String::Howmany();// invoking a static member function
// 只能访问静态数据成员

// 可以设置类级标记，以控制某些接口的行为

// 12.2.5 进一步重载赋值运算符
// 程序清单12.4 string1.h
// string1.h -- fixed and agumented string class definition
// #ifndef STRING_H_
// #define STRING_H_
// #include <iostream>
// using std::ostream;
// using std::istream;

// class String
// {
// private:
//     char * str;
//     int len;
//     static int num_strings;
//     static const int CINLIM = 80;
// public:
// // constructors and other methods
//     String(const char *);
//     String();
//     String(const String &);
//     ~String();
//     int length () const { return len; };
// // overloaded operator methods
//     String & operator=(const String &);
//     String & operator=(const char *);
//     char & operator[](int i);
//     const char & operator[](int i) const;
// // overloaded operator friends
//     friend bool operator<(const String &st, const String &st2);
//     friend bool operator>(const String &st1, const String &st2);
//     friend bool operator==(const String &st, const String &st2);// == 和 =，该分清了吧ge
//     friend ostream & operator<<(ostream & os, const String & st);
//     friend istream & operator>>(istream & is, String & st);// 输入，你还传参const？？
// // static function
//     static int Howmany();
// };
// #endif

// // 程序清单12.5.cpp
// // string1.cpp -- String class methods
// #include <cstring>      // string.h for some
// // #include "string1.h"
// using std::cin;
// using std::cout;

// // initializing static const member
// int String::num_strings = 0;

// // static method
// int String::Howmany()
// {
//     return num_strings;
// }

// // class methods
// String::String(const char * s)      // construct String from C string
// {
//     len = std::strlen(s);       // set size
//     str = new char[len + 1];        // allot storage
//     std::strcpy(str, s); // initialize pointer
//     num_strings++;                  // set object count
// }

// String::String()
// {
//     len = 4;                                        //why???????????????????????????????
//     str = new char[1];
//     str[0] = '\0';                  // default string
//     num_strings++;
// }

// String::String(const String & st)
// {
//     len = st.len;                       // same length
//     str = new char[len + 1];            // allot space
//     std::strcpy(str, st.str);//copy string to neew location
//     num_strings++;                      // handle static member update
// }

// String::~String()   // necessary destructor
// {
//     --num_strings;
//     delete [] str;
// }

// // overloaded operator methods

//     // assign a String to a String
// String & String::operator=(const String & st)
// {
//     if (this == &st)
//         return *this;
//     delete [] str;
//     len = st.len;
//     str = new char[len + 1];
//     std::strcpy(str, st.str);
//     return *this;       // 啊啊啊别忘了返回值！
// }


//     // assign a C string to a String
// String & String::operator=(const char * s)
// {
//     delete [] str;
//     len = std::strlen(s);
//     str = new char[len + 1];
//     std::strcpy(str, s);
//     return *this;
// }

//     // read-write char access for non-const String
// char & String::operator[](int i)
// {
//     return str[i];
// }

//     // read-only char access for const String
// const char & String::operator[](int i) const
// {
//     return str[i];
// }

// // overloaded operator friends
// bool operator<(const String & st1, const String & st2)
// {
//     return (std::strcmp(st1.str, st2.str) < 0);
// }
// bool operator>(const String & st1, const String & st2)
// {
//     return (st2 < st1);
// }
// bool operator==(const String & st1, const String & st2)
// {
//     return (std::strcmp(st1.str, st2.str) == 0);
// }
//     // Simple string output
// ostream & operator<<(ostream & os, const String & st)
// {
//     cout << st.str;
//     return os;
// }
// istream & operator>>(istream & is, String & st)
// {
//     char temp[String::CINLIM];// char s[100];
//     is.get(temp, String::CINLIM);// is.getline(s, 100);
//     if (is)// st = s;
//         st = temp;
//     while(is && is.get() != '\n')
//         continue;
//     return is;// return is;
// }
// 友元函数访问私有数据要限定名？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？

// 程序清单12.6 sayings1.cpp
// sayings.cpp -- using expanded String class
// compile with string1.cpp
// #include <iostream>
// // #include "string1.h"
// const int ArSize = 10;
// const int MaxLen = 81;
// int main()
// {
//     using std::cout;
//     using std::cin;
//     using std::endl;
//     String name;
//     cout << "Hi, what's your name?\n>>";
//     cin >> name;

//     cout << name << ", please enter up to " << ArSize
//          << " short sayings <empty line to quit>:\n";
//     String sayings[ArSize];     // array of subjects
//     char temp[MaxLen];          // temporary string storage
//     int i;
//     for (i = 0; i < ArSize; i++)
//     {
//         cout << i + 1 << ": ";
//         cin.get(temp, MaxLen);
//         while (cin && cin.get() != '\n')
//             continue;
//         if (!cin || temp[0] == '\0')
//             break;
//         else
//             sayings[i] = temp;
//     }
//     int total = i;  // total # of lines read
    
//     if (total > 0)
//     {
//         cout << "Here are your sayings:\n";
//         for (int i = 0; i < total; i++)
//             cout << sayings[i][0] << ": " << sayings[i] << endl;

//         int shortest = 0;
//         int first = 0;
//         for (i = 0; i < total; i++)
//         {
//             if(sayings[i].length() < sayings[shortest].length())
//                 shortest = i;
//             if (sayings[i] < sayings[first])
//                 first = i;  
//         }
//         cout << "Shortest saying:\n" << sayings[shortest] << endl;
//         cout << "First alphabetically:\n" << sayings[first] << endl;
//         cout << "This program used " << String::Howmany() << " String objects. Bye.\n";
//     }
//     else
//         cout << "No input! Bye.\n";
//     return 0;
// }

// strcmp?????????????????????????????????????????????????????????????????????????????????????????

// 12.3 在构造函数中使用new时应注意的事项
// 12.3.1 应该和不应该
// 两个不应该
// String::String()
// {
//     str = "default string";         // no new []
//     len = std::strlen(str);// 计算字符数除了对原字符串，当然也可以对赋值过的str啦
// }
// 没有用new来初始化str，而析构函数用delete释放str
// 对不是new初始化的指针使用delete，结果不确定，可能有害

// String::String(const char * s)
// {
//     len = std::strlen(s);
//     str = new char;     // oops, no []
//     std::strcpy(str, s);// oops, no room
// }
// 使用了new，但内存量分配不正确，只能保存一个字符，但试图将过长的字符串复制到其中
// 导致内存问题
// 另，new不带中括号，与另一个（指第三个）构造函数格式不一致
// （为了兼容，多个构造函数需要以相同的方式使用new）

// 一个应该，正确的
// String::String(const String & st)
// {
//     len = st.len;
//     str = new char[len + 1];    // good, allocate space
//     strcpy(str, st.str);// good, copy value
// }

// 将第一个（默认）构造函数，
// 可以改为以下形式
// String::String()
// {
//     len = 0;// len = 1;
//     str = new char[1];  // uses new with []
//     str[0] = '\0';
// }

// String::String()
// {
//     len = 0;
//     str = 0;    // or, with C++11, str = nullptr // 0或NULL（这个编译器或许也可以NULL）
// }

// String::String()
// {
//     // static const char[4] = "C++";// 不可以诶
//     static const char * s = "C++";  // initialize just once ❤❤❤❤❤❤❤❤❤❤❤❤❤❤❤❤❤❤❤❤❤❤❤❤❤
//     len = std::strlen(s);
//     str = new char[len + 1];
//     strcpy(str, s);                 // uses new with []
// }

// 12.3.2 包含类成员的逐成员复制
// 默认的逐成员赋值，成员类，将使用复制构造函数或赋值运算符
// 故不需要另外编写大类的复制构造函数和赋值运算符

// 但若因大类其他成员需要定义复制构造函数和赋值运算符，情况更复杂
// 显式调用类成员的复制构造函数和赋值运算符
// 将在13章介绍

// 12.4 有关返回对象的说明
// 
// 12.4.1 返回指向const对象的引用
// 提升效率
// 1.返回对象调用构造函数，返回引用不会
// 2.引用指向的对象应该在函数调用时存在
// 3.传参声明为const引用，返回类型必须为const，才匹配

// 12.4.2 返回指向非const对象的引用
// 常见：重载赋值运算符和与cout一起使用的<<运算符

// 重载赋值运算符：返回一个指向调用对象的引用，可以修改，因此不是const
// 提升效率

// <<返回值串接输出
// 必须是ostream &而不能仅仅是ostream
// 如果使用返回类型ostream，将要求调用ostream类的复制构造函数，而ostream没有公有的复制构造函数。？？？？？？？？？？？？？？？？

// 12.4.3 返回对象
// 调用函数局部变量（被调函数执行完时析构，引用指向的对象不存在）
// 返回对象而非引用
// 重载的算术运算符
// 构造函数创建一个方法（被调函数）可以访问的类对象
// 复制构造函数创建一个调用程序可以访问的类对象

// 12.4.4 返回const对象
// 1.要返回局部对象——应该返回对象而不是指向对象的引用——复制构造函数
// 2.返回一个没有公有复制构造函数的类（如ostream类）的对象——必须返回引用
// 3.可以返回对象也可以返回指向对象的引用，

// 12.5 使用指向对象的指针
// 程序清单 12.7 sayings2.cpp
// sayings2.cpp -- using pointers to objects
// compile with string1.cpp
// #include <iostream>
// #include <cstdlib>      // (or stdlib.h) for rand(), srand()
// #include <ctime>        // (or time.h) for time()
// // #include "string1.h"
// const int ArSize = 10;
// const int MaxLen = 81;
// int main()
// {
//     using namespace std;
//     String name;
//     cout << "Hi, what's your name?\n";
//     cin >> name;

//     cout << name << ", please enter up to " << ArSize
//          << " short sayings <empty line to quit>:\n";
//     String sayings[ArSize];
//     char temp[MaxLen];      // temporary string storage
//     int i;
//     for (i = 0; i < ArSize; i++)
//     {
//         cout << i+1 << ": ";
//         cin.get(temp, MaxLen);
//         while (cin && cin.get() != '\n')
//             continue;
//         if (!cin || temp[0] == '\0')    // empty line?
//             break;                      // i not incremented
//         else
//             sayings[i] = temp;          // overloaded assignment
//     }
//     int total = i;      // total # of lines read

//     if (total > 0)
//     {
//         cout << "Here are your sayings:\n";
//         for (i = 0; i < total; i++)
//             cout << sayings[i] << "\n";

//     // use pointers to keep trace of shortest, first strings
//     String * shortest = &sayings[0];    // initialize to first object
//     String * first = &sayings[0];
//     for (i = 0; i < total; i++)
//     {
//         if (sayings[i].length() < sayings->length())//(*shortest).length())
//             shortest = &sayings[i];
//         if (sayings[i] < *first)    // compare values
//             first = &sayings[i];    // assign address
//     }
//     cout << "Shortest saying:\n" << *shortest << endl;
//     cout << "First alphabetically:\n" << *first << endl;

//     srand(time(0));
//     int choice = rand() % total; // pick index at random
//     // use new to create, initialize new String object
//     String * favorite = new String(sayings[choice]);
//     cout << "My favorite saying:\n" << *favorite << endl;
//     delete favorite;
//     }
//     else
//         cout << "Not much to say, eh?\n";
//     cout << "Bye.\n";
//     return 0;
// }

// 12.5.1 再谈new和delete
// 使用new创建对象
// 使用new为创建的 对象 分配内存
// 调用构造函数为字符串分配内存（使用析构函数释放）

// 析构函数的调用
// 动态变量：执行完定义该对象的程序块时
// 静态变量：程序结束时
// new创建的：仅 显式使用delete删除对象时

// 12.5.2 指针和对象小结
// 常规表示法声明指向对象的指针
// String * glamour;
// // 指针初始化为已有的对象
// String * first = &sayings[0];
// // new来初始化指针，创建一个新的对象
// String * favorite = new String(sayings[choice]);
// // (对类使用new将用构造函数初始化新创建的对象)
// // invokes default construtor
// String * gleep = new String; 
// // invokes the String(const char *) constructor
// String * glop = new String("my my my");
// // invokes the String(const String &) constructor
// String & favorite = new String(sayings[choice]);

// ->运算符通过指针访问类方法
// *解除引用运算符来获得对象
// 12.5.3 再谈定位new运算符
// 定位new运算符能在分配内存时指定内存位置

// 程序清单12.8 placenew1.cpp
// placenew1.cpp -- new, placement new, no delete
// #include <iostream>
// #include <string>
// #include <new>
// using namespace std;
// const int BUF = 512;
// class JustTesting
// {
// private:
//     string words;
//     int number;
// public:
//     JustTesting(const string & s = "Just Testing", int n = 0)
//     { words = s; number = n; cout << words << " constructed\n"; }
//     ~JustTesting() { cout << words << " destroyed\n"; }
//     void Show() const{ cout << words << ", " << number << endl; }
// };
// int main()
// {
//     char * buffer = new char[BUF]; // get a block of memory
    
//     JustTesting *pc1, *pc2;

//     pc1 = new (buffer) JustTesting;     // place object in buffer
//     pc2 = new JustTesting("Heap1", 20); // place object on heap

//     cout << "Memory block addresses:\n" << "buffer: "
//         << (void *) buffer << "    heap: " << pc2 << endl;
//     cout << "Memory contents:\n";
//     cout << pc1 << ": ";
//     pc1->Show();
//     cout << pc2 << ": ";
//     pc2->Show();

//     JustTesting *pc3, *pc4;
//     pc3 = new (buffer) JustTesting("Bad Idea", 6);
//     pc4 = new JustTesting("Heap2", 10);

//     cout << "Memory contents:\n";
//     cout << pc3 << ": ";
//     pc3->Show();
//     cout << pc4 << ": ";
//     pc4->Show();
//     delete pc2;         // free Heap1
//     delete pc4;         // free Heap2
//     delete [] buffer;   // free buffer
//     cout << "Done\n";
// }

// delete和常规的new运算符可配合使用，但不能与定位new运算符配合使用
// ？？？？？？？？？例如，指针pc3没有收到new运算符返回的地址，因此delete pc3将导致运行阶段错误？？？？？？
// 在另一方面，指针pc1指向的地址与buffer相同，但buffer是使用new []初始化的，因此必须使用delete [ ]而不是delete来释放
// 即使buffer是使用new而不是new []初始化的，delete pc1也将释放buffer，而不是pc1。
// 这是因为new/delete系统知道已分配的512字节块buffer，但对定位new运算符对该内存块做了何种处理一无所知。

// (以上说明无法delete p1,p3，只能delete [] buffer)
// (但是，直接delete [] buffer;)
// 没有为定位new运算符在该内存块中创建的对象调用析构函数。

// 显式地为使用定位new运算符创建的对象调用析构函数，必须指定要销毁的对象。

// 正确的删除顺序
// 1.对于使用定位new运算符创建的对象，应以与创建顺序相反的顺序进行删除。
//  原因在于，晚创建的对象可能依赖于早创建的对象
// 2.仅当所有对象都被销毁后，才能释放用于存储这些对象的缓冲区。
//   (别忘了这个也还是要释放哒)

// 程序清单12.9 placenew2.cpp
// placenew2.cpp -- new, placement new, no delete
// #include <iostream>
// #include <string>
// #include <new>
// using namespace std;
// const int BUF = 512;

// class JustTesting
// {
// private:
//     string words;
//     int number;
// public:
//     JustTesting(const string & s = "Just Testing", int n = 0)
//     { words = s; number = n; cout << words << " constructed\n"; }
//     ~JustTesting(){ cout << words << " destroyed\n"; }
//     void Show() const{ cout << words << ", " << number << endl; }
// };

// int main()
// {
//     char * buffer = new char[BUF];  // get a block of memory

//     JustTesting *pc1, *pc2;

//     pc1 = new (buffer) JustTesting;     // place object in buffer
//     pc2 = new JustTesting("Heap1", 20); // place object on heap

//     cout << "Memory block addresses:\n" << "buffer: "
//         << (void *) buffer << "    heap:" << pc2 << endl;
//     cout << "Memory contents:\n";
//     cout << pc1 << ": ";
//     pc1->Show();
//     cout << pc2 << ": ";
//     pc2->Show();

//     JustTesting *pc3, *pc4;
// // fix placement new location
//     pc3 = new (buffer + sizeof(JustTesting))
//                 JustTesting("Better Idea", 6);
//     pc4 = new JustTesting("Heap2", 10);

//     cout << "Memory contents:\n";
//     cout << pc3 << ": ";
//     pc3->Show();
//     cout << pc4 << ": ";
//     pc4->Show();

//     delete pc2;     // free Heap1
//     delete pc4;     // free Heap2
// // explicitly destroy placement new objects
//     pc1->~JustTesting();    // destroy object pointed to by pc3
//     pc3->~JustTesting();    // destroy object pointed to by pc1
//     delete [] buffer;       // free buffer
//     cout << "Done\n";
//     return 0;
// }

// 12.6 复习各种技术
// 12.6.1 重载<<运算符
// ostream & operator<<(ostream & os, const c_name & obj)
// {
//     os << ...;  // display object contents
//     return os;
// }
// 如果该类提供了能够返回所需内容的公有方法
// 即可在运算符中使用这些方法，便不用将它们设置为友元函数

// 12.6.2 转换函数
// 其他类型转换为类——类构造函数
// c_name(type_name value);
// 类转化为其他类型——类成员函数
// operator type_name();
// 没有声明返回类型，但要返回所需类型的值
// 可在声明构造函数时使用关键字explicit，防止它被用于隐式转换

// 12.6.3 其构造函数使用new的类
// 如果用new运算符来分配类成员指向的内存——设计时采取一些预防措施
// 指向的内存是new分配的类成员，析构函数中对其使用delete
// 构造函数new[]和new二选一，不能混用
// delete释放的指针，在每个构造函数中要么new，要么空指针
// 定义一个分配内存（而非指向已有内存）的复制构造函数
// 定义一个重载赋值运算符的成员函数（attetion：成员函数！）
//      1.检查this == &参数
//      2. 是则返回*this,否则delete
//      3.分配内存，复制内容

// // 12.7 队列模拟
// // 解决编程问题
// // 12.7.1 队列类

// // 1.Queue类的接口
// class Queue
// {
//     enum {Q_SIZE = 10};
// private:
//     // private representation to be developed late
// public:
//     Queue(int qs = Q_SIZE); // create queue with qs limit
//     ~Queue();
//     bool isempty() const;
//     bool isfull() const;
//     int queuecount() const;
//     bool enqueue(const Item & item);    // add item to end
//     bool dequeue(Item & item);          // remove item from front
// };

// // 2. Queue类的实现
// struct Node
// {
//     Item item;              // data stored in the node
//     struct Node * next;     // pointer to next node
// };

// class Queue
// {
// private:
// // class scope definitions
//     // Node is a nested structure definition local to this class;
//     struct Node {Item item; struct Node * next; };
//     enum {Q_SIZE = 10};
// // private class members
//     Node * front;   // pointer to front of Queue
//     Node * rear;    // pointer to rear of Queue
//     int items;      // current number of items in Queue
//     int qsize;      // maximum number of items in Queue
//     // ...
// public:
// //...
// };
// // 嵌套结构（类、枚举）和类
// // 类中声明的
// // 不创建数据对象，只是指定了可以在类中使用的类型
// // 声明在私有：仅可在这个类使用
// // 声明在共有：作用域解析运算符在类外部使用该声明的类型

// // 3. 类方法
// // 类构造函数应提供类成员的值
// // Queue::Queue(int qs)
// // {
// //     front = rear = nullptr;
// //     items = 0;
// //     qsize = qs;
// // }
// // 但是！！！！！！！！qsize是常量，可以初始化不能给其赋值（引用亦如是）

// // 调用构造函数的流程
// // 1. 对象在括号中的代码执行前被创建，|此时会给各个成员变量分配内存
// // 2. 进入到括号，用常规赋值将值存到内存中

// // 然而，对于const数据成员由于只能初始化，应在执行括号内前，即创建对象时初始化
// // 成员初始化列表
// // 前面带冒号，逗号分隔的初始化列表组成，（参数列表右括号后，函数体左花括号前）
// // 初始化器为data(value);

// Queue::Queue(int qs) : qsize(qs)//戳啦！qsize = qs    // initialize qsize to qs
// {
//     front = rear = nullptr;
//     items = 0;
// }

// // 初值可以是常量or参数列表的参数
// // 不仅限于初始化常量

// Queue::Queue(int qs) : qsize(qs), front(nullptr), rear(nullptr),items(0)
// {
// }

// // 但是这种成员列表初始化的语法
// // 仅限于构造函数

// // 必要，对const类成员和被声明为引用的类成员，必须
// // 只能在创建时初始化

// // 效率，对本身就是类对象的成员来说，使用成员初始化列表效率更高

// // 数据成员被初始化的顺序与它们出现在类声明中的顺序相同，
// // 与初始化器中的排列顺序无关。
// // wow！！！！！！！！！！！！！！！！！!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// bool Queue::enqueue(const Item & item)
// {
//     if (isfull())
//         return false;
//     Node * add = new Node;  // create node
// // on failure, new throws std::bad_alloc exception
//     add->item = item;       // set node pointers
//     add->next = nullptr;    // or nullptr
//     items++;
//     if (front == nullptr)       // if queue is empty
//         front = add;    // place item at front
//     else                        // add 本身就是指针，别再用地址运算符&add了
//         rear->next = add;      // else place at rear
//     rear = add;                // have rear point to new node
//     return true;
// }
// // 1. 队列已满，则结束

// // 2. 创建一个新结点，
// // 3. 存入数据，设置指针nullptr

// // 4. 项目计数更新
// // 5. 节点附加到队尾（1）原rear指针设置，链接节点
//                 // （2）rear更新
// // （特殊情况：原队列为空，则front也需要更新）

// // bool Queue::dequeue(Item & item)
// // {
// //     if (front->item == item){
// //         Node * t = front;
// //         front = front->next;
// //         delete t;
// //         items--;
// //     }
// //     Node * tmp = front -> next;
// //     Node * tp = front;
// //     while(tmp != nullptr){
// //         if (tmp->item == item){
// //             tp->next = tmp->next;
// //             delete tmp;
// //             items--;
// //             break;
// //         }
// //         else{
// //             tp = tmp;
// //             tmp = tmp->next;
// //         }
// //     }
// //     if (tmp == nullptr)
// //         return false;
// //     return true;
// // }

// // 删除队首项目(出队)，不是找到项目删除啦
// bool Queue::dequeue(Item & item)
// {
//     if (isempty())
//         return false;

//     item = front->item;
//     items--;
//     Node * tf = front;
//     front = front->next;
//     delete tf;
//     // items--;
//     if (items == 0)
//         rear = nullptr;//rear指针需要更新的特殊情况
//     return true;
// }
// // 1. 队列为空，结束
// // 注意：出队，需将队列第一个项目提供给调用函数，即复制值到传参的引用变量中
// // 2. 项目计数items更新
// // 3. front更新（记得保存原front不然找不到了）
// // 4. 原front删除
// // （特殊情况：删完为空了，则rear也需更新）

// // 显式析构函数——该函数删除剩余的所有节点
// Queue::~Queue()
// {
//     Node * tmp = front;
//     while(tmp != nullptr)// while queue is not yet empty
//     {
//         front = tmp->next;  // reset pointer to next item
//         delete tmp;         // delete former front
//         tmp = front;        // save address of front item
//     }
// }

// Queue::~Queue()
// {
//     Node * tmp;
//     while(front != nullptr) // while queue isnot empty
//     {
//         tmp = front;        // save address of front item
//         front = front->next;// reset pointer to next item
//         delete tmp;         // delete former front
//     }
// }

// // 使用new的类通常需要显示复制构造函数和深度复制的赋值运算符
// // why（意义）：保存瞬像，为两个不同策略提供相同输入，拆分，合并结合，截短
// // 目前暂时不需要，但未来需要却没有会引发程序混乱崩溃
// // so
// // 1. 提供复制构造函数和深度复制的赋值运算符重载（尽管目前并不需要）
// // 2. 避免额外工作并防止程序崩溃的小技巧：
//     // 将所需方法定义为伪私有
// class Queue
// {
// private:
//     Queue(const Queue &) : qsize(0){}   // preemptive definition
//     Queue & operator=(const Queue & q)  { return * this }
// // ...
// };

// // 两个作用
// // 避免本来自动生成的默认方法定义
// // 是私有的，不能被广泛使用
// // 如不允许：
// Queue snick(nip);
// tuck = nip;

// // 1. 与其将来面对无法预料的运行故障，不如得到一个易于跟踪的编译错误，
// //   指出这些方法是不可访问的
// // 2. 在定义不允许复制的类时，这种方法也很有用

// // 另一种禁用方法的方式：关键字delete(见18章)

// // 其他需要注意的影响：
// // 1. 对象按值传递或返回时，调用复制构造函数
// //      遵循优先按引用传递，则没有问题
// // 2. 创建其他临时对象，调用复制构造函数
// //      但Queue中没有导致创建临时对象的操作，如重载加法运算符

// // 12.7.2 Customer类
// #include <stdlib.h>
// class Customer
// {
// private:
//     long arrive;        // arrival time for customer
//     int processtime;  // processing time for custome
// public:
//     Customer() { arrive = processtime = 0; }
//     void set(long when);
//     long when() const { return arrive; }
//     int ptime() const { return processtime; }
// };

// void Customer::set(long when)
// {
//     processtime = std::rand() % 3 + 1;
//     arrive = when;
// }

// 程序清单12.10 将Queue和Customer类放在一起
// 程序清单12.10 queue.h
// queue.h -- interface for a queue
#ifndef QUEUE_H_
#define QUEUE_H_
// This queue will contain Customer items
class Customer
{
private:
    long arrive;        // arrival time for customer
    int processtime;    // processing time for customer
public:
    Customer() { arrive = processtime = 0; }
    void set(long when);
    long when() const { return arrive; }
    long ptime() const { return processtime; }
};

typedef Customer Item;

class Queue
{
private:
// class scope definitions
    // Node is a nested structure definition local local to this class
    struct Node { Item item; struct Node * next; };
    enum {Q_SIZE = 10};
//private class members
    Node * front;       // pointer to front of Queue
    Node * rear;        // pointer to rear of Queue
    int items;          // current number of items in Queue
    const int qsize;    // maximum number of items in Queue
    //preemptive definitions to prevent public copying
    Queue(const Queue & q) : qsize(0) {};
    Queue & operator=(const Queue & q) { return * this; }
public:
    Queue(int qs = Q_SIZE); //create queue with a qs limit
    ~Queue();
    bool isempty() const;
    bool isfull() const;
    int queuecount() const;
    bool enqueue(const Item &item); // add item to end
    bool dequeue(Item & item);      // remove item from front
};
#endif

// 程序清单12.11 列出了方法
// 程序清单12.11 queue.cpp
// queue.cpp -- Queue and Customer methods
// #include "queue.h"
#include <stdlib.h> // (or cstdlib.h) for rand()

// Queue method
Queue::Queue(int qs) : qsize(qs)
{
    front = rear = nullptr; // or NULL
    items = 0;
}

Queue::~Queue()
{
    Node * tmp;
    while(front != nullptr) // while queue is not yet empty
    {
        tmp = front;        // save address of front item
        front = front->next;// reset pointer to next item
        delete tmp;         // delete former front
    }
}

bool Queue::isempty() const
{
    return items == 0;                                                          // 对吼！！！
    // if (items == 0)
    //     return true;
    // return false;
}

bool Queue::isfull() const
{
    return items == qsize;                                                      // 对吼！！！
    // if (items == qsize)
    //     return true;
    // return false;
}

int Queue::queuecount() const
{
    return items;
}

// Add item to queue
bool Queue::enqueue(const Item &item)   // add item to end
{
    if (isfull())   // 为什么如果没有queue就会报错？不应该是公有方法吗？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？
        return false;

    Node * add = new Node;  // create Node
// on failure, new throws std::bad_alloc exception
    add->item = item;       // set node pointers 很怪
    add->next = nullptr;    // or nullptr        的解释

    items++;
    if (front == nullptr)// if (front = nullptr)    // if queue is empty
        front = add;        // place item at front
    else                    // 确实是要else吼，不然是rear本身改为add就够，rear->next会对一个空指针使用间接访问运算符
        rear->next = add;   // else place at rear
    rear = add;             // have rear point set to new node
    return true;
}

// Place front item into item variable and remove from queue
bool Queue::dequeue(Item & item)    // remove item from front
{
    if (front == nullptr)// if (isempty())
        return false;

    item = front->item; // set item to first item in queue

    items--;
    Node * temp = front;// save location of first item
    front = front->next;// reset front to item
    delete temp;        // delete former first item
    if (items == 0)// if (front = nullptr)
        rear = nullptr;
    return true;
}

// customer method

// when is the time at which the customer arrives
// the arrival time is set to when and the processing
// time set to a random value in the range 1 - 3
void Customer::set(long when)
{
    processtime = std::rand() % 3 + 1;
    arrive = when;
    // processtime = rand() % 3;         // 别忘加一啊喂！！！
}

// 程序清单12.12 bank.cpp
// bank.cpp -- using the Queue interface
// compile with queue.cpp
#include <iostream>
#include <stdlib.h> // for rand() and srand()
#include <ctime> // for time()
// #include "queue.h"
const int MIN_PER_HR = 60;

bool newcustomer(double x);    // is there a new customer?

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ios_base;
// setting things up
    std::srand(std::time(0));   // random initializing for rand()
    
    cout << "Case Study: Bank of Heather Automatic Teller\n";
    cout << "Enter maximum size of queue: ";
    int qs;
    cin >> qs;
    Queue line(qs); // line queue holds up to qs people

    cout << "Enter the number of simulation hours: ";
    int hours;      // hours of simulation
    cin >> hours;
    // simulation will run 1 cycle per minute
    long cyclelimit = MIN_PER_HR * hours;

    cout << "Enter the average number of customers per hour: ";
    double perhour; // average # of arrival per hour
    cin >> perhour;
    double min_per_cust;    // average time between arrivals
    min_per_cust = MIN_PER_HR / perhour;

    Item temp;          // new customer data
    long turnaways = 0;  // turn away by full queue
    long customers = 0; // joined the queue
    long served = 0;    // served during simulation
    long sum_line = 0;  // cumulative line length
    int wait_time = 0;  // cumulative time in line
    long line_wait= 0;   // cumulative time in line

// running the simulation
    for (int cycle = 0; cycle < cyclelimit; cycle++)
    {
        if (newcustomer(min_per_cust)) // have newcomer
        {
            if (line.isfull())
                turnaways++;
            else
            {
                customers++;
                temp.set(cycle);    // cycle = time of arrival
                line.enqueue(temp); // add newcomer to line
            }
            if (wait_time <= 0 && !line.isempty())
            {
                line.dequeue(temp);
                wait_time = temp.ptime();
                line_wait += cycle - temp.when();
            }
            if (wait_time > 0)
                wait_time--;// 不是else wait_time--，只要是大于0，都在这一轮减少1
            sum_line += line.queuecount(); // 不理解，这样不是很多人算了很多次吗，什么意义？

        }
    }

// report results
    if (customers > 0)
    {
        cout << "customers accepted: " << customers << endl;
        cout << "  customers served: " << served << endl;
        cout << "         turnaways: " << turnaways << endl;
        cout << "average queue size: ";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);   // 为什么不需要std？？？？？？？
        cout << (double) sum_line / cyclelimit << endl;
        cout << " average wait time: "
             << (double)line_wait / served << "minutes\n";
    }
    else
        cout << "No customers!\n";
    cout << "Done!\n";

    return 0;
}

// x = average time, in minutes, between customers
// return value is true if customer shows up this minute
bool newcustomer(double x)
{
    return ( std::rand() * x / RAND_MAX < 1);
}