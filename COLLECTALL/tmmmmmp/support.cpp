// 程序清单support.cpp
// support.cpp -- use external variable
// compile with external.cpp
#include <iostream>
extern double warming; // use warming from another file

// function prototype
void update(double dt);
void local();

using std::cout;
void update(double dt)          //modifies global variables
{         
    extern double warming;      //optional redeclaration
    warming += dt;              //uses global warming
    cout << "Updating global warming to " << warming;
    cout << " degrees.\n";

}

void local()
{
    double warming = 0.8;//new variable hides external one

    cout << "Local warming = " << warming << " degrees.\n";
        //Access global variable with the
        //scope resolution operator
    cout << "But global warming = " << ::warming;
    cout << " degrees.\n";
}