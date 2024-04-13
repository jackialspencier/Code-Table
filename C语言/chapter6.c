//6.1再探while循环
/* summing.c —— 根据用户键入的整数求和 */
// #include <stdio.h>
// int main(void)
// {
//     long num;
//     long sum = 0L;
//     int status;

//     printf("Please enter an integer to be summed ");
//     printf("(q to quit): ");
//     status = scanf("%ld", &num);
//     while (status == 1)
//     {
//         sum = sum + num;
//         printf("Please enter next integer (q to quit)");
//         status = scanf("%ld", &num);
//     }
//     printf("Those integers sum to %ld.\n", sum);

//     return 0;
// }



//6.1.1程序注释

//6.1.2C风格读取循环
//当获取值和判断值都成功
//   处理该值

//6.2while语句
//6.2.1终止while循环
//6.2.2何时终止while循环
//when.c —— 何时退出循环
// #include <stdio.h>
// int main(void)
// {
//     int n = 5;

//     while (n < 7)
//     {
//         printf("n = %d\n", n);
//         n++;
//         printf("Now n = %d\n", n);
//     }
//     printf("The loop has finished.\n");

//     return 0;
// }

/* while.c —— 注意花括号的使用 */
/* 糟糕的代码创建了一个无限循环 */
// #include <stdio.h>
// int main(void)
// {
//     int n = 0;

//     while (n < 3)
//         printf("n is %d\n", n);
//         n++;
//         printf("That's all this program does.\n");

//         return 0;
// }

/* while2.c —— 注意分号的位置 */
// #include <stdio.h>
// int main(void)
// {
//     int n = 0;

//     while (n++ < 3);
//         printf("n is %d.\n", n);
//     printf("That's all the program does.\n");

//     return 0;
// }

//cmpflt.c —— 浮点数比较
// #include <stdio.h>
// #include <math.h>
// int main(void)
// {
//     const double ANSWER = 3.14159;
//     double response;

//     printf("What is the value of pi?\n");
//     scanf("%lf", &response);
//     while(fabs(response - ANSWER) > 0.0001)
//     {
//         printf("Try again!\n");
//         scanf("%lf", &response);
//     }
//     printf("Close enough!\n");

//     return 0;
// }

//6.3.1什么是真
/* t_and_f.c —— C中的真和假的值 */
// #include <stdio.h>
// int main(void)
// {
//     int true_val, false_val;

//     true_val = (10 > 2);
//     false_val = (10 == 2);
//     printf("true = %d; false = %d \n", true_val, false_val);

//     return 0;
// }

//6.3.2其他真值
// truth.c —— 哪些值为真
// #include <stdio.h>
// int main(void)
// {
//     int n = 3;

//     while (n)
//         printf("%2d is true\n", n--);
//     printf("%2d is false\n", n);

//     n = -3;
//     while (n)
//         printf("%2d is true\n", n++);
//     printf("%2d is false\n", n);

//     return 0;
// }

//6.3.3真值的问题 
//trouble.c —— 误用=会导致无限循环

// #include <stdio.h>
// int main(void)
// {
//     long num;
//     long sum = 0L;
//     int status;

//     printf("Please enter an integer to be summed");
//     printf("(q to quit): ");
//     status = scanf("%ld", &num);
//     while (status = 1)
//     {
//         sum = sum + num;
//         printf("Please enter next integer to be summed (q to quit): ");
//         status = scanf("%ld", &num);
//     }
//     printf("Those integers sum to %ld", sum);

//     return 0;
// }

//6.3.4新的布尔类型
// boolean.c —— 使用_Bool类型的变量variable
// #include <stdio.h>
// int main(void)
// {
//     long num;
//     long sum = 0L;
//     _Bool input_is_good;

//     printf("Please enter an integer to be summed \n");
//     printf("(q to quit): \n");
//     input_is_good = (scanf("%ld", &num) == 1);
//     while(input_is_good)
//     {
//         sum = sum + num;
//         printf("Please enter next integer to be summbed (q to quit): \n");
//         input_is_good = (scanf("%ld", &num) == 1);
//     }
//     printf("Those integers sum to %ld.\n", sum);

//     return 0;

//6.3.5优先级和关系运算符

//6.4不确定循环与计数循环
//sweetie1.c —— 一个计数循环
// #include <stdio.h>
// int main(void)
// {
//     const int NUMBER = 22;
//     int count = 1;
//     while (count < NUMBER)
//     {
//         printf("Be my Valentine!\n");
//         count++;
//     }

//     return 0;
// }

//6.5for循环
//程序清单6.11 sweetie.c程序
// sweetie2.c —— 使用for的计数循环
// #include <stdio.h>
// int main(void)
// {
//     const int NUMBER = 22;
//     int count;

//     for (count = 1; count <= NUMBER; count++)
//         printf("Be my valentine!\n");

//     return 0;
// }

//程序清单6.12 —— 使用for循环创建一个立方表
// #include <stdio.h>
// int main(void)
// {
//     int num;

//     printf("    n    n cubed\n");
//     for(num = 1; num <= 6; num++)
//         printf("%5d %5d\n", num, num*num*num);
    
//     return 0;
// }

/* for_down.c */
// #include <stdio.h>
// int main(void)
// {
//     int secs;

//     for (secs = 5; secs > 0; secs--)
//         printf("%d seconds!\n", secs);
//     printf("We have ignition!\n");

//     return 0;
// }

//计数器递增2.10等
/* for_13s.c */
// #include <stdio.h>
// int main(void)
// {
//     int n;

//     for (n = 2; n < 60; n = n + 13)
//         printf("%d \n", n);

//     return 0;
// }

/* for_char.c */
// #include <stdio.h>
// int main(void)
// {
//     char ch;

//     for (ch = 'a'; ch <= 'z'; ch++)
//         printf("The ASCII value for %c is %d.\n", ch, ch);

//     return 0;
// }

/* for_cube.2 */
// #include <stdio.h>
// int main(void)
// {
//     int num;

//     printf("    n    n cubed\n");
//     for (num = 1; num*num*num <= 216; num++)
//         printf("%5d %5d\n", num, num*num*num);

//     return 0;
// }

/* for_geo.c */
// #include <stdio.h>
// int main(void)
// {
//     double debt;
//     for (debt = 100.0; debt <= 150; debt = debt*1.1)//记得把新的值赋给debt。
//         printf("Your debt is now %.2f.\n", debt);
    
//     return 0;
// }

/* for_wild.c */
// #include <stdio.h>
// int main(void)
// {
//     int x;
//     int y = 55;

//     for (x = 1; y <= 75; y = (++x * 5) + 50)
//         printf("%10d %10d\n",x , y);
    
//     return 0;
// }

/* for_none.c */
// #include <stdio.h>
// int main(void)
// {
//     int ans, n;
    
//     ans = 2;
//     for (n = 3; ans <= 25;)
//         ans = ans * n;
//     printf("n = %d; ans = %d.\n", n, ans);

//     return 0;
// }

/* for_show.c */
// #include <stdio.h>
// int main(void)
// {
//     int num = 0;
    
//     for (printf("Keep entering numbers!\n"); num != 6;)
//         scanf("%d", &num);
//     printf("That's the one I want!\n");

//     return 0;
// }

//6.6其他赋值运算符

//6.7逗号与运算符
//postage.c —— 一类邮资
// #include <stdio.h>
// int main(void)
// {
//     const int FIRST_OZ = 46;
//     const int NEXT_OZ = 20;
//     int ounces, cost;

//     printf(" ounces cost\n");
//     for (ounces = 1, cost = FIRST_OZ; ounces <= 16; ounces++, cost += NEXT_OZ)
//         printf("%5d $%4.2f\n", ounces, cost / 100.0);
    
//     return 0;
// }

//6.7.1当zeno遇到for循环
/* zeno.c —— 求序列的和 */
// #include <stdio.h>
// int main(void)
// {
//     int t_ct;
//     double time, power_of_2;
//     int limit;

//     printf("Enter a number of terms you want: ");
//     scanf("%d", &limit);
//     for (time = 0, power_of_2 = 1, t_ct = 1; t_ct <= limit; t_ct++, power_of_2 *= 2.0)
//     {
//         time += 1.0 / power_of_2;
//         printf("time = %f when terms = %d.\n", time, t_ct);
//     }

//     return 0;
// }

//6.8出口条件循环
/* do_while.c —— 出口条件循环 */
// #include <stdio.h>
// int main(void)
// {
//     const int secret_code = 13;
//     int code_entered;

//     do
//     {
//         printf("To enter the triskaidekaphobia therapy club,\n");
//         printf("please enter the secret code number: ");
//         scanf("%d", &code_entered);    /* code */
//     } while (code_entered != secret_code/* condition */);
//     printf("Congratulations! You are cured!\n");
    
//     return 0;
// }

/* entry.c —— 出口循环条件 */
// #include <stdio.h>
// int main(void)
// {
//     const int secret_code = 13;
//     int code_entered;

//     printf("To enter the triskaidekaphobia therapy club,\n");
//     printf("Please enter the secret code number: ");
//     scanf("%d", &code_entered);
//     while (code_entered != secret_code)
//     {
//         printf("To enter the trikaidekaphobia therapy club,\n");
//         printf("Please enter the secret code number: ");
//         scanf("%d", &code_entered);
//     }

//     printf("Congratulations! You are cured!\n");

//     return 0;
// }

//6.9如何选择循环

//6.10嵌套循环
/* rows1.c —— 使用嵌套循环 */
// #include <stdio.h>
// #define ROWS 6
// #define CHARS 10
// int main(void)
// {
//     int row;
//     char ch;

//     for (row = 0; row < ROWS; row++)
//     {
//         for (ch = 'A'; ch < ('A' + CHARS); ch++)
//         printf("%c", ch);
//         printf("\n");
//     }

//     return 0;
// }

//6.10.1程序分析
//rows2.c a—— 依赖外部循环的嵌套循环
// #include <stdio.h>
// int main(void)
// {
//     const int ROWS = 6;
//     const int CHARS = 6;
//     int row;
//     char ch;

//     for (row = 0; row < ROWS; row++)
//     {
//         for (ch = ('A' + row); (ch < 'A' + CHARS); ch++)
//             printf("%c", ch);
//         printf("\n");
//     }

//     return 0;
// }

//scores_in.c —— 使用循环处理数组（尝试）
// #include <stdio.h>
// #define SIZE 10
// #define PAR 72
// int main(void)
// {
//     int index, score[SIZE];
//     int sum = 0;
//     float average;

//     printf("Enter %d golf scores:\n", SIZE);
//     for (index = 0; index < 10; index++)
//     {
//         scanf("%d", &score[index]);
//         sum += score[index];
//     }
//     average = sum / 10.0;
//     printf("The summary of tem scores is %d.\n", sum);
//     printf("The average of ten scores is %.2f.\n", average);

//     return 0;
// }

//scores_in.c —— 使用循环处理数组
// #include <stdio.h>
// #define SIZE 10
// #define PAR 72
// int main(void)
// {
//     int index, score[SIZE];
//     int sum = 0;
//     float average;

//     printf("Enter %d golf scores:\n", SIZE);
//     for (index = 0; index < SIZE; index++)
//         scanf("%d", &score[index]);
//     printf("The scores read in are as follows:\n");
//     for (index = 0; index < SIZE; index++)
//         printf("%5d", score[index]);
//     printf("\n");
//     for (index = 0; index < SIZE; index++)
//         sum += score[index];
//     average = (float) sum / SIZE;
//     printf("Sum of scores = %d, average = %.2f\n", sum, average);
//     printf("That's a handicap of %.0f.\n", average - PAR);

//     return 0;
// }

// double power(double n, int p)
// {
//     double pow = 1;
//     int i;

//     for (i = 1; i <= p; i++)
//         pow *= n
    
//     return pow;
// }

//6.12使用函数返回值的循环示例
//power.c —— 计算数的整数幂
// #include <stdio.h>
// double power(double n, int p);
// int main(void)
// {
//     double x, xpow;
//     int exp;

//     printf("Enter a number and the positive integer power");
//     printf(" to which\nthe number will be raised. Enter q");
//     printf(" to quit.\n");
//     while(scanf("%lf%d", &x, &exp) == 2)
//     {
//         xpow = power (x, exp);
//         printf("%.3g to the power %d is %.5g\n", x, exp, xpow);
//         printf("Enter next pair od numbers or q to quit.\n");
//     }
//     printf("Hope you enjoyed this power trip -- bye!\n");

//     return 0;
// }

// double power(double n, int p)
// {
//     double pow = 1;
//     int i;

//     for (i = 1; i <= p; i++)
//         pow *= n;
    
//     return pow;
// }

//6.12.1程序分析
//6.12.2使用带返回值的函数