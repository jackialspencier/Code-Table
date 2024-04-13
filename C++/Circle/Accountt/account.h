#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
using namespace std;
class SavingAccount{
    int account;
    static int count;
    double saving;
    float mrate12 = 0.05;
public:
    SavingAccount(double money);
    void display();
    void calculate();
    void changerate(float nrate);
};
#endif