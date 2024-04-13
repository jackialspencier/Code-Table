//arrayone.cpp -- small arrays of integers
// #include <iostream>
// int main()
// {
//     using namespace std;
//     int yams[3];
//     yams[0] = 7;
//     yams[1] = 8;
//     yams[2] = 6;
//     int yamcosts[3] = {20, 30, 5};

//     cout << "Total yams = ";
//     cout << yams[0] + yams[1] + yams[2]  << endl;
//     cout << "The package with " << yams[1] << " yams costs ";
//     cout << yamcosts[1] << " cents per yam.\n";
//     int total = yams[0] * yamcosts[0] + yams[1] * yamcosts[1];
//     total = total + yams[2] * yamcosts[2];
//     cout << "The total yam expense is " << total << " cents.\n";

//     cout << "\nSize of yams array = " << sizeof yams;
//     cout << " bytes.\n";
//     cout << "Size of one element = " << sizeof yams[0];
//     cout << " bytes.\n";
//     return 0;


// }

// #include <iostream>
// using namespace std;
// int main()
// {
//     char ch = '\0123';//十六进制仅2个，八进制为3位。
//     cout << ch;
// }

//4.2.2在数组中使用字符串
//程序清单4.2 string.cpp
// #include <iostream>
// #include <cstring>
// int main()
// {
//     using namespace std;
//     const int Size = 15;
//     char name1[Size];
//     char name2[Size] = "C++owboy";
//     //NOTE: some implementations may require the static keyword
//     //to initialize the array name2

//     cout << "Howdy! I'm " << name2;
//     cout << "! What's your name?\n";
//     cin >> name1;
//     cout << "Well, " << name1 << ", your name has ";
//     cout << strlen(name1) << " letters and is stored\n";
//     cout << "in an array of "<< sizeof(name1) << " bytes.\n";
//     cout << "Your initial is " << name1[0] << ".\n";
//     name2[3] = '\0';
//     cout << "Here are the first 3 characters of my name: ";
//     cout << name2 << endl;

//     return 0; 
// }

//4.2.3 字符串输入
//程序清单4.3 instr1.cpp
// instr1.cpp -- reading more than one string
// #include <iostream>
// int main()
// {
//     using namespace std;
//     const int ArSize = 20;
//     char name[ArSize];
//     char dessert[ArSize];

//     cout << "Enter your name:\n";
//     cin >> name;
//     cout << "Enter your favorite dessert:\n";
//     cin >> dessert;
//     cout << "I have some delicious " << dessert;
//     cout << " for you, " << name << ".\n";

//     return 0; 
// }

//4.2.4 每次读取一行字符输入
//1.面向行的输入
//程序清单4.4 instr2.cpp
//instr2.cpp -- reading more than one word with getline
// #include <iostream>
// int main()
// {
//     using namespace std;
//     const int ArSize = 20;
//     char name[ArSize];
//     char dessert[ArSize];

//     cout << "Enter your name:\n";
//     cin.getline(name, ArSize);
//     cout << "Enter your favorite dessert:\n";
//     cin.getline(dessert, ArSize);
//     cout << "I have some delicious " << dessert;
//     cout << " for you, " << name << "\n";
//     return 0;
// }

//2.面向行的输入
//程序清单4.5 instr3.cpp
//instr3.cpp -- reading more than one word with get() & get()
// #include <iostream>
// int main()
// {
//     using namespace std;
//     const int ArSize = 20;
//     char name[ArSize];
//     char dessert[ArSize];

//     cout << "Enter your name:\n";
//     cin.get(name, ArSize).get();
//     cout << "Enter your favorite dessert:\n";
//     cin.get(dessert, ArSize).get();
//     cout << "I have some delicious " << dessert;
//     cout << " for you, " << name << ".\n";
//     return 0;
// }

// //4.2.5混合输入字符串和数字
// #include <iostream>
// using namespace 
// //
// #include <iostream>
// using  namespace std;
// int main()
// {
//     char ch;
//     cin >> ch;
//     switch (ch)
//     {
//         case 'a': cout << "vowel";
//                 break;
//         case 'e': cout << "vowel";break;
//         case 'i': cout << "vowel";break;
//         case 'o': cout << "vowel";break;
//         case 'u': cout << "vowel";break;
//         default : cout << "constant";break;
//     }
//     return 0;
// }

// 4.3 string类简介
// 程序清单4.7 strtypr1.cpp
// strtype1.cpp -- using the C++ string class
// #include <iostream>
// #include <string>
// int main()
// {
//     using namespace std;
//     char charr1[20];
//     char charr2[20] = "jaguar";
//     string str1;
//     string str2 = "panther";

//     cout << "Enter a kind of feline: ";
//     cin >> charr1;
//     cout << "Enter another kind of feline: ";
//     cin >> str1;
//     cout << "Here are some felines:\n";
//     cout << charr1 << " " << charr2 << " " 
//         << str1 << " " << str2
//         << endl;
//     cout << "The third letter in " << charr2 << " is "
//         << charr2[2] << endl;
//     cout << "Th ethird letter in " << str2 << " is "
//         << str2 [2] << endl;
//     return 0;
// }

//4.3.1 C++字符串初始化
//程序清单4.8 strtype2.cpp
//strtyp2.cpp -- assigning, adding, and appending
// #include <iostream>
// #include <string>
// int main()
// {
//     using namespace std;
//     string s1 = "penguin";
//     string s2, s3;
//     cout << "You can assign one string object to another: s2 = s1\n";
//     s2 = s1;
//     cout << "s1: " << s1 << ", s2: " << s2 << endl;
//     cout << "You can assign a C-style string to a string object.\n";
//     cout << "s2 = \"buzzard\"\n";
//     s2 = "buzzard";
//     cout << "s2: " << s2 << endl;
//     cout << "You can concatenate strings: s3 = s1 + s2\n";
//     s3 = s1 + s2;
//     cout << "s3: " << s3 << endl;
//     cout << "You can append strings.\n";
//     s1 += s2;
//     cout << "s1 += s2 yields s1 = " << s1 << endl;
//     s2 += " for a day";
//     cout << "s2+= \" for a day\" yields s2 = " << s2 << endl;

//     return 0;
// }

//4.3.3string类的其他操作
//程序清单4.9 strtypr3.cpp
// strtype.cpp -- more string class features
// #include <iostream>
// #include <cstring>
// #include <string>
// int main()
// {
//     using namespace std;
//     char charr1[20];
//     char charr2[20] = "jaguar";
//     string str1;
//     string str2 = "panther";

//     str1 = str2;
//     strcpy(charr1, charr2);

//     str1 += " paste";
//     strcpy(charr1, charr2);

//     int len1 = str1.size();
//     int len2 = strlen(charr1);

//     cout << "The string " << str1 << " contains "
//         << len1 << " characters.\n";
//     cout << "The string " << charr1 << " contains "
//         << len2 << " characters.\n";
    
//     return 0;
// }

//4.3.4string类I/O
//程序清单4.10 strtype4.cpp
// strtype4.cpp -- line input
// #include <iostream>
// #include <cstring>
// #include <string>
// int main()
// {
//     using namespace std;
//     char charr[20];
//     string str;

//     cout << "Length of string in charr before input: "
//         << strlen(charr) << endl;
//     cout << "Length of string in str before input: "
//         << str.size() << endl;
//     cout << "Enter a line of text:\n";
//     cin.getline(charr, 20);
//     cout << "You entered: " << charr << endl;
//     cout << "Enter another line of text:\n";
//     getline(cin, str);//非类方法
//     cout << "You entered: " << str << endl;
//     cout << "Length of string in charr after input: " 
//         << strlen(charr) << endl;
//     cout << "Length of string in str after input: "
//         << str.size() << endl;

//     return 0;
// }

//"\n"

//4.4结构简介
// #include <iostream>
// using namespace std;
// int main(){
// //定义结构
//     struct inflatable
//     {
//         char name[20];//每个列表项都是一条声明语句
//         float volume;//结构的成员
//         double price;
//     };//结构储存的数据类型的列表
// //创建变量（声明结构变量）
//     inflatable hat;
//     inflatable woopie_cushion;
//     inflatable mainframe;
//     struct inflatable goose;
//     inflatable vincent;
// //访问结构成员
//     vincent.price;
//     hat.price;
//     hat.volume;//一个double变量
// }

//4.4.1在程序中使用结构
//在外部声明符号常量通常更合理？//符号常量？

//程序清单4.11 structur.cpp
//structur.cpp -- a simple structure
// #include <iostream>
// struct inflatable
// {
//     char name[20];
//     float volume;
//     double price;
// };

// int main()
// {
//     using namespace std;
//     inflatable guest = 
//     {
//         "Glorious Gloria",
//         1.88,
//         29.99
//     };
//     inflatable pal = 
//     {
//         "Audacious Arthur",
//         3.12,
//         32.99,//诶，这是可以多加逗号嘛。
//     };

//     cout << "Expand your guest list with " << guest.name;
//     cout << " and " << pal.name << "!\n";
//     cout << "You can have both for $";
//     cout << guest.price + pal.price << "!\n";

//     return 0;
// }

//4.4.2 C++结构初始化
//等号可省略
// inflatable duck {"Daphne", 0.12, 9.98};
//空——0
// inflatable mayor {};//mayor.name每个字节都被设置为0
//不可缩窄转换

//4.4.3结构可以将string类作为成员吗//只要编译器支持对以string对象作为成员的结构初始化
// #include <string>
// struct inflatable
// {
//     std::string name;//一定要让结构定义能访问名称空间std
//     float volume;
//     double price;
// };

//4.4.4其他结构属性
//结构赋值，传递和返回结构
//结构赋值
//程序清单4.12 assgn_st.cpp
//assgn_st.cpp -- assigning structures
// #include <iostream>
// struct inflatable
// {
//     char name[20];
//     float volume;
//     double price;
// };
// int main()
// {
//     using namespace std;
//     inflatable bouquet = 
//     {
//         "sunflowers",
//         0.20,
//         12.49
//     };
//     inflatable choice;
//     cout << "bonquet: " << bouquet.name << "for $";
//     cout << bouquet.price << endl;

//     choice = bouquet;
//     cout << "choice: " << choice.name << "for $";
//     cout << choice.price << endl;

//     return 0;
// }

//同时定义结构和创建结构变量
// struct perks
// {
//     int key_number;
//     char car[12];
// } mr_smith, ms_jones;

//并同时初始化
// struct perks
// {
//     int key_number;
//     char car[12];
// } mr_glitz = 
// {
//     7,
//     "Packard"
// };//注意一下;

//声明没有名称（标记）的结构类型，同时定义一该类型变量。
//之后无法创建该类型变量
// struct //no tag
// {
//     int x; //2 members
//     int y;
// } position; //a structure variable
//使用结构标记作为类型名称
//高级特性（如成员函数）

//4.4.5 结构数组
//创建结构数组
// using namespace std;
// struct inflatable
// {
//     char name[20];
//     float volume;
//     double price;
// };
// inflatable gifts[100];

//访问数组元素的成员（成员运算符plus句点运算符）
// cin >> gifts[0].volume;
// cout << gifts[99].price << endl;

//gifts.price的gifts为什么不是首元素？

//how？？？？？？两个初始化位于同一行，而每个结构成员的初始化各占一行。

//初始化结构数组
// inflatable guests[2] = 
// {
//     {"Bambi", 0.5, 21.99},
//     {"Godzailla", 2000, 565.99}
// };

//程序清单4.13 anstruc.cpp
// arrstruc.cpp -- an array of structures
// #include <iostream>
// struct inflatable
// {
//     char name[20];
//     float volume;
//     double price;
// };
// int main()
// {
//     using namespace std;
//     inflatable guests[2] = 
//     {
//         {"Bambi", 0.50, 21.99},
//         {"Godzilla", 2000, 565.99}
//     };

//     cout << "The guests " << guests[0].name << " and " << guests[1].name
//         << "\nhave a combined volume of "
//         << guests[0].volume + guests[1].volume << " cubic feet.\n";

//     return 0;
// }

//4.4.6 结构中的位字段
//间距意义是？
//允许指定占用特定位数的结构成员
// struct torglr_register
// {
//     unsigned int SN : 4;
//     unsigned int : 4;
//     bool goodIn : 1;
//     bool goodTorglr : 1;
// };
// torgle_register tr = {14, true, false};
// ...
// if (tr.goodIn)
// ...

//4.5共用体
//或 不同的时间进行
// union one4all
// {
//     int int_val;
//     long long_val;
//     double double_val;
// };
// one4all pail;
// pail.int_vail = 15;    //store an int
// cout << pail.int_val;
// pail.double_val = 1.38;//store a double, int value is lost
// cout << pail_val;

//共用体的用途——节省空间——常用于节省内存
// struct widget
// {
//     char brand[20];
//     int type;
//     union id
//     {
//         long id_num;
//         char id_char[20];//注意引号
//     } id_val;//注意引号
// };
// //...
// widget prize;
// //...
// if (wedget.type == 1)
//     cin >> widget.id_val.id_num;
// else
//     cin >> widget.id_val.id_char;

//匿名共用体
// struct widget
// {
//     char brand[20];
//     int type;
//     union
//     {
//         int id_num;
//         char id_char[20];
//     } id_val;
// };
// //...
// widget prize;
// if (widget.type == 1)
//     cin >> widget.id_num;
// else
//     cin >> widget.id_char;//两个都是prize的成员，确定哪个成员是活动的。

//4.6 枚举(enumeration)
//enum 另一种创建符号常量的方式
//可代替const
//允许定义新类型?
// enum spectrum {red, orange, yellow, blue, violet, indigo, ultraviolet};
// spectrum band; //band a variable of type spectrum
// band = blue;//不进行强制类型转换情况，尽可将定义枚举时用的枚举量赋给这种枚举的变量
// band = 2000;//invalid
//只定义了赋值运算符
//提升为int，int不可自动转化为枚举类型
//强制类型转换
// band = spectrum(3);
// band = spectrum(40003);//undefined
//匿名（？）枚举：只使用常量，不创建枚举类型的变量

//4.6.1设置枚举类型的值
//自动
//赋值运算符显式设置--必须为整数
// enum bits{one = 1, two = 2, four = 4, eight = 8};
//设置一部份
// enum bigste{first, second = 100, third}; //未被初始化的枚举量比前面的大1
//创建多个值相同的枚举量
// enum {zero, null = 0, one, numero_one = 1};
//(早期)只能将int值（or升成int的值）赋给枚举量-->限制取消，long甚至long long

//4.6.2 枚举的取值范围
//强制类型转化
//上限（上界）——最大值，大于他的2幂-1
//下限（下界）——最小值——（不小于0）0or 2的幂加符号+1
//作用域内枚举

//4.7指针和自由储存空间
//地址运算符&的用法
//程序清单4.14 address.cpp
//address.cpp -- using the & operator to find addresses
// #include <iostream>
// int main()
// {
//     using namespace std;
//     int donuts = 6;
//     double cups = 4.5;

//     cout << "donuts = " << donuts;
//     cout << " and donuts address = " << &donuts << endl;
//     //maybe unsigned(donuts/cups)
//     cout << "cups = " << cups;
//     cout << " and cups address = " << &cups << endl;
//     return 0;
// }
//先储存了cups？

//间接值或解除引用运算符
//程序清单4.15 pointer.cpp
//pointer.cpp -- our first pointer variable
// #include <iostream>
// int main()
// {
//     using namespace std;
//     int updates = 6;//declare a variable
//     int * p_updates;//declare pointer to an int

//     p_updates = &updates;//assign address of int to pointer

//     //express values in two ways
//     cout << "Values: updates = " << updates;
//     cout << ", *p_updates = " << *p_updates << endl;

//     //express address two ways
//     cout << "Addresses: &updates = " << &updates;
//     cout << ", p_updates = " << p_updates << endl;

//     //use pointer to change value
//     *p_updates = *p_updates + 1;
//     cout << "Now updates = " << updates << endl;
//     return 0;
// }

//4.7.1 声明和初始化指针
//p_updates指向int类型   p_updates是指向int的指针   
//int* p1, p2
//创建了一个指针和一个int变量
//对于每个指针变量名，都要用一个*
//（有些系统可能需要更大的地址，系统可以针对不同的类型使用不同长度的地址）。
//那不就可以说明类型了？
//程序清单4.16 init_ptr.cpp
// init_ptr.cpp -- initialize a pointer
// #include <iostream>
// int main()
// {
//     using namespace std;
//     int higgens = 5;
//     int * pt = &higgens;

//     cout << "Value of higgens = " << higgens
//         << "; Address of higgens = " << &higgens << endl;
//     cout << "Value of *pt = " << *pt
//         << ";Value of pt = " << pt << endl;

//     return 0;
// }

//4.7.2 指针的危险
//创建指针时分配了用来储存地址的内存，没有分配用来储存指针所指向数据的内存
// long * fellow;    //create a pointer-to-long
// *fellow = 223323; //place a value in never-never land
//放在哪里不知道，fellow可能是任何值
//需要初始化

//4.7.3 指针和数字
// int * pt;
// pt = 0xB8000000;//type mismatch
// int * pt;
// pt = (int *) 0xB000000;//type now match
//pt是int值的地址，不意味着pt本身的类型是int

//4.7.4 使用new来分配内存
//为可以通过名称直接访问的内存提供别名
//用武之地 —— 在运行阶段分配未命名的内存以储存值
//但pn指向的内存不是变量（？？？？？？？）
//程序清单4.17 use_new.cpp
//use_new.cpp -- using the new operator
// #include <iostream>
// int main()
// {
//     using namespace std;
//     int nights = 1001;
//     int * pt = new int;
//     *pt = 1001;

//     cout << "nights value = ";
//     cout << nights << "; location " << &nights << endl;
//     cout << "int ";
//     cout << "value = " << *pt << "; location = " << pt << endl;

//     double *pd = new double;
//     *pd = 10000001.0;

//     cout << "double ";
//     cout << "value = " << *pd << "; location = " << pd << endl;
    
//     cout << "location of pointer pd: " << &pd << endl;
//     cout << "size of pt = " << sizeof(pt);
//     cout << "; size of *pt = " << sizeof(*pt) << endl;
//     cout << "size of pd = " << sizeof(pd);
//     cout << "size of *pd = " << sizeof(*pd) << endl;

//     return 0;
// }

//地址本身只指出了对象储存地址的开始（，没有指出其类型1）

//4.7.5 使用delete释放内存
//new分配的，不要释放已释放的（不要释放声明变量获得的），对空指针使用安全
// int * ps = new int;//allocate memory
// int * pq = ps;//set second pointer to he same block
// delete pq; //delete with second pointer

//4.7.6 使用new来创建动态数组
//动态联编，程序在运行时确定数组长度
//1.使用new创建动态数组
//将数组的元素类型和元素数目告诉new
//new与delete的方括号格式匹配（不匹配——结果不确定）

//？？？如果使用new [ ]为一个实体分配内存，则应使用delete（没有方括号）来释放
//？？？不能使用sizeof运算符来确定动态分配的数组包含的字节数。
//之前不是有sizeof整的数组大小啥的？
// int * psome = new int [10];
// delete [] psome;


//2.使用动态数组
//如何使用new来创建动态数组以及使用数组表示法来访问元素
//指出了指针和真正的数组名之间的根本差别
//程序清单 4.18 arraynew.cpp
// arraynew.cpp -- using the new operator for arrays
// #include <iostream>
// int main()
// {
//     using namespace std;
//     double * p3 = new double [3];//space for 3 doubles
//     p3[0] = 0.2;                 //treat p3 like an array name
//     p3[1] = 0.5;
//     p3[2] = 0.8;
//     cout << "p3[1] is " << p3[1] << ".\n";
//     p3 = p3 + 1;                    //increment the pointer
//     cout << "Now p3[0] is " << p3[0] << " and ";
//     cout << "p3[1] is " << p3[1] << ".\n";
//     p3 = p3 - 1;                    //point back to the beginning
//     //指出了数组名和指针的根本差异
//     //不能修改数组名的值。指针说变量，可以修改它的值。
//     delete [] p3;                   //free the memory
//     return 0;
// }

//4.8指针、数组和算术指针
//程序清单4.19 addpntrs.cpp
// addpntrs.cpp -- pointer addition
// #include <iostream>
// int main()
// {
//     using namespace std;
//     double wages[3] = {10000.0, 20000.0, 30000.0};
//     short stacks[3] = {3, 2, 1};

//     //Here are two ways to get the address of an array
//     double * pw = wages;//name of an array
//     short * ps = &stacks[0];// or use address operator
//     //with an array element
//     cout << "pw = " << pw << ", *pw = " << *pw << endl;
//     pw = pw + 1;
//     cout << "add 1 to the pw pointer:\n";
//     cout << "pw = " << pw << ", *pw = " << *pw << "\n\n";

//     cout << "ps = " << ps << ", *ps = " << *ps << endl;
//     ps = ps + 1;
//     cout << "add 1 to the ps pointer:\n";
//     cout << "ps = " << ps << ", *ps = " << *ps << "\n\n";

//     cout << "access two elements with array notation\n";
//     cout << "stacks[0] = " << stacks[0]
//         << ", stacks[1] = " << stacks[1] << endl;
//     cout << "access two elements with pointer notation\n";
//     cout << "*stacks = " << *stacks
//         << ", *(stacks + 1) = " << *(stacks + 1) << endl;

//     cout << sizeof(wages) << " = size of wages array\n";//此时C++不将数组名解释为指针
//     cout << sizeof(pw) << " = size of pw pointer\n";

//     return 0;
// }

//4.8.1 程序说明
//数组名和指针区别
//1数组名不可以被修改
// pointername = pointername + 1;//valid
// arrayname = arrayname + 1;//not valid
//2sizeof——得到数组长度vs指针长度
//此时数组名不被解释为指针
//ps：对数组取地址时，数组名也不会被解释为其地址
// short tell[10];//tell an array of 20 bytes
// cout << tell << endl;//display &tell[0]
// cout << &tell << endl;//display address of whole array
//&tell[0]即tell是一个2字节内存块的地址——tell+1将地址加2
//&tell指向一个包含20个元素的short数组——&tell + 1将地址加20

// short (*pas)[20] = &tell;//pas points to array of 20 shorts
// short * pas[20]//省略括号，pas先与[]结合。pas是一个short指针数组，含20个元素 
//pas被设置为&tell所以*pas与tell等价

//4.8.2指针小结
//pa = new double[30] 的pa？pa+1？

//4.8.3 指针和字符串
// char flower[10] = "rose";
// cout << flower << "s are red";

//程序清单4.20 ptrstr.cpp
// ptrstr.cpp -- using pointers to strings
// #include <iostream>
// #include <cstring>
// int main()
// {
//     using namespace std;
//     char animal[20] = "bear";
//     const char * bird = "wren";//const,这种方法意味着可以用bird访问字符串，但不可以修改//字符串字面值是常量
//     char * ps;

//     cout << animal << " and ";
//     cout << bird << "\n";
//     //cout << ps << "\n"; //may display garbage, may cause a crash

//     cout << "Enter a kind of animal: ";
//     cin >> animal;
//     //cin >> ps //too horrible a blunder to try; ps doesn't point to allocated space

//     ps = animal;
//     cout << ps << "!\n";
//     cout << "Before using strcpy():\n";
//     cout << animal << " at " << (int *) animal << endl;//如果要显示的是字符串的地址，则必须将这种指针强制转换为另一种指针类型
//     cout << ps << " at " << (int *) ps << endl;

//     ps = new char[strlen(animal) + 1];
//     strcpy(ps, animal);

//     cout << "After using strcpy():\n";
//     cout << animal << " at " << (int *) animal << endl;
//     cout << ps << " at " << (int *) ps << endl;
//     delete [] ps;
//     return 0;
// }

//将值读入一个字符串可能会影响被认为是独立的、位于其他地方的字符串。
//啥啊？？？

// const char * bird;//禁止改变bird指向的位置中的内容
//那是否可以改变bird指向的位置呢？
//指向位置的值const与指向位置const？

//一般来说，如果给cout提供一个指针，它将打印地址。但如果指针的类型为char *，则cout将显示指向的字符串
//attention:将animal赋给ps并不会复制字符串，而只是复制地址。这样，这两个指针将指向相同的内存单元和字符串。
//不是副本


//通过声明另一个数组或使用new来完成。后一种方法使得能够根据字符串的长度来指定所需的空间
//声明数组的size内不可以使用strlen()吗

//初始化数组
// char food[20] = "carrots";
// strcpy(food, "flan");

//如果该函数在到达字符串结尾之前，目标内存已经用完，则它将不会添加空字符。
// strncpy(food, "a picnic basket filled with many goodies", 19);
// food[19] = '\0';
//目标内存这不是没用完吗，为什么要手动添加？
//还是对于要复制的最大字符数有没有用完？

//？？？why应使用strcpy( )或strncpy( )，而不是赋值运算符来将字符串赋给数组？？

// 4.8.4 使用new创建动态结构
//使用new创建一个未命名的结构
//演示了两种访问结构成员的指针表示法
//程序清单4.21 newstrct.cpp
// newstrct.cpp -- using new with a structure
// #include <iostream>
// struct inflatable //struct definition
// {
//     char name[20];
//     float volume;
//     double price;
// };
// int main()
// {
//     using namespace std;
//     inflatable * ps = new inflatable;
//     cout << "Enter the name of inflatable item: ";
//     cin.get(ps -> name, 20);
//     cout << "Enter volume in cubic feet: ";
//     cin >> (*ps).volume;
//     cout << "Enter price: $";
//     cin >> ps -> price;
//     cout << "Name: " << (*ps).name << endl;
//     cout << "Volume: " << ps -> volume << " cubix feet\n";
//     cout << "Price: $" << ps -> price << endl;
//     delete ps;
//     return 0;
// }

//1.一个使用new和delete的示例
//程序清单4.22定义了一个函数getname( )，该函数返回一个指向输入字符串的指针。
//该函数将输入读入到一个大型的临时数组中，
//然后使用new [ ]创建一个刚好能够存储该输入字符串的内存块，
//并返回一个指向该内存块的指针。

//另外，还可以使用new根据需要的指针数量来分配空间。就目前而言，这有点不切实际，即使是使用1000个指针的数组也是这样
//啥啥啥？

//程序清单4.22 delete.cpp
//delete.cpp -- using the dekete operator
// #include <iostream>
// #include <cstring>
// using namespace std;
// char * getname(void);
// int main()
// {
//     char * name;

//     name = getname();
//     cout << name << " at " << (int *) name << endl;
//     delete [] name;

//     name = getname();
//     cout << name << " at " << (int *) name << endl;
//     delete [] name;//说明new和delete可以分开放置，但只是说明，自己别这么干，容易忘记。

//     return 0;
// }
// char * getname(void)
// {
//     char temp[80];

//     cout << "Enter last name: ";//
//     cin >> temp;
//     char * pn = new char[(strlen(temp) + 1)];
//     strcpy(pn, temp);//

//     return pn;//temp lost when function ends//if指清除，pn没被清除？if 丢失，是好事算不占内存？
// }

//4.8.5自动储存、静态储存和动态储存（自由储存空间or栈）
//1自动储存（那C语言的指针传递信息呢？）
//常规变量
//2静态储存
//3动态储存
//自由储存空间

//4.9类型组合
//程序清单4.23 mixtypes.cpp
// mixtypes.cpp -- some type combinations
// #include <iostream>

// struct antarctica_years_end
// {
//     int year;
// /* some really interesting data, etc. */
// };

// int main()
// {
//     antarctica_years_end s01, s02, s03;
//     s01.year = 1998;
//     antarctica_years_end * pa = &s02;
//     pa -> year = 1999;
//     antarctica_years_end trio[3];
//     trio[0].year = 2003;
//     std::cout << trio -> year << std::endl;
//     const antarctica_years_end * arp[3] = {&s01, &s02, &s03};
//     std::cout << arp[1] -> year << std::endl;
//     const antarctica_years_end ** ppa = arp;
//     auto ppb = arp;
//     std::cout << (*ppa) -> year << std::endl;
//     std::cout << (*(ppb + 1)) -> year << std::endl;
//     return 0;
// }

//4.10 数组的替代品
//4.10.1 模板类vector
// #include <vector>
// #include <iostream>
// using namespace std;
// using std::cout;
// using std::cin;
// using std::vector;
// vector<int> vi;
// int n;
// cin >> n;//为了说明可以是整型变量
// vector<double> vd(n);
// vector<typeName> vt(n_elem);//n_elem可以是整型常量/变量

//4.10.2模板类array（C+11）
//与数组一样，array对象的长度也是固定的，
//也使用栈（静态内存分配），而不是自由存储区，因此其效率与数组相同
//为什么是也，当new时，数组动态储存，stastic静态，其余自动储存不是吗？
// #include <array>
// using namespace std;
// array<int, 5> ai;
// array<double, 4> ad = {1.2, 2.1, 3.43, 4.3};
//声明创建一个名为arr的array对象，它包含n_elem个类型为typename的元素：
// array<typeName, n_elem> arr;//n_elem不能是变量

//4.10.3比较数组、vector对象和array对象
// 程序清单4.24 choices.app
// choices.app -- array variations
#include <iostream>
#include <array>
#include <vector>
int main()
{
    using namespace std;
    //C, original C++
    double a1[4] = {1.2, 2.4, 3.6, 4.8};
    // C++98, STL
    vector<double> a2(4);
    //no simpl way to initialize in C98
    a2[0] = 1.0/3.0;
    a2[1] = 1.0/5.0;
    a2[2] = 1.0/7.0;
    a2[3] = 1.0/9.0;
    //C++11 -- create and initialize array object
    array<double, 4> a3 = {3.14, 2.72, 1.62, 1.41};
    array<double, 4> a4;
    a4 = a3;//valid for array objects of same size
    //use array notation
    cout << "a1[2]: " << a1[2] << " at " << &a1[2] << endl;
    cout << "a2[2]: " << a2[2] << " at " << &a2[2] << endl;
    cout << "a3[2]: " << a3[2] << " at " << &a3[2] << endl;
    cout << "a4[2]: " << a4[2] << " at " << &a4[2] << endl;
//misdeed
    a1[-2] = 20.2;
    cout << "a1[-2]: " << a1[-2] << " at " << &a1[-2] << endl;
    cout << "a3[2]: " << a3[2] << " at " << &a3[2] << endl;
    cout << "a4[2]: " << a4[2] << " at " << &a4[2] << endl;
    return 0;

}