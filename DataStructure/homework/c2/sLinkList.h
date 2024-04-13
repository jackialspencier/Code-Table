#include "list.h"
// 代码清单2-10 单链表类的定义
template<class elemType>
class sLinkList:public list<elemType>
{
private:
    struct node{        // 单链表中的节点类
        elemType data;
        node * next;

        node(const elemType &x, node *n = NULL)
            { data = x; next = n;}
        node():next(NULL) {}
        ~node() {}  //不会自动生成吗，为什么要写出来
    };

    node * head;        // 头指针
    int currentLength;  // 表长

    struct node * move(int i) const;// 返回第i个结点的地址

public:
    sLinkList();
    ~sLinkList() {clear(); delete head; }

    void clear();
    int length() const { return currentLength;}
    void insert(int i, const elemType &x);
    void remove(int i);
    elemType visit(int i) const;
    int search(const elemType &x) const;
    void traverse() const;
    void reverse();
};

template<class elemType>
struct sLinkList<elemType>::node* sLinkList<elemType>::move(int i) const//两边都需要struct！！！
{
    node *p = head;
    while(i-- >= 0 && p) 
        p = p->next;
    return p;
}

template<class elemType>
sLinkList<elemType>::sLinkList()
{
    head = new node;
    currentLength = 0;
}

template<class elemType>
void sLinkList<elemType>::clear()
{
    node *p = head -> next, *q;
    head->next = NULL;//对属性数据更新，别忘了啦
    while(p != NULL)    // 删除列表中所有结点
    {
        q = p->next;
        delete p;
        p = q;
    }
    currentLength = 0;
}

template<class elemType>
void sLinkList<elemType>::insert(int i, const elemType &x)
{
    // node *tp = move(i-1);
    // node *p = new node(x,tp->next);
    // tp ->next = p;
    node * pos;

    pos = move(i-1);
    pos->next = new node(x, pos->next);
    ++currentLength;
}

template<class elemType>
void sLinkList<elemType>::remove(int i)
{
    // node * pos = move(i-1);
    // node * q = pos->next;
    // pos->next = q->next;
    // delete q;
    node *pos, *delp;

    if (i < 0)//
        return;//
    pos = move(i-1);
    if (!(pos || pos->next))//
        return;//
    delp = pos->next;
    pos->next = delp->next;
    delete delp;
    --currentLength;
}

template<class elemType>
int sLinkList<elemType>::search(const elemType &x) const
{
    node *p = head->next;
    int i = 0;
    
    while(p!= NULL && p->data != x) 
    {
        p = p->next;
        i++;
    }
    if (p == NULL)
        return -1;
    else
        return i;
}

template<class elemType>
elemType sLinkList<elemType>::visit(int i) const
{
    node *p;
    if ((p = move(i))!= NULL)
        return p->data;
}

template<class elemType>
void sLinkList<elemType>::traverse() const
{
    node *p = head->next;
    std::cout << std::endl;
    while(p != NULL)
    {
        std::cout << p->data << " ";
        p = p-> next;
    }
    std::cout << std::endl;
}

template<class elemType>
void sLinkList<elemType>::reverse()
{
    node * p[currentLength] = {head->next,};
    for (int i = 1; i < currentLength; i++)
        p[i] = p[i-1]->next;
    
    head->next = p[currentLength-1];
    for (int i = 0; i < currentLength-1; i++)
        p[currentLength-1-i]->next = p[currentLength-2-i];
    p[0]->next = nullptr;
        //head->next = plength-1
        // p[length-1]->next = p[length-2]
}
//逐个保存到node（data貌似就可以）1234567，然后再遍历一遍逐个把data赋值回去
// 可以只改变指向吗？
// 也以类似方式取出再赋值回去