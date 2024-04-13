// 代码清单2-2 顺序表类的定义和实现
# include "list.h"
template<class elemType>
class seqList: public list<elemType>
{
    private:
        elemType * data;
        int currentLength;
        int maxSize;
        void doubleSpace(); // 扩大数组空间
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

template<class elemType>
void seqList<elemType>::doubleSpace()
{
    elemType * temp = data;
    // data = new[2 * maxSize];
    maxSize *= 2;
    data = new elemType[maxSize];
    for (int i = 0; i < currentLength; i++)
        data[i] = temp[i];
    delete [] temp;
}

template<class elemType>
seqList<elemType>::seqList(int initSize)
{
    maxSize = initSize;
    data = new elemType[maxSize];
    currentLength = 0;
}

template<class elemType>
seqList<elemType>::~seqList()
{
    // clear();//别漏啦delete data
    delete data;
}

template<class elemType>
void seqList<elemType>::clear()
{
    currentLength = 0;
}

template<class elemType>
int seqList<elemType>::length() const
{
    return currentLength;
}

template<class elemType>
void seqList<elemType>::insert(int i, const elemType &x)
{
    if (currentLength == maxSize)
        doubleSpace();
    for (int j = currentLength; j > i; j--)
        data[j] = data[j-1];
    data[i] = x;
    ++currentLength;
}

template<class elemType>
void seqList<elemType>::remove(int i)
{
    // if (i<0 || i>currentLength - 1)
    //     throw OutOfBound();
    for (int j = i; j < currentLength - 1; j++)
        data[j] = data[j+1];
    --currentLength;
}

template<class elemType>
int seqList<elemType>::search(const elemType &x) const
{
    // for (int i = 0; i < currentLength; i++)
    //     if (data[i] == x)
    //         return i;
    // return -1;
    for (int i = 0; i < currentLength && data[i] != x; i++)
    if (i == currentLength) return -1;
    else return i;
    return -1;
}

template<class elemType>
elemType seqList<elemType>::visit(int i) const
{
    return data[i];
}

template<class elemType>
void seqList<elemType>::traverse() const
{
    std::cout << std::endl;
    for (int i = 0; i < currentLength; i++)
        std::cout << data[i] << ' ';
}
