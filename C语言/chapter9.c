//chapter9.c
//程序清单9.2
/* lethead2.c */
// #include <stdio.h>
// #include <string.h>
// #define NAME "GIGANTHINK, INC"
// #define ADDRESS "101 Megabuck Plaza"
// #define PLACE "Megapolis, CA 94904"
// #define WIDTH 40
// #define SPACE ' '

// void show_n_char(char ch, int num);

// int main(void)
// {
//     int spaces;

//     show_n_char('*', WIDTH);
//     putchar('\n');

//     show_n_char(SPACE, 12);
//     printf("%s\n", NAME);

//     spaces = (WIDTH - strlen(ADDRESS)) / 2;
//     show_n_char(SPACE, spaces);
//     printf("%s\n", ADDRESS);
    
//     show_n_char(SPACE, (WIDTH - strlen(PLACE))/2);
//     printf("%s\n", PLACE);

//     show_n_char('*', WIDTH);
//     putchar('\n');

//     return 0;
// }

// /* show_n_char()函数的定义 */
// void show_n_char(char ch, int num)//需要在主函数中计算/体现，更清晰。
// {
//     int count;

//     for (count = 1; count <= num; count++)
//         putchar(ch);
// }

//9.1.4 定义带形式参数的函数

//9.1.5 声明带形式参数函数的原型

//9.1.6调用带实际参数的函数

//9.1.7黑盒视角

//9.1.8使用return从函数中返回值
/*lesser.c —— 找出两个整数中的一个 */
// #include <stdio.h>
// int imin(int, int);

// int main(void)
// {
//     int evil1, evil2;

//     printf("Enter a pair of integers (q to quit):\n");
//     while (scanf("%d %d", &evil1, &evil2))
//     {
//         printf("The lesser of %d and %d is %d.\n", evil1, evil2, imin(evil1, evil2));
//         printf("Enter a pair of integers(q to quit):\n");
//     }
//     printf("Bye.\n");

//     return 0;
// }

// int imin(int n, int m)
// {
//     int min;
    
//     if(n < m)
//         min = n;
//     else
//         min = m;

//     return min;
// }

// #include <stdio.h>
// int imin(int m, int n);
// int main(void)
// {
//     int evil1, evil2;

//     printf("Enter a pair of integers(q to quit):\n");
//     while(scanf("%d %d", &evil1, &evil2))
//     {
//         printf("The lesser of %d and %d is %d.\n", evil1, evil2, imin(evil1, evil2));
//         printf("Enter a pair of integers(q to quit):\n");
//     }
//     printf("Bye.\n");

//     return 0;
// }
// /*返回最小值的函数，第2个版本*/
// int imin(int m, int n)
// {
//     return (m > n)? n : m;//return ((n < m)? n : m);可以用括号把返回值括起来
// }

//9.1.9 函数类型

//9.2 ANSI C函数原型

//9.2.1问题所在
/* misuse.c —— 错误地使用函数 */
// #include <stdio.h>
// int imax(int, int);

// int main(void)
// {
//     printf("The maximum of %d and %d is %d.\n", 3, 5 ,imax(3, 5));
//     printf("The maximum of %d and %d is %d.\n", 3, 5, imax(3.9, 5.4));//3.0和5.0
//     return 0;
// }

// int imax(n, m)
// int n, m;
// {
//     return ((n > m) ? n : m);
// }

//9.2.3无参数和未指定参数
// int printf(const char *, ...);

//9.2.4函数原型的优点
//下面这行代码即式函数定义，也是函数原型
// int imax(int a, int b){return a > b? a : b;}

//9.3 递归
//9.3.1演示递归
//程序清单9.6 recur.c 程序
/* recur.c -- 递归演示 */
// #include <stdio.h>
// void up_and_down(int);

// int main(void)
// {
//     up_and_down(1);
//     return 0;
// }

// void up_and_down(int n)
// {
//     printf("Level %d: n location %p\n", n, &n);
//     if (n < 4)
//         up_and_down(n + 1);
//     printf("LEVEL %d: n location %p\n",n, &n);
// }

//9.3.2 递归的基本原理

//9.3.3 尾递归
//factor.c -- 使用循环和递归计算阶乘
// #include <stdio.h>
// long fact(int n);
// long rfact(int n);
// int main(void)
// {
//     int num;

//     printf("This program calculates factorials.\n");
//     printf("Enter a value in the range 0-12 (q to quit):\n");
//     while (scanf("%d", &num) == 1)
//     {
//         if (num < 0)
//             printf("No negative numbers, please.\n");
//         else if (num > 12)
//             printf("Keep input under 13.\n");
//         else
//         {
//             printf("loop: %d factorial = %ld.\n", num, fact(num));
//             printf("recursion: %d factorial = %ld.\n", num, rfact(num));
//         }
//         printf("Enter a value in the range of 0-12(q to quit):\n");
//     }
//     printf("Bye.\n");

//     return 0;
// }

// long fact(int n)
// {
//     long ans;

//     for (ans = 1; n > 1; n--)
//         ans *= n;
    
//     return ans;
// }

// long rfact(int n)
// {
//     long rans = 1;
    
//     rans *= n;
//     if (n > 1)
//         rfact(n--);
    
//     return rans;//why！！！
// }

// long rfact(int n)
// {
//     long ans;

//     if(n > 0)
//         ans = n * rfact(n - 1);//每次ans都是独立的，需要返回值来传递。
//     else
//         ans = 1;
    
//     return ans;
// }

//9.3.4 递归和倒序计算
//程序清单9.8  binary.c 程序
/* binary -- 以二进制形式打印整数 */
// #include <stdio.h>
// void to_binary(unsigned long n);
// int main(void)
// {
//     unsigned long number;
    
//     printf("Enter an integer(q to quit):\n");
//     while (scanf("%lu", &number) == 1)
//     {
//         printf("Binary equivalent: ");
//         to_binary(number);
//         putchar('\n');
//         printf("Enter an integer (q to quit):\n");     
//     }
//     printf("Done.\n");

//     return 0;
// }

// void to_binary(unsigned long n)
// {
//     int r;

//     r = n % 2;
//     if (n >= 2)
//         to_binary(n / 2);
//     putchar(r == 0? '0' : '1');

//     return;
// }
//这个二进制转换方法需要注意。

//9.3.5 递归的优缺点

//9.4编译多源代码文件的程序
//9.4.1 UNIX
//9.4.2 LINUX
//9.4.3 DOS命令行编译器
//9.4.4 Windows和苹果的IDE编译器
//9.4.5使用头文件











/* usehotel.c -- 房间费程序 */
/* 与程序清单9.10一起编译    */
// #include <stdio.h>
// #include "hotel.h"
// int main(void)
// {
//     int nights;
//     double hotel_rate;
//     int code;

//     while ((code = menu()) != QUIT)
//     {
//         switch (code)
//         {
//             case 1: hotel_rate = HOTEL1;
//                     break;
//             case 2: hotel_rate = HOTEL2;
//                     break;
//             case 3: hotel_rate = HOTEL3;
//                     break;
//             case 4: hotel_rate = HOTEL4;
//                     break;
//             default: hotel_rate = 0.0;
//                      printf("Oops!\n");
//                      break;
//         }
//         nights = getnights();
//         show_price(hotel_rate, nights);
//     }
//     printf("Thank you and goodbye.\n");

//     return 0;
// }

// //程序清单9.10 hotel.c函数支持模块
// /* hotel.c —— 酒店管理函数 */
// #include <stdio.h>
// #include "hotel.h"
// int menu(void)
// {
//     int code, status;

//     printf("\n%s%s\n", STARS, STARS);
//     printf("Enter the number of the desired hotel: \n");
//     printf("1) Fairfield Arms              2) Hotel Olympics\n");
//     printf("3) Chertworthy Plaza           4) The Stockton\n");
//     printf("5)quit\n");
//     printf("%s%s\n", STARS, STARS);
//     while (((status = scanf("%d", &code)) != 1) || (code < 1 || code >5));
//     {
//         if (status != 1)
//             scanf("%*s");//星昊是什么意思哇
//         printf("Enter an integer from 1 to 5, please.\n");
//     }

//     return code;
// }

// int getnights(void)
// {
//     int nights;

//     printf("How many nights are needed?");
//     while (scanf("%d", &nights != 1))
//     {
//         scanf("%*s");//为什么之前那个函数内不想这样不检验是否读取到直接以防万一？
//         printf("Please enter an integer, such as 2.\n");
//     }
//     return nights;
// }

// void showprice(double rate, int nights)
// {
//     int n;
//     double total = 0.0;
//     double factor = 1.0;

//     for (n = 1; n <= nights; n++, factoe *= DISCOUNT)
//         total += rate * factor;
//     printf("The total cost will be $%0.2f.\n");
// }

// /* hotel.h -- 符号常量和hotel.c中所有函数的原型 */
// #define QUIT 5
// #define HOTEL1 180.00
// #define HOTEL2 225.00
// #define HOTEL3 255.00
// #define HOTEL4 355.00
// #define DISCOUNT 0.95
// #define STARS "**************************************"

// int menu(void);
// int getnights(void);
// void showprice(double rate, int nights);








//9.5 查找地址：&运算符
// 程序清单9.12 lockcheck.c 程序
/* lockcheck.c -- 查看变量被储存在何处 */
// #include<stdio.h>
// void mikado(int);
// int main(void)
// {
//     int pooh = 2, bah = 5;

//     printf("In main(), pooh = %d and &pooh = %p\n", pooh, &pooh);
//     printf("In main(), bah = %d and &bah = %p\n", bah, &bah);
//     mikado(pooh);

//     return 0;
// }

// void mikado(int bah)
// {
//     int pooh = 10;

//     printf("In mikado(), pooh = %d, &pooh = %p\n", pooh, &pooh);
//     printf("In mikado(), bah = %d, &bah = %p\n", bah, &bah);
// }

//9.6 更改主调函数中的变量
//程序清单9.13 swap1.c 程序
/* swap1.c -- 第一个版本的交换函数 */
// #include <stdio.h>
// void intchange(int u, int v);
// int main(void)
// {
//     int x = 5, y = 10;

//     printf("Originally x = %d and y = %d.\n", x, y);
//     intchange(x, y);
//     printf("Now x= %d and y = %d.\n", x, y);

//     return 0;
// }
// void intchange(int u, int v)
// {
//     int temp;

//     printf("Originally u = %d and v = %d.\n", u, v);
//     temp = u;
//     u = v;
//     v = temp;
//     printf("Now u = %d and v = %d.\n", u, v);
// }

//9.7 指针简介
//9.7.1 间接运算符
//9.7.2 声明指针
//9.7.3 使用指针在函数间通信
// 程序清单9.15 swap3.c程序
// #include <stdio.h>
// void interchange(int * u, int * v);

// int main(void)
// {
//  int x = 5, y = 10;
//  printf("Originally x = %d and y = %d.\n", x, y);
//  interchange(&x, &y);
//  printf("Now x = %d and y = %d.\n", x, y);

//     return 0;
// }

// void interchange(int * u, int * v)
// {
//     int temp;
//     temp = *u;
//     *u = *v;
//     *v = temp;
// }