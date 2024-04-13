// #include <iostream>

// template<class T>
// T maxx(T a, T b)
// { return a > b ? a : b; }

// int main()
// {
//     using namespace std;
//     int maxNum = maxx(3,7);
//     char maxChar = maxx('z', 'a');
//     double maxDouble = maxx(3.5, 4.6);
//     float maxFloat = max<float>(3.5, 4.6);

//     cout << maxNum << endl;
//     cout << maxChar << endl;
//     cout << maxDouble << endl;
//     cout << maxFloat << endl;

//     return 0;
// }

// #include <iostream>
// using namespace std;
// void print (int n);
// int main()
// {
//     print(3);
//     return 0;
// }
// void print(int n)
// {
//     if (n < 0)
//         return;
//     cout << n << endl;
//     print(n - 1);
// }

// 递归的标准模式
//递归的形式
// 阶乘函数
// #include <iostream>
// using namespace std;
// int fact(int n);
// int main()
// {
//     cout << fact(3) << endl;
//     return 0;
// }
// int fact(int n)
// {
//     if (n == 0) 
//         return 1;
//     else
//         return n * fact(n-1);
// }

// 递归举例：求n的k次幂
// #include <iostream>
// using namespace std;
// int RaiseIntPower(int n, int k);
// int main()
// {
//     cout << RaiseIntPower(9, 3) << endl;
//     return 0;
// }
// int RaiseIntPower(int n, int k)
// {
//     if (k == 0)
//         return 1;
//     else
//         return n * RaiseIntPower(n, k-1);
// }

// 递归举例：Fibonacci函数
// #include <iostream>
// using namespace std;
// int f(int);
// int main()
// {
//     for (int i = 0; i < 20; i++)
//         cout << i << ": " << f(i) << endl;
//     return 0;
// }
// int f(int n)
// {
//     if (n == 0)
//         return 0;
//     else if (n == 1)
//         return 1;
//     else
//         return f(n - 1) + f(n - 2);
// }

//Fabonacci的迭代实现
// #include <iostream>
// using namespace std;
// int f(int n);
// int main()
// {
//     for (int i = 0; i < 20; i++)
//         cout << i << " : " << f(i) << endl;
//     return 0;
// }
// int f(int n)
// {
//     int f_n1 = 1;//写成fn_1, fn_2或许更有助于理解防止混淆。
//     int f_n2 = 0;
//     int fn;
//     if (n == 0)
//         return 0;
//     else if (n == 1)
//         return 1;
//     for (int i = 2; i <= n; i++)
//     {
//         fn = f_n1 + f_n2;//那个赋值1最初决定了哪个是靠后的。那么每次更新的时候靠前的更新成后，后更新成本fn。
//                             //不要混淆赋值对象。
//         f_n2 = f_n1;
//         f_n1 = fn;
//     }
//     return fn;
// }

//找硬币的递归实现
// 计算n角钱所需最少硬币数
// #include <iostream>
// using namespace std;
// int money(int n);
// int main()
// {
//     cout << money(18) << endl;
//     return 0;
// }
// // int money(int n)
// // {
// //     if (n == 1 || n == 2 || n == 5 || n == 10) return 1;
// //     int temp[4];
// //     int min = 0;
// //     temp[0] = 1 + money(n - 1);
// //     temp[1] = 1 + money(n - 2);
// //     temp[2] = 1 + money(n - 5);
// //     temp[3] = 1 + money(n - 10);
// //     for (int i = 0; i < 4; i++)
// //         if (temp[i] < min)
// //             min = temp[i];
// //     return min;
// // }

//right
// int money(int n)
// {
//     if (n == 0) return 0;//不能不写，要是要算的钱是0呢？
//     if (n == 1 || n == 2 || n == 5 || n == 10) return 1;
//     int min = money(n-1) + 1;
//     if (money(n-2) + 1 < min) min = money(n - 2) + 1;// n > 2
//     if (n > 5 && money(n - 5) + 1 < min) min = 1 + money(n - 5);
//     if (n > 10 && money(n - 10) + 1 < min) min = 1 + money(n - 10);
//     return min;
// }

//找硬币问题迭代实现
// 计算n角钱最少需要硬币数
// int money(int n)
// {
//     if (n == 0) return 0;
//     if (n == 1 || n == 2 || n == 5 || n == 10) return 1;
//     int nums[10000] = {0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 1};
//     for (int i = 3; i <= n; i++)
//     {
//         nums[i] = nums[i - 1] + 1;
//         if (i > 2 && nums[i - 2] + 1 < nums[i])  nums[i] = nums[i - 2] + 1;
//         if (i > 5 && nums[i - 5] + 1 < nums[i]) nums[i] = nums[i - 5] + 1;
//         if (i > 10 && nums[i - 10] + 1 < nums[i]) nums[i] = nums[i - 10] + 1;
//     }
//     return nums[n];
// }

// hannoi
// #include <iostream>
// unsigned long long int hannoi(char start, char finish, char temp, int plates);
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;
//     cout << hannoi('A', 'B', 'C', n);
//     return 0;
// }

// unsigned long long int hannoi(char start, char finish, char temp, int plates)
// {
//     static unsigned long long int count = 0;
//     if (plates == 1)
//     {
//         count++;
//         return 1;
//     }
//     hannoi(start, temp, finish, plates-1);
//     count++;
//     hannoi(temp, finish, start, plates-1);
//     return count;
// }


// #include <iostream>
// using namespace std;
// bool isPrime(int);
// int main()
// {
//     int m, n;
//     int count = 0;
//     cin >> m >> n;
//     for (int i = m; i <= n; i++)
//     {
//         if (isPrime(i))
//             count++;
//     }
//     cout << count;
//     return 0;
// }
// bool isPrime(int a)
// {
//     bool isP = true;
//     if (a == 1)
//         return false;
//     if (a == 2)
//         return true;
//     for (int i = 2; i < a; i++)
//         if (a % i == 0)
//         {
//             isP = false;
//             break;
//         }
//     return isP;
// }

// #include <iostream>
// using namespace std;
// bool perfectNumber(int a);
// int main()
// {
//     int m, n;
//     bool havePfct = false;
//     cin >> m >> n;
//     for (int i = m; i <= n; i++)
//     {
//         if (perfectNumber(i))
//         {
//             cout << i << " ";
//             havePfct = true;
//         }
//     }
//     if (!havePfct)
//         cout << "-1";
//     return 0;
// }
// bool perfectNumber(int a)
// {
//     int sum = 0;
//     for (int i = 1; i < a; i++)
//         if (a % i == 0)
//             sum+=i;
//     if (sum == a)
//         return true;
//     else
//         return false;
// }

// #include <iostream>
// using namespace std;
// void printInt(int num, int b);
// int main()
// {
//     int n, base;
//     cin >> n >> base;
//     printInt(n, base);
//     return 0;
// }

// void printInt(int num, int b)
// {
//     char chs[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
//     char numb[1000];
//     int i = 0;
//     while (num)
//     {
//         numb[i] = chs[num % b];
//         num = num / b;
//         i++;
//     }
//     for (int j = i - 1; j >= 0; j--)
//         cout << numb[j];
// }

// #include <iostream>
// using namespace std;
// void valid(int a);
// int main()
// {
//     int n;
//     cin >> n;
//     valid(n);
//     return 0;
// }

// void valid(int a)
// {
//     while(a != 1)
//     {
//         cout << a << " ";
//         if (a % 2 == 1)
//             a = a * 3 + 1;
//         else
//             a = a / 2;
//     }
//     cout << a;
// }

#include<iostream>
using namespace std;
// int fib();
// int main()
// {
//     for (int i = 0; i < 10; i++)
//         cout << fib() << endl;
//     return 0;
// }
// int fib()
// {
//     static unsigned i = 0;
//     i++;
//     static int f_n1 = 1, f_n2 = 1, fn = 2;//这几个也要是静态呀
//     if (i == 1 || i == 2)
//         return 1;
//     if (i == 3)
//         return 2;
//     //接下来， 每调用一次移一位， 输出fn
//     f_n1 = f_n2;
//     f_n2 = fn;
//     fn = f_n1 + f_n2;
//     return fn;
// }


// #include<iostream>  
// using namespace std; 

// int f(int a);
// int main(){
// 	int n,m;
//     cin>>n>>m;
//     if(n<m) cout<<"wrong";
//     else cout<<f(n)/f(m)/f(n-m);
//     return 0;
// }

// int f(int a)
// {
//     int ans = 1;
//     for (int i = 1; i <= a; i++)
//         ans *= i;
//     return ans;
// }

// #include <iostream>
// using namespace std;
// double calculate (double a, double b);
// int main()
// {
//     int t;
//     double answers[100];
//     cin >> t;
//     for (int i = 0; i < t; i++)
//     {
//         double m, n;
//         cin >> m >> n;
//         answers[i] = calculate(m, n);
//     }
//     for (int i = 0; i < t; i ++)
//         cout << answers[i] << " ";
//     return 0;

// }
// double calculate (double a, double b)
// {
//     double ans;
//     ans = 1.0/ (((1.0 / a) + (1.0 / b)) / 2);
//     return ans;
// }

// #include <iostream>
// using namespace std;
// int CountDigit(int number,int digit);
// int main()
// {
//     int m, n;
//     cin >> m >> n;
//     cout << CountDigit(m, n);;
//     return 0;
// }
// int CountDigit(int number,int digit)
// {
//     int count = 0;
//     if (digit < 10)
//         while (number)
//         {
//             if (number % 10 == digit)
//                 count++;
//             number /= 10;
//         }
//     else
//     {
//         char chs[100];
//         char chd[100];
//         int i = 0;
//         while (number)
//         {
//             chs[i] = number % 10 + '0';
//             i++;
//             number /= 10;
//         }
//         int j = 0;
//         while (digit)
//         {
//             chd[j] = digit % 10 + '0';
//             j++;
//             digit /= 10;
//         }
//         for (int a = 0; a < i; a++)
//         {
//             bool isDigit = false;
//             if (chs[a] == chd[0])
//             {
//                 isDigit = true;
//                 for (int b = 0; b < j; b++)
//                     if (chs[a+b] != chd[b])
//                         isDigit = false;
//             }
//             if (isDigit)
//                 count++;
//         }
//     }

//     return count;
// }

// #include <iostream>
// using namespace std;

// long long quickPow(int n, int k);

// int main() 
// {
//   int n, k;
//   cin >> n >> k; 
//   cout << quickPow(n, k);
//   return 0;
// }

// long long quickPow(int n, int k)
// {
//     int temp;
//     if (k == 0)
//         return 1;
//     if (k % 2 == 0)
//     {        
//         temp =  quickPow(n, k/2);
//         return temp * temp;
//     }
//     else
//     {
//         temp = quickPow(n, k/2);
//         return n * temp * temp;
//     }
// }


// #include <iostream>
// using namespace std;

// int main()
// {
//     char ch1[20] = {0};
//     char ch2[20] = {0};
//     char temp;

//     cin >> ch1 >> ch2;
//     for (int i = 0; i < 20; i++)
//     {
//         if (ch1[i] != 0 && ch2[i] != 0)
//         {
//             temp = ch1[i];
//             ch1[i] = ch2[i];
//             ch2[i] = temp;
//         }
//     }
//     cout << ch1 << endl << ch2 << endl;
//     return 0;
// }

// #include <iostream>
// #include <cstring>
// using namespace std;

// void getDate(int &, int &, int &);
// int main()
// {
//     int day, month, year;
//     getDate(day, month, year);
//     cout << day <<" "<< month<<" " << year << endl;
//     return 0;
// }
// void getDate(int & da, int &mon, int &yr)
// {
//     cin >> da;
//     string mn;
//     cin.get();
//     for (int i = 0; i < 3;i++)
//         mn += cin.get();
//     if (mn == "Jan") mon = 1;
//     if (mn == "Feb") mon = 2;
//     if (mn == "Mar") mon = 3;
//     if (mn == "Apr") mon = 4;
//     if (mn == "May") mon = 5;
//     if (mn == "Jun") mon = 6;
//     if (mn == "Jul") mon = 7;
//     if (mn == "Aug") mon = 8;
//     if (mn == "Sep") mon = 9;
//     if (mn == "Oct") mon = 10;
//     if (mn == "Nov") mon = 11;
//     if (mn == "Dec") mon = 12;

//     cin.get();
//     cin >> yr;
// }
// Jan
// Feb 
// Mar
// april
// may
// june
// july
// august sep oct nov dec

// #include <iostream>
// using namespace std;
// void findMax(int * p, int size, int * pm1, int *pm2);

// int main()
// {    
//     int n;
//     cin >> n;
//     int *pn = new int[n];
//     for (int i = 0; i < n; i++)
//         cin >> pn[i];
    
//     int max1, max2;
//     findMax(pn, n, &max1, &max2);
//     delete [] pn;
//     cout << max1 << " " << max2;
//     return 0;
// }
// void findMax(int * p, int size, int * pm1, int *pm2)
// {
//     int m11, m12, m21, m22;
//     switch(size)
//     {
//         case 1: *pm1 = p[0];
//                 *pm2 = 0;
//                 return;
//         case 2: *pm1 = (p[0] >= p[1]) ? p[0] : p[1];
//                 *pm2 = (p[0] <= p[1]) ? p[0] : p[1];
//                 return;
//         default:findMax(p, size / 2, &m11, &m12);
//                 findMax(&p[size / 2], size - size / 2, &m21, &m22);
//                 *pm1 = (m11 >= m21) ? m11 : m21;
//                 if (m11 >= m21)
//                      *pm2 = (m12 >= m21) ? m12 : m21; 
//                 else
//                     *pm2 = (m11 >= m22) ? m11 : m22;
//                 return;
//     }
// }


// #include <iostream>   
// #include <cstring>
// using namespace std; 
// char * & funA(char ** & ppc);
// char * funB(char [], char **);

// // // 写出两个函数的声明

// int main() 
// {
//     char a[100], b[100];
//     for(int i = 0; i < 3; ++i) 
//     {
//         char **p;
//         cin >> a;
//         funA(p) = a;
//         cout << funB(b, p) << endl;
//     }
//     return 0;
// }

// // 写出两个函数的定义
// char * & funA(char ** & ppc)//引用·！！char **& ppc
// {
//     ppc = new char *;
//     *ppc = nullptr;
//     return *ppc;
// }
// char * funB(char bs[], char ** ppc)
// {
//     for (int i = 0; i < 100; i++)
//     {
//         bs[i] = 0;//记得清除原来的！
//     }
//     for (int i = 0; i < strlen(*ppc); i++)
//     {
//         if ((*ppc)[i] <= 'z' && (*ppc)[i] >= 'a')
//             bs[i] = (*ppc)[i] - 'a' + 'A';
//         else
//             bs[i] = (*ppc)[i];
//     }
//     delete ppc;

//     return bs;
// }

// #include <iostream>
// using namespace std;

// int main()
// {
//     char ch1[20] = {0};
//     char ch2[20] = {0};
//     char temp;
//     char * pc = ch1;

//     cin >> ch1 >> ch2;
//     for (; pc - ch1 < 20; pc++)
//     {
//         if (pc != 0 && ch2[pc - ch1] != 0)
//         {
//             temp = *pc;
//             ch1[pc - ch1] = ch2[pc - ch1];
//             ch2[pc - ch1] = temp;
//         }
//     }
//     cout << ch1 << endl << ch2 << endl;
//     return 0;
// }

// #include <cctype>
// #include <iostream>
// #include <cstring>
// using namespace std;
// char *my_trim(int* count)
// {
//     char* p;
//     p = new char[40000];
//     *count = 0;
//     char tmp;
//     while(isspace(tmp = cin.get()))
//         (*count)++;
//     cin.getline(p, 40000);
//     delete [] p;
//     return p;
// }
// int main()
// {
//     int count;
//     char* ret = my_trim(&count);
//     cout << ret;
//     // delete[] (ret - count);
//     return 0;
// }


// #include <cctype>
// #include <iostream>
// #include <cstring>
// using namespace std;
// char *my_trim(int* count);
// int main()
// {
//     int count;
//     char* ret = my_trim(&count);
//     cout << ret;
//     cout << count;
//     delete[] (ret - count);
//     return 0;
// }
// char *my_trim(int* count)
// {
//     char* p;
//     p = new char[40000];
//     for (int i = 0; i < 40000; i++)
//         p[i] = 0;
//     *count = 0;
//     int i = 0;
//     bool beforechar = true;
//     char tmp;
//     while(cin.get(tmp))
//     {
//         p[i] = tmp;
//         i++;
//         if (!isspace(tmp))
//             beforechar = false;
//         if (isspace(tmp)&&beforechar)
//             (*count)++;
//     }

//     return p + (*count);
// }


// #include <iostream>
// using namespace std;
// int main()
// {
//     //输入
//     //比较哪个放前面
//     //输出
// }

#include <iostream>
using namespace std;
bool max(int ref, int b);
void swap(int &a, int &b);
int turnStr(char *, int);
char *largestNumber(int *nums, int numsSize);
int main()
{
    int nums[5];
    int i;
    for (i = 0; i < 5; i++)
        cin >> nums[i];
    char * s;
    s = largestNumber(nums, i);//跳出循环时以及是2了
    cout << s;
    delete [] s;
    return 0;
}


char *largestNumber(int *nums, int numsSize){
    for (int i = 0; i < numsSize; i++)
    {
//比较哪个放前面
        // int temp = nums[i];//temp永远是交换前最初的nums[i],比较对象都不对
        for (int j = i+1; j < numsSize; j++)
        {
            if(!max(nums[i], nums[j]))
                swap(nums[i], nums[j]);
        }
    //最高位最大前面
    //同最高位下一位，在下一位，以此类推
//放前面
    //放第i个
//返回
    }

    char *str;
    str = new char[100]();
    int countchar = 0;
//转成字符串，叠加上去
    for (int i = 0; i < numsSize; i++)
    {
        countchar += turnStr(str+countchar, nums[i]);
    }
    return str;
}

bool max(int ref, int b)
{
    int tmp1, tmp2, count1, count2;
    tmp1 = ref;
    tmp2 = b;
    count1 = count2 = 0;
    //计算位数
    while (tmp1)
    {
        count1++;
        tmp1 /= 10;
    }
    while (tmp2)
    {
        count2++;
        tmp2 /= 10;
    }
    //计算两种情况的值
    tmp1 = ref;
    tmp2 = b;
    for (int i = 0; i < count2; i++)
        tmp1 *= 10;
    tmp1 += b;
    for (int i = 0; i < count1; i++)
        tmp2 *= 10;
    tmp2 += ref;
    //比较
    if (tmp1 > tmp2)
        return true;
    else
        return false;
}

// bool max(int ref, int b)
// {
//     int m = ref;
//     int n = b;
//     int rs[10];
//     int bs[10];
//     int i = 0;
//     while(ref)
//     {
//         rs[i] = ref % 10;
//         ref /= 10;
//         i++;
//     }
//     int j = 0;
//     while(b)
//     {
//         bs[j] = j % 10;
//         b /= 10;
//         j++;
//     }
//     if (rs[i] > bs[j])
//         return true;
//     else if (rs[i] < bs[j])
//         return false;
//     else if (rs[i] == bs[j])
//     {
//         int rfront, bfront;
//         rfront = m;
//         bfront = n;
//         for (int count = 0; count < j; count++)
//             rfront *= 10;
//         rfront += n;
//         for (int count = 0; count < i; count++)
//             bfront *= 10;
//         bfront += m;
//         if (rfront > bfront)
//             return true;
//         else
//             return false;
//     }
//     return true;
// }

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

int turnStr(char * p, int a)
{
    int count = 0;
    char tp[10];
    //得到字符，计算位数
    while(a)
    {
        tp[count] = a % 10 + '0';
        a /= 10;
        count++;
    }
    //交换位置
    for (int i = count - 1; i >= 0; i--)
    {
        p[count - i - 1] = tp[i];
    }
    return count;
}

// #include <iostream>
// int split(char *str, char *split);
// using namespace std;
// int main()
// {
//     char xx[100];
//     char yy[10];
//     cin.getline(xx, 100);
//     cin.getline(yy, 100);
//     cout << split(xx, yy);
//     return 0;
// }
// int split(char *str, char *split)
// {
//     //找分割字符
//     int ans = 0;
//     bool haveSplit = false;
//     bool isSplit;
//     int counts = 0;
//     int countt = 0;
//     for (; str[counts] != '\0'; counts++) ;
//     for (; split[countt] != '\0'; countt++) ;

//     for (int i = 0; i < counts; i++)
//     {
//         isSplit = false;                        //不管怎样么样，每轮都用的每次循环要重置呀！
//         if (str[i] == split[0])
//         {
//             isSplit = true;
//             for (int j = 1; j < countt;j++)
//             {
//                 if (str[i+j] != split[j])
//                     isSplit = false;
//             }
//         }
//         if (isSplit == true)
//         {
//             haveSplit = true;
//             ans = i + countt;
//             break;
//         }
//     }
//     if (haveSplit = false)
//         return 0;
//     //else
//     bool allSplit = false;//但是要初始化为false
// // bool allSplit不可以放外面，要是if测试没通过应该返回ans，但放外面true初始化就会变成结果是allsplit
//     if ((counts % countt == 0) && ans == countt)
//     {
//         allSplit = true;
//         for (int i = countt; (i < counts)&&(allSplit);i += countt)
//             for (int j = 0; (j < countt)&&(allSplit); j++)
//                 if (str[i+j] != split[j])//j不是i+j
//                     allSplit = false;
//     }
//     if (allSplit)
//         return -1;
//     return ans;
//     //没有0
//     //考虑特殊情况全都是-1
//     //找到一个，记录位置，返回其后第一个字符的下标
// }