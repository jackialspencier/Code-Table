// 第四章 队列
// 4.1 队列的定义
// 队尾（允许插入），队头（允许删除），队头元素，队尾元素
// 空队列，入队，出队
// 队列——先进先出的线性表

// 队列的基本操作
// 创建一个新的队列create()：创建一个空的队列
// 入队enQueue()：将x插入队尾，使之成为队尾元素
// 出队deQueue()：删除队头元素并返回队头元素的值
// 读队头元素getHead()：返回队头元素的值
// 判队列空isEmpty()：若队列为空，返回true，否则返回false

// 代码清单4-1 队列的抽象类
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

// 4.2 队列的顺序实现
// 4.2.1 顺序队列的储存实现
// 顺序队列，一维数组
// 
