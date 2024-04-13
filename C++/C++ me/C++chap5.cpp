//5.1 for循环
// 程序清单5.1 forloop.cpp
// forloop.cpp -- introducing the for loop
// #include <iostream>
// int main()
// {
//     using namespace std;
//     int i; // create a counter
// //initialize; test; update
//     for (i = 0; i < 5; i++)
//         cout << "C++ knows loops.\n";
//     cout << "C++ knows when to stop.\n";
//     return 0;
// }

// 程序清单5.2 num_test.cpp
// #include <iostream>
// int main()
// {
//     using namespace std;
//     cout << "Enter the starting countdown value: ";
//     int limit;
//     cin >> limit;
//     int i;
//     for (i = limit; i; i--)
//         cout << "i = " << i << ".\n";
//     cout << "Done now taht i = " << i << "\n";
//     return 0;
// }

//程序清单5.3 express.cpp
// express.cpp -- values of expressions
// #include <iostream>
// int main()
// {
//     using namespace std;
//     int x;

//     cout << "The expression x = 100 has the value ";
//     cout << (x = 100) << endl;
//     cout << "Now x = " << x << endl;
//     cout << "The expression x < 3 has the value ";
//     cout << (x < 3) << endl;
//     cout << "The expression x > 3 has the value ";
//     cout << (x > 3) << endl;//该标记命令cout显示true和false
//     cout.setf(ios_base::boolalpha);
//     cout << "The expression x < 3 has the value ";
//     cout << (x < 3) << endl;
//     cout << "The expresiion x > 3 has the value ";
//     cout << (x > 3) << endl;
//     return 0;
// }

//每个表达式都有值
// for (expression; expression; expression);
// for (for-init-statement condition; condition);

//5.1.2 回到for循环
// 程序清单5.4 formore.cpp
// foremore -- more looping with for
// #include <iostream>
// const int ArcSize = 16;
// int main()
// {
//     long long factorials[ArcSize];
//     factorials[1] = factorials[0] = 1;
//     for (int i = 2; i < ArcSize; i++)
//         factorials[i] = i * factorials[i - 1];
//     for (int j = 0; j < ArcSize; j++)
//         std::cout << j << "! = " << factorials[j] << std::endl; 
//     return 0;
// }

// 5.1.3 修改步长
//程序清单5.5 bigstep.cpp
// bigstep.cpp -- count as directed
// #include <iostream>
// int main()
// {
//     using std::cout;
//     using std::cin;
//     using std::endl;
//     cout << "Enter an integer: ";
//     int by;
//     cin >> by;
//     cout << "Counting by " << by << "s:\n";
//     for (int i = 0; i < 100; i = i + by)
//     //i == 100, 检测不等通常比检测想等好
//     //如此处i不会等于100
//         cout << i << endl;//别忘了endl！！！
//     return 0;
// }

// 5.1.4 使用for循环访问字符串
//可以使用string对象，也可以使用char数组
//因为它们都让您能够使用数组表示法来访问字符串中的字符
//size（）
//程序清单5.6 forstr1.cpp
// forstr.cpp -- using for with a string
// #include <iostream>
// #include <string>
// int main()
// {
//     using namespace std;
//     cout << "Enter a word: ";
//     string word;
//     cin >> word;

//     //display letters in reverse order
//     for (int i = word.size() - 1; i >= 0; i--)//not size(word),而是word.size()
//         cout << word[i];
//     cout << "\nBye.\n";
//     return 0;
// }

//5.1.5递增运算符（++）和递减运算符（--）
// 程序清单5.7 plus_one.cpp
// plus_one.cpp -- the increment operator
// #include <iostream>
// int main()
// {
//     using std::cout;
//     int a = 20;
//     int b = 20;
    
//     cout << "a   = " << a << ";   b = " << b << "\n";
//     cout << "a++ = " << a++ << "; ++b = " << ++b << "\n";
//     cout << "a   = " << a << ";   b = " << b << "\n";
// }
//粗略地讲，a++意味着使用a的当前值计算表达式，然后将a的值加1；
//而++b的意思是先将b的值加1，然后使用新的值来计算表达式。
// my key: 使用后修改，修改后使用
// x = 2 * x++ * (3 - ++x) ;//don't so it except as an experiment
//看看C语言关于计算顺序blabla未定义的阐释？？？？？

// 5.1.6 副作用和顺序点
//副作用（side effect）指的是在计算表达式时对某些东西（如存储在变量中的值）进行了修改
//顺序点（sequence point）是程序执行过程中的一个点，
//  在这里，进入下一步之前将确保对所有的副作用都进行了评估
//如语句中的分号，任何完整的表达式末尾
//完整表达式呢？它是这样一个表达式：不是另一个更大表达式的子表达式

// y = (4 + x++) + (6 + x++);
//表达式4 + x++不是一个完整表达式，
//因此，C++不保证x的值在计算子表达式4 + x++后立刻增加1。
//在这个例子中，整条赋值语句是一个完整表达式，而分号标示了顺序点，
//因此C++只保证程序执行到下一条语句之前，x的值将被递增两次。
//C++没有规定是在计算每个子表达式之后将x的值递增，还是在整个表达式计算完毕后才将x的值递增
//《没有规定》，只是保证在顺序点“前”完成

//thinking about C 的内容
//y = (4 * x++) + (6 * x++)
//*不作用于同一个数，不保证从左到右。

//所谓的使用再递增，递增再使用，使用指的其实是《表达式的值》
// 如x++;和++x;，表达式的值未被使用，因此只存在副作用。
// 执行速度 -- 似乎没啥
// 对于类而言，前缀版本的效率比后缀版本高。
// 总之，对于内置类型，采用哪种格式不会有差别；
// 但对于用户定义的类型，如果有用户定义的递增和递减运算符，则前缀格式的效率更高。

//5.1.8 递增/递减运算符和指针
//将什么解除引用，将什么递增。这取决于运算符的位置和优先级
//前缀和解引用优先级相同，从右到左方式结合
//后缀比前缀运算符优先级高，从左到右的方式结合
//double x = *++pt
//++*pt
//同优先级看结合方式
//同一个操作数不同优先级的先
//指针递增和递减遵循指针算术规则

//5.1.9 组合赋值运算符
//*(pa + 4) += 7;
// L /= R // L = L / R
// L %= R // L = L % R

// 5.1.10 复合语句（语句块）
// 程序清单5.8 block.cpp
// block.cpp -- use a block statement
// #include <iostream>
// int main()
// {
//     using namespace std;
//     cout << "The amazing Accounto will sum and average ";
//     cout << "Five numbers for you.\n";
//     cout << "Please enter five values:\n";
//     double number;
//     double sum = 0.0;
//     for (int i = 0; i < 5; i++)
//     {
//         cout << "Value " << i << ": ";
//         cin >> number;
//         sum += number;
//     };
//     cout << "Five exquisite choices indeed! ";
//     cout << "They sum to " << sum << endl;
//     cout << "and average to " << sum / 5 << ".\n";
//     cout << "The Amazing Accounto bids you adieu!\n";
//     return 0;
// }

//在外部语句块中定义的变量在内部语句块中也是被定义了的。
//如果在语句块中定义一个新的变量，则仅当程序执行该语句块中的语句时，该变量才存在。
//执行完该语句块后，变量将被释放。这表明此变量仅在该语句块中才是可用的
// #include <iostream>
// int main()
// {
//     using namespace std;
//     int x = 20;
//     {
//         int y = 100;
//         cout << x << endl;
//         cout << y << endl;
//     }
//     cout << x << endl;
//     cout << y << endl;
//     return 0;
// }

//如果在一个语句块中声明一个变量，而外部语句块中也有一个这种名称的变量
//在声明位置到内部语句块结束的范围之内，新变量将隐藏旧变量；然后旧变量再次可见
// #include <iostream>
// int main()
// {
//     using std::cout;
//     using std::endl;
//     int x = 20;
//     {
//         cout << x << endl;
//         int x = 100;
//         cout << x << endl;
//     }
//     cout << x << endl;
//     return 0;
// }

//5.1.11 其他语法技巧 -- 逗号运算符
//把more语句放到只允许一条语句的地方——语句块、逗号运算符
// i++, j--;
//逗号不总是逗号运算符//列表分隔符
// int i, j;
//comma is a seperate here, not an operator
//程序清单5.6按相反的顺序显示数组的内容，
//而程序清单5.9将数组中的字符顺序反转。
// 程序清单5.9 forstr2.cpp
// forstr2.cpp -- reversing an array
// #include <iostream>
// #include <string>
// int main()
// {
//     using namespace std;
//     cout << "Enter a word: ";
//     string word;
//     cin >> word;

// //physically modifying string object
//     char temp;
//     int i, j;
//     for (i = 0, j = word.size()-1; i < j; i++, j--)
//     {
//         char temp = word[i];//可以用int诶
//         word[i] = word[j];
//         word[j] = temp;
//     };
//     cout << word << "\nDone.\n";
//     return 0;
// }

//1.程序说明
// temp在每轮循环中都将被分配和释放。这比在循环前声明temp的速度要慢一些。
//3.逗号运算符花絮
//两个特性
//顺序点
//逗号表达式的值-第二部分
//运算优先级最低
// cata = 17, 240; //cata = 17//优先级
// cata = (17, 240) //cata = 240//表达式的值

//由于字符用其ASCII码表示，因此也可以将这些运算符用于字符。不能将它们用于C-风格字符串，但可用于string类对象。
//？？？？？？
//关系运算符优先级比算术运算符低


//5.1.13 赋值、比较和可能犯的错误
// 程序清单5.10 equal.cpp
// equal.cpp -- equality vs assignment
// #include <iostream>
// int main()
// {
//     using namespace std;
//     int quizscores[10] = {20, 20, 20, 20, 20, 19, 20, 18, 20, 20};

//     cout << "Doing it right:\n";
//     int i;
//     for (i = 0; quizscores[i] == 20; i++)
//         cout << "quiz " << i << "is a 20\n";
//     cout << "Doing it dangerously wrong:\n";
//     for (i = 0; quizscores[i] = 20; i++)
//         cout << "quiz " << i << " is a 20.\n";

//     return 0;
// }
//?????segmentation fault?

// 5.1.14 C-风格字符串的比较
// 程序清单5.11 -- comparing strings using arrays
// #include <iostream>
// #include <cstring>
// int main()
// {
//     using namespace std;
    // char word[5] = "?ate";
    // for (char ch = 'a'; strcmp(word, "mate"); ch++)
    // {
    //     cout << word << endl;
    //     word[0] = ch;
    // }
    // cout << "After the loop ends, word is " << word << endl;
    /*cout << strcmp("mate", "mate");*/
//     return 0;
//  }
//strcmp()在字符串不等时返回true，相等返回false
//strcmp是逐个字母比较，直到有结果（> < =）就不继续比较吗？
//所谓的返回正负数就是0or-1？

//5.1.15 比较string类字符串
//关系运算符重载故可用在string对象上
//程序清单5.12 compstr.cpp
// compstr.cpp -- comparing strings using arrays
// #include <iostream>
// #include <string> // string class
// int main()
// {
//     using namespace std;
//     string str = "?ate";
//     char ch;

//     for (ch = 'a'; str != "mate"; ch++)
//     {
//         cout << str << endl;
//         str[0] = ch;
//     }
//     cout << "After the loop ends, word is " << str << endl;

//     return 0;
// }
//string类重载运算符!=的方式让您能够在下述条件下使用它：至少有一个操作数为string对象，
//另一个操作数可以是string对象，也可以是C-风格字符串。
//不是计数循环，根据情况来确定是否停止

//5.2 while循环
//空值字符不是空格
//程序清单5.13 while.cpp
// while.cpp -- introducing the while loop
// #include <iostream>
// const int ArSize = 20;
// int main()
// {
//     using namespace std;
//     // char name[ArSize];
//     string name;

//     cout << "Your first name, please: ";
//     cin >> name;
//     cout << "Here is your name, verticalized and ASCIIized:\n";
//     int i = 0;
//     while(name[i] != '\0')//(name[i])
//     {
//         cout << name[i] << ": " << int(name[i]) << endl;
//         i++;
//     }
//     return 0;
// }

//name[i]是常规字符，其值为该字符的编码—非零值或true。
//然而，当name[i]为空值字符时，其编码将为0或false。

//要打印字符的ASCII码，必须通过强制类型转换将name[i]转换为整型。
//这样，cout将把值打印成整数，而不是将它解释为字符编码。

//又一个神奇的因果关系
// 不同于C-风格字符串，string对象不使用空字符来标记字符串末尾，
// 因此要将程序清单5.13转换为使用string类的版本，只需用string对象替换char数组即可。
// 第16章将讨论可用于标识string对象中最后一个字符的技术。

//5.2.1 for与while
//for和while：省略，初始化，continue
//循环计数
//无法预知循环次数
//while(); //problem semicolon
//{...}
//该循环不执行任何操作，是一个死循环。请注意这种分号。
//花括号中所有的代码现在位于循环的后面，永远不会被执行。

//5.2.2等待一段时间：编写延时循环
//程序清单5.14
//ctime//clock()//clock_t
//waiting.cpp -- using clock() in a time-delay loop
// #include <iostream>
// #include <ctime> // describe clock() fuction, clock_t type
// int main()
// {
//     using namespace std;
//     cout << "Enter the delay time, in seconds: ";
//     float secs;
//     cin >> secs;
//     clock_t delay = secs * CLOCKS_PER_SEC;//covert to clock ticks

//     cout << "starting\a\n";
//     clock_t start = clock();
//     while(clock() - start < delay)//wait until time elapses
//     ;//note the semicolon
//     cout << "done \a\n";
//     return 0;
// }
//wow，注意一下这个程序

//typedef typeName AliasName
//#define生命一系列变量时不适用
// #define FLOAT_POINTER float *
// FLOAT_POINTER a, b;
// => float * a, b;//b是float类型，a是float指针类型？
//typedef没有这个问题。

//5.3 do while循环
// 程序清单5.15 sowhile.cpp
// dowhile.cpp -- exit-condition loop
// #include <iostream>
// int main()
// {
//     using namespace std;
//     int n;
    
//     cout << "Enter numbers in the range 1-10 to find:";
//     cout << "my favorite number\n";
//     do
//     {
//         cin >> n;
//     }while(n != 7);
//     cout << "Yes, 7 is my favorite.\n";

//     return 0;
// }

//5.4 基于范围的for循环（C++11）
// double prices[5] = {4.99, 10.99, 6.87, 7.99, 8.49};
// for (double x : proces)
//     cout << x << std::endl;

// for (double &x : prices)
//     x = x * 0.80; // 20% off sale
//符号&表明x是一个引用变量
//就这里而言，这种声明让接下来的代码能够修改数组的内容，而第一种语法不能。

//还可结合使用基于范围的for循环和初始化列表
// for (int x : {3, 5, 2, 8, 6})
//     cout << x << " ";
// cout << '\n';

//哨兵字符//回显
//程序清单5.16 textin1.cpp
// #include <iostream>
// int main()
// {
//     using namespace std;
//     char ch;
//     int count = 0;
//     cout << "Enter characters; enter # to quit:\n";
//     cin >> ch;
//     while(ch != '#')
//     {
//         cout << ch;
//         ++count;
//         cin >> ch;
//     }
//     cout << endl << count << " characters read\n";
//     return 0;
// }
// 还可结合使用基于范围的for循环和初始化列表
// 发送给cin的输入被缓冲。这意味着只有在用户按下回车键后，
// 他输入的内容才会被发送给程序
// 所以可以在#后面输入字符


/*
// #include <iostream>
// using namespace std;

// int main()
// {
//     int a, n;
//     long long int sum = 0;
//     cin >> a >> n;
//     int ax = 0;
//     int axx = a;
//     for (int i = 0; i < n; i++)
//     {
//         if i > 0
//         axx *= 10;    
//         ax += axx;
//         sum += ax;
//     }
//     cout << sum;
//     return 0;
// }
*/

// 5.5.2 使用cin.get(char)进行补救
// textin2.cpp -- using cin.get()
// #include <iostream>
// int main()
// {
//     using namespace std;
//     char ch;
//     int count = 0;

//     cout << "Enter characters; enter # to quit:\n";
//     cin.get(ch);
//     while(ch != '#')
//     {
//         cout << ch;
//         ++count;
//         cin.get(ch);
//     }
//     cout << endl << count << " characters are read.\n";
//     return 0;
// }
//引用

//5.5.3 使用哪一个cin.get()

// 5.5.4 文件尾条件
// < 重定向运算符
// golfish < fishtale
// unix ctrl + D
// windows ctrl + Z 或 Enter
// 程序清单5.18 textin3.cpp
// textin3.cpp -- reading chars to end of file
// #include <iostream>
// int main()
// {
//     using namespace std;
//     char ch;
//     int count = 0;
//     cin.get(ch);//attempt to read a char
//     while(cin.fail() == false)//while(!cin.fail)//test for EOF
//     //while(cin)//while input is successful
//     {
//         cout << ch;
//         ++count;//do stuff
//         cin.get(ch);//attempt to read another char
//     }
//     cout << endl << count << " characters are read\n";

//     return 0;
// }

//循环可精简为
// while(cin.get(ch))//while input is successful
// {
    // ...//do stuff
// }

//三条指导原则：确定循环条件，、对条件进行初始化，更新条件
//全部被放到循环测试条件中
//all in one

//5.5.5 另一个cin.get()版本
//getchar() putchar()
//cstdio或stdio.h
//ch = cin.get()
//将字符编码以int形式返回
//cin.get(char)
//返回一个对象

//cout.put(ch)
//参数类型为char
//putchar()
//参数类型为int

//为成功地使用cin.get( )，需要知道其如何处理EOF条件。
//当该函数到达EOF时，将没有可返回的字符。
//相反，cin.get( )将返回一个用符号常量EOF表示的特殊值。

// int ch;
// ch = cin.get()
// while(ch != EOF)//EOF不表示输入中的的字符，而是指出没有字符
// {
//     cout.put(ch);//cout.put(char(ch)) for some implementations
//     ++count;
//     ch = cin.get();
// }

//程序清单5.19 textin4.cpp
// textin4.cpp -- reading chars with cin.get()
// #include <iostream>
// int main(void)
// {
//     using namespace std;
//     int ch;//should be int, not char
//     int count = 0;//不要忘记对count初始化！（自己的计数器也要初始化呀）
//     while((ch = cin.get()) != EOF)//test for end-of-file
//     //!= 的优先级比=高，所以把比较不等与否后的bool值赋给ch
//     {
//         cout.put(char(ch));
//         count++;
//     }
//     cout << endl << count << " characters are read\n";

//     return 0; 
// }

// 如果旧的代码使用int变量进行输入，而所用的实现包含put( )的多个原型，
//则必须做进一步的调整。
//有些C++实现都提供了3个原型：put(char)、put(signed char)和put(unsigned char)。
//在这些实现中，给put( )传递一个int参数将导致错误消息，
// 因为转换int的方式不止一种。//
//使用显式强制类型转换的原型（如cin.put(char(ch))）可使用int参数。

//5.6嵌套循环和二维数组
// for (int row = 0; row < 4; row++)
// {
//     for (int col = 0; col < 5; col++)
//         cout << maxtemps[4][5] << "\t";
//     cout << endl;
// }

//5.6.1 初始化二维数组
//由于每个元素本身就是一个数组，
//  因此可以使用与上述代码类似的格式来初始化每一个元素
//初始化由一系列逗号分隔的一维数组初始化（用花括号括起）组成
// int maxtemps[4][5] = //2-D arrary
// {
//     {96, 100, 87, 101, 105},//values for maxtemps[0]
//     {96, 98, 91, 107, 104}, //values for maxtemps[1]
//     {97, 98, 93, 108, 107}, //values for maxtemps[2]
//     {98, 103, 95, 109, 108} //values for maxtemps[3]
// }

//使用二维数组
//程序清单5.20 nested.cpp
// nested.cpp -- nested loops and 2-D array
// #include <iostream>
// const int Cities = 5;
// const int Years = 4;
// int main()
// {
//     using namespace std;
//     const char * cities[Cities] = 
//     {
//         "Gribble City",
//         "Gribbletown",
//         "New Gribble",
//         "San Gribble",
//         "Gribble Vista"
//     };

//     int maxtemps[Years][Cities] = 
//     {
//         {96, 100, 87, 101, 105},
//         {96, 98, 91, 107, 104},
//         {97, 101, 93, 108, 107},
//         {98, 103, 95, 109, 108}
//     };

//     cout << "Maximum temperatures for 2008 -2011\n\n";
//     for (int city = 0; city < Cities; city++)
//     {
//         cout << cities[city] << ":\t";//":" << "\t"可以合并呀
//         for (int year = 0; year < Years; year++)
//             cout << maxtemps[year][city] << "\t";
//         cout << endl;
//     }
//     return 0;
// }

//cin.get（char）成员函数调用通过 返回转换 为false的 <bool值> 来指出已到达EOF，
//而cin.get( )成员函数调用则通过返回<EOF值>来指出已到达EOF，EOF是在文件iostream中定义的。