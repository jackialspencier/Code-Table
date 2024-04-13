#ifndef LINKQUEUE_H_
#define LINKQUEUE_H_
#include "queue.h"
template<class elemType>
class linkQueue:public queue<elemType>
{
private:
    struct node{
        elemType data;
        node * next;
        node(const elemType &x, node * N = nullptr)
        {data = x; next = N;}
        node():next(nullptr){}
        ~node() {}
    };
    node * front, * rear;

public:
    linkQueue();
    ~linkQueue();
    bool isEmpty() const;
    elemType getHead() const;
    elemType deQueue();
    void enQueue(const elemType &x);
};


template<class elemType>
linkQueue<elemType>::linkQueue()
{
    front = rear = nullptr;
}

template<class elemType>
linkQueue<elemType>::~linkQueue()
{
    node * tmp;
    while(front != nullptr){
        tmp = front;
        front = front->next;
        delete tmp;
    }
}

template<class elemType>
bool linkQueue<elemType>::isEmpty() const
{
    return (front == nullptr);
}

template<class elemType>
elemType linkQueue<elemType>::getHead() const
{
    return front->data;
}
template<class elemType>
void linkQueue<elemType>::enQueue(const elemType &x)
{
    if (rear == nullptr)
        front = rear = new node(x);
    else
        rear = rear -> next = new node(x);
} 
template<class elemType>
elemType linkQueue<elemType>::deQueue()
{
    node * tmp = front;
    if(front){
    front = front->next;
    if (front == nullptr)
        rear = nullptr;
    elemType x = tmp->data;
    delete tmp;
    return x;}
}


#endif