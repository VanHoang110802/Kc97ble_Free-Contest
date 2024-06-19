#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FILE_IO freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define BEGIN auto begin_run = chrono::steady_clock::now();

#define END auto end_run = chrono::steady_clock::now();\
auto time_run = end_run - begin_run;\
cout << "\nTime: " << chrono::duration_cast<chrono::milliseconds>(time_run).count() << " ms.";

string s;
long long f[100005][30], t[30];
long long n, dem = 0;

void XuLy()
{
    cin >> s;
    n = s.size();
    s = " " + s;
    for(int i = 1; i <= n; ++i) s[i] = s[i] - 'a' + 1;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= 26; ++j)
        {
            if (s[i] == j) f[i][j] = f[i - 1][j] + 1;
            else f[i][j] = f[i - 1][j];
        }
    }
    for(int i = 1; i <= n; ++i) t[s[i]] = n + 1;
    for (int i = n; i >= 1; i--)
    {
        if (t[s[i]] > i)
            dem += t[s[i]] - i - 1;
        for(int j = 1; j <= 26; ++j)
        {
            if (j != s[i])
            {
                long long k = min(t[s[i]], n);
                if (f[k][j] - f[i][j] > 1)
                    dem -= (f[k][j] - f[i][j] - 1);
            }
        }
        t[s[i]] = i;
    }
    cout << dem;
}

int main()
{
    //BEGIN;
    //FILE_IO;
    FAST_IO;
    //int test; cin >> test; while(test--)
    {
        XuLy();
    }
    //END;
    return 0;
}
    
