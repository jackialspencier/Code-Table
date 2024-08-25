# 9.3 散列表
（二叉查找树查找元素需要一系列的比较）
储存和查找方法：将关键字值直接映射到表中某个位置，将该关键字对应的数据元素储存在这个位置
               查找时，根据被查找的关键字值找到储存该数据元素的地址，从而获得数据元素
--理想查找时间O(1)

## 9.6.1 散列表的定义
实现散列表的基本问题：**设计散列函数**&**解决碰撞**
### 1.散列函数
评判标准：计算速度快，地址均匀冲突机会少
#### （1）直接地址法
方法：取关键字值或关键字值的某个线性函数的值作为散列地址
特点：要数据分布较为均匀，不常用
#### （2）除留余数法
方法：H(key) = key MOD p 或 H(key) = key MOD p+c
特点：p一般选取小于等于m的素数——较为均匀，碰撞较少
     最常用，余数总在0-p-1之间
#### （3）数字分析法
方法：对关键字集合中的所有关键字，分析每一位数字分布，取数字分布均匀的位置作为地址的组成部分
特点：适用于关键字之间的区别集中在某些位上面
#### （4）平方取中法
方法：关键字中各位分布较均匀，但关键字值域比数组规模大，可以将关键字平方后，取其结果的中间各位作为散列函数值值
    （由于中间各位和每一位数字都有关系，因此均匀分布可能性较大）
    中间部分取几位依赖于散列表单元总数
#### （5）折叠法
方法：选取一个长度后，将关键字按此长度分组相加（抛弃进位）
特点：关键字相当长，比散列表单元总数大得多
<br>

散列函数选择的考虑因素：
- 计算散列函数所需时间
- 关键字长度
- 散列表长度（散列表地址**范围**）
- 关键字分布情况
- 记录查找频率

总的来说要选择一个尽可能使冲突产生可能性小的hash函数。
<br>

### 2.碰撞的解决
冲突不可避免，通常有以下两种方法：
法一：将溢出数据元素存放到散列表中**没有使用过的单元**。
- 特点：封闭式，不再使用额外储存单元——**闭散列表**
- 具体方案：线性探测法，二次探测法，再散列法

法二：将映射到同一地址的数据元素组织成一个线性表
- 特点： 空间开放式，**开散列表/拉链法**
- 具体方案由于地址相同的数据元素个数变化很大，通常采用链表
  散列表本身仅保存一只想各自链表的第一个结点指针
   

<br>
problem：新插入的元素被散列到一个已经被占据的位置，那么该把它放在那里？

## 9.6.2 线性探测法
**insert**：
思路：从散列到的位置开始顺序搜索，直到发现一个空位置
- 关于找到空单元的时间：
  可能很长：仅剩一个空单元，搜索整个数组找它。
  平均搜索半个数组，已经离期望每个访问固定时间的期望很远。
  可能不远：数组相当空，插入代价就没那么高

**find**:
思路：与insert走几乎相同的途径。
- 途径终点：
  逐个向后检查，找到对应值
  逐个向后，找到null——没找到
- 迟删除：
  （散列表的每个单元既表示自己，也作为解决碰撞时联系其他元素的占位符。）
  标记已删除而不是物理删除——单元中**增加一个字段，表示该单元活动/删除的**（正常储存/活动/删除）

代码清单 9-23 基于线性探测法的闭散列表的实现（除留余数法散列函数）
``` cpp
template <class KEY, class OTHER>
class closeHashTable: public dynamicSearchTable<KEY, OTHER>{
    private:
        struct node{
            SET <KEY, OTHER> data;
            int state; //0 -- empty  1 -- active  2 -- deleted

            node() {state = 0;}
        }
    
        node * array;
        int size;
        int (*key)(const KEY &x);//函数指针。
        static int defaultKey(const int &x) {return x;}
    
    public:
        closeHashTable(int length = 101, int(*f)(const KEY &x) = defaultKey);
        ~closeHashTable();
        SET<KEY, OTHER> *find(const KEY &x) const;
        void insert(const SET<KEY, OTHER> &x);
        void remove(const KEY &x)
};

template <class KEY, class OTHER>
closeHashTable<KEY, OTHER>::closeHashTAble(int length, int(*f)(const KEY &x))
{
  size = length;
  array = new node[size];
  key = f;
}

template<class KEY, class OTHER>
void closeHashTable<KEY, OTHER>::insert(const SET<KEY, OTHER> &x)
{
  int initPos, pos;

  initPos = pos = key(x.key) % size;
  do{
    if (array[pos].state != 1){ // 找到空单元
      array[pos].data = x;
      array[pos].state = 1;
      return;
    }
    pos = (pos + 1) % size;
  } while (pos != initPos);
}

template <class KEY, class OTHER>
void closeHashTable<KEY, OTHER>::remove(const KEY & x)
{
  int initPos, pos;
  
  initPos = pos = key(x) % size;
  do {
    if (array[pos].state == 0) return;
    if (array[pos].state == 1 && array[pos].data.key == x){ // 找到，删除   //为什么需要检查为1？可能2，已删除
        array[pos].state = 2;
        return;
    }
    pos = (pos + 1) % size;
  }while(pos != initPos);
}

template<class KEY, class OTHER>
SET<KEY, OTHER> *closeHashTAble<KEY, OTHER>::find(const KEY &x) const
{
  int initPos, pos;

  initPos = pos = key(x) % size;
  do{
    if(state == 0)
      return nullptr;//注意nullptr
    if(state == 1 && array[pos].data.key == x)
      return array[pos].data;
    pos = (pos + 1) % size;
  } while(pos != initPos);
}
```

