#include <iostream>
#include "clock.h"



using namespace std;
int main()
{
    Clock t1, t2;
    t1.read();
    t2.read();
    getminus(t1, t2).show();
    return 0;
}
