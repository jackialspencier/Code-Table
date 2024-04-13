#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    int nums[10000];
    int count = 0;
    int target, i, j;
    bool foundAnswer = false;

    //获取输入
    while(scanf("%d", &nums[count]))
        count++;
    cin >> target;
    //处理数据
    for (i = 0; (i < count) && (!foundAnswer); i++)
        for (j = 0; j < count && (!foundAnswer); j++)
            if (nums[i] + nums[j] == target & i != j)
                foundAnswer = true;
    cout << i << j;
    return 0;
}