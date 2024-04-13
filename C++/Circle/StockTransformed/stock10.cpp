// 2.实现文件
// 程序清单10.5 stock10.cpp
// stock10.cpp -- Stock class with constructors, destructor added
#include <iostream>
#include <string>
#include "stock10.h"

// constructors (berboss versions)
Stock::Stock(){     //default constructor
    std::cout << "Default constructor called\n";
    company = "no name";// 应提供初始值
    shares = 0;
    share_val = 0.0;
    total_val = 0.0;// 应该也可以set_tot();
}

Stock::Stock(const std::string & co, long num, double price){
    std::cout << "Constuctor using " << co << " called\n";
    company = co;

    if (num < 0)
    {
        std::cout << "Number of shares can't be negative; "
                    << company << " shares set to 0.\n";
        shares = 0;
    }
    else
        shares = num;
    share_val = price;
    set_tot();
}
//class destructor
Stock::~Stock(){
    std::cout << "Bye, " << company << "!\n";// << std::endl
}
// other methods
void Stock::buy(long num, double price){
    using std::cout;
    if (num < 0){
        cout << "Numbers of shares purchased can't be negative. "//"Shares bought can't be less than zero. ";
        // std::cout << "!";// 重复使用using声明和限定名称？？？？？？？？？？？？？？？？？？？？？？？？？？？？//：：叫啥来着作用域限定符？
            << "Transaction is aborted.\n";
    }
    else{
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(long num, double price){
    using std::cout;
    if (num < 0)
        cout << "Number of shares sold can't be negative."
            << "Transaction is aborted.\n";
    else if (num > shares)
        cout << "You can't sell more than you have!"
            << "Transaction is aborted.\n";
    else{
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price){
    share_val = price;
    set_tot();
}

// void Stock::show(){
//     using std::cout;
//     cout << "Company: " << company << "\tShares: " << shares << std::endl;
//     cout << "\tShare value: " << share_val << "\tTotal value: " << total_val;
// }

void Stock::show(){
    using std::cout;
    using std::ios_base;
    //set format to #.###
    ios_base::fmtflags orig =
        cout.setf(ios_base::fixed, ios_base::floatfield);
    std::streamsize prec = cout.precision(3);

    cout << "Company: " << company
        << "  Shares: " << shares << '\n';
    cout << "  Shares price: " << share_val;
    //set format to #.##
    cout.precision(2);
    cout << "  Total worth: $" << total_val << '\n';
    
    // restore original format
    cout.setf(orig, ios_base::floatfield);
    cout.precision(prec);
}