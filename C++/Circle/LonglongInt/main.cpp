struct bigInt{
    char * p = nullptr;
    int count;
public:
    bigInt(){count = 0;};
    bigInt(const bigInt &a);
    void read();
    void show();
    ~bigInt();
};

bigInt sum(bigInt & i1, bigInt &i2);


#include <iostream>
// #include "LongLongInt.h"
using namespace std;


#include <iostream>
// #include "LongLongInt.h"


using namespace std;

int main(){

    bigInt x1;
    bigInt x2;
    x1.read();
    x2.read();
    sum(x1,x2).show();
    return 0;
}



bigInt::bigInt(const bigInt & a)//!!!!!!!!!!!!!!!!!
{
    count = a.count;
    p = new char[count];
    for (int i = 0; i < count; i++)
        p[i] = a.p[i];
}

void bigInt::read()
{
    count = 0;
    char tmp;
    char * tp;
    tmp = cin.get();
    while(tmp <= '9' && tmp >= '0')
    {
        count++;
        tp = new char[count];
        if (p != nullptr){
            for (int i = 0; i < count - 1; i++)
                tp[i] = p[i];
            tp[count-1] = tmp;
            delete [] p;
            p = tp;
        }
        else
        {
            tp[count-1] = tmp;
            p = tp;
        }
        tmp = cin.get();
    }
}

void bigInt::show()
{
    for (int i = 0; i < count; i++)
        cout << p[i];                       //字符数组不是字符串,不能自动输出\0前面的然后结尾.
}

bigInt::~bigInt()
{
    if (p != nullptr)
        delete [] p;
}


bigInt sum(bigInt & i1, bigInt &i2)
{
    bigInt tmpi;
    int tt = 0;
    tmpi.count = (i1.count > i2.count ? i1.count : i2.count);
    tmpi.p = new char[tmpi.count];
    for (int i = 1; tmpi.count - i >= 0; i++)
        if (i1.count - i >= 0 && i2.count - i >= 0)
        {
            tmpi.p[(tmpi.count) - i] = ((i1.p[(i1.count) - i] - '0') + (i2.p[(i2.count - i)] - '0') + tt) % 10 + '0'; // tt要加在里面,不然9+1+'0'
            // tt = 0;
            if ((i1.p[(i1.count) - i] - '0') + (i2.p[(i2.count - i)] - '0') + tt >= 10)
                tt = ((i1.p[(i1.count) - i] - '0') + (i2.p[(i2.count - i)] - '0') + tt) / 10;
            else
                tt = 0;
        }
        else if (i1.count - i >= 0){
            tmpi.p[tmpi.count - i] = (i1.p[i1.count - i] - '0' + tt) % 10 + '0';
            if ((i1.p[i1.count - i] - '0' + tt) / 10)
                tt = (i1.p[i1.count - i] - '0' + tt) / 10;
            else
                tt = 0;
        }
        else if (i2.count - i >= 0){
            tmpi.p[tmpi.count - i] = (i2.p[i2.count - i] - '0' + tt) % 10 + '0';
            if ((i2.p[i2.count - i] - '0' + tt) / 10)
                tt = (i2.p[i2.count - i] - '0' + tt) / 10;
            else
                tt = 0;
        }
    if ((i1.count == i2.count && i1.p[0] - '0' + i2.p[0] - '0' + tt >= 10) 
            || (i1.count > i2.count && i1.p[0] - '0' + tt >= 10) 
            || (i2.count > i1.count && i2.p[0] - '0' + tt >= 10)) 
    {
        // if ((i1.count > i2.count && i1.p[0] + tt >= 10))                  // 记住人家是字符啊啊啊啊啊啊啊啊啊啊啊!!!!!!!!
        //     cout << "addd\n" << i1.p[0] + tt << endl;
        // if ((i2.count > i1.count && i2.p[0] + tt >= 10))
        //     cout << "addddd\n" << i2.p[0] + tt << endl;
        char * plusp;
        tmpi.count++;
        plusp = new char[tmpi.count];
        for (int i = 0; i < tmpi.count - 1; i++)
            plusp[i+1] = tmpi.p[i];
        plusp[0] = '1'; // 1被转换成.....................................................char了啊!
        delete [] tmpi.p;
        tmpi.p = plusp;
    }
    return tmpi;
}