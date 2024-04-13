/*platinum.c——your weight in platinum*/
// #include<stdio.h>
// int main(void)
// {
//     float weight;
//     float value;

//     printf("Are you worth your weight in platinum?\n");
//     printf("Let's check it out.\n");
//     printf("Please enter your weight in pounds: ");

//     scanf("%f", &weight);//&&&&&&&&&&7
//     value= 1700.0 * weight * 14.5833;
    
//     printf("Your weight in platinum is worth $%.2f.\n", value);
//     printf("You are easily worth that! If platinum prices drops,\n");
//     printf("eat more to maintain your value.\n");

//     return 0;
// }

// #include<stdio.h>
// int main(void)//()bushi<>
// {
//     unsigned int un = 3000000000;
//     short end = 200;
//     long big = 65537;
//     long long verybig = 12345678908642;

//     printf("un = %u not %d\n", un, un);
//     printf("end = %hd not %d\n", end, end);
//     printf("big = %ld not %hd\n", big, big);
//     printf("berybig= %lld not %ld\n", verybig, verybig);

//     return 0;  
// }

//chapter3
//
//
//
//platinum.c语句和声明
// #include<stdio.h>
// int main(void)
// {
//     float weight;
//     float value;

//     printf("Are you worth your weight in platinum?\n");
//     printf("Let's check it it out.\n");
//     printf("Please enter your weight in pounds: ");

//     scanf("%f", &weight);
//     value = 1700.0 * weight * 14.5833;
    
//     printf("Your weight in platinum is worth $%.2f.\n", value);//记得把变量写上！！
//     printf("Your weight is easily worth that! If platinum price drops,\n");
//     printf("eat more to maintain your value.");

//     return 0;
// }

//bases.c——以十进制、八进制、十六进制打印十进制数
// #include<stdio.h>
// int main(void)
// {
//     int x = 100;

//     printf("dec = %d; octal = %o; hex = %x\n", x, x, x);
//     printf("dec = %d; octal = %#o; hex = %#x\n", x, x, x);

//     return 0;
// }

/*toobig.c——超出系统允许的最大值*/
// #include<stdio.h>
// int main(void)
// {
//     int i = 2147483647;
//     unsigned int j = 4294967295;

//     printf("%d %d %d\n", i, i+1, i+2);
//     printf("%u %u %u\n", j, j+1, j+2);

//     return 0;
// }

/*print2.c——更多printf（）的特性*/
// #include<stdio.h>
// int main(void)
// {
//     unsigned int un = 3000000000;
//     short end = 200;
//     long big = 65537;
//     long long verybig = 12345678908642;

//     printf("un = %u not %d\n", un, un);
//     printf("end = %hd not %d\n", end, end);//截断
//     printf("big = %ld not %hd\n", big, big);
//     printf("veryig = %lld not %ld\n", verybig, verybig);

//     return 0;
// }

/*charcode.c-显示字符的代码编号*/
// #include<stdio.h>
// int main(void)
// {
//     char ch;

//     printf("Please enter a character.\n");
//     scanf("%c", &ch);
//     printf("The code for %c is %d.\n", ch, ch);

//     return 0;
// }

/*altnames.c —— 可移植整数类型名*/
// #include<stdio.h>
// #include<inttypes.h>//支持可移植类型
// int main(void)
// {
//     int32_t me32;

//     me32 = 45933945;
//     printf("First, assume int32_t is int: ");
//     printf("me32 = %d\n", me32);
//     printf("Next, let's not make any assumptions.\n");
//     printf("Instead, use a \"macro\" from inttypes: ");
//     printf("me32 = %" PRId32 "\n", me32);

//     return 0;
// }

/* showf_pt.c —— 以两种方式显示float类型的值（有误）*/
// #include<stdio.h>
// int main(void)
// {
//     float aboat = 32000.0;
//     double abet = 2.14e9;
//     long double dip = 5.23e-5;

//     printf("%f can be written %e\n", aboat, aboat);
//     printf("And it's %a in hexadecimal, powers of 2 notation\n", aboat);
//     printf("%f can be written %e\n", abet, abet);
//     printf("%Lf", dip);
//     printf("%Lf can be written %Le\n", dip, dip);

//     return 0;
// }

/*floaterr.c —— 演示舍入错误*/
// #include<stdio.h>
// int main(void)
// {
//     float a, b;

//     b = 2.0e20 +1.0;
//     a = b - 2.0e20; 
//     printf("%f \n",a);

//     return 0;
// }

/*badcount.c —— 参数错误的情况(这个情况是正常的吗)*/
// #include<stdio.h>
// int main(void)
// {
//     int n = 4;
//     int m = 5;
//     float f = 7.0;
//     float g = 8.0;

//     printf("%d\n", n, m);
//     printf("%d %d %d\n", n);
//     printf("%d %d\n", f, g);

//     return 0;
// }

/* escape.c —— 使用转义序列*/
#include<stdio.h>
int main(void)
{
    float salary;

    printf("\aEnter your desired monthly salary:");
    printf(" $_______\b\b\b\b\b\b\b");
    scanf("%f", &salary);
    printf("\n\t$%.2f a month is $%.2f a year.", salary, salary*12.0);
    printf("\rGee!\n");

    return 0;
}