#include <iostream>
#include "seqList.h"
using namespace std;
// 上述顺序表类的定义存放在头文件"seqList.h"中
int main(){
    seqList<char> chlist(21);   // seqList类对象，ElemType定义为char
                                // 空间大小21
    char ctemp;
    int i, n, result;

    cout << "number of the elements:" << endl;
    cin >> n;
    cin.get(ctemp);// 处理enter     // 将Enter抛弃

    cout << "input the elements:\n" << endl;
    for (int i = 0; i < n-1; i++){
        cin.get(ctemp);
        chlist.insert(i, ctemp);
    }

    ctemp = chlist.visit(0);    //获得首结点
    chlist.remove(0);
    chlist.insert(chlist.length()/2, ctemp);
    
    cout << "output the elements:\n" << endl;
    for (i = 0; i < chlist.length(); i++)
        cout.put(chlist.visit(i));
    cout << '\n';

    return 0;
}