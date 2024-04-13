#ifndef BTREE_H_
#define BTREE_H_
template<class T>
class bTree{
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
#endif