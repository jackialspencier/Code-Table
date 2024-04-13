#include <iostream>
using namespace std;
template <class T>
class binaryTree: public bTree<T>{
    friend void printTree(const binaryTree &t, T flag);
private:
    struct Node{            // 二叉树的结点类
        Node *left, *right; // 结点的左右儿子的地址
        T data;             // 结点的数据信息

        Node(): left(NULL), right(NULL) {}
        Node(T item, Node *L = NULL, Node *R = NULL):data(item), left(L), right(R) {}
        ~Node() {}
    };

    Node *root;// 二叉树的根结点
public:
    binaryTree(): root(NULL) {}
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
    void createTree(T flag);// 创建树
    T parent(const T &x, T flag) const {return flag;}
private:
    Node *find(const T &x, Node *t) const;//参数node *是何用意？
    void clear(Node *&t);
    void preOrder(Node *t) const;
    void midOrder(Node *t) const;
    void postOrder(Node *t) const;
};
