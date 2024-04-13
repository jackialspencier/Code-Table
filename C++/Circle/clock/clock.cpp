#include <iostream>
#include "clock.h"
using namespace std;
void Clock::read(){
    for (int i = 0; i < 3; i++){
        cin >> tt[i];
        cin.get();
    }
}

void Clock::show(){
    for (int i = 0; i < 3; i++)
    {
        if (tt[i] < 10)
            cout << "0" << tt[i];
        else
            cout << tt[i];
        if (i < 2)
            cout << ":";
    }
}

Clock getminus(const Clock & a, const Clock & b)
{
    Clock ans;
    bool fmlater = false;
    for (int i = 0; i < 3; i++)
        if (a.tt[i] > b.tt[i]){
            fmlater = true;
            break;
        }
        else if (a.tt[i] < b.tt[i]){
            fmlater = false;
            break;
        }

    for (int i = 0; i < 3; i++)
        ans.tt[i] = 0;
    if (fmlater)
        for (int i = 2; i >= 0; i--)
        {
            ans.tt[i] += a.tt[i] - b.tt[i];
            if (ans.tt[i] < 0){
            ans.tt[i] += 60;
            ans.tt[i-1]--;
            }
        }
    else
    for (int i = 2; i >= 0; i--)
        {
            ans.tt[i] += b.tt[i] - a.tt[i];
            if (ans.tt[i] < 0){
            ans.tt[i] += 60;
            ans.tt[i-1] -= 1;
            }
        }
    return ans;
}