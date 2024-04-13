#include "seqStack.h"
#include <iostream>
using namespace std;
int main()
{
    const int Up = 1;
    const int Down = 2;
    const int Left = 3;
    const int Right = 4;

    // 迷宫初始化
    int n = 12;
    int ** maze = new int*[n];
    for (int i = 0; i < n; i++)
        maze[i] = new int[n]{0};
    for (int i = 1; i < n - 1; i++)
        for (int j = 1; j < n - 1; j++)
            cin >> maze[i][j];
    
    // 循环走格子
    seqStack<int> road;
    int currentI = 1;
    int currentJ = 1;
    int tmp;
    int i = 1;
    int j = 1;
    road.push(0);
    maze[1][1] = 2;
    while(!(i == n-2 && j == n-2)){
        if (maze[i][j-1] == 1){
            road.push(Left);
            maze[i][j-1] = 2;
            currentJ--;
            j--;
            
        }
        else if (maze[i][j+1] == 1){
            road.push(Right);
            maze[i][j+1] = 2;
            currentJ++;
            j++;
        }
        else if (maze[i-1][j] == 1){
            road.push(Up);
            maze[i-1][j] = 2;
            currentI--;
            i--;
            
        }
        else if (maze[i+1][j] == 1){
            road.push(Down);
            maze[i+1][j] = 2;
            currentI++;
            i++;
            
        }
        else
        {
            tmp = road.pop();
            if (tmp == Up)
                i++;
            else if (tmp == Down)
                i--;
            else if (tmp == Left)
                j++;
            else if (tmp == Right)
                j--;
        }
    }
    
    cout << "Read the route from rear:" << endl;
    while(!road.isEmpty()){
        tmp = road.pop();
        if(tmp == Left)
            cout << "Left ";
        else if(tmp == Right)
            cout << "Right ";
        else if(tmp == Up)
            cout << "Up ";
        else if(tmp == Down)
            cout << "Down ";
        else if (tmp == 0)
            cout << "Start";
    }
    
    return 0;
}