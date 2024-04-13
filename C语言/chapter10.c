//第10章 数组和指针

//10.1数组

//10.1.1 初始化数组
//程序清单10.1 day_mon1.c程序
/* day_mon1.c -- 打印每个月的天数 */
// #include <stdio.h>
// #define MONTHS 12
// int main(void)
// {
//     int days[MONTHS] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//     int index;

//     for (index = 0; index < MONTHS; index++)
//         printf("Month %2d has %2d days.\n", index+1, days[index]);

//     return 0;
// }

//程序清单10.2 no_data.c 程序
/* no_data.c -- 为初始化数组 */
// #include <stdio.h>
// #define SIZE 4
// int main(void)
// {
//     int no_data[SIZE];
//     int i;

//     printf("%2s%14s\n", "i", "no_data[i]");
    
//     for (i = 0; i < SIZE; i++)
//         printf("%2d%14d\n", i, no_data[i]);
    
//     return 0;
// }

/* some_data.c -- 部分初始化数组 */
// #include <stdio.h>
// #define SIZE 4
// int main(void)
// {
//     int some_data[SIZE] = {1492, 1066};
//     int i;

//     printf("%2s%14s\n", "i", "some_data[i]");
//     for (i = 0; i < SIZE; i++)
//         printf("%2d%14d\n", i, some_data[i]);

//     return 0;
// }

//程序清单10.4 day_mon2.c 程序
/*  day_mon2.c -- 让编译器计算元素个数 */
// #include <stdio.h>
// int main(void)
// {
//     const int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31 };
//     int index;

//     for (index = 0; index < sizeof days / sizeof days[0]; index++)
//         printf("Month %2d has %2d days.\n", index+1, days[index]);

//     return 0;

// }

//10.1.2 指定初始化器（C99）
//程序清单10.5 designate.c 程序
// desianate.c -- 使用指定初始化器
// #include <stdio.h>
// #define MONTHS 12
// int main(void)
// {
//     int days[MONTHS] = {31, 28, [4] = 31, 30, 31, [1] = 29};
//     int i;

//     for (i = 0; i < MONTHS; i++)
//         printf("%2d    %d\n", i + 1, days[i]);

//     return 0;
// }

//10.1.3 给数组赋值
//程序清单10.6 bounds.c 程序
//bounds.c —— 数组下标越界
// #include <stdio.h>
// #define SIZE 4
// int main(void)
// {
//     int value1 = 44;
//     int arr[SIZE];
//     int value2 = 88;
//     int i;

//     printf("value1 = %d, vlue2 = %d\n", value1, value2);
//     for (i = -1; i <= SIZE; i++)
//         arr[i] = 2 * i + 1;
//     for (i = -1; i < 7; i++)
//         printf("%2d %d\n", i, arr[i]);
//     printf("value1 = %d, value2 = %d\n", value1, value2);
//     printf("address of arr[-1]: %p\n", &arr[-1]);
//     printf("address of arr[4]: %p\n", &arr[4]);
//     printf("address of value1: %p\n", &value1);
//     printf("address of value2: %p\n", &value2);

//     return 0;
// }

//10.1.5 指定数组的大小

//10.2 多维数组
//程序清单10.7 rain.c 程序
/* rain.c -- 计算每年的总降水量，年平均降水量，月平均降水量 */
// #include <stdio.h>
// #define MONTHS 12
// #define YEARS   5
// int main(void)
// {
//     const float rain[YEARS][MONTHS] =
//     {
//         { 4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6 },
//         { 8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.3 },
//         { 9.1, 8.5, 6.7, 4.3, 2.1, 0.8, 0.2, 0.2, 1.1, 2.3, 6.1, 8.4 },
//         { 7.2, 9.9, 8.4, 3.3, 1.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 6.2 },
//         { 7.6, 5.6, 3.8, 2.8, 3.8, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 5.2 }
//     };
//     int year, month;
//     int subtot, total;

//     printf("YEAR       RAINFALL  (inches)");
//     for (year = 0, total = 0; year < YEARS; year++)
//     {
//         for (month = 0, subtot = 0; month < MONTHS; month++)
//             subtot += rain[year][month];
//         printf("%5d%15.1f\n", 2010 + year, subtot);
//         total += subtot;
//     }
//     printf("\nThe yearly average is %.1f inches.\n\n", total / YEARS);
//     printf("MONTHLY AVERAGES:\n\n");
//     printf(" Jan  Feb  Mar Apr May Jun Jul Aug Sep Oct ");
//     printf(" Nov  Dec\n");
//     for (month = 0; month < MONTHS; month++)
//     {
//         for (year = 0, subtot = 0; year < YEARS; year++)
//             subtot += rain[year][month];
//         printf("%4.1f ", subtot / YEARS);
//     }
//     printf("\n");

//     return 0;
// }

//10.2.1 二维化初始数组

//10.2.2 其他多维数组

//10.3 指针和数组
//程序清单10.8 pnt_add.c 程序
//pnt_add.c -- 指针地址
// #include <stdio.h>
// #define SIZE 4
// int main(void)
// {
//     short dates[SIZE];
//     short * pti;
//     short index;
//     double bills[SIZE];
//     double * ptf;

//     pti = dates;
//     ptf = bills;
//     printf("%23s %15s\n", "short", "double");
//     for (index = 0; index < SIZE; index++)
//     printf("pointers + %d: %10p %10p\n", index, pti + index, ptf + index); 

//     return 0;   
// }

/* day_mon3.c -- uses pointer notation */
// #include <stdio.h>
// #define MONTHS 12

// int main(void)
// {
//     int days[MONTHS] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//     int index;

//     for (index = 0; index < MONTHS; index++)
//         printf("Month %2d has %d days.\n", index + 1, *(days + index));

//     return 0;
// }

//10.4 函数、数组和指针
// sum arr1.c -- 数组元素之和
// 如果编译器不支持%zd，用%u或%lu替换它
//程序清单10.10 sum_aee1.c 程序
//sum_arr1.c -- 数组元素之和
//如果编译器不支持%zd，用%u或%lu替换它
// #include <stdio.h>
// #define SIZE 10
// int sum (int ar[], int n);
// int main(void)
// {
//     int marbles[SIZE] = { 20, 10, 5, 39, 4, 16, 19, 26, 31, 20 };
//     long answer;

//     answer = sum(marbles, SIZE);
//     printf("The total number of marbles is %ld.\n", answer);
//     printf("The size of marbles is %zd bytes.\n", sizeof marbles);

//     return 0;
// }

// int sum(int ar[], int n)
// {
//     int i;
//     int total = 0;

//     for (i = 0; i < n; i++)
//         total += ar[i];
//     printf("The size of ar is %zd bytes.\n", sizeof ar);

//     return 0;
// }

//10.4.1 使用指针形参
//程序清单10.11 sum_arr2.c 程序
/* sum_arr2.c -- 数组元素之和 */
// #include <stdio.h>
// #define SIZE 10
// int sump(int * start, int * end);
// int main(void)
// {
//     int marbles[SIZE] = { 20, 10, 5, 39, 4, 16, 19, 26, 31, 20 };
//     long answer;

//     answer = sump(marbles, marbles + SIZE);
//     printf("The total number of marbles is %ld.\n", answer);

//     return 0;
// }

// int sump(int * start, int * end)
// {
//     int total = 0;
    
//     while(start < end)
//     {
//         total += *start;
//         start++;
//     }
    
//     return total;
// }

//程序清单10.12 order.c 程序
/* order.c -- 指针运算中的优先级 */
// #include <stdio.h>
// int data[2] = {100, 200};
// int moredata[2] = {300, 400};
// int main(void)
// {
//     int * p1, *p2, *p3;

//     p1 = p2 = data;
//     p3 = moredata;
//     printf("   *p1 = %d,   *p2 = %d,   *p3 = %d\n", *p1, *p2, *p3);
//     printf("*p1++ = %d,*++p2 = %d, (*p3)++ = %d\n", *p1++, *++p2, (*p3)++);
//     printf("   *p1 = %d,   *p2 = %d,   *p3 = %d\n", *p1, *p2, *p3);

//     return 0;
// }

//p3好奇特。

// #include <stdio.h>
// int main(void)
// {
//     int i;

//     i=1;
//     printf("i = %d\n", i++);//用完再递增，打印的是1.
//     printf("%d\n",i);

//     return 0;
// }

//10.4.2指针表示法和数组表示法

//10.5指针操作
//程序清单10.13 ptr_ops.c 程序
// ptr_ops.c -- 指针操作
// #include <stdio.h>
// int main(void)
// {
//     int urn[5] = { 100, 200, 300, 400, 500 };
//     int * ptr1, * ptr2, * ptr3;

//     ptr1 = urn;
//     ptr2 = &urn[2];
//     printf("pointer value, dereferenced pointer, pointer adrress:\n");
//     printf("ptr1 = %p, *ptr1 = %d, &ptr1 = %p\n", ptr1, *ptr1, &ptr1);
//     ptr3 = ptr1 + 4;//指针加法
//     printf("\nadding an int to a pointer:\n");
//     printf("ptr1 + 4 = %p, *(ptr1 + 4) = %d\n", ptr1 + 4, *(ptr1 + 4));
//     ptr1++;//递增指针；
//     printf("\nvalues after ptr1++:\n");
//     printf("ptr1 = %p, *ptr1 = %d, &ptr1 = %p\n", ptr1, *ptr1, &ptr1);
//     ptr2--;//递减指针
//     printf("\nvalues after ptr2--\n");
//     printf("ptr2 = %p, *ptr2 = %d, &ptr2 = %p", ptr2, *ptr2, &ptr2);
//     --ptr1;//恢复初始值
//     ++ptr2;//恢复初始值
//     printf("\nPointers reset to original values:\n");
//     printf("ptr1 = %p, ptr2 = %p\n",ptr1, ptr2);
//     //一个指针减去另一个指针
//     printf("\nsubtracting one pointer from another:\n");
//     printf("ptr2 = %p, ptr1 = %p, ptr2 - ptr1 = %td\n", ptr2, ptr1, ptr2 - ptr1);
//     //一个指针减去一个整数
//     printf("\nsubtracting an int from a pointer:\n");
//     printf("ptr3 = %p, ptr3 - 2 =%p\n", ptr3, ptr3 - 2);

//     return 0;
// }

//10.6 保护数组中的数据
//10.6.1对形式参数使用const
//程序清单10.14 arf.c 程序
/* arf.c -- 处理数组的函数 */
// #include <stdio.h>
// #define SIZE 5
// void show_array(const double ar[], int n);
// void mult_array(double ar[], int n, double mult);
// int main(void)
// {
//     double dip[SIZE] = { 20.0, 17.66, 8.2, 15.3, 22.22 };

//     printf("The original dip array:\n");
//     show_array(dip, SIZE);
//     mult_array(dip, SIZE, 2.5);
//     printf("The dip array after calling mult_array():\n");
//     show_array(dip, SIZE);

//     return 0;
// }

// /* 显示数组的内容 */
// void show_array(const double ar[], int n)
// {
//     int i;

//     for (i = 0; i < n; i++)
//         printf("%8.3f ", ar[i]);
//     putchar('\n');
// }
// /* 把数组的每个元素都乘以相同的值 */
// void mult_array(double ar[], int n, double mult)
// {
//     int i;

//     for (i = 0; i < n; i++)
//         ar[i] *= mult;
// }

//10.7 指针和多维数组
//程序清单10.15 zippo1.c 程序
// #include <stdio.h>
// int main(void)
// {
//     int zippo[4][2] = {{ 2, 4 }, { 6, 8 }, { 1, 3 }, { 5, 7 }};

//     printf("zippo = %p,       zippo + 1 = %p\n", zippo, zippo + 1);
//     printf("zippo[0] = %p, zippo[0] + 1 = %p\n", zippo[0], zippo[0] + 1);
//     printf("  *zippo = %p, *zippo + 1 = %p", *zippo, *zippo + 1);
//     printf("zippo[0][0] = %d\n", zippo[0][0]);
//     printf("*zippo[0] = %d\n", *zippo[0]);
//     printf("    **zippo = %d\n", **zippo);
//     printf("     zippo[2][1] = %d\n", zippo[2][1]);
//     printf("*(*(zippo+2) + 1) = %d\n", *(*(zippo + 2) + 1));

//     return 0;
// }

//10.7.1指向多维数组
//int (* pz)[2];
//程序清单10.16 zippo2.c 程序
/* zippo2.c —— 通过指针获取zippo的信息 */
// #include <stdio.h>
// int main(void)
// {
//     int zippo[4][2] = { { 2, 4 }, { 6, 8 }, { 1, 3 }, { 5, 7 } };
//     int (*pz)[2];
//     pz = zippo;//pz和zippo是一个级别还是和zippo0一个级别呢？

//     printf("   pz = %p,    pz + 1 = %p\n", pz, pz + 1);
//     printf("pz[0] = %p, pz[0] + 1 = %p\n", pz[0], pz[0] + 1);
//     printf("  *pz = %p,   *pz + 1 = %p\n", *pz, *pz + 1);//指向一个数组的指针就是指向他的首元素吗？
//     printf("pz[0][0] = %d\n", pz[0][0]);
// }

//程序清单10.16 zippo2.c程序
/* zippo2.c —— 通过指针获取zippo的信息 */
// #include <stdio.h>
// int main(void)
// {
//     int zippo[4][2] = { { 2, 4 }, { 6, 8 }, { 1, 3 }, { 5, 7 } };
//     int (*pz)[2];
//     pz = zippo;

//     printf("   pz = %p,    pz + 1 = %p\n", pz, pz + 1);
//     printf("pz[0] = %p, pz[0] + 1 = %p\n", pz[0], pz[0] + 1);
//     printf("  *pz = %p,   *pz + 1 = %p\n", *pz, *pz + 1);
//     printf("pz[0][0] = %d\n", pz[0][0]);
//     printf("  *pz[0] = %d\n", *pz[0]);
//     printf("    **pz = %d\n", **pz);
//     printf("      pz[2][1] = %d\n", pz[2][1]);
//     printf("*(*(pz + 2) + 1) = %d\n", *(*(pz + 2)+ 1));

//     return 0;
// }

//程序清单10.17 array2d.c 程序
// #include <stdio.h>
// #define ROWS 3
// #define COLS 4
// void sum_rows(int ar[][COLS], int rows);
// void sum_cols(int [][COLS], int);//省略形参名
// int sum2d(int(*ar)[COLS], int rows);//另一种写法
// int main(void)
// {
//     int junk[ROWS][COLS] = {
//             { 2, 4, 6, 8 },
//             { 3, 5, 7, 9 },
//             { 12, 10, 8, 6 },
//     };
//     sum_rows(junk, ROWS);
//     sum_cols(junk, ROWS);
//     printf("Sum of all elements = %d\n", sum2d(junk, ROWS));

//     return 0;
// }

// void sum_rows(int ar[][COLS], int rows)
// {
//     int r;
//     int c;
//     int tot;

//     for (r = 0; r < rows; r++)
//     {
//         tot = 0;
//         for (c = 0; c < COLS; c++)
//             tot += ar[r][c];
//         printf("row %d: sum = %d\n", r, tot);
//     }
// }

// void sum_cols(int ar[][COLS], int rows)
// {
//     int r;
//     int c;
//     int tot;

//     for (c = 0; c < COLS; c++)
//     {
//         tot =0;
//         for (r = 0; r < ROWS; r++)
//             tot += ar[r][c];
//         printf("col %d: sum = %d\n", c, tot);
//     }
// }

// int sum2d(int ar[][COLS], int rows)
// {
//     int r;
//     int c;
//     int tot = 0;

//     for (r = 0; r < ROWS; r++)
//         for (c = 0; c < COLS; c++)
//             tot += ar[r][c];
    
//     return tot;
// }

//10.8 变长数组（VLA）
//程序清单10.18 vararr2d.c 程序
//varrarr2d.c -- 使用变长数组的函数
// #include <stdio.h>
// #define ROWS 3
// #define COLS 4
// int sum2d(int rows, int cols, int ar[rows][cols]);
// int main(void)
// {
//     int i, j;
//     int rs = 3;
//     int cs = 10;
//     int junk[ROWS][COLS] = {
//         { 2, 4, 6, 8 },
//         { 3, 5, 7, 9 },
//         { 12, 10, 8, 6}
//     };

//     int morejunk[ROWS - 1][COLS + 2] = {
//             { 20, 30, 40, 50, 60, 70 },
//             { 5, 6, 7, 8, 9, 10 }
//     };

//     int varr[rs][cs];

//     for (i = 0; i < rs; i++)
//         for (j = 0; j < cs; j ++)
//             varr[i][j] = i * j + j;
    
//     printf("3x5 array\n");
//     printf("Sum of all elements = %d\n", sum2d(ROWS, COLS, junk));
    
//     printf("2x6 arrays\n");
//     printf("Sum of all elements = %d\n", sum2d(ROWS - 1, COLS + 2, morejunk));

//     printf("3x10 VLA\n");
//     printf("Sum of all elements = %d\n", sum2d(rs, cs, varr));

//     return 0;
// }

//带变长数组形参的函数
// int sum2d (int rows, int cols, int ar[rows][cols])
// {
//     int r;
//     int c;
//     int tot;

//     for (r = 0; r < rows; r++)
//         for (c = 0; c < cols; c++)
//             tot += ar[r][c];
    
//     return tot;
// }

//10.9复合字面量
//程序10.19 flc.c 程序
//flc.c 有趣的常量
// #include <stdio.h>
// #define COLS 4
// int sum2d(const int ar[][COLS], int rows);
// int sum(const int ar[], int n);
// int main(void)
// {
//     int total1, total2, total3;
//     int * pt1;
//     int(*pt2)[COLS];

//     pt1 = (int[2]){ 10, 20 };
//     pt2 = (int[2][COLS]){{1, 2, 3, -9}, { 4, 5, 6, -8 }};//注意大小括号使用

//     total1 = sum(pt1, 2);
//     total2 = sum2d(pt2, 2);
//     total3 = sum((int []){ 4, 4, 4, 5, 5, 5 }, 6);
    
//     printf("total1 = %d\n", total1);
//     printf("total2 = %d\n",total2);
//     printf("total3 = %d\n",total3);

//     return 0;
// }

// int sum(const int ar[], int n)
// {
//     int i;
//     int total = 0;

//     for(i = 0; i < n; i++)
//         total += ar[i];

//     return total;
// }

// int sum2d(const int ar [][COLS], int rows)
// {
//     int r;
//     int c;
//     int tot = 0;

//     for (r = 0; r < rows; r++)
//         for (c = 0; c < COLS; c++)
//             tot += ar[r][c];
    
//     return tot;
// }

//10.10 关键概念
