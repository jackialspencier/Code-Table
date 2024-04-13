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



// 4.3 队列的链接实现
// 4.3.1 链接队列的储存实现
// 代码清单4-6 链接队列类的定义
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
    node * front, * rear;//*rear不是rear！！！

public:
    linkQueue();
    ~linkQueue();
    bool isEmpty() const;
    elemType getHead() const;
    elemType deQueue();
    void enQueue(const elemType &x);//not node &x
};
// 4.3.2 链接队列的运算实现
// 代码清单4-7 链接队列类的构造函数和析构函数的实现
template<class elemType>
linkQueue<elemType>::linkQueue()
{
    front = rear = nullptr;
}

template<class elemType>
linkQueue<elemType>::~linkQueue()
{
    // node * tmp = front;
    // while(front != nullptr){
    //     front = front->next;
    //     delete tmp;
    //     tmp = front;
    // }
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
    return x;}//那其他时候返回什么呢？flag？
}

// 4.3.3 链接队列的简单示例
