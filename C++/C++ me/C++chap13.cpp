// #include <iostream>
// int main()
// {
//     std::cout << 16.5 * 6.5 << std::endl;
// }

// 13.1 一个简单的基类
// 原始类：基类     继承类：派生类
// 程序清单13.1 tabtenn0.h
// tabten00.h -- a table-tennis base class
// #ifndef TABTENN0_H_
// #define TABTENN0_H_
// #include <string>
// using std::string;
// // simple base class
// class TableTennisPlayer
// {
// private:
//     string firstname;
//     string lastname;
//     bool hasTable;
// public:
//     TableTennisPlayer (const string & fn = "none",
//                        const string & ln = "none", bool ft = false);
//     void Name() const;
//     bool HasTable() const { return hasTable; };
//     void ResstTable(bool v) {hasTable = v; };// 这个分号有什么意义吗？？？？？？？？？？？？？？？？？？？
// };
// #endif

// // 程序清单13.2 tabtenn0.cpp
// // tabtenn0.cpp -- simple base-class methods
// // #include "tabtenn0.h"
// #include <iostream>

// TableTennisPlayer::TableTennisPlayer (const string & fn,
//     const string & ln, bool ht) : firstname(fn),
//             lastname(ln), hasTable(ht)  {}

// void TableTennisPlayer::Name() const
// {
//     std::cout << lastname << ", " << firstname;
// }

// // 程序清单13.3 usett0.cpp
// // usett0.cpp -- using a base class
// #include <iostream>
// // #include "tabenn0.h"
// int main ( void )
// {
//     using std::cout;
//     TableTennisPlayer player1("Chunk", "Blizzard", true);// C风格字符串，与TT类构造函数不一致，调用const char * 为参数的string的构造函数（maybe先构造临时对象用于传参）
//     TableTennisPlayer player2("Tara", "Boomdea", false);    // 若是string，调用const string & 为参数的string构造函数（maybe构造成员而非临时对象）
//     player1.Name();
//     if (player1.HasTable())
//         cout << ": has a table.\n";
//     else
//         cout << ": hasn't a table.\n";
//     player2.Name();
//     if (player2.HasTable())
//         cout << " has a table"; // emm这时有时无的句号和换行符
//     else
//         cout << "hasn't a table.\n";

//     return 0;
// }

// 13.1.1 派生一个类
// RatePlayer derives from the TableTennisPlayer base class
// class RatePlayer : public TableTennisPlayer
// {
// //...
// };

// simple derived class
// class RatedPlayer : public TableTennisPlayer
// {       //(no direct access to 基类的privete:name and hasTable)
// private:        
//     unsigned int rating;    // add a data number
// public:
//     RatedPlayer(unsigned int r = 0, const string & fn = "none",
//                 const string & ln = "none", bool ht = false);
//     RatedPlayer(unsigned int r, const TableTennisPlayer & tp);
//     unsigned int Rating() const { return rating; }      // add a method
//     void ResetRating (unsigned int r) { rating = r; }   // add a method
// };

// 13.1.2 构造函数：访问权限的考虑
// 创建派生类对象时，程序首先创建基类对象
// 基类对象应当在程序进入派生类构造函数之前被创建
// （需）成员初始化列表语法来完成这种工作。

// 不调用基类构造函数，程序将使用默认的基类构造函数
// 相当于有一个隐式的 “：TableTennisPlayer()”作为成员初始化列表
// RatedPlayer::RatedPlayer(unsigned int r, const string & fn,
//     const string & ln, bool ht) : TableTennisPlayer(fn, ln, ht)
// {
//     rating = r;
// }

// 将调用隐式的复制构造函数
// 符合要求
// 成员复制将使用string类的复制构造函数来复制string成员
// RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer & tp)
//     : TableTennisPlayer(tp)
// {
//     rating = r;
// }

// 愿意的话，也可以对派生类成员使用初始化列表
// RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer & tp)
//     : TableTennisPlayer(tp), rating(r)
// {
// }

// 13.1.3 使用派生类
// 要使用派生类，《程序》必须能够访问基类声明
// 程序清单13.4 将两个类的生命放在同一个头文件中（因为相关的）
// 也可以放在独立的头文件中
// 程序清单13.4 tabtenn1.h
// tabtenn1.h -- a table-tennis base class
// #ifndef TABTENN1_H_
// #define TABTENN1_H_
// #include <string>
// using std::string;
// // simple base class
// class TableTennisPlayer
// {
// private:
//     string firstname;
//     string lastname;
//     bool hasTable;
// public:
//     TableTennisPlayer(const string & fn = "none",
//                       const string & ln = "none", bool ht = false);
//     void Name() const;
//     bool HasTable() const { return hasTable; }// 同名的话貌似会在成员初始化列表中报错呢
//     void ResetTable(bool v) { hasTable = v; }
// };

// // simple derived class
// class RatedPlayer : public TableTennisPlayer
// {
// private:
//     int rating;
// public:
//     RatedPlayer(unsigned int r = 0, const string & fn = "none",
//                 const string & ln = "none", bool ht = false);
//     RatedPlayer(unsigned int r, const TableTennisPlayer & tp);
//     unsigned int Rating() const { return rating; }
//     void ResetRating(unsigned int r) {rating = r;}
// };

// #endif

// // 程序清单13.5 两个类的方法定义
// // 同样可以用不同的文件，但放在一起更简单
// // 程序清单13.5 tabtenn1.cpp
// // tabtenn1.cpp -- simple base-class methods
// // #include "tabtenn1.h"
// #include <iostream>
// TableTennisPlayer::TableTennisPlayer(const string & fn,
//     const string & ln, bool ht) : firstname(fn),
//     lastname(ln), hasTable(ht) {}

// void TableTennisPlayer::Name() const
// {
//     std::cout << lastname << ", " << firstname;
// }

// // RatedPlayer methods
// RatedPlayer::RatedPlayer(unsigned int r, const string & fn,
//     const string & ln, bool ht) : TableTennisPlayer(fn, ln, ht)//, rating(r)
// {
//     rating = r;
// }
// RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer & tp)
//     : TableTennisPlayer(tp), rating(r)
// {
//     // rating = r;
// }

// // 注意基类和继承类的类对象如何使用（基类）TableTennisPlayer类的方法的
// // 程序清单13.6 usett1.cpp
// // usett1.cpp --  using base class and derived class
// #include <iostream>
// // #include "tabtenn1.h"

// int main( void )
// {
//     using std::cout;
//     using std::endl;
//     TableTennisPlayer player1("Tara", "Boomdea", false);
//     RatedPlayer rplayer1(1140, "Mallory", "Duck", true);
//     rplayer1.Name();    // derived object uses base method
//     if (rplayer1.HasTable())
//         cout << ": has a table.\n";
//     else
//         cout << ": hasn't a table.\n";
//     player1.Name();     // base object uses base method
//     if (player1.HasTable())
//         cout << ": has a table.\n";
//     else
//         cout << ": hasn't a table.\n";  // 才意识到hasn't这里这种说法表达怪怪的
//     cout << "Name: ";
//     rplayer1.Name();
//     cout << "; Rating: " << rplayer1.Rating() << endl;
// // initialize RatedPlayer uisng TableTennisPlayer object
//     RatedPlayer rplayer2(1212, player1);
//     cout << "Name: ";
//     rplayer2.Name();
//     cout << "; Rating: " << rplayer2.Rating() << endl;

//     return 0;
// }

// 13.1.4 派生类和基类之间的特殊关系
// 特殊关系
// 1.派生类对象可以使用基类方法
    // 条件：方法不是私有的
// 2.基类指针可以不禁想显示类型转换的情况下指向派生类对象，引用亦如是
    // 基类指针/引用只能用于调用基类方法
    // 单向的（不可以将基类地址/对象 赋给 派生类指针/引用）
// 函数参数（基类引用、指针）
// 基类的初始化与赋值运算符（基类引用）

//13.2 继承：is-a 关系
// 程序清单13.7 brass.h
// brass.h -- bank account classes
// #ifndef BRASS_H_
// #define BRASS_H_
// #include <string>
// // Brass Account Class
// class Brass
// {
// private:
//     std::string fullName;
//     long acctNum;
//     double balance;
// public:
//     Brass(const std::string & s = "Nullbody", long an = -1, double bal = 0.0);
//     void Deposit(double amt);
//     virtual void Withdraw(double amt);
//     double Balance() const;
//     virtual void ViewAcct() const;
//     virtual ~Brass() {};
// };

// // Brass Plus Account Class
// class BrassPlus : public Brass
// {
// private:
//     double maxLoan;
//     double rate;
//     double owesBank;
// public:
//     BrassPlus(const std::string & s = "Nullbody", long an = -1,
//             double bal = 0.0, double ml = 500,
//             double r = 0.11125);
//     BrassPlus(const Brass & ba, double ml = 500, double r = 0.11125);
//     virtual void ViewAcct() const;
//     virtual void Withdraw(double amt);
//     void ResetMax(double m) { maxLoan = m; }
//     void ResetRate(double r) { rate = r; }
//     void ResetOwes() { owesBank = 0; }
// };
// #endif

// // 程序清单13.8 brass.cpp
// // brass.cpp -- bank account class methods
// #include <iostream>
// // #include "brass.h"
// using std::cout;
// using std::endl;
// using std::string;

// // formatting stuff
// typedef std::ios_base::fmtflags format;
// typedef std::streamsize precis;
// format setFormat();
// void restore(format f, precis p);

// // Brass methods

// Brass::Brass(const string & s, long an, double bal)
// {
//     fullName = s;
//     acctNum = an;
//     balance = bal;
// }

// void Brass::Deposit(double amt)
// {
//     if (amt < 0)
//         cout << "Negative deposit not allowed; "
//              << "deposit is cancelled.\n";
//     else
//         balance += amt;
// }

// void Brass::Withdraw(double amt)
// {
//     // set up ###.## format
//     format initialState = setFormat();
//     precis prec = cout.precision(2);

//     if (amt < 0)
//         cout << "Withdrawal amount must be positive; "
//              << "withdrawal canceled.\n";
//     else if (amt <= balance)
//         balance -= amt;
//     else
//         cout << "Withdrawal amount of $" << amt
//              << " exceeds your balance.\n"
//              << "Wthdrawal canceled.\n";
//     restore(initialState, prec);
// }
// double Brass::Balance() const
// {
//     return balance;
// }

// void Brass::ViewAcct() const
// {
//     // set up to ###.##
//     format initialState = setFormat();
//     precis prec = cout.precision(2);
//     cout << "Client: " << fullName << endl;
//     cout << "Account Number: " << acctNum << endl;
//     cout << "Balance: $" << balance << endl;
//     restore(initialState, prec);    // restore original format
// }

// // BrassPlus Methods
// BrassPlus::BrassPlus(const string & s, long an, double bal,
//             double ml, double r) : Brass(s, an, bal)
// {
//     maxLoan = ml;
//     owesBank = 0.0;
//     rate = r;
// }

// BrassPlus::BrassPlus(const Brass & ba, double ml, double r)
//             : Brass(ba)     // use implicit copy constructor
// {
//     maxLoan = ml;
//     owesBank = 0.0;
//     rate = r;
// }

// // redefine how ViewAcct() works
// void BrassPlus::ViewAcct() const
// {
//     // set up ###.## format
//     format initialState = setFormat();
//     precis prec = cout.precision(2);
//     Brass::ViewAcct();  // display base portion
//     cout << "Maximum Loan: $" << maxLoan << endl;
//     cout << "Owes to bank: $" << owesBank << endl;
//     cout.precision(3);  // ###.### format
//     cout << "Loan Rate: " << 100 * rate << "%\n";
//     restore(initialState, prec);
// }

// // redefine how Withdraw() works
// void BrassPlus::Withdraw(double amt)
// {
//     // set ip ###.## format
//     format initialState = setFormat();
//     precis prec = cout.precision(2);

//     double bal = Balance();
//     if (amt <= bal)
//         Brass::Withdraw(amt);
//     else if ( amt <= bal + maxLoan - owesBank)
//     {
//         double advance = amt - bal;
//         owesBank += advance * (1.0 + rate);
//         cout << "Bank advance: $" << advance << endl;
//         cout << "Finance charge: $" << advance * rate << endl;
//         Deposit(advance);
//         Brass::Withdraw(amt);   // 不是只需设置balance为0即可吗 // 但是balance是基类的私有数据，怎么可以开修改器（？
//     }
//     else
//         cout << "Credit limit exceeded. Transaction cancelled.\n";
//     restore(initialState, prec);
// }

// format setFormat()
// {
//     // set up ###.## format
//     return cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
// }

// void restore(format f, precis p)
// {
//     cout.setf(f, std::ios_base::floatfield);
//     cout.precision(p);
// }

// // 2. 使用Brass和BrassPlus类
// // 程序清单13.9 一个Brass对象和一个BrassPlus对象测试类定义
// // usebrass1.cpp -- testing bank account classes
// // compile with brass.cpp
// // #include <iostream>
// // #include "brass.h"

// // int main()
// // {
// //     using std::cout;
// //     using std::endl;

// //     Brass Piggy("Porcelot Pigg", 381299, 4000.00);
// //     BrassPlus Hoggy("Horatio Hogg", 382288, 3000.0);
// //     Piggy.ViewAcct();
// //     cout << endl;
// //     Hoggy.ViewAcct();
// //     cout << endl;
// //     cout << "Depositing $1000 into Hogg Account:\n";
// //     Hoggy.Deposit(1000.00);
// //     cout << "New balance: $" << Hoggy.Balance() << endl;
// //     cout << "Withdrawing $4200 from the Hogg Account:\n";
// //     Piggy.Withdraw(4200.00);
// //     cout << "Pigg account balance: $" << Piggy.Balance() << endl;
// //     cout << "Withdrawing $4200 from Hogg Account:\n";
// //     Hoggy.Withdraw(4200.00);
// //     Hoggy.ViewAcct();

// //     return 0;
// // }

// // 程序清单13.10通过指针数组调用方法，使用虚方法特性
// // 用一个数组表示多种类型的对象，多态性
// // 程序清单13.10 usebrass2.cpp
// // usebrass2.cpp -- polymorphic example
// // compile with brass.cpp
// #include <iostream>
// #include <string>
// // #include "brass.h"
// const int CLIENTS = 4;

// int main()
// {
//     using std::cin;
//     using std::cout;
//     using std::endl;

//     Brass * p_clients[CLIENTS];
//     std::string temp;
//     long tempnum;
//     double tempbal;
//     char kind;

//     for (int i = 0; i < CLIENTS; i++)
//     {
//         cout << "Enter client's name: ";
//         getline(cin, temp);// getline新用法！！！！！！！！！！！！！！！！！！！！！！！！！！！！
//         cout << "Enter client's account number: ";
//         cin >> tempnum;
//         cout << "Enter opening balance: $";
//         cin >> tempbal;
//         cout << "Enter 1 for Brass Account or "
//              << "2 for BrassPlus Account: ";
//         while(cin >> kind && (kind != '1' && kind != '2'))
//             cout << "Enter either 1 or 2";
//         if (kind == '1')
//             p_clients[i] = new Brass(temp, tempnum, tempbal);
//         else
//         {
//             double tmax, trate;
//             cout << "Enter the overdraft limit: $";
//             cin >> tmax;
//             cout << "Enter the interest rate "
//                  << "as a decimal fraction: ";
//             cin >> trate;
//             p_clients[i] = new BrassPlus(temp, tempnum, tempbal,
//                                          tmax, trate);
//         }
//         while(cin.get() != '\n')
//             continue;
//     }
//     cout << endl;
//     for (int i = 0; i < CLIENTS; i++)
//     {
//         p_clients[i] -> ViewAcct();
//         cout << endl;
//     }

//     for (int i = 0; i < CLIENTS; i++)
//     {
//         delete p_clients[i];    // free memory
//     }
//     cout << "Done.\n";
//     return 0;
// }

// 13.4 静态联编和动态联编

// 13.5 访问控制
// protected
// 对于外部世界，保护成员的行为和私有成员类似
// 对应于派生类，保护成员行为与公有成员相似
// 保护数据成员：简化代码工作，但存在设计缺陷
// so：
// 对类数据成员：最好私有访问控制（不要保护访问控制），通过基类方法允许派生类访问基类数据
// 对类成员函数：保护访问控制很有用——让派生类访问公众不能使用的内部函数

// 13.6 抽象基类
// 简单继承、多态继承
// ——抽象基类（Abstract Base Class）（ABC）
// 抽象出共性放到一个ABC中
// 从该ABC派生出不同的类
// 使用纯虚函数提供未实现的函数——声明的结尾处为=0
// // < 原型中 =0 使 虚函数 成为 纯虚函数>
// class BaseEllipse   // abstract base class
// {
// private:
//     double x;
//     double y;
// public:
//     BaseEllipse(double x0 = 0, double y0 = 0) : x(x0), y(y0) {}
//     virtual ~BaseEllipse() {};
//     void Move(int nx, int ny) { x = nx; y = ny; }// 注意！只有构造函数可以使用成员初始化列表！
//     virtual double Area() const = 0;    // a pure virtual function
//     // ...
// };

// （ABC抽象基类与纯虚函数的关系）
// 包含纯虚函数：不能创建该类的对象——包含纯虚函数的类只用作基类// 具体类：可以创建这些类型的对象
//      要成为真正的ABC，至少包含一个纯虚函数
// 允许纯虚函数有定义
// <都可以在基类中定义（这个角度看不需要纯虚函数），但仍需要将类声明为抽象的>
//          <将一个原型声明为虚的，但在实现文件中提供方法的定义>
// summary: 原型中=0指出这是一个抽象基类，在类中 可以 不定义该函数

// summary：
// ABC描述的是至少使用一个纯虚函数的接口
// 从ABC派生出的类将根据派生类的具体特征，使用“常规虚函数”来实现这些接口

// 13.6.1 应用ABC概念
// 程序清单13.11 acctabc.h
// acctabc.h -- bank account classes
// #ifndef ACCTABC_H_
// #define ACCTABC_H_
// #include <iostream>
// #include <cstring>

// // Abstract Base Classes
// class AcctABC
// {
// private:
//     std::string fullName;
//     long actNum;
//     double balance;
// protected:
//     struct Formatting
//     {
//         std::ios_base::fmtflags flag;
//         std::streamsize pr;
//     };
//     const std::string & FullName() const { return fullName; }
//     long AcctNum() const { return actNum; }
//     Formatting SetFormat() const;
//     void Restore(Formatting & f) const;
// public:
//     AcctABC(const std::string & s = "Nobody", long an = -1,
//                 double bal = 0.0);
//     void Deposit(double amt);
//     virtual void Withdraw(double amt) = 0;// pure virtual function  
//     double Balance() const { return balance; }
//     virtual void ViewAcct() const = 0;    // pure virtual funxtion
//     virtual ~AcctABC() {}
// };

// // Brass Account Class
// class Brass : public AcctABC
// {
// public:
//     Brass(const std::string & s = "nobody", long an = -1,
//             double bal = 0.0) : AcctABC(s, an, bal) { }
//     virtual void Withdraw(double amt);
//     virtual void ViewAcct() const;
//     virtual ~Brass() {};
// };

// // Brass Plus Account Class
// class BrassPlus : public AcctABC
// {
// private:
//     double maxLoan;
//     double rate;
//     double owesBank;
// public:
//     BrassPlus(const std::string & s = "Nobody", long an = -1, 
//             double bal = 0.0, double ml = 500, 
//             double rating = 0.10);
//     BrassPlus(const Brass & ba, double ml = 500, double r = 0.1);
//     virtual void Withdraw(double amt);
//     virtual void ViewAcct() const;
//     // virtual ~BrassPlus();
//     void ResetMax(double m) { maxLoan = m; }
//     void ResetRate(double r) { rate = r; }
//     void ReserOwes() { owesBank  =0; }
// };
// #endif

// // 实现那些不是内联函数的方法
// // 程序清单13.12 acctABC.cpp
// // acctabc.cpp -- bank account class methods
// // Abstract Base Class
// #include <iostream>
// // #include "acctabc.h"
// using std::cout;
// using std::ios_base;
// using std::endl;
// using std::string;

// // Abstract Base Class
// AcctABC::AcctABC(const std::string & s, long an, double bal)
// {
//     fullName = s;
//     actNum = an;
//     balance = bal;
// }

// void AcctABC::Deposit(double amt)
// {
//     if (amt <= 0)
//         std::cout << "Negative deposit not allowed; "
//              << "deposit is canceled.\n";
//     else
//         balance += amt;
// }

// void AcctABC::Withdraw(double amt)
// {
//     // if (amt <= 0)
//     //     std::cout << "Withdrawal must be positive; "
//     //          << "Withdraw canceled.\n";
//     // else if (amt <= balance)
//         balance -= amt; 
// }

// // protected methods for formatting
// // void AcctABC::ViewAcct() const
// // {
// //     using std::cout;
// //     cout << "Full name: " << fullName << endl;
// //     cout << "Account number: " << actNum << endl;
// //     cout << "Balance: " << balance << endl;
// // }

// AcctABC::Formatting AcctABC::SetFormat() const  // 为什么需要AcctABC？？？？？？？？？？？？？？？？？
// {
// // set up ###.## format
//     Formatting f;
//     f.flag = std::cout.setf(std::ios_base::fixed,
//              std::ios_base::floatfield);
//     f.pr = std::cout.precision(2);
//     return f;
// };

// void AcctABC::Restore(Formatting & f) const
// {
//     std::cout.setf(f.flag, std::ios_base::floatfield);
//     std::cout.precision(f.pr);
// }

// // Brass methods
// void Brass::Withdraw(double amt)
// {
//     if (amt <= 0)
//         std::cout << "Withdrawal amount must be positive; "
//              << "Withdraw canceled.\n";
//     else if (amt <= Balance())
//         AcctABC::Withdraw(amt);
//     if (amt > Balance())
//         std::cout << "Withdraw amount of $" << amt
//                  << " exceeds your balance.\n"
//                  << "Withdrawal canceled..\n";
// }

// void Brass::ViewAcct() const
// {
//     // AcctABC::ViewAcct();
//     Formatting f = SetFormat();// 别忘了设置格式
//     cout << "Brass Client: " << FullName() << endl;
//     cout << "Account number: " << AcctNum() << endl;
//     cout << "Balance: $" << Balance() << endl;
//     Restore (f);
// }

// // Brass Plus Account Class
// BrassPlus::BrassPlus(const std::string & s, long an, double bal,
//      double ml, double r) : AcctABC(s, an, bal)//, maxLoan(ml), rate(r) {}
// {
//     maxLoan = ml;
//     owesBank = 0.0;// 别忘了设置这个数据项啊喂！用成员画初始化列表时，不要忘了没有使用传参来的数据的数据成员！！
//     rate = r;
// }

// BrassPlus::BrassPlus(const Brass & ba, double ml, double r)
//     : AcctABC(ba)// use implicit copy constructor //, maxLoan(ml), rate(r) {}
// {
//     maxLoan = ml;
//     owesBank = 0.0;
//     rate = r;
// }
// void BrassPlus::ViewAcct() const
// {
//     Formatting f = SetFormat();
//     // AcctABC::ViewAcct();
//     cout << "BrassPlus Client: " << FullName() << endl;
//     cout << "Account NUmber: " << AcctNum() << endl;
//     cout << "BAlance: $" << Balance() << endl;
//     // using std::cout;
//     // using std::endl;
//     cout << "Maximum loan: $" << maxLoan << endl;
//     cout << "Owes to bank: $" << owesBank << endl;
//     cout.precision(3);
//     cout << "Loan Rate: " << 100 * rate  << "%\n.";//<< endl;
//     Restore(f);// 记得传参！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
// }

// void BrassPlus::Withdraw(double amt)
// {
//     // using std::cout;
//     // using std::endl;
//     Formatting f = SetFormat();

//     double bal = Balance();
//     if (amt <= bal)
//         AcctABC::Withdraw(amt); // 貌似书本示例没有考虑小于0的取款情况呢。似乎是一个小设计漏洞。
//     else if (amt <= bal + maxLoan - owesBank)//(amt > Balance() && amt <= Balance() + maxLoan - owesBank)
//     {
//         double advance = amt - bal;
//         // advance = amt - Balance();
//         owesBank += advance * (1 + rate);//rate;
//         cout << "Bank advance: $" << advance << endl;
//         cout << "Finance Charge: " << advance * rate << endl;
//         Deposit(advance);
//         Withdraw(amt);
//     }
//     else// else if (amt > Balance() + maxLoan - owesBank)
//         cout << "Credit limit exceeded. Transaction canceled.\n";
// }

// 程序清单13.13 usebrass3.cpp
// usebrass3.cpp -- polymorphic example using an abstract base class
// compile with acctacb.cpp // 这个acb是认真的吗
// #include <iostream>
// #include <string>
// // #include "acctabc.h"
// const int CLIENTS = 4;

// int main()
// {
//     using std::cin;
//     using std::cout;
//     using std::endl;

//     AcctABC * p_clients[CLIENTS];
//     std::string temp;
//     long tempnum;
//     double tempbal;
//     char kind;

//     for (int i = 0; i < CLIENTS; i++)
//     {
//         cout << "Enetr client's name: ";
//         getline(cin, temp);// 对于string类就是这样用的，之前设计的倒也有相似之处，第一个参数为istream，第二个参数为String
//         // char p[50];
//         // cin.getline(p, 50);
//         // cin.getline(temp, 50);
//         cout << "Enter client's number: ";
//         cin >> tempnum;
//         cout << "Enter openning balance: $";
//         cin >> tempbal;
//         cout << "Enter 1 for Brass Account or"
//              << "2 for BrassPlus Account: ";
//         while(cin >> kind && (kind != '1' && kind != '2'))
//             cout << "Enter 1 or 2: ";
//         if (kind == '1')
//             p_clients[i] = new Brass(temp, tempnum, tempbal);
//         else
//         {
//             double tmax, trate;
//             cout << "Enter the overdraft limit: $";
//             cin >> tmax;
//             cout << "Enter the interest rate "
//                  << "as a decimal fraction: ";// what does it mean by decimal fraction?这啥意思啊？
//             cin >> trate;
//             p_clients[i] = new BrassPlus(temp, tempnum, tempbal, tmax, trate);
//         }
//         while(cin.get() != '\n')
//             continue;   // 为getline开路（）。
//     }
//     cout << endl;
//     for (int i = 0; i < CLIENTS; i++)
//     {
//         p_clients[i]->ViewAcct();
//         cout << endl;
//     }

//     for (int i = 0; i < CLIENTS; i++)
//     {
//         delete p_clients[i];    // free memory
//     }
//     cout << "Done.\n";

//     return 0;
// }

// 13.7 继承和动态内存分配
// Base Class Using DMA
// class baseDMA
// {
// private:
//     char * label;
//     int rating;
// public:
//     baseDMA(const char * l = "null", int r = 0);
//     baseDMA(const baseDMA & rs);
//     virtual ~baseDMA();
//     baseDMA & operator=(const baseDMA & rs);
//     //...
// };

// // derived class without DMA
// class lacksDMA : public baseDMA
// {
// private:
//     char color[40];
// public:
// //...
// };

// 13.7.2 第二种情况：派生类使用new
// derived class with DMA
// class hasDMA :public baseDMA
// {
// private:
//     char * style;   // use new in constructors
// public:
// // ...
// };

// 派生类使用了new
// 必须为派生类定义显式析构函数、复制构造函数、赋值运算符

// 析构函数
// 自动调用基类的析构函数
// 职责是对派生类构造函数执行工作的清理
// hasDMA释放指针style管理的内存，依赖于baseDMA的析构函数释放指针label管理的内存
// baseDMA::~baseDMA() // takes care of baseDMA staff
// {
//     delete [] label;
// }

// hasDMA::~hasDMA()   // takes care of hasDMA stuff
// {
//     delete [] style;
// }

// 复制构造函数
// char数组的常规模式
// 1.strlen()获悉C-风格字符串长度
// 2.分配内存(字符数+储存空字符的一字节)
// 3.函数strcpy()执行复制——将原始字符串复制到目的地
// baseDMA::baseDMA(const baseDMA & rs)
// {
//     label = new char[std::strlen(rs.label) + 1];
//     std::strcpy(label, rs.label);
//     rating = rs.rating;
// }
// 复制构造函数只能访问hasDMA数据，调用baseDMA复制构造函数来处理共享的baseDMA数据
//复制构造函数也是构造函数，给w记着在成员初始化列表中使用基类构造函数❤❤❤❤❤❤❤❤❤❤❤❤❤❤❤❤❤❤❤❤❤❤❤
// hasDMA::hasDMA(const hasDMA & hs)
//         : baseDMA(hs)
// {
//     style = new char[strlen(hs.style) + 1];
//     strcpy(style, hs.style);
// }// baseDMA复制构造函数将使用hasDMA参数的baseDMA部分来构造新对象的baseDMA部分。

//注意：成员初始化将一个hasDMA传给baseDMA复制构造函数
// key：复制构造函数有基类引用参数，基类引用可以指向派生类引用———可以用派生类对象构造基类对象❤❤❤❤❤❤❤❤❤❤❤❤❤❤❤❤❤❤❤❤❤❤❤
// baseDMA & baseDMA::operator=(const baseDMA & rs)
// {
//     if (this == & rs)
//         return *this;
//     delete [] label;
//     label = new char[strlen(rs.label) + 1];
//     std::strcpy(label, rs.label);
//     rating = rs.rating;
//     return *this;
// }
// hasDMA用了动态内存分配，也需要一个显式赋值运算符
// 只能访问hasDMA新增的数据（但要复制所有数据）——继承基类的要靠显式调用基类赋值运算符
// hasDMA & hasDMA::operator=(const hasDMA & hs)
// {
//     if (this == &hs)
//         return *this;
//     baseDMA::operator=(hs);// copy base portion     // 居然是这样显式调用的// 似乎无论虚函数与否，都可以用类型限定名调用
//     delete [] style;        // prepare for new style
//     style = new char[std::strlen(hs.style) + 1];
//     std::strcpy(style, hs.style);
//     return *this; 
// }
// 使用函数表示法方可用作用域解析运算符正确调用所需函数（防止递归）

// 13.7.3 使用动态内存分配和友元的继承实例
// baseDMA，lacksDMA，hasDMA集成到一个示例中
// 程序清单13.14 这些类的头文件
// （除之前介绍的外，包含一个友元函数，说明派生类如何访问基类的友元）
// 程序清单13.14 dma.h
// dma.h -- inheritance and dynamic memory allocation
#ifndef DMA_H_
#define DMA_H_
#include <iostream>

// Base Class Using DMA
class baseDMA
{
private:
    char * label;
    int rating;
public:
    baseDMA(const char * l = "null", int r = 0);
    baseDMA(const baseDMA & rs);
    virtual ~baseDMA();
    baseDMA & operator=(const baseDMA & rs);
    friend std::ostream & operator<<(std::ostream & os,
                                     const baseDMA & rs);
};

// derived class without DMA
// no destructor needed
// uses implicit copy constructor
// uses implicit assignment operator
class lacksDMA :public baseDMA
{
private:
    enum { COL_LEN = 40 };
    char color[COL_LEN];
public:
    lacksDMA(const char * c = "blank", const char * l = "null",
             int r = 0);
    lacksDMA(const char * c, const baseDMA & rs);
    friend std::ostream & operator<<(std::ostream & os,
                                     const lacksDMA & rs);
};

// derived class with DMA
class hasDMA :public baseDMA
{
private:
    char * style;
public:
    hasDMA(const char * s = "none", const char * l = "null",
                int r = 0); // 别写错混淆类名啊啊啊啊啊啊啊
    hasDMA(const char * s, const baseDMA & rs);
    hasDMA(const hasDMA & hs);
    ~hasDMA();
    hasDMA & operator=(const hasDMA & rs);
    friend std::ostream & operator<<(std::ostream & os,
                                     const hasDMA & rs);
};

#endif

// 程序清单13.15 类baseDMA, lackDMA, hasDMA的方法定义
// 程序清单13.15 dma.cpp
// dma.cpp -- dma class methods
// #include "dma.h"
#include <cstring>

// baseDMA methods
baseDMA::baseDMA(const char * l, int r)
{
    label = new char[std::strlen(l) + 1];
    std::strcpy(label, l);
    rating = r;
}

baseDMA::baseDMA(const baseDMA & rs)
{
    label = new char[std::strlen(rs.label) + 1];
    std::strcpy(label, rs.label);
    rating = rs.rating;
}

baseDMA::~baseDMA()
{
    delete [] label;
}

baseDMA & baseDMA::operator=(const baseDMA & rs)
{
    if (this == &rs)
        return *this;
    delete [] label;
    label = new char[std::strlen(rs.label) + 1];
    std::strcpy(label, rs.label);
    rating = rs.rating;
    return *this;
}

std::ostream & operator<<(std::ostream & os, const baseDMA & rs)// 第一个参数别忘了传引用！
{
    os << "Label: " << rs.label << std::endl;
    os << "Rating: " << rs.rating << std:: endl;
    return os;// 别忘了返回值！！！
}   

// lacksDMA methods
lacksDMA::lacksDMA(const char * c, const char * l, // 函数定义不可以写默认值！！！！！！！！！！！
                    int r) : baseDMA(l, r)  // 成员初始化列表调用积累构造函数！！！
{
    std::strncpy(color, c, 39);         // 新的复制函数，这个用法会是什么呢？这个是咋回事呢？
    color[39] = '\0';
}

lacksDMA::lacksDMA(const char * c, const baseDMA & rs)
    : baseDMA(rs)
{
    std::strncpy(color, c, COL_LEN - 1);
    color[COL_LEN] = '\0';
}

std::ostream & operator<<(std::ostream & os,
                          const lacksDMA & ls)
{
    // operator<<(os, baseDMA(rs));
    os << (const baseDMA &) ls;
    os << "Color: " << ls.color << std::endl;
    return os;      // 别忘了返回值！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
}

// hasDMA methods
hasDMA::hasDMA(const char * s, const char * l, int r)
    : baseDMA(l, r)
{
    style = new char[std::strlen(s) + 1];
    strcpy(style, s);           // 明明都是char指针咋就不一样了呢？？？？？？？？？？？？？？？？？？？？？？？？
}

hasDMA::hasDMA(const char * s, const baseDMA & rs)
    : baseDMA(rs)
{
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA & hs)
    : baseDMA(hs)       // invoke base class copy constructor
{
    style = new char[std::strlen(hs.style) + 1];
    strcpy(style, hs.style);
}

hasDMA::~hasDMA()
{
    delete [] style;
}

hasDMA & hasDMA::operator=(const hasDMA & hs)
{
    if (this == &hs)
        return *this;
    baseDMA::operator=(hs);      // copy base portion           // 注意这里调用对象就是原调用对象，省略了一个this->
    delete [] style;             // prepare for new style
    style = new char[std::strlen(hs.style) + 1];
    std::strcpy(style, hs.style);
    return *this;
}

std::ostream & operator<<(std::ostream & os, const hasDMA & hs)
{
    // type cast to match operator<<(ostream &, const baseDMA &)
    os << (const baseDMA &) hs;
    os << "Style: " << hs.style << std::endl;
    return os;  // 别忘了返回值啊！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
}

// 派生类如何使用基类的友元？
// 意义：通过基类的友元使用基类的私有数据
// 不是成员函数，不能用作用域解析运算符
// 强制类型转换，匹配原型时便可选择正确的函数
//      此处：将参数const hasDMA &转换成类型为const baseDMA &的参数
    //转类型咋还能带const，&的呢？                              //          还是说这个是参数，所以比较特殊？

// 程序清单13.16 测试baseDMA，lack(s)DMA和hasDMA的小程序
// 程序清单13.16 usedma.cpp
// usedma.cpp -- inheritance, friends, and DMA
// 才意识到原来DMA代表的应该是动态内存分配：Dynamic Memory Access.  <Assignment？
#include <iostream>
// #include "dma.h"
int main()
{
    using std::cout;
    using std::endl;

    baseDMA shirt("Portabelly", 8);
    lacksDMA balloon("red", "Blimpo", 4);
    hasDMA map("Mercator", "Buffalo Keys", 5);

    cout << "Displaying baseDMA object:\n";
    cout << shirt << endl;
    cout << "Displaying lacksDMA object:\n";
    cout << balloon << endl;
    cout << "Displaying hasDMA object:\n";
    cout << map << endl;

    lacksDMA balloon2(balloon);
    cout << "Result of lacksDMA copy:\n";
    cout << balloon2 << endl;

    hasDMA map2;
    map2 = map;
    cout << "Result of hasDMA assignment:\n";
    cout << map2 << endl;

    return 0;
}

// 13.8 类设计回顾
