// #include <iostream>
// using namespace std;
// struct ttime
// {
//     int hours;
//     int mins;
//     int secs;
// };
// void setTime(ttime &);
// void increase(ttime &);
// void showTime(ttime &);
// void showtt(int);



// int main()
// {
//     struct ttime t1, t2;

//     setTime(t1);
//     showTime(t1);
//     increase(t1);
//     showTime(t1);
    
//     setTime(t2);
//     showTime(t2);
//     increase(t2);
//     showTime(t2);

//     return 0;
// }

// void setTime(ttime & tt)
// {
//     cin >> tt.hours >> tt.mins >> tt.secs;
// }
// void increase(ttime & tt)
// {
//     tt.secs++;
//     if (tt.secs == 60)
//     {
//         tt.secs = 0;
//         tt.mins++;
//     }
//     if (tt.mins == 60)
//     {
//         tt.mins = 0;
//         tt.hours++;
//     }
//     if (tt.hours == 24)
//         tt.hours = 0;
// }
// void showTime(ttime & tt)
// {
//     showtt(tt.hours);
//     cout << ":";
//     showtt(tt.mins);
//     cout << ":";
//     showtt(tt.secs);
//     cout << endl;
// }
// void showtt(int t)
// {
//     if (t < 10)
//         cout << "0" << t;
//     else
//         cout << t;
// }
// #include <iostream>
// struct plur
// {
//     int m;
//     int n;
// };
// void showpl(plur & pl);
// using namespace std;


// int main()
// {
//     plur x, y;
//     cin >> x.m >> x.n >> y.m >> y.n;

//     cout << "x = ";
//     showpl(x);
//     cout << "y = ";
//     showpl(y);

//     x.m += y.m;
//     x.n += y.n;
//     cout << "x += y; x = ";
//     showpl(x);
//     int tym = y.m;
//     y.m = x.m * y.m - x.n * y.n;
//     // cout << x.m << endl;
//     // cout << y.n << endl;
//     // cout << x.n << endl;
//     // cout << y.m << endl;
//     y.n = x.m * y.n + x.n * tym;
//     // cout << y.n << endl;
//     cout << "y *= x; y = ";
//     showpl(y);

//     plur tmp;
//     tmp.m = x.m + y.m;
//     tmp.n = x.n + y.n;
//     cout << "x + y = ";
//     showpl(tmp);
//     tmp.m = x.m * y.m - x.n * y.n;
//     tmp.n = x.m * y.n + x.n * y.m;
//     cout << "y * x = ";
//     showpl(tmp);

//     cout << "x = ";
//     showpl(x);
//     cout << "y = ";
//     showpl(y);

//     return 0;
// }

// void showpl(plur & pl)
// {
//     if (pl.m == 0 && pl.n == 0)
//         cout << "0" << endl;
//     else if (pl.m == 0 && pl.n != 0)
//         cout << pl.n << "i" << endl;
//     else if (pl.m != 0 && pl.n == 0)
//         cout << pl.m << endl;
//     else if (pl.m != 0 && pl.n != 0)
//         if (pl.n > 0)
//             cout << pl.m << "+" << pl.n << "i" << endl;
//         else
//             cout << pl.m << pl.n << "i" << endl;
// }

// #include <iostream>
// struct dial
// {
//     char name[20];
//     int birth[3];
//     char phone[12];
//     char address[52];
// };
// void getDial(dial * p, int m);
// bool frontOld(int * p1, int * p2);
// void showDial(dial & dl);
// using namespace std;


// int main()
// {
//     int n;
//     cin >> n;
//     cin.get();
//     struct dial *pd = new dial[n];
//     for (int i = 0; i < n; i++)
//     {
//         getDial(pd, i);
//     }
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i + 1; j < n; j++)
//             if (!frontOld(pd[i].birth, pd[j].birth))
//             {
//                 dial tmp = pd[i];
//                 pd[i] = pd[j];
//                 pd[j] = tmp;
//             }
//     }
//     for (int i = 0; i < n; i++)
//         showDial(pd[i]);
//     delete [] pd;

//     return 0;
// }

// void getDial(dial * p, int m)
// {
//     char tmp;
//     int count = 0;
//     while ((tmp = cin.get()) != ' ')
//     {
//         (p[m].name)[count] = tmp;
//         count++;
//     }
//     (p[m].name)[count] = '\0';

//     for (count = 0; count < 3; count++)
//         cin >> (p[m].birth)[count];
//     cin.get();
    
//     count = 0;
//     while ((tmp = cin.get()) != ' ')
//     {
//         (p[m].phone)[count] = tmp;
//         count++;
//     }
//     (p[m].phone)[count] = '\0';

//     cin.getline(p[m].address, 51);

//     // count = 0;
//     // while ((tmp = cin.get()) != ' ')
//     // {
//     //     p->address[count] = tmp;
//     //     count++;
//     // }
//     // p->address[count] = '\0';
// }

// bool frontOld(int * p1, int * p2)
// {
//     if (p1[0] < p2[0])
//         return true;
//     else if (p1[0] > p2[0])
//         return false;
//     else
//     {
//         if (p1[1] < p2[1])
//             return true;
//         else if (p1[1] > p2[1])
//             return false;
//         else
//         {
//             if (p1[2] < p2[2])
//                 return true;
//             else
//                 return false;
//         }
//     }
// }

// void showDial(dial & dl)
// {
//     cout << dl.name << " "
//         << dl.birth[0] << " " << dl.birth[1] << " " << dl.birth[2] << " "
//         << dl.phone << " "
//         << dl.address << endl;
// }






// #include<iostream>
// using namespace std;


// struct Poly {
//     int max_order; // 最大次数
//     int *coeffs; // 每个次数（0、1、2、...、max_order）对应的系数
// };

// void update_poly(Poly &a, int order, int coeff)
// {
//     int * tmp = a.coeffs;
//     if (order > a.max_order || a.coeffs == nullptr){
//         a.max_order = order;
//         tmp = new int[order+1]{0};
//         if (a.coeffs != nullptr){
//         for (int i = 0; i < a.max_order; i++)
//             tmp[i] = a.coeffs[i]; 
//         delete []a.coeffs;
//         }
//     }
//     tmp[order] = coeff;
//     a.coeffs = tmp;
//     // TODO: 设置系数，同时，如果 coeffs 数组不够大，需要重新分配内存，并拷贝原有数据
// //delete放外面啥都给你删了，万一tmp没申请新的if条件测试失败。。。还好!coeffs也是个不对的，才有答案数值的出来。
// }
// Poly *add_poly(Poly *a, Poly *b) 
// {
//     int mmax;
//     mmax =  (a->max_order > b->max_order) ? a->max_order : b->max_order;
//     Poly * ans = new Poly;
//     ans -> max_order = mmax;

//     for (int i = 0; i <= mmax; i++)
//     {
//         if (i <= a->max_order && i <= b->max_order)
//             update_poly(*ans, i, a->coeffs[i]+b->coeffs[i]);
//         else if (i <= a->max_order)
//             update_poly(*ans, i, a->coeffs[i]);
//         else if (i <= b->max_order)
//             update_poly(*ans, i, b->coeffs[i]);
//     }
//     return ans;
//     // TODO: 进行加法计算，返回的 Poly 应使用 new 分配出来
// }



// void init_poly(Poly &a)
// {
//     a.max_order = 0;
//     a.coeffs = nullptr;
// }

// void cleanup_poly(Poly &a)
// {
//     // TODO: Add your code here!
//     delete a.coeffs;
// }

// void read_poly(Poly &a)
// {
//     init_poly(a);
//     int coeff, order;
//     while (true) {
//         cin >> coeff >> order;
//         if (order == -1) break; // end of the poly
//         update_poly(a, order, coeff);
//     }
// }

// void print_poly(Poly &a)
// {
//     // TODO：更新此函数，以正常输出值为 0 的多项式
//     bool allZero = true;
//     for (int i = a.max_order; i >= 0; --i)
//     {
//         if (a.coeffs[i] != 0){
//             allZero = false;
//             cout << a.coeffs[i] << ' ' << i << endl;
//         }
//     }
//     if (allZero)
//         cout << "0 0" << endl;
// }

// int main()
// {
//     Poly a, b;
//     read_poly(a);
//     read_poly(b);
//     Poly *c = add_poly(&a, &b);
    
//     print_poly(*c);

//     cleanup_poly(a);
//     cleanup_poly(b);
//     cleanup_poly(*c);
//     delete c;

//     return 0;
// }




// #include <iostream>
// struct mt{
//     long long num[2][2];
// };
// void cal(mt &, mt);
// using namespace std;


// int main()
// {
//     struct mt m;
//     int n;
//     cin >> n;
//     for (int i = 0; i < 2; i++)
//         for (int j = 0; j < 2; j++)
//             cin >> m.num[i][j];
    
//     if (n == 0){
//         cout << "1 1\n1 1";
//         return 0;
//     }
//     struct mt ans;
//     ans = m;
//     n--;
//     while(n)
//     {
//         if (n % 2)
//             cal(ans, m);
//         cal(m , m);
//         n /= 2;
//     }
    
//     for (int i = 0; i < 2; i++)
//         for (int j = 0; j < 2; j++){
//             if(ans.num[i][j] < 0)
//                 ans.num[i][j] += 1000000007; 
//         }
//     cout << ans.num[0][0] << " " << ans.num[0][1] << endl << ans.num[1][0] << " " << ans.num[1][1];
//     return 0;
// }

// void cal(mt & a, mt b)
// {
//     mt c = a;
//     for (int i = 0; i < 2; i++)
//     for (int j = 0; j < 2; j++){
//         a.num[i][j] = 0;
//         for (int t = 0; t < 2; t++)
//             a.num[i][j] += c.num[i][t] * b.num[t][j];
//         a.num[i][j] %= 1000000007;
//     }
// }

// 1 2
// 3 4
//       7 10
//       15 22
// 37 54
// 81 118
