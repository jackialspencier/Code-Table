#include <iostream>
using namespace std;
#include "linkQueue.h"
#include "bTree.h"

template <class T> class binaryTree;
template <class T> void printTree(const binaryTree<T> &t, T flag);
template<class T>
class binaryTree: public bTree<T>{
    // template <class T>
    friend void printTree<T>(const binaryTree<T> &t, T flag);
private:
    struct Node{
        Node *left, *right;
        T data;             

        Node(): left(nullptr), right(nullptr) {}
        Node(T item, Node *L = nullptr, Node *R = nullptr):data(item), left(L), right(R) {}
        ~Node() {}
    };

    Node *root;
public:
    binaryTree(): root(nullptr) {}
    binaryTree(T x) {root = new Node(x);}
    ~binaryTree();
    void clear();
    bool isEmpty() const;
    T Root(T flag) const;
    T lchild(const T &x, T flag) const;
    T rchild(const T &x, T flag) const;
    
    void delLeft(const T &x);
    void delRight(const T &x);
    void preOrder() const;
    void midOrder() const;
    void postOrder() const;
    void levelOrder() const;
    void createTree(T flag);
    T parent(const T &x, T flag) const {return flag;}

    void exchange();
private:
    Node *find(const T &x, Node *t) const;
    void clear(Node *&t);
    void preOrder(Node *t) const;
    void midOrder(Node *t) const;
    void postOrder(Node *t) const;

    
    void exchange(Node * t);
};


template <class T>
bool binaryTree<T>::isEmpty() const
{
    return root == nullptr;
}

template<class T>
T binaryTree<T>::Root(T flag) const
{
    if (root == nullptr) return flag;
    else return root->data;
}

template<class T>
void binaryTree<T>::clear(binaryTree<T>::Node *&t)
{
    if (t == nullptr) return;
    clear(t->left);
    clear(t->right);
    delete t;
    t = nullptr;
}

template<class T>
void binaryTree<T>::clear()
{
    clear(root);
}

template<class T>
binaryTree<T>::~binaryTree()
{
    clear(root);
}

template<class T>
void binaryTree<T>::preOrder(binaryTree<T>::Node *t) const
{
    if (t == nullptr) return;
    cout << t->data << ' ';
    preOrder(t->left);
    preOrder(t->right);
}


template<class T>
void binaryTree<T>::preOrder() const
{
    cout << "\n 前序遍历:";
    preOrder(root);
}

template<class T>
void binaryTree<T>::postOrder(binaryTree<T>::Node *t) const
{
    if (t == nullptr) return;
    postOrder(t->left);
    postOrder(t->right);
    cout << t->data << ' ';
} 

template<class T>
void binaryTree<T>::postOrder() const
{
    cout << "\n 后序遍历:";
    postOrder(root);
}

template<class T>
void binaryTree<T>::midOrder(binaryTree<T>:: Node *t) const
{
    if (t == nullptr)
        return;
    midOrder(t->left);
    cout << t->data << ' ';
    midOrder(t->right);
}

template<class T>
void binaryTree<T>::midOrder() const
{
    cout << "\n 中序遍历:";
    midOrder(root);
}

template<class T>
void binaryTree<T>::levelOrder() const
{
    linkQueue<Node *> que;
    Node * tmp;

    cout << "\n 层次遍历:";
    que.enQueue(root);

    while(!que.isEmpty()){//循环直到队列为空
        tmp = que.deQueue();
        cout << tmp->data << ' ';
        if (tmp->left) que.enQueue(tmp->left);
        if (tmp->right) que.enQueue(tmp->right);
    }
}

template<class T>
class binaryTree<T>::Node *binaryTree<T>::find(const T &x, binaryTree<T>::Node *t) const//前面class?
{
    Node * tmp;
    if (t == nullptr) return nullptr;
    if (t->data == x) return t;
    if (tmp = find(x, t->left)) return tmp;
    else return find(x, t->right);
}

template<class T>
void binaryTree<T>::delLeft(const T &x)
{
    Node *tmp = find(x, root);
    if(tmp == nullptr) return;
    clear(tmp->left);
}

template<class T>
void binaryTree<T>::delRight(const T &x)
{
    Node *tmp = find(x, root);
    if (tmp == nullptr) return;
    clear(tmp->right);
}

template<class T>
T binaryTree<T>::lchild(const T &x, T flag) const
{
    Node * tmp = find(x, root);
    if (tmp == nullptr || tmp->left == nullptr) return flag;
    return tmp->left->data;
}

template<class T>
T binaryTree<T>::rchild(const T &x, T flag) const
{
    Node * tmp = find(x, root);
    if (tmp == nullptr || tmp->right == nullptr) return flag;

    return tmp->right->data;
}

template<class T>
void binaryTree<T>::createTree(T flag)
{
    linkQueue< Node * > que;
    Node * tmp;
    T x, ldata, rdata;

    // 创建树，输入flag表示空
    cout << "\n 输入根结点:";
    cin >> x;
    root = new Node (x);
    que.enQueue(root);

    while(!que.isEmpty()){
        tmp = que.deQueue();
        cout << "\n输入" << tmp->data << " 的两个儿子("<< flag << "表示空结点):";
        cin >> ldata >> rdata;
        if (ldata != flag) que.enQueue(tmp->left = new Node(ldata));
        if (rdata != flag) que.enQueue(tmp->right = new Node(rdata));
    }

    cout << "create completed!\n";
}

template<class T>
void printTree(const binaryTree<T> &t, T flag)
{
    linkQueue<T> q;
    q.enQueue(t.root->data);
    cout << endl;

    // Node * tmp;
    while(!q.isEmpty()){
        char p, l, r;
        p = q.deQueue();
        l = t.lchild(p, flag);
        r = t.rchild(p, flag);

        cout << p << " " << l << " " << r << endl;

        if(l != '@') q.enQueue(l);
        if(r != '@') q.enQueue(r);
    }
}

template<class T>
void binaryTree<T>::exchange()
{
    cout << "\n 交换所有节点左右子树: ";
    exchange(root);
}

template<class T>
void binaryTree<T>::exchange(binaryTree<T>::Node * p)
{
    if (p == nullptr)
        return;
    exchange(p->left);
    exchange(p->right);
    Node * tmp = p->left;
    p->left = p->right;
    p->right = tmp;
}