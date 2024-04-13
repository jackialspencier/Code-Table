#include <iostream>
using namespace std;
void f(int arr[], int k) {
    cout << sizeof(arr) << " " << sizeof(k) << endl;
}
int main() {
    int * a;
	a = new int[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
	cout << sizeof(a) << endl;
    for (int i = 0; i < 10; i++)
        cout << a[i] << '\t';
    cout << endl;
	f(a, 10);
    delete [] a;
	return 0;
	// C++ 将数组名作为参数传递的情况处理成指针的传递
}