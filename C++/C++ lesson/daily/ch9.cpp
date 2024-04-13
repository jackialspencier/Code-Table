#include <iostream>
using namespace std;
class mystack{
    int * p;
    int maxsize;
    int * tpp;
public:
    mystack(int n);
    ~mystack();
    bool push(int num);
    bool pop(int & num);
    bool isempty();
    bool isfull();
};

mystack::mystack(int n)
{
    p = new int[n];
    maxsize = n;
    tpp = p - 1;
}

mystack::~mystack()
{
    delete [] p;
}

bool mystack::push(int num)
{
    if (tpp + 1 - p < maxsize){ //压入后还要在范围内
        tpp += 1;
        *tpp = num;
        return true;
    }
    else
        return false;
}

bool mystack::pop(int & num)
{
    if (tpp >= p){ // 重叠时还有一个
        num = *tpp;
        tpp--;
        return true;
    }
    else
        return false;
}

bool mystack::isempty()
{
    if (tpp - p == -1)
        return true;
    else
        return false;
}

bool mystack::isfull()
{
    if (tpp - p == maxsize - 1)
        return true;
    else
        return false;
}

int main()
{
    int num[] = {1, 3, 5, 7, 9, 11}, data;
    mystack s(5);
    cout << "The stack is empty: " << s.isempty() << endl;
    cout << "The stack is full: " << s.isfull() << endl;
    for (int i = 0; i <= 5; i++)
    {
        if (s.push(num[i]))
            cout << "Push " << num[i] << " success!" <<endl;
        else
            cout << "Push " << num[i] << " fail!" << endl;
    }
    cout << "The stack is empty: " << s.isempty() << endl;
    cout << "The stack is full: " << s.isfull() << endl;
    for (int i = 0; i <= 5; i++)
    {
        if (s.pop(data))
            cout << "Pop " << data << " success!" << endl;
        else
            cout << "Pop fail!" <<endl;
    }
    return 0;
}