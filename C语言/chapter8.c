// 8.1 单字符I/O：getchar()和putchar()
// 程序清单8.1 echo.c程序
/* echo.c —— 重复输入 */
// #include <stdio.h>
// int main(void)
// {
//     char ch;

//     while ((ch = getchar()) != '#')
//         putchar(ch);

//     return 0;
// }

// 8.2缓冲区

// 8.3结束键盘输入
// 8.3.1 文件、流和键盘输入
// 8.3.2 文件结尾
// 文件清单8.2
/* echo_eof.c —— 重复输入，直到文件结尾 */
// #include <stdio.h>
// int main(void)
// {
//     int ch;

//     while ((ch = getchar()) != EOF)
//         putchar(ch);

//     return 0;
// }

// 8.4 重定向和文件
// 8.4.1 UNIX、Linux和DOS重定向
// 1、重定向输入
// 2、重定向输出
// 3、组合重定向
// 4、注释
// file_eof.c —— 打开一个文件并显示该文件
// 不太懂。。。
//  #include <stdio.h>
//  #include <stdlib.h> //为了使用exit()
//  int main()
//  {
//      int ch;
//      FILE * fp;
//      char fname[50];//储存文件名

//     printf("Enter the name of the file: ");
//     scanf("%s", fname);
//     fp = fopen(fname, "r");//打开待读取文件（不是复制给而是赋给吗？！？）
//     if (fp == NULL)//如果失败
//     {
//         printf("Failed to open file. Bye.\n");
//         exit(1);//退出程序
//     }
//     //getc(fp)从打开的文件中获取一个字符
//     while((ch = getc(fp) != EOF))
//         putchar(ch);
//     fclose(fp);//关闭文件

//     return 0;
// }

// 8.5创建更友好的用户界面
// 8.5.1使用缓冲输入
/* guess.c —— 一个拖沓且错误的猜数字程序 */
// #include <stdio.h>
// int main(void)
// {
//     int guess = 1;

//     printf("Pick a integer from 1 to 100. I will try to guess ");
//     printf("it.\nRespond with a y if my guess is right and with");
//     printf("\nan n if it is wrong.\n");
//     printf("Uh...is your unmber %d?\n",guess);
//     while(getchar() != 'y')
//         printf("Well, then, is it %d?\n", ++guess);
//     printf("I knew I could do it!\n");

//     return 0;
// }

/* guess.c_2 */
// #include <stdio.h>
// int main(void)
// {
//     int guess = 1;
//     char response;

//     printf("Pick a number from 1 to 100. I will try to guess ");
//     printf("it.\nRespond with a y if my guess is right and with");
//     printf("\nan n if it is wrong.\n");
//     printf("Uh...is your number %d?\n", guess);
//     while((response = getchar()) != 'y')
//     {
//         if (response == 'n')
//             printf("Well, then, is it %d?\n", ++guess);
//         else
//             printf("Sorry, I understand only y or n.\n");
//         while (getchar()!='\n')
//             continue;
//     }
//     printf("I knew I could do it!\n");

//     return 0;
// }

// 8.5.2 混合数字和字符输入
//  #include <stdio.h>
//  int main(void)
//  {
//      char ch[50];
//      char chh[60];

//     scanf("%s", ch);
//     scanf("%s", chh);
//     printf("%s\n%s\n", ch, chh);

//     return 0;
// }

// 程序清单8.5 showchar1.c
/* showchar1.c —— 有较大 I/O 问题的程序 */
// #include <stdio.h>
// void display(char cr, int lines, int width);
// int main(void)
// {
//     int ch;
//     int rows, cols;

//     printf("Enter a character and two integers:\n");
//     while((ch = getchar()) != '\n')
//     {
//         scanf("%d %d", &rows, &cols);
//         display(ch, rows, cols);
//         printf("Enter another character and two intergers;\n");
//         printf("Enter a newline to quit.\n");
//     }
//     printf("Bye.\n");

//     return 0;
// }
// void display(char cr, int lines, int width)
// {
//     int row, col;
//     for (row = 1; row <= lines; row++)
//     {
//         for (col = 1; col <= width; col++)
//             putchar(cr);
//         putchar('\n');
//     }
// }

// 程序清单8.6 showchar2.c 程序
//  #include <stdio.h>
//  void display(char cr, int lines, int width);
//  int main(void)
//  {
//      int ch;
//      int rows, cols;

//     printf("Enter a character and two integers:\n");
//     while((ch = getchar()) != '\n')
//     {
//         if (scanf("%d %d", &rows, &cols) != 2)
//             break;
//         display((char)ch, rows, cols);
//         while (getchar() != '\n')
//             continue;
//         printf("Enter another character and two integers;\n");
//         printf("Enter a newline to quit.\n");
//     }
//     printf("Bye.\n");

//     return 0;
// }

// void display(char cr, int lines, int width)
// {
//     int row, col;

//     for (row = 1; row <= lines; row++)
//     {
//         for (col = 1; col <= width; col++)
//             putchar(cr);
//         putchar('\n');
//     }
// }

// 8.6输入验证
//  #include <stdio.h>
//  #include <stdbool.h>
//  //程序1
//  long get_long(void)
//  {
//      long input;
//      char ch;

//     while (scanf("%ld", input) != 1)
//     {
//         while ((ch = getchar()) != '\n')
//             putchar(ch);
//         printf(" is not an integer,\nPlease enter an ");
//         printf("integer value, such as 25, -178, or 3: ");

//         return input;
//     }
// }

// //除了返回值，和外界关系大的作为参？还是啥啊？
// _Bool bad_limits(long begin, long end, long low, long high)
// {
//     _Bool not_good = false;

//     if (begin > end)
//     {
//         printf("%ld isn't smaller than %ld");
//         not_good = true;
//     }
//     if (begin < low || end > low)
//     {
//         printf("Value must be %ld or greater.\n", low);
//         not_good = true;
//     }
//     if (begin > high || end > high)
//     {
//         printf("Value must be %ld or less.", high);
//         not_good = true;
//     }

//     return not_good;
// }

// 明确表示界限所以要再main里面？
// #include <stdbool.h>
// #include <stdio.h>
// long get_long(void);
// _Bool bad_limits(long begin, long end, long low, long high);
// int main(void) 
// {
// 	const long MIN = -10000000L;
// 	const long MAX = +10000000L;	// 为什么要写L，不然还能是什么？+？
// 	long start;
// 	long stop;
// 	long num;
// 	double answer;	// long long answer = 0;
// 	//_Bool bad;

// 	{
// 		start = get_long();
// 		stop = get_long();
// 	}
// 	do
// 		while (bad_limits(start, stop, MIN, MAX) == true)
// 	for (num = start; num <= stop; num++) 
//         answer += num * num;
// 	printf("The sum of square of integers between %ld and %ld is %lld", start,
// 				 stop, answer);

// 	return 0;
// }

//checking.c 程序
// #include <stdio.h>
// #include <stdbool.h>
// long get_long(void);
// _Bool bad_limits(long low, long high, long begin, long end);
// double sum_squares(long a, long b);
// int main(void)
// {
//     const long MIN = -10000000L;
//     const long MAX = +10000000L;
//     long start;
//     long stop;
//     double answer;

//     printf("This program computes the sum of the squares of "
//         "integers in a range.\nThe lower bound should not "
//         "be less than -10000000 and\n the upper bound "
//         "should not be more than +1000000.\nEnter the "
//         "limits(enter 0 for both limits to quit):\n"
//         "lower limit: ");
//     start = get_long();
//     printf("upper limit: ");
//     stop = get_long();
//     while(start != 0 && stop != 0)
//     {
//         if (bad_limits(start, stop, MIN, MAX))
//             printf("Please try again.\n");
//         else
//         {
//             answer = sum_squares(start, stop);
//             printf("The sum of squares of integers ");
//             printf("from %ld to %ld is %g\n", start, stop, answer);
//         }
//         printf("Enter the limits (enter 0 for both"
//             "to quit):\n");
//         printf("lower limits: ");
//         start = get_long();
//         printf("upper limits: ");
//         stop = get_long();
//     }
//     printf("Done!\n");

//     return 0;
// }

// long get_long()
// {
//     long input;
//     char ch;
//     while (scanf("%ld", &input) != 1)//别忘了赋给input
//     {
//         while ((ch = getchar()) != '\n')
//             putchar(ch);
//         printf(" is not an integer.\nPlease enter an ");
//         printf("integer value, such as 25, -178, or 3: ");
//     }

//     return input;
// }

// double sum_squares(long a, long b)
// {
//     double total = 0;
//     long i;

//     for (i = a; i <= b; i++)
//         total += (double)i * (double)i;
    
//     return total;
// }

// _Bool bad_limits(long begin, long end, long low, long high)
// {
//     bool not_good = false;

//     if (begin > end)
//     {
//         printf("%ld isn't smaller than %ld.\n",begin, end);
//         not_good  = true;
//     }
//     if (begin < low || end < low)//一个不就够了？
//     {
//         printf("Values must be %ld or greater.\n", low);
//         not_good = true;
//     }
//     if (begin > high || end > high)
//     {
//         printf("Values must be %ld or lower.\n", high);
//         not_good = true;
//     }

//     return not_good;
// }

//8.6.2 输入流和数字

//8.7 菜单浏览
//8.7.1 任务
//8.7.2 使执行更顺利
// #include <stdio.h>
// char get_choice(void);
// char get_first(void);
// int main(void)
// {
//     int choice;
    
//     while ((choice = get_choice()) != 'q')
//     {
//         switch (choice)
//         {
//             case 'a': printf("Buy low, sell high.\n");
//                       break;
//             case 'b': putchar('\a');
//                       break;
//             case 'c': count();
//                       break;
//             default: printf("Program error!\n");
//         }
//     }

//     return 0;
// }

// char get_choice(void)
// {
//     int ch;

//     printf("Enter the letter of your choice:\n");
//     printf("a. advice           b. bell\n");
//     printf("c. count            q. quit\n");
//     ch = get_first();
//     while ((ch < 'a' || ch > 'c') && ch != 'q')
//     {
//         printf("Please respond with a, b, c, or q.\n");
//         ch = get_first();//getchar改为新设置的函数get_first.在get_first内完成丢弃。
//     }

//     return ch;
// }
// char get_first(void)
// {
//     int ch;

//     ch = getchar();
//     // while(ch == '\n' || ch == ' ')
//     //     ch = getchar();//若是空白字符是作为制表符回车等输入的呢？
//     while (getchar != '\n')
//         continue;

//     return ch;
// }

// void count(void)
// {
//     int i, n;

//     printf("Count how far? Enter an integer:\n");
//     scanf("%d", &n);
//     for (i = 1; i <= n; i++)
//         printf("%d\n", i);
//     while(getchar()!= '\n')
//         continue;//那其实这里没有排除其他空格？
// }

//8.7.3混合字符和数值输入
//程序清单8.8
/* menuette.c —— 菜单程序*/
// #include <stdio.h>
// #include <stdbool.h>
// char get_choice(void);
// char get_first(void);
// int get_int(void);
// void count (void);
// int main(void)
// {
//     int choice;
//     void count(void);

//     while((choice = get_choice()) != 'q')
//     {
//         switch(choice)
//         {
//             case 'a': printf("Buy low, sell high.\n");
//                     break;
//             case 'b': putchar('\a') ;
//                     break;
//             case 'c': count();
//                     break;
//             default: printf("Program error!\n");
//                     break;
//         }
//     } 
//     printf("Bye.\n");

//     return 0;
// }

// void count(void)
// {
//     int n, i;

//     printf("Count how far? Enter an integer:\n");
//     n = get_int();
//     for (i = 1; i <= n; i++)
//         printf("%d\n", i);
//     while(getchar() != '\n')
//         continue;
// }

// char get_choice(void)
// {
//     int ch;

//     printf("Enter the letter of your choice:\n");
//     printf("a. adcvice          b. bell\n");
//     printf("c. count            q. quit\n");
//     ch = get_first();
//     while ((ch < 'a' || ch > 'c') && (ch != 'q'))
//     {
//         printf("Please respond with a, b, c, or q.\n");
//         ch = get_first();
//     }
//     return ch;
// }

// char get_first(void)
// {
//     int ch;

//     ch = getchar();
//     while(getchar() != '\n')
//         continue;
    
//     return ch;
// }

// int get_int(void)
// {
//     int input;
//     char ch;

//     while(scanf("%d", &input) != 1)
//     {
//         while((ch = getchar()) != '\n')
//             putchar(ch);
//         printf(" is not an integer.\nPlease enter an ");
//         printf("integer value, such as 25, -178, or 3: ");
//     }

//     return input;
// }

/* lethead1.c */
// #include <stdio.h>
// #define NAME "GIGATHING, INC"
// #define ADDRESS "101 Megabuck Plaza"
// #define PLACE "Megapolis, CA 94904"
// #define WIDTH 40

// void starbar(void);

// int main(void)
// {
//     starbar();
//     printf("%s\n", NAME);
//     printf("%s\n", ADDRESS);
//     printf("%s\n", PLACE);
//     starbar();

//     return 0;
// }
// void starbar(void)
// {
//     int count;

//     for(count = 1; count <= WIDTH; count++)
//         putchar('*');
//     putchar('\n');
// }