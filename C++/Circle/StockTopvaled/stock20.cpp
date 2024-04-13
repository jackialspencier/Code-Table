// 程序清单10.8 stock20.cpp
// stock20.cpp -- argumented version
#include <iostream>
#include "stock20.h"

//constructors
Stock::Stock()      // default constructor
{
    company = "no name";
    shares = 0;
    share_val = 0.0;
    total_val = 0.0;// set_tot();
}  

Stock::Stock(const std::string & co, long n, double pr)
{
    company = co;

    if (n < 0){
        std::cout << "Number of shares can't be negative; "
                << company << " shares set to 0.\n";
        shares = 0;
        // share_val = 0.0;
        // set_tot();
        }
    else
        shares = n;
    share_val = pr;//!!!!!!!!!!!!!!!!!!在else外面
    set_tot();// !!!!!!!!!!!!!!!!!!!!
}

// class destructor
Stock::~Stock()     // quiet class destructor
{
}

//other methods
void Stock::buy(long num, double price)
{
    if (num < 0)
        std::cout << "Number of shares purchased can't be negative. "//bought
                << "Transaction is aborted.\n";
    else
    {
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(long num, double price)
{
    using std::cout;
    if (num < 0)
        cout << "Number of shares sold can't be negative. "
                << "Transaction is aborted.\n";
    else if (num > shares)
        cout << "You can't sell more than you have! "
            << "Transaction is aborted.\n";
    else
    {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price)
{
    share_val = price;
    set_tot();  //都别忘了set_tot
}

void Stock::show() const
{
    using std::cout;
    using std::ios_base;
    
    // set format to #.###
    ios_base::fmtflags orig = 
        cout.setf(ios_base::fixed, ios_base::floatfield);
    // ios_base::precision  prec =
    std::streamsize prec = cout.precision(3);//注意是哪个名称空间的哪个名称!!!!!!

    cout << "Company: " << company
        << "  Shares: " << shares << '\n';
    cout << "  Share value: $" << share_val;
    //set precision to #.##
    cout.precision(2);                          //皇帝的新设置?
    cout << "  Totol worth: $" << total_val << '\n';//value -> worth // 记得换行符

    // resort cout to former state
    cout.setf(orig, ios_base::floatfield);
    cout.precision(prec);

}

const Stock & Stock::topval(const Stock & s) const //两个const,别漏啦,漏了就不是同一个函数了(吧)?
{
    if (s.total_val > total_val)
        return s;
    else
        return *this;
}