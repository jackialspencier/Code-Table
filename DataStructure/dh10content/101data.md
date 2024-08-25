# 第十章 排序
## 10.1 排序的基本概念
- 排序：把集合中的数据元素按照他们的关键字的非递减或非递增排成一个序列
- 稳定排序与非稳定排序：
  - 关键字值相同的数据元素再排序前后的相对次序不变-稳定排序。
  - 否则非稳定排序。
- 内排序与外排序：
  - 内排序：被排序数据存放在内存中，在内存中调整数据元素相对位置
  - 外排序：排序过程中，数据主要存在外储存器，借助于内储存器逐步调整数据元素之间相对位置。

- 排序算法的衡量标准
  - 时间复杂度：**比较**次数 + **搬移**次数 
  - 空间复杂度
  - 稳定性：相同值的元素在排序前后位置先后关系不变
## 10.2 插入排序
基本方法：每次将一个待排序数据按其关键字大小插入前面已排好序的一组数据元素的适当位置上。
常见的插入排序：**直接插入排序、折半插入排序、希尔排序**
### 10.2.1 直接插入排序
代码清单10-1 直接插入排序的实现
``` cpp
template<class KEY, class OTHER>
void simpleInsertSort(SET<KEY, OTHER> a[], int size)
{
  int k;
  SET<KEY, OTHER> tmp;

  for (int j = 1; j < size; j++){ // 循环1：n-1次技术循环，插入新元素到0-j-1中。
    tmp = a[j];
    for (k = j - 1; tmp.key < a[k].key && k >= 0; k--) // 循环2：借助循环将比新元素大的都向后移一个位置
      a[k+1] = a[k];// 比新元素大的向后搬移
    a[k+1] = tmp;// 新元素插入
  }
}
```
- 最好情况：已经有序，则内循环：每次只执行给循环变量赋初值和条件判别，即跳出——常量时间
    时间复杂度O(N)
- 最坏情况：原递减序，则每趟排序：比较j次，搬移j+2次——循环次数可能是n的循环
  次数n的循环嵌套可能为n的循环——时间复杂度O(N^2)
- 平均情况：每趟排序：j/2次排序，j/2+2次比较
    时间复杂度：O(N^2) —— 直接插入排序只适合排序的数据较少的情况

### 10.2.2 折半插入排序
- 改进思路：通过二分查找代替顺序查找快速找到a[j]的插入位置。（相对直接排序：减少比较次数）。
- 总比较次数<=log((n-1)!)+n即O(nlogn)，总移动次数O(n^2)，总时间复杂度O(N^2)。
- summary:
  - 比较：O(NlogN)
  - 搬移：......最佳：O(N).........平均：O(N^2)........最差:O(N^2)
  - 时间复杂度： 最佳：O(NlogN).....平均：O(N^2)........最差O(N^2)
  - 空间复杂度：O(1)
  - 稳定性：稳定
- 对直接插入改进微乎其微，对接近排好序的序列甚至更差。

### 10.3.3 希尔排序（步长递减插入排序，缩小增量排序）
- 改进思路：避免大量数据搬移。(相对直接排序的改进：减少搬移次数。)
- 基本思想：先比较离得较远的元素，一次交换相当于直接排序的多次交换。后比较离的近的。以此类推逼近直接插入排序。
- 算法思想：
  - 先把序列分割成若干**小序列**，在小序列内插入排序
    （分割方法：相隔一定距离(步长)的各个记录组成一个子序列）
    （小序列内直接插入排序利用：1.直接插入排序短序列更有效 2.直接插入排序最佳O(N)）
  - 逐渐扩大小序列规模，减小小序列个数，使得待排序序列状态更有序
    （最后对整个序列直接插入排序（最后步长应为1））

代码清单10-2 希尔排序的实现
(step/2)不是合适的步长序列，2^n-1较合适
``` cpp
template <class KEY, class OTHER>
void shellSort(SET<KEY, OTHER> a[], int size)
{
  int step i, j;
  SET<KEY, OTHER> tmp;

  for (step = size/2; step > 0; step /= 2)  // step为希尔增量
    for (i = step; i < size; ++i){  // 对相距step的元素序列采用直接插入排序(依次对每个元素，在其所在的小序列中排列)
      tmp = a[i];
      for (j = i-step; j >= 0 && a[j].key > tmp.key; j -= step)
        a[j+step] = a[j];
      a[j+step] = tmp;
    }
}
```

- 步长序列(增量)的选择：
  - bad：1，2，3，8...
    - 时间复杂度O(N^2)
    - 步长不应互为倍数
    - 最后一次步长必为1
  - good：1，3，7，15...
    - 平均时间复杂度O(N^3/2)
    - 空间复杂度O(1)
    - 不稳定（长距离交换）

_____
附：
.N^x中x可以无限接近1，但不为1，相比之下是NlogN的复杂度更好
。非稳定排序
.对稳定性无要求时可以采用

```cpp
template<class KEY, class OTHER>
void shellSort(SET<KEY, OTHER>, a[], int size)
{
  int step, i, j;
  for (int step = size/2; step > 0; step /= 2)
    for (int i = 0; i < step; i++)
      for (int j = i; j < size; j += step)
      {
        
      }
}
```
_____
<br>

## 10.3 选择排序
都是选出最小的用于交换/放到第一个，区别是如何选出
### 10.3.1 直接选择排序
- 顺序查找最小元素，与第i个元素交换，直到all放入合适位置
- 比较次数：O(N^2),移动次数：有序0，逆序3(n-1)**不受影响？**
- 时间复杂度O(N^2)——适合n较小的场合
- 空间复杂度O(1)
- 不稳定
代码清单10-3 直接选择排序的实现
```cpp
template<class KEY, class OTHER>
void simpleSelectSort(SET<KEY, OTHER> a[], int size)
{
  int i, j, min;
  SET<KEY, OTHER> tmp;
  for (i = 0; i < size; i++)
  {
    min = i;
    for (j = i; j < size; j++)
      if (a[j].key < a[i].key)
        min = j;                // 找出最小的的序号
    tmp = a[i];     // 交换
    a[i] = a[min];
    a[min] = tmp;
  }
}
```
### 10.3.2 堆排序
概念与分析：
- 优先级队列出队得到最小元素（优先级队列出队得到最大元素放在数组末尾）
- 时间复杂度：
  - 建堆形成优先级队列O(N)
  - 直接选择排序选出最小n-1次比较，基于堆的优先级队列选出最小元素O(logN)
  - O(NlogN) 
    —— 适合长序列（短序列可以用之前简单的算法，该算法相对有些复杂）(保证最坏O(NlogN))
- 空间复杂度O(1)（始终用的那个数组(每次利用deQueue得到的空闲空间放排好的元素)，只有一个tmp的额外空间）
- 涉及长距离交换，不稳定


注意事项：
- 建堆：由于需要将大的放在后面，所以建堆最大堆而不是最小堆
  - 从数组0位开始储存，i位置的父结点(i-1)/2，左孩子2i+1，右孩子2i+1
- deQueue:出队的元素放在堆后新的空闲空间(a[0]与数组最后一个元素交换，堆规模减一，向下过滤)
  - 向下过滤：需要传递堆规模参数，而不是对整个数组(末尾包含已排序记录)执行，三参：待排序数组，向下过滤起始位置，堆大小

代码清单10-4 堆排序的实现
```cpp
template<class KEY, class OTHER>
void heapSort(SET<KEY, OTHER> a[], int size)
{
  int i;
  SET<KEY, OTHER> tmp;

  // 创建初始的堆
  for(i = size/2 - 1; i >= 0; i--)
    percolateDown(a, i, size);
  //执行n-1次deQueue//不是调用函数deQueue，自己实现
  for (i = size - 1; i >= 0; --i)
  {
    tmp = a[0];// tmp = deQueue(a);
    a[0] = a[i];// a[i] = tmp;
    a[i] = tmp;//不用放在最后// delete a[0]
    percolateDown(a, 0, i);
    
  }
}
```

代码清单10-5 percolateDown函数的实现（基本相同，除了过滤时不是找最小儿子而是找最大的）
```cpp
template<class KEY, class OTHER>
void percolateDown(SET<KEY, OTHER> a[], int hole, int size)
{
  int child;
  SET<KEY, OTHER> tmp = a[hole];

  for (;hole * 2 + 1 < size; hole = child)//hole还有孩子
  {
    child = 2 * hole + 1;
    if (child != size - 1 && a[child+1].key > a[child].key)//哪个孩子有可能向上进入hole
      child += 1;
    if (a[child] > a[hole])//hole下移还是找到hole/孩子是否上去导致hole下移
      a[hole] = a[child];
    else
      break;
  }
  a[hole] = tmp;// 数据入hole
}
```



最好情况：原本就是逆序，便于建堆
复杂度级别一样，但是具体操作次数有时可能较少
堆排序函数有三点不同，2i-1，>0
（最大堆>变<，从0储存，父结点(i-1)/2左子2i+1）
排序先建堆

## 10.4 交换排序

### 10.4.1 冒泡排序
- 基本方法：
  - 从头到尾比较相邻的两个元素，将小的换到前面，大的换到后面。从头到尾一趟(一趟起泡)比较则把最大放在了最后。
  - 从头到倒数第二个元素，第二趟起泡，第二大放在倒数第二个。
  - 以此类推，经过n-1趟起泡，倒数n-1大在第二个。
- 改进1：设立交换检查标志，当不出现交换时终止算法。
- 冒泡排序的实现
代码清单10-6
``` cpp
template <class KEY, class OTHER>
void bubbleSort(<KEY, OTHER> a[], int size)
{
  int i, int j;
  SET<KEY, OTHER> tmp;
  bool flag = true; //记录一趟气泡过程中有没有发生过交换

  for (int i = 0; (i < size) && flag; i++)// size - 1次起泡
  {
    flag = false;
    for (int j = 0; j < size - 1; j++)//第i次起泡
      if (a[j] > a[j+1])
      {
        tmp = a[];
        a[j] = a[j+1];
        a[j+1] = tmp;
        flag = trie;
      }
  }
}
```
- 冒泡排序的性能
  - 时间复杂度
    - 最好时间复杂度O(N)
      原始序列有序时，只需一次起泡（n-1次比较）即可
    - 最坏时间复杂度O(N2)
    - 原始序列逆序时，n-1趟起泡，每次起泡n-i次比较，n-i次交换
  - 适合原序列接近有序的情况
  - 空间复杂度：O(1)（交换用到一个tmp的空间）
  - 稳定性:稳定
summary：

### 10.4.2 快速排序
- 基本思想：
  - 选一数据元素为标准，（用于：将数据分为两组，第一组元素均<=标准元素，第二组元素均>=标准元素）
  - 将第一组的元素放在数组的前面部分，第二组数据元素放在数组的后面部分，标准元素放中间（即标准元素最终位置）
  ——一趟划分
  - 对分成的两组分别重复上述过程(递归)，直到所有元素都在适当位置。

- 注意事项
  - 1. 标准元素的选择
    - 用待排序序列的第一个元素作标准元素
      ——若数据随机分布，能把数据分成均匀两部分
      ——若有序/逆序，则是糟糕的划分，所有待排序数据都在标准元素的一边——时间复杂度是平方级的
    - 随机选择一个标准元素
      少有可能选到最差的，但随机数的选择也花相当多时间
    - 选择中值
      以采样的方式将子集中值作为标准元素
  - 2. 如何划分
    - 开一个同样大小的数组
      顺序扫描原数组，小从左边开始放，大从右边开始放
      实现简单，空间效益差，O(N)空间复杂度
    - 只用一个额外单元的巧妙方法
      - 过程：
      - 先将标准元素放入k中，数组中则有了一个空单元，以low标识。
      - 指针high从右向左扫描，遇到比标准元素小的则暂停，将此时指向的元素放入low指向的空位置。此时数组中一个空单元，被high标识。
      - 指针low从左向右扫描，遇到比标准元素大的则暂停，将此时指向的元素放入high指向的空位置。此时数组中一个空单元，被low标识。
      - 直到low，high重叠，此时将标准元素放入该位置。
      - 分析
        - 只用一个额外空间储存标准元素
        - 对待划分的数据只做了一遍扫描

- 快速排序的实现：
  函数divide完成划分。递归实现快排，递归参数是待排序数据的范围——参数low，high，保存待排序数据的数组a。
  -首先判断递归终止条件是否成立——即排序区间是否存在
  - low>=high，待排序元素不存在/只有一个 => 排序完成，返回。
  - 否则，对此范围内数据排序：
  STEP1调用divide，分成两部分并，返回标准元素位置
  STEP2递归调用quickSort分别排序作、右半部分数据。

  -and then ...排序工作完成！

代码清单10-7 快速排序的实现
```cpp
template <class KEY, class OTHER>
void quickSort(SET<KEY, OTHER> a, int low, int high)
{
  if(low >= high)// 待分段元素只有1个或0个，递归终止
    return;
  int mid = divide(a, low, high);
  quickSort(a, low, mid-1);//排序左一半
  quickSort(a, mid+1, high);//排序右一半
}
```

代码清单10-8 快速排序的包裹函数
考虑到10-7代码清单中的排序算法函数原型与其他的不同，为统一，使用包裹函数
``` cpp
template<class KEY, class OTHER>
void quickSort(SET<KEY, OTHER> a[], int size)
{
  quickSort(a, 0, size-1);
}
```

代码清单10-9 划分函数的实现
工具函数，按注意事项中的讨论实现，返回标准元素的位置
``` cpp
template <class KEY, class OTHER>
int divide(SET<KEY, OTHER> a[], int low, int high)//因为要不断在递归中被调用，并不是都对整个数组处理，故须low，high
{
  SET<KEY, OTHER> k = a[low];
  do{
    while(low < high && a[high].key >= k.key) --high; // for (;a[high].key > k.key && high != low; high--)
    if (high > low) {a[low] = a[high]; low++}// a[low] = a[high];
    while(low < high && a[low].key <= k.key>) ++low;// for (; a[low].key < k.key && high != low; low++)
    if (low < high) {a[high] = a[low]; --high}// a[high] = a[low];
  } while(low != high);
  a[low] = k;
  return low;
}
```

- 性能分析
  - 最好时间复杂度
    最好情况是分成两个相同规模子集。
    根据T(N) = 2T(N/2) + cN，可得出最好时间复杂度O(NlogN)
  - 最坏时间复杂度
    最坏情况是标准元素是最小/最大元素，划分成一个N-1规模的子集。
    根据T(N) = T(N-1) +cN，忽略T(1)，可得T(N)=T(1)+∑i=O(N^2)
  - 平均时间复杂度
    考虑每个可能的子集规模开销求平均值
    根据NT(N)与(N-1)T(N-1)错位相减，有T(N)/N+1= T(N-1)/N + 2c/N+1，可得时间复杂度O(NlogN)


## 10.5 归并排序
1. 思想来源：两个有序表的合并
- 基本思想：两个已有序的表的合并。
  因为都有序，只需从两个表头开始顺序比较，小的放入C表中。
  反复如此直到一表为空，便可将零一表剩下元素全部复制到C的剩余位置。
- （代码清单10-10 归并两个有序序列）
```cpp
tempalte<class KEY, class OTHER>
void merge(SET<KEY, OTHER> a[], int left, int mid, int right)
{
  SET<KEY, OTHER> * tmp = new SET<KEY, OTHER>[right-left+1];
  int i = left, j = mid, k = 0;

  while(i < mid && j <= right>) // 两表都为结束
    if(a[i] <= a[j]) tmp[k++] = a[i++];//tmp[i+j] = a[i];i++!!!!!!
    else  tmp[k++] = a[j++];
  
  while(i < mid)  tmp[k++] = a[i++];//前半部分没有结束，注意没有等号
  while(j <= right) tmp[k++] = a[j++];//后半部分没有结束，注意等号

  for (i = 0; k = left; k <= right) a[k++] = tmp[i++];//注意right可以取到相等
  delete [] tmp;
}
```

1. 归并排序
- 基本思想：利用递归和归并实现排序
  只有一个元素——已排好的序列，排序结束
  否则，对前一半和后一半分别调用归并排序函数进行排序，再将两个排好的序列归并起来。
  —— 那么，就完成了整个序列的排序。
- （代码清单10-11 归并排序的实现）
``` cpp
template<class KEY, class OTHER>
void mergeSort(SET<KEY, OTHER> a[], int left, int right)
{
  int mid = (left+right)/2;

  if (left == right)  return;
  mergeSort(a, left, mid);
  mergeSort(a, mid+1, right);
  merge(a, left, mid+1, right);
}
```
- （代码清单10-12 为一致性，使用包裹函数）
``` cpp
template <class KEY, class OTHER>
void mergeSort(SET<KEY, OTHER> a[], int size)
{
  mergeSort(a, 0, size-1);
}
```

1. 性能分析
- 时间复杂度：与数据的初始排列无关
  根据T(N) = 2T(N/2) + N（此处类似快速排序最好情况）
  可得时间复杂度为O(NlogN)（与快排最好、平均时间复杂度一致）
- 空间复杂度O(N)
``` cpp
```

## 10.6 基数排序（口袋排序法）
- 基本思想：通过**分配**的方法排序（而不是比较）
  - 多关键字基数排序的两类
    - **高位优先法**（分分分...收）
      - 对最高位口袋排序
      - 对每个口袋，按次高位口袋排序，分为更小的口袋
      - 依此类推对K0排序
      - 将最小的口袋依次连接在一起，得有序序列
    - **低位优先法**：(分、收、分、收...分、收)(一定是低位优先)
      - 先对最低位K0口袋排序，把所有记录按口袋顺序收起来（分收）
      - 以此类推，对K1（分收）
      - 直到对最高位Kd-1排序（...分收）
- 算法实现：
  - 口袋不知道多大合适——连接储存合适
  - 每个口袋用一个不带头结点的单链表储存（每个口袋以单链表表示，基数个首尾指针，以指针数组表示）
  - ——链接技术，增设链指针便于收集。
  - 分：建立每个口袋单链表
  - 收：单链表首尾指针相连
代码清单10-13 口袋排序的实现
``` cpp
// 首先定义单链表的结点类型
template<class OTHER>
struct node{
  SET<int, OTHER> data;
  node * next;

  node() {next = nullptr;} //可以有元素不初始化（还是调用了默认构造函数已经？
  node(SET<int, OTHER> d): data(d) {next = nullptr;}
}

template<class OTHER>
void bucketSort(node<OTHER> *&p)
{
  node<OTHER> *bucket[10], *last[10], *tail;//bucket,last:10个口袋  //bucket,last分别是每个口袋的链表的头尾(无头结点)
  int i, j, k, base = 1, max = 0, len = 0;// i由于记录len次分收的第i次，遍历中第j个口袋，数据应分配到第k个口袋

  for (tail = p; tail != nullptr; tail = tail->next)  //找最大键值
    if (tail -> data.key > max) max = tail->data.key;
  if (max == 0) len = 0;
  else  while(max >0)  { len++; max/=10;}

  for (i = 0; i < len; i++){
    for (j = 0; j <= 9; j++)  bucket[j] = last[j] = nullptr;  //清空口袋
    while(p != nullptr){                // 执行一次分配
      k = p->data.key / base % 10;      // 计算出结点应分配到的口袋
      if (bucket[k] == nullptr) bucket[k] = last[k] = p; //当口袋为空时，首尾同时指向此个
      else last = last[k]->next = p;//注意链接+尾指针移动 //当口袋不为空时，尾部链接＋尾指针移动到指向最后一个
      p = p->next;  //循环条件更新
    }

    p = nullptr;  //重组后的链表
    for (int j = 0; j <= 9; j++){ // 执行重组
      if (bucket[j] == nullptr) continue;
      if (p == nullptr) p = bucket[j];
      else tail->next = bucket[j];// 口袋新链表头加入，分p空与非空两种情况
      tail = last[j];// 口袋新链表的尾巴加入
    }
    tail -> next = nullptr; // 表尾置空
    base *= 10;             // 为下一次分配做准备
  }
}
```
- 算法分析
  - 时间复杂度O(len(N+r))
    - 分：O(N)
    - 收：O(r)
    - 循环次数：len
  - 空间复杂度O(r)（O(1)）
  - 稳定

