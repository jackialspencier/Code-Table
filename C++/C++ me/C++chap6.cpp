//if.cpp -- using the if statement
// #include <iostream>
// int main()
// {
//       using std::cin;
//       using std::cout;
//       char ch;
//       int space = 0;
//       int total = 0;
//       cin.get(ch);
//       while(ch != '.')
//       {
//         if (ch == ' ')
//             space++;
//         total++;
//         cin.get(ch);
//       }
//       cout << space << " spaces, " << total;
//       cout << " characters total in sentence\n";
//       return 0;
// }

//注意，字符总数中包括按回车键生成的换行符。

//6.1.1if else语句
//if else //std::限定符
//程序清单6.2 ifelse.cpp
//ifelse.cpp -- using the if else statement
// #include <iostream>
// int main()
// {
//     char ch;

//     std::cout << "Type, and I shall repeat.\n";
//     std::cin.get(ch);
//     while(ch != '.')
//     {
//         if (ch == '\n')
//             std::cout << ch;
//         else
//             std::cout << ch++; // ch++相当于ch = ch + 1,最终为char类型，而ch + 1直接得到的是int类型。
//         std::cin.get(ch);
//     }
//     //try ch + 1 instead of ++ch for interesting effect;
//     std::cout << "\nPlease excuse the slight confusion.\n";
//     return 0;
// }

//6.1.2 格式化if else语句

//6.1.3 if else if else语句
//程序清单6.3 ifelseif.cpp
// ifelseif.cpp -- using if else if else
// #include <iostream>
// const int Favo =27;
// int main()
// {
//     using namespace std;
//     int n;

//     cout << "Enter a number in the range 1-100 to find ";
//     cout << "my favorite number: ";
//     do{
//         cin >> n;
//         if (n < Favo)
//             cout << "Too low -- guess again: ";
//         else if (n > Favo)
//             cout << "Too high -- guess again: ";
//         else
//             cout << Favo << "is correct!\n";
//     }while(n != Favo);

//     return 0;
// }

//6.2逻辑表达式
// 6.2.1 逻辑OR运算符：||
// ||运算符是个顺序点
// ：和，也是顺序点
// ？？？？？？？？？？i++ &lt; 6||i == j;
// 程序清单6.4 or.cpp
// or.cpp -- using the logical OR operator
// #include <iostream>
// int main()
// {
//     using namespace std;
//     cout << "This program may reformat your hard disk\n"
//             "and destroy all your data.\n"
//             "Do you wish to continue?<y/n>";
//     char ch;
//     cin >> ch;
//     if (ch == 'y' || ch == 'Y')
//         cout << "You were warned!\a\a\n";
//     else if (ch == 'n' || ch == 'N')
//         cout << "A wise choice...bye\n";
//     else
//     cout << "That wasn't a y or n! Apparently you "
//             "can't follow\ninstructions, so"
//             "I'll trash your disk anyway.\a\a\a\n";
//     return 0;
// }

//6.2.2逻辑AND运算符：&&
//&&和|| ：1优先级比关系运算符低
//       ：2顺序点
// 程序清单6.5 and.cpp
// &&来处理一种常见的情况——由于两种不同的原因而结束while循环
//and.cpp -- using the logical AND operator
// #include <iostream>
// const int ArSize = 6;
// int main()
// {
//     using namespace std;
//     float naaq[ArSize];
//     cout << "Enter the NAAQS(New Age Awareness Quotients) "
//         <<"of\nyour neighbors. Program terminates "
//         <<"when you make\n" << ArSize << " entries "
//         << "or enter a negative value.\n";
    
//     int i;
//     float temp;
//     cout << "First value: ";
//     cin >> temp;
//     while (i < ArSize && temp >= 0)
//     {
//         naaq[i] = temp;
//         ++i;
//         if (i < ArSize)
//         {
//             cout << "Next value: ";
//             cin >> temp;
//         }
//     }
//     if (i == 0)
//         cout << "No data--bye\n";
//     else{
//         cout << "Enter you NAAQ: ";
//         float you;
//         cin >> you;
//         int count = 0;
//         for (int j = 0; j < i; j++)
//             if (naaq[j] > you)
//                 ++count;
//         cout << count;
//         cout << "of your neighbors have greator awareness of\n"
//              <<   "the New Age than you do.\n";
//     }
//     return 0;
// }

//6.2.3 用&&来设置取值范围
//程序清单6.6 more_and.cpp
// #include <iostream>
// const char * qualify[4] = 
// {
//     "10,000 - meter race.\n",
//     "mud tug-of-war.\n",
//     "masters canoe jousting.\n",
//     "pie-throwing festival.\n"
// };
// int main()
// {
//     using namespace std;
//     int age;
//     cout << "Enter age in years: ";
//     cin >> age;
//     int index;

//     if (age > 17 && age < 35)
//         index = 0;
//     else if (age >= 35 && age < 50)
//         index = 1;
//     else if (age >= 50 && age <= 65)
//         index = 2;
//     else
//         index = 3;
    
//     cout << "You qualify for the " << qualify[index];
//     return 0;
// }

//6.2.4逻辑NOT运算符：！
// 将！用于函数返回值
// not.cpp -- using the not operator
// #include <iostream>
// #include <climits>
// bool is_int(double);
// int main()
// {
//     using namespace std;
//     double num;

//     cout << "Yo, dude! Enter an integer value: ";
//     cin >> num;
//     while (!is_int(num))
//     {
//         cout << "Out of range -- please try again: ";
//         cin >> num;
//     }
//     int val = int(num); //type cast //本来是double。// 确认输入有效后，程序将其赋给一个int变量。
//     cout << "You've entered the integer " << val << "\nBye\n";
//     return 0;
// }
// bool is_int(double x)
// {
//     if (x <= INT_MAX && x >= INT_MIN)
//         return true;
//     else
//         return false;
// }
//main( )程序使用while循环来拒绝无效输入，
//直到用户输入有效的值为止。

// 6.2.5 逻辑运算符细节
// ！运算符优先级高于所有关系运算符和算术运算符
// ! 算术运算符 关系运算符 AND OR

//6.2.6 其他表示方式
// C：#include <iso646.h> // and or not
// C++：and or not

// 6.3 字符函数库cctype
// #include <iostream>
// int main()
// {
//     int a = 10;
//     bool aa = a;
//     std::cout << aa;
// }
// int到bool可以自动转换

// isalpha()
// isdigits()
// isspace()
// ispunct()
// cin.get(char) cin.get()
// 程序清单6.8 cctypes.cpp
// cctypes.cpp -- using the ctype.h library
// #include <iostream>
// #include <cctype>
// int main()
// {
//     using namespace std;
//     cout << "Enter text for analysis, and type @"
//             " to terminate input.\n";
//     char ch;
//     int whitespace = 0;
//     int digits = 0;
//     int chars = 0;
//     int punct = 0;
//     int others = 0;

//     cin.get(ch);
//     while (ch != '@')
//     {
//         if (isalpha(ch))
//             chars++;
//         else if (isspace(ch))
//             whitespace++;
//         else if (ispunct(ch))
//             punct++;
//         else if (isdigit(ch))
//             digits++;
//         else
//             others++;
//         cin.get(ch);
//     }
//     cout << chars << " letters, "
//          << whitespace << " whitespace, "
//          << digits << " digits, "
//          << punct << " punctations, "
//          << others << "others.\n";
//     return 0;
// }
//173-174?177? ?????????????????????????????

//6.4 ?:运算符
//确定两个值中较大的一个
// 程序清单6.9 condit.cpp
// condit.cpp -- using the conditional operator
// #include <iostream>
// int main()
// {
//     using namespace std;
//     int a, b;
//     cout << "Enter two integers: ";
//     cin >> a >> b;
//     cout << "The larger of " << a << " and " << b;
//     int c = a > b ? a : b;
//     cout << " is " << c;
//     return 0;
// }


// const char x[2][20] = {"Jason", "at your service"};
// const char * y = "Quillstone";

// for (int i = 0; i < 3; i++)
//     cout << ((i < 2)? !i ? x[i] : y : x[1]);

// Jason
// Quillstone
// at your service

//6.5 switch语句
// 整数常量表达式
// int char 枚举量
// 程序清单6.10 switch.cpp
// switch.cpp -- using the switch statement
// #include <iostream>
// using namespace std;
// void showmenu();
// void report();
// void comfort();
// int main()
// {
//     showmenu();
//     int choice;
//     cin >> choice;
//     while(choice != 5)
//     {
//         switch(choice)
//         {
//             case 1 : cout << "\a\n";
//                     break;
//             case 2 : report();
//                     break;
//             case 3 : cout << "The boss was in all day.\n";
//                     break;
//             case 4 : comfort();
//                     break;
//             default : cout << "That's not a choice.\n";
//         }
//         showmenu();
//         cin >> choice;
//     }
//     cout << "Bye!\n";
//     return 0;
// }
// void showmenu()
// {
//     cout << "Please enter 1, 2, 3, 4, or 5:\n"
//             "1) alarm           2) report\n"
//             "3) alibi           4) comfort\n"
//             "5) quit\n";
// }
// void report()
// {
//     cout << "It's been an excellent week for business.\n"
//             "Sales are up 120%. Expenses are down 35%.\n";
// }
// void comfort()
// {
//     cout << "Your employees think you are the finest CEO\n"
//             "in the industry. The board of directors think\n"
//             "you are the finest CEO in the industry.\n";
// }

//6.5.1 将枚举量用作标签
// 程序清单6.11 enum.cpp
// enum.cpp -- using enum
// #include <iostream>
// // create named constants for 0 - 6
// enum {red, orange, yellow, green, blue, violet, indigo};

// int main()
// {
//     using namespace std;
//     cout << "Enter color code (0-6): ";
//     int code;
//     cin >> code;
//     while (code >= red && code <= indigo)
//     {
//         switch(code)
//         {
//             case red    : cout << "Her lips were red.\n"; break;
//             case orange : cout << "Her hair was orange.\n"; break;
//             case yellow : cout << "Her shoes were yellow.\n"; break;
//             case green  : cout << "Her nails were green.\n"; break;
//             case blue   : cout << "Her sweatsuit was blue.\n"; break;
//             case violet : cout << "Her eyes were violet.\n"; break;
//             case indigo : cout << "Her mood was indigo.\n"; break;
//         }
//         cout << "Enter the color code (0-6): ";
//         cin >> code;
//     }
//     cout << "Bye\n";
//     return 0;
// }

// 6.5.2 switch和if else
// switch 一个 整型 常量
// if else 取值范围 可浮点型 可变量

//6.6 break和continue语句
//程序清单6.12 jump.cpp
// jump.cpp -- using continue and break
// #include <iostream>
// const int ArSize = 80;
// int main()
// {
//     using namespace std;
//     char line[ArSize];
//     int spaces = 0;

//     cout << "Enter a line of text:\n";
//     cin.get(line, ArSize);
//     cout << "Complete line:\n" << line << endl;
//     cout << "Line through first period:\n";
//     for (int i = 0; line[i] != '\0'; i++)//continue不会跳过for循环的更新表达式and测试表达式
//     {
//         cout << line[i];
//         if (line[i] == '.')
//             break;
//         if (line[i] != ' ')
//             continue;//goto paris;
//         spaces++;
//     }
//     cout << "\n" << spaces << " spaces\n";
//     /*paris:*/ cout << "Done.\n";
//     return 0;
// }

//goto语句

//6.7读取数字的循环
// 程序清单6.13 cinfish.cpp
// cinfish.cpp -- non-numeric input terminates loop
// #include <iostream>
// const int Max = 5;
// int main()
// {
//     using namespace std;
// //get data
//     double fish[Max];
//     cout << "Please enter the weights of your fish.\n";
//     cout << "You may enter up to " << Max
//             << " fish <q to terminate>.\n";
//     cout << "fish #1: ";
//     int i = 0;
//     while (i < Max && cin >> fish[i])
//     {
//         if (++i < Max)
//             cout << "fish #" << i+1 << ": ";
//     }
// //calculate average
//     double total = 0.0;
//     for (int j = 0; j < i; j++)
//         total += fish[j];
// //report results
//     if (i == 0)
//         cout << "No fish\n";
//     else
//         cout << total / i << " = average weight of "
//             << i << " fish\n";
//     cout << "Done.\n";
//     return 0;
// }
//clear()方法输入错误标记和文件尾
//程序清单6.14 cingolf.cpp
//cingolf.cpp -- non-numeric input skiiped
// #include <iostream>
// const int Max = 5;
// int main()
// {
//     using namespace std;
// //get data
//     int golf[Max];
//     cout << "Please enter your golf scores.\n";
//     cout << "You must enter " << Max << " rounds.\n";
//     int i;
//     for (i = 0; i < Max; i++)
//     {
//         cout << "round #" << i+1 << ": ";
//         while (!(cin >> golf[i]))
//         {
//             cin.clear();
//             while(cin.get() != '\n')//' '
//                 continue;
//             cout << "Please enter a number: ";
//         }
//     }
// //calculate average
//     double total = 0.0;
//     for (i = 0; i < Max; i++)
//         total += golf[i];
// //report results
//     cout << total / Max << " = average score "
//             << Max << " rounds\n";

//     return 0;
// }

//6.8 简单的文件输入/输出
//6.8.1 文本I/O和文本文件
//6.8.2 写入到文本文件中

//总之，使用文件输出的主要步骤如下。
// 1．包含头文件fstream。   头文件
// 2．创建一个ofstream对象。    创建对象
// 3．将该ofstream对象同一个文件关联起来。  《关联》
// 4．就像使用cout那样使用该ofstream对象。  使用

//程序清单6.15 outfile.cpp
//outfile.cpp -- writing to a file
// #include <iostream>
// #include <fstream>
// int main()
// {
//     using namespace std;

//     char automobile[50];
//     int year;
//     double a_price;
//     double d_price;

//     ofstream outFile;   //create object for output
//     outFile.open("carinfo.txt");    //associate with a file

//     cout << "Enter the make and model of automobile: ";
//     cin.getline(automobile, 50);
//     cout << "Enter the model year: ";
//     cin >> year;
//     cout << "Enter the original asking price: ";
//     cin >> a_price;
//     d_price = 0.913 * a_price;
// //display information on screen with cout
//     cout << fixed;
//     cout.precision(2);
//     cout.setf(ios_base::showpoint);
//     cout << "Make and model: " << automobile << endl;
//     cout << "Year: " << year << endl;
//     cout << "Was asking $" << a_price << endl;
//     cout << "Now asking $" << d_price << endl;
// //now do exact sanme things using outFile instead of cout
//     outFile << fixed;
//     outFile.precision(2);
//     outFile.setf(ios_base::showpoint);
//     outFile << "Make and model: " << automobile << endl;
//     outFile << "Year: " << year << endl;
//     outFile << "Was asking $" << a_price << endl;
//     outFile << "Now asking $" << d_price << endl;
//     outFile.close();
//     return 0;
// }

//6.8.3 读取文本文件
//方法is_open()
//exit()的原型 EXIT_FAILURE 头文件cstdlib
//程序清单6.16 sumafile.cpp
//sumafile.cpp -- functions with an array argument
#include <iostream>
#include <fstream> //file I/O support
#include <cstdlib>  //support for exit()
const int SIZE = 60;
int main()
{
    using namespace std;
    char filename[SIZE];
    ifstream inFile;

    cout << "Enter name of data file: ";
    cin.getline(filename, SIZE);
    inFile.open(filename);//associate inFile with a file
    if (!inFile.is_open())//failed to open a file
    {
        cout << "Could not open the file " << filename << endl;
        cout << "Program terminating.\n";
        exit(EXIT_FAILURE);
    }
    double value;
    double sum;
    int count = 0;//number of items read

    inFile >> value;// get first value
    while(inFile.good())//while input good and not at EOF
    //good()指出最后一次读取操作是否成功。
    //应在执行读取输入操作后，立即应用这种测试。
    {
        ++count;//one more item read
        sum += value;//calculate running total
        inFile >> value;//get next value
    }
    if (inFile.eof())//到达文件尾
        cout << "End of file reached.\n";
    else if (inFile.fail())//文件尾or类型不匹配
        cout << "Input terminated by data mismatch.\n";
    else
        cout << "Input terminated for unknown reasons.\n";
    if (count == 0)
        cout << "No data processed.\n";
    else
    {
        cout << "Items read: " << count << endl;
        cout << "Sum: " << sum << endl;
        cout << "Average: " << sum / count << endl;
    }
    inFile.close();
    return 0;
}

//standard file-reading loop design
//inFile >> value;
//while (inFile.good())
// {
//     //loop body goes here
//     inFile >> value;
// }

// abbreviated file-reading loop design
// omit pre-loop input
// while (inFile >> value)//read and test for success
// {
//     //loop body goes here
//     //omit end-of-loop input
// }

//都遵循在测试前读取的规则
