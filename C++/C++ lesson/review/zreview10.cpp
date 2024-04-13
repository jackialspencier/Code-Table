// #include <iostream>
// using namespace std;
// class Rational {
// private:
//     int num;
//     int den;
// public:
//     void create(int n, int d);
// };

// void Rational::create(int n, int d)
// {
//     this->num = n;
//     this->den = d;
// }
// #include <iostream>
// using namespace std;
// int main()
// {
// int * nums = nullptr, count = 0, x;
// while (cin >> x)
// {
//     int * tmp = new int[count+1];
//     tmp[count++] = x;
//     if (nums != nullptr){
//         for (int i = 0; i < count - 1; i++)
//             tmp[i] = nums[i];
//         delete [] nums;
//     }
//     nums = tmp;
// }

// while (cin >> x)
// {
//     int * tmp = new int[count+1];

//     for (int i = 0; i < count; i++)
//         tmp[i] = nums[i];
//     tmp[count++] = x;

//     if (nums) delete nums;
//     nums = tmp;
// }

//     int a[10];
//     int b {22321};
//     int c(2);
//     a[3] = 2;
//     cout << a[3] << "\t" << b << "\t" << c << "\tyeah\t";
//     return 0;
// }

// void SmartArrayappend(int e)
// {
//     if (count == capacity){
//         int * temp = new int[2 * capacity];
//         for (int i = 0; i < count; i++);
//             tmp[i] = nums[i];

//         if (nums) delete [] nums;
//         nums = temp;
//         capacity *= 2; // !!
//     }
//     nums[count++] = e;
// }

// #include <iostream>
// using namespace std;
// class aa
// {
//     static double rate;
// public:
//     static double get();
// };

// double aa::rate = 1.2;
// double aa::get()        // 这里貌似一定不能写static？
// {
//     return aa::rate;
// }

// int main()
// {
//     aa m;
//     cout << m.get() << endl;
//     cout << "\t" << aa::get() << endl;      //
//     此时是作用域解析::不是成员运算符.啦！！！
// }

// #include <iostream>
// using namespace std;
// int main()
// {
// //     int a[100];
// //     a[1] = {333};   // 也是一种赋值方式
// //  // a[1]{222};      // 但这样不行
// //     a[100] = 2;//   越界
//     // int b = {2};
//     // int c{2};
//     // cout << b;
//     // cout << '\t' << c <<endl;

//     char * a[10];
//     bool aa = &(a[9]) < &(a[2]);// bool aa = a[9] < a[2];
//     cout << aa << endl;
//     cout << (&(a[8]) - &(a[2])) << endl;
//     cout << (bool (&(a[1]) < &(a[2]))) << endl;
//     return 0;
// }

// #include <iostream>
// using namespace std;
// int main()
// {
//     int a = 3;
//     int b = 7;
//     int c = +3;
//     int m = a < c || a < b;
//     cout << +m;
//     cout << endl << (+c) << endl;
// }

// {
//     if (*this == &r)
//         return *this;
//     // if (storage)
//     delete [] storage;
//     low = r.low;
//     high = r.high;
//     storage = new int[high - low + 1];
//     for (int i = 0; i < high - low + 1; i++)
//         storage[i] = r.storage[i];
//     return * this
// }

// int main() {
// 	int n, k, p = 0;
// 	cin >> n >> k;
//     bool *alive = new bool[n];
// 	for (int i = 0; i < n; ++i) alive[i] = true;
// 	for (int i = 1; i < n; ++i) {
// 		alive[p] = false;
// 		int j = k;
// 		do {
// 			p = (p + 1) % n;
// 			while (!alive[p]) p = (p + 1) % n;
// 			j -= 1;
// 		} while (j > 0);
//         }
// 		delete[] alive;
// 		cout << p << endl;
// 		return 0;
// }

// class BadRational {
// 	int num, den;

//  public:
// 	BadRational(int a, int b) : num(a), den(b) {}
// 	void add(const BadRational &a, const BadRational &b) {
// 		den = a.den * b.den;
// 		num = a.den * b.num + a.num * b.den;
// 	}
// 	void display() { cout << num << '/' << den << endl; }
// };
// int main() {
// 	BadRational p(1, 2), q(2, 5);
// 	p.add(p, q);
// 	p.display();
// 	return 0;
// }
// #include <iomanip>
// int main() {
// cout << (&("abc")) << endl;
// cout.put(12385) << endl;
// cout.put(65) << endl;
// cout.put('A') << endl;
// cout << endl;

// char buffer[] = "Be happy for yourself";
// char * p;
// p = new char(65);
// cout.write(buffer, 10) << endl;
// cout.write(p, 10) << "here" <<endl;
// delete[] p;

// int a = 1122;
// cout.write(&a, 1) << endl;   // 不行
// cout.write(&a, 2) << endl;
// cout.write(&a, 3) << endl;

// char buffer[80];
// cin.read(
// 		buffer,
// 		10);	// 读入 10 个字节，放入 buffer // 并不管这 10 个字节到底表示啥数据
// int a;
// cin.read((char *)&a, 6);	// 这样也可以哦

// cout.write(buffer, 10);
// cout << endl;

// cout.write(buffer, 13);
// cout << endl;

// cout << endl;
// cout.write((char *)&a, 4);
// cout << endl;
// cout.write((char *)&a, 6);
// cout << endl;
// cout.write((char *)&a, 8);
// cout << endl;
// cout << buffer << endl;
// cout << (void *) buffer << endl;
// cout.write("ABCDEFG", 4);

// int n;
// cout << "Enter a octal number: ";
// cin >> oct >> n;
// cout << "octal " << oct << n << " in hexdecimal is:" << hex << n << '\n';
// cout << "hexdecimal " << n << " in decimal is:" << dec << n << '\n';
// cout << setbase(8) << "octal " << n << " in octal is:" << n << endl;

// double x = 123.456789, y = 9876.54321;
// for (int i = 9; i > 0; --i) {
// 	cout.precision(i);
// 	cout << x << '\t' << y << endl;
// }

// cout << endl;
// double a = 12.00000;
// cout.precision(3);
// cout << a << endl;
// cout.setf(ios_base::fixed, ios_base::floatfield);
// cout << a << endl;
// cout.precision(2);
// cout << a;
// char a[10], b[10], c[10];
// cin >> setw(5) >> a >> setw(5) >> b;
// cin >> setw(5) >> c;

// cout << a << "    " << b << "|||" << endl;
// cout << c << "|||"<< endl;
// return 0;

// #include <fstream>
// #include <iostream>
// using namespace std;
// int main() {
// 	fstream f("file");
// 	int i;
// 	if (!f) {
// 		cerr << "open file error\n";
// 		return 1;
// 	}
// 	f.seekp(10);
// 	f << 20;
// 	f.seekg(0);
// 	while (f >> i) cout << i << ' ';
// 	f.close();
// 	return 0;
// 	// 执行后：1 2 3 4 5 207 8 9 10 执行前：1 2 3 4 5 6 7 8 9 10
// 	// 注意这里是覆盖，而不是插入
// }

// #include <iostream>
// int main() {
// 	// const int N = 8;
// 	// int nums[N] = {3, 2, -3, 1, 5, 7, 6, -1};
// 	// int **p = new int *[N];
// 	// for (int i = 0; i < N; ++i) p[i] = &nums[i];
// 	// for (int i = 0; i < N; ++i) {
// 	// 	for (int j = i + 1; j < N; ++j) {
// 	// 		if (*p[i] < *p[j]) {
// 	// 			int *t = p[i];
// 	// 			p[i] = p[j];
// 	// 			p[j] = t;
// 	// 		}
// 	// 	}
// 	// }
//     // std::cout << (*p[N-1]) << "\t" << (*p[0]) << std::endl;
// 	// std::cout << (p[N - 1] - p[0]) << std::endl;//
// p数组里面存的是地址！！！！！！
// 	// delete[] p;
// 	// return 0;

//     // enum trry {BB};
//     // trry m, n;
//     // m = BB;
//     // int d = 10;
//     // n = (trry)d;
//     // // m = d;
//     // d = BB;

//     // std::cout << (int)'0' << std::endl;
//     // cout << INT_M;
//     int a = 0;
//     int b;
//     while(true)
//     {
//         b = a + 1;
//         if (b > a)
//         {

//         }
//         else
//             break;
//         a++;
//     }
//     std::cout << a;
//     // return 0;
// }

// #include <iostream>
// // #include <limits>
// #include <cstdlib>
// #include <ctime>
// using std::cout;
// using std::endl;
// int main() {
// std::cout << "Maximum value of int: " << std::numeric_limits<int>::max()
// 					<< std::endl;
// return 0;
// double a = .1;
// int b = 0123;
// int c = 0X123;
// std::cout << a << endl;
// std::cout << b << endl;
// std::cout << c << endl;
// cout << std::fixed << std::endl;
// int a, b, c;
// a = 0;
// b = 0;
// c = 1;
// cout << (a == b >= c) << endl;
// cin >> a >> oct >> b;
// cout << oct << (a + b) / 2 << endl;

// a = b = c = 6 + c = 7;

// int a = 2, b = 4, c = 6, d = 0;
// int x = a + b > c == ++d;
// cout << x << endl;
// return 0;

// int x = 5;
// cout << (0 < x < 10) << endl;
// x = 20;
// cout << (0 < x < 10) << endl;
// int a = 10;
// // cout << --(a++) << endl;
// cout << a;
// int a = true;
// switch(a)
// {
//     case 1:
//                 cout << a;
//     case 1:
//                 ;
// // }
// int a;
// // srand(time(nullptr));
// a = rand();
// cout << a;
// return 0;

// enum CSS {why, are, you};
// CSS tol = why, arete = are;
// tol = (CSS)(tol + arete);
// using namespace std;
// int x;
// cin >> x;
// while(x != 1)
// {
//     if (x % 2 == 1)
//         x = x * 3 + 1;
//     else
//         x = x / 2;
//     cout << x << " ";
// }
// // cout << x;// 不需要。为1后，检查前已有输出。
// return 0;
//     int a[10] = {999};
//     cout << a[(int)0.1];
// }

// 输出二进制
// #include <iostream>
// using namespace std;
// int main()
// {
//     int n, num_bits = 0;
//     int bits[32];
//     cin >> n;
//     while(n)
//     {
//         bits[num_bits++] = n & 1;
//         n >>= 1;
//     }
//     // for (int i = 0; i < num_bits; i++)
//     for (int i = num_bits-1; i >= 0; i--) // 注意输出顺序，不要遍历反啦
//     {
//         cout << bits[i];
//     }
//     cout << endl;
//     return 0;
// }

// 数字翻转
// #include <iostream>
// using namespace std;
// int main()
// {
//     int n;
//     int nums[10];
//     int count = 0;
//     cin >> n;
//     while(n)
//     {
//         nums[count++] = n % 10;
//         cout << n % 10 << endl;
//         n /= 10;
//     }
//     for (int i = 0; i < count; i++)
//         cout << nums[i];        //注意输出什么
// }
// 更大范围
// #include <iostream>
// using namespace std;
// int main()
// {
//     char digits[110];
//     int count = 0;
//     char tmp;
//     while(true)
//     {
//         cin.get(tmp);
//         if (tmp <= '9' && tmp >= '0')
//             digits[count++] = tmp;
//         else
//             break;
//     }
//     for (int i = count - 1; i >= 0; i--)
//         cout << digits[i];
//     cout << endl;

//     return 0;
// }

// a+b问题
// int ， long
// 更大范围
// #include <iostream>
// #define MAX_DIGITS (12358+1)        // 带加号不括起来可能有问题
// using namespace std;
// int a[MAX_DIGITS], a_digits;
// int b[MAX_DIGITS], b_digits;
// int sum[MAX_DIGITS], sum_digits;

// int main()
// {
//     int counta = 0, countb = 0, countc = 0;
//     char tmp;
//     int adva;
//     // 读入a
//     while(true)
//     {
//         cin.get(tmp);
//         if (tmp >= '0' && tmp <= '9')
//             a[counta++] = tmp - '0';
//         else
//             break;
//     }
//     // 读入b
//     while(true)
//     {
//         cin.get(tmp);
//         if (tmp >= '0' && tmp <= '9')
//             b[countb++] = tmp - '0';
//         else
//             break;
//     }
//     // 计算
//     countc = counta > countb ? counta : countb;
//     for (int i = 0; i < counta || i < countb; i++)
//     {
//         if (i < counta && i < countb){
//             sum[countc - 1 - i] = (a[counta - 1 - i] + b[countb - 1 - i] +
//             adva)% 10; adva = (a[counta - 1 - i] + b[countb - 1 - i] + adva)
//             / 10;
//         }
//         else if (i < counta){
//             sum[countc - 1 - i] = (a[counta - 1 - i] + adva) % 10;
//             adva = (a[counta - 1 - i] + adva) / 10;
//         }
//         else if (i < countb){
//             sum[countc - 1 - i] = (b[countb - 1 - i] + adva) % 10;
//             adva = (b[countb - 1 - i] + adva) / 10;
//         }
//     }
//     if (adva)
//         cout << 1;  // 应该存在最前面，为了不移动便如此了
//     // for (int i = countc - 1; i >= 0; i--)    // 抓住从最高位开始输出！！！
//     for (int i = 0; i < countc; i++)
//         cout << sum[i];
//     cout << endl;
//     return 0;
// }
// 进位！！！！！！

// 示例思路一
// #include <iostream>
// #define MAX_DIGITS (12358 + 1)
// using namespace std;

// int a[MAX_DIGITS], a_digits;
// int b[MAX_DIGITS], b_digits;
// int sum[MAX_DIGITS], sum_digits;

// int main()
// {
//     char tmp;
//     // 读入a
//     while(true)
//     {
//         cin.get(tmp);
//         if (tmp >= '0' && tmp <= '9')
//             a[a_digits++] = tmp - '0';
//         else
//             break;
//     }
//     // 读入b
//     while(true)
//     {
//         tmp = cin.get();
//         if (tmp <= '9' && tmp >= '0')
//             b[b_digits++] = tmp - '0';
//         else
//             break;
//     }
//     // 计算
//     int carry;
//     for (int i = a_digits - 1, j = b_digits - 1; i >= 0 || j >= 0; i--, j--)
//     {
//         int s = carry; // 0+carry
//         if (i >= 0) s += a[i];
//         if (j >= 0) s += b[j];
//         sum[sum_digits++] = s % 10;                 //
//         注意保存sum的顺序和保存a，b的顺序是不一样的 carry = s / 10;
//     }

//     if (carry)
//     {
//         // assert(carry <= 1);
//         sum[sum_digits++] = carry;
//     }

//     // 输出
//     // for (int i = sum_digits-1; i >= 0; i--)
//     //     cout << sum[i];
//     for (int i = 0; i < sum_digits; i++)
//         cout << sum[sum_digits - 1 - i];
//     cout << endl;
// }

// 示例思路二
// #include <iostream>
// #define MAX_DIGITS (12358 + 1)
// using namespace std;

// int a[MAX_DIGITS], a_digits;
// int b[MAX_DIGITS], b_digits;
// int sum[MAX_DIGITS], sum_digits;

// int main()
// {
//     char tmp;
//     int temp;
//     // 读入a，翻转
//     while(true)
//     {
//         cin.get(tmp);
//         if (tmp <= '9' && tmp >= '0')
//             a[a_digits++] = tmp - '0';
//         else
//             break;
//     }
//     for (int i = 0; i < a_digits / 2; i++)
//     {
//         temp = a[i];
//         a[i] = a[a_digits - 1 - i];
//         a[a_digits - 1 - i] = temp;
//     }
//     // 读入b，翻转
//     while (true)
//     {
//         tmp = cin.get();
//         if (tmp >= '0' && tmp <= '9')
//             b[b_digits++] = tmp - '0';
//         else
//             break;
//     }
//     for (int i = 0; i < b_digits / 2; i++)
//     {
//         temp = b[i];
//         b[i] = b[b_digits - 1 - i];
//         b[b_digits - 1 - i] = temp;
//     }
//     // 计算
//     int s = 0;
//     int carry = 0;
//     for (int i = 0; i < b_digits || i < a_digits; i++)
//     {
//         s = carry;
//         if (i < b_digits)   s += b[i];
//         if (i < a_digits)   s += a[i];
//         sum[sum_digits++] = s % 10;
//         carry  = s / 10;
//     }
//     if (carry)
//         sum[sum_digits++] = carry;
//     // 输出
//     for (int i = 0; i < sum_digits; i++)
//         cout << sum[sum_digits - 1 - i];
//     cout << endl;
//     return 0;
// }

// 示例一与示例二：
// 示例一，反向遍历a，b
// 示例二，翻转a，b，正向遍历a，b

// 0 1 2 3 4 5 6 7 8 9 10
// 0 1 2 1 2 3 2 3 4 1 1
// 用f[k]表示走k级台阶的走法种数
// f[k] = f[k-1] + f[k-2];
// 0 1 2
// int f[N];
// for (int i = 3; i < N; i++)
// {
//     f[i] = f[i - 1] + f[i - 2];
// }

// 1.3.9.10硬币个数最少
// f[N];
// f[0] = 0; f[1] = 1; f[3] = 1; f[9] = 1; f[10] = 1;
// for (int i = 0; i <= N; i++)
// {
//     int min = f[i - 1] + 1;
//     // if (i > 1)
//     //     min = f[i]
//     if (i > 3)
//         if (min > f[i - 3] + 1)
//             min = f[i - 3] + 1;
//     if (i > 9 && min > f[i - 9] + 1)
//         min = f[i - 9] + 1;
//     if (i > 10 && f[i - 10] + 1)
//         min = f[i - 10] + 1;
// }

// 顺序查找
// #include <iostream>
// using namespace std;
// const int NumOfNumbers = 7;
// int main()
// {
//     int array[NumOfNumbers] = {2, 3, 1, 7, 5, 8, 9};
//     int key = 0;// int key;
//     cout << "输入要查找的数字：";
//     cin >> key;

//     int i;
//     for (i = 0; i < NumOfNumbers; i++)
//     {
//         if (array[i] == key)
//             break;
//     }

//     if (i < NumOfNumbers)
//         cout << i << endl;
//     //注意没找到的输出
//     else
//         cout << "Not Found!" << endl;
//     return 0;
// }
// 二分查找
// #include <iostream>
// using namespace std;
// const int NumOfNumbers = 7;
// int main()
// {
//     int array[NumOfNumbers] = {1, 2, 3, 5, 7, 8, 9};
//     int numberToFind = 0;
//     cout << "请输入要查找的数字：" << endl;
//     cin >> numberToFind;

//     int left = 0;
//     int right = NumOfNumbers - 1;
//     int mid;
//     bool hasFound = false;
//     int ans;

//     while (left <= right){// left > right时已经把所有范围排除了
//         mid = (left + right) / 2;

//         if (array[mid] == numberToFind){
//             hasFound = true;
//             ans = mid;  // 可以直接在找到的同时输出然后break！
//             // 记得break啦！！！
//         }
//         else if (numberToFind > array[mid])
//             left = mid + 1;
//         else if (numberToFind < array[mid])
//             right = mid - 1;
//     }

//     if (hasFound)
//         cout << ans << endl;    //
//         如果设置在找到的同时输出，那么只需根据left>right决定是否没找到即可。
//     else
//         cout << "Not Found!" << endl;
// }

// 看了示例try again
// #include <iostream>

// 排序
// 选择排序
// #include <iostream>
// using namespace std;
// const int N = 8;
// int main()
// {
//     int numbers[N] = {31, 41, 59, 26, 53, 58, 97, 93};
//     int minindex = 0;
//     for (int i = 0; i < N; i++){
//         // 此前已找到i个最小的并排序好占了0~i-1位置
//         // 找最小
//         minindex = i;
//         for(int j = i + 1; j < N; j++)
//             if (numbers[minindex] > numbers[j])
//                 minindex = j;// 记录的是位置不是值，才能交换
//         // 交换
//         int tmp = numbers[i];
//         numbers[i] = numbers[minindex];
//         numbers[minindex] = tmp;
//     }

//     for (int i = 0; i < N; i++)
//         cout << numbers[i] << " ";
//     cout << endl;

//     return 0;
// }

// 排序
// 冒泡排序
// #include <iostream>
// using namespace std;
// const int N = 8;

// int main()
// {
//     int numbers[N] = {31, 41, 59, 26, 53, 58, 97, 93};
//     bool isSwap = true;///

//     for (int i = 0; i < N && isSwap; i++) // me冒泡次数///
//     {
//         isSwap = false;////
//         //依次扫描、比较并移动(,)元素0到元素N-1-i
//         for (int j = 0; j < N - i - 1; j++) // me冒泡范围
//             if (numbers[j] > numbers[j + 1]){
//                 int temp = numbers[j];
//                 numbers[j] = numbers[j+1];
//                 numbers[j+1] = temp;
//                 isSwap = true; ///
//             }
//         //扫描结束后，被扫描到最大的会被放到N-1-i的位置
//     }

//     for (int i = 0; i < N; i++)
//         cout << numbers[i] << " ";
//     cout << endl;

//     return 0;
// }

// #include <iostream>
// #include <cmath>
// using namespace std;
// int main()
// {
//     double x1 = -1, x2 = 1, x, fx1, fx2, fx;
//     do{
//         fx1 = x1 * x1 * x1 + 2 * x1 * x1 + 5 * x1 - 1;
//         fx2 = x2 * x2 * x2 + 2 * x2 * x2 + 5 * x2 - 1;
//         x = (x1 * fx2 - x2 * fx1) / (fx2 - fx1);
//         fx = x * x * x + 2 * x * x + 5 * x - 1;
//         if (fx * fx1 > 0)
//             x1 = x;
//         else
//             x2 = x;
//     } while (fabs(fx) > 1e-7);// while (fabs(fx) < 1e-7);   // 绝对值！
//     cout << "方程的根为：" << x;
//     return 0;
// }

// #include <iostream>
// #include <cmath>
// using namespace std;
// int main()
// {
//     double mid, x1 = -1, x2 = 1, fx1, fx2, fmid;
//     do
//     {
//         fx1 = x1 * x1 * x1 + 2 * x1 * x1 + 5 * x1 - 1;
//         fx2 = x2 * x2 * x2 + 2 * x2 * x2 + 5 * x2 - 1;
//         mid = (x1 + x2) / 2;
//         fmid = mid * mid * mid + 2 * mid * mid + 5 * mid - 1;
//         if (fmid * fx1 > 0)
//             x1 = mid;
//         else
//             x2 = mid;
//     } while (fabs(fmid) > 1e-7);

//     cout << "方程的根为：" << mid << endl;
//     return 0;
// }

// #include <iostream>
// #include <cmath>
// using namespace std;
// int main()
// {
//     // double delta = 0.00001;
//     // double fx;
//     // bool found = false;
//     // while (true){
//     //     double x;
//     //     for (x = -1; x < 1; x+=delta)   // x
//     不可以是局部变量！！不然后面代码块外怎么输出？
//     //     {
//     //         fx = x * x * x + 2 * x * x + 5 * x - 1;
//     //         if (fabs(fx) < 1e-7)
//     //         {
//     //             found = true;
//     //             break;
//     //         }
//     //     }
//     //     if (found)
//     //     {
//     //         cout << x << endl;
//     //         break;
//     //     }
//     //     else
//     //         delta /= 10;
//     // }

//     char str[80];
//     gets(str);

//     return 0;
// }

// if (lenName < N - 1)

// 算单词后的空格
#include <iostream>
using namespace std;
int main() {
	int count = 0;
	char tmp, beforetmp = ' ';

	while ((tmp = cin.get()) != '\n') {
		if (tmp == ' ' &&
				beforetmp != ' ')	 // 貌似会忽略最后一个,如果没有特意输入一个空格
			count++;
		beforetmp = tmp;
	}

	cout << count << endl;
}

// 示例
// 算单词前的空格（第一个字符前偷偷相当于补了一个空格在前面）
#include <iostream>
using namespace std;
int main() {
	char line[80];
	char prev = ' ';
	cin.getline(line, 80);
	int count = 0;

	for (int i = 0; line[i] != '\0'; i++) {
		if (prev == ' ' && line[i] != ' ') count++;
		prev = line[i];
	}
	cout << count;
	return 0;
}

int fact(int n) {
	int res = 1;
	if (res < 0) return 0;	///
	for (int i = 1; i <= n; i++) res *= i;
	return res;
}

bool IsLeapYear(int n) {
	bool leapyear;
	leapyear = (n % 400 == 0 || n % 100 != 0 && n % 4 == 0);
	return leapyear;
}

double power(double x, int n) {
	double res = 1;
	for (int i = 0; i < n; i++) res *= x;
	return res;
}

#include <iostream>
using namespace std;
void Function();
int x = 1;
int y = 2;

int main() {
	int i = 0;
	cout << x << ", " << y << endl;
	Function();
	cout << x << ", " << y << endl;
	return 0;
}

void Function() {
	int a = 0;
	cout << x++ << ", " << y << endl;
}

#include <iostream>
using namespace std;
void Function();
int x = 1;
int y = 2;

int main() {
	Function();
	cout << "x=" << x << "  y=" << y << endl;
	return 0;
}

void Function() {
	int x = 2, y = 1;
	cout << "x=" << ++x << "  y=" << y << endl;
}

#include <iostream>
using namespace std;
void Function(int x, int y);
int x = 1;
int y = 2;

int main() {
	cout << "x=" << x << "  y=" << y << endl;
	Function(x, y);
	return 0;
}

void Function(int x, int y) {
	x = 2;
	y = 1;
	cout << "x=" << x << "  y=" << y << endl;
}

#include <iostream>
using namespace std;
void Function(int x, int y);

int main() {
	int x = 1;
	int y = 2;
	cout << "x=" << x << "  y=" << y << endl;
	Function(x, y);
	return 0;
}

void Function(int x, int y) {
	x = 2;
	y = 1;
	cout << "x=" << x << "  y=" << y << endl;
}

// 递归
// 递归模式
int func() {
	if (简单情况)
		return 简单情况的结果;
	else
		return 调用简单情况的结果，求出当前情况的结果;
}

// 递归形式

// 例子
// 求n的阶乘
long fact(int n) {
	if (n == 0)
		return 1;
	else
		return fact(n - 1) * n;
}
// 求n的k次幂
long power(int n, int k) {
	if (k == 1)
		return n;
	else
		return n * power(n, k - 1);
}

// Fibonacci函数
int f(int n) {
	if (n == 0)
		return 0;	 // return 1;
	else if (n == 1)
		return 1;
	else
		return f(n - 1) + f(n - 2);
}

// Fibonacci函数的迭代实现
int f(int n) {
	int f1 = 0, f2 = 1, f3 = 1;
	if (n == 0) return 0;	 ///
	if (n == 1) return 1;	 ///
	// if (n == 2) return 2;
	int count;
	int tmpnew;
	for (count = 3; count <= n; count++) {
		tmpnew = f2 + f3;
		f1 = f2;
		f2 = f3;
		f3 = tmpnew;
	}
	return f3;
}
// 示例答案
int f(int n) {
	int i, fn_1 = 0, fn_2 = 1, fn;
	if (n == 0) return 0;
	if (n == 1) return 1;
	for (i = 2; i <= n; i++)	// 注意是小于等于
	{
		fn = fn_1 + fn_2;
		fn_2 = fn_1;
		fn_1 = fn;
	}
	return fn;
}
// 找硬币的递归实现
int f(int n) {
	if (n == 0) return 0;
	if (n == 1 || n == 3 || n == 9 || n == 10) return 1;
	int min = 1 + f(n - 1);
	int temp;
	if (n > 3 && min > (temp = (1 + f(n - 3)))) min = temp;
	if (n > 9 && min > (temp = (1 + f(n - 9)))) min = temp;
	if (n > 10 && min > (temp = (1 + f(n - 10)))) min = temp;
	return min;	 // 别忘了return啦！
}

// Hannoi塔
void Hannoi(int n, char start, char finish, char temp) {
	if (n == 1) {
		cout << start << " -> " << finish << '\t';
	} else {
		Hannoi(n - 1, start, temp, finish);
		cout << start << " -> " << finish << '\t';
		Hannoi(n - 1, temp, finish, start);
	}
}

#include <iostream>
using namespace std;
void f(int arr[], int k) {
    cout << sizeof(arr) << " " << sizeof(k) << endl;
}
int main() {
    int * a;
	a = new int[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
	cout << sizeof(a) << endl;
    for (int i = 0; i < 10; i++)
        cout << a[i] << '\t';
    cout << endl;
	f(a, 10);
    delete [] a;
	return 0;
	// C++ 将数组名作为参数传递的情况处理成指针的传递
}

{
    if (a > b)
        if (a > c)
            return a;
        else
            return c;
    else if (b > c)
        return b;
    else
        return c;
}

{
    int * c = a;
    if (*c > b)
        c = b;
    if (*c > *x)
        c = x;
}

// 正确的找最小值
int *min(int *a, int *b, int *c)
{
    if (*a <= *b && *a <= *c)
        return a;
    if (*b <= *a && *b <= *c)
        return b;
    return c;
}

// 
#include <ctype.h>  // 包含函数i是space(char)
int word_cnt(const char *s)
{
    int cnt = 0;
    while(*s != '\0')
    {
        // 跳过空白字符
        while(isspace(*s))
            ++s;
        // 计数单词（非结尾）并跳过这个单词
        if (*s != '\0'){
            cnt++;  //找到一个新的单词
            while(*s != '\0' && !isspace(*s))
                s++;    // 寻找/定位到下一个空格/结束
        }
    }
    return cnt;
}



