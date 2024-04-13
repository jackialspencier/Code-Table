#include <iostream>
#include "sLinkList.h"
using namespace std;
int main()
{
    sLinkList<char> chlist;

    char temp;
    int i, n, result;

    cout << "number of elements:" << endl;
    cin >> n;
    cin.get(temp);

    cout << "input the elements:\n" << endl;
    for (i = 0; i < n; i++)
    {
        cin.get(temp);
        chlist.insert(i, temp);
    }

    temp = chlist.visit(0);
    chlist.remove(0);
    chlist.insert(n/2, temp);

    cout << "output the elements:\n" << endl;
    for (i = 0; i < chlist.length(); i++)
        cout.put(chlist.visit(i));
    
    cout << '\n';

    chlist.reverse();
    cout << "output the elements:\n";
    chlist.traverse();
    cout << endl;
    return 0;
}