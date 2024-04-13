// #include<stdio.h>
// int main(void)
// {
//     int num;
//     num = 1;

//     printf("I am a simple ");
//     printf("computer.\n");
//     printf("My favorite number is %d because it is first.\n",num);

//     return 0;
// }

//fathm_ft.c——把二音寻转换成英寸
// #include<stdio.h>//别漏了这句啊喂！
// int main(void)
// {
//     int feet,fathoms;//一行可以写不止一个诶
    
//     fathoms=2;
//     feet=6*fathoms;
//     printf("There are %d feet in %d fathoms!\n", feet, fathoms);
    
//     return 0;
// }

//fathm_ft.c——把2音寻转换成英寸
// #include<stdio.h>
// int main(void)
// {
//     int feet,fathoms;
    
//     fathoms = 2;
//     feet = 6 * fathoms;
//     printf("There are %d feet in %d fathoms.\n", feet, fathoms);
//     printf("Yes, I said %d feet!\n", 6 * fathoms);

//     return 0;
// }

// //*two_func.c——一个文件中包含两个函数*/
// #include<stdio.h>
// void butler(void);/*ANSI/ISO C函数原型*/
//  int main(void)
//  {
//     printf("I will summon the butler function.\n");
//     butler();
//     printf("Yes. Bring me some tea and writeable DVDs.\n");

//     return 0;
//  }
// void butler (void)/*函数定义开始*/
// {
//     printf("You rang, sir?\n");
// }

//two——func.c一个文件中包含两个函数
// #include<stdio.h>
// void butler(void);
// int main(void)
// {
//     printf("I will summon the butler fuction.\n");
//     butler();
//     printf("Yes. Bring me some tea and writeable DVDs.\n");

//     return 0;
// }
// void butler(void)
// {
//     printf("You rang, sir?\n");
// }

/*chapter 2, review questions7*/
//two_values.c——以特定格式输出两个值。
// #include<stdio.h>
// int main(void)
// {
//     int words, lines;
    
//     words = 3020;
//     lines = 350;
//     printf("There are %d words and %d lines.", words, lines);

//     return 0;
// }

/* platinum.c —— your weight in platinum */
// #include<stdio.h>
// int main(void)
// {
//     float weight;
//     float value;
    
//     printf("Are you worth your weight in platinum?\n");
//     printf("Let's check it out.\n");
//     printf("Please enter your weight in pounds: ");

//     scanf("%f", &weight);

//     value=1700.0 * weight * 14.5833;
//     printf("Your weight in platinum is worth $%.2f.\n", value);
//     printf("You are easily worth that! If platinum prices drop,\n");
//     printf("eat more to maintain your value.\n");

//     return 0;
// }

//2.12编程练习
// 1.换行符\n和打印输出
//注意只要没\n几次printf的输出都是连着的。
// #include<stdio.h>
// int main(void)
// {
//     printf("Gustav Mahler");

//     printf("\nGustav\nMahler");

//     printf("\nGustav ");
//     printf("Mahler");
    
//     return 0;
// }

// 2.打印输出
// #include<stdio.h>
// int main(void)
// {
//     printf("My name is Hejia Wang.");
//     printf("\nI'm living in a dormitary in Shanghai Jiao Tong University now.");

//     return 0;
// }

// 3.整数数据类型变量打印
// #include<stdio.h>
// int main(void)
// {
//     int ages, days;
    
//     ages = 19;
//     days = 365 * ages;
//     printf("%d %d", ages, days);

//     return 0;
// }

//4.多个函数
// #include<stdio.h>
// void jolly(void);
// void deny(void);
// int main(void)
// {
//     jolly();
//     jolly();
//     jolly();
//     deny();
// }
// void jolly(void)
// {
//     printf("For he's a jolly good fellow!\n");
// }
// void deny(void)
// {
//     printf("Which nobody can deny!");
// }

// 5.多个函数（与其他打印内容组合使用）
// #include<stdio.h>
// void br(void);
// void ic(void);
// int main(void)
// {
//     br();
//     printf(", ");
//     ic();
//     printf("\n");
//     ic();
//     printf(",");
//     printf("\n");
//     br();

//     return 0;
// }
// void br(void)
// {
//     printf("Brazil, Russia");
// }
// void ic(void)
// {
//     printf("India, China");
// }

//6.变量赋值
// #include<stdio.h>
// int main(void)
// {
//     int toes;
//     int toes_2;
//     int toes_3;
    
//     toes = 10;
//     toes_2 = toes^2;
//     toes_3= toes^3;
// }

//7.
// #include<stdio.h>
// void smile(void);
// int main(void)
// {
//     smile();
//     smile();
//     smile();
//     printf("\n");
//     smile();
//     smile();
//     printf("\n");
//     smile();
//     return 0;
// }
// void smile(void)
// {
//     printf("Smile!");
// }

//8.函数内调用函数
// #include<stdio.h>
// void one_three(void);
// void two(void);
// int main(void)
// {
//     printf("starting now:");
//     one_three();
//     printf("\ndone!");
    
//     return 0;
// }
// void one_three(void)
// {
//     printf("\none");
//     two();
//     printf("\nthree");
// }
// void two(void)
// {
//     printf("\ntwo");
// }