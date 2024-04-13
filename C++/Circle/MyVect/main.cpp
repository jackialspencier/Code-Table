#include "myvect.h"
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    MyVect v1(n);
    double x;
    cin >> v1;
    cout << "Now v1 is: "<< v1 << endl;
    cout << "The length of v1 is " << v1.getlength() << endl;
    cout << "The norm of v1 is " << v1.getnorm() << endl;
    x = v1 - 1.0;
    cout << "The norm of v1 minus 1 is " << x << endl;
    MyVect v2 = v1;
    cout << "Now v2 is: " << v2 << endl;
    //cout << "The number of vectors is: " << v1.getcount() << endl;
    cout << endl;
    {
        MyVect v3(n);
        v3= v1 + v2;
        cout << "The result of v1+v2 is: " << v3 << endl;
        cout << "The 1st element of v3 is " << v3[1] << endl;
        //cout << "The number of vectors is: " << MyVect::getcount() << endl;
    }
    cout << endl;
    cout << "The number of living vectors is: " << v1.getliving() << endl;
    //cout << "The number of total vector is: " << v1.getcount() << endl;
    cout << "The result of v1++ is: " << v1++ << endl;
    cout << "The result of v1==v2 is " << (v1==v2) << endl;
    cout << "The result of ++v2 is: " << ++v2 << endl;
    cout << "The result of v1==v2 is " << (v1==v2) << endl;
    return 0;
}