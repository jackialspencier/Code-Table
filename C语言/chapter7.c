//第七章 C控制语句：分支和跳转
//7.1 if 语句
//
// #include <stdio.h>
// int main(void)
// {
//     const int FREEZING = 0;
//     float temperature;
//     int cold_days = 0;
//     int all_days = 0;

//     printf("Enter the list of daily low temperature.\n");
//     printf("Use Celsius, and enter q to quit.\n");
//     while (scanf("%f", &temperature) == 1)
//     {
//         all_days++;
//         if (temperature < FREEZING)
//             cold_days++;
//     }
//     if (all_days != 0)
//         printf("%d days total: %.1f%% were below freezing.\n",
//                 all_days, 100.0 * (float)cold_days / all_days);
//     if (all_days == 0)
//         printf("No data entered!\n");

//     return 0;
// }

//7.2 if else语句

//7.2.1 另一个示例：介绍getchar()和putchar()
//cypher1.c —— 更改输入，空格不变
// #include <stdio.h>
// #define SPACE ' '
// int main(void)
// {
//     char ch;

//     ch = getchar();
//     while (ch != '\n')//\n还是换行符呢？怪怪的。是怎么回事？
//     {
//         if (ch == SPACE)
//             putchar(ch);
//         else
//             putchar(ch + 1);
//         ch = getchar();
//     }

//     return 0;
// }

//7.2.2ctype.h系列的字符函数
//cypher2.c —— 替换输入的字母，非字母字符保持不变
// #include <stdio.h>
// #include <ctype.h>
// int main(void)
// {
//     char ch;

//     while ((ch = getchar()) != '\n')//识别输出区的一个换行符？
//     {
//         if (isalpha(ch) != 0) //凭什么不能多一个！=0？
//             putchar(ch + 1);
//         else
//             putchar(ch);
//     }
//     putchar(ch);

//     return 0;
// }

//7.2.3多重选择else if
//electric —— 计算电费
// #include <stdio.h>
// #define RATE1 0.13230
// #define RATE2 0.15040
// #define RATE3 0.30025
// #define RATE4 0.34025
// #define BREAK1 360
// #define BREAK2 468
// #define BREAK3 720
// #define BASE1 (BREAK1 * RATE1)
// #define BASE2 (((BREAK2 - BREAK1) * RATE2) + BASE1)
// #define BASE3 (BASE2 + RATE3 * (BREAK3 - BREAK2))
// int main(void)
// {
//     double kwh;
//     double bill;

//     printf("Please enter the kwh used:\n");
//     scanf("%lf", &kwh);//%lf对应double类型
//     if (kwh <= BREAK1)
//         bill = kwh * RATE1;
//     else if (kwh <= BREAK2)
//         bill = BASE1 + RATE2 * (kwh - BREAK1);
//     else if (kwh <= BREAK3)
//         bill = BASE2 + RATE3 * (kwh - BREAK2);
//     else
//         bill = BASE3 + RATE4 * (kwh - BREAK3);
//     printf("The charge for %.1f lwh is $%1.2f.\n", kwh, bill);

//     return 0;
// }

//7.2.4 else和if配对
// #include <stdio.h>
// int main(void)
// {
//     int num;

//     printf("number    reaction\n");
//     while(scanf("%d", &num) == 1)
//     {
//         if (num > 6)
//             if (num < 12)
//             printf("          You're close!\n");
//         else 
//             printf("          Sorry, you lose a turn!\n");
//     }

//     return 0;
// }

// #include <stdio.h>
// int main(void)
// {
//     int num;

//     printf("number  reaction\n");
//     while (scanf("%d", &num) == 1)
//         if (num > 6)
//         {
//             if (num < 12)
//                 printf("     You're close!\n");
//         }
//         else
//             printf("     Sorry, you lose a turn!\n");

//     return 0;
// }

//7.2.5多层嵌套的if语句
//divisors.c —— 使用嵌套if语句显示一个数的约数
// #include <stdio.h>
// #include <stdbool.h>
// int main(void)
// {
//     unsigned long num;
//     unsigned long div;
//     bool isPrime;

//     printf("Please enter a number for analysis; ");
//     printf("Enter q to quit.\n");
//     while (scanf("%ld", &num) == 1)
//     {
//         for (div = 2, isPrime = true; (div * div) <= num; div++)
//         {
//             if (num % div == 0)
//             {
//                 if ((num / div) == div)
//                     printf("%lu is divisible by %lu.\n", num, div);
//                 else//if ((dv * div) != num)和else，和自写对应相反。
//                     printf("%lu is divisible by %lu and %lu.\n", num, div, num / div);
//                 isPrime = false;
//             }
//         }
//         if (isPrime)
//             printf("%lu is prime.\n", num);
//         printf("Please enter another integer for analysis; ");
//         printf("Enter q to quit.\n");
//     }
//     printf("Bye.\n");

//     return 0;
// }

//7.3逻辑运算符
// chcount.c —— 使用逻辑与运算符
// #include <stdio.h>
// #define PERIOD '.'
// int main(void)
// {
//     char ch;
//     int charcount = 0;

//     while((ch = getchar()) != PERIOD)
//     {
//         if (ch != '"' && ch != '\'')
//             charcount++;
//     }
//     printf("There are %d non-quote characters.\n", charcount);
//     printf("%1134");

//     return 0;
// }

//7.3.1 备选拼写： iso646.h头文件

//7.3.2 优先级

//7.3.3 求值顺序

//7.3.4范围
// if (range >= 90 && range <= 100)
//     printf("Good show!\n");
// #include <stdio.h>
// int main(void)
// {
//     int range;

//     scanf("%d", &range);
//     if (90 <= range <= 100)
//         printf("Good show!\n");

//     return 0;
// }

// #include <stdio.h>
// int main(void)
// {
//     char ch;

//     ch = getchar();
//     if (ch >= 'a' && ch <= 'z')
//         printf("That's a lowercase character!\n");

//     return 0;
// }

//if (islower(ch))
    // printf("That's a lowercase character!\n");

//7.4一个统计单词的程序
// #include <stdio.h>
// #include <stdbool.h>
// #include <ctype.h>
// #define STOP '|'
// int main(void)
// {
//     char ch;
//     char prev;
//     bool inword = false;
//     int characters = 0;
//     int words = 0;
//     int lines = 0;

//     while ((ch = getchar()) != STOP)
//     {   
        
//             characters++;

//         if ((!isspace(ch)) && (!inword))
//             {
//                 words++;
//                 inword = true;
//             }
//         if ((isspace(ch)) && inword)
//             inword = false;

//         if (ch == '\n')
//             lines++;
        
//         prev = ch;
//     }
//     if (prev != '\n')
//         lines++;
    
//     printf("There are %d lines, %d words and %d characters in this paragraph.\n",
//              lines, words, characters);

//     return 0;
// }

// wordcnt.c —— 统计字符数、单词数、行数
// #include <stdio.h>
// #include <ctype.h>
// #include <stdbool.h>
// #define STOP '|'
// int main(void)
// {
//     char c;
//     char prev;
//     long n_chars = 0L;
//     int n_words = 0;
//     int n_lines = 0;
//     int p_lines = 0;
//     bool inword = false;

//     printf("Enter text to be analyzed (| to terminate):\n");
//     prev = '\n';//用于识别完整的行。（有啥用？防止一个输入也没有？）
//     while ((c = getchar()) != STOP)
//     {
//         n_chars++;
//         if (c == '\n')
//             n_lines++;
//         if ((!isspace(c)) && (!inword))
//         {
//             n_words++;
//             inword = true;
//         }
//         if ((isspace(c)) && (inword))
//             inword = false;
//         prev = c;
//     }
//     if (prev != '\n')
//         p_lines = 1;
//     printf("characters = %ld, words = %d, lines = %d, ",
//              n_chars, n_words, n_lines);
//     printf("partial lines = %d\n", p_lines);

//     return 0;
// }

//7.5 条件运算符：？：
//程序清单7.8 paint.c程序
/* paint.c —— 使用条件运算符 */
// #include <stdio.h>
// #define COVERAGE 350
// int main(void)
// {
//     int sq_feet;
//     int cans;

//     printf("Enter a number of square feet to be painted:\n");
//     while (scanf("%d", &sq_feet) == 1)
//     {
//         cans = sq_feet / COVERAGE;
//         cans += (sq_feet % COVERAGE == 0)? 0: 1;//示例两个括号？
//         printf("You need %d %s of paint.\n", cans, cans == 1? "can": "cans");//示例不加括号？
//         printf("Enter next value (q to quit):\n");
//     }

//     return 0;
// }

//7.6 循环辅助：continue和break
//7.6.1 continue语句
//程序清单7.9 skippart.c 程序
/* skippart.c —— 使用continue跳过循环部分 */
// #include <stdio.h>
// int main(void)
// {
//     const float MIN = 0.0f;
//     const float MAX = 100.0f;

//     float score;
//     float total = 0.0f;
//     int n = 0;
//     float min = MAX;
//     float max = MIN;//啊哈？

//     printf("Enter the first score (q to quit): ");
//     while ((scanf("%f", &score)) == 1)
//     {
//         if (score < MIN || score > MAX)
//         {
//             printf("%0.1f is an invalid value. Try again: ", score);
//             continue;//注意是跳出“循环”or嵌套的“循环”。if不是循环！
//         }
//         //else？
//         printf("Accepting %0.1f:\n", score);
//         min = (score < min) ? score : min;
//         max = (score > max) ? score : max;
//         total += score;
//         n++;
//         printf("Enter next score (q to quit): ");
//     }
//     if (n > 0)
//     {
//         printf("Average of %d scores is %0.1f.\n", n, total / n);
//         printf("Low = %0.1f, high = %0.1f\n", min, max);
//     }
//     else
//         printf("No valid scores were entered.\n");
    
//     return 0;
// }

//7.6.2 break语句
//程序清单7.10 break.c程序
// #include <stdio.h>
// int main(void)
// {
//     float length, width;

//     printf("Enter the length of the rectangle:\n");
//     while (scanf("%f", &length) == 1)
//     {
//         printf("Length = %0.2f:\n", length);
//         printf("Enter its width:\n");
//         if (scanf("%f", &width) == 0)
//             break;
//         printf("Width = %0.2f:\n",width);
//         printf("Area = %0.2f:\n", length * width);
//         printf("Enter the length of the rectangle:\n");
//     }
//     printf("Done.\n");

//     return 0;
// }

// #include <stdio.h>
// int main(void)
// {
//     int p, q;

//     scanf("%d", &p);
//     while(p > 0)
//     {
//         printf("%d\n", p);
//         scanf("%d", &q);
//         while (q > 0)
//         {
//             printf("%d\n", p * q);
//             if (q > 100)
//                 break;
//             scanf("%d", &q);
//         }
//         // if (q > 100)
//         //     break;
//         scanf("%d", &p);
//     }

//     return 0;
// }

//7.7 多重选择：switch和break
/* animals.c —— 使用switch语句 */
// #include <stdio.h>
// #include <ctype.h>
// int main(void)
// {
//     char ch;

//     printf("Give me a letter of the alphabet, and I will give ");
//     printf("an animal name\nbeginning with that letter.\n");
//     printf("Please type in a letter; type # to end my act.\n");
//     while ((ch = getchar()) != '#')
//     {
//         if ('\n' == ch)
//             continue;
//         if (islower(ch))
//             switch (ch)
//         {
//             case 'a':
//                 printf("argali, a wild sheep of Asia\n");
//                 break;
//             case 'b':
//                 printf("babirusa, a wild pig of Malay\n");
//                 break;
//             case 'c':
//                 printf("coati, racoonlike mammal\n");
//                 break;
//             case 'd':
//                 printf("desman, aquatic, molelike critter\n");
//                 break;
//             case 'e':
//                 printf("echidna, the spiny anteater\n");
//                 break;
//             case 'f':
//                 printf("fisher, brownish marten\n");
//                 break;
//             default:
//                 printf("That's a dumper!\n");
//         }
//         else
//             printf("I recognize only lowercase letters.\n");
//         while (getchar() != '\n')
//             continue;
//         printf("Please type another letter or a #.\n");
//     }
//     printf("Bye!\n");

//     return 0;
// }

// vowels.c —— 使用多重标签
// #include <stdio.h>
// int main(void)
// {
//     char ch;
//     int a_ct, e_ct, i_ct, o_ct, u_ct;

//     a_ct = e_ct = i_ct = o_ct = u_ct = 0;

//     printf("Enter some text; enter # to quit it.\n");
//     while ((ch = getchar()) != '#')
//     {
//         switch (ch)
//         {
//             case 'a':
//             case 'A':   a_ct++;
//                         break;
//             case 'e':
//             case 'E':   e_ct++;
//                         break;
//             case 'i':
//             case 'I':   i_ct++;
//                         break;
//             case 'o':
//             case 'O':   o_ct++;
//                         break;
//             case 'u':
//             case 'U':   u_ct++;
//                         break;
//             default:    break;
//         }
//     }
//     printf("number of vowels:   A    E    I    O    U\n");
//     printf("                 %4d %4d %4d %4d %4d\n", a_ct, e_ct, i_ct, o_ct, u_ct);

//     return 0;
// }

// #include <stdio.h>
// #include <ctype.h>
// int main(void)
// {
//     char ch;

//     ch = toupper(getchar());
//     printf("%c\n", ch);

//     return 0;
// }

// #include <stdio.h>
// int main(void)
// {
//     char ch;
//     int chcount;

//     while ((ch = getchar()) != '\n')
//     {
//         if (ch == ' ')
//             continue;
//         putchar(ch);
//         chcount++;
//     }
//     printf("\n%d\n", chcount);

//     return 0;
// }

