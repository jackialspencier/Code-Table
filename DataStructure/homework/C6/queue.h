#ifndef QUEUE_H_
#define QUEUE_H_
template<class elemType>
class queue
{
    public:
        virtual bool isEmpty() const = 0;               // 判队空
        virtual void enQueue(const elemType &x) = 0;    // 进队
        virtual elemType deQueue() = 0;                 // 出队
        virtual elemType getHead() const = 0;           // 读队头函数
        virtual ~queue() {}                             // 虚析构函数           // why is it necessary
};
#endif