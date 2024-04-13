//第三章 处理数据
//3.1 简单变量
//3.1.1变量名
//3.1.2 整型
//3.1.3整型short、int、long和long long
//程序清单3.1 limits.cpp
// #include <iostream>
// #include <climits>
// int main()
// {
//     using namespace std;
//     int n_int = INT_MAX;
//     short n_short = SHRT_MAX;
//     long n_long = LONG_MAX;
//     long long n_llong =LLONG_MAX;

//     //sizeof operator yields size of type or of variable;
//     cout << "int is " << sizeof(int) << " bytes." << endl;
//     cout << "short is " << sizeof n_short << " bytes." << endl;
//     cout << "long is " << sizeof n_long << "bytes." << endl;
//     cout << "long long is " << sizeof n_llong << " bytes." << endl;
//     cout << endl;
    
//     cout << "Maximum values:" << endl;
//     cout << "int: " << n_int << endl;
//     cout << "short: " << n_short << endl;
//     cout << "long: " << n_long << endl;
//     cout << "long lomg :" << n_llong << endl;

//     cout << "Minimum int value = " << INT_MIN << endl;
//     cout << "Bits per bytes = " << CHAR_BIT << endl;

//     return 0;
// }

//程序清单3.2 exceed.cpp
//exceed.cpp --exceeding some integer limits
// #include <iostream>
// #define ZERO 0
// #include <climits>
// int main()
// {
//     using namespace std;
//     short sam = SHRT_MAX;
//     unsigned short sue =sam;

//     cout << "Sam has " << sam << " dollars and Sue has " << sue;
//     cout << " dollars deposited." << endl
//          << " Add $1 to each account." << endl << "Now ";
//     sam = sam + 1;
//     sue = sue + 1;
//     cout << "Sam has " << sam << " dollars and Sue has "<< sue;
//     cout << " dollars deposited.\nPoor Sam!" << endl;
//     sam = ZERO;
//     sue = ZERO;
//     cout << "Sam has " << sam << " dollars and Sue has " << sue;
//     cout << " dollars deposited." << endl;
//     cout << "Take $1 from each account." << endl << "Now";
//     sam = sam - 1;
//     sue = sue - 1;
//     cout << "Sam has " << sam << "dollars and Sue has " << sue; 
//     cout << " dollars deposited." << endl << "Lucky Sue!" << endl;
//     return 0;
// }

//3.1.5选择整数类型
//3.1.6 整型字面值
//程序清单3.3 hexoct.cpp
//hexoct.cpp -- shows hex and octal literals
// #include <iostream>
// int main()
// {
//     using namespace std;
//     int chest = 42;//decimal integer literal 
//     int waist = 0x42;//hexadecimal integer literal
//     int inseam = 042;// octal integer literal

//     cout << "Monsieur cuts a striking figure!\n";
//     cout << "chest = " << chest << " (42 in decimal)\n";
//     cout << "waist = " << waist << " (0x42 in hex)\n";
//     cout << "inseam = " << inseam << " (042 in octal\n)";

//     return 0;
// }

//程序清单3.4 hexoct2.cpp
//hexoct2.cpp -- display values in hex and octal
// #include <iostream>
// using namespace std;
// int main()
// {
//     using namespace std;
//     int chest = 42;
//     int waist = 42;
//     int inseam = 42;

//     cout << "Monsieuer has a striking figure!" << endl;
//     cout << "chest = " << chest << " (decimal for 42)" << endl;
//     cout << hex;
//     cout << "waist = " << waist << " (hexadecimal for 42)" << endl;
//     cout << oct;
//     cout << "inseam = " << inseam << " (octal for 42)" << endl;
//     return 0;
// }

//3.1.7 C++如何确定常量的类型
//3.1.8char类型：字符和小整数
//程序清单3.5 chartypr.cpp
//chartype.cpp -- the char type
// #include <iostream>
// int main()
// {
//     using namespace std;
//     char ch;

//     cout << "Enter a character: " << endl;
//     cin >> ch;
//     cout << "Halo!";
//     cout << "Thank you for the " << ch << " character." << endl;

//     return 0;
// }

//程序清单3.6 morechar.cpp
// #include <iostream>
// int main()
// {
//     using namespace std;
//     char ch = 'M';
//     int i = ch;
//     cout << "The ASCII code for " << ch << " is " << i << endl;

//     cout << "Add one to the character code:" << endl;
//     ch = ch + 1; 
//     i = ch;
//     cout << "The ASCII code for " << ch << " is " << i <<endl;

//     //using the cout.put() member function to display a char
//     cout << "Displaying char ch using cout.put(ch): ";
//     cout.put(ch);

//     //using cout.put() to display a char constant
//     cout.put('!');

//     cout << endl << "Done!" << endl;
//     return 0;
// }

// //程序清单3.7 bondini.cpp
// #include <iostream>
// int main()
// {
//     using namespace std;
//     cout << "\aOpreation \"HyperHype\" is now activated!\n";
//     cout << "Enter your agent code:________\b\b\b\b\b\b\b\b";
//     long code;
//     cin >> code;
//     cout << "\aYou entered " << code << "...\n";
//     cout << "\aCode verified! Proceed with Plan Z3!\n";
//     return 0;
// }

//程序清单3.8 floatnum.cpp
//floatnum.cpp -- floating-point types
// #include <iostream>
// int main()
// {
//     using namespace std;
//     cout.setf(ios_base::fixed, ios_base::floatfield);
//     float tub = 10.0 / 3.0;
//     double mint = 10.0 / 3.0;
//     const float million = 1.0e6;

//     cout << "tub = " << tub;
//     cout << ", a million tubs = " << million * tub;
//     cout << ",\nand then million tubs = ";
//     cout << 10 * million * tub << endl;

//     cout << "mint = " << mint << " and a million mints = ";
//     cout << million * mint << endl;
//     return 0;
// }

//程序清单3.9 fltadd.cpp
//fltadd.cpp -- precision problems with float
// #include <iostream>
// int main()
// {
//     using namespace std;
//     float a = 2.34E+22f;
//     float b = a + 1.0f;

//     cout << "a = " << a << endl;
//     cout << "b - a = " << b - a << endl;
//     return 0;
// }

//C++3.4算术运算符
//程序清单3.10 arith.cpp
//arith.cpp -- some C++ arithmetic
// #include <iostream>
// int main()
// {
//     using namespace std;
//     float hats, heads;
//     cout.setf(ios_base::fixed, ios_base::floatfield);
//     cout << "Enter a number: ";
//     cin >> hats;
//     cout << "Enter another number: ";
//     cin >> heads;

//     cout << "hats = " << hats << "; heads = " << heads << endl;
//     cout << "hats + heads = " << hats + heads << endl;
//     cout << "hats - heads = " << hats - heads << endl;
//     cout << "hats * heads = " << hats * heads << endl;
//     cout << "hat / heads = " << hats / heads << endl;
//     return 0;
// }

//3.4.1运算符的优先级和结合性
//程序清单3.11 divide.cpp
//divide.cpp -- integer and float-point division
// #include <iostream>
// int main()
// {
//     using namespace std;
//     cout.setf(ios_base::fixed, ios_base::floatfield);
//     cout << "Interger division: 9/5 = " << 9 / 5 << endl;
//     cout << "Floating-point division: 9.0 / 5.0 = ";
//     cout << 9.0 / 5.0 << endl;
//     cout << "Mixed division: 9.0 / 5 = " << 9.0 / 5 << endl;
//     cout << "double constants: 1e7/9.0 = ";
//     cout << 1e7 / 9.0 << endl;
//     cout << "Float constants: 1e7f/9.0f = ";
//     cout << 1.e7f / 9.0f << endl;
//     return 0;
// }

//3.4.3 求模运算符
//程序清单3.12 modulus.cpp
//modulus.cpp --uses %operator to convert lbs lbs to stone
// #include <iostream>
// int main()
// {
//     using namespace std;
//     const int Lbs_per_stn = 14;
//     int lbs;

//     cout << "Enter your weight in pounds: ";
//     cin >> lbs;
//     int stone = lbs / Lbs_per_stn;
//     int pounds = lbs % Lbs_per_stn;
//     cout << lbs << " pounds are " << stone
//          << " stone, " << pounds << " pound(s).\n";
//     return 0;
// }

//程序清单3.13 assign.cpp
//init.cpp -- type changes on initialization
// #include <iostream>
// int main()
// {
//     using namespace std;
//     cout.setf(ios_base::fixed, ios_base::floatfield);
//     float tree = 3;
//     int guess(3.9832);
//     int debt = 7.2E12;
//     cout << "tree = " << tree << endl;
//     cout << "guess = " << guess <<endl;
//     cout << "debt = " << debt << endl;

//     return 0;
// }

//2.以{}方式初始化时进行的转换（C++）

//程序清单3.14 typecast.cpp
//typecast.cpp -- forcing type changes
// #include <iostream>
// int main()
// {
//     using namespace std;
//     int auks, bats, coots;

//     //the following statement adds the values as double
//     //then converts the result to int
//     auks = 19.99 + 11.99;

//     //these statements add values as int
//     bats = (int) 19.99 + (int) 11.99;
//     coots = int (19.99) + int (11.99);
//     cout << "auks = " << auks << ", bats = " << bats;
//     cout << ", coots = " << coots << endl;

//     char ch = 'Z';
//     cout << "The code for " << ch << " is";
//     cout << int (ch) << endl;
//     cout << "Yes, the code is ";
//     cout << static_cast<int>(ch) << endl;
//     return 0;
// }

//3.4.5C++11中的auto声明
// #include <iostream>
// int main()
// {
//     using namespace std;
//     int ch = 'a';
//     auto b = ch + 1;//对吼，这不就是自动类型转换嘛，不要只从auto角度看了呀。看看这个表达式角度。
//     cout << int('A');
//     cout << int (b);
//     cout << char (b);
// }
// #include <iostream>
// int main()
// {
//     using namespace std;
//     int elec;
//     int money;
//     int a, b;

//     cin >> elec;
//     money = elec * 6;
//     a = money / 10;
//     b = money % 10;
//     cout << a << " " << b;
// }
// #include <iostream>
// using namespace std;
// int main()
// {
//     int num[2];
//     int a[4];
//     int temp1, temp2;
//     int mm;
//     int m[4];
//     int tem1, tem2;

//     cin >> num[0] >> mm;
//     for(int i = 0; i < 1; i++)
//     {
//         a[0] = num[i] / 1000;
//         a[1] = (num[i] % 1000) / 100;
//         a[2] = (num[i] % 100) / 10;
//         a[3] = num[i] % 10 / 1;
//         for (int j = 0; j < 4 ; j++)
//         {
//             a[j] = (a[j] + 7) % 10;
//         }
//         temp1 = a[0];
//         temp2 = a[1];
//         a[0] = a[2];
//         a[1] = a[3];
//         a[2] = temp1;
//         a[3] = temp2;
//         int ans;
//         ans = a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3];
//         cout << ans << " ";
//     }


//     m[0] = mm / 1000;
//     m[1] = (mm % 1000) / 100;
//     m[2] = (mm % 100) / 10;
//     m[3] = (mm % 10) / 1;
//     tem1 = m[0];
//     tem2 = m[1];
//     m[0] = m[2];
//     m[1] = m[3];
//     m[2] = tem1;
//     m[3] = tem2;

//     for (int i = 0; i < 4; i++)
//     {
//         if (m[i] >= 7)
//             m[i] = m[i] - 7;
//         else 
//             m[i] = m[i] + 10 - 7; 
//     }
//     // cout << endl << m[0] << endl << m[1] << endl << m[2] << endl << m[3] << endl;
//     mm = m[0] * 1000 + m[1] * 100 + m[2] * 10 + m[3];
//     cout << mm;

//     return 0;
// }

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
    //Please input your code
    int r;
    double S, V;
    const double pi = 3.14;

    cin >> r;
    S = 4 * pi * r * r;
    V = ((4 / 3) * pi * r * r * r);//4/3是两个整数相除保留1啦！
    cout << fixed << setprecision(1);
    cout << "半径为" << r << "的球体积为" << V << endl;
    cout << "半径为" << r << "的球体表面积为" << S << endl;
    return 0;
}