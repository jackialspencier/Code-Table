#ifndef STONEWT_H_
#define STONEWT_H_
class Stonewt
{
private:
    enum{ Lbs_per_stn = 14 };  // pounds per stone
    int stone;                 // whole stones
    double pds_left;           // fractional pounds     // 啥意思，干啥的？
    double pounds;             // entire weight in punds
public:
    Stonewt(double lbs);        // constructor for double pounds
    Stonewt(int stn, double lbs);   // constructor for stone, lbs
    Stonewt();                  // default constructor
    ~Stonewt();
    void show_lbs() const;      // show weight in punds format
    void show_stn() const;      // show weight in stone format
};
#endif

// 程序清单11.17 stonewt.cpp
#include <iostream>
using std::cout;
// #include "stonewt.h"

// construct Stonewt object from double value
Stonewt::Stonewt(double lbs)
{
    stone = int (lbs) / Lbs_per_stn;
    pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);//这个lbs - int(lbs)就很妙
    pounds = lbs;
}
Stonewt::Stonewt(int stn, double lbs)
{
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_per_stn + lbs;
}
Stonewt::Stonewt()  // default constructor, wt = 0.0
{
    stone = pds_left = pounds = 0.0;// 别把int的stone放前面，虽然这里没啥影响
}
Stonewt::~Stonewt()     // destructor
{
}
//show weight in stones
void Stonewt::show_stn() const
{
    cout << stone << " stone, " << pds_left << " pounds\n";
}
// show weight in pounds
void Stonewt::show_lbs() const
{
    cout << pounds << " pounds\n";
}

// 程序清单11.18 stone.cpp
// stone.cpp -- user-defined conversions
// compile with stonewt.cpp
include <iostream>
using std::cout;
// #include "stonewt.h"
void display(const Stonewt & st, int n);
int amin()
{
    Stonewt incognito = 275;    // use constructor to initialize
    Stonewt wolfe(285.7);       // same as Stonewt wolfe
    Stonewt taft(21, 8);

    cout << "The celebrity weighed ";
    incognito.show_stn();
    cout << "The detective weighed ";
    wolfe.show_stn();
    cout << "The President weighed ";
    taft.show_lbs();
    incognito = 276.8;      // uses constructor for conversion
    taft = 325;             // same as taft = Stonewt(325);
    cout << "After dinner, the celebrity weighed ";
    incognito.show_stn();
    cout << "After dinner, the President weighed ";
    taft.show_lbs();
    display(taft, 2);
    cout << "The wrestler weighed even more.\n";
    display(422, 2);
    cout << "No stone left unearned\n";
    return 0;
}

void display(const Stonewt & st, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Wow!";
        st.show_stn();
    }
}