/* shoes1.c —— 把鞋码转换成英寸 */
// #include <stdio.h>
// #define ADJUST 7.31
// int main(void)
// {
//     const double SCALE = 0.333;
//     double shoe, foot;

//     shoe = 9.0;
//     foot = SCALE * shoe + ADJUST;
//     printf("Shoe size (men's)    foot length\n");
//     printf("%10.1f %15.2f inches\n", shoe, foot);

//     return 0;
// }

/* shoes2.c —— 计算多个不同鞋码对应的脚长 */
// #include <stdio.h>
// #define ADJUST 7.31
// int main(void) {
// 	const double SCALE = 0.333;
// 	double shoe, foot;

// 	printf("Shoe size (men's)    foot length\n");
// 	shoe = 3.0;
// 	while (shoe < 18.5)// while这后不加引号
// 	{
// 		foot = SCALE * shoe + ADJUST;
// 		printf("%10.1f %15.2f inches\n", shoe, foot);
// 		shoe = shoe + 1.0;
// 	}
// 	printf("If the shoe fits, wear it.\n");

// 	return 0;
// }

// 5.2基本运算符
// pow（）函数
//  #include <stdio.h>
//  #include<math.h>
//  int main(void)
//  {
//      float a;

//     a = pow(3.5, 2.2);
//     printf("%f\n", a);

//     return 0;
// }

// 5.2.1赋值运算符=
/* golf.c —— 高尔夫锦标赛记分卡 */
// #include <stdio.h>
// int main(void)
// {
//     int jane, tarzan, cheetah;

//     cheetah = tarzan = jane = 68;
//     printf("                 cheetah    tarzan    jane\n");
//     printf("First round score %4d %8d %8d\n", cheetah, tarzan, jane);

//     return 0;

// }
/* golf.c -- 高尔夫锦标赛记分卡（书本示例） */
// #include <stdio.h>
// int main(void)
// {
//     int jane, tarzan, cheeta;

//     cheeta = tarzan = jane = 68;
//     printf("               cheeta   tarzan    jane\n");
//     printf("First round score %4d %8d %8d\n", cheeta, tarzan, jane);

//     return 0;
// }

// 5.2.2加法运算符+
//  #include <stdio.h>
//  int main(void)
//  {
//      printf("%d\n", 4 + 20);

//     return 0;
// }

// 5.2.5乘法运算符*
/* squares.c —— 计算1~20的平方 */
// #include <stdio.h>
// int main(void)
// {
//     int num = 1;

//     while(num < 21)
//     {
//         printf("%4d %6d\n", num, num * num);
//         num = num + 1;
//     }
//     return 0;
// }

// 5.2.5 1.指数增长
/* wheat.c —— 指数增长 */
// #include <stdio.h>
// #define SQUARES 64
// int main(void)
// {
//     const double CROP = 2E16;
//     double current, total;
//     int count = 1;

//     printf("square      grains        total       ");
//     printf("fraction of\n");
//     printf("           added          grains      ");
//     printf("world total\n");
//     total = current = 1.0;
//     printf("%4d %13.2e %12.2e %12.2e\n", count, current, total, total /
//     CROP); while ( count < SQUARES )
//     {
//         count = count + 1;
//         current = 2.0 * current;
//         total = total + current;
//         printf("%4d %13.2e %12.2e %12.2e\n", count, current, total, total /
//         CROP);
//     }
//     printf("That's all.\n");

//     return 0;
// }

// 5.2.6 除法运算符：/
/* divide.c —— 演示除法 */
// #include <stdio.h>
// int main(void)
// {
//     printf("integer division:  5/4   is %d\n", 5 / 4);
//     printf("integer division:  6/3   is %d\n", 6 / 3);
//     printf("integer division:  7/4   is %d\n", 7 / 4);
//     printf("floating division: 7./4. is %1.2f\n", 7. / 4.);
//     printf("mixed sivision:    7./4  is %1.2f\n", 7. / 4);

//     return 0;
// }

// 5.2.7运算符优先级
//  #include <stdio.h>
//  int main(void)
//  {
//      float butter, n;
//      const float SCALE = 2.0;
//      n = 6.0;

//     butter = 25.0 +60.0 * n / SCALE;
//     printf("%f\n", butter);

//     return 0;
// }

// 5.2.8优先级和求值顺序
// 学以致用
/* rules.c —— 优先级测试 */
// #include <stdio.h>
// int main(void)
// {
//     int top, score;

//     top = score = -(2 + 5) * 6 + (4 + 3 * (2 + 3));
//     printf("top = %d, score = %d\n", top, score);

//     return 0;
// }

// 5.3 其他运算符
// 5.3.1sizeof运算符和size_t类型
// sizeof.c —— 使用sizeof运算符
// 使用C99新增的%zd转换说明 —— 如果编译器不支持%zd，请将其改成%u或%lu
//  #include <stdio.h>
//  int main(void)
//  {
//      int n = 0;
//      size_t intsize;

//     intsize = sizeof (int);
//     printf("n = %d, n has %zd bytes; all ints have %zd bytes.\n", n, sizeof
//     n, intsize);

//     return 0;
// }

// 5.3.2求模运算符%
// min_sec.c —— 把秒数转换成分和秒
//  #include <stdio.h>
//  #define SEC_PER_MIN 60
//  int main(void)
//  {
//      int sec, min, left;

//     printf("Convert seconds to minutes and seconds!\n");
//     printf("Enter the number of seconds (<=0 to quit):\n");
//     scanf("%d", &sec);

//     while (sec > 0)
//     {
//         min = sec / SEC_PER_MIN;
//         left = sec % SEC_PER_MIN;
//         printf("%d seconds is %d minutes, %d seconds.\n", sec, min, left);
//         printf("Enter next value(<=0 to quit);\n");
//         scanf("%d", &sec);
//     }
//     printf("Done!\n");

//     return 0;
// }

// 5.3.3递增运算符++
// 程序清单5.10 add_one.c程序
/* add_one.c —— 递增：前缀和后缀 */
// #include <stdio.h>
// int main(void)
// {
//     int ultra = 0, super = 0;

//     while (super < 5)
//     {
//         super++;
//         ++ultra;
//         printf("super = %d, ultra = %d\n",super, ultra);
//     }

//     return 0;
// }

// 同输出的不同写法
//  #include <stdio.h>
//  int main(void)
//  {
//      int ultra = 0, super = 0;

//     while (super < 5)
//     {
//         ultra = ultra + 1;
//         super = super + 1;
//         printf("ultra = %d super = %d\n", ultra, super);
//     }

//     return 0;
// }

/* post_pre.c —— 前缀和后缀 */
// #include <stdio.h>
// int main(void)
// {
//     int a = 1, b = 1;
//     int a_post, pre_b;

//     a_post = a++;
//     pre_b = ++b;
//     printf("a   a_post   b   pre_b \n");
//     printf("%1d %5d %5d %5d\n", a, a_post, b, pre_b);

//     return 0;
// }

// 5.3.4递减运算符:--
//  #include <stdio.h>
//  #define MAX 100
//  int main(void)
//  {
//      int count = MAX + 1;

//     while (--count > 0)
//     {
//         printf("%d bottles of spring water on the wall, "
//                 "%d bottles of spring water!\n", count, count);
//         printf("Take one down and pass it around,\n");
//         printf("%d bottles of spring water!\n\n", count - 1);
//     }

//     return 0;
// }

// 5.3.5优先级
// 注意区分递增或递减运算符的“优先级”和“求值顺序”
//  #include <stdio.h>
//  int main(void)
//  {
//      int y = 2, n = 3;
//      int nextnum;

//     nextnum = (y + n++) * 6;
//     printf("%d\n", nextnum);

//     return 0;
// }

// 5.3.6不要自作聪明
//  #include <stdio.h>//6 30
//  int main(void)
//  {
//      int num = 5;
//  printf("%10d %10d\n", num, num * num ++);

//     return 0;
// }

// 5.4表达式和语句
// 5.4.1表达式
// 5.4.2语句
// 程序清单5.13  addemup.c程序
/* addemup.c —— 几种常见的语句 */
// #include <stdio.h>
// int main(void)
// {
//     int count, sum;

//     count = 0;
//     sum = 0;
//     while (count++ < 20)
//         sum = sum + count;
//     printf("sum = %d\n", sum);

//     return 0;
// }

// 5.4.3复合语句
/* 程序段 1 */
// #include <stdio.h>
// int main(void)
// {
//     int index, sam;

//     index = 0;
//     while(index++ < 10)
//         sam = 10 * index + 2;
//     printf("sam = %d\n", sam);

//     return 0;
// }

/* 程序段 2 */
// #include <stdio.h>
// int main(void)
// {
//     int index, sam;

//     index = 0;
//     while (index++ < 10)
//     {
//         sam = 10 * index + 2;
//         printf("%d\n", sam);
//     }

//     return 0;
// }

// 5.5 类型转换
// 程序清单5.14 convert.c程序
//  #include <stdio.h>
//  int main(void)
//  {
//      char ch;
//      int i;
//      float f1;

//     f1 = i = ch = 'C';
//     printf("ch = %c, i = %d, f1 = %2.2f\n", ch, i, f1);
//     ch = ch + 1;
//     i = f1 + 2 * ch;
//     f1 = 2.0 * ch + i;
//     printf("ch = %c, i = %d, f1 =%2.2f\n",ch, i, f1);
//     ch = 1107;
//     printf("ch = %c\n", ch);
//     ch = 80.89;
//     printf("Now ch = %c\n", ch);

//     return 0;
// }

/* pound.c —— 定义一个带一个参数的函数 */	 //???{}不是()
// #include <stdio.h>
// void pound(int n);
// int main(void)
// {
//     int times = 5;
//     char ch = '!';
//     float f = 6.0f;

//     pound(times);
//     pound(ch);
//     pound(f);

//     return 0;
// }

// void pound(int n)
// {
//     while (n-- > 0)
//         printf("#");
//     printf("\n");
// }

//怪，写不出来
// #include <stdio.h>
// void pound();
// int main(void) {
// 	int times = 5;
// 	char ch = '!';
// 	float f = 6.0f;

// 	pound(times);
// 	pound(ch);
// 	pound(f);

// 	return 0;
// }

// void pound() {
// 	while (n-- > 0);
//     printf("#");
//     printf("\n");
// }

//running.c —— A useful program for runners
// #include <stdio.h>

//running.c —— A useful programme for runners
// #include <stdio.h>
// const int S_PER_M = 60;
// const int S_PER_H = 3600;
// const double M_PER_K = 0.62137;
// int main(void)
// {
//     double distk, distm;
//     double rate;
//     int min, sec;
//     int time;
//     double mtime;
//     int mmin, msec;

//     printf("This program converts your time for a metric race\n");
//     printf("to a time for running a mile and to your average\n");
//     printf("speed in miles per hour.\n");
//     printf("Please enter, in kilometers, the distance run.\n");
//     scanf("%lf", &distk);
//     printf("Next enter the time in minutes and seconds.\n");
//     printf("Begin by enter the minutes.\n");
//     scanf("%d", &min);//什么时候不需要&来着？
//     printf("Now enter the seconds.\n");
//     scanf("%d",&sec);

//     time = S_PER_M * min + sec;
//     distm = M_PER_K * distk;
//     rate = distm / time * S_PER_H;
//     mtime = (double) time / distm;
//     mmin = (int) mtime / S_PER_M;
//     msec = (int) mtime % S_PER_M;

//     printf("You ran %1.2f km(%1.2f miles) in %d min, %d sec.\n", 
//             distk, distm, min, sec);
//     printf("The pace corresponds to running a mile in %d min, ", mmin);
//     printf("%d sec.\nYour average speed was %1.2f mph.\n", msec, rate);

//     return 0;
// }