// #include <iostream>
// using namespace std;

// int main()
// {
//     int n, temp;
//     cin >> n;
//     const int MaxSize = n;
//     int nums[MaxSize];

//     int i, j;
//     for ( i = 0; i < MaxSize; i++)
//         cin >> nums[i];

//     for (i = 0; i < MaxSize; i++)
//     {
//         temp = nums[i];
//         for (j = i + 1; j < MaxSize; j++)
//             if (nums[j] > nums[i])
//             {
//                 nums[i] = nums[j];
//                 nums[j] = temp;
//             }
//     }
//     for (i = 0; i < MaxSize; i++)
//         cout << nums[i] << " ";
//     return 0;
// }

// #include <iostream>
// using namespace std;
// int main()
// {
//     int n, k, i, j;

//     cin >> n >> k;
//     const int Lights = n;
//     int Onoff[Lights];
//     for (i = 0; i < Lights; i++)
//         Onoff[i] = 0;
//     for (int j = 0; j < k; j++)
//     {
//         int m = 1;
//         while(m * (j + 1) <= Lights)
//         {
//             Onoff[m * (j+1) - 1]++;
//             m++;
//         }
//     }
//     for (i = 0; i < Lights; i++)
//     {
//             Onoff[i] = Onoff[i] % 2;
//         if (Onoff[i] == 1)
//             cout << (i+1) << " ";
//     }
// }

// #include <iostream>
// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;
//     int year, month, date, notryearcount, ryearcount, day, day13;
//     int days1[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//     int days2[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//     int weekday13[7] = {0, 0, 0, 0, 0, 0, 0};
//     date = 0;
//     notryearcount = 0;
//     ryearcount = 0;
//     for (int year = 1900; year < 1900 + n; year++)
//     {
//         day = 0;
//         day = ryearcount * 366 + notryearcount * 365;
//         for (int month = 1; month <=12; month++)
//         {
//             day13 = day + 13;
//             // Days = (year % 400 == 0 || year % 400 != 0 && year % 4 == 0) ?
//             366: 465;
//             //计算天数从而计算星期几
//             weekday13[day13 % 7]++;
//             if (year % 400 == 0 || year % 400 != 0 && year % 4 == 0)
//                 day += days2[month];
//             else
//                 day += days1[month];
//             //2.总共的第几天， 3%7算出星期几
//         }
//         if (year % 400 == 0 || year % 400 != 0 && year % 4 == 0)
//             ryearcount++;
//         else
//             notryearcount++;
//     }
//     for (int i = 0; i < 7; i++)
//         cout << weekday13[i] << " ";
//     return 0;
// }

// #include <iostream>
// using namespace std;

// int main()
// {
//     int nums[1000];
//     int arr[1000];
//     int i, count, j, temp, rcount;
//     i = 0;
//     rcount = 0;
//     //获取输入
//     while (cin >> nums[i])
//     {
//         count++;
//         i++;
//         cout << "*";
//     }
//     //处理输入
//     for (j = 0; j < count; j++)
//     {
//         temp = nums[j];
//         for (i = 0; i < count; i++)
//         {
//             if ((nums[i] == temp) && (i <= j))
//                 break;
//             else if ((nums[i] == temp) && (i > j))
//             {
//                 arr[rcount] = temp;
//                 rcount++;
//                 cout << arr[rcount];
//             }
//             else if (i == count - 1)
//             {
//                 arr[rcount] = temp;
//                 rcount++;
//                 cout <<arr[rcount];
//                 cout << nums[i];
//             }
//         }
//     }
//     //输出
//     cout << rcount;

//     for (i = 0; i < rcount; i++)
//         cout << arr[i] << " ";
//     return 0;
// }

// #include <iostream>
// using namespace std;
// int main()
// {
//     int n, i, j, temp;
//     cin >> n;
//     int nums[100];
//     //获取输入
//     for (i = 0; i < n; i++)
//         cin >> nums[i];
//     //排序
//     for (i = 0; i < n; i++)
//     {
//         for (j = i + 1; j < n; j++)
//         if (nums[j] > nums[i])
//         {
//             temp = nums[i];
//             nums[i] = nums[j];
//             nums[j] = temp;
//         }
//     }
//     //输出
//     for (i = 0; i < n; i++)
//         cout << nums[i] << " ";
// }

// #include <iostream>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;
//     int year, month, day;
//     day = 0;
//     int DayinMon1[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//     int DayinMon2[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//     int weekdays[7] = {0, 0, 0, 0, 0, 0, 0};
//     //计算13号是第几天：年叠加、月叠加、日
//     for (year = 1900; year < 1900 + n; year++)
//     {
//         for (month = 0; month < 12; month++)
//         {
//             //计算day+13星期几并保存
//             weekdays[(day + 13) % 7]++;
//             if (year % 400 == 0 || year % 100 != 0 && year % 4 == 0)
//                 day += DayinMon2[month];
//             else
//                 day += DayinMon1[month];
//         }
//         day += ((year % 400 == 0 || year % 100 != 0 && year % 4 == 0) ? 366 :
//         365);
//     }
//     //取余计算星期
//     for (int i = 1; i < 7; i++)
//         cout << weekdays[i] << " ";
//     cout << weekdays[0];
//     return 0;
// }

// #include <iostream>
// using namespace std;
// int main()
// {
//     int nums[1000];
//     int only[1000];
//     int i, count, onlycount, j;

//     //读取一组数据
//     count = 0;
//     onlycount = 0;
//     while (cin >> nums[count])
//         count++;
//     //处理（保存每个第一次出现的到另一个数组里）
//     for (i = 0; i < count; i++)
//     {
//         bool norpt =
//         true;//！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
// 循环内重置！！！
//         for (j = 0; j < i; j++)
//             if (nums[j] == nums[i])
//                 norpt = false;
//         if (norpt)
//         {
//             only[onlycount] = nums[i];
//             onlycount++;
//         }
//     }
//     //前面没出现，保存，其前面出现，不保存
//     //输出（打印only数组）
//     for (i = 0; i < onlycount; i++)
//         cout << only[i] << " ";
//     return 0;
// }

// #include <iostream>
// using namespace std;
// int main()
// {
//     int nums[1000];
//     int i, count;
//     bool norpt;
//     count = 0;
//     while(cin >> nums[count])
//     {
//         norpt = true;
//         //是否重复，是，则count不增加以等待覆盖，否，则count指向下一个待输入
//         for (i = 0; i < count; i++)
//             if (nums[i] == nums[count])
//                 norpt = false;
//         if (norpt)
//             count++;
//     }
//     //输出
//     cout << count << " ";
//     for (i = 0; i < count; i++)
//         cout << nums[i] << " ";
//     return 0;
// }

// #include <iostream>
// using namespace std;
// void changebb(int);
// int main()
// {
//     int bb, i, sqr, j, m;
//     bool ishws;
//     cin >> bb;
//     int bnums[32];
//     int bbnums[32];
//     //输入一个B，进制选择

//     //判断回文数
//     for (i = 1; i <= 200; i++)
//     {
//         ishws = true;
//         sqr = i * i;    // 1遍历，求出平方
//         for (j = 0; ;)
//         {
//             bbnums[j] = sqr % bb;
//             j++;
//             sqr = sqr / bb;
//             if (sqr == 0)
//                 break;
//         }
//         //2 平方转换成B进制
//         for (m = 0; m < j; m++)
//         {
//             if (bbnums[j-m-1] != bbnums[m])
//                 ishws = false;
//         }
//         //3检验转换后是否回文数
//         if (ishws)
//         {
//             // 输出原数字B进制
//             int temp = i;
//             int b = 0;
//             while(1)
//             {
//                 bnums[b] = temp % bb;
//                 b++;
//                 temp = temp / bb;
//                 if (temp == 0)
//                     break;
//             }
//             for (int a = 0; a < b; a++)
//                 changebb(bnums[a]);
//             cout << " ";
//             //输出平方的B进制
//             for (int a = 0; a < j; a++)
//                 changebb(bbnums[a]);
//             cout << endl;
//         }
//         //是则转换描述+输出，否则不输出
//     }
//     return 0;//别放循环内压！

// }

// void changebb(int m){
//     switch(m)
//     {
//         case 0:
//         case 1:
//         case 2:
//         case 3:
//         case 4:
//         case 5:
//         case 6:
//         case 7:
//         case 8:
//         case 9:  cout << m;
//                 break;
//         case 10: cout << "A";
//                 break;
//         case 11: cout << "B";
//                 break;
//         case 12: cout << "C";
//                 break;
//         case 13: cout << "D";
//                 break;
//         case 14: cout << "E";
//                 break;
//         case 15: cout << "F";
//                 break;
//         case 16: cout << "G";
//                 break;
//         case 17: cout << "H";
//                 break;
//         case 18: cout << "I";
//                 break;
//         case 19: cout << "J";
//                 break;
//         case 20: cout << "K";
//                 break;
//     }
// }

// #include <iostream>
// using namespace std;
// int main()
// {
//     int n;
//     int x;
//     bool isContained = false;
//     int nums[1000];
//     cin >> n;
//     for (int i = 0; i < n; i++)
//         cin >> nums[i];
//     // 输入个数及有序数组的数据
//     cin >> x;
//     //输入x
//     int l = 0;
//     int r = n - 1;
//     int mid;
//     while(l <= r)
//     {
//         mid = (l + r) / 2;//mid 要在循环内更新！
//         if (x == nums[mid])
//         {
//             isContained = true;
//             cout << mid;
//             break;
//         }
//         else if (x < nums[mid])
//             r = mid - 1;
//         else if (x > nums[mid])
//             l = mid + 1;
//     }
//     //判断是否在数组中（bool）
//     //yes => 输出下标
//     // no => 插入
//     if (!isContained)
//     {
//         int i;
//         if (l == 0)
//             cout << "0";
//         else if (r == n - 1)
//             cout << n;
//         else
//             cout << l;
//         return 0;
//     }
// }

// #include <iostream>
// using namespace std;
// int main()
// {
//     int n;
//     cin >> n;//初始化！！！！！！！！
//     int max;
//     bool foundMax = false;
//     int rec[20][20];
//     for (int i = 0; i < n; i++)
//         for (int j = 0; j < n; j++)
//             cin >> rec[i][j];
//     //获取输入
//     for (int j = n - 1; (j >= 0) && (!foundMax); j--)
//     {
//         for (int i = 0; (i < n) && (!foundMax); i++)
//         {
//             if (rec[i][j] == 1)
//             {
//                 foundMax = true;
//                 max = i;
//             }
//         }
//     }
//     //找最大的，数据处理
//     //输出最大值
//     cout << max;
// }

// #include <iostream>
// using namespace std;
// int main()
// {
//     //获取输入
//     int n;
//     int x;
//     int nums[100];
//     bool foundX = false;
//     cin >> n;
//     for (int i = 0; i < n; i++)
//             cin >> nums[i];
//     cin >> x;
//     //寻找位置，存在==输出位置，不存在==-1-1
//     int l = 0;
//     int r = n - 1;
//     int mid;
//     while (l <= r)
//     {
//         mid = (l + r) / 2;
//         if (x == nums[mid])
//         {
//             foundX = true;
//             int temp = mid;
//             while (nums[temp - 1] == x)
//                 temp--;
//             cout << temp << " ";
//             while (nums[temp + 1] == x)
//                 temp++;
//             cout << temp;
//             break;//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//         }
//         else if (x < nums[mid])
//             r = mid - 1;
//         else
//             l = mid + 1;
//     }
//     //输出(not found)
//     if (!foundX)
//         cout << "-1 -1";
//     return 0;
// }

// #include <iostream>
// using namespace std;
// int main()
// {
//     //获取输入
//     int n;
//     int temp;
//     int l, r, mid;
//     int nums[100];

//     cin >> n;
//     cin >> nums[0];
//     for (int i = 1; i < n; i++)
//     {
//         bool foundX = false;
//         cin >> temp;
//         l = 0;
//         r = i - 1;
//         while(l <= r)
//         {
//             mid = (l + r) / 2;
//             if (nums[mid] == temp)
//             {
//                 for (int m = i; m >= mid; m--)
//                     nums[m] = nums[m - 1];
//                 nums[mid] = temp;
//                 foundX = true;
//                 break;//break!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//             }
//             else if (temp < nums[mid])
//                 r = mid - 1;
//             else
//                 l = mid + 1;
//         }
//         if (!foundX)
//         {
//             if (l == 0)
//             {
//                 for (int m = i; m >= 0; m--)
//                     nums[m] = nums[m - 1];
//                 nums[0] = temp;
//             }
//             else if(l == i)
//                 nums[i] = temp;
//             else
//             {
//                 for (int m = i; m >= l; m--)
//                     nums[m] = nums[m - 1];
//                 nums[l] =
//                 temp;//插入位置是l但并不是r！！！！！！！！！！！！！！！！！！！！！
//             }
//         }
//         // cin >> nums[i];
//     }
//     //数据处理（插入排序）//1找到位置//后移//插入

//     for (int i = 0; i < n; i++)
//         cout << nums[i] << " ";
//     //输出
//     return 0;
// }

// #include <iostream>
// using namespace std;
// int main()
// {

//     return 0;
// }

// #include <iostream>
// using namespace std;
// int main()
// {
//     int n,l;
//     int balls[10000];
//     //获取输入
//     cin >> n >> l;
//     for (int i = 0; i < n; i++)
//         cin >> balls[i];
//     //处理数据
//     //最快//最慢//奇偶
//     if (n % 2 == 1)
//     {
//         if ((l - balls[n-1]) < balls[1])
//             cout << (l - balls[n-1]) << " ";
//         else
//             cout << balls[1] << " ";
//         if ((l - balls[0]) < balls[n-2])
//             cout << balls[n-2] << " ";
//         else
//             cout << (l - balls[0]) << " ";
//     }
//     else
//     {
//         if (l - balls[n-2] < balls[1])
//             cout << (l - balls[n-2]) << " ";
//         else
//             cout << balls[1] << " ";
//         if (l - balls[0] > balls[n-1])
//             cout << (l - balls[0]) << " ";
//         else
//             cout << balls[n-1] << " ";
//     }
//     //输出
//     return 0;
// }

// #include <iostream>
// using namespace std;
// int main()
// {
//     int n, l;
//     int balls[10000];
//     int max, min;
//     cin >> n >> l;
//     max = 0;
//     min = l;
//     //获取输入转化时间
//     for (int i = 0; i < n; i++)
//     {
//         cin >> balls[i];
//         if (i % 2 == 0)
//             balls[i] = l - balls[i];
//     }
//     //找到最大最小
//     for (int i = 0; i < n; i++)
//     {
//         if (balls[i] > max)
//             max = balls[i];
//         if (balls[i] < min)
//             min = balls[i];
//     }
//     //输出
//     cout << min << " " << max;

//     return 0;
// }

// #include <iostream>
// using namespace std;
// int main()
// {
//     double temp, ans, count;
//     ans = 0;
//     count = 0;
//     while(count < 4)
//     {
//         if(!(cin >> temp))
//         {
//             cin.clear();
//             cin.get();
//         }
//         else
//         {
//             ans += temp;
//             count++;
//         }
//     }
//     cout << ans;
//     return 0;
// }

// #include <iostream>
// using namespace std;
// const int Size = 100000;
// int main()
// {
//     int arr[Size];
//     int ans = 0;
//     for (int i = 0; i < Size; i++)
//         arr[i] = i + 1;
//     for (int i = 1; i < Size; i++)
//     {
//         if (arr[i] != 0)
//         {
//             ans += arr[i];
//             for (int j = i+1; j < Size; j++)
//                 if (arr[j] % arr[i] == 0)
//                     arr[j] = 0;
//         }
//     }
//     cout << ans;
//     return 0;
// }

// #include <iostream>
// int main()
// {
//     using namespace std;
//     int nums[5];
//     int temp, ccount;
//     for (int i = 0; i < 5; i++)
//         cin >> nums[i];
//     for (int i = 0; i< 5; i++)
//     {
//         temp = -1;
//         for (int j = 0; j < 5; j++)
//             if (nums[j] > temp)
//             {
//                 temp = nums[j];
//                 ccount = j;
//             }
//         cout << temp;
//         nums[ccount] = -1;
//     }
//     return 0;
// }

// #include <iostream>
// using namespace std;
// int main()
// {
//     int isbn[20];
//     char temp;
//     int count = 0;
//     int categ = 0;
//     int tot = 0;
//     //获取信息输入
//     while ((temp = cin.get()) != '\n')
//     {
//         if (temp != '-')
//         {
//             isbn[count] = temp - '0';
//             count++;
//         }
//         else
//             categ++;
//     }
//     //分辨13与10，分别处理
//     if (categ == 3)
//     {
//         for (int i = 0; i < 10; i++)
//             tot += isbn[i] * (10 - i);
//         if (tot % 11 == 0)
//             cout << "yes";
//         else
//             cout << "no";
//     }
//     else
//     {
//         for (int i = 0; i < 13; i++)
//             if (i % 2 == 0)
//                 tot += isbn[i];
//             else
//                 tot += isbn[i] * 3;
//         if (tot % 10 == 0)
//             cout << "yes";
//         else
//             cout << "no";
//     }
//     return 0;
// }

// #include <iostream>
// using namespace std;

// int main()
// {
//     int r;
//     int f[12][12];
//     int max;

//     cin >> r;
//     for (int i = 1; i <= r; i++)
//     {
//         f[i][0] = f[i][i+1] = 0;
//         for (int j = 1; j <= i; j++)
//             cin >> f[i][j];
//     }
//     for (int i = 1; i <= r; i++)
//     {
//         for (int j = 1; j <= r; j++)
//         {
//             f[i][j] += ((f[i - 1][j] > f[i-1][j-1]) ? f[i- 1][j] :
//             f[i-1][j-1]);
//         }
//     }

//     max = f[r][1];
//     for (int j = 1; j <= r; j++)
//         if (f[r][j] > max)
//             max = f[r][j];
//     cout << max;

//     return 0;
// }

// #include <iostream>
// using namespace std;

// int main()
// {
//     int m, n;
//     int mat [12][12] = {0};
//     int max[12][12] ={0};//第i行的多个最大值的下表
//     bool isFound = false;
//     //获取输入
//     cin >> m >> n;
//     for (int i = 0; i < m; i++)
//         for (int j = 0; j < n; j++)
//             cin >> mat[i][j];
//     //找鞍点
//     //每行最大
//     for (int i = 0; i < m; i++)
//     {
//         int tempmax = mat[i][0];
//         int count = 1;
//         for (int j = 0; j < n; j++)
//             if (tempmax < mat[i][j])
//             {
//                 tempmax = mat[i][j];
//                 max[i][0] = j;
//             }
//         for (int j = max[i][0] + 1; j < n; j++)
//             if (tempmax == mat[i][j])
//             {
//                 max[i][count] =
//                 j;//第i行第max【i】【(0到count)q】列元素，以满足行最大，看是否在该列最小
//                                     //该列最小的元素下标为min【q】【】
//                 count++;
//             }
//         for (int a = 0;  a < count; a++)
//         {
//             bool isMin = true;
//             for (int b = 0; b < m; b++)
//             {
//                 if (mat[i][max[i][a]] > mat[b][max[i][a]])
//                     {
//                         isMin = false;
//                         break;
//                     }
//             }
//             if (isMin)
//             {
//                 cout << "mat[" << i <<"]" << "[" << max[i][a] <<"]=" <<
//                 mat[i][max[i][a]] << endl; isFound = true;
//             }
//         }
//     }
//     if (!isFound)
//         cout << "Not Found";
//     return 0;
// }

// #include <iostream>
// using namespace std;

// int main()
// {
//     char chs[82];
//     int num = 0;
//     cin.getline(chs, 82);
//     for (int i = 0; chs[i] != '\0'; i++)
//     {
//         if ('0' <= chs[i] && chs[i] <= '9')
//         {
//             num = num * 10 + chs[i] - '0';
//         }
//     }
//     num *= 2;
//     cout << num;
//     return 0;
// }

// #include <iostream>
// using namespace std;

// int main()
// {
//     char chs[82];
//     int count = 0;
//     cin.getline(chs, 82);
//     for (int i = 0; chs[i] != '\0'; i++)
//     {
//         switch(chs[i])
//         {
//             case 'a':
//             case 'e':
//             case 'i':
//             case 'o':
//             case 'u':
//             case 'A':
//             case 'E':
//             case 'I':
//             case 'O':
//             case 'U': count++;
//         }
//     }
//     cout << count;
//     return 0;
// }

// #include <iostream>
// #include <cstring>
// using namespace std;

// int main()
// {
//     char chs[82];
//     char x;
//     int max;
//     bool isFound = false;

//     cin.getline(chs, 82);
//     x = cin.get();
//     for (int i = 0; chs[i] != '\0'; i++)
//     {
//         if (chs[i] == x)
//         {
//             isFound = true;
//             max = i;
//         }
//     }
//     if (!isFound)
//         cout << "Not Found";
//     else
//         cout << max;
//     return 0;
// }

// #include <iostream>
// #include <cstring>
// using namespace std;
// int main()
// {
//     char chs[82];
//     cin.getline(chs, 82);
//     int n = strlen(chs);
//     for (int i = 0; i < n; i++)
//     {
//         char temp = chs[0];
//         //找到当前最大
//         for (int j = 0; j < n; j++)
//         {
//             if (chs[j] > temp)
//             {
//                 temp = chs[j];
//             }
//         }
//         //去掉重复(self)
//         for (int j = 0; j < n; j++)
//         {
//             if (chs[j] == temp)
//                 chs[j] = 0;
//         }
//         //输出
//         if (temp != 0)
//             cout << temp;
//     }
// }

// #include <iostream>
// using namespace std;

// int main()
// {
//     int n;
//     int ccount, ncount, ecount;
//     char chs[10][82];

//     ccount = ncount = ecount = 0;
//     cin >> n;
//     cin.get();
//     for (int i = 0; i < n; i++)
//     {
//         cin.getline(chs[i], 80);
//         for (int j = 0; chs[i][j] != '\0'; j++)
//         {
//             if (('a' <= chs[i][j] && chs[i][j] <= 'z') || ('A' <= chs[i][j]
//             && chs[i][j] <= 'Z'))
//                 ccount++;
//             else if ('0' <= chs[i][j] && chs[i][j] <= '9')
//                 ncount++;
//             else if (chs[i][j] != ' ' && chs[i][j] != '\n')
//                 ecount++;
//         }
//     }
//     cout << "英文字母：" << ccount << endl;
//     cout << "数字：" << ncount << endl;
//     cout << "其他字符：" << ecount << endl;
//     return 0;
// }

// #include <iostream>
// using namespace std;
// int main()
// {
//     char str1[162];
//     char str2[162];
//     bool isFound = false;
//     int n;

//     cin >> str1;
//     cin >> str2;
//     for (int i = 0; str1[i] != '\0'; i++)
//     {
//         if (str2[0] == str1[i])
//         {
//             isFound = true;
//             n = i;
//             for (int j = 1; str2[j] != 0; j++)
//             {
//                 if (str1[i + j] != str2[j])
//                     isFound = false;
//             }
//         }
//     }
//     if (!isFound)
//     {

//     }
// }

// #include <iostream>
// #include <cstring>
// using namespace std;
// int main()
// {
//     char str1[162];
//     char str2[162];
//     bool isFound;

//     cin.getline(str1, 160);
//     cin.getline(str2, 160);
//     for (int i = 0; i < strlen(str1); i++)
//     {
//         if (str1[i] == str2[0])
//         {
//             isFound = true;
//             for (int j = 0; j < strlen(str2); j++)
//             {
//                 if (str1[i + j] != str2[j])
//                 {
//                     isFound = false;
//                     break;
//                 }
//             }
//         }
//         if (isFound)
//         {
//             cout << i;
//             break;
//         }
//     }
//     if (!isFound)
//         cout << "-1";
//     return 0;
// }

// #include <iostream>
// using namespace std;
// int main()
// {
//     char ch;
//     char txt[10000];
//     //读取输入
//     int n = 0;
//     int count = 0;
//     int strt, end;

//     while (cin.get(ch))
//     {
//         txt[n] = ch;
//         n++;
//     }
//     //找回文
//     for (int i = 0; i < n; i++)
//     {
//         int countnow = 0;
//         if ((txt[i] >= 'a' && txt[i] <= 'z') || (txt[i] >= 'A' && txt[i]
//         <='Z'))
//             for (int j = n-1; j >= 0; j--)
//             {
//                 bool isRound = true;
//                 if ((txt[j] >= 'a' && txt[j] <= 'z') || (txt[j] >= 'A' &&
//                 txt[j] <='Z'))
//                 {
//                     for (int m = 0; m <= j - i; m++)
//                         if (((txt[i+m] >= 'a' && txt[i+m] <= 'z') ||
//                         (txt[i+m] >= 'A' && txt[i+m] <='Z')) &&((txt[j-m] >=
//                         'a' && txt[j-m] <= 'z') || (txt[j-m] >= 'A' &&
//                         txt[j-m] <='Z')))
//                         {
//                             if (txt[i=m] != txt[j-m])
//                             {
//                                 isRound = false;
//                                 break;
//                             }
//                             countnow++;
//                         }
//                 }
//                 if (isRound && (count < countnow))
//                 {
//                     count = countnow;
//                     strt = i;
//                     end = j;
//                 }
//             }
//     }
//     cout << count;
//     for (int i = strt; i <= end; i++)
//         cout << txt[i];
//     return 0;
// }

// #include <iostream>
// using namespace std;
// char isChar(char);
// int findRound(char * pt1, char * pt2, int a);
// int main()
// {
//     char ch;
//     char txtt[10000];
//     char txt[10000];
//     //读取输入
//     int tn = 0;
//     int n = 0;
//     int count = 0;
//     int strt;

//     while (cin.get(ch))
//     {
//         txtt[tn] = ch;
//         tn++;
//         if (ch = isChar(ch))
//         {
//             txt[n] = ch;
//             n++;
//         }
//     }
//     // cout << txtt;
//     // 找回文
//     for (int i = 0; i < n; i++)
//     {
//         int countnow = 0;
//         int temp;
//         if (txt[i] == txt[i+1])
//         {
//             int range = (n - i - 2 > i ? i: n - i - 2);
//             temp = findRound(&txt[i], &txt[i+1], range);
//             countnow = 2 * temp;
//         }
//         if (count < countnow)
//         {
//             count = countnow;
//             strt = i - temp + 1;
//         }
//         if (txt[i] == txt[i+2])//不是else if
//         {
//             int range = (n - i - 3 > i ? i : n - i - 3);
//             temp = findRound(&txt[i], &txt[i+2], range);
//             countnow = 2 * temp + 1;
//         }
//         if (count < countnow)
//         {
//             count = countnow;
//             strt = i - temp + 1;
//         }
//     }
//     if (count == 0)
//     {
//         cout << "1" << endl;
//         cout << txtt[0];
//         return 0;
//     }
//     cout << count << endl;

//     bool isFound;
//     int start, end;
//     for (int i = 0; i < n; i++)
//     {
//         int countothers;
//         if (char temp = isChar(txtt[i]))
//         {
//             countothers = 0;
//             if (temp == txt[strt])
//             {
//                 isFound = true;
//                 for (int j = 0; j < count; j++)
//                 {
//                     int tmp;
//                     while(true)
//                     {
//                         if (tmp = isChar(txtt[i+j+countothers]))
//                         {
//                             if (tmp != txt[strt + j])
//                                 isFound = false;
//                             break;
//                         }
//                         else
//                             countothers++;
//                     }
//                     if (!isFound)
//                         break;
//                 }
//             }
//         }
//         if (isFound)
//         {
//             start = i;
//             end = i + count + countothers;
//             break;
//         }
//     }
//     if (isFound)
//         for (int i = start; i < end; i++)
//             cout << txtt[i];
//     return 0;
// }

// char isChar(char ch)
// {
//     if (ch >= 'a' && ch <= 'z')
//         return ch;
//     else if (ch >= 'A' && ch <= 'Z')
//         return ch - 'A' + 'a';
//     else
//         return 0;
// }

// int findRound(char * pt1, char * pt2, int a)
// {
//     int equal = 0;
//     for (; equal <= a; equal++)
//         if (pt1[0-equal] != pt2[0+equal])
//             break;
//     return equal;
// }

// #include <iostream>
// #include <cstring>
// using namespace std;
// int beforerpt(char *, int);
// int main()
// {
//     char chs[100];
//     int max, temp;
//     cin >> chs;
//     for (int i = 0; i < strlen(chs); i++)
//         if (max < (temp = beforerpt(&chs[i], strlen(chs) - i - 1)))
//             max = temp;
//     cout << max << endl;
// }
// int  beforerpt(char * pt, int n)
// {
//     int rpt[26] = {0};
//     int i;
//     for (i = 0; i <= n; i++)
//     {
//         rpt[pt[i] - 'a']++;
//         if (rpt[pt[i] - 'a'] == 2)
//             break;
//     }
//     return i;
// }

// #include <iostream>
// using namespace std;
// int main()
// {
//     int a, b, ans;
//     char op;
//     cin >> a;
//     cin.get(op);
//     cin >> b;
//     switch(op)
//     {
//         case '+':ans = a + b;
//                 break;
//         case '-':ans = a - b;
//                 break;
//         case '*':ans = a * b;
//                 break;
//         case '/':ans = a / b;
//                 break;
//     }
//     cout << a << op << b << "=" << ans << endl;
//     return 0;
// }

// #include <iostream>
// #include <cstring>
// using namespace std;
// int main()
// {
//     char chs[82];
//     cin.getline(chs, 80);
//     // cout << strlen(chs);
//     for (int i = 0; i < strlen(chs); i++)
//         if (i % 2 == 1)
//             cout << chs[i];
//     return 0;
// }

// #include <iostream>
// int main()
// {
//     int lmp[5][5];
//     bool litAll;
//     for (int i = 0; i < 5; i++)
//         for (int j = 0; j < 5; j++)
//         {
//             int temp;
//             if ((temp = cin.get())!= '\n')
//                 lmp[i][j] = temp - '0';
//         }

//     for (int i = 0; ; i++)
//     {

//     }
// }

// #include <iostream>
// #include <cstring>
// using namespace std;

// int main()
// {
//     int size;
//     char chs[32] = {0};
//     char org[100][100] = {0};

//     cin >> size;
//     cin.get();
//     cin.getline(chs, 100);
//     if (size == 1)
//     {
//         cout << chs;
//         return 0;
//     }
//     for (int i = 1; i < strlen(chs); i++)
//     {
//         int q = i % (2 * size - 2);
//         int count = i / (2 * size - 2);
//         if (q < size)
//             org[q][count * (size - 1)] = chs[i];
//         else
//             org[size - (q + 1 - size) - 1][count * (size - 1) + (q + 1 -
//             size)] = chs[i];
//     }

//     cout << chs[0];
//     for (int i = 0; i < size; i++)
//         for (int j = 0; j < 100; j++)
//             if (org[i][j] != 0)
//                 // cout << i << "  " << j << "   " << org[i][j] << endl;
//                 cout << org[i][j];
//     return 0;
// }

// a e
// bdf
// c g

// a d
// b f
// ceg

// #include <iostream>
// using namespace std;
// int press(int pt[][5], int m, int n);//改变灯，同时改变一个按的次数
// int main()
// {
//     bool allLit;
//     int lmp[5][5];
//     int i = 0;
//     int j = 0;
//     int temp , min;
//     for (int m = 0; m < 5; m++)
//         for (int n = 0; n < 5;n++)
//         {
//             char t = cin.get();
//             if (t == '\n')
//                 continue;
//             else
//                 lmp[m][n] = t - '0';
//         }
//     cout << "aa"<< endl;
//     min = 26;

//     for (lmp[i][j] = 0; lmp[i][j] < 2; temp = press(lmp, i, j))
//     for (lmp[i][++j] = 0; lmp[i][j] < 2; temp += press(lmp, i, j))
//     for (lmp[i][++j] = 0; lmp[i][j] < 2; temp += press(lmp, i, j))
//     for (lmp[i][++j] = 0; lmp[i][j] < 2; temp += press(lmp, i, j))
//     for (lmp[i][++j] = 0; lmp[i][j] < 2; temp += press(lmp, i, j))

//     for (lmp[++i][j%=5] = 0; lmp[i][j] < 2; press(lmp, i, j))
//     for (lmp[i][++j] = 0; lmp[i][j] < 2; temp += press(lmp, i, j))
//     for (lmp[i][++j] = 0; lmp[i][j] < 2; temp += press(lmp, i, j))
//     for (lmp[i][++j] = 0; lmp[i][j] < 2; temp += press(lmp, i, j))
//     for (lmp[i][++j] = 0; lmp[i][j] < 2; temp += press(lmp, i, j))

//     for (lmp[++i][j%=5] = 0; lmp[i][j] < 2; press(lmp, i, j))
//     for (lmp[i][++j] = 0; lmp[i][j] < 2; temp += press(lmp, i, j))
//     for (lmp[i][++j] = 0; lmp[i][j] < 2; temp += press(lmp, i, j))
//     for (lmp[i][++j] = 0; lmp[i][j] < 2; temp += press(lmp, i, j))
//     for (lmp[i][++j] = 0; lmp[i][j] < 2; temp += press(lmp, i, j))

//     for (lmp[++i][j%=5] = 0; lmp[i][j] < 2; press(lmp, i, j))
//     for (lmp[i][++j] = 0; lmp[i][j] < 2; temp += press(lmp, i, j))
//     for (lmp[i][++j] = 0; lmp[i][j] < 2; temp += press(lmp, i, j))
//     for (lmp[i][++j] = 0; lmp[i][j] < 2; temp += press(lmp, i, j))
//     for (lmp[i][++j] = 0; lmp[i][j] < 2; temp += press(lmp, i, j))

//     for (lmp[++i][j%=5] = 0; lmp[i][j] < 2; press(lmp, i, j))
//     for (lmp[i][++j] = 0; lmp[i][j] < 2; temp += press(lmp, i, j))
//     for (lmp[i][++j] = 0; lmp[i][j] < 2; temp += press(lmp, i, j))
//     for (lmp[i][++j] = 0; lmp[i][j] < 2; temp += press(lmp, i, j))
//     for (lmp[i][++j] = 0; lmp[i][j] < 2; temp += press(lmp, i, j))

//     {
//         allLit = true;
//         for (int i = 0; i < 25; i ++)
//             if (lmp[i] == 0)
//             {
//                 break;
//                 allLit = false;
//             }
//         if (allLit && temp < min) min = temp;
//     }

//     cout << min << endl;
//     return 0;
// }
//             //一个不亮的都没有
//             //min < 次数？min:次数；

// int press(int pt[][5], int m, int n)
// {
//     pt[m][n] = (pt[m][n]+1) % 2;
//     if (m-1 > 0 && m-1 < 5) pt[m-1][n] = (pt[m-1][n]+1) % 2;
//     if (n-1 > 0 && n-1 < 5) pt[m][n-1] = (pt[m][n]+1) % 2;
//     if (m+1 > 0 && m+1 < 5) pt[m+1][n] = (pt[m+1][n]+1) % 2;
//     if (n+1 > 0 && n+1 < 5) pt[m][n+1] = (pt[m][n+1]+1) % 2;

//     return 1;
// }

// #include <iostream>
// using namespace std;
// void press(int ar[][5], int a, int b, int & c);
// bool inrange(int num);
// int main()
// {
//     int lights[5][5];
//     char tmp;
//     int count = 0;
//     bool allLit = true;

//     for (int i = 0; i < 5; i++)
//         for (int j = 0; j < 5; )
//         {
//             cin.get(tmp);
//             if ( tmp != '\n')// if (tmp = cin.get() != '\n')
//             {
//                 lights[i][j] = tmp - '0';
//                 j++;
//             }
//         }

//     if (lights[0][0] == 0 && lights[0][1] == 0)
//             press(lights, 0, 0, count);
//     for (int j = 1; j < 4; j++)
//     {
//         if (lights[0][j] && lights[0][j+1] == 0)
//             press(lights, 0, j+1, count);
//     }

//     for (int i = 1; i < 5; i++)
//     {
//         for (int j = 0; j < 5; j++)
//             if (lights[i-1][j] == 0)
//                 press(lights, i, j, count);
//     }

//     for (int i = 0; i < 5; i++)
//         for (int j = 0; j < 5; j++)
//             if (lights[i][j] == 0)
//             {
//                 allLit = false;
//                 break;
//             }
//     if (allLit)
//         cout << count;
//     else
//         cout << "-1";

//     return 0;
// }

// void press(int ar[][5], int a, int b, int & c)
// {
//     c++;
//     ar[a][b] = (ar[a][b] + 1) % 2;
//     if (inrange(a-1))
//         ar[a-1][b] = (ar[a-1][b] + 1) % 2;
//     if (inrange(a+1))
//         ar[a+1][b] = (ar[a+1][b] + 1) % 2;
//     if (inrange(b-1))
//         ar[a][b-1] = (ar[a][b-1] + 1) % 2;
//     if (inrange(b+1))
//         ar[a][b+1] = (ar[a][b+1] + 1) % 2;
// }

// bool inrange(int num)
// {
//     if (0 <= num && num < 5)
//         return true;
//     else
//         return false;
// }

#include <iostream>
using namespace std;
char isChar(char);
int findRound(char * pt1, char * pt2, int a);
int main()
{
    char ch;
    char txtt[10000];
    char txt[10000];
    //读取输入
    int tn = 0;
    int n = 0;
    int count = 0;
    int strt;

    while (cin.get(ch))
    {
        txtt[tn] = ch;
        tn++;
        if (ch = isChar(ch))
        {
            txt[n] = ch;
            n++;
        }
    }
    // cout << txtt;
    // 找回文
    for (int i = 0; i < n; i++)
    {
        int countnow = 0;
        int temp;
        if (txt[i] == txt[i+1])
        {
            int range = (n - i - 2 > i ? i: n - i - 2);
            temp = findRound(&txt[i], &txt[i+1], range);
            countnow = 2 * temp;
        }
        if (count < countnow)
        {
            count = countnow;
            strt = i - temp + 1;
        }
        if (txt[i] == txt[i+2])//不是else if
        {
            int range = (n - i - 3 > i ? i : n - i - 3);
            temp = findRound(&txt[i], &txt[i+2], range);
            countnow = 2 * temp + 1;
        }
        if (count < countnow)
        {
            count = countnow;
            strt = i - temp + 1;
        }
    }
    if (count == 0)
    {
        cout << count + 1 << endl;
        for (int a = 0; a < n; a++)
        {
            if (isChar(txt[a]))
            {
                cout << txt[a];
                break;
            }
        }// cout << txtt[0];
        return 0;
    }
    cout << count << endl;

    bool isFound;
    int start, end;
    for (int i = 0; i < tn; i++)//n
    {
        int countothers;
        // if (char temp = isChar(txtt[i]))
        char temp;
        if (temp = isChar(txtt[i]))
        {
            countothers = 0;
            if (temp == txt[strt])
            {
                isFound = true;
                for (int j = 0; j < count; j++)
                {
                    int tmp;
                    while(true)
                    {
                        if (tmp = isChar(txtt[i+j+countothers]))
                        {
                            if (tmp != txt[strt + j])
                                isFound = false;
                            break;
                        }
                        else
                            countothers++;
                    }
                    if (!isFound)
                        break;
                }
            }
        }
        if (isFound)
        {
            start = i;
            end = i + count + countothers;
            break;
        }
    }
    if (isFound)
        for (int i = start; i < end; i++)
            cout << txtt[i];
    return 0;
}

char isChar(char ch)
{
    if (ch >= 'a' && ch <= 'z')
        return ch;
    else if (ch >= 'A' && ch <= 'Z')
        return ch - 'A' + 'a';
    else
        return 0;
}

int findRound(char * pt1, char * pt2, int a)
{
    int equal = 0;
    for (; equal <= a; equal++)
        if (pt1[0-equal] != pt2[0+equal])
            break;
    return equal;
}

// #include <cmath>
// #include <iostream>
// #include <string>
// #include <vector>

// using namespace std;

// int main() {
// 	const int N = 5;
// 	const int N_N = N * N;

// 	int mat[N][N];
// 	for (int i = 0; i < N; i++) {
// 		string temp;
// 		cin >> temp;
// 		for (int j = 0; j < N; j++) mat[i][j] = temp[j] == '0' ? 1 : 0;
// 	}

// 	int stat = 0;
// 	int plan = 0;
// 	int ans = N_N;

// 	for (int i = 0; i < N_N; i++) {
// 		stat = stat << 1;
// 		stat += mat[i / N][i % N];
// 	}

// 	for (int plan = 0; plan < pow(2, N_N); plan++) {
// 		int cnt = 0;

// 		int num = plan;
// 		while (num) {
// 			cnt++;
// 			num &= (num - 1);	 // 清除最右侧的1
// 		}
// 		if (cnt >= ans) continue;

// 		int temp = stat ^ plan;
// 		for (int i = 0; i < N_N; i++) {
// 			if (plan & (1 << N_N - i - 1)) {
// 				if (i / N - 1 >= 0)
// 					temp ^= (1 << (N_N - (N * (i / N - 1) + i % N) - 1));
// 				if (i / N + 1 < N) temp ^= (1 << (N_N - (N * (i / N + 1) + i % N) - 1));
// 				if (i % N - 1 >= 0)
// 					temp ^= (1 << (N_N - (N * (i / N) + i % N - 1) - 1));
// 				if (i % N + 1 < N) temp ^= (1 << (N_N - (N * (i / N) + i % N + 1) - 1));
// 			}
// 		}
// 		if (temp == 0) ans = cnt;
// 	}
// 	cout << ans << endl;
// }