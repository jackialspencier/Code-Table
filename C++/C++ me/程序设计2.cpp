//第二章 程序的基本组成
//2.1程序的基本结构
//代码清单2-1 求解一元二次方程
//文件名 2-1.cpp
//用标准公式求解一元二次方程
// #include <iostream>
// #include <cmath>
// using namespace std;
// int main()
// {
//     double a, b, c, x1, x2, dlt;

//     cout << "请输入方程的三个系数" << endl;
//     cin >> a >> b >> c;

//     dlt = b * b - 4 * a * c;
//     x1 = (-b + sqrt(dlt)) / 2 / a;
//     x2 = (-b + sqrt(dlt)) / 2 / a;

//     cout << "x1=" << x1 << "   x2=" << x2 << endl;

//     return 0;
// }

//PPT Hello World
// File: hello.cpp
// this program prints the message
//"hello everyone" on the screen
// #include <iostream>
// using namespace std;
// int main()
// {
//     cout << "hello everyone" << endl;
//     return 0;
// }

//PPT a+b问题
//This program prints sum of two integers
// #include <iostream>
// using namespace std;
// int main()
// {
//     int a, b, c;

//     cin >> a >> b;
//     c = a + b;
    
//     cout << "result = " << c << endl;//'\n';
//     return 0;
// }

//-1加一？
// #include <iostream>
// using namespace std;
// int main()
// {
//     // short a = -1;
//     // short b = a + 1;

//     // cout << b << endl;

//     // return 0;
//     char ch = 'A';
//     printf("%d", ch);

//     return 0;
// }
//为什么，不是从1111111111111111变成10000000000000000（截断截断第一个？）

// #include <iostream>
// using  namespace std;
// int main()
// {
//     //输入你的代码
//     int a, a1, a2, a3, a4;
//     char ch1, ch2, ch3, ch4;

//     cin >> a;//尖括号往哪里要分清楚哇.
//     a4 = a / 1000;
//     a3 = (a % 1000) / 100;
//     a2 = (a % 100) / 10;
//     a1 = a % 10;

//     ch1 = (a4 + 13) - 1 + 'A';
//     ch2 = (a3 + 13) - 1 + 'A';
//     ch3 = a2 + 12 + 'A';
//     ch4 = a1 + 12 + 'A';

//     cout << ch1 << ch2 << ch3 << ch4;

//     return 0;
// }

// #include <iostream>
// using  namespace std;
// int main()
// {
//     int a;
//     a = 4 - !3;
//     cout << a;
// }