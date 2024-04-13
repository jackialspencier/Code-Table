//talkback.c —— 演示与用户交互
// #include<stdio.h>
// #include<string.h>
// #define DENSITY 62.4
// int main(void)
// {
//     float weight, volume;
//     int size, letters;
//     char name[40];

//     printf("Hi! What's your first name?\n");
//     scanf("%s", name);
//     printf("%s, what's your weight in pounds?\n", name);
//     scanf("%f", &weight);
//     size = sizeof name;
//     letters = strlen(name);
//     volume = weight / DENSITY ;
//     printf("Well, %s, your volume is %2.2f cubic feet.\n", name, volume);
//     printf("Also, your first name has %d letters,\n", letters);
//     printf("and we have %d bytes to store it.\n", size);

//     return 0;
// }

/*praisel.c —— 使用不同类型的字符串*/
// #include<stdio.h>
// #define PRAISE "You are an extraodinary person."
// int main(void)
// {
//     char name[40];

//     printf("What's your name? ");
//     scanf("%s", name);
//     printf("Hello, %s. %s\n", name, PRAISE);

//     return 0;
// }

/*praise2.c*/
//如果编译器不能识别%zd，尝试换成%u或%Lu。（l和L？还有这些又是什么？）u、zd可以，Lu不行？？
// #include<stdio.h>
// #include<string.h>
// #define PRAISE "You are an extraordinary being."
// int main(void)
// {
//     char name[40];

//     printf("What's your name? ");
//     scanf("%s", name);
//     printf("Hello, %s. %s\n", name, PRAISE);
//     printf("Your name of %zd letters occupies %u memory cells.\n",
//             strlen(name), sizeof name);
//     printf("The phrase of praise has %u letters ",
//             strlen(PRAISE));
//     printf("and occupies %zd memory cells.\n", sizeof PRAISE);

//     return 0;  
// }

/*pizza。c —— 在比萨饼程序种使用已定义的常量*/
// #include<stdio.h>
// #define PI 3.14159
// int main(void)
// {
//     float area, circum, radius;
    
//     printf("What is the radius of your pizza?\n");
//     scanf("%f", &radius);
//     area = PI * radius * radius;
//     circum = 2.0 * PI * radius;
//     printf("Your basic pizza parameters are as follows:\n");
//     printf("circumstance = %1.2f, area = %1.2f\n", circum, area);

//     return 0;
// }

/*自行尝试*/
// #include<stdio.h>
// #include<limits.h>
// #include<float.h>
// int main(void)
// {
//     printf  ("%d", INT_MAX);

//     return 0;
// }

// #include<stdio.h>
// #include<limits.h>
// int main(void)
// {
//     printf("Maximum int value on this system = %d\n", INT_MAX);

//     return 0;
// }

//defines.c —— 使用limits.h和float(.h?)头文件中定义的明示常量（4.3）
// #include<stdio.h>
// #include<limits.h>
// #include<float.h>
// int main(void)
// {
//     printf("Some number limits for this system:\n");
//     printf("Biggest int: %d\n", INT_MAX);
//     printf("Smallest long long: %lld\n", LLONG_MIN);
//     printf("One byte = %d bits on this system.\n", CHAR_BIT);
//     printf("Largest double:%e\n", DBL_MAX);
//     printf("Smallest normal float: %e\n", FLT_MIN);
//     printf("float precision = %d digits\n", FLT_DIG);
//     printf("float epsilon = %e\n", FLT_EPSILON);

//     return 0;
// }

// #include<stdio.h>
// int main(void)
// {
//     float a = 3.13e-8;
//     printf("%f", a);

//     return 0;
// }

/*printout.c —— 使用转换说明*/
// #include<stdio.h>
// #define PI 3.141593
// int main(void)
// {
//     int number = 7;
//     float pies = 12.75;
//     int cost = 7800;
//     printf("The %d contestants ate %f berry pies.\n"
//             , number, pies);
//     printf("The value of pi is %f.\n", PI);
//     printf("Farewell! thou art too dear for my possessing,\n");
//     printf("%c%d\n", '$', 2*cost);

//     return 0;    
// }

/*width.c —— 字段宽度*///超过了什么就不行？怪
// #include<stdio.h>
// #define PAGES 121211111111
// int main(void)
// {
//     printf("*%d*\n", PAGES);
//     printf("*%2d*\n", PAGES);
//     printf("*%10d*\n", PAGES);
//     printf("*%-10d*\n",PAGES);

//     return 0;
// }

//floats.c —— 一些浮点型修饰符的组合
// #include<stdio.h>
// int main(void)
// {
//     const double RENT = 3852.99;

//     printf("*%f*\n", RENT);
//     printf("*%e*\n", RENT);
//     printf("*%4.2f*\n", RENT);
//     printf("*%3.1f*\n", RENT);
//     printf("*%10.3f*\n", RENT);
//     printf("*%10.3E*\n", RENT);
//     printf("*%+4.2f*\n", RENT);
//     printf("*%010.2f*\n", RENT);

//     return 0;
// }

/*flags.c —— 演示一些格式标记*/
// #include<stdio.h>
// int main(void)
// {
//     printf("%x %X %#x %#X\n", 31, 31, 31, 31);
//     printf("**%d**% d**% d**\n", 42, 42, -42);
//     printf("**%5d**%5.3d**%05d**%05.3d**\n", 6, 6, 6, 6);

//     return 0;
// }

/* string.c —— 字符串格式 */
// #include<stdio.h>
// #define BLURB "Authentic imitation!"
// int main(void)
// {
//     printf("[%2s]\n", BLURB);
//     printf("[%24s]\n", BLURB);
//     printf("[%24.5s]\n", BLURB);
//     printf("[%-24.5s]\n", BLURB);
//     printf("[%5.3d]\n", 6123);

//     return 0;
// }

//学以致用（书上%.2f）
// #include<stdio.h>
// int main(void)
// {
//     char name[40] = "NAME";
//     float cash = 355.71;
    
//     printf("The %s family just may be $%6.2f dollars richer!", name, cash);

//     return 0;
// }

/* intconv.c —— 一些不匹配的整型转换 */
// #include<stdio.h>
// #define PAGES 336
// #define WORDS 63618
// int main(void)
// {
//     short num = PAGES;
//     short mnum = -PAGES;

//     printf("num as short and unsigned short: %hd %hu\n", num, num);
//     printf("-num as short and unsigned short: %hd %hu\n", mnum, mnum);
//     printf("num as int and char: %d %c\n", num, num);
//     printf("WORDS as int short, and char: %d %hd %c\n", WORDS, WORDS, WORDS);

//     return 0;
// }

/* floatcnv.c —— 不匹配的浮点型转换 */
// #include<stdio.h>
// int main(void)
// {
//     float n1 = 3.0;
//     double n2 = 3.0;
//     long n3 = 2000000000;
//     long n4 = 1234567890;

//     printf("%.1e %.1e %.1e %.1e\n", n1, n2, n3, n4);
//     printf("%ld %ld\n", n3, n4);
//     printf("%ld %ld %ld %ld\n", n1, n2, n3, n4);

//     return 0;
// }

/* prntval.c —— print（）的返回值*/
// #include<stdio.h>
// int main(void)
// {
//     int bph2o = 212;
//     int rv;

//     rv = printf("%d F is water's boiling point.\n", bph2o);
//     printf("The printf() function printed %d characters.\n", rv);

//     return 0;
// }

/* longstrg.c —— 打印较长的字符串 */
// #include<stdio.h>
// int main(void)
// {
//     printf("Here's one way to print a ");
//     printf("long string.\n");
//     printf("Here's another way to print a \
// long string.\n");
//     printf("Here's the newest way to print a "
//            "long string.");

//     return 0;
// }

//程序清单4.15
//input.c —— 何时使用&
// #include<stdio.h>
// int main(void)
// {
//     int age;
//     float assets;
//     char pet[30];

//     printf("Enter your age, assets, and favorite pet.\n");
//     scanf("%d %f", &age, &assets);
//     scanf("%s", pet);
//     printf("%d %.2f %s", age, assets, pet);

//     return 0;
// }
// // input.c -- 何时使用&（书本示例）
// #include <stdio.h>
// int main(void)
// {
//     int age;             // 变量
//     float assets;        // 变量
//     char pet[30];        // 字符数组，用于储存字符串

//     printf("Enter your age, assets, and favorite pet.\n");
//     scanf("%d %f", &age, &assets);    // 这里要使用&
//     scanf("%s", pet);                 // 字符数组不使用&
//     printf("%d $%.2f %s\n", age, assets, pet);

//     return 0;
// }

//程序清单4.16
/* varwid —— 使用变宽输出字段 */
// #include <stdio.h>
// int main(void)
// {
//     unsigned width, precision;
//     int number = 256;
//     double weight = 242.5;

//     printf("Enter a field width:\n");
//     scanf("%d", &width);
//     printf("The number is :%*d:\n", width, number);
//     printf("Now enter a width and a precision: ");
//     scanf("%d %d", &width, &precision);
//     printf("Weight = %*.*f\n", width, precision, weight);
//     printf("Done!\n");

//     return 0;
// }

//程序清单4.17
/* skipteo.c —— 跳过输入中的前两个数 */
// #include<stdio.h>
// int main(void)
// {
//     int n;

//     printf("Please enter three integers:\n");
//     scanf("%*d %*d %d", &n);
//     printf("The last integer was %d\n", n);

//     return 0;
// }

// #include<stdio.h>
// int main(void)
// {
//     float distance = 10.22;
//     printf("Count Beppo ran %.2f miles in 3 hours.\n", distance);
//     printf("Count Beppo ran %10.2f miles in 3 hours.\n", distance);

//     return 0;
// }

//4.4.7 printf()
// #include <stdio.h>
// int main(void)
// {
//     int val1, val2, val3;

//     val1 = 12;
//     val2 = 234;
//     val3 = 1222;
//     printf("%d %d %d\n", val1, val2, val3);
//     val1 = 4;
//     val2 = 5;
//     val3 = 23;
//     printf("%d %d %d\n", val1, val2, val3);
//     val1 = 22334;
//     val2 = 2322;
//     val3 = 10001;
//     printf("%d %d %d\n", val1, val2, val3);

//     return 0;
// }

//足够大的字段宽度
// #include <stdio.h>
// int main(void)
// {
//     int val1, val2, val3;
//     val1 = 12;
//     val2 = 234;
//     val3 = 1222;
//     printf("%9d %9d %9d\n", val1, val3, val3);
//     val1 = 4;
//     val2 = 5;
//     val3 = 23;
//     printf("%9d %9d %9d\n", val1, val2, val3);
//     val1 = 23334;
//     val2 = 2322;
//     val3 = 10001;
//     printf("%9d %9d %9d\n", val1, val2, val3);
// }
