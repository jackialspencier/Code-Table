// 第3章 栈
// 栈的逻辑结构、栈的实现、常见的栈的应用
// 3.1 栈的定义
// 代码清单3-1 栈的抽象类
template<class elemType>
class stack
{
    public:
        virtual bool isEmpty() const =0;    // 判栈空
        virtual void push(const elemTYpe &x) = 0; // 进栈
        virtual elemType pop() = 0;      // 出栈
        virtual elemType top() const = 0;// 取栈顶元素
        virtual ~stack() {}
};
// 3.2 栈的顺序实现
// 代码清单3-2 顺序栈的定义
template<class elemType>
class seqStack:public stack<elemType>
{

};
// 3.3 栈的链接实现
// 3.4 STL中的栈
// 3.5 栈的应用
// 3.5.1 递归消除——递归时间复杂度
// 3.5.2 括号配对——用栈实现计算器
// 3.5.3 简单的计算器