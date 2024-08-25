#include "Set.h"
#include "dynamicSearchTable.h"
#include "CloseHashTable.h"
struct sequn
{
    int row;
    int col;
};
int sequnToInt(const sequn &x); 
int main()
{
    int vlaue;

    closeHashTable<sequn, int> spmatrix(127, sequnToInt);
}

int sequnToInt(const sequn &x)
{
    return (x.row % 100) * 100 + (x.col % 100);
};