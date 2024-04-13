//第二章——开始学习C++
//2.1 进入C++
//程序清单2.1 myfirst.cpp
// #include <iostream>
// int main()
// {
//     using namespace std;
//     cout << "Come up and C++ me some time.";
//     cout << endl;
//     cout << "You won't regret it!" << endl;
//     return 0; 
// }

//程序清单2.2 carrot.cpp
//carrot.cpp -- food processing program
//uses and displays a variable
// #include <iostream>
// int main()
// {
//     using namespace std;

//     int carrots;

//     carrots = 25;
//     cout << "I have ";
//     cout << carrots;
//     cout << " carrots.";
//     cout << endl;
//     carrots = carrots - 1;
//     cout << "Crunch, crunch, Now I have " << carrots << " carrots." << endl;
//     return 0;
// }


//2.3 其他C++语句
//程序清单2.3 getinfo.cpp
//getinfo.cpp -- input and output
// #include <iostream>
// int main()
// {
//     using namespace std;

//     int carrots;

//     cout << "How many carrots do you have?" << endl;
//     cin >> carrots;
//     cout << "Here are tow more. ";
//     carrots = carrots + 2;
//     cout << "Now you have " << carrots << " carrots." << endl;
//     return 0;
// }

//2.4 函数
//程序清单2.4 sqrt.cpp
// #include <iostream>
// #include <cmath>

// int main()
// {
//     using namespace std;

//     double area;
//     cout << "Enter rhe floor area, in square feet, of your home: ";
//     cin >> area;
//     double side;
//     side = sqrt(area);
//     cout << "That's the equivalent of a square " << side
//          << " feet to the side." << endl;
//     cout << "How fascinating!" << endl;
//     return 0;
// }

//2.4.3 用户定义的函数
//程序清单2.5 ourfunc.cpp
//ourfunc.cpp --defining your own function
// #include <iostream>
// void simon(int);

// int main()
// {
//     using namespace std;
//     simon(3);
//     cout << "Pick an integer: ";
//     int count;
//     cin >> count;
//     simon(count);
//     cout << "Done!" << endl;
//     return 0;
// }

// void simon(int n)
// {
//     using namespace std;
//     cout << "Simon says touch your toes " << n << " times." << endl;
// }

//2.4.4 用户定义定义的有返回值的函数
//程序清单2.6 convert.cpp
//convert.cpp -- converts stone to pounds
// #include <iostream>
// int stonetolb(int);
// int main()
// {
//     using namespace std;
//     int stone;
//     cout << "Enter the weight in stone: ";
//     cin >> stone;
//     int pounds = stonetolb(stone);
//     cout << stone << "stone = ";
//     cout << pounds << " pounds." << endl;
//     return 0;
// }

// int stonetolb(int sts)
// {
//     return 14 * sts;
// }

//2.4.5 在多函数程序中使用using编译指令
//程序清单2.5改版
//ourfunc1.cpp -- repositioning the using directive
// #include <iostream>
// using namespace std;
// void simon(int);

// int main()
// {
//     simon(3);
//     int count;
//     cout << "Enter an integer: ";
//     cin >> count;
//     simon(count);
//     cout << "Done!" << endl;
//     return 0;
// }

// void simon(int n)
// {
//     cout << "Simon says touch your toe " << n << " times." << endl;
// }

//have a try in C++ class
// #include <iostream>
// using namespace std;
// int main(void)
// {
//     cout << std::fixed << std::endl;

//     int a, b;
//     cin >> a >> b;
//     cout << a << " " << b << endl;

//     return 0;
// }
