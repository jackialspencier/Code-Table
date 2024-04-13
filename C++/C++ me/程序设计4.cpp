// #include <iostream>
// using namespace std;
// int main(void)
// {
//     cout << "请输入年份：";
//     int year;
//     cin >> year;
//     if (year % 400 == 0 || year % 100 != 0 && year % 4 == 0)
//         cout << year << " is a leap year" << endl;
//     else
//         cout << year << " is not a leap year" << endl;
//     return 0;
// }

// #include <iostream>
// using namespace std;
// int main()
// {
//     int year;
//     cout << "请输入年份：";
//     cin >> year;
//     bool isLeapYear = false;
//     if (year % 400 == 0 || year % 100 != 0 && year % 4 == 0)
//         isLeapYear = true;//bool isLeapYear = (year % 400 == 0 || year % 100
//         != 0 && year % 4 == 0)
//     if (isLeapYear)
//         cout << year << " is a leap year";
//     else
//         cout << year << "is not a leap year";
//     return 0;
// }

// #include <iostream>
// using namespace std;
// int main()
// {
//     char ch = '9';
//     cout << (int)ch;
//     return 0;
// }

// char dog[8] = {'b', 'e', 'a', 'u', 'x', ' ', 'I', 'I'};
// char cat[8] = {'f', 'a', 't', 'e', 's', 's', 'a', '\0'};
// char bird[11] = "Mr. Cheeps";
// char fish[] = "Bubbles";

// #include <iostream>
// using  namespace std;
// int main()
// {
//     int year, month, day;
//     int dayNum;
//     cin >> year >> month >> day;
//     dayNum = 31 * (month - 1) + day;
//     if (month > 2)
//     {
//         int a = (4 * month + 23) % 10;
//         int b;
//         if (a < 5)
//             b = (4 * month + 23) / 10;
//         else
//             b = (4 * month + 23) / 10 + 1;
//         dayNum = dayNum - b;
//         if ((year % 400 == 0) || ((year % 100 != 0) && (year % 4 == 0)));
//             dayNum++;
//     }
//     cout << dayNum;
//     return 0;
// }
// 1
// #include <iostream>
// using namespace std;
// int main() {
// 	int x1, y1, x2, y2, x3, y3, x4, y4;
// 	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
// 	int left, top, right, bottom;
// 	left = right = y2 - y1;
// 	top = bottom = x2 - x1;
// 	if ((left < 0) && (top < 0)) {
// 		cout << "NULL";
// 		return 0;
// 	}
// 	left = right = y4 - y3;
// 	top = bottom = x4 - x3;
// 	if ((left < 0) && (top < 0)) {
// 		cout << "NULL";
// 		return 0;
// 	}

// 	int x, xx, y, yy;
// 	if (x1 < x3 && x3 < x2 && x2 < x4)	//(x1 < x3 < x2 < x4)
// 	{
// 		x = x3;
// 		xx = x2;
// 	} else if (x3 < x1 && x1 < x4 && x4 < x2) {
// 		x = x1;
// 		xx = x4;
// 	} else if (x3 < x1 && x1 < x2 && x2 < x4)	 //(x3 < x1 < x2 < x4)
// 	{
// 		x = x1;
// 		xx = x2;
// 	} else if (x1 < x3 && x3 < x4 && x4 < x2)	 //(x1 < x3 < x4 < x2)
// 	{
// 		x = x3;
// 		xx = x4;
// 	} else {
// 		cout << "NULL";
// 		return 0;
// 	}

// 	if (y1 < y3 && y3 < y2 && y2 < y4)	//(y1 < y3 < y2 < y4)
// 	{
// 		y = y3;
// 		yy = y2;
// 	} else if (y3 < y1 && y1 < y4 && y4 < y2)	 //(y3 < y1 < y4 < y2)
// 	{
// 		y = y1;
// 		yy = y4;
// 	} else if (y3 < y1 && y1 < y2 && y2 < y4)	 //(y3 < y1 < y2 < y4)
// 	{
// 		y = y1;
// 		yy = y2;
// 	} else if (y1 < y3 && y3 < y4 && y4 < y2)	 //(y1 < y3 < y4 < y2)
// 	{
// 		y = y3;
// 		yy = y4;
// 	} else {
// 		cout << "NULL";
// 		return 0;
// 	}

// 	cout << x << " " << y << " " << xx << " " << yy;
// 	return 0;
// }

// #include <iostream>
// using  namespace std;
// int main()
// {
//     int month, day, year;
//     int dayNum;
//     bool isLegal = false;

//     cin >> year >> month >> day;
//     if (month >= 12)
//         cout << "Illegal";
//     else if ((month % 2 == 1 && month < 8) && (day > 31))
//         cout << "Illegal";
//     else if ((month % 2 == 0 && month >= 8) && (day > 31))
//         cout << "Illegal";
//     else if ((month == 4 || month == 6 || month == 9 || month == 11) && (day
//     > 30))
//         cout << "Illegal";
//     else if ((month == 2 && (year % 400 == 0 ||(year % 100 !=0 && year % 4 ==
//     0))) && day > 29)
//         cout << "Illegal";
//     else if ((month == 2 && (!(year % 400 == 0 ||(year % 100 !=0 && year % 4
//     == 0)))) && day > 28)
//         cout << "Illegal";
//     else
//     {
//         isLegal = true;
//         dayNum = 31 * (month - 1) + day;
//         if (month > 2)
//         {
//             dayNum -= (4 * month + 23) / 10;
//             if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
//                 dayNum++;
//         }
//     }

//     if (isLegal)
//         cout << dayNum;
//     return 0;
// }

// #include <iostream>
// using namespace std;
// int main() {
// 	int i;
// 	int s = 0;
// 	for (i = 1; i <= 100; s = s + i, i + 1)
// 		;
//     cout << "a";
// 	cout << s << endl;
// 	return 0;
// }

// #include <iostream>
// using namespace std;

// int main()
// {
//     int fn_1, fn_2, fn;
//     fn_1 = 0;
//     fn_2 = 1;
// 	fn = 1;
//     int n;
//     cin >> n;
// 	bool more2 = false;
// 	if (n == 1 || n == 2)
// 		cout << "1";
//     for (int i = 0 ; n > 2 && i < n - 2; i++)
//     {
// 		more2 = true;
//         int temp1 = fn_2;
// 		int temp2 = fn;
// 		fn_1 = fn_2;
// 		fn_2 = fn;
// 		fn = temp1 + temp2;
//     }
// 	if (more2)
// 		cout << fn;
//     return 0;
// }

// #include <iostream>
// using namespace std;

// int main()
// {
//     long long n, m;
// 	long long divd = 0;
// 	long long i;
// 	cin >> n >> m;
// 	if (m == 0)
// 		cout << n;
// 	else if (n == 0 || n % m == 0)
// 		cout << m;
// 	else{
// 		for (i = 1; i <= n % m; i++)
// 		{
// 			if (m % i == 0 && (n % m) % i == 0 && i >= divd)
// 				divd = i;
// 		}
// 		cout << divd;
// 	}
//     return 0;
// }

// #include <iostream>
// using namespace std;

// long long rev(long long);
// int main()
// {
//     long long n;
// 	cin >> n;
// 	int i, count;
// 	count = 0;
// 	for (i = 0; i <= n; i++)
// 	{
// 		if (i + rev(i) == n)
// 			count++;
// 	}
// 	cout << count;
//     return 0;
// }

// long long rev(long long x)
// {
// 	int x1, x2, x3, x4, x5, x6;
// 	x1 = x2 = x3 = x4 = x5 = x6 = 0;
// 	long long revx;
// 	x1 = x / 100000;
// 	x2 = x / 10000 % 10;
// 	x3 = x / 1000 % 10;
// 	x4 = x / 100 % 10;
// 	x5 = x / 10 % 10;
// 	x6 = x % 10;
// 	if (x1)
// 		revx = x1 + x2 * 10 + x3 * 100 + x4 * 1000 + x5 * 10000 + x6 * 10000;
// 	else if (x2)
// 		revx = x2 * 1 + x3 * 10 + x4 * 100 + x5 * 1000 + x6 * 10000;
// 	else if (x3)
// 		revx = x3 * 1 + x4 * 10 + x5 * 100 + x6 * 1000;
// 	else if (x4)
// 		revx = x4 * 1 + x5 * 10 + x6 * 100;
// 	else if (x5)
// 		revx = x5 * 1 + x6 * 10;
// 	else
// 		revx = x;
// 	return revx;
// }

// #include <iostream>
// using namespace std;

// int main()
// {
//     int n;
// 	int max1, max2;
// 	max1 = max2 = 0;
// 	int temp;
// 	cin >> n;
// 	for (int i = 0; i < n; i++)
// 	{
// 		cin >> temp;
// 		if (temp >= max1)
// 		{
// 			max2 = max1;
// 			max1 = temp;
// 		}
// 		else if (temp >= max2)
// 			max2 = temp;
// 	}
// 	cout << max2;
//     return 0;
// }

// #include <iostream>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;
// 	int i;
// 	for (i = 1; i <= n; i++)
// 	{
// 		if (n % i == 0)
// 			cout << i << " ";
// 	}
//     return 0;
// }

// #include <iostream>
// using namespace std;

// int main() {
// 	int m, n;
// 	int i, j, count;
// 	count = 0;
	
// 	cin >> m >> n;
// 	if (m == 1) count--;
// 	for (i = m; i <= n; i++) {
// 		bool isPrime = true;//bool得在这里！
// 		for (j = 2; j < i; j++) {
// 			if (i % j == 0) isPrime = false;
// 		}
// 		if (isPrime) count++;
// 	}

// 	cout << count;
// 	return 0;
// }

// #include <iostream>
// using namespace std;

// int main()
// {
// 	int n;
// 	cin >> n;
// 	cout << n << " ";
// 	while(n != 1){
// 		if (n % 2 == 1)
// 		{
// 			n = n * 3 + 1;
// 			cout << n << " ";
// 		}
// 		else
// 		{
// 			n = n / 2;
// 			cout << n << " ";
// 		}
// 	}
// 		return 0;
// }

// #include <iostream>
// using namespace std;

// int main()
// {
//     int n;
// 	cin >> n;
// 	int m = 1;
// 	bool is2M = false;
// 	if (n == 1) 
// 		cout << "true";
// 	else{
// 		while (m < n)
// 			{
// 				m *= 2;
// 				if (m == n)
// 					is2M = true;
// 			}
// 		if (is2M)
// 			cout << "true";
// 		else
// 			cout << "false";
// 		}
//     return 0;
// }

// #include <iostream>
// using namespace std;

// int main()
// {
// 	int n;
// 	cin >> n;
// 	//穷举法
// 	int m1, m5, m16, m23, m33;
// 	int mum = 99;
// 	for (m33 = 0; m33 <= 3; m33++)
// 	{
// 		for (m23 = 0; m23 < 5; m23++)
// 		{
// 			for (m16 = 0; m16 < 7; m16++)
// 			{
// 				for (m5 = 0; m5 < 20; m5++)
// 				{
// 					m1 = n - m5 * 5 - m16 * 16 - m23 * 23 - m33 * 33;
// 					if (m1 >= 0 && m1 + m5 + m16 + m23 + m33 < mum)
// 						mum = m1 + m5 + m16 + m23 + m33;
// 				}
// 			}
// 		}
// 	}
// 	cout << mum << " ";
 
	
// 	//贪心算法
	
// 	int n1, n5, n16, n23, n33;
// 	int num;
// 	n33 = n / 33;
// 	n23 = (n % 33) / 23;
// 	n16 = ((n % 33) % 23) / 16;
// 	n5 = (((n % 33) % 23) % 16) / 5;
// 	n1 = (((n % 33) % 23) % 16) % 5;
// 	num = n1 + n5 + n16 + n23 + n33;
// 	cout << num;
    

//     return 0;
// }

// #include <iostream>
// using namespace std;

// int main()
// {
//     int n;
//     int count1, count2;
//     cin >> n;
//     while(n)
//     {
//         if (n > 0)
//             count1++;
//         else
//             count2++;
// 		cin >> n;
//     }
//     cout << count1 << " " << count2;
//     return 0;
// }

// #include <iostream>
// int main()
// {
//     using namespace std;
//     int x, y, z;
//     for (x = 0; x < 10; x++)
//         for (y = 0; y < 10; y++)
//             for (z = 0; z < 10; z++)
//             {
//                 if (x * 100 + y * 10 + z + 100 * y + 10 * z + z == 532)
//                     cout << x << " " << y << " " << z;
//             }
//     return 0;
// }

// #include <iostream>
// int main()
// {
//     using namespace std;
//     int a2b3;
//     for (a2b3 = 1000; a2b3 < 10000; a2b3++)
//         if (a2b3 % 23 == 0 && a2b3 / 100 % 10 == 2 && a2b3 % 10 == 3)
//             cout << a2b3 << " ";
//     return 0;
// }

// #include <iostream>
// #include <cmath>
// int main()
// {
//     using namespace std;
//     double a, b, delta;
//     a = 0.0;
//     b = 1.0;
//     cin >> delta;
//     double s1;
//     s1 = 0.0;

//     for (double i = a; i < b; i += delta)
//         s1 += delta * (sqrt(1 - i * i));
    
//     cout << 4 * s1;
//     return 0;
// }

// #include <iostream>
// #include <cmath>
// double funcx(double);
// int main()
// {
//     using namespace std;
//     double x1, x2, x;
//     double fx1, fx2, fx;
//     x1 = 0;
//     x2 = 2;
//     do
//     {
//         fx1 = funcx(x1);
//         fx2 = funcx(x2);
//         x = (x1 * fx2 - x2 * fx1) / (fx2 - fx1);
//         fx = funcx(x);
//         if (fx * fx2 > 0)
//             x2 = x;
//         else 
//         x1 = x;
//     } while (fabs(fx) > 10e-10);
//     cout << x;
//     cout << endl << fx;
// }
// double funcx(double a)
// {
//     double b;
//     b = 2 * a * a * a - a * a + 5 * a - 1;
//     return b;
// }

// #include <iostream>
// using namespace std;

// int fsum(long long x);
// int main()
// {
//     int long long n;
//     cin >> n;
//     for (int i = 0; i < 10; i++)
//         n = fsum(n);
//     cout << n;
//     return 0;
// }
// int fsum(long long x)
// {
//     int x9,x8, x7, x6, x5, x4, x3, x2, x1;
//     x9 = (x / 100000000) % 10;
//     x8 = (x / 10000000) % 10;
//     x7 = (x / 1000000) % 10;
//     x6 = (x / 100000) % 10;
//     x5 = (x / 10000) % 10;
//     x4 = (x / 1000) % 10;
//     x3 = (x / 100) % 10;
//     x2 = (x / 10) % 10;
//     x1 = (x / 1) % 10;
//     int nn;
//     nn = x1 + x2 + x3 + x4 + x5 + x6 + x7 + x8 + x9;
//     return nn;
// }
// #include <iostream>
// int main()
// {
//     using namespace std;
//     int n;
//     int resum, sum;
//     resum = 0;
//     sum = 0;
//     cin >> n;
//     for (int i = 0; i <= n; i++)
//         sum += i;
//     for (int j = 0; j < n; j++)
//     {
//         int pren;
//         cin >> pren;
//         resum += pren;
//     }
//     cout << (sum - resum);
    
//     return 0;
// }

// #include <iostream>
// using namespace std;

// bool cchang(int);
// int chang1(int);
// int main()
// {
//     using namespace std;
//     int num;
//     int count;
//     cin >> num;
//     bool is1 = cchang(num);
//     if (!is1)
//         cout << "-1";
//     else  
//     {  
//         count = chang1(num);
//         cout << count;
//     }
//     return 0;
// }

// bool cchang(int n)
// {
//     while (n % 2 == 0 || n % 3 == 0 || n % 5 == 0)
//     {
//         if (n % 2 == 0)
//             n = n / 2;
//         if (n % 3 == 0)
//             n = n / 3;
//         if (n % 5 == 0)
//             n = n / 5;
//     }
//     if (n == 1)
//         return true;
//     return false;
// }
// int chang1 (int m)
// {
//     int ways[3] = {0, 0, 0};
//     if (m % 2 == 0)
//     {
//         if (m / 2 == 1)
//             ways[0] = 1;
//         else
//             ways[0] = chang1(m / 2);
//     }
//     if (m % 3 == 0)
//     {
//         if (m / 3 == 1)
//             ways[1] = 1;
//         else
//             ways[1] = chang1(2 * m / 3);
//     }
//     if (m % 5 == 0)
//     {
//         if (m / 5 == 0)
//             ways[2] = 1;
//         else
//             ways[2] = chang1(4 * m / 5);
//     }
//     int min = ways [1];
//     for (int i = 0; i < 3; i++)
//         if (min >= ways[i])
//             min = ways[i];
//     return min;
// }

// #include <iostream>
// using namespace std;

// int main()
// {
//     int n, p;
//     cin >> n >> p;
//     int count = 0;
    
//     for (int i = 1; i <= n; i++)
//     {
//         int j = i;
//         while(j % p == 0)
//         {
//             j = j / p;
//             count++;
//         }
//     }
//     cout << count;
//     return 0;
// }

// #include <iostream>
// using namespace std;

// int main()
// {
//     int n;
//     bool has3 = false;
//     int i;
//     cin >> n;
//     if (n < 1000 || n > 1000000)
//         cout << "Input error!";
//     else
//     {
//         for (i = 999; i >= 100 && !has3; i--)
//             if (n % i == 0)
//                 has3 = true;
//         if (has3)
//             cout << (1 + i);
//         else
//             cout << "Not found!";
//         return 0;
//     }
// }


// #include <iostream>
// using namespace std;
// const int ArSize = 99999;
// int stairs(int);
// int main()
// {
//     int n;
//     cin >> n;
//     cout << stairs(n);
//     return 0;
// }
// int stairs(int m)
// {
//     int way1, way2;
//     if (m > 2)
//     {
//         way1 = stairs(m - 1) + 1;
//         way2 = stairs(m - 2) + 1;
//     }
//     else if (m == 1)
//         way1 = 1;                       
//     else if (m == 2)
//         way2 = 2;
//     return (way1 + way2);
// }

// #include <iostream>
// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;
//     for (int i = 0; i < 2 * n - 1; i++)
//     {
//         int w = 2 * n - 1 / 2;
//         for (;w > 0; w--)
//             cout << " ";
//         for (int j = 2 * i - 1; j > 0; j--)
//             cout << "+";
//         cout << endl;
//     }
//     return 0;
// }

// #include <iostream>
// using namespace std;

// int main()
// {
//     using namespace std;
//     int n;
//     int count;
//     cin >> n;
//         while (n % 2 == 0)
//         {
//             n = n / 2;
//             count++;
//         }
//         while(n % 5 == 0)
//         {
//             n = n / 5;
//             count = count + 3;
//         }
//         while(n % 3 == 0)
//         {
//             n = n/3;
//             count = count + 2;
//         }
//         if (n != 1)
//             cout << "-1";
//         else
//             cout << count;
//     return 0;
// }

// #include <iostream>
// using namespace std;

// int main()
// {
//     int n, p;
//     cin >> n >> p;
//     int count = 0;
    
//     for (int i = 2; i <= n; i++)
//     {
//         int j = i;
//         if ((j % (p * p * p * p * p * p)) == 0)
//             while ((j % (p * p * p * p * p * p)) == 0)
//                 count = count + 6;
//         else
//             while(j % p == 0)
//             {
//                 j = j / p;
//                 count++;
//             }
//     }
//     cout << count;
//     return 0;
// }

// #include <iostream>
// using namespace std;
// const int ArSize = 20;
// int main()
// {
//     int digit;
//     char nums[ArSize];
//     int i, count;
//     for (i = 0; i < ArSize; i++)
//     {
//         char temp;
//         if ('0' <= (temp = cin.get()) && temp <= '9')
//             nums[i] = temp;
//         else 
//             break;
//     }
//     cin >> digit;
//     for (int j = 0; j < i; j++)
//     {
//         if ((nums[j] - '0') == digit)
//             count++;
//     }
//     cout << count;
//     return 0;
// }



// #include <iostream>
// using namespace std;

// int main()
// {
//     int m, n;
//     int i, j, tot;
//     cin >> m >> n;
//     if (n <= 10000)
//     {
//         for (i = m; i <= n; i++)
//         {
//             tot = 0;
//             for (j = 1; j < i; j++)
//             {
//                 if (i % j == 0)
//                     tot += j;
//             }
//             if (tot == i)
//                 cout << i << " ";
//         }
//     }
//     else
//     {
//         n = 10000;
//         for (i = m; i <= n; i++)
//         {
//             tot = 0;
//             for (j = 1; j < i; j++)
//             {
//                 if (i % j == 0)
//                     tot += j;
//             }
//             if (tot == i)
//                 cout << i << " ";
//         }
//     }
//     return 0;
// }

// #include <iostream>
// using namespace std;

// int main()
// {
//     int p, n;
//     cin >> n >> p;
//     int count, precount;
//     count = 0;
//     while ((precount = n / p) != 0)
//     {
//         count += precount;
//         n = n / p;
//     }
//     cout << count;
//     return 0;
// }

#include <iostream>
using namespace std;

int main()
{
    int m, n;
    int i, j, tot;
    bool hasPer = false;
    cin >> m >> n;
    if (n <= 10000)
    {
        for (i = m; i <= n; i++)
        {
            tot = 0;
            for (j = 1; j < i; j++)
            {
                if (i % j == 0)
                    tot += j;
            }
            if (tot == i)
            {
                cout << i << " ";
                hasPer = true;
            }
        }
    }
    else
    {
        n = 10000;
        for (i = m; i <= n; i++)
        {
            tot = 0;
            for (j = 1; j < i; j++)
            {
                if (i % j == 0)
                    tot += j;
            }
            if (tot == i)
            {
                cout << i << " ";
                hasPer = true;
            }
        }
    }
    if (!hasPer)
        cout << "-1";
    return 0;
}

