// 第七章 函数——C++的编程模块
// 7.1 复习函数的基本知识
// 程序清单7.1 calling.cpp
//calling.cpp -- defining, prototyping, and calling a function
// #include <iostream>
// void simple();
// int main()
// {
//     using namespace std;
//     cout << "main() will call the simple() function:\n";
//     simple();   //function call
//     cout << "main() is finished with the simple() function.\n";
//     //cin.get()
//     return 0;
// }
// // function definition
// void simple()
// {
//     using namespace std;
//     cout << "I'm but a simple function.\n";
// }

//7.1.1 定义函数
// void functionName(parameterList)
// {
//     statement(s)
//     return; //optional
// }
// parameterList指定了传递给函数的参数类型和数量
// 通常，可以用void函数来执行某种操作。
// 将Cheers!打印指定的次数
// #include <iostream>
// void cheers(int n)
// {
//     for (int i = 0; i < n; i++)
//         std::cout << "Cheers! ";
//     std::cout << std::endl;
// }

//有返回值函数的类型被声明为返回值的类型
// typeName functionName(parameterList)
// {
//     statements;
//     return value;//value is type cast to type typeName
// }

//7.1.2 函数原型和函数调用
// 程序清单7.2 protos.cpp
// protos.cpp -- using prototypes and function calls
// #include <iostream>
// void cheers(int);
// double cube(double x);
// int main()
// {
//     using namespace std;
//     cheers(5);//function call
//     cout << "Give me a number: ";
//     double side;
//     cin >> side;
//     double volume = cube(side);
//     cout << "A " << side << "-foot cube has a volume of ";
//     cout << volume << " cubic feet.\n";
//     cheers(cube(2));
//     return 0;
// }
// void cheers(int n)
// {
//     using namespace std;
//     for (int i = 0; i < n; i++)
//         cout << "Cheers! ";
//     cout << endl;
// }

// double cube(double x)
// {
//     return x * x * x;
// }

//提供原型的原因//原型的语法
//感谢原型所做的一切

//1.为什么需要原型
//2.原型的语法
//3.原型的功能(参数)

// 7.2 函数参数和按值传递
// 7.2.1 多个参数
// 一个接受两个参数的函数
//在函数中修改形参的值不会影响调用程序中的数据
// 程序清单7.3 twoarg.cpp
// twoarg.cpp -- a function with two arguments
// #include <iostream>
// using namespace std;
// void n_chars(char, int);
// int main()
// {
//     int times;
//     char ch;

//     cout << "Enter a character: ";
//     cin >> ch;
//     while (ch != 'q')
//     {
//         cout << "Enter an integer: ";
//         cin >> times;
//         n_chars(ch, times);//function with two arguments
//         cout << "\nEnter another character or press the"
//             " q-key to quit: ";
//         cin >> ch;
//     }
//     cout << "The value of times is " << times << ".\n";
//     cout << "Bye\n";
//     return 0;
// }
// void n_chars(char c, int n)
// {
//     while (n-- > 0)
//         cout << c;
//     cout << endl << n;
// }

//7.2.2 另外一个接受两个参数的函数
// 演示局部变量的用法,而不是形参的用法
// 程序清单7.4 lotto.cpp
// lotto.cpp -- probability of winning
// #include <iostream>
// //Note: Some implementations require double instead of long double
// long double probability(unsigned numbers, unsigned picks);
// int main()
// {
//     using namespace std;
//     double total, choices;
//     cout << "Enter the total number of choices on the game card and \n";
//             "the number of picks allowed:\n";
//     while ((cin >> total >> choices) && choices <= total)
//     {
//         cout << "You have one chance in ";
//         cout << probability(total, choices);
//         cout << " of winning.\n";
//         cout << "Next two members (q to quit): ";
//     }
//     cout << "bye\n";
//     return 0;
// }
// the following function calculates the probability of picking picks
// numbers correctly frome numbers choices
// long double probability(unsigned numbers, unsigned picks)
// {
//     long double result = 1.0;
//     long double n;
//     unsigned p;

//     for (n = numbers, p = picks; p > 0; n--, p--)
//         result = result * n / p;
//     return result;
// }

//♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥

// 7.3函数和数组
// int sum_arr(int arr[], int n)
// 程序清单7.5 arrfun1.cpp
//arrfun1.cpp -- functions with an array argument
// #include <iostream>
// const int ArSize = 16;
// int sum_arr(int arr[], int n);
// int main()
// {
//     using namespace std;
//     int cookies[ArSize] = {1, 2, 4, 8, 16, 32, 64, 128};
// // some ystems require preceding int with static to
// // enable array initialization
//     int sum = sum_arr(cookies, ArSize);
//     cout << "Total cookies eaten: " << sum << "\n";
//     return 0;
// }
// // return the sum of an integer array
// int sum_arr(int arr[], int n)
// {
//     int total = 0;

//     for (int i = 0; i < n; i++)
//         total += arr[i];
//     return total;
// }

//7.3.1 函数如何用指针来处理数组
// 当（且仅当）用于函数头或函数原型中，
// int *arr和int arr [ ]的含义才是相同的
// 它们都意味着arr是一个int指针
// 别忘了，在其他的上下文中，int * arr和int arr [ ]的含义并不相同。
// 例如，不能在函数体中使用int tip[ ]来声明指针。
// *arr[i] = *(ar + i)
// &arr[i] = ar + i

//C++将数组名解释为其第一个元素的地址
//例外
// 首先，数组声明使用数组名来标记存储位置；
// 其次，对数组名使用sizeof将得到整个数组的长度（以字节为单位）；
// 第三，正如第4章指出的，将地址运算符&用于数组名时，将返回整个数组的地址
//      例如&cookies将返回一个32字节内存块的地址（如果int长4字节）。
        //这一点在 &arr + 1时更加明显(

// 7.3.2 将数组作为参数意味着什么
//传递常规变量时，函数将使用该变量的拷贝；但传递数组时，函数将使用原来的数组。
//这种区别并不违反C++按值传递的方法，sum_arr( )函数仍传递了一个值，
//这个值被赋给一个新变量，但这个值是一个地址，而不是数组的内容。

// 程序清单7.6 arrfun2.cpp
// cookies和arr值相同
// 指针概念如何使sum_arr函数比以前更通用
// std::限定符而不是编译指令using来提供对cout 和 endl的访问权
// arrfun2.cpp -- functions with an array argument
// #include <iostream>
// const int ArSize = 8;
// int sum_arr(int arr[], int n);
// //using std:: instead of using directive
// int main()
// {
//     int cookies[ArSize] = {1,2,4,8,16,32,64,128};
//     std::cout << cookies << " = array address, ";

//     std::cout << sizeof cookies << " = sizeof cookies\n";
//     int sum = sum_arr(cookies, ArSize);
//     std::cout << "Total cookies eaten: " << sum << std::endl;
//     sum = sum_arr(cookies, 3);  //a lie
//     std::cout << "First three eaters ate " << sum << " cookies.\n";
//     sum = sum_arr(cookies + 4, 4);      //another lie//这条语句将计算数组第5、6、7、8个元素的总和。没有超出越界诶.
//     std::cout << "Last four aeters ate " << sum << " cookies.\n";
//     return 0;
// }

// //return the sum of an integer array
// int sum_arr(int arr[], int n)
// {
//     int total = 0;
//     std::cout << arr << " = arr, ";

//     std::cout << sizeof arr << " = sizeof arr\n";
//     for (int i = 0; i < n; i++)
//         total = total + arr[i];
//     return total;
// }

// //为将数组类型和元素数量告诉数组处理函数，请通过两个不同的参数来传递它们：
// void fillArray(int arr[], int size); //prototype
// //而不要使用方括号表示法来传递数组长度
// void fillArray(int arr[size]);       //NO -- bad prototype

//7.3.3 更多数组函数示例
// 1.填充数组
// #include <iostream>
// int fill_array(double ar[], int limit)
// {
//     using namespace std;
//     double temp;
//     int i;
//     for (i = 0; i < limit; i++)
//     {
//         cout << "Enter value # " << (i + 1) << ": ";
//         cin >> temp;
//         if (!cin)
//         {
//             cin.clear(); //
//             while (cin.get() != '\n')
//                 continue;
//             cout << "Bad input; input process teminated.\n";
//             break;
//         }
//         else if (temp < 0)
//             break;
//         ar[i] = temp;
//     }
//     return i;
// }

//2. 显示数组及用const保护数组（（（const//const使指针指向value不变？指针指向地址不变？

// void show_array(const double ar[], int n)//ar指向的是常量值
// {
//     using namespace std;
//     for (int i= 0; i < n; i++)
//     {
//         cout << "Property #" << (i + 1) << ": $";
//         cout << ar[i] << endl;
//     }
// }

//3.修改数组
// void revalue(double r, double ar[], int n)
// {
//     for (int i =0; i < n; i++)
//         ar[i] *= r;
// }

//arrfun3.cpp -- array functions and const
// #include <iostream>
// const int MAX = 5;
// // function properties
// int fill_array(double ar[], int n);
// void show_array(double ar[], int n);
// void revalue(double r, double ar[], int n);
// int main()
// {
//     using namespace std;
//     double properties[MAX];

//     int size = fill_array(properties, MAX);
//     show_array(properties, size);//传递参数size而不是MAX
//     if (size > 0)
//     {
//         cout << "Enter revaluation factMAXor: ";
//         double factor;
//         while (!(cin >> factor))
//         {
//             cin.clear();
//             while(cin.get() != '\n')
//                 continue;
//             cout << "Bad input, please enter a number: ";
//         }
//         revalue(factor, properties, size);
//         show_array(properties, size);
//     }
//     cout << "Done!\n";
//     //cin.get();
//     //cin.get();
//     return 0;
// }

// int fill_array(double ar[], int n)
// {
//     using namespace std;
//     double temp;
//     int i; //i是返回值！！！
//     for (i = 0; i < n; i++)
//     {
//         cout << "Enter value # " << (i+1) << ": ";
//         cin >> temp;
//         if (!cin)//EOF，读取失败，其他故障
//         //cin.eof(),cin.fail()
//         //EOF -- cin.eof(),cin.fail(),cin
//         //读取失败 —— cin.fail(),cin
//         //其他故障 —— cin
//         {
//             cin.clear();
//             while (cin.get() != '\n')
//                 continue;
//             cout << "Bad input; input process terminated ";
//             break;
//         }
//         else if (temp < 0)
//             break;
//         ar[i] = temp;
//     }
//     return i;//!
// }

// void show_array(double ar[], int n)
// {
//     using namespace std;
//     for (int i = 0; i < n; i++)
//         cout << "Property #" << (i + 1) << ": " << ar[i] << endl;//endl
// }

// void revalue(double r, double ar[], int n)
// {
//     for (int i = 0; i < n; i++)
//         ar[i] *= r;
// }

//5.程序说明

//6.数组处理函数的常用编写方式
// void f_modify(double ar[], int n);
// void _f_no_change(const double ar[], int n);
//数组地址（数据类型）与元素数
// 函数缺少一些有关原始数组的知识；
//例如，它不能使用sizeof来获悉原始数组的长度，而必须依赖于程序员传入正确的元素数。

//7.3.4 使用数组区间的函数
//通过两个指针标识元素区间
//超尾？

// 程序清单7.8 arrfun4.cpp
// arrfun4.cpp -- functions with an array range
// #include <iostream>
// const int ArSize = 8;
// int sum_arr(const int * begin, const int * end);
// int main()
// {
//     using namespace std;
//     int cookies[ArSize] = {1, 2, 4, 8, 16, 32, 64, 128};
//     //some systems require preceding int with static to
//     //enable array initialization

//     int sum = sum_arr(cookies, cookies + ArSize);//指向数组后一个元素
//     cout << "Total cookies eaten: " << sum << endl;
//     sum = sum_arr(cookies, cookies + 3);
//     cout << "First three eaters ate" << sum << " cookies.\n";

//     sum = sum_arr(cookies + 4, cookies + 8);
//     cout << "Last four eaters ate " << sum << " cookies.\n";
//     return 0;
// }

//return the sum of an integer array
// int sum_arr(const int * begin, const int * end)
// {
//     const int * pt;
//     int total = 0;

//     for (pt = begin; pt != end; pt++)//条件测试
//         total += *pt;//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//     return total;
// }

// 根据指针减法规则，在sum_arr( )中，表达式end – begin是一个整数值，
//等于数组的元素数目。
// 并不会多一。相差。

//7.3.5 指针和const
// cosnt关键字用于指针的两种方式
// 让指针指向一个常量对象
// 将指针本身声明为常量（防止改变指针指向的位置）

// int age = 39;
// const int * pt = &age;//指向常量的指针pt
                    //pt指向一个const int
//pt的声明不意味着它指向的值实际上是常量
//而是对于pt而言这个值是一个常量
//（可以直接通过age修改age的值，）但不能使用pt指针修改

//常规变量——赋给——常规指针（之前）

//常规变量——赋给——const指针（如上）

//X const变量——赋给——常规指针（不可行）
// const float g_moon = 1.63;
// float * pm = &g_moon;//INVALID
//如果将g_moon的地址赋给pm，则可以使用pm来修改g_moon的值，
//这使得g_moon的const状态很《荒谬》
// 因此C++禁止将const的地址赋给非const指针。
// 如果读者非要这样做，可以使用强制类型转换来突破这种限制，
// 详情请参阅第15章中对运算符const_cast的讨论。

//const变量——赋给——const指针（如下）
// const float g_earth = 9.80;
// const float * pe = &g_earth;
//即不能用pe来修改g_earth值，也不可通过g_earth来修改

//指针指向指针
// 一级间接关系：可非const赋给const
// int age = 39;
// int * pd = &age;
// const int * pt = pd;
// 两级间接关系：不安全
//若可以：
// const int **pp2;
// int *p1;
// const int n = 13;
// pp2 = &p1;// not valid, but suppose it were
// *pp2 = &n;//valid, both const, but sets p1 to point at n 
// *p1 = 10;//valid, but change xonst n
//将非const地址&p1赋给const指针pp2,因此可以用p1修改const数据
// 因此，仅当只有一层间接关系（如指针指向基本数据类型）时，
// 才可以将非const地址或指针赋给const指针。

//如果数据类型本身并不是指针，
//则可以将const数据或非const数据的地址赋给指向const的指针，
///(如果数据类型本身是指针，理论上只能将const指针数据赋给const指针，
///非const指针数据赋给const指针会导致（由于*const指针可以指向const）非const指针指向const数据
///使得const可以通过非const指针修改)
///故而直接禁止二级间接关系指针指向指针

//但只能将非const数据的地址赋给非const指针。
///而不能将const数据的地址赋给非const指针。
//。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。
// const char * typename = "sjtu";

// const int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,};
// 一个由const数据组成的数组
// 禁止将常量数组的地址赋给非常量指针将意味着不能将数组名作为参数传递给使用非常量形参的函数
//上述函数调用试图将const指针（months）赋给非const指针（arr），编译器将禁止这种函数调用。
//《const指针months》


// 第二种使用const方式使得无法修改指针的值
//第一种再例
// int age = 39;
// const int * pt = &age;
// int sage = 80;
// pt = &sage;
//第二种方式
// int sloth = 3;
// const int * ps = &sloth;
//允许ps指向另一个位置
//但不允许使用ps来修改(sloth的)值
// int * const finger = &sloth;
//使finger只能指向sloth
//但允许使用finger来修改(sloth的)值

//finger和*ps都是const，但*finger和ps不是const

//还可以声明指向const对象（并不是指向的对象本身是const）的const指针
// double trouble = 2.0E30;
// const double * const stick = &trouble;
//stick和*stick都是const


// void show_array(const double ar[], int n);
//在该声明中使用const意味着show_array( )不能修改传递给它的数组中的值。
//只要只有一层间接关系，就可以使用这种技术。
//           例如，这里的数组元素是基本类型，
//但如果它们是指针或指向指针的指针，则不能使用const。

//7.4 函数和二维数组
// int sum(int (*ar2)[4], int size);
// int data[3][4] = {{1,2,3,4}, {9,8,7,6}, {2,4,6,8}};
// int total = sum(data, 3);
// int *ar[4]; //声明的是一个含四个指针元素的数组
// int (*ar)[4];
// int sum(int ar[][4], int size);
//指针类型制定了列数，所以不需要另外指定
// int a[100][4];
// int b[6][4];
//...
// int total1 = sum(a, 100);//sum of all a
// int total2 = sum(b, 6);//sum of all b
// int total3 = sum(a,10); //sum first 10 rows of a
// int total4 = sum(a + 10, 10);

//如何在函数定义中使用二维数组的指针
//最简单的方法：看作二维数组的名称
// int sum(int ar2[][4], int size)
// {
// 	int total = 0;
// 	for (int r = 0; r < size; r++)
// 		for (int c = 0; c < 4; c++)
// 		total += ar2[r][c];
// 	return total;
// }
// ar2[r][c] == *(*(ar2 + r) + c);
// ar2 //pointer to the first row of an array of 4 int
// ar2 + r //pointer to row r (an array of 4 int)
// *(ar2 + r)//rpw r(an array of 4 int, hence the name of an array
// 			//thus a pointer to the first int in a row, i.e., ar2[r])
// *(ar2 + r) + c//pointer int number c in a row r, i.e., ar2[r] + c
// *(*(ar2 + r) + c)//value of int number c in row e, i.e., ar2[r][c]

// 7.5 函数和C-风格字符串
// 将字符串作为数组传递意味着传递的是地址

// 7.5.1 将C-风格字符串作为参数的函数
// char ghost[15] = "galloping";
// char * str = "galumphing";
// int n1 = strlen(ghost);//ghost is &ghost[0]
// 						//ghost代表数组是对应用sizeof不是strlen
// int n2 = strlen(str);//pointer to char
// int n3 = strlen("gambling");// address of a string

// 程序清单7.9 strgfun.cpp
// strgfun.cpp -- functions with a string argument
// #include <iostream>
// unsigned int c_in_str(const char * str, char ch);
// int main()
// {
// 	using namespace std;
// 	char mmm[15] = "minimum";	//string in an array
// 	//some systems require preceding char with stastic to
// 	//enable array initialization
// 	const char *wail = "ululate";
// 	unsigned int ms = c_in_str(mmm, 'm');
// 	unsigned int us = c_in_str(wail, 'u');
// 	cout << ms << " m characters in" << mmm << endl;
// 	cout << us << " u characters in" << wail << endl;
// 	return 0;
// }
// unsigned int c_in_str(const char * str, char x)
// {
// 	unsigned int count = 0;
// 	for (int i = 0; str[i] != '\0'; i++)
// 	{
// 		if (str[i] == x)
// 			count++;
// 	}
// 	return count;
// }

// unsigned int c_in_str(const char * str, char ch)
// {
// 	unsigned int count = 0;

// 	while (*str)//quit when *str is '\0'
// 	{
// 		if (*str == ch)
// 			count++;
// 		str++;//move pointer to next char
// 	}
// 	return count;
// }

// while(*str) 能这么干，和空值字符'\0'的ascii编码为0有关。
// str++; 记得更新测试条件!!!!!!
// 用for的计数器要防止计数器在循环体内被更改（或者说是小心）
// 总而言之要有一个控制循环终止的条件啦！

//7.5.2 返回C-风格的字符串
// 程序清单7.10 stgback.cpp
// strgback.cpp -- a function that returns a pointer to char
// #include <iostream>
// char * buildstr(char c, int n);
// int main()
// {
// 	using namespace std;
// 	int times;
// 	char ch;

// 	cout << "Enter a character: ";
// 	cin >> ch;
// 	cout << "Enter an integer: ";
// 	cin >> times;
// 	char *ps = buildstr(ch, times);
// 	cout << ps << endl;
// 	delete [] ps;		//free memory
// 	ps = buildstr('+',20);//reuse pointer
// 	cout << ps << "-DONE-" << ps << endl;
// 	delete [] ps;		//free memory
// 	return 0;
// }
// builds string made of n c characters
// char * buildstr(char c, int n)
// {
// 	char * pstr = new char[n + 1];
// 	pstr[n] = '\0';
// 	while (n-- > 0)//不能直接n--，否则1到n-1
// 		pstr[n] = c;
// 	return pstr;//pstr，而不是字符串，被释放，但函数返回了pstr的值
// }
//从后往前填充是为了不引入新变量
// int i = 0;
// while (i < n)
// 	pstr[i++] = c;

//a try
// while(n > 0)
// 	pstr[--n] = c;

//这种设计（让函数返回一个指针，该指针指向new分配的内存）
//的缺点是，程序员必须记住使用delete

//7.6 函数和结构
//最直接的方式——处理基本类型那样处理结构
//方式二（节省空间+C）：传递结构的地址，用指针访问
//第三种选择：按引用传递
//7.6.1 传递和返回结构
// #include <iostream>
// struct travel_time
// {
// 	int hours;
// 	int mins;
// };
// travel_time sum(travel_time t1, travel_time t2);
// int main()
// {
// 	using namespace std;

// }

// 程序清单7.11 travel.cpp
// travel.cpp -- using structure with functions
// #include <iostream>
// struct travel_time
// {
// 	int hours;
// 	int mins;
// };
// const int Mins_per_hr = 60;
// travel_time sum(travel_time t1, travel_time t2);
// void show_time(travel_time t);
// int main()
// {
// 	using namespace std;
// 	travel_time day1 = {5, 45};
// 	travel_time day2 = {4, 55};

// 	travel_time trip = sum(day1, day2);
// 	cout << "Two_day total: ";
// 	show_time(trip);

// 	travel_time day3 = {4, 32};
// 	cout << "Three days total: ";
// 	show_time(sum(trip, day3));

// 	return 0;
// }

// travel_time sum(travel_time t1, travel_time t2)
// {
// 	struct travel_time total;
// 	//
// 	// int hs, ms;
// 	// ms = (t1.mins + t2.mins) % Mins_per_hr;
// 	// hs = (t1.hours + t2.hours) + (t1.mins + t2.mins) / Mins_per_hr;
// 	// total = {hs, ms};
// 	//
// 	total.mins = (t1.mins + t2.mins) % Mins_per_hr;
// 	total.hours = (t1.hours + t2.hours) + 
// 				(t1.mins + t2.mins) / Mins_per_hr;
// 	return total;
// }
// void show_time(travel_time t)
// {
// 	std::cout << t.hours << " hours, ";
// 	std::cout << t.mins << " minutes" << std::endl;//endl也是在std名称空间里哒！
// }

//7.6.2 另一个处理结构的示例
// #include <iostream>
// struct rect
// {
// 	double x;
// 	double y;
// };
// struct polar
// {
// 	double distance;
// 	double angle;
// };
// void show_polar(polar dapos)
// {
// 	using namespace std;
// 	const double Rag_to_deg = 57.29577951;
// 	cout << "dstance = " << dapos.distance;
// 	cout << ", angle = " << (dapos.angle * Rag_to_deg);
// 	cout << "degrees\n";//注意单位，以及换行！！！！！
// }
// #include <cmath>
// polar rect_to_polar(rect xypos)
// {
// 	polar answer;
// 	answer.distance = sqrt(xypos.x * xypos.x + xypos.y * xypos.y);
// 	answer.angle = atan2(xypos.y, xypos.x);
// 	return answer;		//return a polar structure
// }

// 程序清单7.12 atrctfun.cpp
// strctfun.cpp -- functions with a structure argument
// #include <iostream>
// #include <cmath>

// //structure declarations
// // using namespace std;
// struct polar
// {
// 	double distance;	//distance from origin
// 	double angle;		//distance from origin
// };
// struct rect
// {
// 	double x;	//horizontal distance from origin
// 	double y;	//vertical distance from origin
// };

// //prototypes
// void show_polar(polar dapos);
// polar rect_to_polar(rect xypos);

// int main()
// {
// 	using namespace std;
// 	rect rplace;
// 	polar pplace;

// 	cout << "Enter the x and y values: ";
// 	while (cin >> rplace.x >> rplace.y)//cin被用于测试表达式中时，将根据输入是否成功，被转换为bool值true或false
// 	{
// 		pplace = rect_to_polar(rplace);
// 		show_polar(pplace);
// 		cout << "Next two members (q to quit): ";
// 	}
// 	cout << "Done.\n";

// 	return 0;
// }

// // show polar coordinates, converting angle to degrees
// void show_polar(polar dapos)
// {
// 	using namespace std;
// 	const double Rag_to_deg = 57.29577951;
// 	cout << "distance = " << dapos.distance;
// 	cout << ", angle = " << (dapos.angle * Rag_to_deg) << " degrees.\n";
// }

// //convert rectangular to polar coordinates
// polar rect_to_polar(rect xypos)
// {
// 	using namespace std;
// 	polar answer;
// 	answer.distance = sqrt(xypos.x * xypos.x + xypos.y * xypos.y);
// 	answer.angle = atan2(xypos.y, xypos.x);
// 	return answer;
// }

//7.6.3 传递结构的地址
// #include <iostream>
// struct polar
// {
// 	double distance;
// 	double angle;
// };
// //show polar coordinates, converting angle to degrees
// void show_polar(const polar * pda)
// {
// 	using namespace std;
// 	const double Rag_to_deg = 57.29577951;
// 	cout << "distance = " << pda -> distance;
// 	cout << ", angle = " << ((pda -> angle) * Rag_to_deg);
// 	cout << "degrees.\n";
// }

// 程序清单7.13 strctptr.cpp
// strctptr.cpp -- functions with pointer to structure arguments
// #include <iostream>
// #include <cmath>
// struct rect
// {
// 	double x;
// 	double y;
// };
// struct polar
// {
// 	double distance;
// 	double angle;
// };
// void show_polar(const polar * pda);
// void rect_to_polar(rect * pxy, polar * npda);
// int main()
// {
// 	using namespace std;
// 	polar pplace;
// 	rect rplace;

// 	cout << "Enter the x and y value: ";
// 	while (cin >> rplace.x >> rplace.y)
// 	{
// 		rect_to_polar(&rplace, &pplace);
// 		show_polar(&pplace);
// 		cout << "Next two numbers (q to quit): ";
// 	}
// 	cout << "Done.\n";
// 	return 0;
// }
// // show polar coordinates, converting angle to degrees
// void show_polar(const polar * pda)//const~!!!!!!!!!!!!!!!!!!!!
// {
// 	using namespace std;
// 	const double Rag_to_deg = 57.29577951;

// 	cout << "distance = " << pda->distance;
// 	cout << ", angle = " << pda->angle * Rag_to_deg;
// 	cout << " degrees\n";
// }
// //converting rectangular to polar coordinates
// void rect_to_polar(rect * pxy, polar * npda)
// {
// 	using namespace std;
// 	npda->distance = sqrt(pxy->x * pxy->x + pxy->y * pxy->y);
// 	npda->angle = atan2(pxy->y, pxy->x);
// }

//7.7 函数与string对象
//多个字符串——一个string数组
//		   ——二维char数组
// 程序清单7.14 topfive.cpp
// topfive.cpp -- handling an array of string objects
// #include <iostream>
// #include <string>
// using namespace std;
// const int SIZE = 5;
// void display(const string sa[], int n);
// int main()
// {
// 	string list[SIZE];
// 	cout << "Enter your " << SIZE << " favorite astronomical sights:\n";
// 	for (int i = 0; i < SIZE; i++)
// 	{
// 		cout << i+1 << ": ";
// 		getline(cin, list[i]);
// 	}
// 	cout << "Your list:\n";
// 	display(list, SIZE);
// 	return 0;
// }
// void display(const string sa[], int n)//const!!!!!!!!!!!!!!
// {
// 	for (int i = 0; i < n; i++)
// 		cout << i+1 << ": " <<sa[i] << endl;
// }

//7.8 函数与array对象
// #include <array>
// #include <string>
// const int Seasons = 4;
// std::array<double, 4> expenses;
// void show(const std::array<double, 4> da);//da an object
// void fill(std::array<double, 4> * pa);// pa a pointer to an object
// const std::array<std::string, Seasons> Snames = {"Spring", "Summer", "Fall", "Winter"};
// const std::array<std::string, Seasons> Snames = {"Spring", "Summer", "Fall", "Winter"};
// 程序清单7.15 arrobj.cpp
// arrobj.cpp -- functions with array objects (C+11)
// #include <iostream>
// #include <array>
// #include <string>
// //constant data
// const int Seasons = 4;
// const std::array<std::string, Seasons> Snames = {"Spring", "Summer", "Fall", "Winter"};
// //function to modify array object
// void fill(std::array<double, Seasons> * pa);
// //function that uses array object without modifying it
// void show(std::array<double, Seasons> da);

// int main()
// {
// 	std::array<double, Seasons> expenses;
// 	fill(&expenses);
// 	show(expenses);
// 	return 0;
// }
// void fill(std::array<double, Seasons> * pa)
// {
// 	using namespace std;
// 	for (int i = 0; i < Seasons; i++)
// 	{
// 		cout << "Enter " << Snames[i] << " expenses: ";
// 		cin >> (*pa)[i];// 不是pa[i]
// 	}
// }//表示法
// void show(std::array<double, Seasons> da)
// {
// 	using namespace std;
// 	double total = 0.0;
// 	cout << "\nEXPENSES\n";
// 	for (int i = 0; i < Seasons; i++)
// 	{
// 		cout << Snames[i] << ": $" << da[i] << endl;
// 		total += da[i];
// 	}
// 	cout << "Total Expenses: $" << total << endl;
// }//效率
//引用可解决效率和表示法两方面问题。

//7.9 递归
//7.9.1包含一个递归调用的递归
// void recurs(argumentlist)
// {
// 	stetements1;
// 	if (test)//test最终将为false，调用链将断开
// 		recurs(arguments);
// 	statements2;;
// }

//程序清单7.16 recur.cpp
//recur.cpp -- using recursion
// #include <iostream>
// void countdown(int n);
// int main()
// {
// 	countdown(4);//call the recursive function
// 	return 0;
// }
// void countdown(int n)
// {
// 	using namespace std;
// 	cout << "Counting down..." << n << " (n at " << &n << ")"<< endl;
// 	if (n > 0)
// 		countdown(n-1);//function calls itself
// 	cout << n << ": Kaboom!" << "      (n at " << &n << ")" << endl;
// }

//7.9.2 包含多个递归调用的递归

//7.10 函数指针
//标尺
//分而治之策略
//程序清单7.17 ruler.cpp
// ruler.cpp --using recursion to subdivide a ruler
// #include <iostream>
// const int Len = 66;
// const int Divs = 6;
// void subdivide(char ar[], int low, int high, int level);
// int main()
// {
// 	char ruler[Len];
// 	int i;
// 	for (i = 1; i < Len - 2; i++)
// 		ruler[i] = ' ';
// 	ruler[Len - 1] = '\0';
// 	int max = Len - 2;
// 	int min = 0;
// 	ruler[min] = ruler[max] = '|';
// 	std::cout << ruler << std::endl;
// 	for (i = 1; i <= Divs; i++)
// 	{
// 		subdivide(ruler, min, max, i);
// 		std::cout << ruler << std::endl;
// 		for (int j = 1; j < Len - 2; j++)
// 			ruler[j] = ' ';
// 	}
// 	return 0;
// }
// void subdivide(char ar[], int low, int high, int level)
// {
// 	if (level == 0)
// 		return;
// 	int mid = (high + low) / 2;
// 	ar[mid] = '|';
// 	subdivide(ar, low, mid, level - 1);
// 	subdivide(ar, mid, high, level - 1);
// }

//**&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&……%￥#@#￥%……&*（*&*……&%￥#@#￥%

//7.10 函数指针
// 允许不同的时间传递不同的函数地址
// 可以在不同的时间使用不同的函数
//7.10.1 函数指针的基础知识
// estimate()
// 1.获取函数的地址
// 使用函数名，后面不带参数
// 区分传递的是函数还是函数的返回值
// process(think)//passes address of think() to process()//可在其内部调用
// thought(think)//passes return value of think() to thought()//调用并传递返回值

// 2.声明函数指针
//指定指针指向的类型——函数类型——声明应指定函数的返回类型以及函数的特征标（参数列表）
// ——即 声明应该像函数原型那样指出函数有关的信息
// double pam(int); //prototype
// double (*pf) (int);//pf points to a function that
                        //takes one int argument and that
                        //returns type double
// 函数原型，(*pf)代替函数名
// 区分：
// double (*pf)(int);//(*pf)是一个用一个int参数返回double的函数，所以pf是指向其的指针
// double *pf(int);//函数原型，pf是使用一个int参数返回指向double的指针的函数

// double pam(int);
// double (*pf)(int);
// pf = pam;//pf now points to the pam() function

// void estimate(int lines, double (*pf)(int));
// estimate(50, pam);
// 使用函数指针——编写原型+传递地址

// 3.使用指针来调用函数
// 前面说过，(*pf)扮演的角色和函数名相同so使用(*pf)时当作函数名使用即可
// double pam(int);
// double (*pf)(int);
// pf = pam;//记得别忘了让指针指向一个东西！指针“初始化”(赋值)非常非常必要！
// double x = pam(int);
// double y = (*pf)(int);
// as a matter of fact
// double y = pf(5); // also call pam() using the pointer pf
// 允许使用函数名一样使用pf

//1：由于pf是函数指针，而*pf是函数，因此应将（*pf）( )用作函数调用
//2：由于函数名是指向该函数的指针，指向函数的指针的行为应与函数名相似

//7.10.2 函数指针示例
// 程序清单7.18 fun_ptr.cpp
// fun_ptr.cpp -- pointers to functions
// #include <iostream>
// double besty(int);
// double pam(int);

// //second argument is pointer to a type double function that
// // takes a type int argument
// void estimate(int lines, double (*pf)(int));

// int main()
// {
// 	using namespace std;
// 	int code;
	
// 	cout << "How many lines of code do you need? ";
// 	cin >> code;
// 	cout << "Here's Besty's estimate:\n";
// 	estimate(code, besty);
// 	cout << "Here's Pam's estimate:\n";
// 	estimate(code, pam);
// 	return 0;
// }

// double besty(int lns)
// {
// 	return 0.05 * lns;
// }
// double pam(int lns)
// {
// 	return 0.03 * lns + 0.0004 * lns * lns;
// }

// void estimate(int lines, double (*pf)(int))
// {
// 	using namespace std;
// 	cout << lines << " lines will take ";
// 	cout << (*pf)(lines) << "hour(s)\n";
// }

// 7.10.3 深入探讨函数指针
// 看似不同的特征标（实际相同）
// const double * f1(const double * ar, int n);
// const double * f2(const double ar[], int n);
// const double * f3(const double [], int);
// const double * f4(const double *, int);//不提供标识符
// //声明一个指针
// const double * (*p1)(const double *, int);
// //声明的同时初始化
// const double * (*p1)(const double *, int) = f1;
// // C++11的自动类型推断功能
// auto p2 = f2;

// cout << (*p1)(av, 3) << ": " << *(*p1)(av, 3) << endl;
// cout << p2(av, 3) << ": " << *p2(av, 3) << endl;

// const double * (*ps[4])(const double *, int)

// 程序清单7.19 arfupt.cpp
// arfupt.cpp -- an array of function pointers
// #include <iostream>
// // various notations, same signatures
// const double * f1(const double ar[], int n);
// const double * f2(const double [], int);
// const double * f3(const double *, int);

// int main()
// {
// 	using namespace std;
// 	double av[3] = {1112.3, 1542.6, 2227.9};

// 	// pointer to a function
// 	const double * (*p1)(const double *, int) = f1;
// 	auto p2 = f2;
// 	cout << "Using pointers to functions:\n";
// 	cout << "Address Value\n";
// 	cout << (*p1)(av, 3) << ": " << *(*p1)(av, 3) << endl;
// 	cout << p2(av, 3) << ": " << *p2(av, 3) << endl;



// 	//pa an array of pointers
// 	//auto doesn't work with list initialization
// 	const double *(*pa[3])(const double *, int) = {f1, f2, f3};
// 	// but it does work for initializing to a single value
// 	//pb a pointer to first element of pa
// 	auto pb = pa;
// 	//pre-C++11 can use the following code instead
// 	//const double *(**pb)(const double *, int) = pa;
// 	cout << "\nUsing an array of pointers to functions:\n";
// 	cout << "Adress Value\n";
// 	for (int i = 0; i < 3; i++)
// 		cout << pb[i](av, 3) << ": " << *pb[i](av, 3) << endl;
// 	cout << "\nUsing a pointer to a pointer to a function:\n";
// 	cout << "Address Value\n";
// 	for (int i = 0; i < 3; i++)
// 		cout << pb[i](av, 3) << ": " << *pb[i](av, 3) << endl;
// 	// what about a pointer to an array of function pointers
// 	cout << "\nUsing pointers to an array of pointers:\n";
// 	cout << " Adress Value\n";
// 	//easy way to decalre pc
// 	//pre-C++11 can use the following code instead
// 	// const double * (*(*pc)[3])(const double *, int) = &pa;// const double *(*(*pc)[3])(const double *, int) = &pa;
// 	auto pc = &pa;
// 	cout << (*pc)[0](av, 3) << ": " << *(*pc)[0](av, 3) << endl;
// 	//hard way to declare pd
// 	const double *(*(*pd)[3])(const double *, int) = &pa;
// 	//store return value;
// 	const double * pdb = (*pd)[1](av, 3);
// 	cout << pdb << ": " << *pdb << endl;
// 	//alternative notation
// 	cout << (*(*pd)[2])(av, 3) << ": " << *(*(*pd)[2])(av, 3) << endl;
// 	return 0;
// }

// //some rather dull functions

// const double * f1(const double * ar, int n)
// {
// 	return ar;
// }
// const double * f2(const double ar[], int n)
// {
// 	return ar+1;
// }
// const double * f3(const double ar[], int n)
// {
// 	return ar+2;
// }

//7.10.4 使用typedef进行简化
// typedef double real;
// typedef const double *(*p_fun)(const double *, int);
// p_fun p1 = f1;
// p_fun pa[3] = {f1, f2, f3};//pa an array of 3 function pointers
// p_fun (*pd)[3] = &pa;//pd points to an array of 3 function pointers

//7.11 总结