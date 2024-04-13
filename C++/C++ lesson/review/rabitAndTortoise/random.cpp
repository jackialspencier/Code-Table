#include "random.h"
#include<cstdlib>
#include<ctime>

// 初始化随机数种子
void RandomInit(){
    srand(time(nullptr));
}
// 返回一个low到high之间的随机数，包括low和high
int RandomInteger(int low, int high)
{
    return (low + (high - low + 1) * rand() / (RAND_MAX + 1));
}


