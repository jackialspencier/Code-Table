# 第13章

# 13.1 图的定义
图=顶点集V+边集E，通常被表示为一个二元组（V，E）
有向图的边/弧<>,无向图/双向图的边()
边的加权——加权有/无向图

## 13.1.1 图的基本术语
- 邻接
- 度 = 入度 + 出度
- 边=1/2度
- 子图
- 路径和路径长度
- 无向图的连通性：连通、连通图、连通分量
- 有向图的连通性：强连通图、强连通分量、弱连通图
- 完全图n(n-1)/2,Cn2、有向完全图n(n-1)，有向无环图
- 生成树与最小生成树（MST）

## 13.1.2 图的运算
常规：构造，判断边存在、添加/删除边、返回顶点数/边数，遍历顶点
与应用相关：拓扑排序和关键路径、最小生成树、最短路径等。

代码清单13-1 图的抽象类
``` cpp
template <class TypeOfVer, class TypeOfEdge>
class gragh{
    public:
        virtual void insert(TypeOfVer x, TypeOfVer y, TypeOfEdge w) = 0;
        virtual void remove(TypeOfVer x, TypeOfVer y) = 0;
        virtual bool exist(TypeOfVer x, TypeOfVer y) = 0;
        int numOfVer() const { return Vers; }
        int numOfEdge() const { return Edges; }

    protetcted:
        int Vers, Edges;
}
```

# 13.2 图的存储
两种方式：邻接矩阵和邻接图

## 13.2.1 邻接矩阵表示法
- 存储顶点：一个顶点值类型的数组
- 存储边：nxn的布尔矩阵
1. 有向图
   (1) 入度 = 本行之和
   (2) 出度 = 本列之和
2. 无向图
   (1)三角对称矩阵
   (2)顶点i的度 = i行之和/i列之和
3. 加权图
   布尔矩阵 -> 整型/实型矩阵，空/∞，对角线0
4. 邻接矩阵的特点
   - 优点：增加、删除、判断边的存在O(1)，适合(有向)稠密网
   - 缺点：即使<< n2，仍需n2单元：浪费空间，读入数据O(n2)，尤其实际多稀疏网
           不适合增删结点
5. 具体实现
代码清单13-2 基于邻接矩阵的图类定义
``` cpp
template <class TypeOfVer, class TypeOfEdge>
class adjMatrixGrapph: public graph<TypeOfVer, TypeOfEdge>
{
    public:
        adjMatrixGragh(int vSize, const TypeOfVer d[], const TypeOfEdge noEdgeFlag);
        void insert(TypeOfVer x, TypeOfVer y, TypeOfEdge w);    // 插入一条边
        void remove(TypeOfVer x, TypeOfVer y);                  // 删除一条边
        bool exist(TypeOfVer x, TypeOfVer y) const;             // 判断一条边是否存在
        ~adjMatrixGragh();
    private:
        TypeOfEdge ** edge; // 存放邻接矩阵
        TypeOfVer *ver; // 存放结点值
        TypeOfEdge noEdge; // 邻接矩阵中的∞的表示值
        int find(TypeOfVer v) const
        {
            for (int i = 0; i < Vers; i++)
                if (ver[i] == v) return i;
        }
}
```

代码清单13-3 adjMatrixGragh类的构造函数
``` cpp
template<class TypeOfVer, class TypeOfEdge>

adjMatrixGragh<TypeOfVer, TypeOfEdge>::adjMatrixGragh(int vSize, const TypeOfVer d[], const TypeOfEdge noFlagEdge)
{
    int i, j;

    // 先设置结点数、边数、无边标记三个数据成员的值
    Vers = vSize;
    Edges = 0;
    noEdge = noEdgeFlag;

    // 存放结点的数组的初始化
    ver = new TypeOfVer[vSize];
    for (i = 0; i < vSize; i++)
        ver[i] = d[i];

    // 邻接矩阵的初始化
    edge = new TypeOfEdge*[vSize];
    for (i = 0; i < n; i++){
        edge[i] = new TypeOfEdge[vSize];
        for (j = 0; j < vSize; j++)
            edge[i][j] = noEdge;
        edge[i][i] = 0;     // 个别再后调整
    }
}
```

代码清单13-4 adjMatrixGragh类的析构函数
``` cpp
template<class TypeOfVer, class TypeOfEdge>
adjMatrixGraph<TypeOfVer, TypeOfEdge>::~adjMatricGraph()
{
    delete [] ver;
    for (int i = 0; i < Vers; i++)  // 释放邻接矩阵每一行
        delete [] edge[i];  
    delete [] edge;
}
```

代码清单13-5 adjMatrixGraph类其他成员函数的实现
``` cpp
template<class TypeOfVer, class TypeOfEdge>
adjMatrixGraph<TypeOfVer, TyprOfEdge>::insert(TyprOfVer x, TypeOfVer y, TypeOfEdge w)
{
    int u = find(x), v = find(y);
    edge[u][v] = w;
    ++Edges;    // 别忘了更新边数
}

template<class TypeOfVer, class TypeOfEdge>
adjMatrixGraph<TyprOfVer, TypeOfEdge>::remove(TypeOfVer x, TypeOfVer y)
{
    int u = find(x), v = find(y);
    edge[u][v] = noEdge;
    --Edges;
}

template<class TypeOfVer, class TypeOfEdge>
adjMatrixGraph<TypeOfVer, TypeOfEdge>::exist(TypeOfVer x, TypeOfVer y)
{
    int u = find(x), v = find(y);
    // return(edge[u][v] != noEdge);
    if (edge[u][v] == noEdge) return false;
    else return true; 
}
```

这个类的使用
``` cpp
    adjMatrixGraph<char, int> g(10, 'abcdefghij', -1);  // 定义一个这个类的对象
    g.insert('a', 'f', 9);    //添加一条从a出发到f，权值9的边
    g.remove('a', 'f');         // 删除这条边
```

## 13.2.2 邻接表表示法

# 13.3 图的遍历

# 13.4 图的应用
































# 第一张
多出选择题，如计算时间复杂度
单链表注意找到位置指针部分的On
吧h
# 第二章 线性表
blabla判断优缺点选用，注意每种操作时间复杂度，和空间上的优势差异
顺序表也有优势，别忘了
常用：在最后一个元素前插入一个元素and删除最后一个元素：顺序表（顺序表一个重要问题搬移这里不涉及）
常用：查找到某个元素后删除：单链表
注意顺序表的删除需要搬移
某个操作的实现效率那个高

程序填空题（常考对于链表、指针的操作）

# 第三章 栈
栈的基本操作：入栈、出栈
站的表达式，常在程序填空（？）11.19/5/30

后缀表达式
符号栈
何时可以出栈：后面的优先级比前面的低，遇到括号，括号前的都可以出栈了
运算数栈/操作数栈

密码
倒着——栈——先进后出

# 第四章 队列
选择题、程序填空题
1. 队列的基本操作：入队出队
2. 循环队列：选择题
3. 队列的应用：程序填空、程序设计（树。。。。。。？11：30/5/30）

头尾指针区分空和满
链表里面的循环的队列，方向选择
若循环单链表表示队列，方向怎么取。唯一一个指针如何放放哪里时入队出队方便
表头——队头，表尾——队尾，指针放在队尾

# 第六章 树
二叉树、哈夫曼树、普通树和森林
结点数目和高度关系，父子序号关系，分叉数目和结点的关系，n0和n2，遍历：考察方式：已知两种推第三种
遍历的应用（找所有祖先，子孙，兄弟，程序设计/填空）
二叉树：
性质：选择题
四种遍历（递归、非递归实现）
遍历的应用：程序设计、程序填空

树和森林变换等
度和结点的关系，高度和结点的关系

遍历的推导，由已知遍历推未知遍历
二叉查找树中序遍历有序
中序+任意都可，其他不行重构出唯一一个二叉树

哈夫曼树与哈夫曼编码（一般不会出编码题）
概念与性质（选择）
构造、编码（选择、简答）——给出权值序列构建哈夫曼树，表格

树与森林（多为选择）
遍历（前序遍历和后续遍历，没有中序遍历）（与转换后：前序——前序，后序——中序）
孩子兄弟连存储（已知孩子兄弟连的二叉树表示，转回原数，求前序、后序、层次遍历）
与二叉树的转换
（树的前序和后序，也就是二叉树的前序和中序，可以唯一确定）



# 第七章 优先级队列
二叉堆
堆的定义，建堆，堆的操作，复杂度
（最大堆，最小堆）（插入后的堆）（关键字最大最小的可能在哪里）——选择题
简答题：已知序列，用buildheap（时间性能最好）建堆
建堆的诸葛插入、递归一般不会考...

# 第八章 集合与静态查找表

# 第九章 动态查找表
二叉查找树：概念（中序遍历有序），插入，查找，删除，时间复杂度
AVL树：概念，查找，插入，删除，复杂度（四种重构算法）
散列表：概念，闭散列表（迟删除），开散列表（可以直接删除），查找，插入，删除

# 第十章 排序
插入排序
选择排序（直接选择排序，堆排序，注意建堆！！！）
（堆排序必考，出现大题可能比较大）（写出表格？）
交换排序
归并排序（不是两两，看代码，分两段mid，mid+1）
基数排序（一定是低位优先）
过程、性能、设计和选择算法（看情况）
时间复杂度，比较次数，搬移次数，最好时间复杂度对应情况，最坏时间复杂度随影情况，平均，空间复杂度
由序列变化反推使用的方法
第k小，选择类排序，堆排序

若原始（接近）逆序，本就是最大堆，适合建堆故堆排序

# 第十一章 外部排序和查找
一般不会出现在程序设计和填空，书上本就没有对应代码
外部查找
B树，B+树
定义，查找，插入，删除
外排序
模型，k路合并，置换选择

B树和B+树，置换选择常考简答题！
含n个非叶节点的m阶B树至少包含多少关键字，至多包含多少关键字？
扣定义

# 第十三章 图
