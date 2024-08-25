#ifndef DYNAMICSEARCH_H_
#define DYNAMICSEARCH_H_
#include "Set.h"
template <class KEY, class OTHER>
class dynamicSearchTable{
    public:
        virtual SET<KEY, OTHER> *find(const KEY &x) const = 0;
        virtual void insert(const SET<KEY, OTHER> &X) = 0;
        virtual void remove(const KEY &x) = 0;
        virtual ~dynamicSearchTable() {};
};
#endif