#ifndef _LIST_H
#define _LIST_H
template<class elemType>
class list
{
    public:
        virtual void clear()=0; // 删除线性表中所有的数据元素
        virtual int length() const=0;   // 求线性表的长度
        virtual void insert(int i, const elemType &x)=0;    // 在第i个位置插入一个元素
        virtual void remove(int i)=0;   // 删除第i个位置的元素
        virtual int search(const elemType &x) const=0;  // 搜索某个元素x在线性表中是否出现
        virtual elemType visit(int i) const=0;  // 返回线性表中第i个数据元素的值
        virtual void traverse() const=0;    // 按序访问线性表的每一数据元素
        virtual ~list() {};
};
#endif