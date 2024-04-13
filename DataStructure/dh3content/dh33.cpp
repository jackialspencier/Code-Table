template<class elemType>
class linkStack: public stack<elemType>
{
    private:
        struct node{
            elemType data;
            node * next;//是node类型指针，不是elemType类型的指针
            node(const elemType &x, node * N = NULL)
                { data = x, next = N; }
            node():next(NULL){}
            };
        node * top_p;
    public:
        linkStack();
        ~linkStack();
        bool isEmpty() const;
        void push(const elemType &x);
        elemType pop();
        elemType top() const;//记得const！！
};

// 链接储存时的运算实现
// 构造函数：将top_p设为空指针
template<class elemType>//别忘了这一行！
linkStack<elemType>::linkStack()
{
    top_p = NULL;
}

// try:
template<class elemType>
linkStack<elemType>::~linkStack()
{
    node * tmp;
    while(top != NULL){
        tmp = top_p->next;
        delete top_p;
        top_p = tmp;
    }
}
// 区别：用于指向待删元素的指针不同
template<class elemType>
linkStack<class elemType>::~linkStack()
{
    node * tmp;
    while(top_p != NULL){
        tmp = top;
        top = top->next;
        delete tmp;
    }
}
// 因为检查的top，所以在以tmp为待删元素时，tmp可以滞后
// 但以top为待删元素时，被删的下一个需要tmp，tmp不能滞后，又由于要检查top，top也不能滞后，需要二者同步

template<class elemType>
void linkStack<elemType>::push(const elemType &x)
{
    top_p = new node(x, top_p);
}

template<class elemType>
elemType linkStack<elemType>::pop()
{
    node * tmp = top_p;
    top_p = top_p->next;
    elemType x = tmp -> data;
    delete tmp;
    return x;
}

template<class elemType>
elemType linkStack<elemType>::top() const
{
    return top_p -> data;
}

template<class elemType>
bool linkStack<elemType>::isEmpty() const
{
    return top_p == NULL;
}