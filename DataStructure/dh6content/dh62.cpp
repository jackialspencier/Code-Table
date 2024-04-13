#include <iostream>
#include "dh43.h"
using namespace std;
// 6.2 二叉树
// 6.2.1 二叉树的定义
// 根节点+两颗不相交的左、右子树（也都是二叉树）
// 有序树，严格区分，即使只有一个子树(交换得到的是另一棵二叉树)
// 满二叉树/丰满树(任意一层结点都达到最大值)
// 完全二叉树(满二叉树最底层自右往左一次去掉若干结点(不能跳过))

// 6.2.2 二叉树的常用性质
// 四个性质+PPT单独一个
// 1.一棵非空二叉树第i层最多2^(i-1)个结点
// 2.一棵高度为k的二叉树，最多有2^k - 1个结点。
// 3.对于一棵非空二叉树，叶子结点数n0，度为2的结点数n2，则有n0=n2+1成立。
// 4.具有n个结点的完全二叉树高度k=[log2n]+1
// 5.完全二叉树自上往下每一层自左往右依次编号，根节点编号1，第i个结点的左子2i，右子2i+1
//   （非完全二叉树不具备这个编号特性）

// 6.2.3 二叉树的基本运算
// PART遍历
// 1.前序遍历
// 先根遍历：根结点，左子树、右子树之间先访问根节点。
// 前序遍历递归定义：若二叉树为空，则操作为空，否则：
// (1)访问根节点
// (2)前序遍历左子树
// (3)后序遍历右子树

// 2.中序遍历
// 中根遍历：根结点，左子树，右子树之间，根结点放在左右子树中间访问
// 中序遍历递归定义：若二叉树为空，则操作为空。否则；
// (1)中序遍历左子树
// (2)根节点
// (3)中序遍历右子树
// 投影序

// 3.后序遍历
// 后根遍历：根结点、左子树、右子树之间，根节点是最后被访问的。
// 后序遍历的递归定义：若二叉树为空，则操作为空。否则：
// (1)后序遍历左子树
// (2)后序遍历右子树
// (3)访问根结点

// 4.层次遍历
// 先访问根结点，从左到右的次序访问第二层节点。
// 访问第k层所有结点后，按从左到右次序访问第k+1层。

// 根据前序+中序，后序+中序，层次+中序，确定二叉树
// 代码清单6-2 二叉树的抽象类
template <class T>
class bTree
{
public:
    virtual void clear() = 0;
    virtual bool isEmpty() const = 0;
    virtual T Root(T flag) const = 0;
    virtual T parent(const T &x, T flag) const = 0;
    virtual T lchild(const T &x, T flag) const = 0;
    virtual T rchild(const T &x, T flag) const = 0;
    virtual void delLeft(const T &x) = 0;
    virtual void delRight(const T &x) = 0;
    virtual void preOrder() const = 0;
    virtual void midOrder() const = 0;
    virtual void postOrder() const = 0;
    virtual void levelOrder() const = 0;
};

// 6.2.4 二叉树的顺序实现
// 完全二叉树的顺序储存
// 按层编号——编号反应父子关系：
// k结点的左儿子2k，右儿子2k+1，父结点[k/2]
// 非完全二叉树的顺序存储（基于完全二叉树的存储方式）
// 残缺位置增设需节点(特殊值表示)使之变成完全二叉树
// 储存空间浪费
// 应用：
// 特殊场合如节点个数已知、不会增删结点的完全二叉树或接近完全二叉树的二叉树

// 6.2.5 二叉树的链接实现
// 链接储存：用指针指出父子关系
// 只指出儿子——标准储存结构，指出儿子还指出父结点——广义的标准储存结构
// 1.标准储存结构
// 二叉链表：两条链，指向左右儿子
// 结点构成：储存数据元素值+指向左儿子指针字段+指向右儿子指针字段
// 属性：只需要一个指向根节点的指针root——根指针
// （难以找父结点）
// 2.广义的标准储存结构（若需找父亲）
// 增加一个指向父结点的指针——三叉链表（每个结点三条链）

// 6.2.6 二叉链表类
// 1.二叉链表类的定义：     2
// 代码清单6-3 二叉链表类的定义
template <class T>
class binaryTree;
template <class T>
void printTree<T>(const binaryTree<T> &t, T flag);
template <class T>
class binaryTree : public bTree<T>
{
    template <class T>
    friend void printTree<T>(const binaryTree<T> &t, T flag);

private:
    struct Node
    {                       // 二叉树的结点类
        Node *left, *right; // 结点的左右儿子的地址
        T data;             // 结点的数据信息

        Node() : left(nullptr), right(nullptr) {}
        Node(T item, Node *L = nullptr, Node *R = nullptr) : data(item), left(L), right(R) {}
        ~Node() {}
    };

    Node *root; // 二叉树的根结点
public:
    binaryTree() : root(nullptr) {}
    binaryTree(T x) { root = new Node(x); }
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
    void createTree(T flag); // 创建树
    T parent(const T &x, T flag) const { return flag; }

private:
    Node *find(const T &x, Node *t) const; // 参数node *是何用意？
    void clear(Node *&t);
    void preOrder(Node *t) const; // 此处加引用&会报错，因为后面有const，加&有改变数据的可能
    void midOrder(Node *t) const;
    void postOrder(Node *t) const;
};

// 2.二叉链表类的运算实现   8
//
template <class T>
bool binaryTree<T>::isEmpty() const
{
    return root == nullptr;
}

template <class T>
T binaryTree<T>::Root(T flag) const
{
    if (root = nullptr)
        return flag;
    else
        return root->data;
}

template <class T>
void binaryTree<T>::clear(binaryTree<T>::Node *&t)
{
    if (t == nullptr)
        return;
    clear(t->left);
    clear(t->right);
    delete t;
    t = nullptr;
}

template <class T>
void binaryTree<T>::clear()
{
    clear(root);
}

template <class T>
binaryTree<T>::~binaryTree()
{
    clear(root); // 不需要设置nullptr，因为clear内部设置了。如果其内部没有设置，需要设置吗？
}

// 代码清单6-5 二叉链表中遍历函数的实现
template <class T>
void binaryTree<T>::preOrder(binaryTree<T>::Node *t) const
{
    if (t == nullptr)
        return;
    cout << t->data << ' ';
    preOrder(t->left);
    preOrder(t->right);
}

// 3.25课堂练习
// size()
//
// int binaryTree<T>::size(binaryTree<T>::Node *t) const
// {
//      if (t == nullptr) return 0;
//      int a = 1;
//      a += size(t->left);
//      a += size(t->right);
//      return a;
// }
//
// ans:
// template<class T>
// int binaryTree<T>::
template <class T>
void binaryTree<T>::preOrder() const
{
    cout << "\n 前序遍历:";
    preOrder(root);
}

template <class T>
void binaryTree<T>::postOrder(binaryTree<T>::Node *t) const
{
    if (t == nullptr)
        return;
    postOrder(t->left);
    postOrder(t->right);
    cout << t->data << ' ';
}

template <class T>
void binaryTree<T>::postOrder() const
{
    cout << "\n 后序遍历:";
    postOrder(root);
}

template <class T>
void binaryTree<T>::midOrder(binaryTree<T>::Node *t) const
{
    if (t == nullptr)
        return;
    midOrder(t->left);
    cout << t->data << ' ';
    midOrder(t->right);
}

template <class T>
// void binaryTree<class T>
void binaryTree<T>::midOrder() const
{
    cout << "\n 中序遍历:";
    midOrder(root);
}

template <class T>
void binaryTree<T>::levelOrder() const
{
    linkQueue<Node *> que;
    Node *tmp;

    cout << "\n 层次遍历:";
    que.enQueue(root);

    while (!que.isEmty())
    { // 循环直到队列为空
        tmp = que.deQueue();
        cout << tmp->data << ' ';
        if (tmp->left)
            que.enQueue(tmp->left);
        if (tmp->right)
            que.enQueue(tmp->right);
    }
}

// 代码清单6-6 二叉链表中find\lchild\rchild\delLeft\delRight函数的实现
template <class T>
binaryTree<T>::Node *binaryTree<T>::find(const T &x, binaryTree<T>::Node *t) const
{
    Node *tmp;
    if (t == nullptr)
        return nullptr;
    if (t->data == x)
        return t;
    if (tmp = find(x, t->left))
        return tmp;
    else
        return find(x, t->right);
}

template <class T>
void binaryTree<T>::delLeft(const T &x)
{
    Node *tmp = find(x, root);
    if (tmp == nullptr)
        return;
    clear(tmp->left);
}

template <class T>
void binaryTree<T>::delRight(const T &x)
{
    Node *tmp = find(x, root);
    if (tmp == nullptr)
        return;
    clear(tmp->right);
}

template <class T>
T binaryTree<T>::lchild(const T &x, T flag) const
{
    Node *tmp = find(x, root);
    if (tmp == nullptr || tmp->left = nullptr)
        return flag;
    return tmp->left->data; //   别忘了要return的是data
}

template <class T>
T binaryTree<T>::rchild(const T &x, T flag) const
{
    Node *tmp = find(x, root);
    if (tmp == nullptr || tmp->right == nullptr)
        return flag;

    return tmp->right->data;
}
// 代码清单6-7
// 二叉链表中createTree函数的实现
template <class T>
void binaryTree<T>::createTree(T flag)
{
    linkQueue<Node *> que;
    Node *tmp;
    T x, ldata, rdata;

    // 创建树，输入flag表示空
    cout << "\n 输入根结点:";
    cin >> x;
    root = new Node(x);
    que.enQueue(root);

    while (!que.isEmpty())
    {
        tmp = que.deQueue();
        cout << "\n输入" << tmp->data << " 的两个儿子(" << flag << "表示空结点):";
        cin >> ldata >> rdata;
        if (ldata != flag)
            que.enQueue(tmp->left = new Node(ldata));
        if (rdata != flag)
            que.enQueue(tmp->right = new Node(rdata));
    }

    cout << "create completed!\n";
}
// 3。二叉链表类的简单示例  1
// 4.二叉树遍历的非递归实现 4
// 代码清单6-8 二叉树输出函数
template <class T>
void printTree(const binaryTree<T> &t, T flag)
{
    linkQueue<T> q;
    q.enQueue(t.root->data); // 不要输出的吗//en
    cout << endl;

    // Node * tmp;
    while (!q.isEmpty())
    {
        // tmp = q.deQueue();
        // cout << tmp->data;
        // if (tmp->left) q.enQueue(tmp->left);
        // if (tmp->right) q.enQueue(tmp->right);
        char p, l, r;
        p = q.deQueue();
        l = t.lchild(p, flag);
        r = t.rchild(p, flag);

        cout << p << " " << l << " " << r << endl;

        if (l != '@')
            q.enQueue(l);
        if (r != '@')
            q.enQueue(r);
    }
}

int main()

{
    binaryTree<char> tree;

    tree.createTree('@');

    tree.preOrder();

    tree.midOrder();

    tree.postOrder();

    tree.levelOrder();

    printTree(tree, '@');

    tree.delLeft('L');

    tree.delLeft('C');

    tree.delRight('C');

    //  tree.exchange();

    printTree(tree, '@');

    return 0;
}
