#include <iostream>
struct mt{
    long long num[2][2];
};
void cal(mt &, mt);
using namespace std;


int main()
{
    struct mt m;
    int n;
    cin >> n;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            cin >> m.num[i][j];
    
    if (n == 0){
        cout << "1 0\n0 1";
        return 0;
    }
    struct mt ans;
    ans = m;
    n--;
    while(n)
    {
        if (n % 2)
            cal(ans, m);
        cal(m , m);
        n /= 2;
    }
    
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++){
            if(ans.num[i][j] < 0)
                ans.num[i][j] += 1000000007; 
        }
    cout << ans.num[0][0] << " " << ans.num[0][1] << endl << ans.num[1][0] << " " << ans.num[1][1];
    return 0;
}

void cal(mt & a, mt b)
{
    mt c = a;
    for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++){
        a.num[i][j] = 0;
        for (int t = 0; t < 2; t++)
            a.num[i][j] += c.num[i][t] * b.num[t][j];
        a.num[i][j] %= 1000000007;
    }
}