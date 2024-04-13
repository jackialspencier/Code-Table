// 10.3.5 改进Stock类
// 1.头文件
// 程序清单10.4 stock10.h
//stock10.h -- Stock class declaration with const constructors, destructor added
#ifndef STOCK10_H_
#define STOCK10_H_
#include <string>
class  Stock{
    std::string company;//string在std里
    long shares;
    double share_val;
    double total_val;
    void set_tot() { total_val = shares * share_val; }
public:
// two constructors
    Stock();//default constructor
    Stock(const std::string & co, long num = 0, double price = 0.0);
    ~Stock();
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    void show();
};
#endif