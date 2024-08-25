#ifndef CLOSEHASHTABLE_H_
#define CLOSEHASHTABLE_H_
#include "Set.h"
template <class KEY, class OTHER>
class closeHashTable: public dynamicSearchTable<KEY, OTHER>
{
private:
    struct node
    {
        SET<KEY, OTHER> data;
        int state; // 0 -- empty  1 -- active  2 -- deleted
        // enum STATE
        // STATE state

        node() { state = 0; }
    };

    node *array;
    int size;
    int (*key)(const KEY &x); //???
    static int defaultKey(const int &x) { return x; }

public:
    closeHashTable(int length = 101, int (*f)(const KEY &x) = defaultKey);
    ~closeHashTable() {delete [] array;}
    SET<KEY, OTHER> *find(const KEY &x) const;
    void insert(const SET<KEY, OTHER> &x);
    void remove(const KEY &x);
};

template <class KEY, class OTHER>
closeHashTable<KEY, OTHER>::closeHashTable(int length, int (*f)(const KEY &x))
{
    size = length;
    array = new node[size];
    key = f;
}

template <class KEY, class OTHER>
void closeHashTable<KEY, OTHER>::insert(const SET<KEY, OTHER> &x)
{
    int initPos, pos;

    initPos = pos = key(x.key) % size;
    do
    {
        if (array[pos].state != 1)
        { // 找到空单元
            array[pos].data = x;
            array[pos].state = 1;
            return;
        }
        pos = (pos + 1) % size;
    } while (pos != initPos);
}

template <class KEY, class OTHER>
void closeHashTable<KEY, OTHER>::remove(const KEY &x)
{
    int initPos, pos;

    initPos = pos = key(x) % size;
    do
    {
        if (array[pos].state == 0)
            return;
        if (array[pos].state == 1 && array[pos].data.key == x)
        { // 找到，删除   //为什么需要检查为1？可能2，已删除
            array[pos].state = 2;
            return;
        }
        pos = (pos + 1) % size;
    } while (pos != initPos);
}

template <class KEY, class OTHER>
SET<KEY, OTHER> *closeHashTable<KEY, OTHER>::find(const KEY &x) const
{
    int initPos, pos;

    initPos = pos = key(x) % size;
    do
    {
        if (array[pos].state == 0)
            return nullptr; // 注意nullptr
        if (array[pos].state == 1 && array[pos].data.key == x)
            return &array[pos].data;
        pos = (pos + 1) % size;
    } while (pos != initPos);
}

#endif