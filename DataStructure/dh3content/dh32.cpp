// 3.2.1 顺序栈的储存实现
// 代码清单3-2 顺序栈类的定义
template<class elemType>
class seqStack: public stack<elemType>
{
    private:
        elemType * elem;
        int top_p;
        int maxSize;
        void doubleSpace();
    public:
        seqStack(int initSize = 10);
        ~seqStack();
        bool isEmpty() const;
        void push(const elemType &x);
        elemType pop();
        elemType top() const;
};

// 3.2.2 顺序栈的运算实现
// 代码清单3-3 顺序栈构造函数和析构函数的实现
template<class elemType>
seqStack<elemType>::seqStack(int initSize)//书上seqList应该有误吧？
{
    elem = new elemType[initSize];
    maxSize = initSize;
    top_p = -1;
}

template<class elemType>
seqStack<elemType>::~seqStack()
{
    delete [] elem;
}

// 代码清单3-4 顺序栈中进栈，出栈、返回栈顶元素和判栈空操作的实现
template<class elemType>
bool seqStack<elemType>::isEmpty() const
{
    return (top_p == -1);//不用括号
}

template<class elemType>
void seqStack<elemType>::push(const elemType &x)
{
    if (top == initSize - 1)
        doubleSpace();
    // else     //不需要else！！！
    // {
    elem[++top_p] = x;
    // }
}

template<class elemType>
elemType seqStack<elemType>::pop()
{
    return elem[top_p--];
}

template<class elemType>
elemType seqStack<elemType>::top() const
{
    return elem[top_p];
}

//try：
// template<class elemType>
// void seqStack<elemType>::doubleSpace()
// {
//     maxSize *= 2;
//     elemType * tmp = elem;
//     elem = new elemType[maxSize];
//     for (int i = 0; i <= top_p; i++)
//         elem[i] = tmp[i];
//     delete [] tmp;
// }

//主要区别：遍历边界使用的是更新前的maxSize而不是top（都行吗？？？？？？？？？？？？？？？？？）
template<class elemType>
void seqStack<elemType>::doubleSpace()
{
    elemType * tmp = elem;

    elem = new elemType[2 * maxSize];

    for (int i = 0; i < maxSize; ++i)
        elem[i] = tmp[i];
    
    maxSize *= 2;   
    delete [] tmp;
}

// 3.2.3 顺序栈的性能分析