// 程序清单9.5 external.cpp
// external.cpp -- external variables
// compile with support.cpp

// 9.3.名称空间
// 程序清单9.5 external.cpp
// external.cpp -- external variables
// compile with support.cpp
#include <iostream>
using namespace std;
// external variable
double warming = 0.3; //warming defined
//function prototypes
void update(double dt);
void local();

int main()              //uses global variable
{
    cout << "Global warming is " << warming << " degrees.\n";
    update(0.1);
    cout << "Global warming is " << warming << " degrees.\n";
    local();
    cout << "Global warming is " << warming << " degrees.\n";
    return 0;
}