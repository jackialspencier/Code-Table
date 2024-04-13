// 第10章 对象和类

// 10.1 过程性编程和面向对象编程

// 10.2 抽象和类

// 10.2.1 类型是什么
// 数据的外观 —— 要对他执行的操作
// 指定基本类型：1。内存2.解释内存的位3.可执行的操作或方法

// 10.2.2 C++中的类
// // 程序清单10.1 stock00.h
// // stock00.h -- Stock class interface
// // version 00
// #ifndef STOCK00_H_
// #define STOCK00_H_

// #include <iostream>
// class Stock //class declaration
// {
// private:
//     std::string company;
//     long shares;
//     double share_val;
//     double total_val;
//     void set_tot() {total_val = shares * share_val; }
// public:
//     void acquire(const std::string & co, long n, double pr);
//     void buy(long num, double price);
//     void sell(long num, double price);
//     void update(double price);
//     void show();
// };   //note semicolon at the end
// #endif

// 1.访问控制

// 2.控制对成员的访问：公有还是私有

// // 程序清单10.2 stock00.cpp
// //stwock00.cpp -- implementing the Stock class
// // verdion 00
// #include <iostream>
// // #include "stock00.h"
// void Stock::acquire(const std::string & co, long n, double pr)
// {
//     company = co;
//     if (n < 0)
//     {
//         std::cout << "Number of shares can't be negative; "
//                     << company << "shares set to 0.\n";
//         shares = 0;
//     }
//     else
//         shares = n;
//     share_val = pr;
//     set_tot();
// }

// void Stock::buy(long num, double price)
// {
//     if (num < 0)
//     {
//         std::cout << "Number of shares purcahsed can't be negative."
//                     << "Transaction is sborted.\n";
//     }
//     else
//     {
//         shares += num;
//         share_val = price;
//         set_tot();
//     }
// }

// void Stock::sell(long num, double price)
// {
//     using std::cout;
//     if (num < 0)
//     {
//         cout << "Number of shares sold can't be negative."
//                 << "Transaction is aborted.\n";
//     }
//     else if (num > shares)
//     {
//         cout << "You can't sell more than you have!"
//                 << "Transaction is aborted.\n";
//     }
//     else
//     {
//         shares -= num;
//         share_val = price;
//         set_tot();
//     }
// }

// void Stock::update(double price)
// {
//     share_val = price;
//     set_tot();
// }
// void Stock::show()
// {
//     std::cout << "Company: " << company
//                 << "  Shares: " << shares << '\n'
//                 << "  Share Price: $" << share_val
//                 << "  Total worth: $" << total_val << '\n';
// }

// 1. 成员函数说明
// 收购，增持，减持，保证不为负，不超自持
// set_tot()实现代码的一种方式，不是公共接口组成部分。// 确保相同，便于修改

// 2.内联方法
// 类声明中定义的自动成为内联
// 类声明外定义的，想内联用inline限定符
// use inline in definition

// 3.方法使用哪个对象
// 10.2.4 使用类
// // 程序清单10.3 usestock0.cpp
// // usestock0.cpp -- the client program
// // compile with stock00.cpp
// #include <iostream>
// // #include "stock00.h"
// int main()
// {
//     Stock fluffy_the_cat;
//     fluffy_the_cat.acquire("NanoSmart", 20, 12.50);
//     fluffy_the_cat.show();
//     fluffy_the_cat.buy(15, 18.125);
//     fluffy_the_cat.show();
//     fluffy_the_cat.sell(400, 20.00);
//     fluffy_the_cat.show();
//     fluffy_the_cat.buy(300000, 40.125);
//     fluffy_the_cat.show();
//     fluffy_the_cat.sell(300000, 0.125);
//     fluffy_the_cat.show();
//     return 0;
// }

// 10.2.5 修改实现
// 数字的格式
// 避免科学计数法
// 设置cout对象的一个标记，命令cout使用定点表示法
// std::cout.setf(std::ios_base::fixed, std::ios_base::floatfiled)//被嵌套的两个库里可以有一样的名字吗？？？？？？
// // 显示三位小数
// std::cout.precision(3);
// // 将修改限定在实现文件中，以免影响程序的其他方面
// // 不应影响客户的其他部分
// // 重置格式信息，恢复到被调用前的状态
// std::streamsize prec = 
//     std::cout.precision(3); // save preceding value for precision
// std::cout.precision(prec);  //reset to old value

// //store original flags
// std::ios_base::fmtflags orig = std::cout.setf(std::ios_base::fixed);
// // reset to stored values
// std::cout.setf(orig, std::ios_base::floatfield);             //为什么返回并被储存的是修改前的不是修改后的啊？

// void Stock::show()
// {
//     using std::cout;
//     using std::ios_base;
//     //set format to #.###
//     ios_base::fmtflags orig = cout.setf(ios_base::fixed, ios_base::floatfield);
//     std::streamsize prec = std::cout.precision(3);

//     cout << "Company: " << company
//         << "  Shares: " << shares << '\n';
//     cout << "  Share price: $" << share_val;
//     //set format to #.##
//     cout.precision(2);
//     cout << "  Total worth: $" << total_val << '\n';

//     // restore original format
//     cout.setf(orig, ios_base::floatfield);
//     cout.precision(prec);
// }

// 构造函数一种可能的定义
//同aqcquire，但程序声明对象时，将自动调用构造函数

// //10.3.2 使用构造函数
// // Stock gift = Stock("World Cabbage", 250, 100);
// // Stock gift("World Cabbage", 250,100);
// //显式调用
// Stock food = Stock("World Cabbage", 250, 1.25);
// //隐式调用（紧凑）
// Stock garment("World Cabbage", 50, 2.5);
// // 等价于
// Stock garment = Stock("World Cabbage", 50, 2.5);
// // 每次创建类对象，C++都使用类构造函数
// //与 new 一起使用
// Stock *pstock = new Stock("Electroshock Games", 18, 19.0);
// // 一般来说用对象调用方法
// //由于构造函数构造出对象前对象不存在，故而构造函数用来创建对象，而不能被对象调用

// // 10.3.3 默认构造函数
// // 编译器提供==>程序员提供
// // 默认构造函数的声明与定义
// // 方式1：给已有构造函数提供默认值
// // 方式2：函数重载定义一个不含参数的构造函数
// // 默认构造函数的使用
// // 显式调用
// // Stock first = Stock();//calls default constructor explicitly
// // 隐式调用
// // Stock first;          //calls it implicitly
// // Stock *prelief = new Stock;//calls it implicitly

// // 注意区分
// Stock first("Concrete Conglomerate");   // calls constructor
// Stock second();     //declares a function
// Stock third;        //calls default constructor
// //隐式调用默认构造函数时，不要使用圆括号。

// 10.3.4 析构函数
// 没有返回值和声明类型
// 没有参数
// 何时调用？静态，自动，new，临时 —— 过期时调用
// 程序员没有提供析构函数——编译器隐式声明， 发现导致对象被删除的代码后，提供默认析构函数的定义

// // 10.3.5 改进Stock类
// // 1.头文件
// // 程序清单10.4 stock10.h
// //stock10.h -- Stock class declaration with const constructors, destructor added
// #ifndef STOCK10_H_
// #define STOCK10_H_
// #include <string>
// class  Stock{
//     std::string company;//string在std里
//     long shares;
//     double share_val;
//     double total_val;
//     void set_tot() { total_val = shares * share_val; }
// public:
// // two constructors
//     Stock();//default constructor
//     Stock(const std::string & co, long num = 0, double price = 0.0);
//     ~Stock();
//     void buy(long num, double price);
//     void sell(long num, double price);
//     void update(double price);
//     void show();
// };
// #endif

// // 2.实现文件
// // 程序清单10.5 stock10.cpp
// // stock10.cpp -- Stock class with constructors, destructor added
// #include <iostream>
// #include <string>
// // #include "stock10.h"

// // constructors (berboss versions)
// Stock::Stock(){     //default constructor
//     std::cout << "Default constructor called\n";
//     company = "no name";// 应提供初始值
//     shares = 0;
//     share_val = 0.0;
//     total_val = 0.0;// 应该也可以set_tot();
// }

// Stock::Stock(const std::string & co, long num, double price){
//     std::cout << "Constuctor using " << co << " called\n";
//     company = co;

//     if (num < 0)
//     {
//         std::cout << "Number of shares can't be negative; "
//                     << company << " shares set to 0.\n";
//         shares = 0;
//     }
//     else
//         shares = num;
//     share_val = price;
//     set_tot();
// }
// //class destructor
// Stock::~Stock(){
//     std::cout << "Bye, " << company << "!\n";// << std::endl
// }
// // other methods
// void Stock::buy(long num, double price){
//     using std::cout;
//     if (num < 0){
//         cout << "Numbers of shares purchased can't be negative. "//"Shares bought can't be less than zero. ";
//         // std::cout << "!";// 重复使用using声明和限定名称？？？？？？？？？？？？？？？？？？？？？？？？？？？？//：：叫啥来着作用域限定符？
//             << "Transaction is aborted.\n";
//     }
//     else{
//         shares += num;
//         share_val = price;
//         set_tot();
//     }
// }

// void Stock::sell(long num, double price){
//     using std::cout;
//     if (num < 0)
//         cout << "Number of shares sold can't be negative."
//             << "Transaction is aborted.\n";
//     else if (num > shares)
//         cout << "You can't sell more than you have!"
//             << "Transaction is aborted.\n";
//     else{
//         shares -= num;
//         share_val = price;
//         set_tot();
//     }
// }

// void Stock::update(double price){
//     share_val = price;
//     set_tot();
// }

// // void Stock::show(){
// //     using std::cout;
// //     cout << "Company: " << company << "\tShares: " << shares << std::endl;
// //     cout << "\tShare value: " << share_val << "\tTotal value: " << total_val;
// // }

// void Stock::show(){
//     using std::cout;
//     using std::ios_base;
//     //set format to #.###
//     ios_base::fmtflags orig =
//         cout.setf(ios_base::fixed, ios_base::floatfield);
//     std::streamsize prec = cout.precision(3);

//     cout << "Company: " << company
//         << "  Shares: " << shares << '\n';
//     cout << "  Shares price: " << share_val;
//     //set format to #.##
//     cout.precision(2);
//     cout << "  Total worth: $" << total_val << '\n';
    
//     // restore original format
//     cout.setf(orig, ios_base::floatfield);
//     cout.precision(prec);
// }

// // 3. 客户文件
// // 程序清单 10.6 usestock2.cpp
// // usestock1(2?).cpp -- use the Stock class
// // compile with stock10.cpp
// #include <iostream>
// // #include "stock10.h"

// int main(){
//     {
//         using std::cout;
//         cout << "Using constructors to create new objects\n";
//         Stock stock1("NanoSmart", 12, 20.0);                //syntax1
//         stock1.show();
//         Stock stock2 = Stock("Boffo Objects", 2, 2.0);      //syntax2
//         stock2.show();

//         cout << "Assigning stock1 to stock2:\n";
//         stock2 = stock1;
//         cout << "Listing stock1 and stock2:\n";
//         stock1.show();
//         stock2.show();

//         cout << "Using a constructor to reset an object\n";
//         stock1 = Stock("Nifty Foods", 10, 50.0);    // temp object
//         cout << "Revised stock1:\n";
//         stock1.show();
//         cout << "Done\n";
//     }// 避免看不到析构函数的两条消息。so有用的一对大括号！
//     return 0;
// }

// 4.程序说明
// 构造函数
// 隐式调用
// 显式调用 //可能创建临时对象，立即或稍后删除
// 构造函数用于赋值,而不是初始化，//创建临时对象，立即或稍后删除

// 5. C++11列表初始化

// // 6.const成员函数
// const Stock land = Stock("Kludgehorn Properties");
// land.show();// 编译器将拒绝第二行，因为代码无法确保调用对象不被修改
// // 原来是通过将函数参数声明为const引用或const的指针来解决，但是这里show没有任何参数
// // 使用的对象是通过方法调用隐式提供的，需要新的语法——保证函数不会修改对象
// // resolution: 将const关键字放在函数括号后面
// // 声明
// void show() const;  // promises not to change invoking object
// // 函数开头
// void Stcok::show() const{}// promises not to change invoking object

// 10.3.6 构造函数和析构函数小结

// 10.4 this指针
// 一个成员函数返回两个Stock对象中股价更高的那个对象的引用
// question1. 将两个要比较的对象提供给成员函数
// 第二个对象作为参数
// 隐式地访问一个对象,显示访问另一个对象
// question2. 将方法的答案传回程序
// 返回一个指向股价更高的对象的引用
// 函数参数名或???
// *this(this指针)
// const Stock & topval(const Stock & s) const;
// 括号中的const表明不会修改被显式访问的对象
// 括号后的const表明不会修改被隐式访问的对象/ 括号后的const表明不能通过this修改对象的值

//this特殊指针,被设置为调用它的对象的地址
//隐式调用的对象被使用时的类成员数据式this->类成员数据的缩写
// 括号后的const表明不能通过this修改对象的值

// this解引用 *this得到对象本身
// const Stock & Stock::topval(const Stock & s) const
// {
//     if (s.total_val > total_val)
//         return s;       // argument object
//     else
//         return *this;   // invoking object
// }

// // 程序清单10.7 stock20.h
// // stock20.h -- argumented version
// #ifndef STOCK20_H_
// #define STOCK20_H_
// #include <string>
// class Stock
// {
// private:        //
//     std::string company;
//     long shares;// 书上是int
//     double share_val;
//     double total_val;
//     void set_tot() {total_val = shares * share_val; }
// public:
//     Stock();    //default constructor
//     Stock(const std::string &, long n = 0, double pr = 0.0);
//     ~Stock();   // do-nothing destructor
//     void buy(long num, double price);
//     void sell(long num, double price);
//     void update(double price);
//     void show() const;
//     const Stock & topval(const Stock & s) const;
// };

// #endif

// // 程序清单10.8 stock20.cpp
// // stock20.cpp -- argumented version
// #include <iostream>
// // #include "stock20.h"

// //constructors
// Stock::Stock()      // default constructor
// {
//     company = "no name";
//     shares = 0;
//     share_val = 0.0;
//     total_val = 0.0;// set_tot();
// }  

// Stock::Stock(const std::string & co, long n, double pr)
// {
//     company = co;

//     if (n < 0){
//         std::cout << "Number of shares can't be negative; "
//                 << company << " shares set to 0.\n";
//         shares = 0;
//         // share_val = 0.0;
//         // set_tot();
//         }
//     else
//         shares = n;
//     share_val = pr;//!!!!!!!!!!!!!!!!!!在else外面
//     set_tot();// !!!!!!!!!!!!!!!!!!!!
// }

// // class destructor
// Stock::~Stock()     // quiet class destructor
// {
// }

// //other methods
// void Stock::buy(long num, double price)
// {
//     if (num < 0)
//         std::cout << "Number of shares purchased can't be negative. "//bought
//                 << "Transaction is aborted.\n";
//     else
//     {
//         shares += num;
//         share_val = price;
//         set_tot();
//     }
// }

// void Stock::sell(long num, double price)
// {
//     using std::cout;
//     if (num < 0)
//         cout << "Number of shares sold can't be negative. "
//                 << "Transaction is aborted.\n";
//     else if (num > shares)
//         cout << "You can't sell more than you have! "
//             << "Transaction is aborted.\n";
//     else
//     {
//         shares -= num;
//         share_val = price;
//         set_tot();
//     }
// }

// void Stock::update(double price)
// {
//     share_val = price;
//     set_tot();  //都别忘了set_tot
// }

// void Stock::show() const
// {
//     using std::cout;
//     using std::ios_base;
    
//     // set format to #.###
//     ios_base::fmtflags orig = 
//         cout.setf(ios_base::fixed, ios_base::floatfield);
//     // ios_base::precision  prec =
//     std::streamsize prec = cout.precision(3);//注意是哪个名称空间的哪个名称!!!!!!

//     cout << "Company: " << company
//         << "  Shares: " << shares << '\n';
//     cout << "  Share value: $" << share_val;
//     //set precision to #.##
//     cout.precision(2);                          //皇帝的新设置?
//     cout << "  Totol worth: $" << total_val << '\n';//value -> worth // 记得换行符

//     // resort cout to former state
//     cout.setf(orig, ios_base::floatfield);
//     cout.precision(prec);

// }

// const Stock & Stock::topval(const Stock & s) const //两个const,别漏啦,漏了就不是同一个函数了(吧)?
// {
//     if (s.total_val > total_val)
//         return s;
//     else
//         return *this;
// }

// // 10.5 对象数组
// // 声明方法与声明标准数组相同
// // 当程序创建未被显式(?)初始化的类对象时,总使调用默认构造函数
// // --编译器提供(无任何构造函数)or程序员提供
// // 初始化
// // 可以用构造函数来初始化数组元素
// // 为每个元素调用构造函数
// // 标准格式对数组初始化:用括号括起的,以逗号分隔的列表
// // 每次调用构造函数表示一个值
// // -可以对不同的元素使用不同的构造函数
// // -为初始化的剩下的原素将使用默认构造函数初始化
// // 初始化数组的方案:1默认构造函数创建数组元素2花括号里的构造函数创建临时对象,3复制
// // 要创建类对象数组,必须要有默认构造函数

// // 程序清单10.9 usestock2.cpp
// // usestock2.cpp -- using the Stock class
// // compile with stock20.cpp
// #include <iostream>
// // #include "stock20.h"

// const int STKS = 4;
// int main()
// {
// // create an array of initialized objects
//     Stock stocks[STKS] = {
//         Stock("NanoSmart", 12, 20.0),
//         Stock("Boffo Objects", 200, 2.0),
//         Stock("Monolithic Obelisks", 130, 3.25),
//         Stock("Fleep Etherprises", 60, 6.5)
//         };
//     std::cout << "Stock holdings:\n";
//     int st;
//     for (st = 0; st < STKS; st++)
//         stocks[st].show();
// // set pointer to first element
//     const Stock * top = &stocks[0];
//     for (st = 1; st < STKS; st++)
//         top = &top->topval(stocks[st]);// *top = (*top).topval(stocks[st]);
// // now top points to the most valuable holding
//     std::cout << "\nMost valuablle holding:\n";
//     top->show();
//     return 0;
// }

// 10.6 类作用域
// 类声明或成员函数定义中, 可以用维修时的成员名称
// 构造函数名称在调用前,才能被识别,因为和类名相同
// 其他情况下,使用类成员名,必须根据上下文使用:直接成员运算符(.),简介成员运算符(->),或作用域解析运算符;
// #include <iostream>

// class Ik
// {
// private:
//     int fuss;
// public:
//     Ik(int f = 9){fuss = f; };// fuss is in scope           // 类声明中且成员函数定义中
//     void ViewIk() const;       // ViweIk() has class scope  // 类声明
// };

// void Ik::ViewIk() const     // Ik:: places ViewIk() into Ik scope   // 作用域解析运算符
// {
//     std::cout << fuss << std::endl;   // fuss in scope within class methods // 成员函数定义中
// }

// int main()
// {
//     Ik *pik = new Ik;
//     Ik ee = Ik(8);  // constructor in scope because has class name  // 构造函数调用
//     ee.ViewIk();    // class object brings ViewIk into scope        //直接成员运算符
//     pik->ViewIk();  // pointer-to-Ik brings ViewIk into scope       //简介成员运算符
// }

// // 10.6.1 作用域为类的常量
// // 创建一个有所有对象共享的符号常量
// // 不可行:
//     class Bakery{
//         private:
//             const int Months = 12;  // declares a constant? FALLS
//             double costs[Months];
//     };
// // 行不通,因为声明类只描述了对象的形式没有创建对象
// // 还没有创建,则没有用于储存的的空间(实际上,提供了成员初始化,但不适用于前述数组声明)
// // 两种方法
// //1 声明一个枚举
// // 类声明中声明的枚举作用域为整个类, 故可用枚举为整型常量提供作用域为整个类的符号名称
// class Bakery{
// private:
//     enum {Months = 12};
//     double costs[Months];
// };
// 用这种方式声明枚举,不创建类数据成员
// 所有对象中都不包含枚举
// Months只是一个符号名称.作用域为整个类的代码中遇到,编译器用12来替换
// (只创建了符号常量,不打算创建枚举类型变量,不需要提供类型名)

//2 使用关键字static
// class Bakery{
// private:
//     static const int Months = 12;
//     double costs[Months];
// };
// 与其他静态变量储存在一起而不是存在对象中
// 只有一个Months常量,被所有Bakery对象共享
// C++98:只能用这种技术声明值为整数或枚举的常量,不可以储存double C++11:可以储存double

// 10.6.2 作用域内枚举
// (枚举量可能冲突)

// 新枚举,其枚举量作用域为类
// 声明:
// enum class egg {Small, Medium, Large, Jumbo};
// enum struct t_shirt {Small, Medium, Large, XLarge};
// // 可用struct代替class
// // 使用
// egg choice = egg::Large;            // the Large enumerator of the egg enum
// t_shirt Floyd = t_shirt::Large;     // the Large enumerator of the t_shirt enum

// 提高了作用域内枚举的类型安全
// 作用域内不允许隐式转换为整型
//(有些情况常规枚举变量转换为整型:赋给int变量,比较表达式)
// enum egg_old {Small, Medium, Large, Jumbo};         // unscoped
// enum class t_shirt {Small, Medium, Large, XLarge};  // scoped // 定义枚举用花括号不是圆括号
// egg_old one = Medium;           // unscoped
// t_shirt rolf = t_shirt::Large;  // scoped

// int king = one; // implicit type conversion for unscoped
// int ring = rolf; // not allowed, no implicit type conversion
// if (king < Jumbo)
//     std::cout << "Jumbo converted to int before comparison.\n";
// if (king < t_shirt::Medium)
//     std::cout << "Not allowed: < not defined for scoped enum.\n";

// // 可以强制类型转换
// int Frodo = int(t_shirt::Small);

// 枚举底层类型:整型
// 作用域内枚举
//C++11作用域内枚举默认int
//提供语法做出不同选择(底层类型必须为整型)
// underlying type for pizza is short
// enum class pizza : short {Small, Medium, Large, XLarge};
//常规变量:
//C++11,也可用此语法
//没有指定则编译器选择的底层类型随实现而异
// :short 放在后面!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// 10.7 抽象数据类型
// ADT abstract data type
// 抽象数据类型
// 私有部分必须标明数据的储存方式
// 公有成员提供了表示栈操作的接口,隐藏数据表示,用通用术语表达

// 程序清单10.10 stack.h
// stack.h -- class definition for the stack ADT
#ifndef STACK_H_
#define STACK_H_

typedef unsigned long Item;

class Stack
{
private:
    enum {MAX = 10};    // constant specific to class
    Item items[MAX];    // holds stack item
    int top;            // index for top stack item
public:
    Stack();
    bool isempty() const;
    bool isfull() const;
    // push retuns false if atack already is full, true otherwise
    bool push(const Item & item);   // add item to stack
    // pop returns false if stack already is empty, true otherwise
    bool pop(Item & item);  // pop into item
};
#endif

// 程序清单10.11 stack.cpp
// stack.cpp -- Stack menmber functions
// #include "stack.h"
Stack::Stack()  // create an empty stack
{
    top = 0;
}

bool Stack::isempty() const
{
    return top == 0;
}

bool Stack::isfull() const
{
    return top == MAX;
}

bool Stack::push(const Item & item)
{
    if (top < MAX)
    {
        items[top++] = item;// items[top] = item;
        // top++;
        return true;
    }
    else
        return false;
}

bool Stack::pop(Item & item)// pop 进item,怎么可以const?
{
    if (top > 0)
    {
        item = items[--top];
        return true;
    }
    else
        return false;
}

// 程序清单10.12 stacker.cpp
// stacker.cpp -- testing the Stack class
#include <iostream>
#include <cctype>   // or ctype.h
// #include "stack.h"
int main()
{
    using namespace std;
    Stack st;       // create an empty stack
    char ch;
    unsigned long po;
    cout << "Please enter A to add a purchase order,\n"
        << "P to process a PO, or Q to quit.\n";
    while (cin >> ch && toupper(ch) != 'Q')
    {
        while (cin.get() != '\n')
            continue;// cin.get();
        if (!isalpha(ch))
        {
            cout << '\a';
            continue;
        }
        switch(ch)
        {// 不用else了,直接switch
            case 'A':
            case 'a': cout << "Enter a PO number to add: ";
                    cin >> po;
                    if (st.isfull())
                        cout << "Stack already full\n";
                    else
                        st.push(po);// if (!push) cout...
                    break;
            case 'p':
            case 'P': if (st.isempty())
                          cout << "Stack already empty\n";
                      else{
                          st.pop(po);
                          cout << "PO #" << po << " popped\n";
                      }
                      break;
                           
        }
        cout << "Please enter A to add a purchase order,\n"
            << "P to process a PO, or Q to quit.\n";
    }
    cout << "Bye\n";
    return 0;
}

// 10.8 总结
// this指针被设置为调用对象的地址，因此*this是该对象的别名
// 面向对象编程
// 强调程序如何表示数据
// 第一步是根据它与程序之间的接口来描述数据,从而指定如何使用数据
// 然后,设计一个类来实现该接口

//私有数据成员存储信息，公有成员函数（又称为方法）提供访问数据的唯一途径。<唯一>
// 每个对象都存储自己的数据，而共享类方法
// my_object.try_me()
// 在OOP中，这种函数调用被称为将try_me消息发送给mr_object对象。

// 成员函数对多个对象操作// 额外的对象作为参数传递给他
// 方法需要显式地引用 调用它的对象 // this指针  // this指针被设置为调用对象的地址,因此*this是该对象的别名

// 类适合ADT
// 公有成员函数接口    ->  ADT描述的服务
// 私有部分和类方法    ->  提供实现,隐藏