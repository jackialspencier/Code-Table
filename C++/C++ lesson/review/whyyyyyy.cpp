// #include <iostream>
// #include <cstring>
// using namespace std;
// int setBigInt(const char *s1, char *s)
// {
//     // 从字符串常量到数组/指针
//     for (int i = 0; i < 128; ++i) s[i] = '0'; // 先将 s 变成 0
//     for (int i = strlen(s1) - 1; i >= 0; --i)
//     {
//         if (s1[i] > '9' || s1[i] < '0')
//         {
//             cerr << "字符串不是数字！" << endl;
//             return -1;
//         }
//         s[i] = s1[i];
//     }
//     return 0;
// }

// // 计算大整数 p1 + p2 结果保存在 s 中，三个数组长度均不超 128
// void addBigInt(const char *p1, const char *p2, char *s)
// {
//     int carry = 0; // 进位
//     for (int i = 0; i < 128; ++i)
//     {
//         int sum = p1[i] - '0' + p2[i] - '0' + carry;
//         carry = sum / 10;
//         s[i] = sum % 10 + '0';
//     }
//     if (carry > 0) { cerr << "数太大了！" << endl; exit(-1); }
// }

// void printBigInt(const char *s)
// {
//     bool printed = false;
//     for (int i = 127; i >= 0; --i)
//     {
//         if (s[i] == '0' && !printed) continue; // 跳过前置 0
//         cout << s[i];
//         printed = true;
//     }
//     cout << endl;
// }

// int main()
// {
//     char num1[128], num2[128], sum[128];

//     setBigInt("1233", num1);
//     setBigInt("345", num2);

//     printBigInt(num1);
//     printBigInt(num2);
//     addBigInt(num1, num2, sum);
//     printBigInt(sum);

//     return 0;
// }

// int a[3][4];

// int (*p)[4];
// int * 1;

// for (p = a; p < a + 3; p++){}
//     for (q = (*p); q < *p + 4; q++)
//         cout << *q << '\t';
//     cout << endl
// }

#include <iostream>
using namespace std;
// struct StudentT {
// 	int a;
// 	char name[20];
// };
// StudentT &getStudentData() {
// 	StudentT *student = new StudentT;
// 	return *student;
// }
int main() {
	// struct StudentT *p;
	// p = new /*struct*/ StudentT;
	// StudentT &s1 = getStudentData();	// 用完记得释放
	// delete &s1;
	// return 0;
    // // int * p const;
    // int x = 1, y = 3;
    // int const * p = &x;
    // p = &y;// 可以
    // *p = y;// 不行

}

