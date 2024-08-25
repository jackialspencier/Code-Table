# 第九章 动态查找表

____________________________

静态查找表不可变，动态查找表不仅支持查找，还支持增删
其抽象类为
```cpp
template<class KEY, class OTHER>  
class dynamicSearchTable{
    public:
        virtual SET<KEY, OTHER> *find(const KEY &x) const = 0;
        virtual void insert(const SET<KEY, OTHER> &x) = 0;
        virtual void remove(const KEY &x) = 0;
        virtual ~dynamicSearchTable() {};
}
```

由于增删操作，顺序储存不合适（大规模数据移动）
两种动态查找表实现：
用于处理动态查找表的树——查找树
专用于集合查找的数据结构——散列表

-—-本章介绍几种常见查找树：二叉查找树、平衡树(及其变异)---
## 9.1二叉查找树（二叉排序树）

### 9.1.1二叉查找树的定义
**定义**：空树或满足以下条件的树：
（1）非空左子树键值都小于根结点
（2）非空右子树键值都大于根结点
（3）左右子树也是二叉查找树

### 9.1.2 二叉查找树的储存实现
常插入删除——**二叉树的标准储存法**储存
储存结点的类：被定义为私有的内嵌类
唯一的数据成员：储存二叉树只需要一个**指向根节点的指针**
操作：定义递归定义，故操作递归实现——包裹函数，公有函数与带有递归参数的私有成员函数
.... (例如，其中析构删除节点，递归实现，需要私有函数makeEmpty)

代码清单9-2 二叉查找树类的定义：
```cpp
template<class KEY, class OTHER>
class BinarySearchTree:public dynamicSearchTable<KEY, OTHER>
{
    private:
        struct BinaryNode
        {
            SET<KEY, OTHER> data;
            BinaryNode * left;
            BinaryNode * right;

            BinaryNode(const SET<KEY, OTHER> & thedata, BinaryNode *lt=nullptr,
                 BinaryNode *rt=nullptr)
                 : data( thedata ), left( lt ), right( rt ) {}
        }
        BinaryNode *root;//用于储存整个树的指向根结点的指针

    public:
        BinarySearchTree();
        ~BinarySearchTree();
        SET<KEY, OTHER> *find(const KEY &x) const;
        void insert( const SET<KEY, OTHER> &x);
        void remove( const KEY & x );

    private:
        void insert( const SET<KEY, OTHER>& x, BinaryNode * t );
        void remove( const KEY & x, BInaryNode * t);
        SET(KEY, OTHER)* find(const KEY &x, BinaryNode * t) const;
        void makeEmpty(BInaryNode * t);
}
```

### 9.1.3 二叉查找树的运算实现
**查找**
____
二叉查找树的递归查找过程：
（1）根结点**不存在**，待查找元素不存在
（2）根结点关键字值**等于**查找的关键字，查找成功
（3）根结点关键字值**大于**待查找的关键字值，到**左子树**查找
（4）根结点关键字值**小于**待查找的关键字值，到**右子树**查找

由于查找递归实现，公有的find函数调用私有的find函数

代码清单9-3：find函数的实现
``` cpp
template<class KEY, class OTHER>
SET<KEY, OTHER> *find(const KEY &x) const
{
    return find(x, root);
}

template<class KEY, class OTHER>
SET<KEY, OTHER> *find(const KEY &x, BinaryNode *t) const
{
    if( t == NULL || t->data.key == x ) // 找到或不存在
        return (SET<KEY, OTHER>*) t;
    if( x < t->data.key )
        return find( x, t->left );  // 继续查找左子树
    else
        return find( x, t->right ); // 继续查找右子树
}
```
<br>

**插入**
______
（插入原则是仍为二叉查找树，且仅当不存在键值为x的结点时才插入）
（由于2，包含查找过程，未找到时恰好找到需插入的位置）
二叉树插入的递归过程：
（1）根节点不存在，插入为根结点
（2）根节点关键字值大于插入元素关键字值，在左子树上插入
（3）根结点关键字值小于插入元素关键字值，在右子树上插入

注意：私有insert函数第二个形参是一个指向结点的指针的引用，引用符号不可省略？

代码清单9-4：插入函数的实现
``` cpp
template<class KEY, class OTHER>
void BinaryTree<KEY, OTHER>::insert(const SET<KEY, OTHER> &x)
{
    insert(x, root);
}

template<class KEY, class OTHER>
void BinarySearchTree<KEY, OTHER>::insert( const SET<KEY, OTHER> &x, BinaryNode * &t)
{
    if (t == nullptr)
        t = new BinaryNode(x, nullptr, nullptr); // 正是第二个参数的&将新插入的结点和父结点关联了起来。
    else if(x.key < t->data.key) //t是根结点指针，x是待插入元素
        insert( x, t->left );
    else if(x.key > t->data.key)
        insert( x, t->right );
    else cout << x.key << "is exist" << endl;
}
```
<br>

**删除**（二叉查找树最复杂的操作）
____
要求：删除元素后——重新连接、满足二叉查找树性质、不希望深度加深（concerning算法运行时间）
删除叶节点：直接删除
删除只有一个儿子的结点：父结点连接被删结点-->父结点连到被删结点的儿子
删除有两个儿子的结点：找到替身（左树max，右树min）替代，转化为替身(仅一个儿子/叶结点)的删除

总结：二叉树删除过程：
（1）被删结点值小于根结点：左子树上删除该结点
（2）被删结点值大于根结点，去右子树上删除该结点
（3）删除根结点。-叶节点直接删除-单子根结点替代-双子叶节点，取左数最大/右树最小为替身，变为删除替身

代码清单9-5 remove函数的实现
``` cpp
template<class KEY, class OTHER>
void BinarySearchTree<KEY, OTHER>::remove(const KEY & x)
{
    remove(x, root);
}

template<class KEY, class OTHER>
void BinarySearchTree<KEY, OTHER>::remove(const KEY & x, BinaryNode * & t)
{
    if (t == nullptr)
        return;
    if (x < t->data.key )
        reomve(x, t->left );
    else if (x > t->data.key)
        remove(x, t->right );
    else if (t->left != nullptr && t->right != nullptr)//到这句已有相等。有两个孩子
    {
        BinaryNode * tmp = t->right;
        while(tmp->left != nullptr)
            tmp = tmp->left;// 找到右子树的最小值（最左）
        t->data = tmp->data;
        remove(t->data.key, t->right);//t的已经改了不是吗，对，现在要删的就是替身本身
    }
    else// 被删结点是叶节点或只有一个孩子
    {
        BinaryNode * oldNode = t;
        t = (t->left != nullptr) ? t->left : t->right;
        // if(t->left != nullptr) 
        //     t = t->left;
        // else
        //     t = t->right;
        delete oldNode;
    }
}
```
<br>

**构造，析构（及makeEmpty函数）**
___