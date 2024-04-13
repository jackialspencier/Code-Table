// 第二章 线性表
// 2.1 线性表的定义
// 代码清单2-1 线性表的抽象类
template<class elemTyepe>
class list
{
    public:
        virtual void clear()=0;         // 删除所有
        virtual int length() const=0;   // 求表长
        virtual void insert(iny i, const elemType&x)=0; // 插入元素
        virtual void remove(int i)=0;   // 删除
        virtual int research(const elemType& x)=0;      // 搜索元素
        virtual elemType visit(int i)=0;// 返回第i个元素的值
        virtual void traverse() const=0;// 遍历
        virtual ~list() {};
};

// 2.2 线性表的顺序实现
// 顺序实现，顺序表，与内存对应
// 2.2.1 线性表的储存实现
// 顺序实现：储存在一块连续空间中，用储存位置反应数据元素之间的关系
// 代码清单2-2 顺序表类的定义和实现
template<class elemType>
class seqList: public list<elemType>//从线性表的抽象类list公有派生
{
    private:
        elemType *data;//储存线性表元素起始地址
        int currentLength;//线性表表长
        int maxSize;//数组规模
        void doubleSpace();     //扩大数组空间
    public:
        seqList(int initSize = 10);
        ~seqList();
        void clear();
        int length() const;
        void insert(int i, const elemType &x);
        void remove(int i);
        int search(const elemType &x) const;
        elemType visit(int i) const;
        void traverse() const;
};

// 2.2.2 顺序表的运算实现
// 代码清单2-3 顺序表类的clear、visit、length和析构函数的实现
// 析构函数释放动态数组的空间
template<class elemType>
seqList<elemType>::~seqList()
{
    delete [] data;
}
// clear()将currentLength置0
template<class elemType>
void seqList<elemType>::clear()
{
    currentLength = 0;
}
// length()返回变量currentLength的值
template<class elemType>
int seqList<elemType>::length() const
{
    return currentLength;
}
// visit(i)返回data[i]的值
template<class elemType>
elemType seqList<elemType>::visit(int i) const
{
    return data[i];
}

// traverse()输出数组data的前currentLength个元素
// 代码清单2-4 顺序表类的traverse函数的实现
template<class elemType>
void seqList<elemType>::traverse() const
{
    cout << endl;
    for (int i = 0; i < currentLength; i++)
        cout << data[i] << ' ';
}

// 创建一个空的顺序表，估计数组初始规模(提高顺序表效率，避免反复使用doublespace参数)
// 代码清单2-5 顺序表类构造函数的实现
template <class elemType>
seqList<elemType>::seqList(int initSize)
{
    data = new elemType[initSize];
    maxSize = initSize;
    currentLength = 0;
}

// search查找某个元素是否出现在线性表中，存在则序号是多少
// 代码清单 2-6 顺序表类search函数的实现
template<class elemType>
int seqList<elemType>::search(const elemType &x) const
{
    // for (int i = 0; i < currentLength; i++)
    //     if (data[i] == x) 
    //         return i;
    // return -1;

    // int i;
    for (int i = 0; i < currentLength && data[i] != x; ++x);
    if (i == currentLength) return -1;
    else return i;
}

// 插入操作，顺序表采用顺序储存，物理顺序和逻辑顺序必须一致
// 插入：后移（从最后一个开始移动），空出位置待插入元素
// 扩大数组空间，申请动态数组，复制，释放原数组空间
// 代码清单 2-7 顺序表中插入函数和doubleSpace函数的实现
template<class elemType>
void seqList<elemType>::doubleSpace()
{
    elemType *tmp = data;

    maxSize *= 2;
    data = new elemType[maxSize];
    for (int i = 0; i < currentLength; ++i)
        data[i] = tmp[i];
    delete [] tmp;
}

template<class elemType>
void seqList<elemType>::insert(int i, const elemType &x)
{
    if (currentLength == maxSize)
        doubleSpace();
    for (int j = currentLength; j > i; j--)
        data[j] = data[j - 1];
    // for (int j = currentLength - 1; j >= i; j--)
    //     data[j+1] = data[j];
    data[i] = x;
    ++currentLength;//别漏啦！！
}
// 删除，其后所有元素前移（必须从最前一个待移动的元素开始，与插入移动顺序相反）
// 代码清单2-8 顺序表类删除函数的实现
template<class elemType>
void seqList<elemType>::remove(int i)
{
    for (int j = i; j < currentLength-1; j++)
        data[j] = data[j+1];
    for (nt j = i + 1; j < currentLength; j++)//注意是小于，不是小于等于，别多减了！！
        data[j-1] = data[j];
    currentLength--;
}

// 2.2.3 顺序实现的性能分析
// 由于要保持物理与逻辑顺序一致性，插入时性能不太理想，但适合做定位访问的线性表

// 2.2.4 顺序表的简单示例
// 例2.2 4.7.{1, 3, 4, 7, 2, 10, 4, 3}.4(x)search是找指定元素的位置



// 2.3 线性表的链接实现
// 以链接的方式来储存线性表——链表
// 结点包含 数据+关系(地址)
// 单链表、双链表、单循环链表、双循环链表

// 2.3.1 单链表
// 每个结点由一个数据元素和一个后继指针组成
// 线性关系不是由存储位置来实现，而是由指针来实现
// 插入可以由修改指针指向实现
// 1.单链表的储存实现
// 储存一个单链表只需要一个指向头节点的指针，头指针——只需要一个数据成员
// 定义结点类型，私有内嵌类，由数据成员data和指向直接后继的指针next，经常需要访问数据，用struct定义
// 为便于不用遍历则返回表长，在单链表中设置一个保存表长的数据成员
// 代码清单2-10 单链表类的定义
template<class elemType>
class sLinkList: public list<elemType>
{
private:
    struct node{
        elemType data;
        node * next;//node类指针不是elemType指针

        node(const elemType &x, node *n = NULL) //复制构造函数吧
            {data = x, next = n;;}
        node():next(NULL){} //默认构造函数吧
        ~node() {}
    }//：不仅数据项，还有构造函数和析构函数

    node * head;        // 头指针
    int currentLength;  // 表长

    node *move(int i) const;    // 返回第i个结点的地址//工具函数

public:
    sLinkList();//：构造函数做的事：定义属性，初始化
    ~sLinkList() {clear(); delete head;}

    void clear();
    void length() const {return currentLength;}
    void insert(int i, const elemType &x);
    void remove(int i);
    int search(const elemType &x) const;
    elemType visit(int i) const;
    void traverse() const;
};

// 2.单链表的运算实现
// 找到第i个结点的地址需要将一个指针从head开始后移i+1次
// 代码清单2-11 单链表类私有成员函数move的实现
template<class elemType>
sLinkList<elemType>::structure node *sLinkList<elemType>::move(int i) const// ：要structure node 
{
    node *p = head;
    while(i-- >= 0) p = p->next;
    return p;
}

// 构造函数创建一个空的链表，只有一个头结点的单链表——申请空间放节点，结点地址放head
// 代码清单2-12 单链表类的构造函数
template<class elemType>
sLinkList<elemType>::sLinkList()
{
    head = new node;
    currentLength = 0;
}

// clear删除所有元素，head指向设置为空，释放所有节点的空间
// 代码清单2-13 单链表类清空函数的实现
template<class elemType>
void sLinkList<elemType>::clear()
{
    node *p = head -> next, *q;    
    head -> next = NULL;// 别忘了属性更新
    while(p != NULL)
    {
        q = p->next;
        delete p;
        p = q;
    }        
    currentLength = 0;            
    // node *p = head;
    // node *q = p->next;
    // while(q != NULL){
    //     delete p;
    //     p = q;
    //     q = p->next;
    // }
    // delete p;
}

// try：
// void sLinkList<elemType>::clear()
// {
//     node * p = head, * q = head -> next;
//     while(p != null)
//     {
//         q = p -> next;
//         delete p;
//         p = q; 
//     }
//     currentLength = 0;
// }

// 代码清单2-14 单链表类的插入何删除函数的实现
// pos -> next = new node(x, p->next);//妙蛙
// 删除过程与插入类似
// 被删存入delp，链接，删除
// 代码清单2-14 单链表类的插入和删除函数的实现
template<class elemType>
void sLinkList<elemType>::insert(int i, const elemType &x)
{
    node * pos;
    pos = move(i-1);
    pos->next = new node(x ,pos->next);
    ++currentLength;
}

template<class elemType>
void sLinkList<elemType>::remove(int i)
{
    node *pos, *delp;

    pos = move(i-1);
    delp = pos->next;
    pos -> next = delp->next;   // 绕过delp
    delete delp;
    --currentLength;
}

// 代码清单2-15 单链表中search\visit和traverse函数的实现
template<class elemType>
int sLinkList<elemType>::search(const elemType &x) const
{
    // node *p = head->next;
    // int i = 0;
    // while(p != NULL)
    // {
    //     if (p -> data == x)
    //         return i;
    //     p = p -> next;
    // }
    // return -1;
    node *p = head->next;
    int i = 0;

    while(p != NULL && p->data != x) {p = p -> next; i++}
    if (p == NULL) return -1; else return i;
}
template<class elemType>
elemType sLinkList<elemType>::visit(int i) const
{
    return move(i)->data;
}
template<class elemType>
void sLinkList<elemType>::traverse() const
{
    node *p = head -> next;
    cout << endl;
    while(p != NULL){
        cout << p->data << "  ";
        p = p->next;
    }
    cout << endl;
}
// 3.单链表的简单示例
// 例2.4 erase(i)函数：删除所有等于第i个元素的元素
// 代码清单 2-16 例2.4 实现代码
template<class elemType>
void sLinkList<elemType>::erase(int i)
{
    node *pre = move(i);
    elemType tmp = pre->data;
    remove(i);
    node *p = head->next;
    int i = 0;
    while(p != NULL)
    {
        if (p->data == tmp){
            remove(i);  // 貌似复杂度不符合了？
            currentLength--;
        }
        p = p->next;
        i++;
    }

}

template<class elemType>
void sLinkList<elemType>::erase(int i)
{
    node *pre = move(i-1), *delp = pre->next;// pre指向被删结点迁移节点，delp指向被删结点
    elemType tmp = delp->data;
    int cnt = 1;


    pre->next = delp->next; // 删除第i个结点
    delete delp;

    for(pre = head; pre->next != NULL; pre = pre->next)   // 删除所有值等于tmp的结点
    if (pre->next->data == tmp)
    {
        delp = pre->next;
        pre->next = delp->next;
        delete delp;
        ++cnt;
    }
    currentLength -= cnt;
}

// 2.3.2 双链表
// 代码2-17 双链表的定义和实现
template<class elemType>
class dLinkList: public list<elemType>
{
    private:
        struct node{    // 双链表中的结点类
            elemType data;
            node * prev, *next;

            node(const elemType &x, node *p = NULL, node *n = NULL)
                { data = x; next = n; prev = p;}
            node():next(NULL), prev(NULL) {}
            ~node(){}
        };
    
    node * head, tail;  // 头尾指针
    int currentLength;  // 表长

    node *move(int i) const; // 返回第i个结点的地址

    public:
        dLinkList();
        ~dLinkList() {clear(); delete head; delete tail;}

        void clear();
        int length() const {return currentLength;}
        void insert(int i, const elemType &x);
        void remove(int i);
        int search(const elemType &x) const;
        elemType visit(int i) const;
        vooid traverse() const;
}
// 1.双链表的储存实现
// 2.双链表的运算实现
// 代码清单2-18 双链表构造函数的实现
// 代码清单2-19 双链表的插入、删除和move函数实现
// 代码清单visit、clear、search和traverse函数的实现

// 3.双链表的简单示例
// 不需要附加头尾节点
// 代码清单2-21 例2.5的实现代码

// 2.3.3 循环链表
// 2.3.4 链表的性能分析

// 2.4 标准模板库(STL)中的线性表
// 2.5 线性表的应用