// 4.2 队列的顺序实现
// 4.2.1 顺序队列的存储实现
// 顺序实现——顺序队列，由一个一维的数组组成
// 1. 队头位置固定的顺序实现
//      入队、判队空、读队头的时间复杂度都是O(1)
//      出队操作O(N)
//      当有元素出队时，队列中所有元素都向前移动一个位置
// 2. 队头位置不固定的顺序实现
//      入队出队、判队空、读队头时间复杂度O1
//      problem:空间利用率
// 3. 循环队列（最常用储存方案）
//      入队：(rear+1) % maxSize; elem[rear] = x
//      出队：(front+1) % maxSize;
//      problem:如何确定队空和队满
//      solution:可以牺牲一个单元(or保存currentlength)
//          front指向的单元只起标志作用，不能保存数据
//      判队满：(rear + 1) % maxSize == front
//      判队空：front == rear;
//      summary：储存方案：一个数组，队头尾位置front和rear
// 代码清单4-2 顺序队列类的定义
template<class elemType>
class seqQueue: public queue<elemType>
{
private:
    elemType *elem;
    int maxSize;
    // elemType *front;
    // elemType *rear;
    int front,rear;
    void doubleSpace();
public:
    seqQueue(int size = 10);
    ~seqQueue();
    bool isEmpty() const;
    void enQueue(const elemType &x);
    elemType deQueue();//不要参数，出队的一定是队头
    elemType getHead() const;
};
// 4.2.2 循环队列的运算实现
// 代码清单4-3 循环队列中的构造函数、析构函数、读队头元素、出队和判队空函数的实现
template<class elemType>
seqQueue<elemType>::seqQueue(int size)
{
    elem = new int[size];
    maxSize = size;
    front = rear = 0;
}

template<class elemType>
seqQueue<elemType>::~seqQueue()
{
    delete [] elem;
}

template<class elemType>
bool seqQueue<elemType>::isEmpty() const
{
    return front == rear;
}

template<class elemType>
elemType seqQueue<elemType>::getHead() const
{
    return elem[(front+1)%maxSize];// return elem[rear];头尾！！！！！！分清楚！
}

template<class elemType>
elemType seqQueue<elemType>::deQueue()
{
    front = (front+1) % maxSize;
    return elem[front];
}

// 代码清单4-4 enQueue和doubleSpace函数的实现
template<class elemType>
void seqQueue<elemType>::enQueue(const elemType &x)
{
    // rear = (rear+1)%maxSize;
    // if(rear == front)
    //     doubleSpace();
    // elem[rear] = x;
    if ((rear+1) % maxSize == front)
        doubleSpace();
    rear = (rear+1) % maxSize;
    elem[rear] = x;
}

template<class elemType>
void seqQueue<elemType>::doubleSpace()
{
    elemType * p = elem;
    elem = new elemType[2 * maxSize];
    // for (int i = 0; i < maxSize; i++)
    //     elem[i] = p[i];
    for(int i = 1; i <= maxSize; i++)//为什么是小于不是小于等于？
        elem[i] = p[(front+i)%maxSize];
    delete [] p;//为什么只需要delete p？
    front = 0;
    rear = maxSize;//为什么不是maxsize？
    maxSize *= 2;
}

// 4.2.3 循环队列的简单示例
// 例4.2循环队列区分队空与队满，通常牺牲一个单元。
//      这个问题也可以通过保存队列长度的方法解决。设计一个按此方法实现的循环队列类。
// 代码清单4-5 保存队列长度的循环队列类的实现
template<class elemType>
class seqQueue
{
private:
    elemType * elem;
    int maxSize;
    int front, rear;//此时front指向的第一个数据的前一个为止也可以存放数据。除了队满and空判断(及用到判断的)改动其他几乎不变。
    int currentLength;
    void doubleSpace();
public:
    seqQueue(int size = 10);
    ~seqQueue();
    bool isEmpty() const;
    elemType getHead() const;
    void enQueue(const elemType &x);
    elemType deQueue();
};

template<class elemType>
seqQueue<elemType>::seqQueue(int size)
{
    elem = new int[size];
    maxSize = size;
    front = rear = maxSize-1;
    currentLength = 0;
}

template<class elemType>
seqQueue<elemType>::~seqQueue()
{
    delete [] elem;
}

template<class elemType>
bool seqQueue<elemType>::isEmpty() const
{
    return currentLength == 0;
    // return (currentLength == maxSize);//判队空不是队满
}

template<class elemType>
elemType seqQueue<elemType>::getHead() const
{
    return elem[(front+1) % maxSize];
}

template<class elemType>
void seqQueue<elemType>::enQueue(const elemType &x)
{
    if (currentLength == maxSize)
        doubleSpace();
    rear = (rear+1) % maxSize;
    elem[rear] = x;
    currentLength++;
}

template<class elemType>
elemType seqQueue<elemType>::deQueue()
{
    front = (front+1) % maxSize;
    return elem[front];
    currentLength--;
}

template<class elemType>
void seqQueue<elemType>::doubleSpace()
{
    elemType * tmp = elem;
    elem = new int[maxSize * 2];
    for (int i = 0; i < maxSize; i++)
        elem[i] = tmp[(front+i+1)%maxSize];//yeah!!!
    delete [] tmp;
    front = 2* maxSize - 1;//-1
    rear = maxSize - 1;
    maxSize *= 2;
}